#include "trip.h"
Trip::Trip(string cou, string cit, long p, string hn, string id, tm start, tm end)
{
    char bufor[64];
    country = cou;
    city = cit;
    price = p;
    hotel_name = hn;
    trip_id = id;
    strftime(bufor, 64, "%x", &start);
    start_of_trip = bufor;
    strftime(bufor, 64, "%x", &end);
    end_of_trip = bufor;
    state = NOT_YET_BEGAN;
    has_supervisor = false;
}
Trip::~Trip()
{
    clist.clear();
}
string Trip::get_country()
{
    return country;
}
string Trip::get_city()
{
    return city;
}
string Trip::get_hotel_name()
{
    return hotel_name;
}
long Trip::get_price()
{
    return price;
}
string Trip::get_id()
{
    return trip_id;
}
string Trip::get_starting_date()
{
    return start_of_trip;
}
string Trip::get_ending_date()
{
    return end_of_trip;
}
status Trip::get_state()
{
    return state;
}
bool Trip::get_status()
{
    return has_supervisor;
}
string Trip::get_supervisor_id()
{
    return supervisor_id;
}
void Trip::print()
{
    cout << "==================HOTEL  INFO==================" << endl;
    cout << "Country: " << country << endl
         << "City: " << city << endl
         << "Hotel's name: " << hotel_name << endl
         << "Price: " << price << " zl" << endl
         << "Duration: " << start_of_trip << "-" << end_of_trip << endl
         << "ID: " << trip_id << endl;
    if (has_supervisor == true)
        cout << "Supervisor: " << supervisor << endl;
    if (state == NOT_YET_BEGAN)
        cout << "Status: didnt't yet begin" << endl;
    if (state == IN_PROGRESS)
        cout << "Status: in progress" << endl;
    if (state == ENDED)
        cout << "Status: ended" << endl;
    cout << endl
         << "===============LIST OF CUSTOMERS===============" << endl;
    for (int k = 0; k < clist.size(); k++)
    {
        cout << k + 1 << ". " << clist[k].get_id() << " " << clist[k].get_name() << " " << clist[k].get_surname() << " " << clist[k].get_email() << " " << clist[k].get_telephone() << endl;
    }
    cout << "===============================================" << endl;
}
void Trip::choose_trip()
{
    cout << country << " - " << city << endl;
}
vector<Customer> &Trip::get_customers()
{
    return clist;
}
void Trip::set_country(string xcountry)
{
    country = xcountry;
}
void Trip::set_city(string xcity)
{
    city = xcity;
}
void Trip::set_hotel_name(string xhotel_name)
{
    hotel_name = xhotel_name;
}
void Trip::set_price(long xprice)
{
    price = xprice;
}
void Trip::set_starting_date(string xstart_of_trip)
{
    start_of_trip = xstart_of_trip;
}
void Trip::set_ending_date(string xend_of_trip)
{
    end_of_trip = xend_of_trip;
}
void Trip::set_state(status xstate)
{
    state = xstate;
}
void Trip::set_status(bool xstatus)
{
    has_supervisor = xstatus;
}
void Trip::set_supervisor(string xsupervisor)
{
    supervisor = xsupervisor;
}
void Trip::set_supervisor_id(string xsupervisor_id)
{
    supervisor_id = xsupervisor_id;
}