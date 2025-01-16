#include<vector>
#include"../model/employee.hpp"
vector<Employee> employeeRepositories;
void loadEmployeesFromFile();  // Load data from the text file to the vector
void saveEmployeesToFile();    // Save data from the vector to the text file
void loginOrRegister();