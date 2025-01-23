#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
#include<fstream>
#include"../model/employee.hpp"
#include"../repository/employee_repo.hpp"
#include"../view/table.hpp"
#include <cstring>
#include<conio.h>
using namespace std;



#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"


// Function to combine login and registration in one
void loginOrRegister() {
    int choice;
    string username, password;
    ifstream loginFile("login.txt");  // File to store user login info
    string storedUsername, storedPassword;
    // Check if the file exists, otherwise, prompt to register
    if (loginFile) {





std:: cout<<YELLOW<<R"(
                  __          ________ _      _____ ____  __  __ ______ 
                  \ \        / /  ____| |    / ____/ __ \|  \/  |  ____|
                   \ \  /\  / /| |__  | |   | |   | |  | | \  / | |__   
                    \ \/  \/ / |  __| | |   | |   | |  | | |\/| |  __|  
                     \  /\  /  | |____| |___| |___| |__| | |  | | |____ 
                      \/  \/   |______|______\_____\____/|_|  |_|______|
                                                       
                                                       
    )"<< endl;


        cout<<BLUE<<"\t\t\t________________________________________________"<<endl;
        cout<<BLUE<<"\t\t\t|============ Welcome to the System ============|" << endl;
        cout<<BLUE<<"\t\t\t|_______________________________________________|"<<endl;  
        cout<<BLUE<<"\t\t\t|1. Login                                       |" << endl;
        cout<<BLUE<<"\t\t\t|_______________________________________________| "<<endl;
        cout<<BLUE<<"\t\t\t|2. Register                                    |" << endl;
        cout<<BLUE<<"\t\t\t|_______________________________________________|"<<endl;
        cout<<BLUE<<"\t\t\t|3. Exit                                        |" <<endl;
        cout<<BLUE<<"\t\t\t|===============================================|"<<endl;
        cout <<BLUE<<"\t\t\tPlease choose an option: ";
        cin >> choice;

        // If file exists, login
        if(choice == 3){
        exit(0);
        }
        if (choice == 1) {
            cout<<BLUE<< "\t\t\t============ Login System ============" << endl;
            cout<<BLUE<< "\t\t\tUsername: "; cin >> username;
            cout<<BLUE<< "\t\t\tPassword: "; cin >> password;

            getline(loginFile, storedUsername);
            getline(loginFile, storedPassword);
            loginFile.close();

            if (username == storedUsername && password == storedPassword) {
                cout<<"\t\t\tLogin Successful!" << endl;
                cout<<"\t\t\tPress Any Key To Continue"<<endl;
                _getch();
                system("cls");
            } else {
                cout<<BLUE<<"\t\t\tWrong Username or Password\n";
                cout<<BLUE<<"\t\t\tPress any key to try again..." << endl;
                _getch();
                system("cls");
                return loginOrRegister();  // Retry login
            }
        }
        // Register new user
        else if (choice == 2) {
            cout<<YELLOW<<"\t\t\t============ Register System ============" << endl;
            cout<<"\t\t\tEnter Username: "; cin >> username;
            cout<<"\t\t\tEnter Password: "; cin >> password;

            // Store the username and password to login.txt
            ofstream loginFile("login.txt");
            loginFile << username << endl << password;
            loginFile.close();

            cout<<RED<<"\t\t\tRegistration Successful! You can now login." << endl;
        }
        else {
            cout<<RED <<"\t\t\tInvalid option! Please try again." << endl;
            _getch();
            return loginOrRegister();  // Retry
        }
    }
    else {
        // No user found, directly go to registration
        cout<<RED<<"\t\t\tNo user found. Please register first." << endl;
        cout<<"\t\t\t============ Register System ============" << endl;
        cout<<"\t\t\tEnter Username: "; cin >> username;
        cout<<"\t\t\tEnter Password: "; cin >> password;

        // Store the username and password to login.txt
        ofstream loginFile("login.txt");
        loginFile << username << endl << password;
        loginFile.close();

        cout<<GREEN<<"\t\t\tRegistration Successful! You can now login." << endl;
    }
}
    

// Function to get all employees
void getAllEmployees() {
    cout<<"\t\t\t[+] View all Employees\n";
    vector<vector<string>> employees;
    vector<string> columns = {"ID", "Name", "Role"};
    for (Employee &p : employeeRepositories) {
        vector<string> data = {to_string(p.getId()), p.getName(), p.getRole()};
        employees.push_back(data);
    }
    printTable(employees, columns);
}

// Function to check if the role is already taken
bool isRoleTaken(const string& role) {
    for (Employee& emp : employeeRepositories) {
        if (strcasecmp(emp.getRole().c_str(), role.c_str()) == 0) {
            return true;  // Role already exists (case-insensitive)
        }
    }
    return false;  // Role is available
}

// Function to search an employee by ID
Employee searchById() {
    int id;
    cout<<"\t\t\tPlease input the ID you wish to search: "; cin >> id;
    for (Employee g : employeeRepositories) {
        if (g.getId() == id) {
            g.output();
            return g;
        }
    }
    cout<<RED<< "\t\t\tInvalid ID" << endl;
    return {};
}

// Function to search an employee by name or role
Employee searchByNameAndRole(string input) {
    for (Employee u : employeeRepositories) {
        if (u.getName() == input || u.getRole() == input) {
            u.output();
            return u;
        }
    }
    cout<<RED<<"\t\t\tInvalid Name or Role" << endl;
    return {};
}

// Function to update employee information
Employee updateEmployee() {
    int id;
    string updateName, updateRole;
    cout<<"\t\t\tInput the employee ID to update: "; cin >> id;
    for (Employee &update : employeeRepositories) {
        if (update.getId() == id) {
            cout<<"\t\t\tChange Name from " << update.getName() << " to: "; cin.ignore(); getline(cin, updateName);
            update.setName(updateName);
            cout<<"\t\t\tChange from " << update.getRole() << " to: "; getline(cin, updateRole);
            update.setRole(updateRole);
            saveEmployeesToFile();
            cout<<"\t\t\tUpdated successfully!" << endl;
            return update;
        }
    }
    cout<<GREEN<< "\t\t\tInvalid ID" << endl;
    return {};
}

// Function to add an employee
void addEmployee() {
    int id;
    string name, role;
    cout<< "\t\t\tPlease input employee info" << endl;

    cout <<"\t\t\tID: "; cin >> id;
    for (Employee i : employeeRepositories) {
        if (i.getId() == id) {
            cout<<BLUE<<"\t\t\tID already available. Please input a new ID." << endl;
            return addEmployee();
        }
    }
    cin.ignore();
    cout <<"\t\t\tName: "; getline(cin, name);
    cout <<"\t\t\tRole: "; getline(cin, role);

    // Check if the role is already taken
    if (isRoleTaken(role)) {
        cout<<GREEN<<"\t\t\tRole is already taken. Please choose a different role." << endl;
        return addEmployee();
    }

    Employee employee(id, name, role);
    employeeRepositories.push_back(employee);
    saveEmployeesToFile();
}

// Function to delete an employee by ID
bool deleteEmployeeById() {
    int id;
    cout<<YELLOW<<"\t\t\tPlease input the ID you want to delete: "; cin >> id;
    for (int x = 0; x < employeeRepositories.size(); x++) {
        if (employeeRepositories[x].getId() == id) {
            employeeRepositories.erase(employeeRepositories.begin() + x);
            saveEmployeesToFile();
            cout<<YELLOW<<"\t\t\tDeleted successfully!" << endl;
            return true;
        }
    }
    cout<<YELLOW<< "\t\t\tInvalid ID" << endl;
    return false;
}

// Function to load employee data from a file
void loadEmployeesFromFile() {
    ifstream inputFile("employees.txt");
    if (inputFile) {
        int id;
        string name, role;
        while (inputFile >> id >> ws) {
            getline(inputFile, name);
            getline(inputFile, role);
            Employee employee(id, name, role);
            employeeRepositories.push_back(employee);
        }
    }
    inputFile.close();
}

// Function to save employee data to a file
void saveEmployeesToFile() {
    ofstream outputFile("employees.txt");
    for (Employee &emp : employeeRepositories) {
        outputFile << emp.getId() << endl;
        outputFile << emp.getName() << endl;
        outputFile << emp.getRole() << endl;
    }
    outputFile.close();
}



