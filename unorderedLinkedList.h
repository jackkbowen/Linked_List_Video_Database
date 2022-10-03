#pragma once
#ifndef unorderedLinkedList_H
#define unorderedLinkedList_H



#include <iostream>

using namespace std;

template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template <class Type>
class linkedListIterator
{
public:
	linkedListIterator();
	
	linkedListIterator(nodeType<Type>* ptr);
	
	Type operator*();
	linkedListIterator<Type> operator++();
	bool operator==(const linkedListIterator<Type>& right) const;
	bool operator!=(const linkedListIterator<Type>& right) const;
	
private:
	nodeType<Type>* current; 

};

template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator = (const linkedListType<Type>&);
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList() const;
	Type front() const;
	Type back() const;
	virtual bool search(const Type& searchItem) const = 0;
	virtual void insertfirst(const Type& newItem) = 0;
	linkedListIterator<Type> begin();
	linkedListIterator<Type> end();
	linkedListType();
	linkedListType(const linkedListType<Type>& otherList);
	~linkedListType();

public:
	int count;
	nodeType<Type>* first;
	nodeType<Type>* last;

private:
	void copyList(const linkedListType<Type>& otherList);

};

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
};

#endif // !unorderedLinkedList_H
