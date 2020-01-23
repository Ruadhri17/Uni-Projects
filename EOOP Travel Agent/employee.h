#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>
#include <iomanip>
#include <time.h>
#include "trip.h"

using namespace std;

enum worker
{
    AGENT,
    HAVE_NO_TRIP,
    HAVE_ONE_TRIP,
};

class Employee
{
private:
    bool type;
    string name;
    string surname;
    string email;
    long telephone;
    string employee_id;
    worker state;

public:
    Employee(bool t, string n, string s, string e, long tel, string id, worker stat); //done
    ~Employee();                                                                      //done
    void add_customer(int num_of_customers, vector<Trip> &tlist, int choice);         //done
    void remove_customer(vector<Trip> &tlist, string id, int choice);                 //done
    void edit_customer(vector<Trip> &tlist, string id, int choice);                   //done
    void print();                                                                     //done
    string remove_numbers(string words);                                              //done
    bool get_type();                                                                  //done
    string get_name();                                                                //done
    string get_surname();                                                             //done
    string get_email();                                                               //done
    long get_telephone();                                                             //done
    string get_id();
    worker get_state();                  //done
    void set_name(string xname);         //done
    void set_surname(string xsurname);   //done
    void set_email(string xemail);       //done
    void set_telephone(long xtelephone); //done
    void set_state(worker xstate);
};
#endif
