#include<iostream>
#include"../service/employee_service.hpp"
#include<conio.h>  // For _getch() and kbhit()

using namespace std;
    
class UI{
    private:
        static void option(int choice){
            system("cls"); // Clear screen for a fresh display
            cout<<"-------------------------------------------\n";
            cout<<"|   Welcome to Employee Management System    | \n";
            cout<<"-------------------------------------------\n";
            // Display the options with the selected one highlighted
            string menu[7] = {
                "[+] Add a new Employee", 
                "[+] Delete an Employee",
                "[+] Update An Employee", 
                "[+] Search For Employee", 
                "[+] View all Employees", 
                "[+] Logout",
                "Press Enter To Select The Option"
            };

            
            for (int i = 0; i < 7; i++) {
                if (i == choice) {
                    cout << "-> " << menu[i] << " <-\n"; // Highlight the selected option
                } else {
                    cout << menu[i] << endl;
                }
            }
            cout<<"-------------------------------------------\n";
        }

        static void searchMenu(int searchChoice) {
            system("cls");
            cout<<"-------------------------------------------\n";
            cout<<"       Search Employee Options             \n";
            cout<<"-------------------------------------------\n";
            // Display search options with the selected one highlighted
            string searchOptions[4] = {
                "[+] Search by ID", 
                "[+] Search by Name", 
                "[+] Search by Role",
                "Back to Main Menu"
            };

            for (int i = 0; i < 4; i++) {
                if (i == searchChoice) {
                    cout << "-> " << searchOptions[i] << " <-\n"; // Highlight the selected option
                } else {
                    cout << searchOptions[i] << endl;
                }
            }
            cout<<"-------------------------------------------\n";
        }

        static void handleSearchChoice(int searchChoice) {
            string name;
            string role;
            switch (searchChoice) {
                case 0:
                    cout << "[+] Searching by ID..."<<endl;
                    // Add logic to search by ID
                    searchById();
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
                    getch();
                    break;
                case 1:
                    
                    cout<<"Please Input Name You Wish To Search: ";getline(cin,name);
                    searchByNameAndRole(name);
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
                    getch();
                break;
                case 2:
                    
                    cout<<"Please Input Role You Wish To Search: ";getline(cin,role);
                    searchByNameAndRole(role);
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
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
                    cout<<"[+] Add a new Employee"<<endl;
                    addEmployee();  // Your function to add an Employee
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
                    break;
                case 1:
                system("cls");
                    cout<<"[+] Delete an Employee\n";
                    deleteEmployeeById();  // Your function to delete an Employee
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
                    break;
                case 2:
                    system("cls");
                    cout<<"[+] Update an Employee\n";
                    updateEmployee();  // Your function to update an Employee
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
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
                    cout<<"[+] View all Employees\n";
                    getAllEmployees();  // Your function to view all Employee
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
                    _getch();
                    break;
                case 5:
                    cout<<"[+] Logout Successfully\n";
                    return loginOrRegister();
                    break;
                default:
                    cout<<"[-] Invalid choice. Please try again.\n";
                    cout<<"Press Any Key To Go Back To Menu"<<endl;
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

