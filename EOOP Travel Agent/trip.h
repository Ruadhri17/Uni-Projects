#ifndef _TRIP_H_
#define _TRIP_H_
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>
#include <iomanip>
#include <time.h>
#include "customer.h"

enum status {NOT_YET_BEGAN, IN_PROGRESS, ENDED};


using namespace std;

class Trip
{
private:
    string country;
    string city;
    long price;
    string hotel_name;
    string start_of_trip;
    string end_of_trip;
    string trip_id;
    vector<Customer> clist;
    status state;
    bool has_supervisor;
    string supervisor;
    string supervisor_id;

public:
    Trip(string cou, string cit, long p, string hn, string id, tm start, tm end);
    ~Trip();                                                                     
    void print();                                                                
    void choose_trip();                                                          
    string get_country();                                                        
    string get_city();                                                         
    long get_price();                                                           
    string get_hotel_name();         
    string get_id();                  
    string get_starting_date();
    string get_ending_date();
    status get_state();
    bool get_status();
    string get_supervisor_id();
    vector<Customer> &get_customers();                                           
    void set_country(string xcountry); 
    void set_city(string xcity);
    void set_hotel_name(string xhotel_name); 
    void set_price(long xprice);
    void set_starting_date(string xstart_of_trip);
    void set_ending_date(string xend_of_trip);
    void set_state(status xstate);
    void set_status(bool xstatus);
    void set_supervisor(string xsupervisor);
    void set_supervisor_id(string xsupervisor_id);
};
#endif