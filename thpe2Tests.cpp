#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "thpe2.h"

TEST_CASE("minLocation - location is 0")
{
    double array[] = {1, 5, 2, 6};
    int size = 4;
    int location;
    
    location = minLocation(array, size);
    REQUIRE(location == 0);
}

TEST_CASE("minLocation - location is 1")
{
    double array[] = {8, 0, 2, 6, 7, 2};
    int size = 6;
    int location;
    
    location = minLocation(array, size);
    REQUIRE(location == 1);
}

TEST_CASE("minLocation - location is 4")
{
    double array[] = {7, 5, 3, 6, 2, 9, 3};
    int size = 7;
    int location;
    
    location = minLocation(array, size);
    REQUIRE(location == 4);
}

TEST_CASE("minValue - min of 1")
{
    double array[] = {1, 5, 2, 6};
    int size = 4;
    double value;
    
    value = minValue(array, size);
    REQUIRE(value == 1);
}

TEST_CASE("minValue - min is 0")
{
    double array[] = {8, 0, 2, 6, 7, 2};
    int size = 6;
    double value;
    
    value = minValue(array, size);
    REQUIRE(value == 0);
}

TEST_CASE("minLocation - min is 2")
{
    double array[] = {7, 5, 3, 6, 2, 9, 3};
    int size = 7;
    double value;
    
    value = minValue(array, size);
    REQUIRE(value == 2);
}

TEST_CASE("maxLocation - test")
{
    double array[] = {1, 5, 2, 6};
    int size = 4;
    int location;
    
    location = maxLocation(array, size);
    REQUIRE(location == 3);
}

TEST_CASE("maxLocation - location is 0")
{
    double array[] = {8, 0, 2, 6, 7, 2};
    int size = 6;
    int location;
    
    location = maxLocation(array, size);
    REQUIRE(location == 0);
}

TEST_CASE("maxLocation - location is 5")
{
    double array[] = {7, 5, 3, 6, 2, 9, 3};
    int size = 7;
    int location;
    
    location = maxLocation(array, size);
    REQUIRE(location == 5);
}

TEST_CASE("maxValue - test")
{
    double array[] = {1, 5, 2, 6};
    int size = 4;
    double value;
    
    value = maxValue(array, size);
    REQUIRE(value == 6);
}

TEST_CASE("maxValue - max is 0")
{
    double array[] = {8, 0, 2, 6, 7, 2};
    int size = 6;
    double value;
    
    value = maxValue(array, size);
    REQUIRE(value == 8);
}

TEST_CASE("maxLocation - max is 2")
{
    double array[] = {7, 5, 3, 6, 2, 9, 3};
    int size = 7;
    double value;
    
    value = maxValue(array, size);
    REQUIRE(value == 9);
}

TEST_CASE("sumArray - sum is 14")
{
    double array[] = {1, 5, 2, 6};
    int size = 4;
    double sum;
    
    sum = sumArray(array, size);
    REQUIRE(sum == 14);
}

TEST_CASE("sumArray - sum is 19")
{
    double array[] = {6, 5, 2, 6, 0};
    int size = 5;
    double sum;
    
    sum = sumArray(array, size);
    REQUIRE(sum == 19);
}

TEST_CASE("sumArray - test")
{
    double array[] = {5, 5, 5, 5, 5, 5};
    int size = 6;
    double sum;
    
    sum = sumArray(array, size);
    REQUIRE(sum == 30);
}

TEST_CASE("averageArray - average is 14/4")
{
    double array[] = {1, 5, 2, 6};
    int size = 4;
    double avg;
    
    avg = averageArray(array, size);
    REQUIRE(avg == 14/4.0);
}

TEST_CASE("averageArray - average is 19/5")
{
    double array[] = {6, 5, 2, 6, 0};
    int size = 5;
    double avg;
    
    avg = averageArray(array, size);
    REQUIRE(avg == 19/5.0);
}

TEST_CASE("averageArray - average is 40/8")
{
    double array[] = {5, 5, 5, 5, 5, 5, 5, 5};
    int size = 8;
    double avg;
    
    avg = averageArray(array, size);
    REQUIRE(avg == 40/8.0);
}

TEST_CASE("copyArray - copying 1, 2, 3")
{
    double dest[3];
    double source[] = {1, 2, 3};
    
    int size = 3;
    
    copyArray(dest, source, size);
    REQUIRE( ((sumArray(dest, size) == sumArray(source, size)) && 
    (averageArray(dest, size) == averageArray(source, size)) ));
}

TEST_CASE("initialArray - initializing to 2")
{
    double value = 2;
    double array[4];
    int size = 4;
    
    initialArray(array, size, value);
    
    REQUIRE(((sumArray(array, size) == 8) && (averageArray(array, size) == 2)));
}

TEST_CASE("mySort - ascending sort")
{
    double array[] = {5, 0, 1, 4, 3, 2};
    
    mySort(array, 6, "ASC");
    
   REQUIRE(array[0] == 0);
   REQUIRE(array[1] == 1);
   REQUIRE(array[2] == 2);
   REQUIRE(array[3] == 3);
   REQUIRE(array[4] == 4);
   REQUIRE(array[5] == 5);
}

TEST_CASE("mySort - descending sort")
{
    double array[] = {5, 0, 1, 4, 3, 2};
    
    mySort(array, 6, "DSC");
    
   REQUIRE(array[0] == 5);
   REQUIRE(array[1] == 4);
   REQUIRE(array[2] == 3);
   REQUIRE(array[3] == 2);
   REQUIRE(array[4] == 1);
   REQUIRE(array[5] == 0);
}

TEST_CASE("linearSearch - item is 1")
{
    int ans;
    double array[] = {6, 2, 8, 1, 9};
    
    ans = linearSearch(array, 5, 1);
    
    REQUIRE(ans == 3);
}

TEST_CASE("linearSearch - item is not found")
{
    int ans;
    double array[] = {4, 6, 8, 2, 9};
    
    ans = linearSearch(array, 5, 0);
    
    REQUIRE(ans == -1);
}

TEST_CASE("binarySearch - item is 1")
{
    int ans;
    double array[] = {6, 2, 8, 1, 9};
    
    ans = binarySearch(array, 5, 1);
    
    REQUIRE(ans == 0);
}

TEST_CASE("binarySearch - item is not found")
{
    int ans;
    double array[] = {4, 6, 8, 2, 9};
    
    ans = binarySearch(array, 5, 0);
    
    REQUIRE(ans == -1);
}

TEST_CASE("countIf - counting 3, 4 times")
{
    double array[] = {4, 3, 7, 3, 1, 6, 3, 3};
    int ans;
    
    ans = countIf(array, 8, 3);
    REQUIRE( ans == 4 );
}

TEST_CASE("countIf - counting 2, 0 times")
{
    double array[] = {4, 3, 7, 3, 1, 6, 3, 3};
    int ans;
    
    ans = countIf(array, 8, 2);
    REQUIRE( ans == 0 );
}

TEST_CASE("mySqrt - sqrt of 25.0")
{
    double ans;
    
    ans = mySqrt(25.0);
    
    REQUIRE(ans == Approx(5.0));
}

TEST_CASE("mySqrt - sqrt of 1.0")
{
    double ans;
    
    ans = mySqrt(1.0);
    
    REQUIRE(ans == Approx(1.0));
}

TEST_CASE("mySqrt - sqrt of 46.0")
{
    double ans;
    
    ans = mySqrt(46.0);
    
    REQUIRE(ans == Approx(6.7823299831));
}

TEST_CASE("myCbrt - cbrt of 27.0")
{
    double ans;
    
    ans = myCbrt(27.0);
    
    REQUIRE(ans == Approx(3.0));
}

TEST_CASE("myCbrt - cbrt of 216.0")
{
    double ans;
    
    ans = myCbrt(216.0);
    
    REQUIRE(ans == Approx(6.0));
}

TEST_CASE("myCbrt - cbrt of 99.0")
{
    double ans;
    
    ans = myCbrt(99.0);
    
    REQUIRE(ans == Approx(4.62606500918));
}

TEST_CASE("myFactorial - factorial of 5")
{
    double n = 5;
    double ans;
    
    ans = myFactorial(n);
    
    REQUIRE(ans == 120);
}
   
TEST_CASE("mySin - sin of 0")
{
    double deg = 0;
    double ans;

    ans = mySin(deg);

    REQUIRE(ans == Approx(0));
}

TEST_CASE("mySin - sin of 1.5708")
{
    double deg = 1.5708;
    double ans;

    ans = mySin(deg);

    REQUIRE(ans == Approx(1.0));
}
 
TEST_CASE("mySin - sin of 0.785398")
{
    double deg = 0.785398;
    double ans;

    ans = mySin(deg);

    REQUIRE(ans == Approx(0.707107));
}
 
TEST_CASE("mySinD - sin of 0")
{
    double deg = 0;
    double ans;

    ans = mySinD(deg);

    REQUIRE(ans == Approx(0));
}
 
TEST_CASE("mySinD - sin of 90")
{
    double deg = 90;
    double ans;

    ans = mySinD(deg);

    REQUIRE(ans == Approx(1.0));
}
 
TEST_CASE("mySinD - sin of 45")
{
    double deg = 45;
    double ans;

    ans = mySinD(deg);

    REQUIRE(ans == Approx(0.707107));
}
 
TEST_CASE("myCos - Cos of 0")
{
    double deg = 0;
    double ans;

    ans = myCos(deg);

    REQUIRE(ans == Approx(0));
}
 
TEST_CASE("myCos - Cos of 1.5708")
{
    double deg = 1.5708;
    double ans;

    ans = myCos(deg);

    REQUIRE(ans == Approx(1.0));
}

TEST_CASE("myCos - Cos of 0.785398")
{
    double deg = 0.785398;
    double ans;

    ans = myCos(deg);

    REQUIRE(ans == Approx(0.707107));
}

TEST_CASE("myCosD - Cos of 0")
{
    double deg = 0;
    double ans;

    ans = myCosD(deg);

    REQUIRE(ans == Approx(0));
}

TEST_CASE("myCosD - Cos of 90")
{
    double deg = 90;
    double ans;

    ans = myCosD(deg);

    REQUIRE(ans == Approx(1.0));
}

TEST_CASE("myCosD - Cos of 45")
{
    double deg = 45;
    double ans;

    ans = myCosD(deg);

    REQUIRE(ans == Approx(0.707107));
}

TEST_CASE("myTan - tan 0")
{
    double deg = 0;
    double ans;
     
    ans = myTan(deg);
     
    REQUIRE(ans == Approx(0));
}

TEST_CASE("myTan - tan 0.785398")
{
    double deg = 0.785398;
    double ans;
     
    ans = myTan(deg);
     
    REQUIRE(ans == Approx(0));
}

TEST_CASE("myTanD - tan of 0")
{
    double deg = 0;
    double ans;
     
    ans = myTanD(deg);
     
    REQUIRE(ans == Approx(0));
}

TEST_CASE("myTanD - tan 90")
{
    double deg = 90;
    double ans;
     
    ans = myTan(deg);
     
    REQUIRE(ans == Approx(0));
}

TEST_CASE("myLog - x is 64 base is 8")
{
    double x = 64;
    int base = 8;
    double ans;

    ans = myLog(x, base);

    REQUIRE(ans == Approx(2.0));
}

TEST_CASE("myLog - x is 16 base is 8")
{
    double x = 16;
    int base = 8;
    double ans;

    ans = myLog(x, base);

    REQUIRE(ans == Approx(1.333333));
}

TEST_CASE("myLog - x is 1024 base is 2")
{
    double x = 1024;
    int base = 2;
    double ans;

    ans = myLog(x, base);

    REQUIRE(ans == Approx(10.0));
} 

TEST_CASE("myLog - x is 8 base is 10")
{
    double x = 8;
    int base = 10;
    double ans;

    ans = myLog(x, base);

    REQUIRE(ans == Approx(0.903089));
}