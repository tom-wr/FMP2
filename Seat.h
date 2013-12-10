/** Seat enum to hold types of seat available.
 *
 */
#ifndef SEAT_H_
#define SEAT_H_

#include <string>

namespace Seat{

	/**
	 * Seat type enum.
	 */
	enum Type
	{
		FIRST,
		ECONOMY,
		SIZE_OF_ENUM
	};

	static const char* toString[SIZE_OF_ENUM] = {"FIRST", "ECONOMY"};
}
#endif /* SEAT_H_ */
