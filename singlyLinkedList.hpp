//
// Created by elija on 4/24/2022.
//

#ifndef EE205_LAB_08D_ANIMAL_FARM_2__SINGLYLINKEDLIST_HPP_
#define EE205_LAB_08D_ANIMAL_FARM_2__SINGLYLINKEDLIST_HPP_

#include "list.hpp"

class SinglyLinkedList : public List
{
 public:
	SinglyLinkedList ();

	void 	push_front (Node *newNode);
	Node * 	pop_front () noexcept override;
	void 	insert_after (Node *currentNode, Node *newNode);
	void 	dump () const noexcept override;
	bool 	validate () const noexcept override;
};

#endif //EE205_LAB_08D_ANIMAL_FARM_2__SINGLYLINKEDLIST_HPP_
