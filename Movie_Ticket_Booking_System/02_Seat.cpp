#include <string>
using namespace std;
class Seat {
    private: string seatNumber,type;
    public: Seat(string n="",string t="SILVER"):seatNumber(n),type(t) {
    }
    string getNumber()const {
        return seatNumber;
    }
    string getType()const {
        return type;
    }
}
;
