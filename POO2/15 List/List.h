//
// Created by Nykros on 07.04.2016.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdexcept>

using namespace std;

template<typename T>
class List {
	friend ostream& operator<<(ostream& os, const List<T>& list) {
		for (Iterator it = list.begin(); it != list.end(); ++it)
			os << *it << ' ';
		return os;
	}

private:
	class Node {
	public:
		Node(const T& data, Node* next = nullptr, Node* before = nullptr) : next(next), before(before), data(data) { }

		T data;
		Node* next;
		Node* before;
	};

	Node* head = nullptr;
	Node* tail = nullptr;

	size_t _size = 0;

public:
	class Iterator {
	private:
		Node* curr;
	public:
		Iterator(Node* elem) {
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

		T& operator*() {
			return curr->data;
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

	/**
	 * Constructeur de copie
	 */
	List<T>(const List<T>& other) {
		*this = other;
	}

	/**
	 * Surcharge de l'opérateur d'affectation
	 */
	List<T>& operator=(const List<T>& other) {
		if (this != &other) {
			clear();
			this->_size = other._size;
			for (Iterator it = other.begin(); it != end(); ++it)
				append(*it);
		}
		return *this;
	}

	/**
	 * Retourne l'élément à l'indice donné
	 */
	T& operator[](const size_t index) {
		if (!isInRange(index)) throw out_of_range("index is out of bounds : " + index);

		size_t i = index;
		Iterator it = begin();
		while (i-- > 0)
			++it;

		return (*it);
	}

	/**
	 * Retourne la taille de la liste
	 */
	size_t size() const {
		return _size;
	}

	/**
	 * Insère au début de la liste l'objet 'o'
	 */
	void insert(T o) {
		if (head == nullptr) {
			head = tail = new Node(o);
		} else {
			head = new Node(o, head);
			head->next->before = head;
		}
		++_size;
	}

	/**
	 * Ajoute à la fin de la liste l'objet 'o'
	 */
	void append(T o) {
		if (head == nullptr) {
			head = tail = new Node(o);
		} else {
			tail = new Node(o, nullptr, tail);
			tail->before->next = tail;
		}
		++_size;
	}

	/**
	 * Supprime à l'index donné. Commence à 0.
	 */
	void remove(int index) {
		if (!isInRange(index)) throw out_of_range("index is out of bounds : " + index);
		Node* toDel = head;
		while (index-- > 0) // Trouve l'élément sur la bonne valeur
			toDel = toDel->next;

		// Chaînage
		if (toDel->before) toDel->before->next = toDel->next;
		if (toDel->next) toDel->next->before = toDel->before;
		if (toDel == head) head = toDel->next;
		if (toDel == tail) tail = toDel->before;

		delete toDel;
		--_size;
	}

	void remove(T& o) {

	}

	Iterator begin() const {
		return Iterator(head);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}

	Iterator find(T o) const {

	}

	~List() {
		clear();
	}

private:
	/**
	 * vide la liste
	 */
	void clear() {
		while (head != nullptr) remove(0);
	}

	/**
	 * return true si l'index est dans la range
	 */
	bool isInRange(const int index) {
		return index >= 0 && index < _size;

	}

};

#endif //LIST_LIST_H