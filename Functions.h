#pragma once
#include <iostream>
#include<forward_list>
#include <vector>
using namespace std;

template <typename T>
class CSingleLinkedList
{
private:
    forward_list<T> list;
    int size;
public:
    CSingleLinkedList();
    CSingleLinkedList(vector<T> a);
    CSingleLinkedList(CSingleLinkedList& a);
    CSingleLinkedList(CSingleLinkedList&& a) noexcept;
    ~CSingleLinkedList();
    void show();
    T getFirstEl();
    T getLastEl();
    double getNumOfEl();
    T findMax();
    T findMin();
    void bubbleSort();
    void choiceSort();
    void skalyar(double a);
    T operator[](int index);
    CSingleLinkedList& operator=(CSingleLinkedList<T>& b);
    bool operator==(CSingleLinkedList<T>& a);
    bool operator!=(const T& a);
    bool operator!=(const CSingleLinkedList<T>& a) const;
    CSingleLinkedList& operator=(CSingleLinkedList&& b) noexcept;
    //   CSingleLinkedList operator - ();
    CSingleLinkedList operator+(T b);
    CSingleLinkedList operator+(CSingleLinkedList& a);
    CSingleLinkedList operator-(CSingleLinkedList& a);
    CSingleLinkedList* getArray(int num);
    vector<T> getVector();
    CSingleLinkedList reverseList();
    forward_list<T> getList()
    {
        return list;
    }
    //work
    friend istream& operator >> (istream& in, CSingleLinkedList<T>& a)
    {
        cout << "Enter number of elements" << endl;
        in >> a.size;
        T s;
        a.list.clear();
        vector<T> u;
        auto tmp = a.list.begin();
        cout << "Enter " << a.size << " elements" << endl;
        for (int i = 0; i < a.size; i++)
        {
            in >> s;
        	u.push_back(s);
        }
        a.list.assign(u.begin(), u.end());
        return in;
    }

    //work
    friend ostream& operator << (ostream& out, const CSingleLinkedList<T>& a)
    {
        // if (a.list->empty() == false) {
        for (const auto& element : a.list)
        {
            out << element << " ";
        }

        return out;
    }
};


template <typename T>
int FindElementInArray(T* array, int size, T element);

template <typename T>
bool compare(int a, int b) {
    return a > b;
}