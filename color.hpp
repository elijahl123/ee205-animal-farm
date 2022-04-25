///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file color.hpp
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_LAB_08D_ANIMAL_FARM_2__COLOR_HPP_
#define EE205_LAB_08D_ANIMAL_FARM_2__COLOR_HPP_

#include <iostream>

enum class Color
{
	UNKNOWN_COLOR = 0, BLACK, BROWN, WHITE,
	RED, BLUE, GREEN, GINGER,
	CREAM, CINNAMON, CALICO
};

std::ostream& operator<<(std::ostream& lhs_stream, const Color& rhs_Color);

#endif //EE205_LAB_08D_ANIMAL_FARM_2__COLOR_HPP_
