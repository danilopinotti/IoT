#include "net/ip/uip-udp-packet.h" 

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
  uip_ip6addr(&ipaddr, 0xcafe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3);
  uip_ds6_addr_add(&ipaddr, 0, ADDR_MANUAL); 

  static struct uip_udp_conn *udp_server;
  udp_server = udp_new(NULL,0,NULL);
  udp_bind(udp_server, UIP_HTONS(5000));

  printf ("Receiver funcionando!\n");

  PROCESS_WAIT_EVENT();
  if(ev == tcpip_event) {
     static char *appdata;
     appdata = (char *)uip_appdata;
     appdata[uip_datalen()] = 0;
     printf("%s \n",appdata);
    } 


  PROCESS_END();

}
