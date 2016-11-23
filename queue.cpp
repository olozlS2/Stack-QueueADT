/*
** NAME : Eunji Lee
** FILE : queue.cpp
** CLASS: CS163 Karla Fant
** ASSGN: Assignment2
*/

#include "queue.h"

// Class queue
// Default contructor
queue::queue():rear(NULL){}

// Default destructor
// Call dequeue function to remove everything in CLL
queue::~queue()
{
        dequeue();
}

// This function is a wrapper function to display everything in the data structure
// Set head as rear->next and disconnect the list so that iteration stops
// After displaying all, reconnect the list
int queue::display()
{
        if(!rear)
                return 0;
        q_node * head = rear->next;
        rear->next = NULL;
        display(head);
        rear->next = head;
        return 1;
}

// This function is called in a wrapper function and does the real data structure work
int queue::display(q_node * head)
{
        if(!head)
                return 0;
        head->trips.display();
        return display(head->next);
}

// It's for adding a collection of road trip information at the end of a CLL
int queue::enqueue(const road_trip & new_trip)
{
        q_node * temp = new q_node;
        temp->trips.copy_trip(new_trip);
        if(rear == NULL)
        {
                rear = new q_node;
                rear = temp;
                rear->next = rear;
        }
        else if(rear->next == rear)
        {
                rear->next = temp;
                temp->next = rear;
                rear = temp;
        }
        else
        {
                temp->next = rear->next;
                rear->next = temp;
                rear = temp;
        }
        return 1;
}

// This function is to check if the data structure is empty
bool queue::isEmpty(road_trip & transfer)
{
        if(rear == NULL)
                return true;
        else
        {
                transfer.copy_trip(rear->next->trips);
                return false;
        }
}

// This function is to remove all data in the data structure
// Removing is done at the end of the list
int queue::dequeue()
{
        if(rear == NULL)
                return 0;
        else if(rear->next == rear)
        {
                rear->next = NULL;
                delete rear;
                rear = NULL;
                return 0;
        }
        else
        {
                q_node * temp = rear->next;
                rear->next = temp->next;
                temp->next = NULL;
                delete temp;
                temp = NULL;
                return 1;
        }
}

// This function is a wrapper function to retrieve if inputted data exists in the list
int queue::peek(road_trip & found)
{
        if(rear==NULL)
                return 0;
        q_node * head = rear->next;
        rear->next = NULL;
        int result = peek(found, head);
        rear->next = head;
        return result;
}

// This function is called in a wrapper function and does the real data structure work
int queue::peek(road_trip & found, q_node * head)
{
        if(head==NULL)
                return 0;
        if(head->trips.compare(found))
                return 1;
        return peek(found, head->next);
}
