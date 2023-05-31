#include<iostream>
#include "Functions.cpp"
#include <vector>
#include <forward_list>
#include <map>
#include <stack>
#include <unordered_map>
//#include "CSphere.h"
using namespace std;
int main(void)
{
    map<int, string> a;
    a.insert({ 1, "Apple" });
    a.insert({ 2, "Banana" });
    a.insert({ 1, "Orange" });

    for (const auto& tmp: a) {
        cout << "Key: " << tmp.first << ", Value: " << tmp.second << endl;
    }
    for (int i = 1; i <= 3; i++) {
        auto search = a.find(i);
        if (search != a.end()) {
            cout << "true : value" << search->second << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
    a.erase(1);
    for (const auto& tmp : a) {
        cout << "Key: " << tmp.first << ", Value: " << tmp.second << endl;
    }
    a.erase(3);
    for (const auto& tmp : a) {
        cout << "Key: " << tmp.first << ", Value: " << tmp.second << endl;
    }

    stack<int> b;
    b.push(10);
    b.push(20);
    b.push(30);

    while (!b.empty()) {
        cout << "Top element: " << b.top() << endl;
        b.pop();
    }


    unordered_map<int, string> c;

    c.insert({ 2, "Apple" });
    c.insert({ 1, "Banana" });
    c.insert({ 1, "Orange" });

    for (const auto& tmp : c) {
        cout << "Key: " << tmp.first << ", Value: " << tmp.second << endl;
    }
    auto search = c.find(2);
    if (search != c.end()) {
        cout << "true. Value: " << search->second << endl;
    }
    else {
        cout << "false" << endl;
    }

    c.erase(1);
    for (const auto& tmp : c) {
        cout << "Key: " << tmp.first << ", Value: " << tmp.second << endl;
    }

}