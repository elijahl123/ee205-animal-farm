///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file breed.hpp
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_LAB_08D_ANIMAL_FARM_2__BREED_HPP_
#define EE205_LAB_08D_ANIMAL_FARM_2__BREED_HPP_

#include <iostream>

enum class Breed {
	UNKNOWN_BREED,
	MAINE_COON,
	MANX,
	SHORTHAIR,
	PERSIAN,
	SPHYNX
};

std::ostream &operator<<(std::ostream &lhs_stream, const Breed &rhs_Breed);

#endif //EE205_LAB_08D_ANIMAL_FARM_2__BREED_HPP_
