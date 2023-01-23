# impatient-producer

## Problem Description 

Producer sends messages to consumer to process the messages. The consumer receives the messages and process it and replies back the same message when it has completed.

message has two fields
  - device-id ( 0 - 255)
  - command ( read, write, open, close)
  
It takes 1-5 seconds to process the message. The time taken to process depends on device id ( process time = device-id mod 5 ).

The producer sends command for 10 different devices every time. Producer is very impatient, doesn't wait for reply and send messages constantly.

Please optimize the consumer to handler impatient producer.
