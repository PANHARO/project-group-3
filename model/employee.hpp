#include<iostream>
#include<vector>
#include<iomanip>
#pragma once

using namespace std;

class Employee{
    
    private:
        // fields
        int id;
        string name;
        string role;
    public:
        //method
        void setId(int id){
            this->id = id;
        }
        int getId(){ 
            return this->id; 
            }
        void setName(string name){
            this->name = name;
        }
        string getName(){ 
            return this->name; 
            }
        void setRole(string role){
            this->role = role;
        }
        string getRole(){ 
            return this->role; 
            }
        //Constructor
        Employee(){}
        Employee(int id, string name, string role){
            this->id = id;
            this->name = name;
            this->role = role;
        }
        //Output
        void output(){
            cout<<"Your Employee ID: "<<id<<endl;
            cout<<"Your Employee Name: "<<name<<endl;
            cout<<"Your Employee Role: "<<role<<endl;
        }
};