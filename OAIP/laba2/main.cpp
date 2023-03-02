#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Employee {
  string name;
  string position;
  int hours_worked;
  double hourly_rate;
  double salary;
};

vector<Employee> employees;

void addEmployee() {
  Employee employee;
  cout << "Enter employee name: ";
  getline(cin, employee.name);
  cout << "Enter employee position: ";
  getline(cin, employee.position);
  cout << "Enter employee hourly rate: ";
  cin >> employee.hourly_rate;
  cout << "Enter employee hours worked: ";
  cin >> employee.hours_worked;
  employee.salary = employee.hourly_rate * employee.hours_worked;
  employees.push_back(employee);
}

void listEmployees() {
  for (int i = 0; i < employees.size(); i++) {
    cout << "Name: " << employees[i].name << endl;
    cout << "Position: " << employees[i].position << endl;
    cout << "Hourly rate: " << employees[i].hourly_rate << endl;
    cout << "Hours worked: " << employees[i].hours_worked << endl;
    cout << "Salary: " << employees[i].salary << endl;
  }
}

void saveEmployees() {
  ofstream outfile;
  outfile.open("employees.txt");
  for (int i = 0; i < employees.size(); i++) {
    outfile << employees[i].name << endl;
    outfile << employees[i].position << endl;
    outfile << employees[i].hourly_rate << endl;
    outfile << employees[i].hours_worked << endl;
    outfile << employees[i].salary << endl;
  }
  outfile.close();
}

void loadEmployees() {
  ifstream infile;
  infile.open("employees.txt");
  while (!infile.eof()) {
    Employee employee;
    getline(infile, employee.name);
    getline(infile, employee.position);
    infile >> employee.hourly_rate;
    infile >> employee.hours_worked;
    infile >> employee.salary;
    employees.push_back(employee);
  }
  infile.close();
}

int main() {
  loadEmployees();
  while (true) {
    cout << "Main menu" << endl;
    cout << "1. Add employee" << endl;
    cout << "2. List employees" << endl;
    cout << "3. Save employees" << endl;
    cout << "4. Exit" << endl;
    int choice;
    cin >> choice; // Reads the user's choice from input
    cin.ignore(); // Ignores the newline character left in the input stream by cin
    switch (choice) {
      case 1:
        addEmployee();
        break;
      case 2:
        listEmployees();
        break;
      case 3:
        saveEmployees();
        break;
      case 4:
        cout << "Exiting program." << endl;
        return 0;
      default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
  }
  return 0;
}
