#include <iostream>
#include <vector>
#include<iomanip>
#include<algorithm>

using namespace std;


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

const string FILENAME = "data.txt";
const string ADMIN_USERNAME = "admin";
const string ADMIN_PASSWORD = "password";
bool isLoggedIn = false;

bool login()
{
    ifstream login("data.txt");

    string userName, userPassword;
    cout << "userName :";
    cin.ignore();
    getline(cin, userName);
    cout << "userPassword :";
    cin.ignore();
    getline(cin, userPassword);
    if (userName == userPassword)
    {
        cout << "User name :" << userName << endl;
        cout << "User Password :" << userPassword << endl;
    }
}

void logout()
{
    isLoggedIn = false;
    cout << "You have been logged out successfully.\n";
}

struct Employee
{
    int id;
    string name;
    string role;
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    void setRole(string role)
    {
        this->role = role;
    }

    //
    void getUserInfo()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << this->role << endl;
    }
};

struct Employee
{
    int id;
    string name;
    string role;
};

class EmployeeManagementSystem
{
private:
    int id;
    string name;
    string role;
    bool isAdminLogin;
    vector<Employee> employees;

public:
    EmployeeManagementSystem() {}
    EmployeeManagementSystem(int id, string name, string role)
    {
        this->id = id;
        this->name = name;
        this->role = role;
    }
    void setID()
    {
        this->id = id;
    }
    void setName()
    {
        this->name = name;
    }
    void setRole()
    {
        this->role = role;
    }
    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    string getRole()
    {
        return this->role;
    }

    void display()
    {
        cout << "++++++++++++ Inser your list ++++++++++++:" << endl;
        cout << "Enter Id :";
        cin >> id;
        cout << "Enter Name :";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Role :";
        cin.ignore();
        getline(cin, role);
        cout << "++++++++++++++++++ Output list ++++++++++++++++" << endl;
        cout << "ID :" << id << endl;
        cout << "Name :" << name << endl;
        cout << "Role :" << role << endl;
    }
    void addEmployee()
    {
        // if (!loggedIn())
        // {
        //     cout << "Access denied. Please log in as admin.\n";
        //     return;
        // }

        Employee emp;
        cout << "Enter Employee ID: ";
        cin >> emp.id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, emp.name);
        cout << "Enter Employee Role: ";
        getline(cin, emp.role);
        // cout << "Enter Employee Salary: ";
        // cin >> emp.salary;

        employees.push_back(emp);
        cout << "Employee added successfully.\n";
    }

    void listEmployees()
    {
        if (employees.empty())
        {
            cout << "No employees found.\n";
            return;
        }

        cout << "Employee List:\n";
        for (const auto &emp : employees)
        {
            cout << "ID: " << emp.id << ", Name: " << emp.name
                 << ", Role: " << emp.role << endl;
        }
    }

    void updateEmployee()
    {
        // if (!admin.loggedIn())
        // {
        //     cout << "Access denied. Please log in as admin.\n";
        //     return;
        // }

        int id;
        cout << "Enter Employee ID to update: ";
        cin >> id;

        auto it = find_if(employees.begin(), employees.end(), [id](Employee &emp)
                          { return emp.id == id; });

        if (it != employees.end())
        {
            cout << "Enter new name (current: " << it->name << "): ";
            cin.ignore();
            getline(cin, it->name);
            cout << "Enter new role (current: " << it->role << "): ";
            getline(cin, it->role);

            cout << "Employee updated successfully.\n";
        }
        else
        {
            cout << "Employee not found.\n";
        }
    }

    void deleteEmployee()
    {
        // if (!admin.loggedIn())
        // {
        //     cout << "Access denied. Please log in as admin.\n";
        //     return;
        // }

        int id;
        cout << "Enter Employee ID to delete: ";
        cin >> id;

        auto it = remove_if(employees.begin(), employees.end(), [id](Employee &emp)
                            { return emp.id == id; });

        if (it != employees.end())
        {
            employees.erase(it, employees.end());
            cout << "Employee deleted successfully.\n";
        }
        else
        {
            cout << "Employee not found.\n";
        }
    }

    void searchEmployee()
    {
        if (employees.empty())
        {
            cout << "No employees to search.\n";
            return;
        }

        int option;
        cout << "Search by: 1. ID 2. Name 3. Role\nEnter option: ";
        cin >> option;

        if (option == 1)
        {
            int id;
            cout << "Enter Employee ID: ";
            cin >> id;

            auto it = find_if(employees.begin(), employees.end(), [id](Employee &emp)
                              { return emp.id == id; });

            if (it != employees.end())
            {
                cout << "Employee found: ID: " << it->id << ", Name: " << it->name
                     << ", Role: " << it->role << endl;
            }
            else
            {
                cout << "Employee not found.\n";
            }
        }
        else if (option == 2)
        {
            string name;
            cout << "Enter Employee Name: ";
            cin.ignore();
            getline(cin, name);

            auto it = find_if(employees.begin(), employees.end(), [&name](Employee &emp)
                              { return emp.name == name; });

            if (it != employees.end())
            {
                cout << "Employee found: ID: " << it->id << ", Name: " << it->name
                     << ", Role: " << it->role << endl;
            }
            else
            {
                cout << "Employee not found.\n";
            }
        }
        else if (option == 3)
        {
            string role;
            cout << "Enter Employee Role: ";
            cin.ignore();
            getline(cin, role);

            auto it = find_if(employees.begin(), employees.end(), [&role](Employee &emp)
                              { return emp.role == role; });

            if (it != employees.end())
            {
                cout << "Employee found: ID: " << it->id << ", Name: " << it->name
                     << ", Role: " << it->role << endl;
            }
            else
            {
                cout << "Employee not found.\n";
            }
        }
        else
        {
            cout << "Invalid option.\n";
        }
    }
};
