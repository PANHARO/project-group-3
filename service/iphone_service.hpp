#include<string>
#include<vector>
#include<algorithm>
#include<cctype>
#include"../model/employee.hpp"
#include"../repository/employee_repo.hpp"
#include"../view/table.hpp"
using namespace std;

void getAllEmployees(){
    
    cout<<"[+] View all iPhones\n";
                vector<vector<string>> employees;
                // columns  
                vector<string> columns = {"ID", "Name", "Role"};
                for(Employee &p : employeeRepositories){
                vector<string> data = {to_string(p.getId()),(p.getName()),(p.getRole())};
                employees.push_back(data);
                }
    printTable(employees, columns);
 
}
Employee searchById(){
    // your code here...]
    int id;
    cout<<"Please Input Id You Wish To Search: ";cin>>id;
    for (Employee g : employeeRepositories){
        if(g.getId() == id){
            g.output();
            return g;
        }
    }
    cout<<"Invalid ID"<<endl;
    return {};
}
Employee searchByNameAndRole(string input){
    
    // your code here...]
    for (Employee u : employeeRepositories){
        if(u.getName() == input || u.getRole() == input){
            u.output();
            return u;
        }
    }
    cout<<"Invalid Name"<<endl;
    return {};
}
Employee updateEmployee(){
    int id;
    string updateName;
    string updateRole;
    cout<<"Input The Employee Id To Update: ";cin>>id;
    for (Employee &update : employeeRepositories){
        if(update.getId() == id){
            cout<<"Change Name From "<<update.getName()<<" To: ";cin.ignore();getline(cin,updateName);
            update.setName(updateName);
            cout<<"Change From "<<update.getRole()<<" To: ";getline(cin,updateRole);
            update.setRole(updateRole);
            cout<<"Update Successfully"<<endl;
            return update;
        }
    }
    cout<<"Invalid ID"<<endl;
    return {};
}

void addEmployee(){
    // your code here...
    int id;
    string name;
    string role;
    cout<<"Please Input Your Employee Info"<<endl;

    cout<<"ID: ";cin>>id;
    for(Employee i : employeeRepositories){
        if(i.getId() == id){
            cout<<"ID Already Available Please Input New ID"<<endl;
            return addEmployee();
        }
    }
    cin.ignore();
    cout<<"Name: ";getline(cin,name);
    cout<<"Role: ";getline(cin,role);
    Employee employee(id,name,role);
    employeeRepositories.push_back(employee);
    
}

bool deleteEmployeeById(){
    // your code here...
    int id;
    cout<<"Please Input The Id You Want To Delete: ";cin>>id;
    for (int x = 0; x < employeeRepositories.size(); x++ ){
        if (employeeRepositories[x].getId() == id){
            employeeRepositories.erase(employeeRepositories.begin() + x);
            cout<<"Delete Successfully"<<endl;
            return true;
        }
    }
    cout<<"Invalid Id"<<endl;
    return false;
}