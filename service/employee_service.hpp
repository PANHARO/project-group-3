#include<iostream>
#include"../model/employee.hpp"
#include"../repository/employee_repo.hpp"

using namespace std;

void viewAllEmployees(){
    cout<<"-------------------"<<endl;
    cout<<"All employees list: "<<endl;
    for(Employee e : employeeRepo){
        e.getEmployeeInfo();
    }
    cout<<"-------------------"<<endl;
}

Employee searchEmployeeInfoById(int id){
    for(Employee i : employeeRepo){
        if(i.ids==id){
            return i;
        }else{
            cout<<"Employee not found!";
        }
    }
    return{};
}
Employee searchEmployeeInfoByName(string name){
    for(Employee n : employeeRepo){
        if(n.names==name){
            return n;
        }else{
            cout<<"Employee not found!";
        }
    }
    return{};
}
Employee searchEmployeeInfoByRole(string role){
    for(Employee r : employeeRepo){
        if(r.roles==role){
            return r;
        }else{
            cout<<"Employee not found!";
        }
    }
    return{};
}

Employee addEmployee(){
    Employee newEmployee;
    cout<<"Insert employee id: ";cin>>newEmployee.ids;
    cout<<"Insert employee name: ";
    cin.ignore();
    getline(cin,newEmployee.names);
    cout<<"Insert employee role: ";
    getline(cin,newEmployee.roles);
    newEmployee.access();
    employeeRepo.push_back(newEmployee);
    cout<<"-----Employee has been added successfully! :)------"<<endl;
    return newEmployee;
}
bool deleteEmployeeById(int id){
    for(int i=0; i<employeeRepo.size(); i++){
        if(employeeRepo[i].ids==id){
            employeeRepo.erase(employeeRepo.begin()+i);
            cout<<"Employee with ID "<<id<<"has been deleted successfully!"<<endl;  
            return true;      
        }
    }
    return false;
}
void updateEmployeeById(){
    int id;
    cout<<"Insert an ID of the employee you want to update: ";
    cin>>id;
    for(Employee e: employeeRepo){
        if(e.ids==id){
            cout<<"Update details for employee: "<<id<<endl;
            cout<<"Enter employee name: ";
            cin.ignore();
            getline(cin,e.names);
            cout<<"Update employee role: ";
            getline(cin,e.roles);
            cout<<"Employee with ID: "<<id<<" has been updated successfully"<<endl;
            return;
        }
    }
    cout<<"Employee with ID: "<<id<<" has not been found!"<<endl; 
}