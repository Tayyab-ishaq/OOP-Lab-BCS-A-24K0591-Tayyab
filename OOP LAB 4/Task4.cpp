#include <iostream>
using namespace std;
class ServerSession
{
    int sessionID;

public:
    ServerSession(int i)
    {
        sessionID = i;
        cout << "session has started and resourse acquired" << endl;
    }
    ~ServerSession()
    {
        cout << "session has ended and resourse is released" << endl;
    }
};
int main()
{
    cout<<"entering main:"<<endl;
    {
        ServerSession s(3);
    }
    // we are printing another line to check that the destructor is called first due to braces then this line
    cout<<"main ending"<<endl;
    return 0;
}

