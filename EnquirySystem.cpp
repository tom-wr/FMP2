/** EnquirySystem class controls queries for passenger and flight information.
 */

#include "EnquirySystem.h"

/**
 * EnquirySystem constructor.
 * @param flightList FlightList- reference to the flight list.
 * @param passengerList PassengerList - reference to the passenger list.
 */
EnquirySystem::EnquirySystem(FlightList& _flightList, PassengerList& _passengerList)
:flightList(_flightList), passengerList(_passengerList)
{

}

/**
 * queries flight information based on user input
 * and displays information.
 */
void EnquirySystem::enquireFlightInformation()
{
	UI::outputAskFlightNumber();
	string flightNumber = UI::inputFlightNumber();
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

		UI::enterToContinue();
	}
	else
		View::error(View::errorFlightNotFound);
}

/*
 * displays details of passengers by looping through a given
 * deque of passengers.
 * @param list deque<Passenger*> - deque of Passengers to be enquired
 */
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

/**
 * queries passenger information based on user input
 * and displays information.
 */
void EnquirySystem::enquirePassengerInformation()
{
	// user input
	UI::outputAskPassengerName();
	string passengerName = UI::inputName();

	Passenger *passenger = passengerList.getPassenger(passengerName);
	if(passenger)
	{
		View::passengerEnquiryHeader(passengerName); // output header

		map<string, Booking*> *bookings = passenger->getBookings();
		map<string, Booking*>::iterator it;
		for(it = bookings->begin(); it != bookings->end(); ++it)
		{
			string flightNumber = (*it).first;
			Seat::Type seat = (*it).second->getSeatType();
			BookingStatus::Type status = (*it).second->getStatus();
			string s_seat = Seat::toString[seat];
			string s_status = BookingStatus::toString[status];

			// output
			View::passengerEnquiryEntry(flightNumber, s_seat, s_status);
			UI::enterToContinue();
		}
	}
	else
		View::error(View::errorPassengerNotExist);
}
