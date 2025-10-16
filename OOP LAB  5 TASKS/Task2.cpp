#include<iostream>
using namespace std;
class MobileDevice{
		private:
			string modelName;
			const string IMEINumber;
		public:
			MobileDevice(string n,string i):IMEINumber(i){
				modelName=n;
			}
			void verifyDevice() const{
				cout<<"mobile model name:"<<modelName<<endl;
				cout<<"mobile imei number:"<<IMEINumber<<endl;
			}
};

int main(){
	MobileDevice m("nokia 3310","32-654321-567890-3");
	m.verifyDevice();
}