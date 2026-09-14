#include<iostream>
#include<string>
using namespace std;
class Customer{
    private:
    int customerId;
    string name;
    string email;
    public:
  Customer(int id, string name, string email) {
    this->customerId = id;
    this->name = name;
    this->email = email;
}
    int getCustomerId(){
        return customerId;
    }
    string getName(){
        return name;
        }
    string getEmail(){
        return email;
    }
    void showCustomer(){
        cout<<"\nCustomer ID: "<<customerId<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Email: "<<email<<endl;
    }
 };
