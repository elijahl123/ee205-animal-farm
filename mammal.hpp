///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_2 - EE 205 - Spr 2022
///
/// @file mammal.h
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#ifndef EE205_LAB_08D_ANIMAL_FARM_2__MAMMAL_HPP_
#define EE205_LAB_08D_ANIMAL_FARM_2__MAMMAL_HPP_

#include "color.hpp"
#include "animal.hpp"

class Mammal : public Animal {
 protected:
	Color color = Color::UNKNOWN_COLOR;

 public:
	static const std::string MAMMAL_NAME;

 public:
	Mammal(const Weight::t_weight newMaxWeight, const std::string &newSpecies) : Animal(newMaxWeight, MAMMAL_NAME, newSpecies) {};
	Mammal(Color newColor, Gender newGender, Weight::t_weight newWeight, Weight::t_weight newMaxWeight, const std::string &newSpecies);

	Color getColor() const noexcept;
	void setColor(Color newColor) noexcept;
	void dump() const noexcept override;
};

#endif //EE205_LAB_08D_ANIMAL_FARM_2__MAMMAL_HPP_
