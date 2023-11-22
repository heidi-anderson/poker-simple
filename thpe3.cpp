/** **********************************************************************
 * @file thpe3
 ************************************************************************/
#include "thpe3.h"
#include <iostream>
using namespace std;
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will classify the different poker hands
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns -1, if none or the hand classification
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {9, 10, 11, 12, 0};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == ROYALFLUSH);

    @endverbatim
 ************************************************************************/
int classifyHand( int cards[52], int length )
{
    int i;
    
    if( length < 5 )
    {
        return -1;
    }
    for(i = 0; i < length; ++i)
    {
        if ( cards[i] > 51 )
        {
            return 1;
        }
    }
    
    if( fourKind(cards, length) == true )
    {
        return FOURKIND;
    }
    if ( fullHouse( cards, length) == true )
    {
        return FULLHOUSE;
    }
    if( threeKind( cards, length) == true )
    {
        return THREEKIND;
    }
    if( twoPair( cards, length) == true )
    {
        return TWOPAIR;
    }
    if( twoKind(cards, length) == true )
    {
        return TWOKIND;
    }
    if( royalFlush(cards, length) == true )
    {
        return ROYALFLUSH;
    }
    if( straight(cards, length) == true && flush(cards, length) == true)
    {
        return STRAIGHTFLUSH;
    }
    if( straight(cards, length) == true)
    {
        return STRAIGHT;
    }
    if( flush(cards, length) == true)
    {
        return FLUSH;
    }
    
    return HIGHCARD;
}    
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function sorts the cards based on the index
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns nothing
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {9, 10, 11, 12, 0};
    int ans = sortIndex(cards, 5);
    
    REQUIRE(ans == "0, 9, 10, 11, 12");

    @endverbatim
 ************************************************************************/
void sortIndex(int cards[52], int length)
{
    int i, j;
    bool swapMade = true;
    int temp;
    
    for(i = 0; i < length - 1 && swapMade == true; i ++)
    {
        swapMade = false;
        for( j = 0; j < length - 1 - i; j ++ )
        {
            if( cards[j] > cards[j + 1])
            {
                temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
                swapMade = true;
            }
        }
    }
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function sorts the cards based on the face of the card
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns nothing
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {0, 23, 31, 40, 49};
    int ans = sortFace(cards, 5);
    
    REQUIRE(ans == "0, 40, 31, 23, 49");

    @endverbatim
 ************************************************************************/
void sortFace(int cards[52], int length)
{
    int i, j;
    bool swapMade = true;
    int temp;
    
    for(i = 0; i < length - 1 && swapMade == true; i ++)
    {
        swapMade = false;
        for( j = 0; j < length - 1 - i; j ++ )
        {
            if( (cards[j] % 13) > (cards[j + 1] % 13))
            {
                temp = cards[j];
                cards[j] = cards[j + 1];
                cards[j + 1] = temp;
                swapMade = true;
            }
        }
    }
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return true if the hand is four of a kind
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {2, 15, 28, 41, 6};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == FOURKIND);

    @endverbatim
 ************************************************************************/
bool fourKind( int cards[52], int length )
{
    sortFace(cards, length);
    int i;
    for (i = 3; i < length; ++i)
    {
        if( 
            cards[i] % 13 == cards[i - 1] % 13 &&
            cards[i - 1] % 13 == cards[i - 2] % 13 &&
            cards[i]  % 13 == cards[i - 3] % 13)
        {
            return true;
        }
    }
    return false;
    
}

bool threeKind( int cards[52], int length )
{
    sortFace(cards, length);
    int i;
    for (i = 2; i < length; ++i)
    {
        if( 
        cards[i] % 13 == cards[i - 1]  % 13 && 
        cards[i - 1] % 13 == cards[i - 2] % 13)
        {
            return true;
        }
    }
    return false;
    
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return true if the hand is two of a kind
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {2, 15, 8, 1, 6};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == TWOKIND);

    @endverbatim
 ************************************************************************/
bool twoKind( int cards[52], int length )
{
    sortFace(cards, length);
    int i;
    for (i = 1; i < length; ++i)
    {
        if( cards[i] % 13 == cards[i - 1] % 13)
        {
            return true;
        }
    }
    return false;
    
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return true if the hand is straight
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {1, 5, 15, 30, 42};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == STRAIGHT);

    @endverbatim
 ************************************************************************/
bool straight( int cards[52], int length)
{
    sortFace(cards, length);
    int i;

    for( i = 4; i < length; ++i)
    {
        if(
            ((cards[i] % 13) == ((cards[i - 1] % 13) + 1)) &&
            ((cards[i] % 13) == ((cards[i - 2] % 13) + 2)) &&
            ((cards[i] % 13) == ((cards[i - 3] % 13) + 3)) &&
            ((cards[i] % 13) == ((cards[i - 4] % 13) + 4)) )
        {
            return true;
        }
        else if(
            ((cards[i] % 13) == 12) &&
            ((cards[i - 1] % 13) == 11) &&
            ((cards[i - 2] % 13) == 10) &&
            ((cards[i - 3] % 13) == 9) &&
            ((cards[i - 4] % 13) == 0) )
        {
            return true;
        }
        
    }
    return false;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return true if the hand is a flush
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {0, 1, 2, 3, 12};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == FLUSH);

    @endverbatim
 ************************************************************************/
bool flush( int cards[52], int length)
{
    sortIndex(cards, length);
    int i;
    
    for( i = 4; i < length; ++i)
    {
        if(
            ((cards[i] / 13) == (cards[i - 1] / 13)) &&
            ((cards[i] / 13) == (cards[i - 2] / 13)) &&
            ((cards[i] / 13) == (cards[i - 3] / 13)) &&
            ((cards[i] / 13) == (cards[i - 4] / 13)))
        {
            return true;
        }
    }
    return false;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return true if the hand is a royal flush
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {9, 10, 11, 12, 0};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == ROYALFLUSH);

    @endverbatim
 ************************************************************************/
bool royalFlush( int cards[52], int length )
{
    sortIndex(cards, length);
    int i;
    
    for( i = 4; i < length; ++i )
    {
        if(
            ((cards[i] % 13) == 12) &&
            ((cards[i - 1] % 13) == 11) &&
            ((cards[i - 2] % 13) == 10) &&
            ((cards[i - 3] % 13) == 9) &&
            ((cards[i - 4] % 13) == 0) )
        {
            return flush(cards, length);
        }
    }
    return false;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return true if the hand is a two pair
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {0, 0, 1, 2, 2};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == TWOPAIR);

    @endverbatim
 ************************************************************************/
bool twoPair ( int cards[52], int length )
{
    sortFace(cards, length);
    
    if(twoKind(cards + 0, 2) && twoKind(cards + 2, 2))
    {
            return true;
    }
    if(twoKind(cards + 0, 2) && twoKind(cards + 3, 2))
    {
            return true;
    }
    if(twoKind(cards + 1, 2) && twoKind(cards + 3, 2))
    {
            return true;
    }
    return false;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function will return true if the hand is a full house
 *
 *  @param[int] cards[52]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

    int cards[5] = {0, 13, 2, 28, 41};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == FULLHOUSE);

    @endverbatim
 ************************************************************************/
bool fullHouse( int cards[52], int length )
{
    sortFace(cards, length);
    
    if(twoKind(cards + 0, 2) && threeKind(cards + 2, 3))
    {
            return true;
    }
    if(threeKind(cards + 0, 3) && twoKind(cards + 3, 2))
    {
            return true;
    }
    return false;
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  This function prints out the report of the game
 *
 *  @param[int] handNames[10]
 *  @param[int] length
 *              
 *
 *  @returns true or false
 *
 *  @par Example
 *  @verbatim

Hand Name                Dealt         Chance
Royal Flush                  0       0.000000%
Straight Flush               0       0.000000%
Four of a Kind               0       0.000000%
Full House                   0       0.000000%
Flush                        1       0.283286%
Straights                    1       0.283286%
Three of a Kind              8       2.266289%
Two Pair                    25       7.082153%
Two of a Kind              131      37.110482%
High Card                  187      52.974504%

Total Hands Dealt          353

    @endverbatim
 ************************************************************************/
string report( int handNames[10], int length )
{

    stringstream result;

    result << "Hand Name                Dealt         Chance" << endl;
    result << "Royal Flush"     << setw(19) << handNames[9] << setw(15) << fixed << setprecision(6) << (double)handNames[9] * 100.0 / length << "%" << endl;
    result << "Straight Flush"  << setw(16) << handNames[8] << setw(15) << fixed << setprecision(6) << (double)handNames[8] * 100.0 / length << "%" << endl;
    result << "Four of a Kind"  << setw(16) << handNames[7] << setw(15) << fixed << setprecision(6) << (double)handNames[7] * 100.0 / length << "%" << endl;
    result << "Full House"      << setw(20) << handNames[6] << setw(15) << fixed << setprecision(6) << (double)handNames[6] * 100.0 / length << "%" << endl;
    result << "Flush"           << setw(25) << handNames[5] << setw(15) << fixed << setprecision(6) << (double)handNames[5] * 100.0 / length << "%" << endl;
    result << "Straights"       << setw(21) << handNames[4] << setw(15) << fixed << setprecision(6) << (double)handNames[4] * 100.0 / length << "%" << endl;
    result << "Three of a Kind" << setw(15) << handNames[3] << setw(15) << fixed << setprecision(6) << (double)handNames[3] * 100.0 / length << "%" << endl;
    result << "Two Pair"        << setw(22) << handNames[2] << setw(15) << fixed << setprecision(6) << (double)handNames[2] * 100.0 / length << "%" << endl;
    result << "Two of a Kind"   << setw(17) << handNames[1] << setw(15) << fixed << setprecision(6) << (double)handNames[1] * 100.0 / length << "%" << endl;
    result << "High Card"       << setw(21) << handNames[0] << setw(15) << fixed << setprecision(6) << (double)handNames[0] * 100.0 / length << "%" << endl << endl;
    
    result << "Total Hands Dealt" << setw(13) << length << endl;
    
    return result.str();
}