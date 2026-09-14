#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Cinema{
    private:
    string name;
    vector<int> screens;
    public:
    Cinema(string name) : name(name){
        screens.push_back(1);
        screens.push_back(2);
    }
    void addScreen(int screenNumber){
        screens.push_back(screenNumber);
    }
    void showScreens(){
        cout<<"\nCinema: "<<name<<endl;
        cout<<"Available Screens: ";
        for(int screen : screens)
        cout<<screen<<" ";
        cout<<endl;
    }
    string getName(){
        return name;
    }
};