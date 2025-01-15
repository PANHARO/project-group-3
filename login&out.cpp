#include <iostream>
#include <string>
using namespace std;


bool isLoggedIn = false;
string loggedInAdmin;

void adminLogin();
void registr();
void adminLogout();

int main() {
    int choice;
    do {
        cout << "============================================" << endl;
        cout << "========== |  * Welcome  * |  ==============" << endl;
        cout << "|Menu                                      |" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "| 1. Login                                 |" << endl;
        cout << "| 2. Register                              |" << endl;
        cout << "| 3. Logout                                |" << endl;
        cout << "| 4. Exit                                  |" << endl;
        cout << "============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                adminLogin();
                break;
            case 2:
                registr();
                break;
            case 3:
                adminLogout();
                break;
            case 4:
                cout << "Exiting. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void adminLogin() {
    if (isLoggedIn) {
        cout << "Already logged in as " << loggedInAdmin << ". Please log out first." << endl;
        return;
    }

    string username, password;
    cout << "................................." << endl;
    cout << "|Please enter your login details:|" << endl;
    cout << "................................." << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    
    isLoggedIn = true;
    loggedInAdmin = username;
    cout << "Login successful. Welcome, " << username << "!" << endl;
}

void registr() {
    string username, password;
    cout << "......................" << endl;
    cout << "|Enter a new username:| "<< endl;
    cout << "......................"<< endl;
    cin >> username;
    cout <<"......................."<< endl;
    cout <<"|Enter a new password:|"<< endl;
    cout <<"........................" << endl;
    cin >> password;

    
    cout << "Registration successful. Welcome, " << username << "!" << endl;
}

void adminLogout() {
    if (!isLoggedIn) {
        cout << "No admin is currently logged in." << endl;
        return;
    }

    cout << "Logging out " << loggedInAdmin<<" Goodbye!" << endl;
    isLoggedIn = false;
    loggedInAdmin = "";
}
