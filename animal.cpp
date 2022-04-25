//
// Created by elijah on 4/24/2022.
//

#include "animal.hpp"
#include "config.hpp"

const std::string Animal::KINGDOM_NAME = "Animalia";

Animal::Animal(const Weight::t_weight newMaxWeight, const std::string& newClassification, const std::string& newSpecies)
{
	weight = Weight(newMaxWeight);
	if (!validateClassification(newClassification))
	{
		throw std::invalid_argument(PROGRAM_NAME ": newClassification is empty");
	}
	classification = newClassification;
	if (!validateSpecies(newSpecies))
	{
		throw std::invalid_argument(PROGRAM_NAME ": newSpecies is empty");
	}
	species = newSpecies;
}

Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
	const std::string& newClassification, const std::string& newSpecies) : Animal(newMaxWeight,
	newClassification,
	newSpecies)
{
	gender = newGender;
	weight = Weight(newWeight, newMaxWeight);
}

std::string Animal::getKingdom() const noexcept
{
	return Animal::KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept
{
	return classification;
}

std::string Animal::getSpecies() const noexcept
{
	return species;
}

Gender Animal::getGender() const noexcept
{
	return gender;
}

Weight::t_weight Animal::getWeight() const noexcept
{
	return weight.getWeight();
}

void Animal::setWeight(const Weight::t_weight newWeight)
{
	weight = Weight(newWeight);
}

void Animal::dump() const noexcept
{
	Node::dump();
	FORMAT_LINE_FOR_DUMP("kingdom", getKingdom());
	FORMAT_LINE_FOR_DUMP("species", getSpecies());
	FORMAT_LINE_FOR_DUMP("classification", getClassification());
	FORMAT_LINE_FOR_DUMP("weight", getWeight());
	FORMAT_LINE_FOR_DUMP("gender", getGender());
}

bool Animal::validate() const noexcept
{
	return Node::validate() && validateClassification(classification) && validateSpecies(species) && weight.validate();
}

bool Animal::validateClassification(const std::string& checkClassification) noexcept
{
	return !checkClassification.empty();
}

bool Animal::validateSpecies(const std::string& checkSpecies) noexcept
{
	return !checkSpecies.empty();
}

void Animal::setGender(const Gender newGender)
{
	gender = newGender;
}

