#include "agency.h"
Travel_agency::Travel_agency()
{
    num_of_agents = 0;
    agents_limit = 0;
    num_of_supervisors = 0;
    supervisors_limit = 0;
    num_of_trips = 0;
    num_of_customers = 0;
    trip_limit = 0;
    is_logged = false;
    char bufor[64];
    date_as_seconds = time(0);
    date_as_struct = gmtime(&date_as_seconds);
    date_as_struct->tm_year += 1900;
    strftime(bufor, 64, "%x", date_as_struct);
    date_as_string = bufor;
}
Travel_agency::~Travel_agency()
{
    elist.clear();
    tlist.clear();
}
void Travel_agency::main_menu()
{
    int choice1, choice2, choice3, choice4, choice5; // integers to manage particural part of menu
    int choice;
    string answer;
    string extra_answer;
    bool logic;
    ;
    do
    {
        logic = false;
        do
        {
            system("clear");
            cout << "What do you want to do?" << endl
                 << "[1] Log in" << endl
                 << "[2] Add object" << endl
                 << "[3] Remove object" << endl
                 << "[4] Edit object" << endl
                 << "[5] Print list of objects" << endl
                 << "[6] Travel in time" << endl
                 << "[0] Leave the program" << endl;
            if (is_logged == true)
                cout << "Login Status: Logged as " << user_name << endl;
            if (is_logged == false)
                cout << "Login Status: offline" << endl;
            cout << "date is: " << date_as_string << endl;
            cout << "Type the number to choose the option: ";
            cin >> choice1;
            if (cin.good() == true)
                if (choice1 >= 0 && choice1 <= 6)
                    logic = true;
                else
                {
                    cout << "This choice is not available, try again!" << endl;
                    cin.clear();
                }
            else
            {
                cout << "Your input is not a number, try again!" << endl;
                cin.clear();
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
            cout << "Press enter to continue..." << endl;
            getchar();
        } while (logic == false);

        switch (choice1)
        {
        case 1:
            log_user();
            break;
        case 2:
            do
            {
                logic = false;
                do
                {
                    system("clear");
                    cout << "What do you want to do?" << endl
                         << "[1] Add employee" << endl
                         << "[2] Add customer" << endl
                         << "[3] Add trip" << endl
                         << "[4] Add supervisor to trip" << endl
                         << "[0] Go back to main menu" << endl;
                    cout << "Type the number to choose the option: ";
                    cin >> choice2;
                    if (cin.good() == true)
                        if (choice2 >= 0 && choice2 <= 4)
                            logic = true;
                        else
                        {
                            cout << "This choice is not available, try again!" << endl;
                            cin.clear();
                        }
                    else
                    {
                        cout << "Your input is not a number, try again!" << endl;
                        cin.clear();
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                } while (logic == false);
                switch (choice2)
                {
                case 1:
                    add_employee();
                    break;
                case 2:
                    system("clear");
                    if (is_logged == false)
                    {
                        cout << "You are not logged in as agent, no permission to add customer!" << endl;
                        cout << "Press enter to continue..." << endl;
                        getchar();
                        break;
                    }
                    for (int k = 0; k < elist.size(); k++)
                    {
                        if (elist[k].get_id() == user_id)
                        {
                            if (tlist.empty() == true)
                            {
                                cout << "There is no trip to add customer" << endl;
                                cout << "Press enter to continue..." << endl;
                                getchar();
                                break;
                            }
                            logic = false;
                            do
                            {
                                system("clear");
                                for (int i = 0; i < tlist.size(); i++)
                                {
                                    cout << "[" << i + 1 << "] ";
                                    tlist[i].choose_trip();
                                }
                                cout << "[0] Leave" << endl;
                                cout << "Choose a destination to which you want to add customer: ";
                                cin >> choice;
                                if (cin.good() == true)
                                    if (choice >= 0 && choice <= tlist.size())
                                        logic = true;
                                    else
                                    {
                                        cout << "This choice is not available, try again!" << endl;
                                        cin.clear();
                                    }
                                else
                                {
                                    cout << "Your input is not a number, try again!" << endl;
                                    cin.clear();
                                }
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Press enter to continue..." << endl;
                                getchar();
                            } while (logic == false);
                            if (choice == 0)
                                break;
                            choice = choice - 1;
                            num_of_customers++;
                            elist[k].add_customer(num_of_customers, tlist, choice);
                        }
                    }
                    break;
                case 3:
                    add_trip();
                    break;
                case 4:
                    cout << "Enter id of supervisor: ";
                    cin >> answer;
                    cout << "Enter id of trip: ";
                    cin >> extra_answer;
                    add_employee_to_trip(answer, extra_answer);
                    break;
                default:
                    break;
                }
            } while (choice2 != 0);
            break;
        case 3:
            do
            {
                logic = false;
                do
                {
                    system("clear");
                    cout << "What do you want to do?" << endl
                         << "[1] Remove Employee" << endl
                         << "[2] Remove Customer" << endl
                         << "[3] Remove Trip" << endl
                         << "[0] Go back to main menu" << endl;
                    cout << "Type the number to choose the option: ";
                    cin >> choice3;
                    if (cin.good() == true)
                        if (choice3 >= 0 && choice3 <= 3)
                            logic = true;
                        else
                        {
                            cout << "This choice is not available, try again!" << endl;
                            cin.clear();
                        }
                    else
                    {
                        cout << "Your input is not a number, try again!" << endl;
                        cin.clear();
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                } while (logic == false);
                switch (choice3)
                {
                case 1:
                    system("clear");
                    cout << "Enter id which you want to remove: ";
                    cin >> answer;
                    remove_employee(answer);
                    break;
                case 2:
                    system("clear");
                    if (is_logged == false)
                    {
                        cout << "You are not logged in as agent, no permission to remove customer!" << endl;
                        cout << "Press enter to continue..." << endl;
                        getchar();
                        break;
                    }
                    for (int k = 0; k < elist.size(); k++)
                    {
                        if (elist[k].get_id() == user_id)
                        {
                            if (tlist.empty() == true)
                            {
                                cout << "There is no trip to remove customer" << endl;
                                cout << "Press enter to continue..." << endl;
                                getchar();
                                break;
                            }
                            logic = false;
                            do
                            {
                                system("clear");
                                for (int i = 0; i < tlist.size(); i++)
                                {
                                    cout << "[" << i + 1 << "] ";
                                    tlist[i].choose_trip();
                                }
                                cout << "[0] Leave" << endl;
                                cout << "Choose a destination in which you want to remove customer: ";
                                cin >> choice;
                                if (cin.good() == true)
                                    if (choice >= 0 && choice <= tlist.size())
                                        logic = true;
                                    else
                                    {
                                        cout << "This choice is not available, try again!" << endl;
                                        cin.clear();
                                    }
                                else
                                {
                                    cout << "Your input is not a number, try again!" << endl;
                                    cin.clear();
                                }
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Press enter to continue..." << endl;
                                getchar();
                            } while (logic == false);
                            if (choice == 0)
                                break;
                            choice = choice - 1;
                            cout << "Enter id which you want to remove: ";
                            cin >> answer;
                            elist[k].remove_customer(tlist, answer, choice);
                        }
                    }
                    break;
                case 3:
                    system("clear");
                    cout << "Enter id which you want to remove: ";
                    cin >> answer;
                    remove_trip(answer);
                    break;
                default:
                    break;
                }
            } while (choice3 != 0);
            break;
        case 4:
            do
            {
                logic = false;
                do
                {
                    system("clear");
                    cout << "What do you want to do?" << endl
                         << "[1] Edit Employee" << endl
                         << "[2] Edit Customer" << endl
                         << "[3] Edit Trip" << endl
                         << "[0] Go back to main menu" << endl;
                    cout << "Type the number to choose the option: ";
                    cin >> choice4;
                    if (cin.good() == true)
                        if (choice4 >= 0 && choice4 <= 3)
                            logic = true;
                        else
                        {
                            cout << "This choice is not available, try again!" << endl;
                            cin.clear();
                        }
                    else
                    {
                        cout << "Your input is not a number, try again!" << endl;
                        cin.clear();
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                } while (logic == false);
                switch (choice4)
                {
                case 1:
                    system("clear");
                    cout << "Enter id which you want to edit" << endl;
                    cin >> answer;
                    edit_employee(answer);
                    break;
                case 2:
                    system("clear");
                    if (is_logged == false)
                    {
                        cout << "You are not logged in as agent, no permission to remove customer!" << endl;
                        cout << "Press enter to continue..." << endl;
                        getchar();
                        break;
                    }
                    for (int k = 0; k < elist.size(); k++)
                    {
                        if (elist[k].get_id() == user_id)
                        {
                            if (tlist.empty() == true)
                            {
                                cout << "There is no trip to edit customer" << endl;
                                break;
                            }
                            logic = false;
                            do
                            {
                                system("clear");
                                for (int i = 0; i < tlist.size(); i++)
                                {
                                    cout << "[" << i + 1 << "] ";
                                    tlist[i].choose_trip();
                                }
                                cout << "[0] Leave" << endl;
                                cout << "Choose a destination in which you want to edit customer: ";
                                cin >> choice;
                                if (cin.good() == true)
                                    if (choice >= 0 && choice <= tlist.size())
                                        logic = true;
                                    else
                                    {
                                        cout << "This choice is not available, try again!" << endl;
                                        cin.clear();
                                    }
                                else
                                {
                                    cout << "Your input is not a number, try again!" << endl;
                                    cin.clear();
                                }
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Press enter to continue..." << endl;
                                getchar();
                            } while (logic == false);
                            if (choice == 0)
                                break;
                            choice = choice - 1;
                            cout << "Enter id which you want to edit: ";
                            cin >> answer;
                            elist[k].edit_customer(tlist, answer, choice);
                        }
                    }
                    break;
                case 3:
                    system("clear");
                    cout << "Enter id which you want to edit" << endl;
                    cin >> answer;
                    edit_trip(answer);
                    break;
                default:
                    break;
                }
            } while (choice4 != 0);
            break;
        case 5:
            do
            {
                logic = false;
                do
                {
                    system("clear");
                    cout << "What do you want to do?" << endl
                         << "[1] Print employees" << endl
                         << "[2] Print trips with customers" << endl
                         << "[0] Go back to main menu" << endl;
                    cout << "Type the number to choose the option: ";
                    cin >> choice5;
                    if (cin.good() == true)
                        if (choice5 >= 0 && choice5 <= 2)
                            logic = true;
                        else
                        {
                            cout << "This choice is not available, try again!" << endl;
                            cin.clear();
                        }
                    else
                    {
                        cout << "Your input is not a number, try again!" << endl;
                        cin.clear();
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                } while (logic == false);
                switch (choice5)
                {
                case 1:
                    if (elist.empty() == true)
                    {
                        cout << "There is no employee to print!" << endl;
                        cout << "Press enter to continue..." << endl;
                        getchar();
                        break;
                    }
                    print_employee();
                    break;
                case 2:
                    print_trip();
                    break;
                default:
                    break;
                }
            } while (choice5 != 0);
            break;
        case 6:
            travel_in_time();
            break;
        default:
            break;
        }
    } while (choice1 != 0);
    cout << "Leaving the program!" << endl;
}
void Travel_agency::add_employee()
{
    int choice1;
    bool type;
    string name;
    string surname;
    string email;
    long telephone;
    string employee_id;
    bool logic = false;
    stringstream into_string;
    do
    {
        system("clear");
        cout << "Who do you want to add?" << endl
             << "[1] Agent" << endl
             << "[2] Supervisor" << endl
             << "[0] Leave" << endl;
        cout << "Type the number to choose the option: ";
        cin >> choice1;
        if (cin.good() == true)
            if (choice1 == 1)
            {
                cout << "You have chosen agent!" << endl;
                type = true; // agent
                if (agents_limit >= 3)
                {
                    cout << "You have already reached maximal number of agents!" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    return;
                }
                agents_limit++;
                num_of_agents++;
                logic = true;
            }
            else if (choice1 == 2)
            {
                cout << "You have chosen supervisor!" << endl;
                type = false; // agent
                if (supervisors_limit >= 5)
                {
                    cout << "You have already reached maximal number of agents!" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    return;
                }
                supervisors_limit++;
                num_of_supervisors++;
                logic = true;
            }
            else if (choice1 == 0)
                return;
            else
            {
                cout << "This choice is not available, try again!" << endl;
                cin.clear();
            }
        else
        {
            cout << "Your input is not a number, try again!" << endl;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
        cout << "Press enter to continue..." << endl;
        getchar();
    } while (logic == false);
    system("clear");
    cout << "Please enter name: " << endl;
    getline(cin, name);
    name = remove_numbers(name);
    cout << "Please enter surname: " << endl;
    getline(cin, surname);
    surname = remove_numbers(surname);
    cout << "Please enter email: " << endl;
    cin >> email;
    cout << "Please enter phone number: " << endl;
    logic = false;
    do
    {
        cin >> telephone;
        if (cin.good() == true)
            if (telephone < 1000000000 && telephone >= 100000000)
                logic = true;
            else
            {
                cout << "Telephone should have 9 digits, try again!" << endl;
                cin.clear();
            }
        else
        {
            cout << "Your input is not a number, try again!" << endl;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
    } while (logic == false);
    if (type == 1)
    {
        into_string << num_of_agents;
        employee_id = into_string.str() + "A";
        Employee new_employee(type, name, surname, email, telephone, employee_id, AGENT);
        elist.push_back(new_employee);
    }
    if (type == 0)
    {
        into_string << num_of_supervisors;
        employee_id = into_string.str() + "S";
        Employee new_employee(type, name, surname, email, telephone, employee_id, HAVE_NO_TRIP);
        elist.push_back(new_employee);
    }
    cout << "ID of this employee is: " << employee_id << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
}
void Travel_agency::remove_employee(string id)
{
    system("clear");
    for (int k = 0; k < elist.size(); k++)
    {
        if (id == elist[k].get_id())
        {
            if (elist[k].get_type() == false)
            {
                supervisors_limit--;
                for (int i = 0; i < tlist.size(); i++)
                {
                    if (tlist[i].get_supervisor_id() == elist[k].get_id())
                    {

                        tlist[i].set_status(false);
                    }
                }
            }
            if (elist[k].get_type() == true)
                agents_limit--;
            if (elist[k].get_id() == user_id)
            {
                is_logged = false;
                user_name = " ";
                user_id = " ";
            }
            elist.erase(elist.begin() + k);
            cin.ignore();
            cout << "Employee removed!" << endl;
            cout << "Press enter to continue..." << endl;
            getchar();
            return;
        }
    }
    cin.ignore();
    cout << "There is no such employee!" << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
    return;
}
void Travel_agency::edit_employee(string id)
{
    string name;
    string surname;
    string email;
    long telephone;
    bool logic = false;
    int choice;
    system("clear");
    for (int k = 0; k < elist.size(); k++)
    {
        if (id == elist[k].get_id())
        {
            do
            {
                do
                {
                    system("clear");
                    cout << "What do you want to do?" << endl
                         << "[1] Edit name" << endl
                         << "[2] Edit surname" << endl
                         << "[3] Edit email" << endl
                         << "[4] Edit telephone" << endl
                         << "[0] Leave editor" << endl;
                    cout << "Type the number to choose the option: ";
                    cin >> choice;
                    if (cin.good() == true)
                        if (choice >= 0 && choice <= 4)
                            logic = true;
                        else
                        {
                            cout << "This choice is not available, try again!" << endl;
                            cin.clear();
                        }
                    else
                    {
                        cout << "Your input is not a number, try again!" << endl;
                        cin.clear();
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                } while (logic == false);
                system("clear");
                cout << "Enter updated information: ";
                switch (choice)
                {
                case 1:
                    getline(cin, name);
                    elist[k].set_name(name);
                    cout << "Name updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 2:
                    getline(cin, surname);
                    elist[k].set_surname(surname);
                    cout << "Surname updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 3:
                    getline(cin, email);
                    elist[k].set_email(email);
                    cout << "Email updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 4:
                    logic = false;
                    do
                    {
                        cin >> telephone;
                        if (cin.good() == true)
                            if (telephone < 1000000000 && telephone >= 100000000)
                            {
                                logic = true;
                                elist[k].set_telephone(telephone);
                                cout << "Telephone updated" << endl;
                                cout << "Press enter to continue..." << endl;
                                getchar();
                            }
                            else
                            {
                                cout << "Telephone should have 9 digits, try again!" << endl;
                                cin.clear();
                            }
                        else
                        {
                            cout << "Your input is not a number, try again!" << endl;
                            cin.clear();
                        }
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
                    } while (logic == false);
                    break;
                default:
                    break;
                }
            } while (choice != 0);
            user_name = elist[k].get_name() + " " + elist[k].get_surname();
            return;
        }
    }
    cout << "There is no such employee!" << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
    return;
}
void Travel_agency::print_employee()
{
    system("clear");
    cout << "List of agents:" << endl;
    cout << "ID" << setw(20) << "Name" << setw(20) << "Surname" << setw(35) << "Email" << setw(10) << "Telephone" << endl
         << endl;
    for (int k = 0; k < elist.size(); k++)
    {
        if (elist[k].get_type() == true)
            elist[k].print();
    }
    cout << endl
         << endl
         << "List of supervisors:" << endl;
    cout << "ID" << setw(20) << "Name" << setw(20) << "Surname" << setw(35) << "Email" << setw(10) << "Telephone" << endl
         << endl;
    for (int k = 0; k < elist.size(); k++)
    {
        if (elist[k].get_type() == false)
            elist[k].print();
    }
    cout << "Press enter to continue..." << endl;
    getchar();
}
void Travel_agency::log_user()
{
    system("clear");
    string id;
    if (is_logged == true)
    {
        cout << "Agent is already logged in!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    else
    {
        if (elist.empty() == true)
        {
            cout << "There is no agent to log!" << endl;
            cout << "Press enter to continue..." << endl;
            getchar();
            return;
        }
        else if (elist.empty() == false)
        {
            cout << "Please give your ID to log in: ";
            cin >> id;
            for (int k = 0; k < elist.size(); k++)
            {
                if (id == elist[k].get_id())
                {
                    if (elist[k].get_type() == false)
                    {
                        cout << "You are not an agent!" << endl;
                        cout << "Press enter to continue..." << endl;
                        getchar();
                        return;
                    }
                    cout << "You are logged as " << elist[k].get_name() << " " << elist[k].get_surname() << endl;
                    cin.ignore();
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    is_logged = true;
                    user_name = elist[k].get_name() + " " + elist[k].get_surname();
                    user_id = elist[k].get_id();
                    return;
                }
            }
            cout << "Logging in unsuccessful, ID not found" << endl;
            cout << "Press enter to continue..." << endl;
            getchar();
            return;
        }
    }
}
void Travel_agency::add_trip()
{
    string country;
    string city;
    long price;
    string hotel_name;
    string trip_id;
    struct tm start_of_trip;
    struct tm end_of_trip;
    bool logic = false;
    stringstream into_string;
    system("clear");
    if (is_logged == false)
    {
        cout << "You are not logged in as agent, no permission to add new trip!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    num_of_trips++;
    trip_limit++;
    cout << "Please enter country: " << endl;
    getline(cin, country);
    country = remove_numbers(country);
    cout << "Please enter city: " << endl;
    getline(cin, city);
    city = remove_numbers(city);
    cout << "Please enter hotel's name: " << endl;
    getline(cin, hotel_name);
    hotel_name = remove_numbers(hotel_name);
    do
    {
        cout << "Please enter starting date of trip" << endl;
        cout << "Year: ";
        cin >> start_of_trip.tm_year;
        if (cin.good() == true)
        {
            cout << "Month: ";
            cin >> start_of_trip.tm_mon;
            if (cin.good() == true && start_of_trip.tm_mon <= 12)
            {
                cout << "day: ";
                cin >> start_of_trip.tm_mday;
                if (cin.good() == true && ((start_of_trip.tm_mon == 2 && start_of_trip.tm_year % 4 == 0 && start_of_trip.tm_mday <= 29) || (start_of_trip.tm_mon == 2 && start_of_trip.tm_year % 4 != 0 && start_of_trip.tm_mday <= 28) || ((start_of_trip.tm_mon == 4 || start_of_trip.tm_mon == 6 || start_of_trip.tm_mon == 9 || start_of_trip.tm_mon == 11) && start_of_trip.tm_mday <= 30) || ((start_of_trip.tm_mon == 1 || start_of_trip.tm_mon == 3 || start_of_trip.tm_mon == 5 || start_of_trip.tm_mon == 7 || start_of_trip.tm_mon == 8 || start_of_trip.tm_mon == 10 || start_of_trip.tm_mon == 12) && start_of_trip.tm_mday <= 31)))
                {
                    if ((start_of_trip.tm_year > date_as_struct->tm_year))
                        logic = true;
                    else if ((start_of_trip.tm_year == date_as_struct->tm_year) && (start_of_trip.tm_mon > date_as_struct->tm_mon))
                        logic = true;
                    else if ((start_of_trip.tm_year == date_as_struct->tm_year) && (start_of_trip.tm_mon == date_as_struct->tm_mon) && (start_of_trip.tm_mday > date_as_struct->tm_mday))
                        logic = true;
                    else
                    {
                        cout << "Your input is wrong (Probably it has already taken place in past, try again!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    cout << "Your input is incorrect, try again!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            else
            {
                cout << "Your input is incorrect, try again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Your input is incorrect, try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (logic == false);
    logic = false;
    do
    {
        cout << "Please enter ending of trip" << endl;
        cout << "Year: ";
        cin >> end_of_trip.tm_year;
        if (cin.good() == true)
        {
            cout << "Month: ";
            cin >> end_of_trip.tm_mon;
            if (cin.good() == true && end_of_trip.tm_mon <= 12)
            {
                cout << "day: ";
                cin >> end_of_trip.tm_mday;
                if (cin.good() == true && ((end_of_trip.tm_mon == 2 && end_of_trip.tm_year % 4 == 0 && end_of_trip.tm_mday <= 29) || (end_of_trip.tm_mon == 2 && end_of_trip.tm_year % 4 != 0 && end_of_trip.tm_mday <= 28) || ((end_of_trip.tm_mon == 4 || end_of_trip.tm_mon == 6 || end_of_trip.tm_mon == 9 || end_of_trip.tm_mon == 11) && end_of_trip.tm_mday <= 30) || ((end_of_trip.tm_mon == 1 || end_of_trip.tm_mon == 3 || end_of_trip.tm_mon == 5 || end_of_trip.tm_mon == 7 || end_of_trip.tm_mon == 8 || end_of_trip.tm_mon == 10 || end_of_trip.tm_mon == 12) && end_of_trip.tm_mday <= 31)))
                {
                    if ((end_of_trip.tm_year > start_of_trip.tm_year))
                        logic = true;
                    else if ((end_of_trip.tm_year == start_of_trip.tm_year) && (end_of_trip.tm_mon > start_of_trip.tm_mon))
                        logic = true;
                    else if ((end_of_trip.tm_year == start_of_trip.tm_year) && (end_of_trip.tm_mon == start_of_trip.tm_mon) && (end_of_trip.tm_mday > start_of_trip.tm_mday))
                        logic = true;
                    else
                    {
                        cout << "Your input is wrong (Probably your input happens before starting date, try again!" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                else
                {
                    cout << "Your input is incorrect, try again!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            else
            {
                cout << "Your input is incorrect, try again!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        else
        {
            cout << "Your input is incorrect, try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (logic == false);
    cout << "Please enter price: " << endl;
    logic = false;
    do
    {
        cin >> price;
        if (cin.good() == true)
            if (price >= 500)
                logic = true;
            else
            {
                cout << "Price can't be less than 500 zlotych" << endl;
                cin.clear();
            }
        else
        {
            cout << "Your input is not a number, try again!" << endl;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
    } while (logic == false);
    into_string << num_of_trips;
    trip_id = into_string.str() + "T";
    start_of_trip.tm_mon -= 1;
    end_of_trip.tm_mon -= 1;
    Trip new_trip(country, city, price, hotel_name, trip_id, start_of_trip, end_of_trip);
    tlist.push_back(new_trip);
    cout << "ID of this trip is: " << trip_id << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
}
void Travel_agency::remove_trip(string id)
{
    system("clear");
    cin.ignore();
    if (is_logged == false)
    {
        cout << "You are not logged in as agent, no permission to remove customer!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    for (int k = 0; k < tlist.size(); k++)
    {
        if (id == tlist[k].get_id())
        {
            if (tlist[k].get_state() == IN_PROGRESS)
            {
                cout << "You cannot remove Trip which is taking place!" << endl;
                cout << "Press enter to continue..." << endl;
                getchar();
                return;
            }
            if (tlist[k].get_status() == true)
            {
                for (int i = 0; i < elist.size(); i++)
                {
                    if (elist[i].get_id() == tlist[k].get_supervisor_id())
                    {
                        elist[i].set_state(HAVE_NO_TRIP);
                        break;
                    }
                }
            }
            tlist.erase(tlist.begin() + k);
            trip_limit--;
            cout << "Trip removed" << endl;
            cout << "Press enter to continue..." << endl;
            getchar();
            return;
        }
    }
    cout << "There is no such trip!" << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
    return;
}
void Travel_agency::edit_trip(string id)
{
    string country;
    string city;
    string hotel_name;
    string email;
    long price;
    int duration;
    struct tm end_of_trip;
    struct tm start_of_trip;
    string updated_starting_date;
    string updated_ending_date;
    bool logic;
    int choice;
    char bufor[64];
    system("clear");
    if (is_logged == false)
    {
        cout << "You are not logged in as agent, no permission to edit trip!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    for (int k = 0; k < tlist.size(); k++)
    {
        if (id == tlist[k].get_id())
        {
            if ((tlist[k].get_starting_date() > date_as_string))
            {
                cout << "You can't edit trip which is in progress are or already taken place!" << endl;
                cout << "Press enter to continue..." << endl;
                getchar();
                return;
            }
            do
            {
                do
                {
                    logic = false;
                    system("clear");
                    cout << "What do you want to do?" << endl
                         << "[1] Edit Country" << endl
                         << "[2] Edit City" << endl
                         << "[3] Edit hotel's name" << endl
                         << "[4] Edit price" << endl
                         << "[5] Edit starting date" << endl
                         << "[6] Edit ending date" << endl
                         << "[0] Leave editor" << endl;
                    cout << "Type the number to choose the option: ";
                    cin >> choice;
                    if (cin.good() == true)
                        if (choice >= 0 && choice <= 6)
                            logic = true;
                        else
                        {
                            cout << "This choice is not available, try again!" << endl;
                            cin.clear();
                        }
                    else
                    {
                        cout << "Your input is not a number, try again!" << endl;
                        cin.clear();
                    }
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
                } while (logic == false);
                system("clear");
                cout << "Enter updated information: ";
                switch (choice)
                {
                case 1:
                    getline(cin, country);
                    tlist[k].set_country(country);
                    cout << "Destination updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 2:
                    getline(cin, city);
                    tlist[k].set_city(city);
                    cout << "Destination updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 3:
                    getline(cin, hotel_name);
                    tlist[k].set_hotel_name(hotel_name);
                    cout << "Hotel's name updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 4:
                    logic = false;
                    do
                    {
                        cin >> price;
                        if (cin.good() == true)
                            if (price >= 500)
                            {
                                logic = true;
                                tlist[k].set_price(price);
                                cout << "Price updated" << endl;
                                cout << "Press enter to continue..." << endl;
                                getchar();
                            }
                            else
                            {
                                cout << "Price can't be less than 500 zlotych" << endl;
                                cin.clear();
                            }
                        else
                        {
                            cout << "Your input is not a number, try again!" << endl;
                            cin.clear();
                        }
                    } while (logic == false);
                    break;
                case 5:
                    logic = false;
                    do
                    {
                        cout << "Year: ";
                        cin >> start_of_trip.tm_year;
                        if (cin.good() == true)
                        {
                            cout << "Month: ";
                            cin >> start_of_trip.tm_mon;
                            if (cin.good() == true && start_of_trip.tm_mon <= 12)
                            {
                                cout << "day: ";
                                cin >> start_of_trip.tm_mday;
                                if (cin.good() == true && ((start_of_trip.tm_mon == 2 && start_of_trip.tm_year % 4 == 0 && start_of_trip.tm_mday <= 29) || (start_of_trip.tm_mon == 2 && start_of_trip.tm_year % 4 != 0 && start_of_trip.tm_mday <= 28) || ((start_of_trip.tm_mon == 4 || start_of_trip.tm_mon == 6 || start_of_trip.tm_mon == 9 || start_of_trip.tm_mon == 11) && start_of_trip.tm_mday <= 30) || ((start_of_trip.tm_mon == 1 || start_of_trip.tm_mon == 3 || start_of_trip.tm_mon == 5 || start_of_trip.tm_mon == 7 || start_of_trip.tm_mon == 8 || start_of_trip.tm_mon == 10 || start_of_trip.tm_mon == 12) && start_of_trip.tm_mday <= 31)))
                                {
                                    if ((start_of_trip.tm_year > date_as_struct->tm_year))
                                        logic = true;
                                    else if ((start_of_trip.tm_year == date_as_struct->tm_year) && (start_of_trip.tm_mon > date_as_struct->tm_mon))
                                        logic = true;
                                    else if ((start_of_trip.tm_year == date_as_struct->tm_year) && (start_of_trip.tm_mon == date_as_struct->tm_mon) && (start_of_trip.tm_mday > date_as_struct->tm_mday))
                                        logic = true;
                                    else
                                    {
                                        cout << "Your input is wrong (Probably it has already taken place in past, try again!" << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                }
                                else
                                {
                                    cout << "Your input is incorrect, try again!" << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            }
                            else
                            {
                                cout << "Your input is incorrect, try again!" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                        else
                        {
                            cout << "Your input is incorrect, try again!" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (logic == false);
                    start_of_trip.tm_mon -= 1;
                    strftime(bufor, 64, "%x", &start_of_trip);
                    updated_starting_date = bufor;
                    tlist[k].set_starting_date(updated_starting_date);
                    cout << "date updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 6:
                    logic = false;
                    do
                    {
                        cout << "Year: ";
                        cin >> end_of_trip.tm_year;
                        if (cin.good() == true)
                        {
                            cout << "Month: ";
                            cin >> end_of_trip.tm_mon;
                            if (cin.good() == true && end_of_trip.tm_mon <= 12)
                            {
                                cout << "day: ";
                                cin >> end_of_trip.tm_mday;
                                if (cin.good() == true && ((end_of_trip.tm_mon == 2 && end_of_trip.tm_year % 4 == 0 && end_of_trip.tm_mday <= 29) || (end_of_trip.tm_mon == 2 && end_of_trip.tm_year % 4 != 0 && end_of_trip.tm_mday <= 28) || ((end_of_trip.tm_mon == 4 || end_of_trip.tm_mon == 6 || end_of_trip.tm_mon == 9 || end_of_trip.tm_mon == 11) && end_of_trip.tm_mday <= 30) || ((end_of_trip.tm_mon == 1 || end_of_trip.tm_mon == 3 || end_of_trip.tm_mon == 5 || end_of_trip.tm_mon == 7 || end_of_trip.tm_mon == 8 || end_of_trip.tm_mon == 10 || end_of_trip.tm_mon == 12) && end_of_trip.tm_mday <= 31)))
                                {
                                    if ((end_of_trip.tm_year > start_of_trip.tm_year))
                                        logic = true;
                                    else if ((end_of_trip.tm_year == start_of_trip.tm_year) && (end_of_trip.tm_mon > start_of_trip.tm_mon))
                                        logic = true;
                                    else if ((end_of_trip.tm_year == start_of_trip.tm_year) && (end_of_trip.tm_mon == start_of_trip.tm_mon) && (end_of_trip.tm_mday > start_of_trip.tm_mday))
                                        logic = true;
                                    else
                                    {
                                        cout << "Your input is wrong (Probably your input happens before starting date, try again!" << endl;
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                }
                                else
                                {
                                    cout << "Your input is incorrect, try again!" << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            }
                            else
                            {
                                cout << "Your input is incorrect, try again!" << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                        }
                        else
                        {
                            cout << "Your input is incorrect, try again!" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (logic == false);
                    end_of_trip.tm_mon -= 1;
                    strftime(bufor, 64, "%x", &end_of_trip);
                    updated_ending_date = bufor;
                    tlist[k].set_starting_date(updated_ending_date);
                    cout << "date updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                default:
                    break;
                }
            } while (choice != 0);
            return;
        }
    }
    cout << "There is no such Trip!" << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
    return;
}
void Travel_agency::print_trip()
{
    int choice;
    bool logic = false;
    system("clear");
    if (tlist.empty() == true)
    {
        cout << "There is no trip to print information!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    do
    {
        for (int k = 0; k < tlist.size(); k++)
        {
            cout << "[" << k + 1 << "] ";
            tlist[k].choose_trip();
        }
        cout << "[0] Leave" << endl;
        cout << "Choose a destination: ";
        cin >> choice;
        if (cin.good() == true)
            if (choice >= 0 && choice <= tlist.size())
                logic = true;
            else
            {
                cout << "This choice is not available, try again!" << endl;
                cin.clear();
            }
        else
        {
            cout << "Your input is not a number, try again!" << endl;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
        cout << "Press enter to continue..." << endl;
        getchar();
    } while (logic == false);
    if (choice == 0)
        return;
    choice = choice - 1;
    system("clear");
    tlist[choice].print();
    cout << "Press enter to continue..." << endl;
    getchar();
}
string Travel_agency::remove_numbers(string words)
{
    string temp;
    for (int i = 0; i < words.size(); ++i)
    {
        if (words[i] == ' ')
            temp += " ";
        if ((words[i] >= 'a' && words[i] <= 'z') || (words[i] >= 'A' && words[i] <= 'Z'))
        {
            temp += words[i];
        }
    }
    return temp;
}
void Travel_agency::travel_in_time()
{

    int days;
    bool logic;
    logic = false;
    system("clear");
    char bufor[64];
    cout << "You can travel ahead by 3, 7 or 14 days. Type your number: ";
    do
    {
        cin >> days;
        if (cin.good() == true)
            if (days == 3 || days == 7 || days == 14)
            {
                date_as_seconds += days * 24 * 3600;
                date_as_struct = gmtime(&date_as_seconds);
                date_as_struct->tm_year += 1900;
                strftime(bufor, 64, "%x", date_as_struct);
                date_as_string = bufor;
                for (int k = 0; k < tlist.size(); k++)
                {
                    if (date_as_string >= tlist[k].get_starting_date() && date_as_string <= tlist[k].get_ending_date())
                        tlist[k].set_state(IN_PROGRESS);
                    if (date_as_string > tlist[k].get_ending_date())
                        tlist[k].set_state(ENDED);
                }
                logic = true;
                cout << "Press enter to continue..." << endl;
                getchar();
                return;
            }
            else
            {
                cout << "You can move only by 3, 7 or 14 days ahead, try again!" << endl;
                cin.clear();
            }
        else
        {
            cout << "Your input is not a number, try again!" << endl;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignores input;
    } while (logic == false);
}
void Travel_agency::add_employee_to_trip(string id_employee, string id_trip)
{
    string temp;
    if (is_logged == false)
    {
        cin.ignore();
        cout << "You are not logged in as agent, no permission to add supervisor to trip" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    for (int k = 0; k < tlist.size(); k++)
    {
        if (tlist[k].get_id() == id_trip)
        {
            if (tlist[k].get_status() == false)
            {
                for (int i = 0; i < elist.size(); i++)
                {
                    if (elist[i].get_id() == id_employee)
                    {
                        if (elist[i].get_state() == HAVE_NO_TRIP)
                            elist[i].set_state(HAVE_ONE_TRIP);
                        else if (elist[i].get_state() == HAVE_ONE_TRIP)
                        {
                            cin.ignore();
                            cout << "Supervisor has already connected trip" << endl;
                            cout << "Press enter to continue..." << endl;
                            getchar();
                            return;
                        }
                        string temp = elist[i].get_name() + " " + elist[i].get_surname();
                        tlist[k].set_supervisor(temp);
                        tlist[k].set_supervisor_id(elist[i].get_id());
                        tlist[k].set_status(true);
                        cin.ignore();
                        cout << "Supervisor added to trip!" << endl;
                        cout << "Press enter to continue..." << endl;
                        getchar();
                        return;
                    }
                }
                cin.ignore();
                cout << "Supervisor not found!" << endl;
                cout << "Press enter to continue..." << endl;
                getchar();
                return;
            }
            else if (tlist[k].get_status() == true)
            {
                cin.ignore();
                cout << "This Trip has already one supervisor" << endl;
                cout << "Press enter to continue..." << endl;
                getchar();
                return;
            }
        }
    }
    cin.ignore();
    cout << "Trip not found!" << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
    return;
}
void Travel_agency::random_event()
{
    system("clear");
    srand(time(NULL));
    int winner = (rand() % 50) + 1;
    int helping_number;
    switch (winner)
    {
    case 10:
        if (elist.empty() == true)
        {
            return;
        }
        helping_number = (rand() % elist.size()) + 0;
        cout << "Something terrible happended, one of your employee "
             << elist[helping_number].get_name()
             << " "
             << elist[helping_number].get_surname()
             << " died, because You didn't give him food. What a bad employer!" << endl;
        remove_employee(elist[helping_number].get_id());
        return;
    case 20:
        if (elist.empty() == true)
        {
            return;
        }
        if (tlist.empty() == true)
        {
            return;
        }
        helping_number = (rand() % tlist.size()) + 0;
        cout << "In " << tlist[helping_number].get_country() << " There is a zombie apocalypse and we need to cancel your trip" << endl;
        remove_trip(tlist[helping_number].get_id());
        return;
    case 30:
        helping_number = (rand() % tlist.size()) + 0;
        if (elist.empty() == true)
        {
            return;
        }
        if (tlist.empty() == true)
        {
            return;
        }
        if (tlist[helping_number].get_customers().empty() == true)
        {
            return;
        }
        cout << "Your customer, which take part in trip to " << tlist[helping_number].get_country() << " resigned, as he can't seat next to window in plane" << endl;
        elist[1].remove_customer(tlist, tlist[helping_number].get_customers()[1].get_id(), helping_number);
        return;
    default:
        return;
    }
}
