open Cil

module E = Errormsg

let str = ref ""
let funclist = ref (("","") :: [])

(* let rec fixLval (lv: lval): string = *)
(*   match lv with *)
(*       (Var a, NoOffset) when (a.vname = "malloc" || a.vname = "free"）->  a.vname *)
(*     | (Mem exp, _) ->  *)
(*     | (Var a,_)  -> ( *)
(*       try *)
(*         (List.assoc a.vname funclist.contents) ^ ";" *)
(*       with *)
(*           _ -> "" *)
(*     ) *)
(*     | _ -> "" *)

(* and fixCallExpr (expr: exp): string = *)
(*   match expr with *)
(*     | Lval a -> fixLval  a *)
(*     | Const _ *)
(*     | SizeOf _  | SizeOfE _ | SizeOfStr _  | AlignOf _ *)
(*     | AlignOfE _ | UnOp _  | BinOp  _  | Question _ *)
(*     | CastE _  | AddrOf _  | AddrOfLabel _  | StartOf _ -> "" *)

let rec  fixinstrs (ins:instr list) : string =
  match ins with
    | i :: rest-> let s,b = fixInstr i in
                   if b then (s^";" ^ (fixinstrs rest)) else (fixinstrs rest)
    | [] -> ""

and fixInstr (i : instr): string* bool  =
  match i with
  | Set _  -> "", false
  | Call (_, (Lval (Var a, NoOffset)), exprs ,location) when (a.vname = "free" || a.vname = "malloc")   ->
         a.vname, true  (* fixCallExpr expr *)(* todo : exprs *)
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
  if (length > 0) then (String.sub str 0 (length-1)) else ""

and fixStmt (s : stmt) : string =
  match s.skind with
  | Instr il ->
    let str = fixinstrs il in
    deleteSemi str
  | If(_,tb,fb,_) ->
     let sb1 = fixBlock tb in
     let sb2 = fixBlock fb in
     let b1 = findMorF sb1 in
     let b2 = findMorF sb2 in
     begin
     match (b1,b2) with
       (true, true) ->
         (
           let b3 = isContainsSemi sb1  in
           let b4 = isContainsSemi sb2  in
           (* print_string (sb1 ^ "  1\n"); *)
           (* print_string (sb2 ^ "   1\n"); *)
           match(b3, b4)  with
               (true ,true ) ->  "(" ^ "("^sb1^")" ^  " + "  ^"("^ sb2 ^")" ^ ")"
             | (true, false)->   "(" ^ "("^sb1^")" ^  " + " ^ sb2 ^ ")"
             | (false,true)->  "("^sb1 ^  " + "  ^"("^ sb2 ^")" ^ ")"
             | (false, false) ->  "(" ^sb1 ^  " + "  ^ sb2  ^ ")"
         )
     | (true, false) ->
       (
         let b3 = isContainsSemi sb1  in
         (* print_string (sb1 ^"   " ^string_of_bool b3 ^ "   2\n"); *)
         if b3 then   "(" ^ "("^sb1^")" ^  " + " ^ "0" ^ ")" else
           "(" ^sb1 ^  " + "  ^ "0"  ^ ")"
       )
     | (false, true) ->
       (
         let b3 = isContainsSemi sb2  in
         (* print_string (sb1 ^ "    3\n"); *)
         if b3 then   "("^"0" ^  " + "  ^"("^ sb2 ^")" ^ ")"
         else "(" ^"0" ^  " + "  ^ sb2  ^ ")"
       )
     | (false, false) ->  "(" ^ "0" ^  " + "  ^ "0"  ^ ")"
     end
  | Switch(_,b,_,_) ->
     let sb = fixBlock b in
     let b= findMorF sb in
     begin
       match b with
         true ->   " (" ^ sb ^ ") "
       | false -> "0"
     end
  | Loop(b,_,_,_) ->
     let sb = fixBlock b in
     let b = findMorF sb in
     begin
       match b with
           true ->  "(ua. " ^sb ^ "a)"
       | false -> "(ua. " ^ "0" ^ ";a)"
     end
  | Block b ->
     fixBlock b
  | TryFinally(b1, b2, _) ->
    "(" ^ (fixBlock b1) ^ " f+ " ^ (fixBlock b2 )^ " ) "
  | TryExcept(b1,_,b2,_) ->
     " ( " ^  (fixBlock b1 ) ^  " try+ "  ^ (fixBlock b2 )  ^ " ) "
  | Return _ -> ""
  | Goto _ -> ""
  | Break _ -> ""
  | Continue _ -> ""
  | _ -> print_string " stms unknown "; ""

and fixstmts (stmts: stmt list) : string =
  match stmts with
      [] -> ""
    | s:: [] ->  (fixStmt s)
    | s :: rest ->let str = ( fixStmt s) in
                  if (findMorF str) then str ^";" ^ (fixstmts rest)  else (fixstmts rest)

and fixBlock (b : block)  = fixstmts b.bstmts

and fixFunction (fd : fundec)  = fixBlock fd.sbody

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
                     else funclist :=  (fd.svar.vname, fixFunction fd) :: !funclist
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
