import time
import logging
import asyncio
from aiocoap import *

logging.basicConfig(level=logging.INFO)

@asyncio.coroutine

def getStatusExec(s_id, future):
  s_id = str(s_id)
  protocol = yield from Context.create_client_context()
  request = Message(code=GET)
  request.set_request_uri('coap://[cafe::c30c:0:0:'+s_id+']/actuators/ledstatus')
  try:
    response = yield from protocol.request(request).response
  except Exception as e:
    print('Failed to fetch resource:')
    print(e)
  else:
    #print('Result: %s\n%r'%(response.code, response.payload))
    future.set_result(response.payload)

def getStatus(s_id):
  future = asyncio.Future()
  asyncio.ensure_future(getStatusExec(s_id, future))
  asyncio.get_event_loop().run_until_complete(future)
  print("RESULTADO: "+future.result())
  return future.result()

def toggle(s_id):
  asyncio.get_event_loop().run_until_complete(toggleExec(s_id))

def toggleExec(s_id):
  s_id = str(s_id)
  protocol = yield from Context.create_client_context()
  request = Message(code=POST)
  request.set_request_uri('coap://[cafe::c30c:0:0:'+s_id+']/actuators/toggle')
  try:
    response = yield from protocol.request(request).response
  except Exception as e:
    print('Failed to fetch resource:')
    print(e)
  else:
    print('Result: %s\n%r'%(response.code, response.payload))

def turnOff(s_id):
  if getStatus(s_id) == "ON":
    time.sleep(0.1)
    toggle(s_id)

def turnOn(s_id):
  if getStatus(s_id) == "OFF":
    time.sleep(0.1)
    toggle(s_id)
  
