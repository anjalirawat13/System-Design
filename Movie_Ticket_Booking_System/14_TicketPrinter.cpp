#include <iostream>
#include <iomanip>
using namespace std;
class TicketPrinter {
    public: void printTicket(const Booking& b)const {
        cout<<"\n========================================\nMOVIE TICKET\n========================================\n";
        cout<<"Booking ID : BK"<<b.getBookingId()<<"\n";
        cout<<"Movie : "<<b.getShow().getMovie().getTitle()<<"\n";
        cout<<"Screen : "<<b.getShow().getScreen().getScreenNumber()<<"\n";
        cout<<"Show Time : "<<b.getShow().getShowTime()<<"\nSeats : ";
        for(size_t i=0;i<b.getSeats().size();++i) {
            if(i)cout<<", ";
            cout<<b.getSeats()[i].getSeatNumber();
        }
        cout<<"\n"<<fixed<<setprecision(2)<<"Total : Rs."<<b.getTotalAmount()<<"\nStatus : "<<b.getStatus()<<"\n========================================\n";
    }
}
;
