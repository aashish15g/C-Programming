
// Author:  Aashish Ganeshkumar
//---------------------------------------
#include <iostream>
#include "Spaceship.h"
using namespace std;

//---------------------------------------
// Functions called from the main program
//---------------------------------------
void PrintMenu()
{
    // Print out menu for user to choose from.
    cout << endl;
    cout << "OPTIONS:" << endl;

    cout << "0 - Quit" << endl;
    cout << "1 - Print my Spaceship's info" << endl;
    cout << "2 - Give my Spaceship a new name" << endl;
    cout << "3 - Give my Spaceship a new color" << endl;
    cout << "4 - Give my Spaceship a new crew size" << endl;
    cout << "5 - Give my Spaceship a new impulse speed" << endl;
    cout << "6 - Set shields up" << endl;
    cout << "7 - Set shields down" << endl;
    cout << "8 - Prepare for orbit" << endl;
    cout << "9 - End the orbit" << endl;
    cout << "10 - Get travel time (in days)" << endl;

    cout << endl;
}

int GetChoice()
{
    int Choice = 0;
    // Create a do while loop that prompts user for integer and store in variable
    // The loop will re-prompt the user if they enter a number that is less than 0 or greater than 10.
    do
    {
        cout << "Enter your choice: ";
        cin >> Choice;
    } while (Choice < 0 || Choice > 10);
    // return variable that stores integer.
    return (Choice);
}

//----------------------------------------------------------------
// Name;  travelDays
// Purpose:  calculates and returns the number of days it will take to travel
// Parameters:  Spaceship - the ship we're traveling on, pass by value
//              double - the distance to travel, in million km, pass by value
//----------------------------------------------------------------
double travelDays(const Spaceship ship, const double distance)
{
    double days = 0.0;
    // call a method to get the ship's current speed (in km/sec)
    long speed = ship.CurrentSpeed();
    // convert the speed to km/day
    long speed_per_day = speed * 86400; // 86400 seconds in a day
    // calculate the time needed in days
    days = (distance * 1000000) / speed_per_day;
    return (days);
}

//---------------------------------------
// The main program
//---------------------------------------
int main()
{

    // variables used in function calls
    string newName;
    string newColor;
    int newCrewSize;
    long newSpeed;
    double distance;
    int choice;

    // Use the default constructor to create defaultSpaceship
    Spaceship defaultSpaceship;
    cout << "defaultSpaceship\n";
    defaultSpaceship.Print();

    // Use the non-default constructor to create mySpaceship.
    Spaceship mySpaceship(10, "Varmps", "Purple", 100000, false);
    cout << "\nmySpaceship\n";
    mySpaceship.Print();

    // Use copy constructor to instantiate your spaceships.
    Spaceship copySpaceship(mySpaceship);
    cout << "\ncopySpaceship\n";
    copySpaceship.Print();

    do
    {

        PrintMenu();
        choice = GetChoice();
        cout << endl;

        switch (choice)
        {
        case 0:
            cout << "Exiting program." << endl;
            break;

        case 1:
            mySpaceship.Print();
            break;

        case 2:
            cout << "Enter a fabulous new name for mySpaceship: ";
            cin >> newName;
            mySpaceship.SetName(newName);
            break;

        case 3:
            cout << "Enter the extravagant new color for mySpaceship: ";
            cin >> newColor;
            mySpaceship.SetColor(newColor);
            break;

        case 4:
            do
            {
                cout << "What will be the new crew size for the spaceship (between 0 and 1000000)? ";
                cin >> newCrewSize;
            } while (newCrewSize < 0 || newCrewSize > 1000000);
            mySpaceship.SetCrewSize(newCrewSize);
            break;

        case 5:
            do
            {
                cout << "What will be the new impulse speed of the spaceship (between 0 and 2000000)? ";
                cin >> newSpeed;
            } while (newSpeed < 0 || newSpeed > 2000000);
            mySpaceship.SetImpulseSpeed(newSpeed);
            break;

        case 6:
            mySpaceship.OrbitStart();
            break;

        case 7:
            mySpaceship.OrbitEnd();
            break;

        case 8:
            mySpaceship.OrbitStart();
            cout << "Preparing for orbit.....are you ready?" << endl;
            break;

        case 9:
            mySpaceship.OrbitEnd();
            cout << "Ending orbit." << endl;
            break;

        case 10:
            do
            {
                cout << "How far are you going, in million kilometers (0 to 2500000)? ";
                cin >> distance;
            } while (distance < 0 || distance > 2500000);
            cout << "Travel time: " << travelDays(mySpaceship, distance) << " days." << endl;
            break;

        default:
            cout << "Not an option. Try again..." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}