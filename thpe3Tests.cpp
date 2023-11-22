#define CATCH_CONFIG_RUNNER
#include "..\\catch.hpp"
#include "thpe3.h"

const bool RUNCATCH = false;

int main( int argc, char **argv)
{
    Catch::Session session;
    int result;
 
    if( RUNCATCH )
    {
        result = session.run();
        if ( result != 0 )
        {
            cout << "Test cases didn't pass." << endl;
            return result;
        }
    }

    int i;
    int handNames[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int length = 0;
    int hand[5] = {0, 0, 0, 0, 0};
    int classification;
    
    if(argc != 4)
    {
        cout << "Usage: thpe3.exe -s seedValue quantity" << endl;
        cout << "       seedValue - # is integer for random numbers" << endl;
        cout << "       quantity - # of hands to deal" << endl << endl;

        cout << "       thpe3.exe -f inputfilename outputfilename" << endl;
        cout << "       inputfilename - filename containing the poker hands to classify" << endl;
        cout << "       outputfilename - filename to output the statistics in" << endl;        
        return 0;
    }
    
    if( strcmp(argv[1], "-s" ) == 0 )
    {
        int seed = atoi(argv[2]);
        length = atoi(argv[3]);
        
        default_random_engine engine( seed );
        uniform_int_distribution<int> distribution(0,51);
        
        for( i = 0; i < length; ++i )
        {
            hand[0] = distribution( engine );
            do
            {
                hand[1] = distribution( engine );
            }
            while(hand[1] == hand[0]);
            do
            {
                hand[2] = distribution( engine );
            }
            while(hand[2] == hand[1] || hand[2] == hand[0]);
            do
            {
                hand[3] = distribution( engine );
            }
            while(hand[3] == hand[2] || hand[3] == hand[1] || hand[3] == hand[0]);
            do
            {
                hand[4] = distribution( engine );
            }
            while(hand[4] == hand[3] || hand[4] == hand[2] || hand[4] == hand[1] || hand[4] == hand[0]);
            
            
            classification = classifyHand(hand, 5);
            handNames[classification] ++;
        }
        
        cout << report(handNames, length);
        
    }
    else if( strcmp(argv[1], "-f") == 0)
    {
        ifstream inputFile (argv[2], fstream::in);
        ofstream outputFile (argv[3], fstream::out);
        
        
        if(inputFile.is_open() == false)
        {
            cout << "Unable to open the file: " << argv[2] << endl;
            if(outputFile.is_open() == true)
            {
                outputFile.close();
            }
            return 0;
        }
        if(outputFile.is_open() == false)
        {
            cout << "Unable to open the file: " << argv[3] << endl;
            inputFile.close();
            return 0;
        }
        
        while(inputFile.good() == true)
        {
            for(i = 0; (i < 5) && (inputFile >> hand[i]); ++i)
            {
               
            }
            if( i == 5 )
            {
                classification = classifyHand(hand, 5);
                handNames[classification] ++;
                length++;
            }
        }
        outputFile << report(handNames, length);
        inputFile.close();
        outputFile.close();
       
       
    }
    else
    {
        cout << "Invalid Option" << endl;
        return 0;
    }
    
    return 0;
}

TEST_CASE("royalFlush - ending in an ace")
{
    
    int cards[5] = {9, 10, 11, 12, 0};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == ROYALFLUSH);
}

TEST_CASE("straightflush - returns true")
{
    
    int cards[5] = {0, 1, 2, 3, 4};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == STRAIGHTFLUSH);
}

TEST_CASE("fourKind - testing true")
{
    int cards[5] = {2, 15, 28, 41, 6};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == FOURKIND);
}

TEST_CASE("fullhouse - returns truee")
{
    
    int cards[5] = {0, 13, 2, 28, 41};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == FULLHOUSE);
}

TEST_CASE("straight - returns true")
{
    
    int cards[5] = {1, 5, 15, 30, 42};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == STRAIGHT);
}

TEST_CASE("flush - returns true")
{
    
    int cards[5] = {0, 1, 2, 3, 12};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == FLUSH);
}

TEST_CASE("threeKind - testing true")
{
    int cards[5] = {2, 15, 28, 1, 6};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == THREEKIND);
}

TEST_CASE("twoPair - returns true")
{
    
    int cards[5] = {0, 0, 1, 2, 2};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == TWOPAIR);
}

TEST_CASE("twoKind - testing true")
{
    int cards[5] = {2, 15, 8, 1, 6};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == TWOKIND);
}
TEST_CASE("highcard - returns true")
{
    
    int cards[5] = {22, 51, 45, 43, 40};
    int ans = classifyHand(cards, 5);
    
    REQUIRE(ans == HIGHCARD);
}




