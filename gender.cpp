//
// Created by elijah on 4/24/2022.
//

#include "gender.hpp"
#include "config.hpp"


inline std::ostream &operator<<(std::ostream &lhs_stream, const Gender &rhs_Gender) {
    switch (rhs_Gender) {
        case Gender::UNKNOWN_GENDER:
            lhs_stream << "Unknown gender";
            break;
        case Gender::MALE:
            lhs_stream << "Male";
            break;
        case Gender::FEMALE:
            lhs_stream << "Female";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }
    return lhs_stream;
}