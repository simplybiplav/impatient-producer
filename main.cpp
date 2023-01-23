#include<iostream>
#include <queue>
#include <unistd.h>
#include <set>
#include <thread>
using namespace std;

const string commands[] = {"read", "write", "open" , "close"};


class Message {
public:
    int device_id;
    string command;
    Message()
    {
        device_id = rand() % 255;
        command = commands [rand() % 4];
    }
    const bool operator<( const Message& m2) const
    {
        if (device_id < m2.device_id && command.compare(m2.command) != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int producer(queue<Message>& request,queue<Message> reply)
{
    set<Message> pollMsg; 
    pair<set<Message>::iterator, bool> insert_ret;
    while(1)
    {
        while(pollMsg.size() < 10 )
        {
            Message m;
            pollMsg.insert(m);
        }
        for (set<Message>::iterator it = pollMsg.begin(); it != pollMsg.end(); ++it)
        {
            request.push(*it);
        }
        for(;  reply.size() !=0;)
        {
            pollMsg.erase(reply.front());
            reply.pop();
        }
    
    }

    return 0;
}


int consumer(queue<Message>& request,queue<Message> reply)
{
    while (1)
    {
        for(;  request.size() !=0;)
        {
            Message m = request.front();
            request.pop();
            sleep( m.device_id %5); // mimicing io-operation with sleep
            reply.push(m);
        }
    }
    return 0;
}


int main()
{
    queue<Message> command_request_queue;
    queue<Message> command_reply_queue;
    thread producer_thread(producer, std::ref(command_request_queue), command_reply_queue); 
    thread consumer_thread(consumer, std::ref(command_request_queue), command_reply_queue); 

    sleep(600);
    return 0;
}
