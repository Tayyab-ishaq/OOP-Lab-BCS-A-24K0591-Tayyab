#include <iostream>
#include <string>
using namespace std;

struct Doctor {
    string name;
    string department;
};

class Patient {
    int id;
    string name;
    int age;
    string disease;
    Doctor doctorAssigned;
    bool hasDoctor;
public:
    Patient() {}
    Patient(int i, string n, int a, string d) {
        id = i;
        name = n;
        age = a;
        disease = d;
        hasDoctor = false;
    }
    Patient(int i, string n, int a, string d, Doctor doc) {
        id = i;
        name = n;
        age = a;
        disease = d;
        doctorAssigned = doc;
        hasDoctor = true;
    }
    int getId() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    string getDisease() { return disease; }
    bool doctorAssignedCheck() { return hasDoctor; }
    Doctor getDoctor() { return doctorAssigned; }
    void assignDoctor(Doctor doc) {
        doctorAssigned = doc;
        hasDoctor = true;
    }
};

class Hospital {
    Patient** patients;
    int capacity;
    int count;
    int nextId;
public:
    Hospital(int c) {
        capacity = c;
        count = 0;
        nextId = 1;
        patients = new Patient*[capacity];
    }
    ~Hospital() {
        for (int i = 0; i < count; i++) {
            delete patients[i];
        }
        delete[] patients;
    }
    void addPatient(string name, int age, string disease) {
        if (count < capacity) {
            patients[count++] = new Patient(nextId++, name, age, disease);
        }
    }
    void addPatient(string name, int age, string disease, Doctor doc) {
        if (count < capacity) {
            patients[count++] = new Patient(nextId++, name, age, disease, doc);
        }
    }
    void assignDoctorToPatient(int id, Doctor doc) {
        for (int i = 0; i < count; i++) {
            if (patients[i]->getId() == id) {
                patients[i]->assignDoctor(doc);
                return;
            }
        }
        cout << "Patient not found" << endl;
    }
    void removePatient(int id) {
        for (int i = 0; i < count; i++) {
            if (patients[i]->getId() == id) {
                delete patients[i];
                for (int j = i; j < count - 1; j++) {
                    patients[j] = patients[j + 1];
                }
                count--;
                return;
            }
        }
        cout << "Patient not found" << endl;
    }
    void displayPatients() {
        if (count == 0) {
            cout << "No patients found" << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << "ID: " << patients[i]->getId()
                 << " Name: " << patients[i]->getName()
                 << " Age: " << patients[i]->getAge()
                 << " Disease: " << patients[i]->getDisease();
            if (patients[i]->doctorAssignedCheck()) {
                Doctor d = patients[i]->getDoctor();
                cout << " Doctor: " << d.name << " (" << d.department << ")";
            }
            cout << endl;
        }
    }
    void searchPatient(int id) {
        for (int i = 0; i < count; i++) {
            if (patients[i]->getId() == id) {
                cout << "ID: " << patients[i]->getId()
                     << " Name: " << patients[i]->getName()
                     << " Age: " << patients[i]->getAge()
                     << " Disease: " << patients[i]->getDisease();
                if (patients[i]->doctorAssignedCheck()) {
                    Doctor d = patients[i]->getDoctor();
                    cout << " Doctor: " << d.name << " (" << d.department << ")";
                }
                cout << endl;
                return;
            }
        }
        cout << "Patient not found" << endl;
    }
};

int main() {
    Hospital hospital(10);

    Doctor d1 = {"Dr Ahmad Watt", "Cardiology"};
    Doctor d2 = {"Dr Sara Ali", "Neurology"};

    hospital.addPatient("Ali Ahmed Burney", 25, "Flu");
    hospital.addPatient("Omar jamal", 40, "Heart Problem", d1);
    hospital.addPatient("Fatima mubashir", 30, "Migraine problems");

    cout << "All patients:" << endl;
    hospital.displayPatients();

    cout << endl << "Assigning doctor to Ali (ID 1)" << endl;
    hospital.assignDoctorToPatient(1, d2);

    hospital.displayPatients();

    cout << endl << "Searching patient ID 2" << endl;
    hospital.searchPatient(2);

    cout << endl << "Removing patient ID 3" << endl;
    hospital.removePatient(3);

    hospital.displayPatients();

    return 0;
}
