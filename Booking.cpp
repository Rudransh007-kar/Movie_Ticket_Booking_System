#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Booking {
private:
    static int nextBookingId;
    int bookingId;
    int customerId;
    string movieName;
    vector<string> seats;
    int totalAmount;
    bool confirmed;
public:
    Booking(int customer, string movie)
        : bookingId(++nextBookingId),
          customerId(customer),
          movieName(movie),
          totalAmount(0),
          confirmed(false) {}
    void addSeat(string seatNumber, int price) {
        seats.push_back(seatNumber);
        totalAmount += price;
    }
    void confirmBooking() {
        confirmed = true;
    }
    void cancelBooking() {
        confirmed = false;
    }
    bool isConfirmed() {
        return confirmed;
    }
    int getBookingId() {
        return bookingId;
    }
    int getTotalAmount() {
        return totalAmount;
    }
    void showBooking() {
        cout << "\nBooking ID: " << bookingId << endl;
        cout << "Customer ID: " << customerId << endl;
        cout << "Movie: " << movieName << endl;
        cout << "Seats: ";
        for (string seat : seats)
            cout << seat << " ";
        cout << "\nTotal Amount: Rs." << totalAmount << endl;
        if (confirmed)
            cout << "Status: CONFIRMED" << endl;
        else
            cout << "Status: CANCELLED" << endl;
    }
};
int Booking::nextBookingId = 1000;