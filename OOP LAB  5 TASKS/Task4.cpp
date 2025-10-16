#include<iostream>
#include<string>
using namespace std;
class CallRecord{
    private:
        string callerID;
        int durationMinutes;
        static int count;
    public:
        void setCallRecord(string i,int d){
            callerID=i;
            durationMinutes=d;
            count++;
        }
        static int return_call_log(){
            return count;
        }
        void disdetail(){
            cout<<"caller id:"<<callerID<<endl;
            cout<<" call duration in minutes:"<<durationMinutes<<endl;
        }
};
//good practice to declare static member outside class
int CallRecord::count=0;
int main(){
    CallRecord c[20];
    for (int i = 0; i < 20; i++)
    {
        c[i].setCallRecord("caller" + to_string(i + 1),i+1);
    }
    //we can call a static function just by using class name directly cuz it doesnt belong to any object
    for (int i = 0; i < 20; i++)
    {
        c[i].disdetail();
    }
    
    cout<<"total call logs:"<<CallRecord::return_call_log()<<endl;
    return 0;
}