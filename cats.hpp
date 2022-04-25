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
#define MAX_CATS 1024
#define MAX_CAT_NAME_LEN 30
#define UNKNOWN_WEIGHT -1

/// Format a line for printing the members of a class
#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

class Cat : public Mammal {
 protected:
	std::string name;
	bool isCatFixed;
 public:
	static const std::string SPECIES_NAME;
	static const Weight::t_weight MAX_WEIGHT;
 public:
	Cat(const std::string &newName);
	Cat(const std::string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const Weight::t_weight newWeight);

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
