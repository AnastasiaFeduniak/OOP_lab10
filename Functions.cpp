#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <forward_list>
#include<memory>
#include "Functions.h"
#include <algorithm>
#include <list>

#include "Errors.h"
using namespace std;

template <typename T>
CSingleLinkedList<T>::CSingleLinkedList()
{
		size = 0;
}

template <typename T>
CSingleLinkedList<T>::CSingleLinkedList(vector<T> a)
{
		size = a.size();
		list.assign(a.begin(), a.end());
}

template <typename T>
CSingleLinkedList<T>::CSingleLinkedList(CSingleLinkedList& a)
{
	list = a.getList();
	size = a.size;
}

template <typename T>
CSingleLinkedList<T>::CSingleLinkedList(CSingleLinkedList&& a) noexcept
{
	list = a.getList();
	size = a.size;
	a.list.clear();
	a.size = 0;
}
template <typename T>
void CSingleLinkedList<T>::show()
{
	for (const auto& element : list)
	{
		cout << element << " ";
	}

}
template <typename T>
double CSingleLinkedList<T>::getNumOfEl()
{
	return size;
}

template <typename T>
T CSingleLinkedList<T>::getFirstEl()
{

	if (size != 0) {
		return *(list.begin());
	}
	 return T(); 

}

template <typename T>
T CSingleLinkedList<T>::getLastEl()
{
	if (size != 0) {
		T El;
		for (const auto& tmp : list) {
			El = tmp;
		}
		return El;
	}
	else { return T(); }
}
template <typename T>
CSingleLinkedList<T>::~CSingleLinkedList() {}


template <typename T>
T CSingleLinkedList<T>::findMax()
{
	if (size != 0) {
		return *(max_element(list.begin(), list.end()));
	}
	else { return T(); }
}
template <typename T>
T CSingleLinkedList<T>::findMin()
{
	if (size != 0) {
		return *min_element(list.begin(), list.end());
	}
	else { return T(); }

}
template <typename T>
void CSingleLinkedList<T>::bubbleSort()
{
	if (size > 1)
	{
		list.sort();
	}
}
template <typename T>
void CSingleLinkedList<T>::choiceSort()
{
	if (size > 1)
	{
		list.sort();
		list.reverse();
	}
}
template <typename T>
void CSingleLinkedList<T>::skalyar(double a)
{
	std::transform(list.begin(), list.end(), list.begin(), [a](T& element) {
		return element * a;
		});
}

template <typename T>
T CSingleLinkedList<T>::operator[](int index)
{
		if (index >= 0 && index < size)
		{
			std::size_t currentPosition = 0;
			size_t p = static_cast<size_t>(index);
			T el;
			for (const auto& value : list) {
				if (currentPosition == p) {
					el = value;
					return el;
				}
				currentPosition++;
			}
		}
		return T();
}
template <typename T>
CSingleLinkedList<T>& CSingleLinkedList<T>::operator=(CSingleLinkedList<T>& b)
{
	list.assign(b.list.begin(), b.list.end());
	size = b.size;
	return *this;
}
template <typename T>
bool CSingleLinkedList<T>::operator==(CSingleLinkedList<T>& a)
{
	return equal(list.begin(), list.end(), a.list.begin(), a.list.end());
}

template <typename T>
bool CSingleLinkedList<T>::operator!=(const CSingleLinkedList<T>& a) const
{
	return !equal(list.begin(), list.end(), a.list.begin(), a.list.end());

}

template <typename T>
CSingleLinkedList<T>& CSingleLinkedList<T>::operator=(CSingleLinkedList&& b) noexcept
{
	list.clear();
	size = 0;
	list.assign(b.list.begin(), b.list.end());
	b.list.clear();
	b.size = 0;
	return *this;
}

template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T>::operator+(T b)
{
	size++;
	auto lastElement = list.before_begin();
	for (auto it = list.begin(); it != list.end(); ++it) {
		lastElement = it;
	}
	list.insert_after(lastElement, 6);
	return *this;
}
template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T>::operator+(CSingleLinkedList& a)
{
	std::transform(list.begin(), list.end(), a.list.begin(), list.begin(), [](const T& element1, const T& element2) {
		return element1 + element2;
		});
		return *this;
}

template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T>::operator-(CSingleLinkedList& a)
{
		/*auto begin = a.list.begin();
		for (auto& value : list)
		{
			value -= *begin;
			++begin;
		}*/
	std::transform(list.begin(), list.end(), a.list.begin(), list.begin(), [](const T& element1, const T& element2) {
		return element1 - element2;
		});
		return *this;
}

template <typename T>
CSingleLinkedList<T>* CSingleLinkedList<T>::getArray(int num)
{
	try
	{
		CSingleLinkedList* f = new CSingleLinkedList[num];
		return f;

	}
	catch (const bad_alloc&)
	{
		throw OutOfMemoryException();
	}
}

template <typename T>
int FindElementInArray(T* array, int size, T element)
{
	for (int i = 0; i < size; i++)
		if (array[i] == element) {
			return i;
		}
	return size;
}

template <typename T>
vector<T> CSingleLinkedList<T>::getVector()
{
	vector<T> a;
	a.assign(list.begin(), list.end());
	return a;
}

template <typename T>
CSingleLinkedList<T> CSingleLinkedList<T>::reverseList()
{
	list.reverse();
	return *this;
}