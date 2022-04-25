//
// Created by elijah on 4/24/2022.
//

#pragma once

#ifndef EE205_LAB_08D_ANIMAL_FARM_2_WEIGHT_HPP
#define EE205_LAB_08D_ANIMAL_FARM_2_WEIGHT_HPP


#include <iostream>

#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

class Weight {
public:
    enum UnitOfWeight {
        POUND, KILO, SLUG
    };
    typedef float t_weight;
private:
    bool bIsKnown = false;
    bool bHasMax = false;
    UnitOfWeight unitOfWeight = POUND;
    t_weight weight{};
    t_weight maxWeight{};

    void setMaxWeight(t_weight newMaxWeight);

public:
    // A default weight
    Weight() noexcept;

    // A weight with a value
    explicit Weight(t_weight newWeight);

    // A weight with a UnitOfWeight. Once UnitOfWeight is set, it can't be changed.
    explicit Weight(UnitOfWeight newUnitOfWeight) noexcept;

    // A weight with a value and UnitOfWeight. Once UnitOfWeight is set, it can't be changed.
    Weight(t_weight newWeight, UnitOfWeight newUnitOfWeight);

    // A weight with a value and a maximum weight. Once maximum weight is set, it can't be changed.
    Weight(t_weight newWeight, t_weight newMaxWeight);

    // A weight with a UnitOfWeight and a maximum weight. Once UnitOfWeight and maximum weight are set, they can't be changed. Once maximum weight is set, it can't be changed.
    Weight(UnitOfWeight newUnitOfWeight, t_weight newMaxWeight);

    // A weight with a value, UnitOfWeight and a maximum weight. Once UnitOfWeight and maximum weight are set, they can't be changed. Once maximum weight is set, it can't be changed.
    Weight(t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight);

    // Destructor
    ~Weight() noexcept;

    // true if the weight is known
    bool isWeightKnown() const noexcept;

    // true if the maximum weight is set
    bool hasMaxWeight() const noexcept;

    // Get the weight in the Weight's units. If the weight is not known, return UNKNOWN_WEIGHT.
    t_weight getWeight() const noexcept;

    // Get the weight in a specified unit.
    t_weight getWeight(UnitOfWeight newUnitOfWeight) const noexcept;

    // Get the maximum weight in the Weight's units. If the maximum weight is not set, return UNKNOWN_WEIGHT.
    t_weight getMaxWeight() const noexcept;

    // Get the UnitOfWeight for this Weight.
    UnitOfWeight getUnitOfWeight() const noexcept;

    /// Set the weight.
    /// \exception out_of_range	When the weight is <=0 or > maxWeight (if maxWeight is set)
    void setWeight(t_weight newWeight);

    /// Set the weight as a specified unit.
    void setWeight(t_weight newWeight, UnitOfWeight newUnitOfWeight);

    /// Check the weight.
    /// Verify that checkWeight > 0
    /// If bHasMax, then checkWeight must be <= maxWeight
    bool isWeightValid(t_weight newWeight) const noexcept;

    /// Check Weight to ensure it's healthy.
    bool validate() const noexcept;

    /// Print the weight class.
    void dump() const noexcept;

    bool operator==(const Weight &rhs_Weight) const;

    bool operator<(const Weight &rhs_Weight) const;

    bool operator!=(const Weight &rhs) const;

    Weight &operator=(const Weight &rhs_Weight);

    Weight &operator+=(t_weight rhs_addToWeight);

    friend std::ostream &operator<<(std::ostream &lhs_stream, Weight::UnitOfWeight rhs_UnitOfWeight);

public:
    static const t_weight UNKNOWN_WEIGHT;
    static const t_weight KILOS_IN_A_POUND;
    static const t_weight SLUGS_IN_A_POUND;
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

    static t_weight fromKilogramToPound(t_weight kilogram) noexcept;

    static t_weight fromPoundToKilogram(t_weight pound) noexcept;

    static t_weight fromSlugToPound(t_weight slug) noexcept;

    static t_weight fromPoundToSlug(t_weight pound) noexcept;

    static t_weight convertWeight(t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

};


#endif //EE205_LAB_08D_ANIMAL_FARM_2_WEIGHT_HPP
