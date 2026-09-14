#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BookingService {
public:
    bool bookSeats(vector<ShowSeat>& seats, vector<string> selectedSeats) {
        for (string selected : selectedSeats) {
            bool found = false;
            for (ShowSeat& seat : seats) {
                if (seat.getSeatNumber() == selected) {
                    found = true;
                    if (seat.isBooked()) {
                        cout << "Seat " << selected << " is already booked!" << endl;
                        return false;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Invalid seat: " << selected << endl;
                return false;
            }
        }
        for (string selected : selectedSeats) {
            for (ShowSeat& seat : seats) {
                if (seat.getSeatNumber() == selected) {
                    seat.bookSeat();
                    break;
                }
            }
        }
        cout << "Seats booked successfully." << endl;
        return true;
    }
    void cancelSeats(vector<ShowSeat>& seats, vector<string> selectedSeats) {
        for (string selected : selectedSeats) {
            for (ShowSeat& seat : seats) {
                if (seat.getSeatNumber() == selected) {
                    seat.cancelSeat();
                    break;
                }
            }
        }
        cout << "Booking cancelled. Seats are available again." << endl;
    }
};