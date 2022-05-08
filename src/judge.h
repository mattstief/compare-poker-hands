#pragma once

#include "hand.h"

//judge class enforces the rules of the game with an iron fist. eliminating all who doubt it's might
class Judge {
    public:
        //calls other functions to determine if a win condition is satisfied
        static int checkWinner(Hand *hand1, Hand *hand2);
        //simple comparison functions
        static int compareBools(const bool bool1, const bool bool2);
        static int compareInts(const int int1, const int int2);
        //interfaces for the comparison functions - makes everything pretty
        static int compareStraightFlush(Hand *hand1, Hand *hand2);
        static int compareMostCommon(Hand *hand1, Hand *hand2);
        static int compareScndCommon(Hand *hand1, Hand *hand2);
        static int compareFullHouse(Hand *hand1, Hand *hand2);
        static int compareFourKind(Hand *hand1, Hand *hand2);
        static int compareStraight(Hand *hand1, Hand *hand2);
        static int compareRanks(Hand *hand1, Hand *hand2);
        static int compareFlush(Hand *hand1, Hand *hand2);
        
};