module F = Frontc
module C = Cil
module E = Errormsg

let parseOneFile (fname: string) : C.file =
  let cabs, cil = F.parse_with_cabs fname () in
  Rmtmps.removeUnusedTemps cil;
  cil


let  rec main (): unit =
  C.print_CIL_Input := true;
  C.lineLength := 100000;
  C.warnTruncate := false;
  E.colorFlag := true;
  Cabs2cil.doCollapseCallCast := true;

  try
    let fname = Sys.argv.(1) in (* file name *)
    let file =  parseOneFile fname in
    let fnum = Sys.argv.(2) in (* 1: trans and abstract  ;     2 : abstract only *)
    (
      match fnum with
          "1" ->(
            (try
               Trans.transfor(file);
             with
                 _ -> print_string " ------------ Error at trans.ml, please revise ----------\n"; exit 0);
            (try
               Abs.abstract (file);
             with
                 _ ->  print_string " ----------- Error at abstract.ml ---------- \n"; exit 0);
            try
              let channel = open_out "rewritten_file.c" in
              (C.dumpFile (!C.printerForMaincil) channel "rewritten_file.c") file;
              close_out channel
            with
                _ -> print_string " \n Couldn't open file \n"  )
        | "2" -> Abs.abstract (file)
        | _ -> print_string " please input number 1 or 2 after file name \n";
    )
  with
      Invalid_argument str ->  print_string str;
        print_string " :  please input file name and number 1 or 2 \n";
    | _ -> print_string " Error: at main.ml file \n"

let _ = main ();;
