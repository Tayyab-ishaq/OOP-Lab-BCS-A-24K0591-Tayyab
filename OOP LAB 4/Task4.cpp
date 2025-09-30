#include <iostream>
#include <string>
using namespace std;

class Employee {
    int id;
    string name;
    string designation;
    int hoursWorked;
    double salary;
public:
    Employee() {}
    Employee(int i, string n, string d) {
        id = i;
        name = n;
        designation = d;
        hoursWorked = 0;
        salary = 0;
    }
    Employee(int i, string n, string d, int h) {
        id = i;
        name = n;
        designation = d;
        hoursWorked = h;
        salary = 0;
    }
    int getId() { return id; }
    string getName() { return name; }
    string getDesignation() { return designation; }
    int getHours() { return hoursWorked; }
    double getSalary() { return salary; }
    void addHours(int h) { hoursWorked += h; }
    void setSalary(double s) { salary = s; }
};

class Admin {
    Employee** employees;
    int capacity;
    int count;
public:
    Admin(int c) {
        capacity = c;
        count = 0;
        employees = new Employee*[capacity];
    }
    ~Admin() {
        for (int i = 0; i < count; i++) {
            delete employees[i];
        }
        delete[] employees;
    }
    void addEmployee(int id, string name, string desig) {
        if (count < capacity) {
            employees[count++] = new Employee(id, name, desig);
        }
    }
    void addEmployee(int id, string name, string desig, int h) {
        if (count < capacity) {
            employees[count++] = new Employee(id, name, desig, h);
        }
    }
    void recordAttendance(int id, int hours) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getId() == id) {
                employees[i]->addHours(hours);
                return;
            }
        }
        cout << "Employee not found" << endl;
    }
    void calculateSalary(int id, double hourlyRate) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getId() == id) {
                double total = employees[i]->getHours() * hourlyRate;
                employees[i]->setSalary(total);
                return;
            }
        }
        cout << "Employee not found" << endl;
    }
    void displayAll() {
        if (count == 0) {
            cout << "No employees found" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "ID: " << employees[i]->getId()
                 << " Name: " << employees[i]->getName()
                 << " Designation: " << employees[i]->getDesignation()
                 << " Hours: " << employees[i]->getHours()
                 << " Salary: " << employees[i]->getSalary() << endl;
        }
    }
    void viewEmployee(int id) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getId() == id) {
                cout << "ID: " << employees[i]->getId()
                     << " Name: " << employees[i]->getName()
                     << " Designation: " << employees[i]->getDesignation()
                     << " Hours: " << employees[i]->getHours()
                     << " Salary: " << employees[i]->getSalary() << endl;
                return;
            }
        }
        cout << "Employee not found" << endl;
    }
};

int main() {
    Admin admin(10);

    admin.addEmployee(1, "Ali karim", "Developer");
    admin.addEmployee(2, "Sara Khan", "Manager", 10);
    admin.addEmployee(3, "Omar jaml", "Designer");

    cout << "Initial records:" << endl;
    admin.displayAll();

    cout << endl << "Marking attendance for Ali (5 hours)" << endl;
    admin.recordAttendance(1, 5);

    cout << "Marking attendance for Omar (8 hours)" << endl;
    admin.recordAttendance(3, 8);

    cout << endl << "Calculating salaries..." << endl;
    admin.calculateSalary(1, 1000);
    admin.calculateSalary(2, 1500);
    admin.calculateSalary(3, 1200);

    cout << endl << "All records:" << endl;
    admin.displayAll();

    cout << endl << "Employee 2 viewing their record:" << endl;
    admin.viewEmployee(2);

    return 0;
}
