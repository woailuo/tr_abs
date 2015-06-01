module F = Frontc
module C = Cil
module E = Errormsg

let parseOneFile (fname: string) : C.file =
  let cabs, cil = F.parse_with_cabs fname () in
  Rmtmps.removeUnusedTemps cil;
  cil

let main (): unit =
  C.print_CIL_Input := true;
  C.lineLength := 100000;
  C.warnTruncate := false;
  E.colorFlag := true;
  Cabs2cil.doCollapseCallCast := true;

  let fname = Sys.argv.(1) in (* file name *)
  let file =  parseOneFile fname in
  let fnum = Sys.argv.(2) in (* 1: trans and abstract  ;     2 : abstract *)
  (
    match fnum with
      "1" ->(   Trans.transfor(file);  Abs.abstract (file);
              try
                let channel = open_out "rewritten_file.c" in
                (C.dumpFile (!C.printerForMaincil) channel "rewritten_file.c") file;
                close_out channel
              with
                _ -> print_string " \n Couldn't open file \n"  )
    | "2" -> Abs.abstract (file)
    | _ -> print_string " please input number 1 or 2 after file name \n"
  )

let _ = main ();;
