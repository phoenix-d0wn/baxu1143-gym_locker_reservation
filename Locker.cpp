// Locker.cpp

# include "Locker.h"

using namespace std;

//  Constructor
Locker::Locker() {
    lockerId = 0;
    memberName = "";
    duration = "";
    isReserved = false;
}

void Locker::setLockerDetails(int id, string name, string dur) {
    lockerId = id;
    memberName = name;
    duration = dur;
    isReserved = true;
}

int Locker::getLockerId() { return lockerId; }
string Locker::getMemberName() { return memberName; }
string Locker::getDuration() { return duration; }
bool Locker::getReservationStatus() { return isReserved; }