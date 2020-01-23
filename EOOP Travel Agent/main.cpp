#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>
#include <iomanip>
#include <time.h>
#include "agency.h"
using namespace std;

int main()
{
    system("clear");
    cout << " ######  #####    ####   ##  ##  ######  ##         ####    ####   ######  ##  ##   ####  ##  ##   " << endl;
    cout << "   ##    ##  ##  ##  ##  ##  ##  ####    ##        ##  ##  ##      ####    ### ##  ##      ####    " << endl;
    cout << "   ##    #####   ######   ####   ##      ##        ######  ##  ##  ##      ## ###  ##       ##     " << endl;
    cout << "   ##    ##  ##  ##  ##    ##    ######  ######    ##  ##   ####   ######  ##  ##   ####    ##     " << endl;
    getchar();
    Travel_agency start;
    start.main_menu();
    return 0;
}

/* TRAVEL AGENCY v1.0

- There can be max 3 agents
- There can be max 5 supervisors
- There can be max 5 trips
- ID is saved as "[number_of_created_object][First letter of function (A,S,T,C)]"
- A random even can occured, it's chance is 3 to 50
- To add trips and customers, we need to be logged in
- We can travel in time by 3, 7 or 14 days
- When trip is in progress, we cannot add/remove/edit customers and trip information
- phone number should consist of only numbers and should have 9 digits
- price of trip cannot be less than 500 zl
- Only one supervisor can be adjusted to trip and supervisor can be adjusted to more than one trip
- the only way to "free" supervisor from trip is to delete trip or supervisor or... leave the program
- if we want to log out we should leave the program
*/
