#include<iostream>
#pragma once

using namespace std;

class Employee{
private:
    string name;
    int id;
    string role;
public:
    string names;
    int ids;
    string roles;
    void access(){
        id=ids;
        name=names;
        role=roles;
    }
    void inputEmployeeInfo(){
        cout<<"Employee name: ";cin>>name;
        cout<<"Employee id: ";cin>>id;
        cout<<"Employee role: ";cin>>role;
    }
    void getEmployeeInfo(){
        cout<<"-------------------"<<endl;
        cout<<"Employee name: "<<name<<endl;
        cout<<"Employee id: "<<id<<endl;
        cout<<"Employee role: "<<role<<endl;
    }

};