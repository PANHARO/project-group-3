#include<iostream>
using namespace std;

class Employee{
private:
    string name;
    int id;
    string role;
public:
    
    void inputEmployeeInfo(){
        cout<<"Employee name: ";cin>>name;
        cout<<"Employee id: ";cin>>id;
        cout<<"Employee role: ";cin>>role;
    }
    void getEmployeeInfo(){
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee id: "<<id<<endl;
        cout<<"Employee role: "<<role<<endl;
    }

};