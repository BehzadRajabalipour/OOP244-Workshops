/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7
// Version 1.0
// Description
// Professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/

#include<iostream>
#include "Truck.h"
#include "Truck.h" // intentional (testing duplicate inclusion)
#include "MotorVehicle.h"
#include "MotorVehicle.h" // intentional (testing duplicate inclusion)

using namespace std;
using namespace sdds;

// Function to print a header with a title.
void printHeader(const char* title)
{
    char oldFill = cout.fill('-');
    cout.width(40);
    cout << "" << endl;

    cout << "|> " << title << endl;

    cout.fill('-');
    cout.width(40);
    cout << "" << endl;
    cout.fill(oldFill);
}

// Function to move a truck to a destination and load cargo.
void moveAndLoad(Truck& aTruck, const char* destination, double cargo)
{
    aTruck.moveTo(destination); // Move the truck to the specified destination.
    if (aTruck.addCargo(cargo)) // Try to add cargo to the truck.
        cout << "Cargo loaded!\n";
    else
        cout << "Adding cargo failed!\n";
    cout << aTruck << endl << endl;
}

// Function to move a truck to a destination and unload cargo.
void moveAndUnload(Truck& aTruck, const char* destination)
{
    aTruck.moveTo(destination); // Move the truck to the specified destination.
    if (aTruck.unloadCargo()) // Try to unload cargo from the truck.
        cout << "Cargo unloaded!\n";
    else
        cout << "Unloading cargo failed!\n";
    cout << aTruck << endl << endl;
}

int main()
{
    {
        printHeader("T1: Vehicle");

        MotorVehicle aVehicle("VVV-111", 2010); // Create a MotorVehicle object.
        cout << aVehicle << endl << endl; // Output the vehicle information.

        aVehicle.moveTo("Downtown Toronto"); // Move the vehicle to a different location.
        aVehicle.moveTo("Mississauga");
        aVehicle.moveTo("North York");

        cout << endl << aVehicle << endl << endl; // Output the updated vehicle information.

        printHeader("T2: Read/Write");
        cin >> aVehicle; // Read vehicle information from the user.
        cout << endl << aVehicle << endl << endl; // Output the updated vehicle information.
    }

    {
        printHeader("T3: Truck");

        Truck aTruck("T-1111", 2015, 5432, "Toronto HQ"); // Create a Truck object.
        cout << endl;

        moveAndLoad(aTruck, "Toronto Deposit", 2345); // Move and load cargo.
        moveAndLoad(aTruck, "Montreal", 3456);
        moveAndLoad(aTruck, "New York", 4567);

        moveAndUnload(aTruck, "New Jersey"); // Move and unload cargo.
        moveAndUnload(aTruck, "Toronto");

        printHeader("T4: Read/Write");
        cin >> aTruck; // Read truck information from the user.
        cout << endl << (MotorVehicle)aTruck; // Output the truck information as a MotorVehicle (testing casting).
        cout << endl << aTruck << endl << endl; // Output the updated truck information.
    }
}
