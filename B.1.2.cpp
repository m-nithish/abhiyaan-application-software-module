/*
-----------------------------------------------------------------------------------------------------------------
WE HAVE DEFINED MASTER,PUBLISHER AND SUBSCRIBER CLASSES AND A STRUCTURE CALLED TOPIC TO IMPLEMENT THE PUBLISHING 
AND SUBSCRIBING OF A MESSAGE.
----------------------------------------------------------------------------------------------------------------- 
*/
#include<iostream>
#include<list>
#include<string>

using namespace std;

//HERE WE DEFINE A STRUCTURE 'TOPIC' THAT HOLDS THE LIST OF SUBCRIBERS AND PUBLISHERS COMMUNICATING ON THAT TOPIC
//AND ALSO HOLDS A FUNCTION THAT PASSES ON THE MESSAGE FROM THE TOPIC TO THE SUBSCRIBERS.
struct topic{
public:
void receive_message(string message_m2t){
    cout<<"Message recieved from master to topic...publishing to subscribers...";
    list<subscriber*>::iterator it;
    for(it=subscribers.begin(),it!=subscribers.end(),++it)
    (*it)->update(message_m2t);
}
private:
list<subscriber*> subscribers;
list<publisher*> publishers;
string received_message;
};

//HERE WE DEFINE A SUBSCRIBER CLASS THAT RECIEVES THE MESSAGE FROM THE TOPIC AND UPDATES ITS VARIABLE 'message'.
class subscriber{
public:
    void update(string message_t2s){
    message=message_t2s;
    }
private:
string message;
}

/*
HERE WE DEFINE A MASTER CLASS THAT HOLDS FUNCTIONS TO ADD AND REMOVE SUBSCRIBERS AND PUBLISHERS TO A TOPIC
WE ASLO HAVE A FUNCTION THAT RECIEVES THE MESSAGE FROM THE PUBLISHER AND PASSES IT ON TO THE CORRESPONDING TOPIC
WE ALSO HAVE A LIST OF POINTERS TO THE TOPICS SO THAT THE MASTER CLASS INDIRECTLY HOLDS THE LIST OF ALL PUBLISHERS 
AND SUBSCRIBERS FOR EACH TOPIC
*/
class master{
public:
void subscribe(subscriber* s,topic* t){
t->subscribers.push_back(s);
}
void unsubscribe(subscriber* s,topic* t){
    t->subscribers.remove(s);
}
void publisher_add(publisher* p,topic* t){
    t->publishers.push_back(p);
}
void publisher_remove(publisher* p,topic* t){
    t->publishers.remove(p);
}
void publish_message(string message_p2m,topic* t){
    message_received=message_p2m;
    cout<<"The received message is"<<message_received;
    cout<<"Message received from publisher to master...publishing to topic...";
    t->receive_message(message_received);
}
private:
list<topic*> topics;
string message_received;
};

//THE PUBLISHER CLASS RECEIVES A MESSAGE FROM THE USER AND PASSES IT ON TO THE TOPIC IT CORRESPONDS TO
class publisher{
public:
void publish(string message_p2m,master* m,topic* t){
    cout<<"publishing message from publisher to master...";
    m->publish_message(message_p2m,t);
}
};
