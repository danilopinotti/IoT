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

  uip_ip6addr(&ipaddr, 0xcafe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2);
  uip_ds6_addr_add(&ipaddr, 0, ADDR_MANUAL); 

  static uip_ipaddr_t remote_ipaddr;
  uip_ip6addr(&remote_ipaddr, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3); 
  static struct uip_udp_conn *client_udp;
  client_udp = udp_new(NULL,0,NULL);
  static char buf[30];

  //Time to wait RPL routes
  static struct etimer et;
  etimer_set(&et, 30 * CLOCK_SECOND);
  PROCESS_YIELD(); 

  sprintf(buf, "TESTE");
   
  uip_udp_packet_sendto(client_udp,buf,

                         strlen(buf),

                         &remote_ipaddr,

                         UIP_HTONS(5000));

  printf ("Sender funcionando!\n");

  PROCESS_END();

}
