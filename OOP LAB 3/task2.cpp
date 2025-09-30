#include<iostream>
using namespace std;
class student{
    private:
        int rollno;
    public:
        string name;
        void setroll(int roll){
            rollno=roll;
        }
        int getroll(){
            return rollno;
        }
};
int main(){
    student s;
    s.name="Tayyab";
    s.setroll(21);
    cout<<"student name:"<<s.name<<endl;
    cout<<"student roll number:"<<s.getroll()<<endl;
    return 0;
}