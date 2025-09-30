#include<iostream>
using namespace std;
class calculator{
    private:
        int num1,num2;
    public:
        void setnum(int a,int b){
            num1=a;
            num2=b;
        }
        int sum(){
            return num1+num2;
        }
};
int main(){
    calculator c;
    c.setnum(7,3);
    cout<<"sum of numbers:"<<c.sum()<<endl;
    return 0;
}