#include<iostream>
using namespace std;
class OrderDetails{
    private:
        int orderID;
        string itemName;
        const double deliveryFee;
    public:
        OrderDetails(int orderID,string itemName,double deliv):deliveryFee(deliv){
            this->orderID=orderID;
            this->itemName=itemName;
        }
        ~OrderDetails(){
            cout<<"Order id:"<<orderID<<" Archived and memory cleared"<<endl;
        }
};
int main(){
    OrderDetails o1(29,"earpfun",2300.29);
    OrderDetails o2(21,"laptop",5300.29);  //firstly this will be deleted cuz of scope
    return 0;
}
