
#include "cats.hpp"
#include "config.hpp"

const std::string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;

Cat::Cat(const std::string& newName) : Mammal(MAX_WEIGHT, SPECIES_NAME)
{
	setName(newName);
}
Cat::Cat(const std::string& newName,
	const Color newColor,
	const bool newIsFixed,
	const Gender newGender,
	const Weight::t_weight newWeight) : Mammal(newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME)
{
	setName(newName);
}
std::string Cat::getName() const noexcept
{
	return name;
}
void Cat::setName(const std::string& newName)
{
	if (newName.empty())
	{
		throw std::invalid_argument("Name cannot be empty");
	}
	if (newName.length() > MAX_CAT_NAME_LEN)
	{
		throw std::invalid_argument("Name is too long");
	}
	name = newName;
}
bool Cat::isFixed() const noexcept
{
	return isCatFixed;
}
void Cat::fixCat() noexcept
{
	isCatFixed = true;
}
std::string Cat::speak() const noexcept
{
	return "Meow";
}
void Cat::dump() const noexcept
{
	Mammal::dump();
	FORMAT_LINE_FOR_DUMP("name", getName());
	FORMAT_LINE_FOR_DUMP("is fixed", isFixed());
}
bool Cat::validate() const noexcept
{
	return Mammal::validate() && validateName(getName());
}
bool Cat::validateName(const std::string& newName)
{
	if (newName.empty())
	{
		std::cout << PROGRAM_NAME << ": Cat name cannot be empty" << std::endl;
		return false;
	}
	if (newName.length() > MAX_CAT_NAME_LEN)
	{
		std::cout << PROGRAM_NAME << ": Cat name is too long" << std::endl;
		return false;
	}
	return true;
}






