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
	//Constructor and destructor
	Transpose() : compares(0) {}
	~Transpose() {}

	//Find element in the list
	bool search(const E& it) {
		int found = 0;
		list.moveToStart();

		//Loop to determine whether there are duplicates in the list
		for (int i = 0; i < list.length(); i++)
		{
			compares++;

			//If there is a duplicate
			if (list.getValue() == it)
			{
				found = 1;
				break;
			}
			list.next();
		}

		//If there is a duplicate
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

	//Append
	void addIt(const E& it) {
		list.append(it);
	}

	//print the list
	void printlist() const {
		cout << "\nTranspose Heuristic:\n" << "Size of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print();
	}

	//Reorder elements
	void reorder() {
		E frontVal = list.frontValue();
		E endValue = list.tailValue();

		//If the current value matches the front value then stop the function
		if (list.getValue() == frontVal)
		{
			return;
		}

		//If the current value matches the value at the end of the list
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

	//Print number of times
	void printlist(int n) const {
		cout << "\nTranspose Heuristic:\n" << "Size of List: " << size();
		cout << "\nNumber of Compares: " << getCompares();
		list.print(n);
	}

	//return number of compares
	int getCompares() const {
		return compares;
	}

	//return size
	int size() const {
		return list.length();
	}
};