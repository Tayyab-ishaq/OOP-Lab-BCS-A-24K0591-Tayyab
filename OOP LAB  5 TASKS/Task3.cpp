#include <iostream>
using namespace std;
// its an aggregation type : hospital has doctors
class Doctor
{
private:
    string name;
    string specialization;

public:
    Doctor(string n, string s) : name(n), specialization(s) {}
    void display()
    {
        cout << "Name:" << name << endl;
        cout << "specialization is:" << specialization << endl;
    }
};
class Hospital
{
private:
    // d is pointer array of type doctor
    Doctor *d[10];
    string hname;
    int c = 0;

public:
    Hospital(string n)
    {
        hname = n;
    }
    void adddocs(Doctor *doc)
    {
        d[c++] = doc;
    }
    void info()
    {
        cout << "Hospital:" << hname << endl;
        cout << "Doctors working:" << endl;
        for (int i = 0; i < c; i++)
        {
            d[i]->display();
        }
    }
};
int main()
{
    Doctor d("ubaid", "homepathic");
    Doctor c("umair", "halopathic");
    Hospital h("darampur");
    h.adddocs(&d);
    h.adddocs(&c);
    h.info();
    //its a weak relation so the part can exist independently
    // we can do things with doctor class too:
    cout<<endl;
    cout<<"<---------------------------------------->"<<endl;
    Doctor f("umer", "neurosergon");
    f.display();
    return 0;
}