//
// Created by elijah on 4/24/2022.
//

#pragma once

#ifndef EE205_LAB_08D_ANIMAL_FARM_2_ANIMAL_HPP
#define EE205_LAB_08D_ANIMAL_FARM_2_ANIMAL_HPP

#include "node.hpp"
#include "gender.hpp"
#include "weight.hpp"
#include <iostream>

class Animal : public Node
{
 private:
	std::string species;
	std::string classification;
	Gender gender = Gender::UNKNOWN_GENDER;
	Weight weight;
 public:
	static const std::string KINGDOM_NAME;
 public:
	/// Create an Animal with the minimum required fields.
	/// @throw invalid_argument	When the classification is invalid
	/// @throw invalid_argument When the species is invalid
	Animal(Weight::t_weight newMaxWeight, const std::string& newClassification, const std::string& newSpecies);

	/// Create an Animal, populating all of the member variables.
	/// @throw invalid_argument	When the classification is invalid
	/// @throw invalid_argument When the species is invalid
	Animal(Gender newGender,
		Weight::t_weight newWeight,
		Weight::t_weight newMaxWeight,
		const std::string& newClassification,
		const std::string& newSpecies
	);

	/// Get the kingdom, which is Animalia
	/// This can be static but for symmetry with the other get methods, I'm leaving it in the class.
	/// @return KINGDOM_NAME
	std::string getKingdom() const noexcept;

	std::string getClassification() const noexcept;

	std::string getSpecies() const noexcept;

	Gender getGender() const noexcept;

	Weight::t_weight getWeight() const noexcept;

	void setWeight(Weight::t_weight newWeight);

	/// Ask the Animal to say something. This method is virtual and abstract.
	virtual std::string speak() const noexcept = 0;

	/// Output the contents of this object.
	/// Reimplemented from Node.
	/// Reimplemented in Cat, and Mammal.
	void dump() const noexcept override;

	/// Check to see if the Animal object is valid.
	/// Nothing to validate for Gender
	/// Reimplemented from Node.
	/// Reimplemented in Cat.
	bool validate() const noexcept override;

 public:
	///Verify the biological classification is valid.
	/// It's unfortunate that C++'s string library does not have 'trim whitespace' functionality. Note: It is available via Boost.
	/// \param checkClassification The classification to check
	/// \return true if the classification is valid
	static bool validateClassification(const std::string& checkClassification) noexcept;

	/// Verify the biological species is valid.
	/// It's unfortunate that C++'s string library does not have 'trim whitespace' functionality. Note: It is available via Boost.
	/// @param checkSpecies The species to check
	/// @return true if the species is valid
	static bool validateSpecies(const std::string& checkSpecies) noexcept;

 protected:
	/// Set the Animal's Gender.
	/// This is not normally called as you can't change an Animal's gender, therefore this method is protected.
	/// You can only change the gender if it's currently UNKNOWN_GENDER.
	/// \param newGender The new gender
	/// \throw logic_error If you try to change the gender of an Animal
	void setGender(Gender newGender);

};

#endif //EE205_LAB_08D_ANIMAL_FARM_2_ANIMAL_HPP
