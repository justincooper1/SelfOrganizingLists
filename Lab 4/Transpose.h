#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

template <class E>
class Transpose : public SelfOrderedListADT<E> {
private:
	Transpose(const Transpose&) {}
	LList<E> list;
	int compares;

public:
	// Constructor and destructor
	Transpose() : compares(0) {}
	~Transpose() {}

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
			list.setNumAccessed(0);
			return true;
		}
		return false;
	}

	void addIt(const E& it) {
		list.append(it);
	}

	// Print the list
	void printlist() const {
		cout << "\nTranspose Heuristic:\n" << "Size of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print();
	}

	// Reorder the list
	void reorder() {
		E frontVal = list.frontValue();
		E endValue = list.tailValue();

		// Stop if current = front value
		if (list.getValue() == frontVal)
		{
			return;
		}

		// Reorder if current = end value
		if (list.getValue() == endValue)
		{
			int endValue = list.getNumAccessed();
			list.prev();
			int prevValue = list.getNumAccessed();
			E temp = list.remove();
			list.setNumAccessed(prevValue);
			list.moveToEnd();
			list.insert(temp);
			list.setNumAccessed(prevValue);
			list.prev();
			list.setNumAccessed(endValue);
			return;
		}

		int toSwap = list.getNumAccessed();
		list.prev();
		int prev = list.getNumAccessed();
		list.next();
		int curr = list.getNumAccessed();
		list.next();
		int next = list.getNumAccessed();
		list.prev();
		E temp = list.remove();
		list.setNumAccessed(next);
		list.prev();
		prev = list.getNumAccessed();
		list.insert(temp);
		list.setNumAccessed(toSwap);
		list.next();
		list.setNumAccessed(prev);
	}

	// Print n times
	void printlist(int n) const {
		cout << "\nTranspose Heuristic:\n" << "Size of List: " << size();
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