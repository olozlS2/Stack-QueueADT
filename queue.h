/*
** NAME : Eunji Lee
** FILE : queue.h
** CLASS: CS163 Karla Fant
** ASSGN: Assignment2
*/

#include "stack.h"

// q_node structure is for queue ADT and it contains road_trip object and q_node pointer.
struct q_node
{
        road_trip trips;
        q_node * next;
};

// Class queue contains enqueue for add, dequeue for remove, peek for retrieve, display functions and a funtion if a node is empty
// Adding will be done at the end of the list with rear pointer and removing will be dont in the beginning of the list with rear->next pointer by the definition of queue.
class queue
{
        public:
                queue();
                ~queue();
                int display();
                int display(q_node * rear);
                int enqueue(const road_trip &);
                bool isEmpty(road_trip &);
                int dequeue();
                int peek(road_trip &);
                int peek(road_trip &, q_node * rear);
        private:
                q_node * rear;
};
