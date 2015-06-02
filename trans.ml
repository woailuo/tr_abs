open Cil

let changesPValue = ref false


let rec getVarinfoName (expr : exp) : string =
  match expr with
    Lval ( Var a, _ ) -> ( print_string (a.vname ^ "\n") );  a.vname
  | Lval(Mem e ,_) -> (print_string " get info name : : ") ;  getVarinfoName e
  | _ -> print_string " not lval ";  ""

and contains (lvs1:string) (lns2:string) : bool =
  let length1= String.length lvs1 in
  print_string (" contains : " ^ lvs1 ^" ;   "^ lns2 ^ "\n");
  let length2= String.length lns2 in
  if length2 >=length1 then
    (
      let newlnstr = String.sub lns2 0 length1 in
      (  print_string (" new string  : " ^ newlnstr ^ "\n"););
      if lvs1 = newlnstr then true else false
    )
  else false

and compareOffset (lvo: offset) (lno : offset) : bool =
    let b = (lvo = lno) in b

and getOffset (offset : offset):string =
  match offset with
  NoOffset -> ""
  | Field(finfo, NoOffset) -> finfo.fname
  | Field(finfo, foffset) -> finfo.fname ^ "->"^getOffset foffset
  | _ -> print_string " other offset string : \n"; ""

and getStructure (expr : exp) : string =
  print_string " start analyzing stucture  by expression \n";
  match expr with
     Lval (Var vinfo, _) -> vinfo.vname
   | Lval (Mem lve, NoOffset) -> "*" ^( getStructure lve )
   | Lval (Mem lve, Field (ffinfo, NoOffset)) ->
      (getStructure lve ) ^ "->"^ ffinfo.fname
   | Lval (Mem lve, Field (ffinfo, foffset)) ->
       (getStructure lve ) ^ "->"^ ffinfo.fname ^ "->"^getOffset foffset
   | Lval (Mem lve, Index _) -> ""
    | CastE (typ, exp)-> print_string " rasise cast  \n";
                       pointerType typ;
                     getStructure exp
     | _ -> print_string " other is empty string: \n "; ""

and compareLval (lv : lval) (expr : exp) :bool = (* conn->db, (conn->db)->addr*)
  match expr with
    Lval ((Var vinfo, _) as ln) ->print_string " compare here 1 \n";
                                  (
                                    match lv with
                                      (Var lvinfo,_) -> if lvinfo.vname = vinfo.vname then true else false
                                    | _ -> false
                                  )
  | Lval((Mem e, NoOffset) as ln) -> print_string " compare here 2 \n"; (* *(p, p->f->q)*)
     (
       match lv with
         (Var vinfo, _) ->
         (
         let vname = vinfo.vname in
         let lnname = getStructure expr in
         let b = contains vname lnname in
         print_string (" compare when var vinfo :  " ^string_of_bool b ^"\n");
         b
         )
       | (Mem lve, NoOffset) -> print_string " m nooffse \n" ;
         let lvstr = getStructure lve in
         let lnstr = getStructure e in
         let b = contains lvstr lnstr in
        print_string (" compare:  " ^string_of_bool b  ^"\n");    b
       | (Mem lve, Field (ffinfo, foffset)) -> print_string " m f \n" ; false
       | (Mem lve, Index _) -> print_string " m index \n"; false
     )
  | Lval((Mem e, Field(fdinfo, offset) ) as ln) ->
     (
       match lv with
         (Var vinfo, _) ->
         (
         let vname = vinfo.vname in
         let lnname = getStructure expr in
         let b = contains vname lnname in
         print_string (" compare when var vinfo :  " ^string_of_bool b ^"\n");
         b
         )
       | (Mem lve, NoOffset) -> print_string " m nooffse \n" ;false
       | (Mem lve, Field (ffinfo, foffset)) -> print_string " m f \n" ;
                                            (
                                              let lvstr = getStructure (Lval lv) in
                                              let lnstr = getStructure expr in
                                              let b = contains lvstr lnstr in
                                              print_string (" compare:  " ^string_of_bool b  ^"\n");
                                              b
                                            )
       | (Mem lve, Index _) -> print_string " m index \n"; false
     )
  | CastE (typ, newexp) -> compareLval lv newexp
  | _ -> print_string " other , unknown \n"; false

and raiseNullExExpr (lv : lval ) (expr : exp) : bool = (* conn->age,  *(conn->age) *)
  match expr with
    Lval (Var info, _ ) ->  print_string (" ex expr var info: "^ info.vname ^" \n" ) ; false
    | Lval (Mem e, Field(fieldinfo, offset) ) ->
       print_string (" raise mem : p->f :  " ^ getStructure expr ^ " ; " ^ "\n");
     if (compareLval lv e ) then true else false
  | Lval (Mem e, NoOffset) ->
     print_string ( " raise mem : *p :"  ^ getVarinfoName e ^ " ; " ^ "\n" );
       if (compareLval lv e) then true else false
  | Lval (Mem e, _) ->
     ( print_string( " raise mem no offset :  " ^ getVarinfoName e^ " ; "^" \n" )) ; false
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
  | BinOp  (binop, e1, e2,typ) ->  let b1 = raiseNullExExpr lv e1 in
                                   let b2 = raiseNullExExpr lv e2 in
                                   b1 || b2
  | Question _-> print_string " rasise err question \n";false
  | CastE  (ctype,cexp )->  raiseNullExExpr lv cexp
  | AddrOf _  -> print_string " rasise err addrof \n";false
  | AddrOfLabel _ -> print_string " rasise err addroflabel \n";false
  | StartOf _ -> print_string " raise err  startof \n"; false


and raiseNullExLval (lv : lval) (ln :lval) : bool =
  print_string " raise null exception lv , ln";
  raiseNullExExpr lv (Lval ln)
  (* match va with *)
  (*   (Var a, _) ->  print_string (" ex lval var: " ^ a.vname ^ "\n" ); false *)
  (* | (Mem exp,Field(fieldinfo, offset) ) -> *)
  (*     print_string " raise mem in ex lval  : p->f  \n"; *)
  (*    if (lv = va ) then true else false *)
  (* | (Mem exp, NoOffset) -> *)
  (*     print_string " raise mem in ex lval : *p \n"; *)
  (*    if (lv = va ) then true else false *)
  (* | (Mem exp, _) ->  print_string " raise mem  in lval : _   \n"; false *)

and iterRaiseExps (lv:lval) (exps : exp list) =
  match exps with
    [] -> false
  | e :: rest -> let b1 = (raiseNullExExpr lv e) in
                 (print_string "    end iter rasi eexp \n ");
                 let b2 =  (iterRaiseExps lv rest) in
                 b1 || b2

and raiseFreeNullEx (lv : lval ) (e : exp) : bool =
  compareLval lv e

and  raiseNullExInstr (lv : lval )  (ins : instr) : bool =
  match ins with
    Set (ln , _ ,_) when  (not ( raiseNullExExpr lv (Lval ln))) && (compareLval lv  (Lval ln)) -> (*  assignment like p = q;  changes p's value*)
    print_string "  instruction changes value of pointer : p = q :   \n";
    (changesPValue := true); false  (* todo *)
   | Set (ln, exp, loc) -> (print_string " \n set lval exp : \n" ); (*  int m = *p; or *p = *q; or ... *)
                             let b1 =  ( raiseNullExLval lv ln) in
                            ( print_string (" lval end : " ^ string_of_bool b1 ^" \n") );
                            let b2 = (raiseNullExExpr lv exp) in
                            print_string (" expr end " ^string_of_bool b2^ "\n" );
                            b1 || b2
   | Call(_, Lval( Var a,NoOffset), [e], loc) when a.vname = "free" ->
      print_string (" Free ("^getStructure e ^ ") \n");
      (print_string " start free null exce  \n ");
      ( print_string " call var , no offset , free function \n ");
      let b1 = (raiseFreeNullEx lv e) in
      print_string " complete raise free null exp: lv e \n";
      let b2 =  (raiseNullExExpr lv e) in
      (print_string (" raise free null ex : "^ string_of_bool b1 ^" \n"));
      (print_string (" raise null ex of e when free(e) : "^ string_of_bool b2 ^" \n"));
      ( print_string " end free null exception \n ");
      b1 || b2
   | Call (Some ln , _ , exps, loc) when  (not ( raiseNullExExpr lv (Lval ln))) && (compareLval lv  (Lval ln)) -> (* changes p's value *)
           print_string "  functions change value of pointer like : p = functions :   \n";
           (changesPValue := true); false  (* todo *)
   | Call (Some lval, _, exps, loc) ->
       (print_string " Start  call functions \n");
       let b1 = (raiseNullExLval lv lval) in
      (print_string (" left value raise null exception   : " ^ string_of_bool b1 ^"\n"));
      let b2 = ( iterRaiseExps lv exps) in
      (print_string (" right expression raise null exception  : " ^ string_of_bool b2 ^"\n"));
      (print_string "  End : call functions like : ( *p = func(); m = func(*p); ) \n" );
      b1 || b2
    | Call (None ,exp,exps,location) ->
                                   print_string " Start call exps \n";
                                   let b = (iterRaiseExps lv exps) in
                                   print_string " End of the call exps \n";   b
   | Asm _ -> print_string " raise asm\n"; false

and raiseNullExInstrs (lv : lval) (inss: instr list) : bool  =
  match inss with
    [] -> print_string " instructions nullex : Nil \n" ; false
  | i :: rest ->
     (
       let raisenull = raiseNullExInstr lv i  in
       let changed = !changesPValue in
       match changed with
         true -> print_string " pointer's value is changed \n ";  false
       | false -> (print_string (" raise null ex instructions :   "^ string_of_bool raisenull ^"\n")); if raisenull then true else raiseNullExInstrs lv rest
     )

and  raiseNullExStmt (lv : lval) (stm: stmt) : bool =
  match stm.skind with
  | Instr ins ->  (print_string "  \n Start instructions:  \n");
                  let b =  (raiseNullExInstrs lv ins) in
                   print_string (" \n  End instructions: " ^ string_of_bool b ^" \n"); b
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
     (  print_string "  Start : inner if statement :\n";
        print_string "                if guard part  :\n";
        let bgd = raiseNullExExpr lv guard in
        (print_string( "                end if guard part "^ string_of_bool bgd ^" :\n"));
       match bgd with
         true ->print_string " if-guard part raise null exception \n";  true
       | false -> let btb =  (raiseNullExStmts lv tb.bstmts ) in  (* consider guard part *)
                  (* let bfb  = (raiseNullExStmts  vi fb.bstmts ) in *)
                  print_string ( "  End : inner if statement :  " ^ string_of_bool btb  ^ "\n");
                      btb (* && bfb *)
    )
  | If _ -> false
  | Loop (b, loc,_,_ ) ->  false
  | Return _   | Goto _   | ComputedGoto _   | Break _   | Continue _
  | Switch _   | Block _  | TryFinally _
  | TryExcept _ -> print_string " other statements \n" ; false

and raiseNullExStmts (lv : lval) (stmts : stmt list) : bool =
  match stmts with
  [] -> false (* *)
  | s :: rest -> let b = raiseNullExStmt lv s in
                     if b then true else (raiseNullExStmts lv rest)

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
    (Var vi, _) -> (* p, or v *)
    (
      let nums = derefPointer vi.vtype in
      print_string (" derefnums = " ^ string_of_int nums ^ " ; ");
      print_string (" n  = " ^ string_of_int n ^ " \n ");
      if nums > n then true else false
    )
  | (Mem e, Field(fdinfo, offset)) ->
    let (returnFinfo, b) = isPointer_Offset fdinfo offset in
    (
      match n,b with
          0 , b -> b (* p -> q ->r *)
        | _, true -> let dnum = derefPointer fdinfo.ftype in
                          if dnum > n then true else false (* *(p->q),*)
        | _ , false -> false
    )
  | (Mem e, NoOffset) -> (* **p, *(p->q) *)
     (
       print_string ( "  this is a complicated pointer : *("^ getStructure e ^") \n");
       match e with
         Lval ( (Var vi, _)  as lv2) -> isPointer lv2 (n+1)
       | Lval ( (Mem e, NoOffset) as lv2 ) -> isPointer lv2 (n+1)
       | Lval((Mem e, offset)as lv2) ->  isPointer lv2 (n+1)
       | _ ->  print_string " ceshi 3 \n" ; true
     )
  | _ -> print_string " other pointer or not \n"; false

and isPointer_Offset (fdinfo : fieldinfo) (ofs : offset) :(fieldinfo * bool) = (* p->q, check if q has offset and the offset is pointer; q has no offset, then q should be a pointer *)
  match ofs with
      NoOffset ->
      (
        match fdinfo.ftype with
              TPtr _ ->( print_string ( fdinfo.fname ^"  is a pointer : \n " )); (fdinfo,true)
            | _ -> (print_string (fdinfo.fname ^ " is not a pointer \n")); (fdinfo,false)
      )
    | Field (fd_info, off_set) -> isPointer_Offset fd_info off_set
    | _ -> print_string " array index offset \n"; (fdinfo,false)

and isNextStmRaiseNull (lv:lval) (s:stmt) =
  match s.skind with
  | Instr ins ->( match ins with
                   [] -> false
                 | i ::rest -> let b =  raiseNullExInstr lv i in
                               if b then true else false )
  | If(guard, tb,fb,_) -> let b = raiseNullExExpr lv guard in
                          if b then true else false
  | Loop (b, loc,_,_ ) ->  false
  | Return _   | Goto _   | ComputedGoto _   | Break _   | Continue _
  | Switch _   | Block _  | TryFinally _
  | TryExcept _ -> print_string " other statements \n" ; false


and analyStmts (s : stmt) : unit =
  match s.skind with
  | Instr il -> print_string " instr\n";
  | Return _ -> print_string " return\n"
  | Goto _ -> print_string " Goto\n"
  | ComputedGoto _ -> print_string "ComputedGoto\n"
  | Break _ -> print_string " Break\n"
  | Continue _ -> print_string " Continue\n"
  (* simple pointer like : if(p), p is a simple pointer;  or if(v), v is variable *)
  | If(Lval((Var (vi:varinfo),NoOffset) as lv ),tb,eb,loc) when eb.bstmts = [] ->
     print_string " Start Analysis if (_,_,_): simple pointer \n";
     let ispointer = isPointer lv 0 in (* here must 0 *)
     (
       match ispointer with
       false -> print_string " if-guard is not a pointer 1 \n"
       | true -> let b = raiseNullExStmts lv tb.bstmts in
               (  match (b,!changesPValue) with
                   (true, false) ->
                   (s.skind <- Block tb);
                           print_string " Can Do Transformation on this statement \n ";
                           (analyBlock tb);
                  | _  -> print_string " Cannot Do Transformation on this statement \n"
               )
     );
     changesPValue:= false;
     print_string " End Analysis if(_,_,_) : simple pointer \n";
  (* complicated pointer : p->q , or *p *)
  | If(Lval((Mem e, offset) as lv),tb,eb,loc) when (eb.bstmts = [] )->
     print_string " Start Analysis if (_,_,_): complicated pointer \n";
     let ispointer = isPointer lv 0 in
     ( match ispointer with
         false ->  print_string " if-guard is not a pointer  2 \n"
       | true ->  (* does next statement raise null exception ?  obtain the next instruction or statement*)
          print_string " go into deeper and the inner is NOT NIL \n ";
          let b = raiseNullExStmts lv tb.bstmts in
          let c =
           (
            match tb.bstmts with
              [] -> false
            | stm :: rest -> isNextStmRaiseNull lv stm
           ) in
          print_string ( " next close raise null exception : " ^ string_of_bool c ^" \n");
          ( match b&&c with
            true -> (s.skind <- Block tb);
                    print_string " Can Do Transformation on this statement : complicated pointer \n ";
                           (analyBlock tb);
                 | false -> print_string " Cannot Do Transformation on this statement : complicated pointerv\n" )
     );
     changesPValue:= false;
     print_string " End Analysis if(_,_,_) : complicated pointer \n";
   (* other if statements *)
  | If _ -> print_string " if  other statements \n"
  | Switch(_,b,_,_) -> print_string " switch\n "
  | Loop(b,_,_,_) -> analyBlock b
  | Block b -> print_string " Block\n"
  | TryFinally(b1, b2, _) -> print_string " TryFinally\n"
  | TryExcept(b1,_,b2,_) -> print_string " TryExcept\n"

and analyBlock (b : block) : unit = List.iter analyStmts b.bstmts

and analyFuns (func : fundec) : unit = analyBlock func.sbody

and transfor (f : file) : unit =
  (* try *)
 ( List.iter
      (fun g -> match g with
                | GFun (func,loc) ->
                   (print_string (" Start GFun: " ^ func.svar.vname ^" \n"));
                   ( analyFuns func  );
                   (print_string " End GFun: \n");
                | _ -> ()
      )
      f.globals (*global list :  functions*)

 )
   (* with *)
   (*    _ -> print_string " :  unknown  error occurs: kkkk \n" *)
