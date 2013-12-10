/**
 * Enum for the status of a booking.
 */

#ifndef BOOKINGSTATUS_H_
#define BOOKINGSTATUS_H_

#include <string>

/**
 * BookingStatus namespace
 */
namespace BookingStatus
{
	/**
	 * enum type for the status of a booking NONE, BOOKED or WAITING.
	 */

	enum Type
	{
		NONE,
		BOOKED,
		WAITING,
		SIZE_OF_ENUM
	};

	static const char* toString[SIZE_OF_ENUM] = {"NONE", "BOOKED", "WAITING"};

}

#endif
