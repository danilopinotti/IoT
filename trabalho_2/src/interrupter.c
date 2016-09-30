#include "net/ip/uip-udp-packet.h" 
#include "dev/button-sensor.h"
#include "contiki.h"
#include <stdio.h>
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"

PROCESS(skel_process, "Skel process");

AUTOSTART_PROCESSES(&skel_process);

PROCESS_THREAD(skel_process, ev, data)

{

  PROCESS_BEGIN();

  NETSTACK_RDC.off(1);

  static uip_ipaddr_t remote_ipaddr;
  uip_ip6addr(&remote_ipaddr, 0xcafe, 0x0, 0x0, 0x0, 0x212, 0x7403, 0x3, 0x303); 
  static struct uip_udp_conn *client_udp;
  client_udp = udp_new(NULL,0,NULL);
  static char command[30];

  printf ("Sender funcionando!\n");
  //Time to wait RPL routes
  PROCESS_YIELD(); 

  int status = 0; 

  if(ev == sensors_event && data == &button_sensor){

  if(status == 0){
    sprintf(command, "n");
    status = 1;
  }
  else if (status == 1){
    sprintf(command, "f");
    status = 0;
  }

  uip_udp_packet_sendto(client_udp,command,

                         strlen(command),

                         &remote_ipaddr,

                         UIP_HTONS(5000));
}

  PROCESS_END();

}
