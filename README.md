# impatient-producer

## Problem Description 

Producer sends messages to consumer to process the messages. The consumer receives the messages and process it and replies back the same message when it has completed.

message has two fields
  - device-id ( 0 - 255)
  - command ( read, write, open, close)
  
It takes 1-5 seconds to process the message. The time taken to process depends on device id ( process time = device-id mod 5 ).

The producer sends command for 10 different devices every time. Producer is very impatient, doesn't wait for reply and send messages constantly.

Consider cpu is multi-core, and os is standard linux. Multiple consumers can also be implemented.

The c++ code is just to provide a initial framework to understand and start with. It compiles on linux, though it has many deliberate bugs. One can choose to work on this code as base or try independantly. One can choose c or rust for implementation as well. 

Please optimize the consumer to handle impatient producer. Ensure code is readable, so that we can understand your thought process. 


