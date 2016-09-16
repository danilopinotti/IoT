#include "contiki.h"

#include <stdio.h>

PROCESS(skel_process, "Skel process");

AUTOSTART_PROCESSES(&skel_process);

PROCESS_THREAD(skel_process, ev, data)

{

  PROCESS_BEGIN();

  printf ("Sender funcionando!\n");

  PROCESS_END();

}
