#include<iostream>
#include<string>
using namespace std;
class Payment{
    protected:
    int amount;
    bool status;
    public:
    Payment(int amount) : amount(amount),status(false){}
    virtual bool makePayment()=0;
    bool isSuccessful(){
        return status;
    }
    int getAmount(){
        return amount;
    }
};