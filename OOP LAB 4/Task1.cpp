#include <iostream>
#include <string>
using namespace std;

class User {
    int id;
    string name;
    string password;
    string role;
public:
    User() {}
    User(int i, string n, string p) {
        id = i;
        name = n;
        password = p;
        role = "User";
    }
    User(int i, string n, string p, string r) {
        id = i;
        name = n;
        password = p;
        role = r;
    }
    int getId() { return id; }
    string getName() { return name; }
    string getPassword() { return password; }
    string getRole() { return role; }
    void setRole(string r) { role = r; }
};

class Admin {
    User** users;
    int capacity;
    int count;
public:
    // parameterized constructor
    Admin(int c) {
        capacity = c;
        count = 0;
        users = new User*[capacity];
    }
    bool validatePassword(string p) {
        if (p.length() < 6) return false;
        for (char ch : p) {
            if (!isalnum(ch)) return true;
        }
        return false;
    }
    void addUser(int id, string name, string pass, string role="User") {
        if (count < capacity && validatePassword(pass)) {
            if (role == "") users[count++] = new User(id, name, pass);
            else users[count++] = new User(id, name, pass, role);
        }
    }
    //to access members of another class in any other class we use that class name with this ->
    void removeUser(int id) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getId() == id) {
                delete users[i];
                for (int j = i; j < count - 1; j++) {
                    users[j] = users[j + 1];
                }
                count--;
                break;
            }
        }
    }
    void displayUsers() {
        for (int i = 0; i < count; i++) {
            cout << users[i]->getId() << " " << users[i]->getName() << " " << users[i]->getRole() << endl;
        }
    }
    void searchUser(int id) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getId() == id) {
                cout << users[i]->getId() << " " << users[i]->getName() << " " << users[i]->getRole() << endl;
                return;
            }
        }
        cout << "User not found" << endl;
    }
    void assignRole(int id, string r) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getId() == id) {
                users[i]->setRole(r);
                return;
            }
        }
    }
};

int main() {
    Admin admin(10);
    admin.addUser(1, "Tayyab", "abc@123", "Admin");
    admin.addUser(2, "Sara khan", "pass#4503");
    admin.addUser(3, "Omar Zafar", "xyz@999", "Guest");
    cout << "All users:" << endl;
    admin.displayUsers();
    cout << endl << "Search ID 2:" << endl;
    admin.searchUser(2);
    cout << endl << "Assigning new role to ID 2" << endl;
    admin.assignRole(2, "Admin");
    admin.searchUser(2);
    cout << endl << "Removing user with ID 1" << endl;
    admin.removeUser(1);
    admin.displayUsers();
    return 0;
}
