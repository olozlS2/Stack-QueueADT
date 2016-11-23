/*
** NAME : Eunji Lee
** FILE : stack.h
** CLASS: CS163 Karla Fant
** ASSGN: Assignment2
*/

// The purpose of this program is to help people who would like to organize their road trip plans and the progress of their trip.
// Road trip plans are stored in a circular linked list (Queue ADT) and where they have been is stored in a linear linked list of arrays (Stack ADT).
#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

// Class road_trip contains all information of road trip for both queue and stack ADTs.
// It contains name and location of stops, information of lodging reservation, rating to lodginging, gas spent, and distance between two stops in miles.
class road_trip
{
        public:
                road_trip();
                ~road_trip();
                int create_trip(char * name, char * location, char * lodging, int rating, float gas, float miles);
                int edit_trip(int rating, float gas);
                void copy_trip(const road_trip new_trip);
                bool compare(const road_trip & found);
                bool isEmpty();
                void display();
                void display2(); // display when addtional data is inserted
        private:
                char * name;
                char * location;
                char * lodging;
                int rating;
                float gas;
                float miles;
};

// s_node structure is for stack ADT and it contains road_trip pointer and s_node pointer.
// The reason why it has road_trip pointer is that for stack ADT, a LLL of arrays is used.
struct s_node
{
        road_trip * trips;
        s_node * next;
};

// The size of each array is MAX=5
const int MAX = 5;

// Class stack contains push for add, pop for remove, peek for retrieve, display funtions and a function if a node is empty.
// Adding and removing will be done in the beginning of list with head pointer by the definition of stack.
class stack
{
        public:
                stack();
                ~stack();
                void display();
                void display(s_node * head);
                int push(const road_trip & new_trip);
                int pop();
                int peek(road_trip&)const;
                bool isEmpty();
        private:
                s_node * head;
                int top_index;
};
