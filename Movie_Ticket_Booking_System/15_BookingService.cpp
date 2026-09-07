#include <iostream>
#include <string>
#include <vector>
using namespace std;
class BookingService {
    private: PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    public: Booking bookTicket(Customer& customer,Show& show,const vector<string>& requestedSeats,Payment& payment) {
        cout<<"\nCustomer: "<<customer.getName()<<"\n";
        vector<ShowSeat*> selected;
        for(const string& n:requestedSeats) {
            ShowSeat* s=show.findSeat(n);
            if(!s) {
                cout<<"Seat "<<n<<" does not exist. Booking rejected.\n";
                return Booking(show,{});
            }
            if(!s->isAvailable()) {
                cout<<"Seat "<<n<<" is already BOOKED. Booking rejected.\n";
                return Booking(show,{});
            }
            for(auto* x:selected)if(x->getSeatNumber()==n) {
                cout<<"Duplicate seat selected. Booking rejected.\n";
                return Booking(show,{});
            }
            selected.push_back(s);
        }
        vector<ShowSeat> bookingSeats;
        for(auto* s:selected) {
            s->bookSeat();
            bookingSeats.push_back(*s);
        }
        double total=priceCalculator.calculateTotal(bookingSeats);
        Booking booking(show,bookingSeats,total);
        if(payment.pay(total)) {
            booking.confirm();
            cout<<"Payment successful. Booking confirmed.\n";
            ticketPrinter.printTicket(booking);
        } else {
            booking.cancel();
            cout<<"Payment failed. Seats released.\n";
        }
        return booking;
    }
    void cancelBooking(Booking& booking) {
        if(booking.getStatus()!="CONFIRMED") {
            cout<<"Only a CONFIRMED booking can be cancelled.\n";
            return;
        }
        booking.cancel();
        cout<<"Booking BK"<<booking.getBookingId()<<" cancelled. Seats are AVAILABLE again.\n";
    }
}
;
