#ifndef _AGENCY_H_
#define _AGENCY_H_
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>
#include <iomanip>
#include <time.h>
#include "employee.h"

using namespace std;

class Travel_agency
{
private:
    string user_name;
    string user_id;
    int num_of_agents;
    int num_of_supervisors;
    int agents_limit;
    int supervisors_limit;
    int num_of_trips;
    int trip_limit;
    int num_of_customers;
    bool is_logged;
    vector<Employee> elist;
    vector<Trip> tlist;
    struct tm *date_as_struct; //date as struct 
    string date_as_string; // date as string
    time_t date_as_seconds; //date as seconds from 1900
public:
    Travel_agency();
    ~Travel_agency();
    void log_user();
    void add_employee();
    void remove_employee(string id);
    void edit_employee(string id);
    void print_employee();
    void add_employee_to_trip(string id_employee, string id_trip);
    void add_trip();
    void remove_trip(string id);
    void edit_trip(string id);
    void print_trip();
    void main_menu();
    string remove_numbers(string words);
    void travel_in_time();
    void random_event();
};
#endif
