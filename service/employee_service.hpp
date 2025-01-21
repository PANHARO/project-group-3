#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "../view/table.hpp"
#include <../model/employee.hpp>
#include <../repository/employee_repo.hpp>

using namespace std;

// vector<Employee>getAllEmployee(){
//     return employeeRepositories;
// }

// Employee addEmployee(Employee e){
//     employeeRepositories.push_back(e);
//     cout<<"Employee  " <<e.name<<"has been add succesfully"<<endl;
//     return e;
// }

// Employee getEmployeeById(int id){
//     for(Employee e : employeeRepositories){
//         if(e.id==id){
//             return e;
//         }
//     }
//     return {};
// }

// bool deleteEmployeeByID(int id){

//     for (int i =0; i<employeeRepositories.size(); i++){
//         if(employeeRepositories[i].id==id){
//             employeeRepositories.erase(employeeRepositories.begin()+i);
//             cout<<"\n Employee with ID "<<id<<"delete succesfull"<<endl;
//             return true;
//         }
//     }
//     return false;
// }

void loginEmployee()
{
    string userName;
    string userPassword;
    string storedUsername, storedPassword;
    int choice;
    ifstream login("data1.txt");
    if (login)
    {
        cout << ">>>>>>>>>>>>>>> Welcome to the System <<<<<<<<<<<<<<<" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "please select your choice : ";
        cin >> choice;

        if (choice == 3)
        {
            exit(0);
        }
        if (choice == 1)
        {
            cout << "............... >>> Login <<<..............." << endl;
            cout << "UserName :";
            cin.ignore();
            getline(cin, userName);
            cout << "UserPassword :";
            cin.ignore();
            getline(cin, userPassword);

            getline(login, storedUsername);
            getline(login, storedPassword);
            login.close();
        }
        if (userName == storedUsername && userPassword == storedPassword)
        {
            cout << "Login succesful" << endl;
        }
        else
        {
            cout << "Wrong username or password" << endl;
        }
    }
    else if (choice == 2)
    {
        cout << "============ Register System ============" << endl;
        cout << "Enter userName: ";
        cin >> userName;
        cout << "Enter userPassword: ";
        cin >> userPassword;

        // Store the username and password to login.txt
        ofstream login("data1.txt");
        login << userName << endl
              << userPassword;
        login.close();
    }
    else
    {
        cout << "try again!" << endl;
    }
    
}