/** **********************************************************************
 * @file thpe2
 ************************************************************************/
#include "thpe2.h"
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return the location/index
 *  of the smallest element in the array
 *  if two elements have the same value, it will
 *  return the smaller of the location.
 *
 *  @param[dbl] array
 *  @param[int] size of array
 *              
 *
 *  @returns smallest element location in array
 *
 *  @par Example
 *  @verbatim

    double array[] = {1, 5, 2, 6};
    int size = 4;
    int location;
    
    location = minLocation(array, size);
    REQUIRE(location == 0);

    @endverbatim
 ************************************************************************/
int minLocation(double *array, int size)
{
    int i = 0;
    double min = array[0];
    int location = 0;
    
    for(i = 0; i < size; ++i)
    {
        if(min > array[i])
        {
            min = array[i];
            location = i;
        }
    }
    return location;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return the smallest value
 *  in the array.
 *
 *  @param[dbl] array
 *  @param[int] size of array
 *              
 *
 *  @returns smallest value in array
 *
 *  @par Example
 *  @verbatim

    double array[] = {8, 0, 2, 6, 7, 2};
    int size = 6;
    double value;
    
    value = minValue(array, size);
    REQUIRE(value == 0);

    @endverbatim
 ************************************************************************/
double minValue(double *array, int size)
{
    return array[minLocation(array, size)];
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return the location/index
 *  of the largest element in the array
 *  if two elements have the same value, it will
 *  return the smaller of the location.
 *
 *  @param[dbl] array
 *  @param[int] size of array
 *              
 *
 *  @returns largest element location in array
 *
 *  @par Example
 *  @verbatim

    double array[] = {8, 0, 2, 6, 7, 2};
    int size = 6;
    int location;
    
    location = maxLocation(array, size);
    REQUIRE(location == 0);

    @endverbatim
 ************************************************************************/
int maxLocation(double *array, int size)
{
    int i = 0;
    double max = array[0];
    int location = 0;
    
    for(i = 0; i < size; ++i)
    {
        if(max < array[i])
        {
            max = array[i];
            location = i;
        }
    }
    return location;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return the largest value
 *  in the array.
 *
 *  @param[dbl] array
 *  @param[int] size of array
 *              
 *
 *  @returns largest value in array
 *
 *  @par Example
 *  @verbatim

    double array[] = {8, 0, 2, 6, 7, 2};
    int size = 6;
    double value;
    
    value = maxValue(array, size);
    REQUIRE(value == 8);

    @endverbatim
 ************************************************************************/
double maxValue(double *array, int size)
{
    return array[maxLocation(array, size)];
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will determines the sum of all the
 *  elements in the array
 *
 *  @param[dbl] array
 *  @param[int] size of array
 *              
 *
 *  @returns sum of array
 *
 *  @par Example
 *  @verbatim

    double array[] = {8, 0, 2, 6, 7, 2};
    double array[] = {6, 5, 2, 6, 0};
    int size = 5;
    double sum;
    
    sum = sumArray(array, size);
    REQUIRE(sum == 19);

    @endverbatim
 ************************************************************************/
double sumArray(double *array, int size)
{
    double sum = 0;
    int i;
    
    for(i = 0; i < size; ++i)
    {
        sum += array[i];
    }
    
    return sum;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will determines the average of all the
 *  elements in the array
 *
 *  @param[dbl] array
 *  @param[int] size of array
 *              
 *
 *  @returns average of array
 *
 *  @par Example
 *  @verbatim

    double array[] = {1, 5, 2, 6};
    int size = 4;
    double avg;
    
    avg = averageArray(array, size);
    REQUIRE(avg == 14/4.0);

    @endverbatim
 ************************************************************************/
double averageArray(double*array, int size)
{
    return sumArray(array, size) / size;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will make an exact duplicate array
 *  in destination based on the values in the source array.
 *
 *  @param[dbl] dest
 *  @param[dbl] source
 *  @param[int] size of array
 *              
 *
 *  @returns nothing, voided function
 *
 *  @par Example
 *  @verbatim

    double dest[3];
    double source[] = {1, 2, 3};
    
    int size = 3;
    
    copyArray(dest, source, size);
    REQUIRE( ((sumArray(dest, size) == sumArray(source, size)) && 
    (averageArray(dest, size) == averageArray(source, size)) ));

    @endverbatim
 ************************************************************************/
void copyArray(double *dest, double *source, int size)
{
    int i;
    
    for(i = 0; i < size; ++i)
    {
        dest[i] = source[i];
    }
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will initialize every element in the array
 *  to the provided value
 *
 *  @param[dbl] array
 *  @param[dbl] value
 *  @param[int] size of array
 *              
 *
 *  @returns nothing, voided function
 *
 *  @par Example
 *  @verbatim

    double value = 2;
    double array[4];
    int size = 4;
    
    initialArray(array, size, value);
    
    REQUIRE(((sumArray(array, size) == 8) && (averageArray(array, size) == 2)));

    @endverbatim
 ************************************************************************/
void initialArray( double *array, int size, double value)
{
    int i;
    
    for(i = 0; i < size; ++i)
    {
        array[i] = value;
    }
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will initialize every element in the array
 *  to the provided value
 *
 *  @param[dbl] array
 *  @param[str] ASCString
 *  @param[int] size of array
 *              
 *
 *  @returns nothing, voided function
 *
 *  @par Example
 *  @verbatim

    double array[] = {5, 0, 1, 4, 3, 2};

    mySort(array, 6, "ASC");

    REQUIRE(array[0] == 0);
    REQUIRE(array[1] == 1);
    REQUIRE(array[2] == 2);
    REQUIRE(array[3] == 3);
    REQUIRE(array[4] == 4);
    REQUIRE(array[5] == 5);

    @endverbatim
 ************************************************************************/
void mySort( double *array, int size, string ASCString )
{
    int i;
    bool ASC = ASCString == "ASC";
    bool flag = true;
    double temp;
    
    
    if((ASCString != "ASC") && (ASCString != "DSC"))
    {
        return;
    }
    
    while(flag == true)
    {
        flag = false;
        
        for(i = 1; i < size; ++i)
        {
            if((array[i] < array[i - 1] && ASC) || (array[i] > array[i - 1] && !ASC))
            {
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                
                flag = true;
            }
        }
    }
 
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will do linear search to find item in array
 *
 *  @param[dbl] array
 *  @param[dbl] item
 *  @param[int] size of array
 *              
 *
 *  @returns location that the item was found or -1 if item was not found
 *
 *  @par Example
 *  @verbatim

    int ans;
    double array[] = {6, 2, 8, 1, 9};
    
    ans = linearSearch(array, 5, 1);
    
    REQUIRE(ans == 3);

    @endverbatim
 ************************************************************************/
int linearSearch( double *array, int size, double item)
{
    int i;
    
    for(i = 0; i < size; ++i)
    {
        if(array[i] == item)
        {
            return i;
        }
    }
    
    return -1;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will do binary search to find item in array
 *
 *  @param[dbl] array
 *  @param[dbl] item
 *  @param[int] size of array
 *              
 *
 *  @returns location that the item was found or -1 if item was not found
 *
 *  @par Example
 *  @verbatim

    int ans;
    double array[] = {4, 6, 8, 2, 9};
    
    ans = binarySearch(array, 5, 0);
    
    REQUIRE(ans == -1);

    @endverbatim
 ************************************************************************/
int binarySearch( double *array, int size, double item)
{ 
    int low = 0;
    int high = size - 1;
    int mid;
    
    mySort(array, size, "ASC");
    
    while(high >= low)
    {
        mid = (high + low) / 2;
        
        if(array[mid] == item)
        {
            return mid;
        }
        else
        {
            if(array[mid] < item)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return the numberof times an item was found
 *
 *  @param[dbl] array
 *  @param[dbl] item
 *  @param[int] size of array
 *              
 *
 *  @returns number of elements that match the requested item
 *
 *  @par Example
 *  @verbatim

    double array[] = {4, 3, 7, 3, 1, 6, 3, 3};
    int ans;
    
    ans = countIf(array, 8, 2);
    REQUIRE( ans == 0 );

    @endverbatim
 ************************************************************************/
int countIf(double *array, int size, double item)
{
    int count = 0;
    int i;
    
    for(i = 0; i < size; ++i)
    {
        if (array[i] == item)
        {
            ++count;
        }
    }
    
    return count;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  Using newtons bisection method, this functions finds the square root 
 *  using the value(x)
 *
 *  @param[dbl] x
 *              
 *
 *  @returns the square root of the value of x
 *
 *  @par Example
 *  @verbatim

    double ans;
    
    ans = mySqrt(25.0);
    
    REQUIRE(ans == Approx(5.0));

    @endverbatim
 ************************************************************************/
double mySqrt( double x )
{
    double high, low;
    double mid;
    int i;
    
    if (x <= 0)
    {
        return 0;
    }
    else
    {
        low = 0;
    }
    
    if(x >= 1)
    {
        high = x;
    }
    else
    {
        high = 1;
    }
    
    for( i = 0; i < ITERATIONMAX; ++i)
    {
        mid = (high + low) / 2;
        if(abs(pow(mid, 2.0) - x) < ERRORVALUE)
        {
            return mid;
        }
        else if(pow(mid, 2.0) > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    
    return mid;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  Using newtons bisection method, this functions finds the cube root 
 *  using the value(x)
 *
 *  @param[dbl] x
 *              
 *
 *  @returns the cube root of the value of x
 *
 *  @par Example
 *  @verbatim

    double ans;
    
    ans = myCbrt(216.0);
    
    REQUIRE(ans == Approx(6.0));

    @endverbatim
 ************************************************************************/
double myCbrt( double x )
{
    double high, low;
    double mid;
    int i;
    
    if (x <= 0)
    {
        return 0;
    }
    else
    {
        low = 0;
    }
    
    if(x >= 1)
    {
        high = x;
    }
    else
    {
        high = 1;
    }
    
    
    for( i = 0; i < ITERATIONMAX; ++i)
    {
        mid = (high + low) / 2;
        if(abs(pow(mid, 3.0) - x) < ERRORVALUE)
        {
            return mid;
        }
        else if(pow(mid, 3.0) > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    
    return mid;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  Using newtons bisection method, this functions finds the logarithm 
 *  using the value(x)
 *
 *  @param[dbl] x
 *              
 *
 *  @returns the log of the value of x
 *
 *  @par Example
 *  @verbatim
 
    double x = 8;
    int base = 10;
    double ans;

    ans = myLog(x, base);

    REQUIRE(ans == Approx(0.903089));

    @endverbatim
 ************************************************************************/
double myLog( double x, int base )
{
    double high = 1;
    double mid, low;
    int i;
    
    while(pow(base, high) <= x)
    {

        high = high + 1;
        
    }
    
    low = high - 1.0;
    
    for(i = 0; i < ITERATIONMAX; ++i)
    {
        mid = (high + low) / 2.0;
        
        if(abs((pow(base, mid)) - x) < ERRORVALUE)
        {
            return mid;
        }
        else if(pow(base, mid) > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return mid;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function determines the factorial of the given n
 *
 *  @param[dbl] n
 *              
 *
 *  @returns the factorial of the value of x
 *
 *  @par Example
 *  @verbatim
 
    double n = 5;
    double ans;
    
    ans = myFactorial(n);
    
    REQUIRE(ans == 120);

    @endverbatim
 ************************************************************************/
double myFactorial(double n)
{
    double res = 1.0;
    int i;
    
    for(i = 1; i <=n; i++)
    {
        res *= i;
    }
    return res;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function determines the sine of the given angle
 *
 *  @param[dbl] angle in radians
 *              
 *
 *  @returns sine of the anlge
 *
 *  @par Example
 *  @verbatim
 
    double deg = 0;
    double ans;

    ans = mySin(deg);

    REQUIRE(ans == Approx(0));

    @endverbatim
 ************************************************************************/
double mySin (double angleRad)
{
    double sum = 0;
    int i;
    double index;
    
    for(i = 0; i < TERMS; ++i)
    {
        index = 2 * i + 1;
        
        if(i % 2 == 0)
        {
            sum += (pow(angleRad, index)) / (myFactorial(index));
        }
        else
        {
            sum -= (pow(angleRad, index)) / (myFactorial(index));
        }
    }
    
    return sum;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function converts the angle from degrees to radians and
 *  determines the sine of the given angle (degrees)
 *
 *  @param[dbl] angle in degrees
 *              
 *
 *  @returns sine of the angle
 *
 *  @par Example
 *  @verbatim
 
    double deg = 90;
    double ans;

    ans = mySinD(deg);

    REQUIRE(ans == Approx(1.0));

    @endverbatim
 ************************************************************************/    
double mySinD(double angleDeg)
{
    double rad;
    double ans;
    
    rad = (angleDeg * PI) / 180;
    
    ans = mySin(rad);
    
    return ans;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function determines the cosine of the given angle
 *
 *  @param[dbl] angle in radians
 *              
 *
 *  @returns cosine of the anlge
 *
 *  @par Example
 *  @verbatim
 
    double deg = 1.5708;
    double ans;

    ans = myCos(deg);

    REQUIRE(ans == Approx(1.0));

    @endverbatim
 ************************************************************************/
double myCos (double angleRad)
{
    double sum = 0;
    int i;
    double index;
    
    for(i = 0; i < TERMS; ++i)
    {
        index = 2 * i;
        
        if(i % 2 == 0)
        {
            sum += (pow(angleRad, index)) / (myFactorial(index));
        }
        else
        {
            sum -= (pow(angleRad, index)) / (myFactorial(index));
        }
    }
    
    return sum;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function converts the angle from degrees to radians and
 *  determines the cosine of the given angle (degrees)
 *
 *  @param[dbl] angle in degrees
 *              
 *
 *  @returns cosine of the angle
 *
 *  @par Example
 *  @verbatim
 
    double deg = 0;
    double ans;

    ans = myCosD(deg);

    REQUIRE(ans == Approx(0));

    @endverbatim
 ************************************************************************/ 
double myCosD(double angleDeg)
{
    double rad;
    double ans;
    
    rad = (angleDeg * PI) / 180;
    
    ans = myCos(rad);
    
    return ans;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function determines the tangent of the given angle
 *
 *  @param[dbl] angle in radians
 *              
 *
 *  @returns tangent of the anlge
 *
 *  @par Example
 *  @verbatim
 
    double deg = 0.785398;
    double ans;
     
    ans = myTan(deg);
     
    REQUIRE(ans == Approx(0));

    @endverbatim
 ************************************************************************/
double myTan(double rad)
{
    double ans;
    
    ans = mySin(rad) / myCos(rad);
    
    return ans;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function converts the angle from degrees to radians and
 *  determines the tangent of the given angle (degrees)
 *
 *  @param[dbl] angle in degrees
 *              
 *
 *  @returns tangent of the angle
 *
 *  @par Example
 *  @verbatim
 
    double deg = 0;
    double ans;
     
    ans = myTanD(deg);
     
    REQUIRE(ans == Approx(0));

    @endverbatim
 ************************************************************************/ 
double myTanD(double angleDeg)
{
   double rad;
   double ans;
   
   rad = (angleDeg * PI) / 180;
   
   ans = myTan(rad);
   
   return ans;
}

