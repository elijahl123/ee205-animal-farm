///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file cats.hpp
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   29_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATS_HPP
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATS_HPP

#include "mammal.hpp"
#include <iostream>
#define MAX_CAT_NAME_LEN 30

class Cat : public Mammal {
 protected:
	std::string name;
	bool isCatFixed;
 public:
	static const std::string SPECIES_NAME;
	static const Weight::t_weight MAX_WEIGHT;
 public:
	explicit Cat(const std::string &newName);
	Cat(const std::string &newName, Color newColor, bool newIsFixed, Gender newGender, Weight::t_weight newWeight);

	std::string getName() const noexcept;
	void setName(const std::string &newName);
	bool isFixed() const noexcept;
	void fixCat() noexcept;
	std::string speak() const noexcept override;
	void dump() const noexcept override;
	bool validate() const noexcept override;

	static bool validateName(const std::string &newName);
};

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CATS_HPP
