//
// Created by elija on 4/24/2022.
//

#include "singlyLinkedList.hpp"
#include "config.hpp"
SinglyLinkedList::SinglyLinkedList()
{
	head = nullptr;
}

/// Insert newNode to the beginning of the List.
/// \param newNode The Node to add to the List. It must be a valid Node. newNode can not be nullptr.
/// \throw invalid_argument	If newNode is nullptr.
/// \throw domain_error	If newNode is not valid.
/// \throw logic_error	If newNode is already in the container.
void SinglyLinkedList::push_front(Node* newNode)
{
	if (newNode == nullptr)
		throw std::invalid_argument("newNode can not be nullptr");
	if (!newNode->validate())
		throw std::domain_error("newNode is not valid");
	// check if newNode is already in the container
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp == newNode)
			throw std::logic_error("newNode is already in the container");
		temp = get_next(temp);
	}
	// Insert newNode to the beginning of the Linked List
	newNode->next = head;
	head = newNode;
}

/// Remove and return the first Node in the List.
/// \return The first Node in the List or nullptr if the List is empty
Node* SinglyLinkedList::pop_front() noexcept
{
	if (head == nullptr)
		return nullptr;
	Node* temp = head;
	head = head->next;
	temp->next = nullptr;
	return temp;
}

/// Insert newNode after currentNode
/// Use push_front() to add to an empty List.
/// \param currentNode Insert newNode after this Node. Must not be nullptr. Must be in the List.
/// \param newNode The Node to add to the List. Must not be nullptr. Must not be in the List.
/// \throw logic_error	If the List is empty
/// \throw invalid_argument	If currentNode is nullptr
/// \throw logic_error	If currentNode is not in the List.
/// \throw invalid_argument	If newNode is nullptr
/// \throw domain_error	If newNode is not valid
/// \throw logic_error	If newNode is already in the List
void SinglyLinkedList::insert_after(Node* currentNode, Node* newNode)
{
	if (empty())
		throw std::logic_error("List is empty");
	if (currentNode == nullptr)
		throw std::invalid_argument("currentNode can not be nullptr");
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp == currentNode)
			break;
		temp = temp->next;
	}
	if (temp == nullptr)
		throw std::logic_error("currentNode is not in the List");
	if (newNode == nullptr)
		throw std::invalid_argument("newNode can not be nullptr");
	if (!newNode->validate())
		throw std::domain_error("newNode is not valid");
	temp = head;
	while (temp != nullptr)
	{
		if (temp == newNode)
			throw std::logic_error("newNode is already in the List");
		temp = temp->next;
	}
	// Insert newNode after currentNode
	newNode->next = currentNode->next;
	currentNode->next = newNode;
}

void SinglyLinkedList::dump() const noexcept
{
	PRINT_HEADING_FOR_DUMP;
	FORMAT_LINE_FOR_DUMP("this", this);
	FORMAT_LINE_FOR_DUMP("head", head);
	FORMAT_LINE_FOR_DUMP("size", size());
}

/// Check to see if the container is valid.
/// If something is not right, it will print a message and stop the validation. It will not throw an exception.
/// \note This method calls validate() on each Node.
/// \return true if the List is healthy. false if otherwise.
bool SinglyLinkedList::validate() const noexcept
{
	if (head == nullptr)
		return true;
	Node* current = head;
	while (current != nullptr)
	{
		if (!current->validate())
		{
			std::cout << PROGRAM_NAME <<  ": invalid node" << std::endl;
			return false;
		}
		current = current->next;
	}
	return true;
}
