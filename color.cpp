//
// Created by Elijah Lopez on 4/24/22.
//

#include "color.hpp"
#include "config.hpp"

std::ostream &operator<<(std::ostream &lhs_stream, const Color &rhs_Color) {
	switch (rhs_Color) {
		case Color::BLACK:
			lhs_stream << "Black";
			break;
		case Color::BROWN:
			lhs_stream << "Brown";
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
	case Color::GINGER:
		lhs_stream << "Ginger";
		break;
	case Color::CREAM:
		lhs_stream << "Cream";
		break;
	case Color::CINNAMON:
		lhs_stream << "Cinnamon";
		break;
	case Color::CALICO:
		lhs_stream << "Calico";
		break;
		default:
			throw std::out_of_range( PROGRAM_NAME ": Color not mapped to a string" );
	}
	return lhs_stream;
};