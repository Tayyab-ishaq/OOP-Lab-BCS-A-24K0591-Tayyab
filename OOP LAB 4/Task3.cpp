#include<iostream>
using namespace std;
class PropertyDeed{
    private:
    int* ownerid;
    public:
    //parameterized constructor
    PropertyDeed(int i){
        ownerid=new int(i);
        
    }
    ~PropertyDeed(){
        delete ownerid;
    }
    void setid(int i){
       *ownerid=i;
    }

    /* shallow copy constructor
   PropertyDeed(PropertyDeed & obj){
        ownerid=obj.ownerid;
    }
    */ 

    //deepcopy constructor
    PropertyDeed(PropertyDeed &other){
        ownerid=new int(*other.ownerid);
    }
    void dis(){
        cout<<"value:"<<*ownerid<<endl;
        cout<<"address:"<<ownerid<<endl;
    }
};
int main(){
    PropertyDeed ob1(21);
    PropertyDeed ob2(ob1);
    ob1.setid(22);
    ob1.dis(); //value:22
    ob2.dis(); //value:21
    return 0;
}
