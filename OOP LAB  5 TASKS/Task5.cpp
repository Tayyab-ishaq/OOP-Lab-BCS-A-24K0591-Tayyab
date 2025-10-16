#include<iostream>
using namespace std;
//we all know without kithen there is no apartment exist so its composition
class Kitchen{
    private:
        string color;
    public:
     Kitchen(string c): color(c){}
     
     void getcolor()const{
        cout<<"color of kitchen:"<<color<<endl;
     }
};
class Apartment{
    private:
        const int aid;
        Kitchen c;
    public:
    Apartment(int i,string c): aid(i),c(c){}
    void disinfo()const{
        cout<<"apartment id:"<<aid<<endl;
        c.getcolor();
    }
};
int main(){
    Apartment a(23,"black");
    a.disinfo();
    return 0;
}