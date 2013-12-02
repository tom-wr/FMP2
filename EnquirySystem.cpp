#include "EnquirySystem.h"

EnquirySystem::EnquirySystem(FlightList& _flightList, PassengerList& _passengerList)
:flightList(_flightList), passengerList(_passengerList)
{

}

void EnquirySystem::enquireFlightInformation(string& flightNumber)
{
	cout << "enquiring after " << flightNumber << endl;
	Flight *flight = flightList.getFlight(flightNumber);
	if(flight)
	{
		BookedList* bookedList = flight->getBookedList();
		WaitingList* waitingList = flight->getWaitingList();
		vector<Passenger*> bookedFirst = bookedList->getFirstClassList();
		vector<Passenger*> bookedEconomy = bookedList->getEconomyClassList();
		vector<Passenger*> waitingFirst = waitingList->getFirstClassList();
		vector<Passenger*> waitingEconomy = waitingList->getEconomyClassList();

		cout << endl;
		cout << "FLIGHT " << flightNumber << endl;
		cout << endl;
		cout << "BOOKED FIRST CLASS" << endl;
		enquireFlightPassengers(bookedFirst);
		cout << endl;
		cout << "BOOKED ECONOMY CLASS" << endl;
		enquireFlightPassengers(bookedEconomy);
		cout << endl;
		cout << "WAITING FIRST CLASS" << endl;
		enquireFlightPassengers(waitingFirst);
		cout << endl;
		cout << "WAITING ECONOMY CLASS" << endl;
		enquireFlightPassengers(waitingEconomy);
	}
}

void EnquirySystem::enquireFlightPassengers(vector<Passenger*> list)
{
	vector<Passenger*>::iterator it;
	for(it = list.begin(); it != list.end(); ++it)
	{
		cout << (*it)->getName() << endl;
	}
}

void EnquirySystem::enquirePassengerInformation(string& passengerName)
{
	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(passenger)
	{
		cout << endl;
		cout << "------------------" << endl;
		cout << endl;
		cout << "PASSENGER " << passengerName << endl;
		map<string, Booking*> *bookings = passenger->getBookings();
		map<string, Booking*>::iterator it;
		for(it = bookings->begin(); it != bookings->end(); ++it)
		{
			cout << "FlightNumber: " << (*it).first << endl;
			cout << "Class: " << (*it).second->getSeatType() << endl;
			cout << "Status: " << (*it).second->getStatus() << endl;
		}
	}
}
