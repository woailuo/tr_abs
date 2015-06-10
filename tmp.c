  match expr with
  | Lval _ ->
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
                                   let b2 = raiseNullExExpr lv e2 in
                                   b1 || b2
  | Question (e1, e2, e3, typ)-> printStr " rasise err question \n";
    let b1 = raiseNullExExpr lv e1 in
    let b2 = raiseNullExExpr lv e2 in
    let b3 = raiseNullExExpr lv e3 in
    b1 || b2 || b3
  | CastE  (ctype,cexp )->  raiseNullExExpr lv cexp
  | AddrOf _  -> printStr " rasise err addrof \n";false
  | AddrOfLabel _ -> printStr " rasise err addroflabel \n";false
  | StartOf _ -> printStr " raise err  startof \n"; false
