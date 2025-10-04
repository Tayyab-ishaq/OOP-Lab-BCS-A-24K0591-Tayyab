#include<iostream>
using namespace std;
class SecureBankAccount{
    private:
        int accountNumber;
        double balance;
        const string accountType;
        int *logHistory;
    public:
        SecureBankAccount(int accountNumber,double balance,int size,string a):accountType(a){
            this->accountNumber=accountNumber;
            if(balance<500.0){
                cout<<"error!"<<endl;
            }
            this->balance=balance;
            logHistory=new int(size);
        }
        // using initializer list with deep copy constructor
        SecureBankAccount(SecureBankAccount &other):accountType(other.accountType){
        accountNumber=other.accountNumber;
        balance=other.balance;
            logHistory=new int(*other.logHistory);
        
        }
        ~SecureBankAccount(){
            delete logHistory;
        }
        // const members can only be accessed by constant functions
        void showDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << " PKR" << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Log History Size: " << *logHistory << endl;
    }
};
int main(){
    SecureBankAccount s1(3626,2300.21,7,"Saving");
    SecureBankAccount s2(s1);
     s1.showDetails();
    cout << endl;
    s2.showDetails();
    return 0;
}
