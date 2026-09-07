#include <vector>
using namespace std;
class PriceCalculator {
    private: const double SILVER_PRICE=150.0,GOLD_PRICE=250.0,PLATINUM_PRICE=400.0;
    public: double calculateTotal(const vector<ShowSeat>& seats)const {
        double total=0;
        for(const auto& s:seats) {
            if(s.getSeatType()=="SILVER")total+=SILVER_PRICE;
            else if(s.getSeatType()=="GOLD")total+=GOLD_PRICE;
            else if(s.getSeatType()=="PLATINUM")total+=PLATINUM_PRICE;
        }
        return total;
    }
}
;
