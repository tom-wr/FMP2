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
		deque<Passenger*> bookedFirst = bookedList->getFirstClassList();
		deque<Passenger*> bookedEconomy = bookedList->getEconomyClassList();
		deque<Passenger*> waitingFirst = waitingList->getFirstClassList();
		deque<Passenger*> waitingEconomy = waitingList->getEconomyClassList();

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
	cout << "finished enquiring!" <<endl;
}

void EnquirySystem::enquireFlightPassengers(deque<Passenger*> list)
{
	if(!list.empty())
	{
		deque<Passenger*>::iterator it;
		for(it = list.begin(); it != list.end(); ++it)
		{
			cout << (*it)->getName() << endl;
		}
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
