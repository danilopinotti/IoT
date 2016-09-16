#include "contiki.h"

#include <stdio.h>

#include "net/ip/uip.h"

#include "net/ipv6/uip-ds6.h"

PROCESS(skel_process, "Skel process");

AUTOSTART_PROCESSES(&skel_process);

PROCESS_THREAD(skel_process, ev, data)

{

  PROCESS_BEGIN();

  static uip_ipaddr_t ipaddr;

  uip_ip6addr(&ipaddr, 0xcafe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2);

  uip_ds6_addr_add(&ipaddr, 0, ADDR_MANUAL); 

  printf ("Receiver funcionando!\n");

  PROCESS_END();

}
