#include <iostream>

template <class T>
class ListElement
{
	public:
		ListElement(T value): next(NULL), data(value){}
		~ListElement() { }

		ListElement *getNext() const {return next;}
		T value() const { return data; }
		void setNext(ListElement *element) { next = element; }
		void setValue(T value) { data = value; } 
                
		private:
		T data;
		ListElement *next;
};

template <class T>
void insertInFront(ListElement<T> *&head, T data)
{
	ListElement<T>* newElement = new ListElement<T>(data);
	newElement->setNext(head);

	head = newElement;
}


template <class T>
ListElement<T>* find(ListElement<T> *head, T data)
{
	ListElement<T>* element = head;
	while(element != NULL && element->value() != data)
		element = element->getNext();
	return element;
}

template <class T>
void printList(ListElement<T> *head)
{
	while(head != NULL){
		std::cout << head->value() << std::endl;
		head = head->getNext();
	}
}

template <class T>
void deleteList(ListElement<T> **head)
{
	ListElement<T>* element = *head;
	while(element){
		ListElement<T> *next = element->getNext();
		delete element; 
		element = next;
	}

	*head = NULL;
}

int main (int argc, char *argv[])
{
	ListElement<int>* head = NULL;

	//insert 5 elements
	for (int i = 1; i <= 5; i++)
	{
		insertInFront(head, i); 
	}
	printList(head);
        deleteList(&head);	

	return 0;
}	
