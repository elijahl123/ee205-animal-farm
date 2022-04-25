//
// Created by elijah on 4/24/2022.
//

#include "node.hpp"
#include "config.hpp"

bool Node::compareByAddress(const Node *node1, const Node *node2) {
    return node1 > node2;
}

void Node::dump() const {
    PRINT_HEADING_FOR_DUMP;
    FORMAT_LINE_FOR_DUMP("this", this);
    FORMAT_LINE_FOR_DUMP("next", next);
}

bool Node::validate() const noexcept {
    if (next == nullptr) {
        return true;
    }
    if (next == this) {
        std::cout << PROGRAM_NAME  << ": next value cannot point to itself" << std::endl;
        return false;
    }
    return next->validate();
}

bool Node::operator>(const Node &rightSide) {
    return this > &rightSide;
}
