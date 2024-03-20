#pragma once
#include<iostream>
using namespace std;
void F1();

template<class T>
void F2(const T& x);

template
void F2<int>(const int& x);