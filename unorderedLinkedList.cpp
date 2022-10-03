#include "unorderedLinkedList.h"

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}
template <class Type>
linkedListIterator<Type>::
linkedListIterator(nodeType<Type>* ptr)
{
    current = ptr;
}
template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}
template <class Type>
bool linkedListIterator<Type>::operator==
(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}
template <class Type>
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}



template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList() const
{
    //pointer to deallocate the memory
    //occupied by the node
    //while there are nodes in the list
    nodeType<Type>* temp;

    while (first != NULL)
    {
        temp = first;        // set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;         // deallocate the memory occupied by temp
    }
                            
        
    last = NULL; //initialize last to NULL; first has already
                 //been set to NULL by the while loop
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList(); //if the list has any nodes, delete them
}

template<class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type>* current; //Pointer to traverse the list

    current = first;         //set current point to the first node
    while (current != NULL)  //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != NULL);
    return first->info; //return the info of the first node
}//end front

template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != NULL);
    return last->info; //return the info of the last node
}//end back

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);
    return temp;
}

template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
    nodeType<Type>* newNode; //pointer to create a node
    nodeType<Type>* current; //pointer to traverse the list
    if (first != NULL) //if the list is nonempty, make it empty
        destroyList();
    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the
        //list to be copied
        count = otherList.count;
        //copy the first node
        first = new nodeType<Type>; //create the node
        first->info = current->info; //copy the info
        first->link = NULL; //set the link field of the node to NULL
        last = first; //make last point to the first node
        current = current->link; //make current point to the next
        // node
        //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>; //create a node
            newNode->info = current->info; //copy the info
            newNode->link = NULL; //set the link of newNode to NULL
            last->link = newNode; //attach newNode after last
            last = newNode; //make last point to the actual last
            //node
            current = current->link; //make current point to the
            //next node
        }//end while
    }//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
    destroyList();
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = NULL;
    copyList(otherList);
}//end copy constructor

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    return *this;
}

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type>* current; //pointer to traverse the list
    bool found = false;
    current = first; //set current to point to the first
    //node in the list
    while (current != NULL && !found) //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
            //the next node
    return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type>* newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem; //store the new item in the node
    newNode->link = first; //insert newNode before first
    first = newNode; //make first point to the actual first node
    count++; //increment count
    if (last == NULL) //if the list was empty, newNode is also
    //the last node in the list
        last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type>* newNode; //pointer to create the new node
    newNode = new nodeType<Type>; //create the new node
    newNode->info = newItem; //store the new item in the node
    newNode->link = NULL; //set the link field of newNode to NULL
    if (first == NULL) //if the list is empty, newNode is
    //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++; //increment count
    }
    else //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual
        //last node in the list
        count++; //increment count
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current; //pointer to traverse the list
    nodeType<Type>* trailCurrent; //pointer just before current
    bool found;
    if (first == NULL) //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
        << endl;
    else
    {
        if (first->info == deleteItem) //Case 2
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL) //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first; //set trailCurrent to point
            //to the first node
            current = first->link; //set current to point to
            //the second node
            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }//end while
            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;
                if (last == current) //node to be deleted was the
                //last node
                    last = trailCurrent; //update the value of last
                delete current; //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                << "the list." << endl;
        }//end else
    }//end else
}