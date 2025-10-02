#include <iostream>
using namespace std;
class CurrencyExchange
{
private:
    const double PKR_to_USD_Rate;
    string &branchName;
    int totalTransactions;
    double amountinpkr;
    double usd;

public:
    CurrencyExchange(double p, string b, int t) : PKR_to_USD_Rate(p), branchName(b)
    {
        totalTransactions = t;
    }
    void setpkra(double a)
    {
        amountinpkr = a;
    }
    void convertPKRtoUSD()
    {
        usd = amountinpkr * PKR_to_USD_Rate;
        cout << " USD equivalent of:" << amountinpkr << "Rs.  is:" << usd << endl;
    }
};
int main()
{
    CurrencyExchange c(0.0036, "meezaan", 3);
    c.setpkra(2800.32);
    c.convertPKRtoUSD();
    return 0;
}
