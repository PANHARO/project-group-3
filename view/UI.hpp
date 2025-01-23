#include<iostream>
#include"../service/employee_service.hpp"
#include<conio.h>  // For _getch() and kbhit()

using namespace std;
    
class UI{
    private:
        static void option(int choice){
            system("cls"); // Clear screen for a fresh display
        std:: cout<<BLUE<<R"(
        
        
 _____                _                                                                                     _   
|  ___|              | |                                                                                   | |  
| |__ _ __ ___  _ __ | | ___  _   _  ___  ___   _ __ ___   __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ 
|  __| '_ ` _ \| '_ \| |/ _ \| | | |/ _ \/ _ \ | '_ ` _ \ / _` | '_ \ / _` |/ _` |/ _ | '_ ` _ \ / _ | '_ \| __|
| |__| | | | | | |_) | | (_) | |_| |  __|  __/ | | | | | | (_| | | | | (_| | (_| |  __| | | | | |  __| | | | |_ 
\____|_| |_| |_| .__/|_|\___/ \__, |\___|\___| |_| |_| |_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__|
               | |             __/ |                                         __/ |                              
               |_|            |___/                                         |___/                               

        
        )"<< endl;


            cout<<YELLOW<<"\t\t--------------------------------------------------------------------------\n";
            cout<<BLUE  <<"\t\t|             Welcome to Employee Management System                      | \n";
            cout<<YELLOW<<"\t\t--------------------------------------------------------------------------\n";
            // Display the options with the selected one highlighted
            string menu[7] = {
                "\t\t\t\t[+] Add a new Employee", 
                "\t\t\t\t[+] Delete an Employee",
                "\t\t\t\t[+] Update An Employee", 
                "\t\t\t\t[+] Search For Employee", 
                "\t\t\t\t[+] View all Employees", 
                "\t\t\t\t[+] Logout",
                "\t\t\t\tPress Enter To Select The Option"
            };

            
            for (int i = 0; i < 7; i++) {
                if (i == choice) {
                    cout << "  ->  " << menu[i] << " <-\n"; // Highlight the selected option
                } else {
                    cout << menu[i] << endl;
                }
            }
            
        }

        static void searchMenu(int searchChoice) {
            system("cls");
            cout<<YELLOW<<"\t\t\t|-----------------------------------------------------------------|\n";
            cout<<BLUE  <<"\t\t\t|                    Search Employee Options                      |\n";
            cout<<YELLOW<<"\t\t\t|-----------------------------------------------------------------|\n";
            // Display search options with the selected one highlighted
            string searchOptions[4] = {
                "\t\t\t[+] Search by ID                                         ", 
                "\t\t\t[+] Search by Name                                        ", 
                "\t\t\t[+] Search by Role                                       ",
                "\t\t\tBack to Main Menu                                        ",
            };

            for (int i = 0; i < 4; i++) {
                if (i == searchChoice) {
                    cout << "-> " << searchOptions[i] << " <-\n"; // Highlight the selected option
                } else {
                    cout << searchOptions[i] << endl;
                }
            }
            cout<<YELLOW<<"\t\t\t-----------------------------------------------------------------\n";
        }

        static void handleSearchChoice(int searchChoice) {
            string name;
            string role;
            switch (searchChoice) {
                case 0:
                    cout <<BLUE<< "\t\t\t[+] Searching by ID..."<<endl;
                    // Add logic to search by ID
                    searchById();
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    getch();
                    break;
                case 1:
                    
                    cout<<"\t\t\tPlease Input Name You Wish To Search: ";getline(cin,name);
                    searchByNameAndRole(name);
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    getch();
                break;
                case 2:
                    
                    cout<<"\t\t\tPlease Input Role You Wish To Search: ";getline(cin,role);
                    searchByNameAndRole(role);
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    getch();
                break;
                case 3:
                return home();
                break;
            }
        }

        static void handleChoice(int choice){
            switch(choice) {
                case 0:
                system("cls");
                    cout<<"\t\t\t[+] Add a new Employee"<<endl;
                    addEmployee();  // Your function to add an Employee
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    break;
                case 1:
                system("cls");
                    cout<<"\t\t\t[+] Delete an Employee\n";
                    deleteEmployeeById();  // Your function to delete an Employee
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    break;
                case 2:
                    system("cls");
                    cout<<"\t\t\t[+] Update an Employee\n";
                    updateEmployee();  // Your function to update an Employee
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    _getch();
                break;
                case 3: {
                int searchChoice = 0;  // Start at the first search option

            while (true) {
                searchMenu(searchChoice); // Show the search options

                char key = _getch(); // Wait for a key press

                if (key == 27) { // Escape key to go back to the main menu
                    return;
                } else if (key == 13) { // Enter key to select the search option
                    handleSearchChoice(searchChoice);  // Handle the selected search option
                } else if (key == 72) { // Up arrow key
                    searchChoice = (searchChoice - 1 + 4) % 4; // Move up in menu, wrapping around
                } else if (key == 80) { // Down arrow key
                    searchChoice = (searchChoice + 1) % 4; // Move down in menu, wrapping around
                }
            }
            break;
        }
                case 4:
                system("cls");
                    cout<<"\t\t\t[+] View all Employees\n";
                    getAllEmployees();  // Your function to view all Employee
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    _getch();
                    break;
                case 5:
                    cout<<"\t\t\t[+] Logout Successfully\n";
                    return loginOrRegister();
                    break;
                default:
                    cout<<"\t\t\t[-] Invalid choice. Please try again.\n";
                    cout<<"\t\t\tPress Any Key To Go Back To Menu"<<endl;
                    break;
            }
        }
    

        public:
    static void home() {
        int choice = 0;  // Start at the first option

        while (true) {
            option(choice); // Show the options with the current choice highlighted

            char key = _getch(); // Wait for a key press

            if (key == 27) { // Escape key to exit
                break;
            } else if (key == 13) { // Enter key to select the option
                handleChoice(choice);  // Handle the selected option
                 // Wait for a key press before continuing (to return to the menu)
            } else if (key == 72) { // Up arrow key
                choice = (choice - 1 + 6) % 6; // Move up in menu, wrapping around
            } else if (key == 80) { // Down arrow key
                choice = (choice + 1) % 6; // Move down in menu, wrapping around
            }
        }
    }
};

