//
// Created by elija on 4/24/2022.
//

#include "list.hpp"

/// true if the List is empty
/// \return true if the List is empty. false if the List has Nodes in it.
bool List::empty() const noexcept
{
	return head == nullptr;
}

/// Get the number of Node objects in the List.
/// \return The number of Nodes in the List
unsigned int List::size() const noexcept
{
	unsigned int size = 0;
	Node *current = head;
	while (current != nullptr)
	{
		size++;
		current = get_next(current);
	}
	return size;
}

/// true if aNode is in the List
/// \param aNode Check this Node to see if it's in the List
/// \return true if aNode is in the List. false if it's not.
bool List::isIn(Node* aNode) const
{
	Node *current = head;
	while (current != nullptr)
	{
		if (current == aNode)
		{
			return true;
		}
		current = get_next(current);
	}
	return false;
}

/// true if the List is sorted
/// This method depends on the Node's > operator.
/// \return true if the List is sorted. false if it's not.
bool List::isSorted() const noexcept
{
	Node *current = head;
	while (current != nullptr)
	{
		if (get_next(current) != nullptr)
		{
			if (current > get_next(current))
			{
				return false;
			}
		}
		current = get_next(current);
	}
	return true;
}

/// Get the first Node in the List.
/// \return The first Node in the List. If the List is empty, return nullptr.
Node* List::get_first() const noexcept
{
	if (empty())
	{
		return nullptr;
	}
	return head;
}

/// Delete all of the nodes in the List.
void List::deleteAllNodes() noexcept
{
	Node *current = head;
	while (current != nullptr)
	{
		Node *next = get_next(current);
		delete current;
		current = next;
	}
	head = nullptr;
}
/// Get the next Node in the List.
/// \param currentNode Start here
/// \return Return the Node that follows currentNode in the List
/// \throw invalid_argument	If currentNode is nullptr
Node* List::get_next(const Node* currentNode)
{
	if (currentNode == nullptr)
	{
		throw std::invalid_argument("currentNode is nullptr");
	}
	return currentNode->next;
}


