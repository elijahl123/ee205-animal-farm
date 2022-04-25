//
// Created by elijah on 4/24/2022.
//

#ifndef EE205_LAB_08D_ANIMAL_FARM_2_GENDER_HPP
#define EE205_LAB_08D_ANIMAL_FARM_2_GENDER_HPP

#include <iostream>

/// A gender... for educational use only. This is not intended to be
/// inclusive of all possible genders
enum class Gender {
    UNKNOWN_GENDER = 0,
    MALE,
    FEMALE
};

/// Output Gender as a formatted string
///
/// @param lhs_stream The output stream to write to (usually `cout`). `
/// `lhs` stands for Left Hand Side and means the left side
/// of the `<<` operator.
/// @param rhs_Gender The Gender to output.
/// `rhs` stands for Right Hand Side and means the right
/// side of the `<<` operator.
/// @return `Unknown gender`, `Female` or `Male`.
inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender );


#endif //EE205_LAB_08D_ANIMAL_FARM_2_GENDER_HPP
