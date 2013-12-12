/** Views namespace holds view strings and functions to be displayed.
 *
 */
#include "View.h"


namespace View {
    
	/**
	 * displays the main menu.
	 */
	void printmenu()
	{
		cout << endl;
        cout << "\t-------------------------------" << endl;
        cout << "\t-          MAIN MENU          -" << endl;
        cout << "\t-------------------------------" << endl;
        cout << "\t- [1] Reservation             -" << endl;
        cout << "\t- [2] Cancellation            -" << endl;
        cout << "\t- [3] Flight Inquiry          -" << endl;
        cout << "\t- [4] Passenger Inquiry       -" << endl;
        cout << "\t- [5] Quit                    -" << endl;
        cout << "\t-------------------------------" << endl;
        cout << endl;
	}

	/**
	 * formats and displays an error message.
	 * @param errorMessage const string& - message to be displayed.
	 */
	void error(const string& errorMessage)
	{
        cout << " !!!\tERROR: " << errorMessage << endl;
	}

	/**
	 * formats and displays a success message string
	 * @param successMessage const string& message to be displayed.
	 */
	void success(const string& successMessage)
	{
		cout <<" +++\t" << successMessage << endl;
	}
    
	/**
	 * formats and displays a question.
	 * @param str const string& - question to be displayed.
	 */
	void question(const string& question)
	{
        cout <<" ~ "+ question << endl;
	}
    
	/**
	 * displays the flight enquiry header for a given flight.
	 * @param flightNumber string& - flight number of the flight.
	 * @param date string& - date string for the flight.
	 * @param time string& - time string for the flight.
	 */
	void flightEnquiryHeader(string& flightNumber, string& date, string& time)
	{
		cout << endl;
        cout << "\t----------------------------------" << endl;
        cout << "\t  FLIGHT ENQUIRY FOR " << flightNumber << endl;
		cout << "\t  Date: " << date << " Time: " << time << endl;
        cout << "\t----------------------------------" << endl;
        cout << endl;
    }
	
	/**
	 * displays flight enquiry sub header given the title.
	 * @param title string& - title for the header.
	 */
	void flightEnquirySubHeader(string& listTitle)
	{
		cout << endl;
		cout << "\t  " << listTitle << endl;
		cout << "\t----------------------------------" << endl;
	}

	/**
	 * displays passenger information for a flight enquiry.
	 * @param passengerName - string& name of the passenger.
	 */
	void flightEnquiryEntry(string& passengerName)
	{
		cout << "\t  " << passengerName << endl;
	}

	/**
	 * displays the table header for passenger enquiry.
	 * @param passengerName - string& name of passenger in enquiry.
	 */
	void passengerEnquiryHeader(string& passengerName)
	{
		cout << endl;
		cout << "\t-------------------------------------------------" << endl;
		cout << "\t  PASSENGER ENQUIRY FOR " << passengerName  << endl;
		cout << "\t-------------------------------------------------" << endl;
		cout << "\t  FLIGHT\t| STATUS\t| SEAT CLASS\t " << endl;
		cout << "\t-------------------------------------------------" << endl;
		cout << endl;
    }
	
	/**
	 * displays information for a particular flight associated with the passenger.
	 * @param flightNumber string& - flightNumber of booking.
	 * @param seat string& - seat of booking.
	 * @param status string& - status of the booking.
	 */
	void passengerEnquiryEntry(string& flightNumber, string& seat, string& status)
	{
		cout << "\t  " << flightNumber << "\t\t  " << status << "\t  " << seat << endl;
	}

	/**
	 * displays a success notification for booked list addition.
	 * @param passengerName const string& - name of passenger added.
	 * @param flightNumber const string& - flightNumber of flight added to.
	 * @param seat const string& - seat type of addition.
	 */
	void successAddedToBookedList(const string& passengerName, const string& flightNumber, const string& seat)
	{
		cout << endl;
		cout << " +++ Passenger " << passengerName
				<< " has booked a " << seat
				<< " class seat for flight " << flightNumber << endl;
	}

	/**
	 * displays a success notification for waiting list addition.
	 * @param passengerName const string& - name of passenger added.
	 * @param flightNumber const string& - flightNumber of flight added to.
	 * @param seat const string& - seat type of addition.
	 */
	void successAddedToWaitingList(const string& passengerName, const string& flightNumber, const string& seat)
	{
		cout << endl;
        cout << " +++ Passenger " << passengerName
        		<< " has been added to the " << seat
        		<< " class waiting list for flight " << flightNumber << endl;
	}

	/**
	 * displays a cancellation notification
	 * @param passengerName string& - name of passenger cancelled.
	 * @param flightNumber string& - flightNumber cancelled.
	 */
	void successCancelledPassenger(string& passengerName, string& flightNumber)
	{
		cout << endl;
        cout<<" +++ Passenger " << passengerName << " has been removed from flight" << endl;
    }

	/**
	 * displays a notification for a successfully transfered passenger.
	 * @param passengerName string& - name of passenger transferd.
	 * @param seat string& - seat passenger has been transfered to.
	 */
	void successTransferedPassenger(const string& passengerName, const string& seat)
	{
		cout << endl;
		cout<<" +++ Passenger " << passengerName << " has been transfered from the " << seat << " waiting list to the booked list" << endl;
	}
    
}

