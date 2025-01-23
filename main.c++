#include<iostream>
#include "view/ui.hpp"

int main() {


    system("cls");
    loadEmployeesFromFile();  // Load data from the file into the vector
    loginOrRegister();  // Show the login or register menu
    UI::home();  // Navigate to the home UI after login or registration
    return 0;
}