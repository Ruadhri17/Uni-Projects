#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>
#include <iomanip>
#include <time.h>

using namespace std;

class Customer
{
private:
    string name;
    string surname;
    string email;
    long telephone;
    string customer_id;

public:
    Customer(string n, string s, string e, long t, string id);
    ~Customer();
    string get_id();                                
    string get_name();                              
    string get_surname();                           
    long get_telephone();
    string get_email();                           
    void set_name(string xname);                    
    void set_surname(string xsurname);              
    void set_telephone(long xtelephone); 
    void set_email(string xemail);           
};

#endif