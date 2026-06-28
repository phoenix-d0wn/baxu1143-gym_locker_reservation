// Locker.h

# include <string>

using namespace std;

// ==========================================
// CLASS DEFINITION
// ==========================================

class Locker {
private:
    int lockerId;
    string memberName;
    string duration;
    bool isReserved;

public:
    Locker();
    void setLockerDetails(int id, string name, string dur);
    int getLockerId();
    string getMemberName();
    string getDuration();
    bool getReservationStatus();

};
