open Cil

let changesPValue = ref false

let isPrintStr = true

let rec  printStr (str : string) =
  if isPrintStr then (print_string str ) else ()

and contains (lvs1:string) (lns2:string) : bool =
  let length1= String.length lvs1 in
  printStr (" contains : fist str: " ^ lvs1 ^"  ; snd str:    "^ lns2 ^ "\n");
  let length2= String.length lns2 in
  if length2 >=length1 then
    (
      let newlnstr = String.sub lns2 0 length1 in
      (printStr (" new string  : " ^ newlnstr ^ "\n"););
      if length2 = length1 then (printStr " length is the same \n ";   if (lvs1 = newlnstr)  then true else false)
      else
        (
          let pstr =  String.sub lns2 length1 1 in
            printStr (" post string  : " ^ pstr ^ "\n");
          if (lvs1 = newlnstr) &&(pstr = "" || pstr = "-" || pstr = "*" || pstr = "[") then true else false
        )
    )
    else false

and getOffset (offset : offset):string =
  match offset with
    NoOffset -> printStr " get offset : no offset \n";  ""
  | Field(finfo, NoOffset) -> finfo.fname
  | Field(finfo, foffset) -> finfo.fname ^ "->"^getOffset foffset
  | Index(e, NoOffset) -> "[" ^ (getStructure e)^ "]"
  | Index(e, inoffset) -> "[" ^ (getStructure e)^ "]"  ^ (getOffset inoffset)  (* todo : e may raise null exception *)

and deleteCastE (expr : exp) : (exp * bool)=
  match expr with
      CastE (ctype, e) ->
        (
          match e with
              CastE _ as e1 -> deleteCastE e1
            | Lval a  -> Lval a , true
            | e -> e, false
         )
    | Lval a  -> Lval a , true
    | e -> e,false

and getStructure (expr : exp) : string =
  printStr " start analyzing stucture  by expression \n";
  match expr with
  | Lval(Var vinfo, Index (e, offset)) -> (vinfo.vname) ^"[" ^(getStructure e)^"]"^ (getOffset offset)
  | Lval (Var vinfo, _) -> vinfo.vname
  | Lval (Mem lve, NoOffset) -> ( getStructure lve ) ^ "*"
  | Lval (Mem lve, Field (ffinfo, NoOffset)) ->
     (getStructure lve ) ^ "->"^ ffinfo.fname
  | Lval (Mem lve, Field (ffinfo, foffset)) ->
     (getStructure lve ) ^ "->"^ ffinfo.fname ^ "->"^getOffset foffset
  | Lval (Mem lve, Index _) ->printStr " getstructure Index  \n"; ""
  | CastE (typ, exp)-> printStr " rasise cast  \n";
                        getStructure exp
   | BinOp  (binop, e1, e2,typ) ->  printStr " Start from binop to test structure \n";
                                    (getStructure e1) ^ (getStructure e2)
   | Const c  ->  (match c with
                     CInt64 (a,b,c) ->  printStr " cint 64\n";   (string_of_int (i64_to_int a))
                   | CStr s -> printStr (" cstr s : " ^ s ^ " \n");""
                   | CWStr _ -> printStr " cwstr \n";""
                   | CChr _ -> printStr " cchr  \n";""
                   | CReal _ -> printStr " creal \n";""
                   | CEnum _ -> printStr " cenum \n";"" )
    | _ -> printStr " other is empty string: \n "; ""

and compareLval (lv : lval) (expr : exp) :bool = (* conn->db, (conn->db)->addr*)
      let lvstr = getStructure (Lval lv) in
      let lnstr = getStructure expr in
      let b = contains lvstr lnstr in
      b

and raiseNullOffset (lv:lval) (ofs: offset) : bool =
  match ofs with
      NoOffset -> false
    | Field(fe, foffset) -> raiseNullOffset lv foffset
    | Index(ine, inoffset) -> let b = raiseNullExExpr lv ine in
                              if b then true else raiseNullOffset lv inoffset

and raiseNullExExpr (lv : lval ) (expr : exp) : bool = (* conn->age,  *(conn->age) *)
  match expr with
      Lval (Var info, Index (e, inoffset)) ->
        printStr " start analyzing  inner index \n";
        let b = raiseNullExExpr lv e in
        if b then true else raiseNullOffset lv inoffset
    | Lval (Var info, _ ) ->  printStr (" ex expr var info: "^ info.vname ^" \n" ) ; false
    | Lval (Mem e, Field(fieldinfo, offset) ) ->
      printStr " Print Structure : \n";
      printStr (" raise mem : p->f :  " ^ getStructure expr ^ " ; " ^ "\n");
      printStr " End Print Structure  \n";
      if (compareLval lv e ) || (raiseNullExExpr lv e) || (raiseNullOffset lv offset) then true else false
  | Lval (Mem e, NoOffset) ->
    printStr " Print Structure : \n";
    printStr ( " raise mem : *p :"  ^ getStructure expr ^ " ; " ^ "\n" );
    printStr " End Print Structure  \n";
    if (compareLval lv e) || (raiseNullExExpr lv e) then true else false
  | Lval (Mem e, _) ->
    ( printStr( " raise mem no offset :  " ^ getStructure expr^ " ; "^" \n" )) ; false
  | Const c  ->  (match c with
                    CInt64 _ -> printStr " cint 64\n";false
                  | CStr s -> printStr (" cstr s : " ^ s ^ " \n");false
                  | CWStr _ -> printStr " cwstr \n";false
                  | CChr _ -> printStr " cchr  \n";false
                  | CReal _ -> printStr " creal \n";false
                  | CEnum _ -> printStr " cenum \n";false )
  (* printStr " rasise err const \n";false *)
  | SizeOf _ -> printStr " rasise err sizeof\n";false
  | SizeOfE e1 -> printStr " rasise err sizeofe \n";
    let b = raiseNullExExpr lv e1 in
    b
  | SizeOfStr _-> printStr " rasise err sizeofstr\n";false
  | AlignOf _ -> printStr " rasise err alignof \n";false
  | AlignOfE e1 -> printStr " rasise err alignofe \n";
    let b = raiseNullExExpr lv e1 in
    b
  | UnOp (unop, e1, typ)  ->( printStr " rasise err unop \n");
    let b = raiseNullExExpr lv e1 in
    b
  | BinOp  (binop, e1, e2,typ) ->  let b1 = raiseNullExExpr lv e1 in
                                   if b1 then true else (raiseNullExExpr lv e2)
  | Question (e1, e2, e3, typ)-> printStr " rasise err question \n";
    let b1 = raiseNullExExpr lv e1 in
    if b1 then true else (
      if (raiseNullExExpr lv e2) then true else (raiseNullExExpr lv e3)
    )
  | CastE  (ctype,cexp )->  raiseNullExExpr lv cexp
  | AddrOf _  -> printStr " rasise err addrof \n";false
  | AddrOfLabel _ -> printStr " rasise err addroflabel \n";false
  | StartOf _ -> printStr " raise err  startof \n"; false

and raiseNullExLval (lv : lval) (ln :lval) : bool =
  printStr " raise null exception lv , ln";
  raiseNullExExpr lv (Lval ln)

and iterRaiseExps (lv:lval) (exps : exp list) =
  match exps with
    [] -> false
  | e :: rest -> let b1 = (raiseNullExExpr lv e) in
                 (printStr "    end iter rasi eexp \n ");
                 if b1 then true else  (iterRaiseExps lv rest)

and raiseFreeNullEx (lv : lval ) (e : exp) : bool =
  compareLval lv e

and  raiseNullExInstr (lv : lval )  (ins : instr) : bool =
  match ins with
    Set (ln , _ ,_) when  (not ( raiseNullExExpr lv (Lval ln))) && (compareLval lv  (Lval ln)) -> (*  assignment like p = q;  changes p's value*)
    printStr "  instruction changes value of pointer : p = q :   \n";
    (changesPValue := true); false  (* todo *)
   | Set (ln, exp, loc) -> (printStr " \n set lval exp : \n" ); (*  int m = *p; or *p = *q; or ... *)
                             let b1 =  ( raiseNullExLval lv ln) in
                              printStr (" lval end : " ^ string_of_bool b1 ^" \n");
                             if b1 then true else (
                               let b2 = (raiseNullExExpr lv exp) in
                               printStr (" expr end " ^string_of_bool b2^ "\n" );
                               b2
                             )
   | Call(_, Lval( Var a,NoOffset), [e], loc) when a.vname = "free" ->
         (printStr " start free null exce  \n ");
      let b1 = (raiseFreeNullEx lv e) in
      printStr " complete raise free null exp: lv e \n";
      (printStr (" raise free null ex : "^ string_of_bool b1 ^" \n"));
      if b1 then true else (raiseNullExExpr lv e)
   | Call (Some ln , _ , exps, loc) when  (not ( raiseNullExExpr lv (Lval ln))) && (compareLval lv  (Lval ln)) -> (* changes p's value *)
           printStr "  functions change value of pointer like : p = functions :   \n";
           (changesPValue := true); false  (* todo *)
   | Call (Some lval, _, exps, loc) ->
       (printStr " Start  call functions \n");
       let b1 = (raiseNullExLval lv lval) in
      printStr (" left value raise null exception   : " ^ string_of_bool b1 ^"\n");
       if b1 then true else
         (
           let b2 = ( iterRaiseExps lv exps) in
           printStr (" right expression raise null exception  : " ^ string_of_bool b2 ^"\n");
           printStr "  End : call functions like : ( *p = func(); m = func(*p); ) \n" ;
           b2
         )
   | Call (None ,exp,exps,location) ->
                                   printStr " Start call exps \n";
                                   let b = (iterRaiseExps lv exps) in
                                   printStr " End of the call exps \n";   b
   | Asm _ -> printStr " raise asm\n"; false

and raiseNullExInstrs (lv : lval) (inss: instr list) : bool  =
  match inss with
    [] -> printStr " instructions nullex : Nil \n" ; false
  | i :: rest ->
     (
       let raisenull = raiseNullExInstr lv i  in
       let changed = !changesPValue in
       match changed with
         true -> printStr " pointer's value is changed \n ";  false
       | false -> (printStr (" raise null ex instructions :   "^ string_of_bool raisenull ^"\n")); if raisenull then true else raiseNullExInstrs lv rest
     )

and  raiseNullExStmt (lv : lval) (stm: stmt) : bool =
  match stm.skind with
  | Instr ins ->  (printStr "  \n Start instructions:  \n");
                  let b =  (raiseNullExInstrs lv ins) in
                   printStr (" \n  End instructions: " ^ string_of_bool b ^" \n"); b
  | If(guard, tb,fb,_) ->
     (  printStr "  Start : inner if statement :\n";
        printStr "                if guard part  :\n";
        let bgd = raiseNullExExpr lv guard in  (* consider guard part *)
        (printStr( "                end if guard part "^ string_of_bool bgd ^" :\n"));
       match bgd with
         true ->printStr " if-guard part raise null exception \n";  true
       | false -> let btb =  (raiseNullExStmts lv tb.bstmts ) in
                  let bfb  = (raiseNullExStmts  lv fb.bstmts ) in
                  printStr ( "  End : inner if statement :  " ^ string_of_bool btb  ^ "\n");
                      btb && bfb
    )
  | Loop (b, loc,_,_ ) ->  false
  | Return _   | Goto _   | ComputedGoto _   | Break _   | Continue _
  | Switch _   | Block _  | TryFinally _
  | TryExcept _ -> printStr " other statements \n" ; false

and raiseNullExStmts (lv : lval) (stmts : stmt list) : bool =
  match stmts with
  [] -> false (* *)
  | s :: rest -> let b = raiseNullExStmt lv s in
                     if b then true else (raiseNullExStmts lv rest)

and pointerType (vtype:typ) : bool =
  match vtype with
    TVoid _   -> printStr " tvoid\n"; false
  | TInt _  -> printStr " tint\n";  false
  | TFloat  _ -> printStr " tfloat\n";  false
  | TPtr (ptype,attrib) -> printStr "pointer type \n"; true
  | TArray (typ, eop, attr) -> pointerType typ
  | TFun _ -> printStr " tfun\n";  false
  | TNamed _  -> printStr " tnamed\n";  false
  | TComp _ -> printStr " tcomp\n";  false
  | TEnum _ -> printStr " tenum\n";  false
  | TBuiltin_va_list  _ -> printStr " tbuiltin_va_list\n";  false

and derefPointer(vtype:typ)  : int =
  match vtype with
    TPtr(ptype,attrib) -> 1 + (derefPointer ptype )
  | _ -> 0


and isPointer (lv: lval) (n : int): bool =
  match lv with
      (Var a, Index (expr, offset)) -> printStr " array index \n ";
        printStr a.vname ; pointerType a.vtype;
  | (Var vi, _) -> (* p, or v *)
    (
      let nums = derefPointer vi.vtype in
      printStr (" derefnums = " ^ string_of_int nums ^ " ; ");
      printStr (" n  = " ^ string_of_int n ^ " \n ");
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
       printStr ( "  this is a complicated pointer : *("^ getStructure e ^") \n");
       match e with
         Lval ( (Var vi, _)  as lv2) -> isPointer lv2 (n+1)
       | Lval ( (Mem e, NoOffset) as lv2 ) -> isPointer lv2 (n+1)
       | Lval((Mem e, offset)as lv2) ->  isPointer lv2 (n+1)
       | _ ->  printStr " ceshi 3 \n" ; true
     )
  | _  -> printStr " other pointer or not \n"; false

and isPointer_Offset (fdinfo : fieldinfo) (ofs : offset) :(fieldinfo * bool) = (* p->q, check if q has offset and the offset is pointer; q has no offset, then q should be a pointer *)
  match ofs with
      NoOffset ->
      (
        match fdinfo.ftype with
              TPtr _ ->( printStr ( fdinfo.fname ^"  is a pointer : \n " )); (fdinfo,true)
            | _ -> (printStr (fdinfo.fname ^ " is not a pointer \n")); (fdinfo,false)
      )
    | Field (fd_info, off_set) -> isPointer_Offset fd_info off_set
    (* | Index (e, inoffset) -> isPointer  *) (* todo: (p->f)[0])*)
    | _ -> printStr " array index offset \n"; (fdinfo,false)

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
  | TryExcept _ -> printStr " other statements \n" ; false


and analyStmts (s : stmt) : unit =
  match s.skind with
  | Instr il -> printStr " instr\n";
  | Return _ -> printStr " return\n"
  | Goto _ -> printStr " Goto\n"
  | ComputedGoto _ -> printStr "ComputedGoto\n"
  | Break _ -> printStr " Break\n"
  | Continue _ -> printStr " Continue\n"
  (* simple pointer like : if(p), p is a simple pointer;  or if(v), v is variable *)
  | If(Lval((Var (vi:varinfo),NoOffset) as lv ),tb,eb,loc) when eb.bstmts = [] ->
    print_string "Start Analysis if (_,_,_): simple pointer \n";
     let ispointer = isPointer lv 0 in (* here must 0 *)
     (
       match ispointer with
       false -> print_string " if-guard is not a pointer  \n"
       | true -> let b = raiseNullExStmts lv tb.bstmts in
               (  match (b,!changesPValue) with
                   (true, false) ->
                   (s.skind <- Block tb);
                           print_string " Can Do Tr \n ";
                           (analyBlock tb);
                  | _  -> print_string " Cannot Do Tr \n"
               )
     );
     changesPValue:= false;
     print_string " End Analysis if(_,_,_) : simple pointer \n";
  (* complicated pointer : p->q , or *p *)
  | If(Lval((Mem e, offset) as lv),tb,eb,loc) when (eb.bstmts = [] )->
    print_string "Start Analysis if (_,_,_): complicated pointer \n";
     let ispointer = isPointer lv 0 in
     ( match ispointer with
         false ->  print_string " if-guard is not a pointer   \n"
       | true ->  (* does next statement raise null exception ?  obtain the next instruction or statement*)
          printStr " go into deeper and the inner is NOT NIL \n ";
          let c =
           (
            match tb.bstmts with
              [] -> false
            | stm :: rest -> isNextStmRaiseNull lv stm
           ) in
          if c then
            ( let b = raiseNullExStmts lv tb.bstmts in
              if b then  (
                (s.skind <- Block tb);
                print_string "Can Do Tr: complicated pointer \n ";
                (analyBlock tb) )
              else
                print_string " Cannot Do Tr: complicated pointer\n"
            )
          else print_string " next close instruction does not raise exception \n\
                                      Cannot Do Tr: complicated pointer \n"
     );
     changesPValue:= false;
     print_string " End Analysis if(_,_,_) : complicated pointer \n";
  | If(BinOp (Ne, e1, e2, typ) , tb, fb, loc) when fb.bstmts=[]  ->
      let ne1, b1 = deleteCastE e1 in
      let ne2, b2 = deleteCastE e2 in
      let b3 =(
        match b1 with
            true -> (
              match ne1 with
                  Lval a -> isPointer a 0
                | _ -> false
            )
          | false -> false
      ) in
      let b4 = (
        match ne2 with
            Const _ -> true
          | _ -> false
      ) in
      if b3&&b4 then
        (match ne1 with
          Lval lv ->
            print_string "Start analyzing if (pointer != NULL) statements \n";
            s.skind <- (If(Lval lv, tb,fb,loc));
            analyStmts s;
            print_string "End analyzing if (pointer != NULL) statements \n";
          | _ ->  printStr " if other statements if (p ! = NULL) \n"
        )
      else printStr " if other statements (p != NULL) \n"
   (* other if statements *)
  | If (Lval((Var a, Index _) as lv), tb, fb, loc) when fb.bstmts = [] ->
     print_string " Start Analysis: Array \n";
     let ispointer = isPointer lv 0 in (* here must 0 *)
     (
       match ispointer with
       false -> print_string " if-guard is not a pointer  \n"
       | true -> let b = raiseNullExStmts lv tb.bstmts in
               (  match (b,!changesPValue) with
                   (true, false) ->
                   (s.skind <- Block tb);
                           print_string " Can Do Tr: Array \n ";
                           (analyBlock tb);
                  | _  -> print_string " Cannot Do Tr: Array  \n"
               )
     );
     changesPValue:= false;
     print_string " End Analysis: Array \n";
  | If _ -> print_string " if  other statements \n"
  | Switch(_,b,_,_) -> printStr " switch\n "
  | Loop(b,_,_,_) -> printStr " loop \n"
  | Block b -> printStr " Block\n"
  | TryFinally(b1, b2, _) -> printStr " TryFinally\n"
  | TryExcept(b1,_,b2,_) -> printStr " TryExcept\n"

and analyBlock (b : block) : unit = List.iter analyStmts b.bstmts

and analyFuns (func : fundec) : unit = analyBlock func.sbody

and transfor (f : file) : unit =
 ( List.iter
      (fun g -> match g with
                | GFun (func,loc) ->
                   (print_string ("Start GFun: " ^ func.svar.vname ^" \n"));
                   ( analyFuns func  );
                   (print_string ("End GFun: " ^ func.svar.vname ^" \n"));
                | _ -> ()
      )
      f.globals (*global list :  functions*)
 )
