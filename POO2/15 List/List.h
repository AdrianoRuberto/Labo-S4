//
// Created by Nykros on 07.04.2016.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdexcept>

using namespace std;

template<typename T>
class List {

private:
	class Element {
		friend ostream& operator<<(ostream& os, const Element& e) {
			return os << e.data;
		}
	private:
		T data;

	public:
		Element(T data, Element* next = nullptr, Element* before = nullptr) : next(next), before(before), data(data) {
		}

		Element* next;
		Element* before;
	};

	Element* head = nullptr;
	Element* tail = nullptr;

public:
	class Iterator {
	private:
		Element* curr;
	public:
		Iterator(Element* elem){
			curr = elem;
		}
		Iterator& operator++() { // prefix ++
			curr = curr->next;
			return *this;
		}

		Iterator operator++(int) { //suffix ++
			Iterator tmp = *this;
			curr = curr->next;
			return tmp;
		}

		Iterator& operator--() { // prefix --
			curr = curr->before;
			return *this;
		}

		Iterator operator--(int) { // suffix --
			Iterator tmp = *this;
			curr = curr->before;
			return tmp;
		}

		Element& operator*() {
			return *curr;
		}

		bool operator==(const Iterator& it) const {
			return curr == it.curr;
		}

		bool operator!=(const Iterator& it) const {
			return !(*this == it);
		}


	};

public:
	List<T>() { }

	List<T>(const List<T>& other) {

	}

	List<T>& operator=(const List<T>& other) {
		if (this != &other) {
			clear();

			for (Iterator it = other.begin(); it != end(); ++it) // Copie les éléments
				insert(*it);
		}
		return *this;
	}

	Element* operator[](const size_t index) {
		if (index < 0 || index >= size()) throw out_of_range("index is out of bounds : " + index);

		size_t i = index;
		Iterator it = begin();
		while (i-- > 0)
			++it;

		return &*it;
	}

	size_t size() const {
		size_t s = 0;
		for (Iterator it = begin(); it != end(); ++s, ++it);
		return s;
	}

	void insert(T o) {
		if (head == nullptr) {
			head = tail = new Element(o);
		} else {
			head = new Element(o, head);
			head->next->before = head;
		}
	}

	void append(T o) {
		if (head == nullptr) {
			head = tail = new Element(o);
		} else {
			tail = new Element(o, nullptr, tail);
			tail->before->next = tail;
		}
	}

	void remove(const size_t index) {
		Element* curr = (*this)[index];
		if (curr->before) curr->before->next = curr->next;
		if (curr->next) curr->next->before = curr->before;

		if (curr == head) head = curr->next;
		if (curr == tail) tail = curr->before;
		delete curr;
	}

	void remove(T o) {

	}

	Iterator begin() const {
		return Iterator(head);
	}

	Iterator end() const {
		return Iterator(tail->next);
	}

	Iterator find(T o) const {

	}

	~List() {
		clear();
	}

private:
	void clear() {
		while (head != nullptr) remove(0);
	}

};

#endif //LIST_LIST_H