#pragma once

#include "card.h"
#include <string>
#include <vector>
#include <iostream>

class Hand {
    private:
        std::vector<Card> hand; //contains the cards
        int mostCommonFaceCount;//count of the most common card in hand. ex: AD 3H AS 3D 3S results in 3
        int scndCommonFaceCount;//count of the second most common card in hand. ex: AD 3H 6S 3D 3S results in 2
        bool hasOnlyOneSuit;    //indicates if all cards in hand are the same suit, hearts, diamonds, etc
        bool isStraight;        //indicates if all cards can be placed in order. ex: K Q J 10 9
    public:
        Hand();
        void print();
        //mutators
        void setMostCommonFaceCount(const int mostCommon) { mostCommonFaceCount = mostCommon; }
        void setScndCommonFaceCount(const int scndCommon) { scndCommonFaceCount = scndCommon; }
        void setHasOnlyOneSuit(const bool oneSuit)        { hasOnlyOneSuit = oneSuit;         }
        void setIsStraight(const bool straight)           { isStraight = straight;            }
        void setHand(std::vector<Card> h)                 { hand = h;                         }
        //accessors
        int getMostCommonFaceCount()    { return mostCommonFaceCount; }
        int getScndCommonFaceCount()    { return scndCommonFaceCount; }
        bool getHasOnlyOneSuit()        { return hasOnlyOneSuit;      }
        bool getIsStraight()            { return isStraight;          }
        std::vector<Card>* getHand()    { return &hand;               }

        //specialized mutators
        void addCard(const Card card);                
        void populateHand(const std::string rawCards);
        //specialized accessors
        int getFaceMatchCount(const cardFace faceToMatch);
        int getSuitMatchCount(const cardSuit suitToMatch);
        //sets variables that require evaluation/logic
        void setProperties();       
        void findRepeatCards();
        void determineOneSuit();
        void determineStraight();
        //helper functions
        bool hasMatches();
        bool isStraightFlush();
        bool isFullHouse();
        bool isFourOfKind();
        int getMaxFaceIdx();
        int checkForFace(const cardFace valueToFind);
        int countFaces  (const cardFace valueToFind);
};