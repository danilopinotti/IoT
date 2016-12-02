import time
import logging
import asyncio
import re
from aiocoap import *

logging.basicConfig(level=logging.INFO)

@asyncio.coroutine

def getStatusExec(s_id):
  global lamp_response
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
    lamp_response = re.search(b"(ON|OFF)", response.payload).group().decode("utf-8")

def getStatus(s_id):
  asyncio.get_event_loop().run_until_complete(getStatusExec(s_id))
  return lamp_response

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
    toggle(s_id)

def turnOn(s_id):
  if getStatus(s_id) == "OFF":
    toggle(s_id)
  
