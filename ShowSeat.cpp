#include<iostream>
#include<string>
using namespace std;
class ShowSeat{
    private:
    string seatNumber;
    string seatType;
    bool booked;
    public:
    ShowSeat(string number,string type) : seatNumber(number),seatType(type),booked(false){}
    string getSeatNumber(){
        return seatNumber;
    }
    string getSeatType(){
        return seatType;
    }
    bool isBooked(){
        return booked;
    }
    int getPrice(){
        if(seatType=="SILVER")
        return 150;
        else if(seatType=="GOLD")
        return 250;
        else 
        return 400;
    }
    bool bookSeat(){
        if(booked){
            cout<<"Seat "<<seatNumber<<" is already booked!"<<endl;
            return false;
        }
        booked=true;
        return true;
    }
    void cancelSeat(){
        booked=false;
    }
    void showSeat(){
        cout<<seatNumber<< " | "<<seatType<< " | Rs."<<getPrice()<< " | ";
        if(booked)
        cout<< "BOOKED";
        else
        cout<< "AVAILABLE";
        cout<<endl;
    }
};