
/**
 * \file
 *         A very simple Contiki application showing how Contiki programs look
 * \author
 *         Adam Dunkels <adam@sics.se>
 */

#include "contiki.h"
#include "dev/leds.h"
#include "dev/light-sensor.h"
#include "dev/button-sensor.h"
#include "sys/etimer.h"

#include <stdio.h> /* For printf() */
/*---------------------------------------------------------------------------*/
PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);
/*---------------------------------------------------------------------------*/

PROCESS_THREAD(hello_world_process, ev, data)
{
  PROCESS_BEGIN();
  SENSORS_ACTIVATE(button_sensor);
  SENSORS_ACTIVATE(light_sensor);
  
  static int counter = 0;
  static struct etimer timer;
  etimer_set(&timer, CLOCK_SECOND*4);

  while(1){

   PROCESS_WAIT_EVENT();
   if(ev == sensors_event && data == &button_sensor && !etimer_expired(&timer)){
     counter++;
     printf("Button press!");
     leds_toggle(LEDS_ALL);
     printf("Light: \%u\nCounter: \%u\n", light_sensor.value(0), counter);
   }

   if(etimer_expired(&timer)){
     leds_toggle(LEDS_ALL);
     etimer_reset(&timer);
     printf("Timer !\n");
   }

  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
