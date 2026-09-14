#include <iostream>
using namespace std;
class UpiPayment : public Payment {
public:
    UpiPayment(int amount) : Payment(amount) {}
    bool makePayment() override {
        cout << "UPI Payment of Rs." << amount << " successful." << endl;
        status = true;
        return status;
    }
};
class CardPayment : public Payment {
public:
    CardPayment(int amount) : Payment(amount) {}
    bool makePayment() override {
        cout << "Card Payment of Rs." << amount << " successful." << endl;
        status = true;
        return status;
    }
};
class CashPayment : public Payment {
public:
    CashPayment(int amount) : Payment(amount) {}
    bool makePayment() override {
        cout << "Cash Payment of Rs." << amount << " successful." << endl;
        status = true;
        return status;
    }
};