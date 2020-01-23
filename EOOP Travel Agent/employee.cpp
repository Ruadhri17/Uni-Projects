#include "employee.h"
Employee::Employee(bool t, string n, string s, string e, long tel, string id, worker stat)
{
    type = t;
    name = n;
    surname = s;
    email = e;
    telephone = tel;
    employee_id = id;
    state = stat;
}
Employee::~Employee()
{
}
void Employee::add_customer(int num_of_customers, vector<Trip> &tlist, int choice)
{
    string name;
    string surname;
    string email;
    long telephone;
    string customer_id;
    stringstream into_string;
    bool logic;
    system("clear");
    if (tlist[choice].get_state() == IN_PROGRESS || tlist[choice].get_state() == ENDED)
    {
        cout << "You cannot add customer to trip which is taking place or ended!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    cout << "Please enter name: " << endl;
    getline(cin, name);
    name = remove_numbers(name);
    cout << "Please enter surname: " << endl;
    getline(cin, surname);
    surname = remove_numbers(surname);
    cout << "Please enter email: " << endl;
    getline(cin, email);
    surname = remove_numbers(email);
    cout << "Please enter phone number:  " << endl;
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
    into_string << num_of_customers;
    customer_id = into_string.str() + "C";
    Customer new_customer(name, surname, email, telephone, customer_id);
    tlist[choice].get_customers().push_back(new_customer);
    cout << "ID of this customer is: " << customer_id << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
}
void Employee::remove_customer(vector<Trip> &tlist, string id, int choice)
{
    system("clear");
    if (tlist[choice].get_state() == IN_PROGRESS || tlist[choice].get_state() == ENDED)
    {
        cout << "You cannot add customer to trip which is taking place or ended!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    for (int k = 0; k < tlist[choice].get_customers().size(); k++)
    {
        if ((tlist[choice].get_customers()[k].get_id()) == id)
            tlist[choice].get_customers().erase(tlist[choice].get_customers().begin() + k); //funny
        cout << "Customer removed!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    cout << "There is no such Customer!" << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
    return;
}
void Employee::edit_customer(vector<Trip> &tlist, string id, int choice)
{
    string name;
    string surname;
    string email;
    long telephone;
    bool logic;
    int answer;
    if (tlist[choice].get_state() == IN_PROGRESS || tlist[choice].get_state() == ENDED)
    {
        cout << "You cannot add customer to trip which is taking place or ended!" << endl;
        cout << "Press enter to continue..." << endl;
        getchar();
        return;
    }
    for (int k = 0; k < tlist[choice].get_customers().size(); k++)
    {
        if (tlist[choice].get_customers()[k].get_id() == id)
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
                    cin >> answer;
                    if (cin.good() == true)
                        if (answer >= 0 && answer <= 4)
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
                switch (answer)
                {
                case 1:
                    getline(cin, name);
                    tlist[choice].get_customers()[k].set_name(name);
                    cout << "Name updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 2:
                    getline(cin, surname);
                    tlist[choice].get_customers()[k].set_surname(surname);
                    cout << "Surname updated" << endl;
                    cout << "Press enter to continue..." << endl;
                    getchar();
                    break;
                case 3:
                    cin >> email;
                    tlist[choice].get_customers()[k].set_email(email);
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
                                tlist[choice].get_customers()[k].set_telephone(telephone);
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
            } while (answer != 0);
            return;
        }
    }
    cout << "There is no such customer" << endl;
    cout << "Press enter to continue..." << endl;
    getchar();
    return;
}
void Employee::print()
{
    cout << employee_id << setw(20) << name << setw(20) << surname << setw(35) << email << setw(10) << telephone << endl;
}
bool Employee::get_type()
{
    return type;
}
string Employee::get_name()
{
    return name;
}
string Employee::get_surname()
{
    return surname;
}
string Employee::get_email()
{
    return email;
}
long Employee::get_telephone()
{
    return telephone;
}
string Employee::get_id()
{
    return employee_id;
}
worker Employee::get_state()
{
    return state;
}
void Employee::set_name(string xname)
{
    name = xname;
}
void Employee::set_surname(string xsurname)
{
    surname = xsurname;
}
void Employee::set_email(string xemail)
{
    email = xemail;
}
void Employee::set_telephone(long xtelephone)
{
    telephone = xtelephone;
}
void Employee::set_state(worker xstate)
{
    state = xstate;
}
string Employee::remove_numbers(string words)
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