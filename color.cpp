//
// Created by Elijah Lopez on 4/24/22.
//

#include "color.hpp"
#include "config.hpp"

std::ostream &operator<<(std::ostream &lhs_stream, const Color &rhs_Color) {
	switch (rhs_Color) {
		case Color::UNKNOWN_COLOR:
			lhs_stream << "Unknown color";
			break;
		case Color::BLACK:
			lhs_stream << "Black";
			break;
		case Color::WHITE:
			lhs_stream << "White";
			break;
		case Color::RED:
			lhs_stream << "Red";
			break;
		case Color::BLUE:
			lhs_stream << "Blue";
			break;
		case Color::GREEN:
			lhs_stream << "Green";
			break;
		case Color::PINK:
			lhs_stream << "Pink";
			break;
		default:
			throw std::out_of_range( PROGRAM_NAME ": Color not mapped to a string" );
	}
	return lhs_stream;
};