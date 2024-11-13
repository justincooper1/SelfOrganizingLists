#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

template <class E>
class MoveToFront : public SelfOrderedListADT<E> {
private:
	MoveToFront(const MoveToFront&) {}
	LList<E> list;
	int compares;

public:
	// Constructor and destructor
	MoveToFront() : compares(0) {};
	~MoveToFront() {};


	// Find element in the list
	bool search(const E& it) {
		int found = 0;
		list.moveToStart();

		for (int i = 0; i < list.length(); i++)
		{
			compares++;

			if (list.getValue() == it)
			{
				found = 1;
				break;
			}
			list.next();
		}

		if (found == 1)
		{
			int temp = list.getNumAccessed();
			list.setNumAccessed(temp + 1);
			reorder();
			return true;
		}
		else
		{
			list.moveToEnd();
			list.insert(it);
			return true;
		}

		return false;
	}

	// Add to list
	void addIt(const E& it) {
		list.append(it);
	}

	//Reorders the elements MTF
	void reorder() {
		int toSwap = list.getNumAccessed();
		list.next();
		int next = list.getNumAccessed();
		list.prev();
		E temp = list.remove();
		list.setNumAccessed(next);
		list.moveToStart();
		int front = list.getNumAccessed();
		list.insert(temp);
		list.setNumAccessed(toSwap);
		list.next();
		list.setNumAccessed(front);
	}

	// Print
	void printlist() const {
		cout << "\nMove-To-Front Heuristic:" << "\nSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print();
	}

	// Print n times
	void printlist(int n) const {
		cout << "\nMove-To-Front Heuristic: " << "\nSize of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print(n);
	}

	int getCompares() const {
		return compares;
	}

	int size() const {
		return list.length();
	}
};