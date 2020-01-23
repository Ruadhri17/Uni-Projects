#include "customer.h"

Customer::Customer(string n, string s, string e, long t, string id)
{
    name = n;
    surname = s;
    email = e;
    telephone = t;
    customer_id = id;
}
Customer::~Customer()
{
}
string Customer::get_id()
{
    return customer_id;
}
string Customer::get_name()
{
    return name;
}
string Customer::get_surname()
{
    return surname;
}
long Customer::get_telephone()
{
    return telephone;
}
string Customer::get_email()
{
    return email;
}
void Customer::set_name(string xname)
{
    name = xname;
}
void Customer::set_surname(string xsurname)
{
    surname = xsurname;
}
void Customer::set_telephone(long xtelephone)
{
    telephone = xtelephone;
}
void Customer::set_email(string xemail)
{
    email = xemail;
}