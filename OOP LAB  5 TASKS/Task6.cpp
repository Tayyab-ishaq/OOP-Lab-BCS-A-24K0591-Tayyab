#include<iostream>
using namespace std;
class Employee{
    private:
        string name;
        static int count;
    public:
    //every time an Employee object is created count++
        Employee(string n){
            name=n;
            count++;
        }
    static int getcount(){
        return count;
    }
};
int Employee::count=0;
class ClientProject{
    private:
        Employee *e[3];
    public:
        void assign(Employee *e1,Employee *e2,Employee *e3){
            e[0]=e1;
            e[1]=e2;
            e[2]=e3;
        }
};
int main(){
    Employee e1("sam"),e2("RAAM"),e3("Hizru");
    ClientProject c; // as we created this object c a default construct by compiler is run
    c.assign(&e1,&e2,&e3);
    cout<<"total employees assigned:"<<Employee::getcount()<<endl;
    return 0;
}