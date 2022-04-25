//
// Created by Elijah Lopez on 4/24/22.
//

#include "breed.hpp"
#include "config.hpp"

std::ostream &operator<<(std::ostream &lhs_stream, const Breed &rhs_Breed) {
	switch (rhs_Breed) {
		case Breed::UNKNOWN_BREED: lhs_stream << "Unknown breed";
			break;
		case Breed::MAINE_COON: lhs_stream << "Maine Coon";
			break;
		case Breed::MANX: lhs_stream << "Manx";
			break;
		case Breed::SHORTHAIR: lhs_stream << "Shorthair";
			break;
		case Breed::PERSIAN: lhs_stream << "Persian";
			break;
		case Breed::SPHYNX: lhs_stream << "Sphynx";
			break;
		default: throw std::out_of_range(PROGRAM_NAME ": Breed not mapped to a string");
	}
	return lhs_stream;
}