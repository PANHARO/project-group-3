#include <iostream>
#include <vector>
#include <iomanip>
#pragma once

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
#define BLUE "\033[34m"

class Employee
{

private:
    // fields
    int id;
    string name;
    string role;

public:
    // method
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    void setRole(string role)
    {
        this->role = role;
    }
    string getRole()
    {
        return this->role;
    }
    // Constructor
    Employee() {}
    Employee(int id, string name, string role)
    {
        this->id = id;
        this->name = name;
        this->role = role;
    }
    // Output
    void output()
    {
        cout <<BLUE<<"\t\t\t------------------" << endl;
        cout <<"\t\t\tYour Employee ID: " << id << endl;
        cout <<"\t\t\tYour Employee Name: " << name << endl;
        cout <<"\t\t\tYour Employee Role: " << role << endl;
    }
};