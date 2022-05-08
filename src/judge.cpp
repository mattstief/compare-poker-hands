#include "judge.h"

//Returns 0 if both conditions are false.
//Returns 1 if the first condition is true and the second is false.
//Returns 2 if the second condition is true and the first is false.
//Returns 3 if both conditions are true.
int Judge::compareBools(const bool bool1, const bool bool2) {
    if (!bool1 && !bool2)
        return 0;
    if (bool1 && !bool2)
        return 1;
    if (!bool1 && bool2)
        return 2;
    else //bool1 && bool2
        return 3;
}

//Returns 0 if ints are equal.
//Returns 1 if the first int is larger.
//Returns 2 if the second int is larger.
int Judge::compareInts(const int int1, const int int2) {
    if (int1 > int2) 
        return 1;
    if (int2 > int1)
        return 2;
    return 0;   //int1 == int2 
}

//returns 1 hand1 is better, 2 if hand2 is better, 0 if tie
int Judge::checkWinner(Hand *hand1, Hand *hand2) {   
    const int straightFlushWin = Judge::compareStraightFlush(hand1, hand2); 
    if(straightFlushWin > 0 && straightFlushWin <= 2)    
        return straightFlushWin;
    else if (straightFlushWin > 2)   //both hands are a straight flush, compare ranks
        return compareRanks(hand1, hand2);  

    const int fourOfKindWin = Judge::compareFourKind(hand1, hand2); 
    if(fourOfKindWin > 0 && fourOfKindWin <= 2)    
        return fourOfKindWin;
    else if (fourOfKindWin > 2)      //both hands are four of a kind, compare ranks
        return compareRanks(hand1, hand2); 

    const int fullHouseWin = Judge::compareFullHouse(hand1, hand2);
    if(fullHouseWin > 0 && fullHouseWin <= 2)    
        return fullHouseWin;
    else if (fullHouseWin > 2)      //both hands are a full house, compare ranks
        return compareRanks(hand1, hand2);  

    const int flushWin = Judge::compareFlush(hand1, hand2);
    if(flushWin > 0 && flushWin <= 2)    
        return flushWin;
    else if (flushWin > 2)      //both hands are a flush, compare ranks
        return compareRanks(hand1, hand2);

    const int straightWin = Judge::compareStraight(hand1, hand2);
    if(straightWin > 0 && straightWin <= 2)    
        return straightWin;
    else if (straightWin > 2)      //both hands are a straight, compare ranks
        return compareRanks(hand1, hand2);

    const int mostCommonMatchWin = Judge::compareMostCommon(hand1, hand2);
    if (mostCommonMatchWin)     //not tied, return the winner
        return mostCommonMatchWin;

    const int scndCommonMatchWin = Judge::compareScndCommon(hand1, hand2);
    if (scndCommonMatchWin)     //not tied, return the winner
        return scndCommonMatchWin;

    return compareRanks(hand1, hand2);
}

//returns 0 if both hands have the same ranks - tie
//returns 1-2 if one hand has greater ranks than the other
int Judge::compareRanks(Hand *hand1, Hand *hand2) {
    int handScores[2] = {0};
    for(cardFace f = cardFace::ace; f > 0; f = cardFace(int(f) - 1)) {
        const int hand1_matches = (hand1->countFaces(f)); 
        const int hand2_matches = (hand2->countFaces(f)); 
        handScores[0] += f * hand1_matches;
        handScores[1] += f * hand2_matches;
        // const int result = compareInts(hand1_matches, hand2_matches);  
        // if (result) {
        //     handScores[result - 1] += f;
        // }
    }
    return compareInts(handScores[0], handScores[1]);
}

//returns 0 if hands have the same most common card count
//returns 1-2 if a hand has a greater most common card count
int Judge::compareMostCommon(Hand *hand1, Hand *hand2) {
    const int int1 = hand1->getMostCommonFaceCount();
    const int int2 = hand2->getMostCommonFaceCount();
    return compareInts(int1, int2);
}

//returns 0 if hands have the same second most common card count
//returns 1-2 if a hand has a greater second most common card count
int Judge::compareScndCommon(Hand *hand1, Hand *hand2) {
    const int int1 = hand1->getScndCommonFaceCount();
    const int int2 = hand2->getScndCommonFaceCount();
    return compareInts(int1, int2);
}



//returns 0 if neither hand is straight flush
//returns 1-2 if one of the hands is a straight flush and the other isn't
//returns 3 if both are straight flushes
int Judge::compareStraightFlush(Hand *hand1, Hand *hand2) {
    const bool bool1 = hand1->isStraightFlush();
    const bool bool2 = hand2->isStraightFlush();
    return compareBools(bool1, bool2);
}

//returns 0 if neither hand is four of kind
//returns 1-2 if one of the hands is four of kind and the other isn't
//returns 3 if both are four of a kind
int Judge::compareFourKind(Hand *hand1, Hand *hand2) {
    const bool bool1 = hand1->isFourOfKind();
    const bool bool2 = hand2->isFourOfKind();
    return compareBools(bool1, bool2);
}

//returns 0 if neither hand is full house
//returns 1-2 if one of the hands is a full house and the other isn't
//returns 3 if both are full houses
int Judge::compareFullHouse(Hand *hand1, Hand *hand2) {
    const bool bool1 = hand1->isFullHouse();
    const bool bool2 = hand2->isFullHouse();
    return compareBools(bool1, bool2);
}

//returns 0 if neither hand is a flush
//returns 1-2 if one of the hands is a flush and the other isn't
//returns 3 if both are flushes
int Judge::compareFlush(Hand *hand1, Hand *hand2) {
    const bool bool1 = hand1->getHasOnlyOneSuit();
    const bool bool2 = hand2->getHasOnlyOneSuit();
    return compareBools(bool1, bool2);
}

//returns 0 if neither hand is a straight
//returns 1-2 if one of the hands is a straight and the other isn't
//returns 3 if both are straights
int Judge::compareStraight(Hand *hand1, Hand *hand2) {
    const bool bool1 = hand1->getIsStraight();
    const bool bool2 = hand2->getIsStraight();
    return compareBools(bool1, bool2);  
}