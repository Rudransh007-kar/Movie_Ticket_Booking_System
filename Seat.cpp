#include<iostream>
#include<string>
using namespace std;
class Seat{
    private:
    string number;
    string type;
    public:
    Seat(string number,string type) : number(number),type(type){}
    string getNumber(){
        return number;
    }
    string getType(){
        return type;
    }
    int getPrice(){
        if(type=="SILVER")
        return 150;
        else if(type=="GOLD")
        return 250;
        else
        return 400;
    }
    void showSeat(){
        cout<<number<<" "<<type<<" Rs. "<<getPrice()<<endl;
    }
};