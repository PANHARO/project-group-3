#include<iostream>
#include"../model/employee.hpp"
#include"../repository/employee_repo.hpp"

using namespace std;

void viewAllEmployees(){
    cout<<"___________________"<<endl;
    cout<<"All employees list: "<<endl;
    for(Employee e : employeeRepo){
        e.getEmployeeInfo();
    }
    cout<<"___________________"<<endl;
}

void searchEmployeeInfoById(int id) {
    // Assuming you have a list or database of employees
    for (const Employee& emp : employeeRepo) {
        if (emp.getEmployeeId() == id) {
            emp.getEmployeeInfo();
            return;
        }
    }
    cout << "Employee not found." << endl;
}
Employee searchEmployeeInfoByName(string name){
    for(Employee n : employeeRepo){
        if(n.name==name){
            return n;
        }else{
            cout<<"Employee not found!";
        }
    }
    return{};
}
Employee searchEmployeeInfoByRole(string role){
    for(Employee r : employeeRepo){
        if(r.role==role){
            return r;
        }else{
            cout<<"Employee not found!";
        }
    }
    return{};
}

Employee addEmployee(){
    Employee newEmployee;
    cout<<"Insert employee id: ";cin>>newEmployee.id;
    cout<<"Insert employee name: ";
    cin.ignore();
    getline(cin,newEmployee.name);
    cout<<"Insert employee role: ";
    getline(cin,newEmployee.role);
    employeeRepo.push_back(newEmployee);
    cout<<"Employee has been added successfully! :)"<<endl;
    return newEmployee;
}
bool deleteEmployeeById(int id){
    for(int i=0; i<employeeRepo.size(); i++){
        if(employeeRepo[i].id==id){
            employeeRepo.erase(employeeRepo.begin()+i);
            cout<<"Employee with ID "<<id<<" has been deleted successfully!"<<endl;  
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
        if(e.id==id){
            cout<<"Update details for employee: "<<id<<endl;
            cout<<"Enter employee name: ";
            cin.ignore();
            getline(cin,e.name);
            cout<<"Update employee role: ";
            getline(cin,e.role);
            cout<<"Employee with ID: "<<id<<" has been updated successfully"<<endl;
            return;
        }
    }
    cout<<"Employee with ID: "<<id<<" has not been found!"<<endl; 
}