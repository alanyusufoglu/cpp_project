#include<iostream>


template<typename T>
class DoublyLinkList

{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;

		Node(const T& value);

	};
	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;

public:



	void push_front(const T& value);
	void push_back(const T& value);
	void print_forward()const;
	void print_backward()const;
	void pop_front();
	void pop_back();
	void clear();
	bool is_empty()const;
	void reverse();

	T& front();
	T& back();


	~DoublyLinkList();

};


template<typename T>
DoublyLinkList<T>::Node::Node(const T& value) :data(value), next(nullptr), prev(nullptr) {}


template<typename T>
void DoublyLinkList<T>::push_front(const T& value)
{
	Node* newNode = new Node(value);


	if (!head)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		newNode->prev = nullptr;
		head->prev = newNode;
		head = newNode;
	}
	++size;


}

template<typename T>
void DoublyLinkList<T>::push_back(const T& value)
{
	Node* newNode1 = new Node(value);


	if (!tail)
	{
		tail = head = newNode1;
	}
	else;
	{
		tail->next = newNode1;
		newNode1->prev = tail;
		tail = newNode1;

	}
	++size;



}
template<typename T>
void DoublyLinkList<T>::print_forward()const
{
	Node* current = head;

	if (!current)
	{
		std::cout << "Liste bos!!!!";
		return;
	}
	std::cout << "liste:";
	while (current)
	{
		std::cout << current->data << " ";
		current = current->next;
	}


}


template<typename T>
void DoublyLinkList<T>::print_backward()const
{
	Node* current1 = tail;

	if (!current1)
	{
		std::cout << "liste bos!!!!";
		return;

	}

	std::cout << "liste(ters):";
	while (current1)
	{

		std::cout << current1->data << " ";
		current1 = current1->prev;


	}




}

template<typename T>
void DoublyLinkList<T>::pop_front()
{

	if (!head)
	{
		std::cout << "liste bos!!";
		return;

	}

	Node* temp = head;
	head = head->next;

	if (head)
	{
		head->prev = nullptr;
	}
	else
	{
		tail = nullptr;
	}


	delete temp;
	--size;



}

template<typename T>
void DoublyLinkList<T>::pop_back()
{
	if (!tail)
	{
		std::cout << "liste bos!!";
	}
	Node* temp1 = tail;
	tail = tail->prev;

	if (tail)
	{
		tail->next = nullptr;

	}
	else
	{
		head = nullptr;
	}
	delete temp1;
	--size;

}
template<typename T>
DoublyLinkList<T>::~DoublyLinkList()
{
	Node* current = head;
	while (current)
	{
		Node* Nextnode = current->next;
		delete current;

		current = Nextnode;
	}

	head = nullptr;
	tail = nullptr;
	size = 0;

}


template<typename T>
void DoublyLinkList<T>::clear() {
	while (head) {
		pop_front();
	}
}


template<typename T>
bool DoublyLinkList<T>::is_empty() const {
	return size == 0;
}


template<typename T>
T& DoublyLinkList<T>::front() {
	if (head) {
		return head->data;
	}
	throw std::out_of_range("Liste boþ");
}

template<typename T>
T& DoublyLinkList<T>::back() {
	if (tail) {
		return tail->data;
	}
	throw std::out_of_range("Liste boþ");
}


template<typename T>
void DoublyLinkList<T>::reverse() {
	Node* current = head;
	Node* temp = nullptr;

	while (current) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp) {
		head = temp->prev;
	}
}




int main()
{

	DoublyLinkList<int> list;

	list.push_back(10);      // Liste: 10
	list.push_front(5);      // Liste: 5 10
	list.push_back(23);      // Liste: 5 10 20

	std::cout << "Listeyi ileri yönlü yazdir:\n";
	list.print_forward();    // Beklenen Çýktý: Liste (ileri): 5 10 20

	std::cout << "Listeyi ters yönlü yazdir:\n";
	list.print_backward();   // Beklenen Çýktý: Liste (ters): 20 10 5

	// Baþtan ve sondan eleman silme
	list.pop_front();        // Liste: 10 20
	std::cout << "Baþtan eleman silindi. Yeni liste:\n";
	list.print_forward();    // Beklenen Çýktý: Liste (ileri): 10 20

	list.pop_back();         // Liste: 10
	std::cout << "Sondan eleman silindi. Yeni liste:\n";
	list.print_forward();    // Beklenen Çýktý: Liste
	std::cin.get();


};