//
// Created by Elijah Lopez on 4/24/22.
//

#include "mammal.hpp"

const std::string Mammal::MAMMAL_NAME = "Mammilian";

Mammal::Mammal(const Color newColor, const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newSpecies) : Animal(newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies) {
	color = newColor;
}
Color Mammal::getColor() const noexcept {
	return color;
}
void Mammal::setColor(const Color newColor) noexcept {
	color = newColor;
}
void Mammal::dump() const noexcept {
	Animal::dump();
	FORMAT_LINE_FOR_DUMP("color", getColor());
}









