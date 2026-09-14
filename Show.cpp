#include<iostream>
#include<string>
using namespace std;
class Show{
    private:
    int showId;
    string movieName;
    string time;
    int screenNumber;
    public:
    Show(int id,string movie,string showTime,int screen) : showId(id),movieName(movie),time(showTime),screenNumber(screen){}
    int getShowId(){
        return showId;
    }
    string getMovieName(){
        return movieName;
    }
    string getTime(){
        return time;
    }
    int getScreenNumber(){
        return screenNumber;
    }
    void showDetails(){
        cout<<"Show ID: "<<showId<<endl;
        cout<<"Movie: "<<movieName<<endl;
        cout<<"Time: "<<time<<endl;
        cout<<"Screen: "<<screenNumber<<endl;
    }
};