/*
** NAME : Eunji Lee
** FILE : stack.cpp
** CLASS: CS163 Karla Fant
** ASSGN: Assignment2
*/

#include "stack.h"

// Class road_trip
// Default constructor
road_trip::road_trip():name(NULL), location(NULL), lodging(NULL), rating(0), gas(0.0), miles(0.0){}

// Default destructor
road_trip::~road_trip(){}

// This function is to create a collection of road trip for each class.
// It takes 3 char*, 1 int, and 2 float inputs and returns int
int road_trip::create_trip(char * new_name, char * new_location, char * new_lodging, int new_rating, float new_gas, float new_miles)
{
        name = new char[strlen(new_name)+1];
        strcpy(name, new_name);
        location = new char[strlen(new_location)+1];
        strcpy(location, new_location);
        lodging = new char[strlen(new_lodging)+1];
        strcpy(lodging, new_lodging);
        rating = new_rating;
        gas = new_gas;
        miles = new_miles;

        return 1;
}

// This function is to add additional information into the existing data
// It takes int and float as an input and returns int
int road_trip::edit_trip(int new_rating, float new_gas)
{
        rating = new_rating;
        gas = new_gas;

        return 1;
}
// This function is to copy a collection of road trip information into another collection of road trip.
// It takes const road_trip object and no return
void road_trip::copy_trip(const road_trip new_trip)
{
        if(!new_trip.name || !new_trip.location || !new_trip.lodging || new_trip.miles == 0.0)
                return;
        if(name)
                delete[] name;
        if(location)
                delete[] location;
        if(lodging)
                delete[] lodging;
        if(miles != 0.0)
                miles = 0.0;
        if(gas != 0.0)
                gas = 0.0;
        if(rating != 0.0)
                rating = 0.0;


        name = new char[strlen(new_trip.name)+1];
        strcpy(name, new_trip.name);
        location = new char[strlen(new_trip.location)+1];
        strcpy(location, new_trip.location);
        lodging = new char[strlen(new_trip.lodging)+1];
        strcpy(lodging, new_trip.lodging);
        miles = new_trip.miles;
        gas = new_trip.gas;
        rating = new_trip.rating;
}

// This function is to compare if two road_trip objects are same
// It takes const road_trip object reference and returns bool
bool road_trip::compare(const road_trip & found)
{
        if(strcmp(name, found.name)==0 && strcmp(location, found.location)==0 && strcmp(lodging, found.lodging)==0 && (gas==found.gas) && (miles==found.miles) && (rating==found.rating))
                return 1;
        else
                return 0;
}

bool road_trip::isEmpty()
{
        if(name && location && lodging && miles != 0.0 && gas !=0.0 && rating !=0.0)
                return false;
        else
                return true;
}

// This function is to display the collection of road_trip for queue ADT
void road_trip::display()
{
        cout << "\nName : " << name <<endl;
        cout << "Location : " << location <<endl;
        cout << "Lodging info : " << lodging <<endl;
        cout << "Miles from the previous stop : " << miles << endl;
}

// This function is to display the collection of road_trip for stack ADT with additional information
void road_trip::display2()
{
        cout << "\nName : " << name <<endl;
        cout << "Location : " << location <<endl;
        cout << "Lodging info : " << lodging <<endl;
        cout << "Miles from the previous stop : " << miles << endl;
        if(rating==1)
                cout << "Rating : poor " << endl;
        if(rating==2)
                cout << "Rating : average " << endl;
        if(rating==3)
                cout << "Rating : good " << endl;
        if(rating==4)
                cout << "Rating : excellent " << endl;
        cout << "Gas spent : " << gas << " gallon"<<endl;
}

// Class stack
// Default constructor
stack::stack():head(NULL){}

// Default destructor
// Call pop function to remove everything in LLL of arrays
stack::~stack()
{
        pop();
}

// It's for adding a collection of road trip information into a LLL of arrays
int stack::push(const road_trip & new_trip)
{
        if(!head)
        {
                head = new s_node;
                head->next = NULL;
                head->trips = new road_trip[MAX];
                head->trips[top_index].copy_trip(new_trip);
                ++top_index;
        }
        else
        {
                if(top_index == MAX)
                {
                        s_node * temp = new s_node;
                        temp->trips = new road_trip[MAX];
                        top_index = 0;
                        temp->trips[top_index].copy_trip(new_trip);
                        temp->next = head;
                        head = temp;
                }
                else
                        head->trips[top_index].copy_trip(new_trip);
                ++top_index;
        }
        return 1;
}
// This function is to remove all data in the data structure
int stack::pop()
{
        if(head==NULL)
                return 0;
        else
        {
                if(top_index!=0)
                        --top_index;
                else
                {
                        s_node * temp = head;
                        if(head->next == NULL)
                                head = NULL;
                        else
                        {
                                head = head->next;
                                temp->next = NULL;
                                delete[] temp->trips;
                                delete temp;
                                top_index = MAX-1;
                        }
                }
                return 1;
        }
}

// This function is to retrieve if inputted data exists in the list
int stack::peek(road_trip & find)const
{
        if(!head)
                return 0;
        else
        {
                find.copy_trip(head->trips[top_index-1]);
                return 1;
        }
}

// This function is to display all data in the data structure
void stack::display()
{
        if(head == NULL)
                return;

        s_node * temp = head;
        int i=0;
        int turn = top_index-1;
        while(temp)
        {
                for(i=turn; i>=0; --i)
                {
                         temp->trips[i].display2();
                }
                turn = MAX-1;
                temp = temp->next;
        }
}

// This function is to check if the data structure is empty
bool stack::isEmpty()
{
        if(head == NULL)
                return true;
        else
                return false;
}
