#include "net/rpl/rpl.h"

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

  rpl_dag_t *dag; 

  uip_ip6addr(&ipaddr, 0xcafe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0);

  dag = rpl_set_root(RPL_DEFAULT_INSTANCE, (uip_ip6addr_t *)&ipaddr);

  rpl_set_prefix(dag, &ipaddr, 64);

  printf ("Sink funcionando!\n");

  PROCESS_END();

}
