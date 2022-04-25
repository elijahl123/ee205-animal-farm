//
// Created by elija on 4/24/2022.
//

#ifndef EE205_LAB_08D_ANIMAL_FARM_2__LIST_HPP_
#define EE205_LAB_08D_ANIMAL_FARM_2__LIST_HPP_

#include "node.hpp"
class List : public Node
{
 protected:
	Node* head;
	unsigned int count = 0;

 public:
	bool empty() const noexcept;
	unsigned int size() const noexcept;
	bool isIn(Node* aNode) const;
	bool isSorted() const noexcept;
	Node* get_first() const noexcept;
	void deleteAllNodes() noexcept;

	virtual Node* pop_front() noexcept = 0;
	virtual void dump() const noexcept = 0;
	virtual bool validate() const noexcept = 0;

	static Node* get_next(const Node* currentNode);
};

#endif //EE205_LAB_08D_ANIMAL_FARM_2__LIST_HPP_
