open Cil

module E = Errormsg

let str = ref ""
let funclist = ref (("","") :: [])

let rec fixLval (fname:string) (lv: lval): string =
  match lv with
  | (Var a, _)  ->
     (
       try
         (List.assoc a.vname funclist.contents)
       with
         _ -> ""
     )
  | _ -> ""

(* and findCall (fname : string) (expr: exp): string = *)
(*   match expr with *)
(*     | Lval a -> fixLval fname a *)
(*     | Const _ *)
(*     | SizeOf _  | SizeOfE _ | SizeOfStr _  | AlignOf _ *)
(*     | AlignOfE _ | UnOp _  | BinOp  _  | Question _ *)
(*     | CastE _  | AddrOf _  | AddrOfLabel _  | StartOf _ -> "" *)

and fixExpr (fname : string) (expr: exp) : string =
  match expr with
  | Lval a -> fixLval fname a
  | UnOp (unop, e1, typ) -> fixExpr fname e1
  | BinOp (binop, e1,e2, typ) -> let str1 = fixExpr  fname e1 in
                                 let str2 = fixExpr fname e2 in
                                 str1 ^ str2
  | Question (e1,e2,e3,typ) -> let str1 = fixExpr  fname e1 in
                               let str2 = fixExpr fname e2 in
                               let str3 = fixExpr fname e3 in
                                 str1 ^ str2 ^ str3
  | CastE (typ, e) -> let str1 = fixExpr fname e in str1
  | Const _
  | SizeOf _  | SizeOfE _ | SizeOfStr _  | AlignOf _
  | AlignOfE _
  | AddrOf _  | AddrOfLabel _  | StartOf _ -> ""

and fixinstrs (fname : string) (ins:instr list) : string =
  match ins with
  | i :: rest-> let s,b = fixInstr fname i in
                  if b then(s ^";" ^ (fixinstrs fname rest)) else (fixinstrs fname rest)
    | [] -> ""

and fixInstr (fname : string) (i : instr): string* bool  =
  match i with
  | Set _  -> "", false
  | Call (_, (Lval (Var a, NoOffset)), exprs ,location) when (a.vname = "free" || a.vname = "malloc")   ->  a.vname, true  (* todo : exprs *)
  | Call (_,((Lval (Var a, _)) as e1), exps, loc) ->
     let str1 = fixExpr fname e1 in
     if a.vname = fname then ("a",true) else
       (if (String.length str1) > 0 then (str1,true) else ("",false))
  | Call _ -> "",false
  | Asm _-> "",false

and findMorF (str: string): bool =
  let b =  (String.contains str 'm') || (String.contains str 'f') in
  b

and isContainsSemi (str: string) : bool =
  let length = String.length str in
  if (length>0&& (findMorF str) )then
    (
      let substr = String.sub str (length-1) 1 in
      if substr = ")" then false else
        (
          if length < 7 then (String.contains str ';') else
            (
              let substr2 = String.sub str (length-7) 7 in
              if (String.contains substr2 ';') then true else false
            )
        )
    )
  else
    false

and deleteSemi (str: string) : string =
  let length = String.length str in
  if (length > 0) then
    (
      let substr = String.sub str (length-1) 1 in
      if substr = ";" then String.sub str 0 (length-1)
      else str
    )
  else ""

and fixStmt (fname : string) (s : stmt) : string =
  match s.skind with
  | Instr il ->
    let str = fixinstrs fname il in
    deleteSemi str
  | If(_,tb,fb,_) ->
     let sb1 = fixBlock fname tb in
     let sb2 = fixBlock fname fb in
     let b1 = findMorF sb1 in
     let b2 = findMorF sb2 in
     begin
     match (b1,b2) with
       (true, true) ->
         (
           let b3 = isContainsSemi sb1  in
           let b4 = isContainsSemi sb2  in
           match(b3, b4)  with
               (true ,true ) ->  "(" ^ "("^sb1^")" ^  " + "  ^"("^ sb2 ^")" ^ ")"
             | (true, false)->   "(" ^ "("^sb1^")" ^  " + " ^ sb2 ^ ")"
             | (false,true)->  "("^sb1 ^  " + "  ^"("^ sb2 ^")" ^ ")"
             | (false, false) ->  "(" ^sb1 ^  " + "  ^ sb2  ^ ")"
         )
     | (true, false) ->
       ( let nstr= ( if (String.length sb2) >0 then sb2 else "0" ) in
         let b3 = isContainsSemi sb1  in
         (* print_string (sb1 ^"   " ^string_of_bool b3 ^ "   2\n"); *)
         if b3 then   "(" ^ "("^sb1^")" ^  " + " ^ (deleteSemi nstr) ^ ")" else
           "(" ^sb1 ^  " + "  ^ (deleteSemi nstr)  ^ ")"
       )
     | (false, true) ->
       ( let nstr =(if (String.length sb1) > 0 then sb1 else "0" ) in
         let b3 = isContainsSemi sb2  in
         if b3 then   "("^ (deleteSemi nstr) ^  " + "  ^"("^ sb2 ^")" ^ ")"
         else "(" ^ (deleteSemi nstr) ^  " + "  ^ sb2  ^ ")"
       )
     | (false, false) ->
        let nstr1 = (if (String.length sb1)>0 then sb1 else "0") in
        let nstr2 = (if (String.length sb2)>0 then sb2 else "0") in
        "(" ^ (deleteSemi nstr1) ^  " + "  ^ (deleteSemi nstr2)  ^ ")"
     end
  | Switch(_,b,_,_) ->
     let sb = fixBlock fname b in
     let b= findMorF sb in
     begin
       match b with
         true ->   "(" ^ sb ^ ")"
       | false -> "0"
     end
  | Loop(b,_,_,_) ->
     let sb = fixBlock fname b in
     let b = findMorF sb in
     begin
       match b with
           true ->  "(ua." ^sb ^ "a)"
       | false -> "(ua." ^ "0" ^ ";a)"
     end
  | Block b ->
     fixBlock fname b
  | TryFinally(b1, b2, _) ->
    "(" ^ (fixBlock fname b1) ^ " f+ " ^ (fixBlock fname b2 )^ ")"
  | TryExcept(b1,_,b2,_) ->
     "(" ^  (fixBlock fname b1 ) ^  " try+ "  ^ (fixBlock fname b2 )  ^ ")"
  | Return (None, loc) -> ""
  | Return (Some expr, loc) -> fixExpr fname expr
  | Goto _ -> ""
  | Break _ -> ""
  | Continue _ -> ""
  | _ -> print_string " stms unknown "; ""

and fixstmts (fname) (stmts: stmt list) : string =
  match stmts with
      [] -> ""
    | s:: [] ->  (fixStmt fname s)
    | s :: rest ->let str = ( fixStmt fname s) in
                  if (String.length str) > 0 then ( deleteSemi str) ^ ";"^ (fixstmts fname rest)  else (fixstmts fname rest)

and fixBlock (fname : string) (b : block)  = fixstmts fname b.bstmts

and fixFunction (fd : fundec)  = fixBlock (fd.svar.vname) fd.sbody

and printfuns (flists: (string*string)list) : unit  =
  match flists with
    (a,b) :: rest ->( if ( a = "") then ()
                      else
                        begin
                          print_string a; print_string ":  "; print_string (deleteSemi b ); print_newline ();
                        printfuns rest
                        end)
  | [] -> ()

let abstract (f : file) : unit =
  try
    (  List.iter (fun g ->
                  match g with
                  | GFun (fd, loc)  ->
                     if (fd.svar.vname = "main") then
                       ()
                     else (
                       let nstr = fixFunction fd in
                       if (String.contains nstr 'a') then
                         (
                           funclist :=  (fd.svar.vname, "(ua." ^ "(" ^nstr^")" ^")") :: !funclist
                         )
                       else
                         (
                           funclist :=  (fd.svar.vname, nstr) :: !funclist
                         )
                     )
                  | _->() )
                 f.globals );

    (  List.iter (fun g ->
                  match g with
                  | GFun (fd, loc) ->
                     if (fd.svar.vname = "main") then
                       funclist :=  (fd.svar.vname, fixFunction fd) :: !funclist
                     else ()
                  | _ -> () )
                 f.globals );

    print_newline ();
    printfuns funclist.contents;
    print_newline ();

  with
    _ -> print_string "Error: abs.ml"; print_newline ()
