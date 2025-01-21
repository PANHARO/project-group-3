#include <iostream>
#include "../service/employee_service.hpp"
#include "table.hpp"

using namespace std;

class UI
{
private:
    static int insertOption()
    {
        int choice;
        cout << "Entern your choice :";
        cin >> choice;
        return choice;
    }
    static void welcome()
    {
        cout << "-------------------------------------------\n";
        cout << "          Employee Management System     \n";
        cout << "-------------------------------------------\n";
    }
    static void option()
    {
        cout << "1. Admin login and logout\n";
        cout << "2. List all employee\n";
        cout << "3. Insert ,update and delet employee\n";
        cout << "4.Search for employee by name, role and id\n";
        cout << "5. Exit\n";
        cout << "-------------------------------------------\n";
    }

public:
    static void home()
    {
        welcome();
        while (true)
        {
            option();
            int choice=insertOption();
            switch(choice){
                case 1:
                
                break;
                default:
                cout<<"Invalid program "<<endl;
                exit(0);
            }
        }
    }
};