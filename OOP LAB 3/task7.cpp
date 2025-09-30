#include<iostream>
using namespace std;
class student{
    private:
        string name;
        int rollno;
        double marks;
        char grade;
    public:
    student(string n,int r,double m){
        name=n;
        rollno=r;
        marks=m;
    }
    void CalcGrade(int mark){
        if(mark>=90){
            grade='A';
        }
        else if(mark>=80){
            grade='B';
        }
        else if(mark>=70){
            grade='C';
        }
        else{
            grade='F';
        }
    }
    void diplayinfo(){
        cout<<"student name:"<<name<<endl;
        cout<<"student roll number:"<<rollno<<endl;
        cout<<"student marks:"<<marks<<endl;
        cout<<"student grade:"<<grade<<endl;
    }
};
int main(){
    student s1("Tayyab",21,94.02);
    s1.CalcGrade(94.02);
    s1.diplayinfo();
    student s2("Jawad",23,94.01);
    s2.CalcGrade(94.01);
    s2.diplayinfo();
    return 0;
}