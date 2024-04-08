#pragma once
template<typename T>
bool compare(T a, T b);//一个模板函数
template<>
bool compare<const char*>(const char* a, const char* b);