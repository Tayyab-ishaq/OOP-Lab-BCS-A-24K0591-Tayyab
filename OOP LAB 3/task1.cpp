#include<iostream>
using namespace std;
class student{
    public:
        string name;
        int rollno;
};
int main(){
    student s;
    s.name="Tayyab";
    s.rollno=21;
    cout<<"strudent name:"<<s.name<<endl;
    cout<<"student roll no:"<<s.rollno<<endl;
    return 0;
}