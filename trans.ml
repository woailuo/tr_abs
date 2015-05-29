open Cil

let changesPValue = ref false

let rec getVarinfoName (expr : exp) : string =
  match expr with
    Lval ( Var a, _ ) -> ( print_string (a.vname ^ "\n") );  a.vname
  | Lval(Mem e ,_) -> (print_string " get info name : : ") ;  getVarinfoName e
  | _ -> print_string " not lval ";  ""



and raiseNullExExpr (vi : varinfo) (expr : exp) : bool =
  match expr with
    Lval (Var info, _ ) ->  print_string (" ex expr var info: "^ info.vname ^" \n" ) ; false
  | Lval (Mem e, Field(fieldinfo, offset)) ->
     print_string (" raise mem : p->f :  " ^ vi.vname ^ " ; " ^ "\n");
     if (vi.vname = getVarinfoName e) then true else false
  | Lval (Mem e, NoOffset) ->
     print_string ( " raise mem : *p :"  ^ vi.vname^ " ; " ^ "\n" );
     if (vi.vname = getVarinfoName e ) then true else false
  | Lval (Mem e, _) ->
    ( print_string( " raise mem no offset :  " ^ vi.vname ^ " ; "^" \n" )) ; false
  | Const c  ->  (match c with
                    CInt64 _ -> print_string " cint 64\n";false
                  | CStr s -> print_string (" cstr s : " ^ s ^ " \n");false
                  | CWStr _ -> print_string " cwstr \n";false
                  | CChr _ -> print_string " cchr  \n";false
                  | CReal _ -> print_string " creal \n";false
                  | CEnum _ -> print_string " cenum \n";false )
  (* print_string " rasise err const \n";false *)
  | SizeOf _ -> print_string " rasise err sizeof\n";false
  | SizeOfE _ -> print_string " rasise err sizeofe \n";false
  | SizeOfStr _-> print_string " rasise err sizeofstr\n";false
  | AlignOf _ -> print_string " rasise err alignof \n";false
  | AlignOfE _ -> print_string " rasise err alignofe \n";false
  | UnOp _  -> print_string " rasise err unop \n";false
  | BinOp  (binop, e1, e2,typ) ->  let b1 = raiseNullExExpr vi e1 in
                                   let b2 = raiseNullExExpr vi e2 in
                                   b1 || b2
  | Question _-> print_string " rasise err question \n";false
  | CastE _-> print_string " rasise err caste \n";false
  | AddrOf _  -> print_string " rasise err addrof \n";false
  | AddrOfLabel _ -> print_string " rasise err addroflabel \n";false
  | StartOf _ -> print_string " raise err  startof \n"; false


and raiseNullExLval (vi : varinfo) (va :lval) : bool =
  match va with
    (Var a, _) ->  print_string (" ex lval var: " ^ a.vname ^ "\n" ); false
  | (Mem exp,Field(fieldinfo, offset) ) ->
      print_string " raise mem in ex lval  : p->f  \n";
     if (vi.vname = getVarinfoName exp ) then true else false
  | (Mem exp, NoOffset) ->
      print_string " raise mem in ex lval : *p \n";
     if (vi.vname = getVarinfoName exp ) then true else false
  | (Mem exp, _) ->  print_string " raise mem  in lval : _   \n"; false

and iterRaiseExps (vi:varinfo) (exps : exp list) =
  match exps with
    [] -> false
  | e :: rest -> let b1 = (raiseNullExExpr vi e) in
                 (print_string "    end iter rasi eexp \n ");
                 let b2 =  (iterRaiseExps vi rest) in
                 b1 || b2

and raiseFreeNullEx (vi:varinfo) (e : exp) : bool =
  match e with
    Lval (Var a, NoOffset) -> a = vi
  | _ -> false

and  raiseNullExInstr (vi:varinfo)  (ins : instr) : bool =
  match ins with
    Set ((Var a,_), _ ,_)  when a.vname = vi.vname -> (*  assignment like p = q;  changes p's value*)
    print_string "  instruction changes value of pointer : p = q :   \n";
    (changesPValue := true); false  (* todo *)
   | Set (lval, exp, loc) -> (print_string " \n set lval exp : \n" ); (*  int m = *p; or *p = *q; or ... *)
                             let b1 =  ( raiseNullExLval vi lval) in
                            ( print_string " lval end \n" );
                            let b2 = (raiseNullExExpr vi exp) in
                            print_string " expr end \n" ;     b1 || b2
   | Call(_, Lval(Var a,NoOffset), [e], loc) when a.vname = "free" ->
      (print_string " start free null exce  \n ");
      ( print_string " call var , no offset , free function \n ");
      let b1 = (raiseFreeNullEx vi e) in
      let b2 =  (raiseNullExExpr vi e) in
      (print_string (" raise free null ex : "^ string_of_bool b1 ^" \n"));
      (print_string (" raise null ex  when free : "^ string_of_bool b2 ^" \n"));
      ( print_string " end free null exception \n ");
      b1 || b2
   | Call (Some (Var a, _), _ , exps, loc) when a.vname = vi.vname -> (* changes p's value *)
           print_string "  functions change value of pointer like : p = functions :   \n";
           (changesPValue := true); false  (* todo *)
   | Call (Some lval, _, exps, loc) ->
       (print_string " Start  call functions \n");
       let b1 = (raiseNullExLval vi lval) in
      (print_string (" left value raise null exception   : " ^ string_of_bool b1 ^"\n"));
      let b2 = ( iterRaiseExps vi exps) in
      (print_string (" right expression raise null exception  : " ^ string_of_bool b2 ^"\n"));
      (print_string "  End : call functions like : ( *p = func(); m = func(*p); ) \n" );  b1 || b2
    | Call (None ,exp,exps,location) ->
                                   print_string " Start call exps \n";
                                   let b = (iterRaiseExps vi exps) in
                                   print_string " End of the call exps \n";   b
   | Asm _ -> print_string " raise asm\n"; false

and raiseNullExInstrs (vi:varinfo) (inss: instr list) : bool  =
  match inss with
    [] -> print_string " instructions nullex : false \n" ; false
  | i :: rest ->
     (
       let raisenull = raiseNullExInstr vi i  in
       let changed = !changesPValue in
       match changed with
         true -> print_string " pointer's value is changed \n ";  false
       | false ->  if raisenull then true else raiseNullExInstrs vi rest
     )

and  raiseNullExStmt (vi:varinfo) (stm: stmt) : bool =
  match stm.skind with
  | Instr ins ->  (print_string "  \n Start instructions:  \n");
                  let b =  (raiseNullExInstrs vi ins) in
                   (print_string " \n  End instructions:  \n"); b
  (* | If(guard ,tb,fb,_) when (fb.bstmts = [])&&(isSimplePointer guard) -> *)
  (*    ( *)
  (*      let bgd = raiseNullExExpr vi guard in *)
  (*      match bgd with *)
  (*        true -> true *)
  (*      | false -> let btb =  (raiseNullExStmts vi tb.bstmts ) in  (\* consider guard part *\) *)
  (*                     (\* let bfb  = (raiseNullExStmts  vi fb.bstmts ) in *\) *)
  (*                     btb (\* && bfb *\) *)
  (*    ) *)
  | If(guard, tb,fb,_) when fb.bstmts =[] ->
    (
       let bgd = raiseNullExExpr vi guard in
       match bgd with
         true -> true
       | false -> let btb =  (raiseNullExStmts vi tb.bstmts ) in  (* consider guard part *)
                      (* let bfb  = (raiseNullExStmts  vi fb.bstmts ) in *)
                      btb (* && bfb *)
    )
  | If _ -> false
  | Loop (b, loc,_,_ ) ->  false
  | Return _   | Goto _   | ComputedGoto _   | Break _   | Continue _
  | Switch _   | Block _  | TryFinally _
  | TryExcept _ -> print_string " other statements \n" ; false

and raiseNullExStmts (vi:varinfo) (stmts : stmt list) : bool =
  match stmts with
  [] -> false (* *)
  | s :: rest -> let b = raiseNullExStmt vi s in
                     if b then true else (raiseNullExStmts vi rest)

(* and isSimplePointer(expr:exp) : bool = *)
(*   match expr with *)
(*     Lval ( Var a, _ ) -> isPointer a *)
(*   | Lval(Mem e ,_) -> false *)
(*   | _ -> print_string " simple pointer not \n "; false *)
and pointerType (vtype:typ) : bool =
  match vtype with
    TVoid _   -> print_string " tvoid\n"; false
  | TInt _  -> print_string " tint\n";  false
  | TFloat  _ -> print_string " tfloat\n";  false
  | TPtr (ptype,attrib) -> true
  | TArray _ -> print_string " tvoid\n";  false
  | TFun _ -> print_string " tvoid\n";  false
  | TNamed _  -> print_string " tnamed\n";  false
  | TComp _ -> print_string " tcomp\n";  false
  | TEnum _ -> print_string " tenum\n";  false
  | TBuiltin_va_list  _ -> print_string " tbuiltin_va_list\n";  false

and derefPointer(vtype:typ)  : int =
  match vtype with
    TPtr(ptype,attrib) -> 1 + (derefPointer ptype )
  | _ -> 0


and isPointer (lv: lval) (n : int): bool =
  match lv with
    (Var vi, _) -> (* p *)
    (
      let nums = derefPointer vi.vtype in
      print_string (" derefnums = " ^ string_of_int nums ^ " ; ");
      print_string (" n  = " ^ string_of_int n ^ " \n ");
      if nums > n then true else false
    )
  | (Mem e, Field(fdinfo, offset)) -> (*  p->q->r *)
     isPointer_Offset fdinfo offset

  | (Mem e, NoOffset) -> (* **p, *(p->q) *)
     (
       print_string "  this is a complicated pointer \n";
       match e with
         Lval ( (Var vi, _)  as lv2) -> isPointer lv2 (n+1)
       | Lval ( (Mem e, NoOffset) as lv2 ) -> isPointer lv2 (n+1)
       | Lval((Mem e, offset)as lv2) -> isPointer lv2 (n+1)
       | _ ->  print_string " ceshi 3 \n" ; true
     )
  | _ -> print_string " other pointer or not \n"; false

and isPointer_Offset (fdinfo : fieldinfo) (ofs : offset) : bool = (* p->q, check if q has offset and the offset is pointer; q has no offset, then q should be a pointer *)
  match ofs with
      NoOffset ->
      (
        match fdinfo.ftype with
              TPtr _ ->( print_string ( fdinfo.fname ^"  is a pointer : \n " )); true
            | _ -> (print_string (fdinfo.fname ^ " is not a pointer \n")); false
      )
    | Field (fd_info, off_set) -> isPointer_Offset fd_info off_set
    | _ -> print_string " array index offset \n"; false


and analyStmts (s : stmt) : unit =
  match s.skind with
  | Instr il -> print_string " instr\n";
  | Return _ -> print_string " return\n"
  | Goto _ -> print_string " Goto\n"
  | ComputedGoto _ -> print_string "ComputedGoto\n"
  | Break _ -> print_string " Break\n"
  | Continue _ -> print_string " Continue\n"
  (* simple pointer like : if(p)*)
  | If(Lval(Var (vi:varinfo),NoOffset),tb,eb,loc) when eb.bstmts = [] ->
     print_string " Start Analysis if (_,_,_): simple pointer \n";
     let lv = (Var vi, NoOffset) in
     let ispointer = isPointer lv 0 in
     (
       match ispointer with
       false -> print_string " if-guard is not a pointer \n"
       | true -> let b = raiseNullExStmts vi tb.bstmts in
                 match b with
                   true -> (s.skind <- Block tb); (analyBlock tb);
                   print_string " Can Do Transformation on this statement \n"
                 | false -> print_string " Cannot Do Transformation on this statement \n"
     );
     changesPValue:= false;
     print_string " End Analysis if(_,_,_) : simple pointer \n";
  (* complicated pointer : p->q *)
  | If(Lval(Mem e, offset),tb,eb,loc) when (eb.bstmts = [] )->
     print_string " Start Analysis if (_,_,_): complicated pointer \n";
     let lv = (Mem e,offset) in
     let ispointer = isPointer lv 0 in
     ( match ispointer with
         false ->  print_string " if-guard is not a pointer \n"
       | true ->  (* is next statement raise null exception ?  obtain the next instruction or statement*)
          (match tb.bstmts with
             [] ->  print_string " go into deeper and the inner is NIL \n "
           | a :: rest -> print_string " go into deeper and the inner is NOT NIL \n "
          );
     );
     changesPValue:= false;
     print_string " End Analysis if(_,_,_) : complicated pointer \n";
   (* other if statements *)
  | If _ -> print_string " if \n"
  | Switch(_,b,_,_) -> print_string " switch\n "
  | Loop(b,_,_,_) -> analyBlock b
  | Block b -> print_string " Block\n"
  | TryFinally(b1, b2, _) -> print_string " TryFinally\n"
  | TryExcept(b1,_,b2,_) -> print_string " TryExcept\n"

and analyBlock (b : block) : unit = List.iter analyStmts b.bstmts

and analyFuns (func : fundec) : unit = analyBlock func.sbody

and transfor (f : file) : unit =
  try
 ( List.iter
      (fun g -> match g with
                | GFun (func,loc) ->
                   (print_string " Start GFun: \n");
                   ( analyFuns func  );
                   (print_string " End GFun: \n");
                | _ -> ()
      )
      f.globals (*global list :  functions*)

 )
   with
      _ -> print_string " :  unknown  error occurs: kkkk \n"
