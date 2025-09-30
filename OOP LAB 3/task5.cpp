#include<iostream>
using namespace std;
class concrete{
    private:
        string message;
    public:
    concrete(string m){
        message=m;
    }
    string display(){
        return message;
    }
};
int main(){
    concrete c("Its a concrete class");
    cout<<"printing message:"<<c.display()<<endl;
    return 0;
}