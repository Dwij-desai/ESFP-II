#include <iostream>
#include <string>

using namespace std;

// Base class for storing personal information of a passenger
class Passenger {
protected:
    string name;
    string aadharNumber;

public:
    Passenger(string _name, string _aadharNumber) : name(_name), aadharNumber(_aadharNumber) {}
    virtual ~Passenger() {}

    virtual void verifyAadhar() = 0;
};

// Base class for booking a ticket
class Ticket {
protected:
    string source;
    string destination;

public:
    Ticket(string _source, string _destination) : source(_source), destination(_destination) {}
    virtual ~Ticket() {}

    virtual void bookTicket() = 0;
};

// Base class for a train
class Train {
protected:
    string trainNumber;
    string trainName;

public:
    Train(string _trainNumber, string _trainName) : trainNumber(_trainNumber), trainName(_trainName) {}
    virtual ~Train() {}
};

// Class for a return ticket, inherits from Ticket
class ReturnTicket : public Ticket {
protected:
    string returnDate;

public:
    ReturnTicket(string _source, string _destination, string _returnDate) : Ticket(_source, _destination), returnDate(_returnDate) {}

    void bookTicket() override {
        // Implement booking logic for a return ticket
    }
};

// Class for a passenger booking, inherits from Passenger and uses Ticket
class PassengerBooking : public Passenger, public Ticket {
private:
    Train* train;
    ReturnTicket* returnTicket;

public:
    PassengerBooking(string _name, string _aadharNumber, string _source, string _destination) :
        Passenger(_name, _aadharNumber), Ticket(_source, _destination) {}

    void verifyAadhar() override {
        // Implement Aadhar card verification logic
    }

    void bookTicket() override {
        // Implement booking logic for a passenger
    }
};

int main() {
    // Example usage
    PassengerBooking passenger("John Doe", "1234567890", "CityA", "CityB");
    passenger.verifyAadhar();
    passenger.bookTicket();

    return 0;
}
