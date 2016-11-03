#include "contiki.h"
#include "net/ip/uip.h"
#include "net/ipv6/uip-ds6.h"
#include "net/rpl/rpl.h"
#include "dev/button-sensor.h"
#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include "contiki-net.h"
#include "er-coap-engine.h"

#include "sys/node-id.h"

PROCESS(interruptor_process,"interruptor");
AUTOSTART_PROCESSES(&interruptor_process);

void
set_prefix_64(uip_ipaddr_t *prefix_64) {
}

void 
client_chunk_handler(void *response) {
  const uint8_t *chunk;
  int len = coap_get_payload(response, &chunk);
  printf("Resultado: |%.*s|\n", len, (char *)chunk);
}


PROCESS_THREAD(interruptor_process, ev, data) {

  PROCESS_BEGIN();

     SENSORS_ACTIVATE(button_sensor);

     NETSTACK_RDC.off(1); 

     printf ("Interruptor ok\n");

     static uip_ipaddr_t remote_ipaddr;
     uip_ip6addr(&remote_ipaddr, 0xcafe, 0x0, 0x0, 0x0, 0xc30c, 0x0, 0x0, node_id-6); 

     static coap_packet_t request[1];

     coap_init_engine();

     while (1) {
     
        PROCESS_YIELD();
       
        if(ev == sensors_event && data == &button_sensor) {
 
           printf ("POST /actuators/toggle\n"); 
           coap_init_message(request, COAP_TYPE_CON, COAP_POST, 0);
           coap_set_header_uri_path(request, "/actuators/toggle");
           COAP_BLOCKING_REQUEST(&remote_ipaddr, UIP_HTONS(5683), request, client_chunk_handler);

           printf ("GET /actuators/ledstatus\n"); 
           coap_init_message(request, COAP_TYPE_CON, COAP_GET, 0);
           coap_set_header_uri_path(request, "/actuators/ledstatus");
           COAP_BLOCKING_REQUEST(&remote_ipaddr, UIP_HTONS(5683), request, client_chunk_handler);

        }

     }     

  PROCESS_END();

}

