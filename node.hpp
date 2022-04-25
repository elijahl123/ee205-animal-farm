//
// Created by elijah on 4/24/2022.
//

#ifndef EE205_LAB_08D_ANIMAL_FARM_2_NODE_HPP
#define EE205_LAB_08D_ANIMAL_FARM_2_NODE_HPP

#include <iostream>
#include <iomanip>

/// Format the heading for dumping members of a class to the console
///
/// Print =====================
#define PRINT_HEADING_FOR_DUMP \
 /* Print =========================================================== */ \
 std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl
/// Format a line for dumping the members of a class to the console.
/// Setup the fields for printing (space pad, left justify, etc.)
#define FORMAT_LINE_FOR_DUMP( className, member ) \
 std::cout << std::setfill( ' ' ) /* Space pad */ \
 << std::left /* Left justify */ \
 << std::boolalpha /* Print `true` or `false` for `bool`s */ \
 << std::setw(8) << (className) \
 << std::setw(20) << (member) \
 << std::setw(52) /* (data) */


class Node {

	friend class List;
	friend class SinglyLinkedList;

protected:
	Node *next;

    /// A generic comparison based on the memory address of the object.
    /// Functions (like sorting) may want to compare two nodes. This is a good default comparison. Other functions may choose to implement their own, more interesting, comparison functions and they can override the > operator.
    /// This allows us to separate the algorithm from the data. We can code an algorithm to operate on a virtual Node > operator and allow the descendants of Node to override > and implement their own ordering.
    /// @returns true if node1 > node2
    static bool compareByAddress(const Node *node1, const Node *node2);
public:
    /// Output the contents of this object.
    /// Reimplemented in Animal, Cat, and Mammal.
    virtual void dump() const;

    /// Check the Node.
    /// This method checks the Node. If something is not right, print out a message and stop the validation. It will not throw an exception.
    /// nullptr is a valid value for the next pointer.
    /// Perform a rudimentary recursive loop test and ensure the next pointer does not refer back to itself. This also has the benefit of dereferencing the next pointer and ensuring it points to a valid address.
    /// Reimplemented in Animal, and Cat.
    /// @returns True if the Node is healthy.
    virtual bool validate() const noexcept;

    /// Compare two nodes: Is the left greater than the right?
    /// @param rightSide The this member is the left side of the > operator. rightSide is the right side of the > operator.
    /// @returns true if leftSide > rightSide
    virtual bool operator>(const Node &rightSide);


};


#endif //EE205_LAB_08D_ANIMAL_FARM_2_NODE_HPP
