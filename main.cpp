/*
** NAME : Eunji Lee
** FILE : main.cpp
** CLASS: CS163 Karla Fant
** ASSGN: Assignment2
*/

#include "queue.h"

const int SIZE = 100;

// This function is to know if the user wants to keep add/delete the stops
bool again()
{
        char ans;
        cin >> ans;
        if(ans == 'y' || ans == 'Y')
                return 1;
        else
                return 0;
}

int main()
{
        char name[SIZE], location[SIZE], lodging[SIZE];
        float miles=0.0;
        float gas=0.0;
        int rating=0;
        queue my_plan;
        stack my_experience;
        road_trip new_trip;


        // Queue - Users type in planning stops and they are inserted into a circular linked list
        cout << "\t<< List of planning stops >> " <<endl;
        do
        {
                cout << "Please enter a name of the stop : ";
                cin >> name; cin.ignore(SIZE, '\n');
                cout << "Please enter a location of the stop (City and State) : ";
                cin.get(location, SIZE); cin.ignore(SIZE, '\n');
                cout << "Please enter an info of lodging at the stop (Name, Add, and price) : ";
                cin.get(lodging, SIZE); cin.ignore(SIZE, '\n');
                cout << "Please enter how many miles it took from the privious stop to the stop : ";
                cin >> miles; cin.ignore(SIZE, '\n');
                // Dealing with exceptions
                if(miles<0.0 || miles >=10000.0)
                {
                        cout << "Invalid input "<<endl;
                        miles = 0.0;
                }
                new_trip.create_trip(name, location, lodging, rating, gas, miles);
                my_plan.enqueue(new_trip);
                // Check if data is inputted into the CLL well with peek function
                if(!my_plan.peek(new_trip))
                        cout << "Inputting process didn't work well"<<endl;
                cout << "\nDo you want to add a road trip? (y/n)";
        } while(again());

        if(!(miles<=0.0 || miles >=10000.0))
        {
                cout << "\t<< List of planning stops >> " <<endl;
                my_plan.display();

                // Stack - Dequeued data from the CLL goes into a linear linked list of arrays
                cout << "\nDo you want to delete a planned road trip? (y/n)";
                while(again())
                {
                        road_trip transfer; // hold dequeued data in order to insert into the stack
                        if(!my_plan.isEmpty(transfer))
                        {

                                transfer.display();
                                cout << "Please enter a rating to lodging(in scale 1~4 where 1 is poor and 4 is excellent) : ";
                                cin >> rating; cin.ignore(SIZE, '\n');
                                // Dealing with exceptions
                                if(rating<1 || rating>4)
                                {
                                        cout << "invalid input" <<endl;
                                        rating = 1;
                                }
                                cout << "Please enter how much was spent on gas for that part of the trip : ";
                                cin >> gas; cin.ignore(SIZE, '\n');
                                // Dealing with exceptions
                                if(gas<=0.0 || gas >=10000.0)
                                {
                                        cout << "Invalid input "<<endl;
                                        gas = 0.0;
                                }
                                // Add additional information into the road_trip object
                                transfer.edit_trip(rating, gas);
                                my_experience.push(transfer);
                                if(!my_experience.peek(transfer))
                                        cout << "Stack Inputting process didn't work well"<<endl;
                                if(my_plan.dequeue())
                                {
                                        cout << "\n\n\t<< List of planned stops after removing >> " <<endl;
                                        my_plan.display();
                                }
                        }
                        else
                                cout << "\nThe queue is empty"<<endl;
                        cout << "\nDo you want to delete a road trip? (y/n)";
                }
                cout << "\t<< List of experienced stops >> " <<endl;
                my_experience.display();

                // By popping the data from the stack, the traveler goes back to their original starting place
                cout << "\nDo you want to delete an experienced road trip? (y/n)";
                while(again())
                {
                        cout << "\n\n\t<< List of experienced stops after removing >> " <<endl;
                        if(!my_experience.isEmpty())
                        {
                                if(my_experience.pop())
                                        my_experience.display();
                        }
                        else
                                cout << "\nThe stack is empty"<<endl;
                        cout << "\nDo you want to delete a road trip? (y/n)";
                }
        }

}