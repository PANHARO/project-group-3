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

// Function to combine login and registration in one
void loginOrRegister() {
    int choice;
    string username, password;
    ifstream loginFile("login.txt");  // File to store user login info
    string storedUsername, storedPassword;
    // Check if the file exists, otherwise, prompt to register
    if (loginFile) {
        cout << "============ Welcome to the System ============" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" <<endl;
        cout << "Please choose an option: ";
        cin >> choice;

        // If file exists, login
        if(choice == 3){
        exit(0);
        }
        if (choice == 1) {
            cout << "============ Login System ============" << endl;
            cout << "Username: "; cin >> username;
            cout << "Password: "; cin >> password;

            getline(loginFile, storedUsername);
            getline(loginFile, storedPassword);
            loginFile.close();

            if (username == storedUsername && password == storedPassword) {
                cout << "Login Successful!" << endl;
                cout<<"Press Any Key To Continue"<<endl;
                _getch();
                system("cls");
            } else {
                cout << "Wrong Username or Password\n";
                cout << "Press any key to try again..." << endl;
                _getch();
                system("cls");
                return loginOrRegister();  // Retry login
            }
        }
        // Register new user
        else if (choice == 2) {
            cout << "============ Register System ============" << endl;
            cout << "Enter Username: "; cin >> username;
            cout << "Enter Password: "; cin >> password;

            // Store the username and password to login.txt
            ofstream loginFile("login.txt");
            loginFile << username << endl << password;
            loginFile.close();

            cout << "Registration Successful! You can now login." << endl;
        }
        else {
            cout << "Invalid option! Please try again." << endl;
            _getch();
            return loginOrRegister();  // Retry
        }
    }
    else {
        // No user found, directly go to registration
        cout << "No user found. Please register first." << endl;
        cout << "============ Register System ============" << endl;
        cout << "Enter Username: "; cin >> username;
        cout << "Enter Password: "; cin >> password;

        // Store the username and password to login.txt
        ofstream loginFile("login.txt");
        loginFile << username << endl << password;
        loginFile.close();

        cout << "Registration Successful! You can now login." << endl;
    }
}
    

// Function to get all employees
void getAllEmployees() {
    cout << "[+] View all Employees\n";
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
    cout << "Please input the ID you wish to search: "; cin >> id;
    for (Employee g : employeeRepositories) {
        if (g.getId() == id) {
            g.output();
            return g;
        }
    }
    cout << "Invalid ID" << endl;
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
    cout << "Invalid Name or Role" << endl;
    return {};
}

// Function to update employee information
Employee updateEmployee() {
    int id;
    string updateName, updateRole;
    cout << "Input the employee ID to update: "; cin >> id;
    for (Employee &update : employeeRepositories) {
        if (update.getId() == id) {
            cout << "Change Name from " << update.getName() << " to: "; cin.ignore(); getline(cin, updateName);
            update.setName(updateName);
            cout << "Change from " << update.getRole() << " to: "; getline(cin, updateRole);
            update.setRole(updateRole);
            saveEmployeesToFile();
            cout << "Updated successfully!" << endl;
            return update;
        }
    }
    cout << "Invalid ID" << endl;
    return {};
}

// Function to add an employee
void addEmployee() {
    int id;
    string name, role;
    cout << "Please input employee info" << endl;

    cout << "ID: "; cin >> id;
    for (Employee i : employeeRepositories) {
        if (i.getId() == id) {
            cout << "ID already available. Please input a new ID." << endl;
            return addEmployee();
        }
    }
    cin.ignore();
    cout << "Name: "; getline(cin, name);
    cout << "Role: "; getline(cin, role);

    // Check if the role is already taken
    if (isRoleTaken(role)) {
        cout << "Role is already taken. Please choose a different role." << endl;
        return addEmployee();
    }

    Employee employee(id, name, role);
    employeeRepositories.push_back(employee);
    saveEmployeesToFile();
}

// Function to delete an employee by ID
bool deleteEmployeeById() {
    int id;
    cout << "Please input the ID you want to delete: "; cin >> id;
    for (int x = 0; x < employeeRepositories.size(); x++) {
        if (employeeRepositories[x].getId() == id) {
            employeeRepositories.erase(employeeRepositories.begin() + x);
            saveEmployeesToFile();
            cout << "Deleted successfully!" << endl;
            cout<<"Press Any Key To Continue"<<endl;
            getch();
            system("cls");
            return true;
        }
    }
    cout << "Invalid ID" << endl;
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



