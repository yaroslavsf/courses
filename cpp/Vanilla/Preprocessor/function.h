#pragma once
#include "function.cpp"
#include "prog.cpp"
template <typename T>
T action(T*& a, T n);
#ifdef INTEGER
void IntArrayFill(int*& a, int n);
void IntArrayPrint(const int a[], int n);
void IntSearchMin(const int a[], int n);
void IntSearchMax(const int a[], int n);
void IntArraySort(int*& a, int n);
void IntArrayEdit(int*& a, int n);
#endif

#ifdef FLOAT
void FloatArrayFill(float*& a, int n);
void FloatArrayPrint(const float a[], int n);
void FloatSearchMin(const float a[], int n);
void FloatSearchMax(const float a[], int n);
void FloatArraySort(float*& a, int n);
void FloatArrayEdit(float*& a, int n);
#endif

#ifdef CHAR
void CharArrayFill(char*& a, int n);
void CharArrayPrint(const char a[], int n);
void CharSearchMin(const char a[], int n);
void CharSearchMax(const char a[], int n);
void CharArraySort(char*& a, int n);
void CharArrayEdit(char*& a, int n);
#endif
