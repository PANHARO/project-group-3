#include<iostream>
#pragma once

using namespace std;

class Employee{
private:
    string name;
    int id;
    string role;
public:
    string getEmployeeName()const{
        return name;
    }
    void setName(const string& name){
        this->name=name;
    }
    int getEmployeeId()const{
        return id;
    }
    void setId(const int& id){
        this->id = id;
    }
    string getEmployeeRole()const{
        return role;
    }
    void setRole(const int& role){
        this->role = role;
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