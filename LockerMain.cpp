#include <iostream>
#include <string>
#include <limits> // FOR PREVENTING INFINITE LOOPS ON INVALID INPUTS

using namespace std;

// CLASS DEFINITION

class Locker {
private:
    int lockerId;
    string memberName;
    string duration; 
    bool isReserved;

public:
    //  Constructor
    Locker() {
        lockerId = 0;
        memberName = "";
        duration = "";
        isReserved = false;
    }

    
    void setLockerDetails(int id, string name, string dur) {
        lockerId = id;
        memberName = name;
        duration = dur;
        isReserved = true;
    }

    
    int getLockerId() { return lockerId; }
    string getMemberName() { return memberName; }
    string getDuration() { return duration; }
    bool getReservationStatus() { return isReserved; }
};


// FUNCTION 

void addLockerReservation(Locker lockers[], int& currentCount, int maxCapacity);
void sortLockerId(Locker[], const int&);
int getValidatedInteger();


// MAIN FUNCTION

int main() {
    const int MAX_LOCKERS = 50;
    Locker gymLockers[MAX_LOCKERS]; // Array
    int currentReservations = 0; //  current  reserved lockers
    int choice;

    do {
        // System Menu List [cite: 16]
        cout << "\n=====================================" << endl;
        cout << "  GYM LOCKER RESERVATION SYSTEM      " << endl;
        cout << "=====================================" << endl;
        cout << "1. Add Locker Reservation" << endl;
        cout << "2. Display Locker Reservations (Under Construction)" << endl;
        cout << "3. Sort Reservations" << endl;
        cout << "4. Search Reservations (Under Construction)" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";

        int size = sizeof(gymLockers) / sizeof(gymLockers[0]);

        // Verify menu choice input
        choice = getValidatedInteger();

        switch (choice) {
        case 1:
            addLockerReservation(gymLockers, currentReservations, MAX_LOCKERS);
            break;
        case 2:
            cout << "\n[Notice] Display feature is not implemented yet." << endl;
            break;
        case 3:
            sortLockerId(gymLockers, currentReservations);
            break;
        case 4:
            cout << "\n[Notice] Searching feature is not implemented yet." << endl;
            break;
        case 5:
            cout << "\nExiting system. Thank you!" << endl;
            break;
        default:
            cout << "\nInvalid choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}


int getValidatedInteger() {
    int input;
    while (true) {
        cin >> input;

        // Check if the input is valid (e.g., user typed a letter/symbol)
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the bad input completely
            cout << "Invalid input! Please enter a valid number: ";
        }
        else {
            // Check if there is extra trailing garbage after the number (e.g., "123xyz")
            if (cin.peek() != '\n' && cin.peek() != EOF) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the rest of the line
                cout << "Invalid format! Please enter a pure number: ";
                continue;
            }
            return input; 
        }
    }
}

/**
 * Made by MUHAMMAD AIZAT AQMAL BIN ZAINUDDIN
 * Function: addLockerReservation
 * user input to create a new gym locker reservation.
 * Prevents array overflow and cleans input streams.
 */
void addLockerReservation(Locker lockers[], int& currentCount, int maxCapacity) {
    // PREVENT OVERFLOW:
    if (currentCount >= maxCapacity) {
        cout << "\nError: All gym lockers are fully reserved! (Capacity reached: " << maxCapacity << ")" << endl;
        return;
    }

    int id;
    string name;
    string dur;

    cout << "\n--- ADD NEW LOCKER RESERVATION ---" << endl;
    cout << "Enter Locker ID Number (numeric only): ";
    id = getValidatedInteger(); // Safely gets integer and clears stream up to the newline

    cout << "Enter Member Full Name and ";
    getline(cin, name);

    cout << "Enter Rental Duration (e.g., 1 Month, 1 Week): ";
    getline(cin, dur);

    // Save data into the current available index of the object array
    lockers[currentCount].setLockerDetails(id, name, dur);

    // Increment the counter safely
    currentCount++;

    cout << "\nSuccess: Locker reservation added successfully!" << endl;
}

/**
 * Made by (B152510010) ARIFF SANUSI
 * Function: sortLockerId
 * Sorts the list of lockers by Locker ID in ASCENDING order
 * Uses the Bubble Sort technique
 */
 void sortLockerId(Locker locker[], const int& size) {
    
    Locker temp;

    for (int i=0; i<size; i++) {

        for (int j=0; j<size-i-1; j++) {
            if (locker[j].getLockerId() > locker[j+1].getLockerId()) {
                temp = locker[j];
                locker[j] = locker[j+1];
                locker[j+1] = temp;
            }
        }
    }
 }