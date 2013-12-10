#include "EnquirySystem.h"

EnquirySystem::EnquirySystem(FlightList& _flightList, PassengerList& _passengerList)
:flightList(_flightList), passengerList(_passengerList)
{

}

void EnquirySystem::enquireFlightInformation()
{
	UI::outputAskFlightNumber();
	string flightNumber = UI::inputFlightNumber();
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

		string subBookedFirst("BOOKED FIRST CLASS");
		string subBookedEconomy("BOOKED ECONOMY CLASS");
		string subWaitingFirst("WAITING FIRST CLASS");
		string subWaitingEconomy("WAITING ECONOMY CLASS");
		string date = flight->getDate().toString();
		string time = flight->getDate().timeString();
		View::flightEnquiryHeader(flightNumber, date, time);
		View::flightEnquirySubHeader(subBookedFirst);
		enquireFlightPassengers(bookedFirst);
		View::flightEnquirySubHeader(subBookedEconomy);
		enquireFlightPassengers(bookedEconomy);
		View::flightEnquirySubHeader(subWaitingFirst);
		enquireFlightPassengers(waitingFirst);
		View::flightEnquirySubHeader(subWaitingEconomy);
		enquireFlightPassengers(waitingEconomy);
	}
}

void EnquirySystem::enquireFlightPassengers(deque<Passenger*> list)
{
	if(!list.empty())
	{
		deque<Passenger*>::iterator it;
		for(it = list.begin(); it != list.end(); ++it)
		{
			string passengerName = (*it)->getName();
			View::flightEnquiryEntry(passengerName);
		}
	}
}

void EnquirySystem::enquirePassengerInformation()
{
	UI::outputAskPassengerName();
	string passengerName = UI::inputName();
	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(passenger)
	{
		View::passengerEnquiryHeader(passengerName);

		map<string, Booking*> *bookings = passenger->getBookings();
		map<string, Booking*>::iterator it;
		for(it = bookings->begin(); it != bookings->end(); ++it)
		{
			string flightNumber = (*it).first;
			Seat::Type seat = (*it).second->getSeatType();
			BookingStatus::Type status = (*it).second->getStatus();
			string s_seat = Seat::toString[seat];
			string s_status = BookingStatus::toString[status];

			View::passengerEnquiryEntry(flightNumber, s_seat, s_status);
		}
	}
}
