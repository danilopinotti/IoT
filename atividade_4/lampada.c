#include "contiki.h"
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/rpl/rpl.h"
#include "dev/leds.h"
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include "contiki-net.h"
#include "rest-engine.h"

#include "sys/node-id.h"

// Recursos REST
extern resource_t
  res_hello,
  res_mirror,
  res_chunks,
  res_separate,
  res_push,
  res_event,
  res_sub,
  res_b1_sep_b2;
extern resource_t res_leds, res_toggle, res_ledstatus;


PROCESS(lampada_process,"lampada");
AUTOSTART_PROCESSES(&lampada_process);

void
set_prefix_64(uip_ipaddr_t *prefix_64) {
}

PROCESS_THREAD(lampada_process, ev, data) {

  PROCESS_BEGIN();

     NETSTACK_RDC.off(1); 

     printf ("Lampada ok\n");

     rest_init_engine();
     rest_activate_resource(&res_hello, "test/hello");
     rest_activate_resource(&res_toggle, "actuators/toggle");
     rest_activate_resource(&res_ledstatus, "actuators/ledstatus");

     while (1) {

        PROCESS_YIELD();

     }

  PROCESS_END();

}

