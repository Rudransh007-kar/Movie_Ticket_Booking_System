#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "Show.cpp"
#include "ShowSeat.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "PaymentTypes.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"
int main() {
    Movie movie("Avengers", "English", 180);
    Customer customer(101, "Raghav", "raghav@gmail.com");
    Show show(1, movie.getTitle(), "7:00 PM", 1);
    vector<ShowSeat> seats = {
        ShowSeat("A1", "SILVER"),
        ShowSeat("A2", "SILVER"),
        ShowSeat("B1", "GOLD"),
        ShowSeat("B2", "GOLD"),
        ShowSeat("C1", "PLATINUM"),
        ShowSeat("C2", "PLATINUM")
    };
    BookingService service;
    while (true) {
        cout << "\n===== MOVIE TICKET BOOKING SYSTEM =====\n";
        cout << "1. Show Movie\n";
        cout << "2. Show Seats\n";
        cout << "3. Book Seats\n";
        cout << "4. Cancel Seats\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        if (choice == 0) {
            cout << "Thank you!\n";
            break;
        }
        if (choice == 1) {
            movie.showMovie();
            show.showDetails();
        }
        else if (choice == 2) {
            for (ShowSeat &seat : seats)
                seat.showSeat();
        }
        else if (choice == 3) {
            string s1, s2;
            cout << "Enter first seat: ";
            cin >> s1;
            cout << "Enter second seat: ";
            cin >> s2;
            vector<string> selected = {s1, s2};
            if (service.bookSeats(seats, selected)) {
                int total = 0;
                for (ShowSeat &seat : seats) {
                    for (string s : selected) {
                        if (seat.getSeatNumber() == s)
                            total += seat.getPrice();
                    }
                }
                cout << "Total Amount: Rs." << total << endl;
                cout << "Payment Method:\n";
                cout << "1. UPI\n";
                cout << "2. Card\n";
                cout << "3. Cash\n";
                cout << "Enter choice: ";
                int paymentChoice;
                cin >> paymentChoice;
                Payment *payment = nullptr;
               if (paymentChoice == 1)
    payment = new UpiPayment(total);
else if (paymentChoice == 2)
    payment = new CardPayment(total);
else if (paymentChoice == 3)
    payment = new CashPayment(total);
else if (paymentChoice == 4) {
    cout << "Payment failed!" << endl;
    service.cancelSeats(seats, selected);
    cout << "Seats released successfully." << endl;
    continue;
}
else {
    cout << "Invalid payment method." << endl;
    service.cancelSeats(seats, selected);
    continue;
}
                if (payment->makePayment()) {
                    Booking booking(customer.getCustomerId(),
                movie.getTitle());
                    for (string s : selected) {
                        for (ShowSeat &seat : seats) {
                            if (seat.getSeatNumber() == s)
                                booking.addSeat(s, seat.getPrice());
                        }
                    }
                    booking.confirmBooking();
                    TicketPrinter printer;
                    printer.printTicket(
                        booking.getBookingId(),
                        customer.getName(),
                        movie.getTitle(),
                        selected,
                        total
                    );
                }
                delete payment;
            }
        }
        else if (choice == 4) {
            string s1, s2;
            cout << "Enter first seat: ";
            cin >> s1;
            cout << "Enter second seat: ";
            cin >> s2;
            vector<string> selected = {s1, s2};
            service.cancelSeats(seats, selected);
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}