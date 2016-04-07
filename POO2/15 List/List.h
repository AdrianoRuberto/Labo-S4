//
// Created by Nykros on 07.04.2016.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

template<typename T>
class List {

private:

	class Element {
		Element* next;
		Element* before;
		T data;

		Element(T data, Element* next = nullptr, Element* before = nullptr) : next(next), before(before), data(data) {

		}
	};

	Element* head;
	Element* tail;

public:
	class Iterator {

	};

public:
	List<T>() {
		head = tail = nullptr;
	}

	List<T>(const List<T>& other) {

	}

	List<T>& operator=(const List<T>& other) {

		return *this;
	}

	Element* operator[](int i) {

	}

	size_t size() const {

	}

	void insert(T o) {

	}

	void append(T o) {

	}

	Iterator begin() {

	}

	Iterator end() {

	}

	Iterator find(T o) const {

	}

	~List() {

	}

};

#endif //LIST_LIST_H