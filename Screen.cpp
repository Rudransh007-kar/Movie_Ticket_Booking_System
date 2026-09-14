#include <iostream>
#include <vector>
using namespace std;
class Screen {
private:
    int screenNumber;
    vector<Seat> seats;
public:
    Screen(int number) : screenNumber(number) {
        seats.push_back(Seat("A1", "SILVER"));
        seats.push_back(Seat("A2", "SILVER"));
        seats.push_back(Seat("B1", "GOLD"));
        seats.push_back(Seat("B2", "GOLD"));
        seats.push_back(Seat("C1", "PLATINUM"));
        seats.push_back(Seat("C2", "PLATINUM"));
    }
    void showSeats() {
        cout << "\nScreen " << screenNumber << " Seats:\n";
        for (Seat &seat : seats)
            seat.showSeat();
    }
    int getScreenNumber() {
        return screenNumber;
    }
};