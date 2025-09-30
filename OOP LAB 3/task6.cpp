#include<iostream>
using namespace std;
class vehicle{
    public:
        string make;
        string model;
    void displayinfo(){
        cout<<"car make:"<<make<<endl;
        cout<<"car model:"<<model<<endl;
    }
};
class car:public vehicle{
    public:
        string enginetype;
    void displayinfo(){
        vehicle::displayinfo();
        cout<<"engine type:"<<enginetype<<endl;
    }

};
int main(){
    car c;
    c.make="BMW";
    c.model="M5 COMPETITION CS";
    c.enginetype="V8 Twin Turbu";
    c.displayinfo();
    return 0;
}