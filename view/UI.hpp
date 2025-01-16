#include<iostream>
#include"../service/employee_service.hpp"
#include"table.hpp"


using namespace std;

class UI{
    private:
        static int insertOption(){
            int choice;
            cout<<"Enter your choice: ";
            cin>>choice;
            return choice;
        }
        static void option(){
           cout << "_____________________________________________\n";
            cout << "Employee Management System \n";
            cout << "_____________________________________________\n";
            cout << "1. User Login, and Logout \n";  // 1️⃣ and 👤
            cout << "2. List all employees \n";       // 2️⃣ and 📋
            cout << "3. Insert, update, and delete employee data \n"; // 3️⃣ and ✏️
            cout << "4. Search for employees by name, role, ID \n";   // 4️⃣ and 🔍
            cout << "5. Exit \n";                      // 5️⃣ and ❌
            cout << "_____________________________________________\n";
        }
    public:

    static void home(){
        // while(true){
        //     option();
        while (true) {
            option();
            int choice = insertOption();
            switch (choice) {
                case 1:
                    cout << "Under development" << endl;
                    break;
                case 2:
                    cout << "View all employees data" << endl;
                    viewAllEmployees();
                    break;
                case 3: {
                    int opt;
                    cout << "1.Insert employee data" << endl;
                    cout << "2.Update employee data" << endl;
                    cout << "3.Delete employee data" << endl;
                    cout << "Insert a number to continue: ";
                    cin >> opt;
                    switch (opt) {
                        case 1:
                            addEmployee();
                            break;
                        case 2:
                            updateEmployeeById();
                            break;
                        case 3: {
                            int id;
                            cout << "Insert an ID you want to delete: ";
                            cin >> id;
                            deleteEmployeeById(id);
                            break;
                        }
                    }
                    break;
                }
                case 4: {
                    int opts;
                    cout << "1. Search for employee by ID" << endl;
                    cout << "2. Search for employee by name" << endl;
                    cout << "3. Search for employee by role" << endl;
                    cout << "Insert a number to continue: ";
                    cin >> opts;
                    switch (opts) {
                        case 1: {
                            int id;
                            cout << "Insert employee ID: ";
                            cin >> id;
                            searchEmployeeInfoById(id);
                            break;
                        }
                        case 2: {
                            string name;
                            cout << "Insert employee name: ";
                            cin.ignore();
                            getline(cin, name);
                            searchEmployeeInfoByName(name);
                            break;
                        }
                        case 3: {
                            string role;
                            cout << "Insert employee role: ";
                            cin.ignore();
                            getline(cin, role);
                            searchEmployeeInfoByRole(role);
                            break;
                        }
                    }
                    break;
                }
                case 5:
                    cout << "[+] Exiting...\n";
                    exit(0);
                default:
                    cout << "[-] Invalid choice. Please try again.\n";
            }
        }
        }
    };
    
