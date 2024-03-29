/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_15
 Fichier     : List.h
 Auteur(s)   : Adriano Ruberto && Matthieu Villard
 Date        : 20.04.2016
 But         : Cette classe définit une list générique doublement chaînée
 ----------------------------------------------------------------------------------
 */

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <stdexcept>

using namespace std;

template<typename T>
class List {
	friend ostream& operator<<(ostream& os, const List& list) {
		for (Iterator it = list.begin(); it != list.end(); ++it)
			os << *it << ' ';
		return os;
	}

private:
	/**
	 * Représente un noeud dans la liste
	 */
	class Node {
	public:
		Node(const T& data, Node* before = nullptr, Node* next = nullptr) : next(next), before(before), data(data) { }

		Node() : next(nullptr), before(nullptr) { }

		T data;
		Node* next;
		Node* before;
	};

	Node* head = nullptr;
	Node* tail = nullptr;

	size_t _size = 0;

public:
	/**
	 * Représente un itérateur sur la liste
	 */
	class Iterator {
		friend class List;

	private:
		Node* current;
	public:
		Iterator(Node* node) {
			this->current = node;
		}

		Iterator& operator++() { // prefix ++
			current = current->next;
			return *this;
		}

		Iterator operator++(int) { //suffix ++
			Iterator tmp = *this;
			current = current->next;
			return tmp;
		}

		Iterator& operator--() { // prefix --
			current = current->before;
			return *this;
		}

		Iterator operator--(int) { // suffix --
			Iterator tmp = *this;
			current = current->before;
			return tmp;
		}

		T& operator*() {
			return current->data;
		}

		bool operator==(const Iterator& it) const {
			return current == it.current;
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
	List(const List& other) {
		copy(other);
	}

	/**
	 * Surcharge de l'opérateur d'affectation
	 */
	List<T>& operator=(const List<T>& other) {
		if (this != &other) {
			clear();
			copy(other);
		}
		return *this;
	}

	/**
	 * Retourne l'élément à l'indice donné
	 */
	T& operator[](const size_t index) {
		if (!isInRange(index)) throw out_of_range("index is out of range");

		size_t i = index;
		Iterator it = begin();
		while (i-- > 0)
			++it;

		return (*it);
	}

	/**
	 * Retourne la taille de la liste
	 */
	const size_t size() const {
		return _size;
	}

	/**
	 * Insère au début de la liste l'objet 'o'
	 */
	List<T>& insert(T o) {
		if (head == nullptr) {
			head = tail = new Node(o, nullptr, nullptr);
		} else {
			head = new Node(o, nullptr, head);
			head->next->before = head;
		}
		++_size;
		return *this;
	}

	/**
	 * Ajoute à la fin de la liste l'objet 'o'
	 */
	List<T>& append(T o) {
		if (head == nullptr) {
			head = tail = new Node(o, nullptr, nullptr);
		} else {
			tail = new Node(o, tail, nullptr);
			tail->before->next = tail;
		}
		++_size;
		return *this;
	}

	/**
	 * Supprime à l'index donné. Commence à 0.
	 */
	List<T>& remove(int index) {
		if (!isInRange(index)) throw out_of_range("index is out of range");
		Iterator toDel = begin();
		while (index-- > 0) // Trouve l'élément sur la bonne valeur
			++toDel;
		deleteNode(toDel.current);
		--_size;
		return *this;
	}

	/**
	 * Supprime l'élement o s'il existe dans la liste. Sinon ne fait rien.
	 */
	List<T>& remove(T& o) {
		Iterator toDel = find(o);
		if (toDel != end()) {
			deleteNode(toDel.current);
			--_size;
		}

		return *this;
	}

	/**
	 * Retourne un itérateur sur le début de la liste
	 */
	Iterator begin() const {
		return Iterator(head);
	}

	/**
	 * Retourne un itérateur sur l'élément après la fin de la liste.
	 */
	Iterator end() const {
		return Iterator(nullptr);
	}

	/**
	 * Retourne un itérateur sur le premier élément correspondant à 'o'. L'opérateur != doit être définis pour
	 * l'élément en question. Si l'élément ne fait pas parti de la liste, retourne end().
	 */
	Iterator find(const T& o) const {
		Iterator it = begin();
		const Iterator e = end();
		while (it != e && it.current->data != o)
			++it;
		return it;
	}

	virtual ~List() {
		clear();
	}

private:
	/**
	 * vide la liste
	 */
	void clear() { while (head != nullptr) remove(0); }

	/**
	 * return true si l'index est dans la range
	 */
	inline bool isInRange(const int index) const { return index >= 0 && index < _size; }

	/**
	 * Supprime un noeud en chaînant correctement
	 */
	void deleteNode(Node* node) {
		if (node->before) node->before->next = node->next;
		if (node->next) node->next->before = node->before;
		if (node == head) head = node->next;
		if (node == tail) tail = node->before;

		delete node;
	}

	void copy(const List& other) {
		_size = other._size;
		const Iterator e = end();
		for (Iterator it = other.begin(); it != e; ++it)
			append(*it);
	}
};

#endif //LIST_LIST_H