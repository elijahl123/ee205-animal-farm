//
// Created by elija on 4/24/2022.
//

#include "weight.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

const Weight::t_weight Weight::UNKNOWN_WEIGHT = -1.0;
const Weight::t_weight Weight::KILOS_IN_A_POUND = 0.453592;
const Weight::t_weight Weight::SLUGS_IN_A_POUND = 0.031051;
const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL = "Kilo";
const string Weight::SLUG_LABEL = "Slug";


void Weight::setMaxWeight(Weight::t_weight newMaxWeight) {
    assert(isWeightValid(newMaxWeight));
    maxWeight = newMaxWeight;
    bHasMax = true;
}

Weight::Weight() noexcept = default;

Weight::Weight(Weight::t_weight newWeight) {
    setWeight(newWeight);
    assert(validate());
    bIsKnown = true;
}

Weight::Weight(enum UnitOfWeight newUnitOfWeight) noexcept {
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight(Weight::t_weight newWeight, enum UnitOfWeight newUnitOfWeight) : Weight(newWeight) {
    unitOfWeight = newUnitOfWeight;
    assert(validate());
}

Weight::Weight(Weight::t_weight newWeight, Weight::t_weight newMaxWeight): Weight(newWeight) {
    setMaxWeight(newMaxWeight);
    assert(validate());
    bHasMax = true;
}

Weight::Weight(enum UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight) : Weight(newUnitOfWeight) {
    setMaxWeight(newMaxWeight);
    assert(validate());
    bHasMax = true;
}

Weight::Weight(Weight::t_weight newWeight, UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight): Weight(newWeight, newUnitOfWeight) {
    setMaxWeight(newMaxWeight);
    assert(validate());
    bHasMax = true;
}

Weight::~Weight() noexcept {
    weight = 0.0;
    maxWeight = 0.0;
    unitOfWeight = UnitOfWeight::POUND;
    bIsKnown = false;
    bHasMax = false;
}

bool Weight::isWeightKnown() const noexcept {
    return weight != 0;
}

bool Weight::hasMaxWeight() const noexcept {
    return maxWeight != 0;
}

Weight::t_weight Weight::getWeight() const noexcept {
    if (Weight::isWeightKnown()) {
        return weight;
    } else {
        return UNKNOWN_WEIGHT;
    }
}

Weight::t_weight Weight::getWeight(enum UnitOfWeight newUnitOfWeight) const noexcept {
    if (Weight::isWeightKnown()) {
        return convertWeight(weight, unitOfWeight, newUnitOfWeight);
    } else {
        return UNKNOWN_WEIGHT;
    }
}

Weight::t_weight Weight::getMaxWeight() const noexcept {
    if (Weight::hasMaxWeight()) {
        return maxWeight;
    } else {
        return UNKNOWN_WEIGHT;
    }
}

Weight::UnitOfWeight Weight::getUnitOfWeight() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(Weight::t_weight newWeight) {
    if (newWeight == 0) {
        throw out_of_range("Weight cannot be 0");
    } else if (bHasMax && newWeight > maxWeight) {
        throw out_of_range("Weight cannot be greater than max weight");
    } else {
        weight = newWeight;
        bIsKnown = true;
    }
}

void Weight::setWeight(Weight::t_weight newWeight, enum UnitOfWeight newUnitOfWeight) {
    if (newWeight == 0) {
        throw out_of_range("Weight cannot be 0");
    } else if (bHasMax && newWeight > maxWeight) {
        throw out_of_range("Weight cannot be greater than max weight");
    } else {
        weight = convertWeight(newWeight, unitOfWeight, newUnitOfWeight);
    }
}

bool Weight::isWeightValid(Weight::t_weight newWeight) const noexcept {
    return newWeight > 0;
}

bool Weight::validate() const noexcept {
    bool bIsValid;
    if (bIsKnown && isWeightValid(weight)) {
        bIsValid = true;
    } else if (bHasMax && isWeightValid(maxWeight)) {
        bIsValid = true;
    } else {
        bIsValid = false;
    }
    return bIsValid;
}

void Weight::dump() const noexcept {
    assert(validate());
    cout << setw(80) << setfill('=') << "" << endl;
    cout << setfill(' ');
    cout << left;
    cout << boolalpha;
    FORMAT_LINE("Weight", "this") << this << endl;
    FORMAT_LINE("Weight", "isKnown") << Weight::isWeightKnown() << endl;
    FORMAT_LINE("Weight", "weight") << Weight::getWeight() << endl;
    FORMAT_LINE("Weight", "unitOfWeight") << Weight::getUnitOfWeight() << endl;
    FORMAT_LINE("Weight", "hasMax") << Weight::hasMaxWeight() << endl;
    FORMAT_LINE("Weight", "maxWeight") << Weight::getMaxWeight() << endl;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    Weight::t_weight lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    Weight::t_weight rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator!=(const Weight &rhs) const {
    return !(rhs == *this);
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    Weight::t_weight lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    Weight::t_weight rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

Weight& Weight::operator=(const Weight &rhs) {
    if (this != &rhs) {
        bIsKnown = rhs.bIsKnown;
        weight = rhs.weight;
        unitOfWeight = rhs.unitOfWeight;
        maxWeight = rhs.maxWeight;
        bHasMax = rhs.bHasMax;
    }
    return *this;
}

Weight &Weight::operator+=(Weight::t_weight rhs_addToWeight) {
    if (bIsKnown) {
        if (rhs_addToWeight == 0) {
            throw out_of_range("Weight cannot be 0");
        } else if (rhs_addToWeight > maxWeight) {
            throw out_of_range("Weight cannot be greater than max weight");
        } else {
            weight += rhs_addToWeight;
        }
    } else {
        throw out_of_range("Weight is unknown");
    }
    return *this;
}

std::ostream& operator<<( ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO:  return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG:  return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}

Weight::t_weight Weight::fromKilogramToPound(Weight::t_weight kilogram) noexcept {
    return (Weight::t_weight) (kilogram / KILOS_IN_A_POUND);
}

Weight::t_weight Weight::fromPoundToKilogram(Weight::t_weight pound) noexcept {
    return (Weight::t_weight) (pound * KILOS_IN_A_POUND);
}

Weight::t_weight Weight::fromSlugToPound(Weight::t_weight slug) noexcept {
    return (Weight::t_weight) (slug / SLUGS_IN_A_POUND);
}

Weight::t_weight Weight::fromPoundToSlug(Weight::t_weight pound) noexcept {
    return (Weight::t_weight) (pound * SLUGS_IN_A_POUND);
}

Weight::t_weight Weight::convertWeight(Weight::t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    if (fromUnit == toUnit) {
        return fromWeight;
    } else if (fromUnit == UnitOfWeight::KILO && toUnit == UnitOfWeight::POUND) {
        return Weight::fromKilogramToPound(fromWeight);
    } else if (fromUnit == UnitOfWeight::POUND && toUnit == UnitOfWeight::KILO) {
        return Weight::fromPoundToKilogram(fromWeight);
    } else if (fromUnit == UnitOfWeight::SLUG && toUnit == UnitOfWeight::POUND) {
        return Weight::fromSlugToPound(fromWeight);
    } else if (fromUnit == UnitOfWeight::POUND && toUnit == UnitOfWeight::SLUG) {
        return Weight::fromPoundToSlug(fromWeight);
    } else {
        return UNKNOWN_WEIGHT;
    }
}