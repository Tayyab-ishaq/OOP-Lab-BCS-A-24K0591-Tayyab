#include<iostream>
using namespace std;
class NUCES_Student{
        private:
        int id;
        string name;
        public:
        //default constructor
        NUCES_Student(){
            id=0;
            name="not registered";
        }
        //parameterized with 1 argument
        NUCES_Student(int i){
            id=i;
            name="Name pending";
        }
        //with 2 arguments
        NUCES_Student(int id,string name){
            this->id=id;
            this->name=name;
        }
        void display(){
            cout<<"id:"<<id<<endl;
            cout<<"name:"<<name<<endl;
        }
};
int main(){
    NUCES_Student s(591,"Tayyab");
    s.display();
    return 0;
}

