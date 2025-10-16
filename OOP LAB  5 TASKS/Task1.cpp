#include<iostream>
using namespace std;
class petrolpump{
		static float pricePerLiter;
		int pumpID;
		int litersFilled;
		float duea;
	public:
		//parameterized constructor
		petrolpump(int i,int f){
			pumpID=i;
			litersFilled=f;
		}
		float due(){
			return	duea=litersFilled*pricePerLiter;
		}
		void printreceipt() {
			cout<<"per litre price of petrol:"<<pricePerLiter<<endl;
			cout<<"pump id is:"<<pumpID<<endl;
			cout<<"due amount to be paid:"<<duea<<endl;
		}
};
 float petrolpump ::pricePerLiter=267.50;
int main(){
	petrolpump p1(21,3);
	p1.due();
	p1.printreceipt();
	petrolpump p2(23,7);
	p2.due();
	p2.printreceipt();
}