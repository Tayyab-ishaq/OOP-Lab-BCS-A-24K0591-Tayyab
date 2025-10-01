#include<iostream>
using namespace std;
class Mobileaccount{
    private:
        double balance;
        string phoneNumber;
    public:
    //default constructor
    Mobileaccount(){
        balance=50.0;
        phoneNumber="";
    }
    //parameterized constructor
    Mobileaccount(double b,string p){
        phoneNumber=p;
        balance=b;
    }
    void display(){
        cout<<"phone number is:"<<phoneNumber<<endl;
        cout<<"balance is:"<<balance<<endl;
    }
};
int main(){
    Mobileaccount m(5000.00,"03198478358");
    m.display();
    return 0;
}

