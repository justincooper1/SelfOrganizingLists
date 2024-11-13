#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"

using namespace std;

template <class E>
class Count : public SelfOrderedListADT<E> {
private:
    Count(const Count&) {}
    LList<E> list;
    int compares;

public:
    // Constructor/Destructor
    Count() : compares(0) {}
    ~Count() {}

    bool search(const E& it) override {
        bool found = false;
        list.moveToStart();

        for (int i = 0; i < list.length(); i++) {
            compares++;  // Increment compares for each comparison
            if (list.getValue() == it) {
                found = true;
                break;
            }
            list.next();
        }

        if (found) {
            int tmp = list.getNumAccessed();
            list.setNumAccessed(tmp + 1);
            reorder();
        } else {
            list.moveToEnd();
            list.insert(it);
            list.setNumAccessed(0);
        }

        return found;
    }

    void addIt(const E& it) override {
        list.append(it);
    }

    int getCompares() const override {
        return compares;
    }

    int size() const override {
        return list.length();
    }

    void printlist() const override {
        cout << "Count Heuristic: " << "\nSize of List: " << size();
        cout << "\nNumber of Compares: " << getCompares();
        list.print();
        cout << endl;
    }

    void printlist(int n) const override {
        cout << "\n\nCount Heuristic: " << "\nSize of List: " << size();
        cout << "\nNumber of Compares: " << getCompares();
        list.print(n);
    }

    void reorder() {
        int swap = list.getNumAccessed();
        list.prev();
        int prev = list.getNumAccessed();

        while (swap > prev) {
            list.next();
            E tmp = list.remove();
            list.setNumAccessed(prev);
            list.prev();
            list.insert(tmp);
            list.setNumAccessed(swap);
            list.next();
            list.setNumAccessed(prev);
            list.prev();
            list.prev();
            prev = list.getNumAccessed();
        }
    }
};