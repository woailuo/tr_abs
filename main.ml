module F = Frontc
module C = Cil
module E = Errormsg

let str = ref " hello \n"

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

  let fname = Sys.argv.(1) in
  let file =  parseOneFile fname in
  Trans.transfor(file);
  try
  let c = open_out "output.c" in
  C.dumpFile (!C.printerForMaincil) c "output.c" file
  with
    _ -> print_string " \n Couldn't open file \n"

let _ = main ();;
