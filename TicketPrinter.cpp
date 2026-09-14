#include <iostream>
#include <string>
#include <vector>
using namespace std;
class TicketPrinter {
public:
    void printTicket(int bookingId, string customerName,
                     string movieName, vector<string> seats,
                     int totalAmount) {
        cout << "\n========== MOVIE TICKET ==========\n";
        cout << "Booking ID: " << bookingId << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Movie: " << movieName << endl;
        cout << "Seats: ";
        for (string seat : seats)
            cout << seat << " ";
        cout << "\nTotal Amount: Rs." << totalAmount << endl;
        cout << "Status: CONFIRMED" << endl;
        cout << "==================================\n";
    }
};