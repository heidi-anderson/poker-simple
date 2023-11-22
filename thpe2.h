#pragma once
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

const int TERMS=10;
const double PI = atan(1.0) * 4;
const double ERRORVALUE = 0.000000000001;
const int ITERATIONMAX = 5000;
const double ERRORTOLERANCE = 0.000001;

int minLocation(double *array, int size);
double minValue(double *array, int size);
double maxValue(double *array, int size);
int maxLocation(double *array, int size);
double sumArray(double *array, int size);
double averageArray(double*array, int size);
void copyArray(double *dest, double *source, int size);
void initialArray( double *array, int size, double value);
void mySort( double *array, int size, string ASCString );
int linearSearch( double *array, int size, double item);
int binarySearch( double *array, int size, double item);
int countIf(double *array, int size, double item);
double mySqrt( double x );
double myCbrt( double x );
double myFactorial(double n);
double mySin (double angleRad);
double mySinD(double angleDeg);
double myCos (double angleRad);
double myCosD(double angleDeg);
double myTan(double rad);
double myTanD(double angleDeg);
double myLog( double x, int base );