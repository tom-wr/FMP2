/** Views namespace holds view strings and functions to be displayed.
 *
 */

#ifndef VIEW_H_
#define VIEW_H_

#include <string>
#include <iostream>
#include <vector>

using namespace std;


namespace View {
    
	/**
	 * displays the main menu.
	 */
	void printmenu();

	/**
	 * formats and displays a question.
	 * @param str const string& - question to be displayed.
	 */
	void question(const string& str);
	/*
	 * questions
	 */
	const string q_firstClassFull("First class is fully booked. Would the passenger like to fly economy instead?");
	const string q_yesOrNo("Please enter Yes or No [Y/N]");
	const string q_menuChoice("Please enter your menu choice [1-5]");
	const string q_passengerName("Please enter the full name of the passenger:");
	const string q_flightNumber("Please enter the flight number:");
	const string q_seatType("Please enter the seat class [First or Economy]:");
	const string q_pressEnter("Please press ENTER to continue.");

	/**
	 * formats and displays an error message.
	 * @param errorMessage const string& - message to be displayed.
	 */
    void error(const string& errorMessage);
    /*
     * errors
     */
    const string invalidFlight("Invalid flight number. Please re-enter flightNumber [5 characters EXACTLY]:");
    const string invalidName("Invalid name. Please re-enter name [A-Z] [30 characters MAX]:");
    const string invalidSeatType("Invalid seat class. Please re-enter [FIRST or ECONOMY]");
    const string invalidMenuChoice("Invalid menu choice. Please re-enter [1-6]:");
    const string errorDoubleBooked("Passenger is already booked on this flight.");
    const string errorSameDateBooked("Passenger already has a flight booking for this date.");
    const string errorFlightNotFound("Flight does not exist.");
	const string errorPassengerNotExist("Passenger does not exist.");
	const string errorFile("Could not read file.");
	const string errorFileLine("File input entry line not valid. Skipping entry line:");
	const string errorFileDate("File input entry date not valid.");
	const string errorFileEmpty("File does not contain any data.");

    /**
     * displays the flight enquiry header for a given flight.
     * @param flightNumber string& - flight number of the flight.
     * @param date string& - date string for the flight.
     * @param time string& - time string for the flight.
     */
    void flightEnquiryHeader(string& flightNumber, string& date, string& time);

    /**
     * displays flight enquiry sub header given the title.
     * @param title string& - title for the header.
     */
    void flightEnquirySubHeader(string& title);

    /**
     * displays passenger information for a flight enquiry.
     * @param passengerName - string& name of the passenger.
     */
    void flightEnquiryEntry(string& passengerName);

    /**
     * displays the table header for passenger enquiry.
     * @param passengerName - string& name of passenger in enquiry.
     */
    void passengerEnquiryHeader(string& passengerName);

    /**
     * displays information for a particular flight associated with the passenger.
     * @param flightNumber string& - flightNumber of booking.
     * @param seat string& - seat of booking.
     * @param status string& - status of the booking.
     */
    void passengerEnquiryEntry(string& flightNumber, string& seat, string& status);
    
    /**
     * formats and displays a success message string
     * @param successMessage const string& message to be displayed.
     */
    void success(const string& successMessage);

    /**
	 * displays a success notification for booked list addition.
	 * @param passengerName const string& - name of passenger added.
	 * @param flightNumber const string& - flightNumber of flight added to.
	 * @param seat const string& - seat type of addition.
	 */
    void successAddedToBookedList(const string& passengerName, const string& flightNumber, const string& seat);

    /**
	 * displays a success notification for waiting list addition.
	 * @param passengerName const string& - name of passenger added.
	 * @param flightNumber const string& - flightNumber of flight added to.
	 * @param seat const string& - seat type of addition.
	 */
    void successAddedToWaitingList(const string& passengerName, const string& flightNumber, const string& seat);

    /**
	 * displays a cancellation notification
	 * @param passengerName string& - name of passenger cancelled.
	 * @param flightNumber string& - flightNumber cancelled.
	 */
    void successCancelledPassenger(string& passengerName, string& flightNumber);

    /**
	 * displays a notification for a successfully transfered passenger.
	 * @param passengerName string& - name of passenger transferd.
	 * @param seat string& - seat passenger has been transfered to.
	 */
    void successTransferedPassenger(const string& passengerName, const string& seat);

};
#endif
