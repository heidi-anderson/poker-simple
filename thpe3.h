#pragma once
#include <random>
#include <sstream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

const int ROYALFLUSH = 9;
const int STRAIGHTFLUSH = 8;
const int FOURKIND = 7;
const int FULLHOUSE = 6;
const int FLUSH = 5;
const int STRAIGHT = 4;
const int THREEKIND = 3;
const int TWOPAIR = 2;
const int TWOKIND = 1;
const int HIGHCARD = 0;


void sortIndex(int cards[52], int length);
void sortFace(int cards[52], int length);
bool fourKind( int cards[52], int length );
bool threeKind( int cards[52], int length );
bool twoKind( int cards[52], int length );
bool straight( int cards[52], int length);
bool flush( int cards[52], int length);
bool royalFlush( int cards[52], int length );
bool twoPair ( int cards[52], int length );
bool fullHouse( int cards[52], int length );
int classifyHand( int cards[52], int length );
string report( int handNames[10], int length );