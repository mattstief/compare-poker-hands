#include "hand.h"

//default constructor
Hand::Hand() {
    int mostCommonFaceCount = 0;
    int scndCommonFaceCount = 0; 
    bool hasOnlyOneSuit = false;
    bool isStraight = false; 
}

//adds card to this hand's vector of Cards
void Hand::addCard(const Card card) {
    hand.push_back(card);
}

//takes in a string of raw card data. ex: "KD QD 7S 4S 9H"
//creates cards from the string data, and adds the cards to
//this hand's vector of Cards
void Hand::populateHand(const std::string inputLine) {
    cardFace inputFace = cardFace::noface;
    cardSuit inputSuit = cardSuit::nosuit;

    for(char c : inputLine) {
        const bool isFaceValue = ( getFaceFromChar(c) != cardFace::noface );
        const bool isSuitValue = ( getSuitFromChar(c) != cardSuit::nosuit );

        if( isFaceValue ) {
            inputFace = getFaceFromChar(c);
        }
        else if ( isSuitValue ) {
            inputSuit = getSuitFromChar(c);
            Card card(inputFace, inputSuit);
            this->addCard(card);

            inputFace = cardFace::noface;
            inputSuit = cardSuit::nosuit;
        }
    }
    this->setProperties();
}

//set the hand's variables that require more complex logic to determine.
void Hand::setProperties() {
    this->findRepeatCards();
    this->determineOneSuit();
    this->determineStraight();
    //this->print();
}

//determines the first and second most common cards of this hand 
//ex: "4H 6C 8D QS 4S" sets most common to 2 because there are 2 fours, and second most common to 1
void Hand::findRepeatCards() {
    int faceCounts[FACES] = {0};
    int max = 0;
    int scnd = 0;
    //tally card face values 
    for(Card card : hand) {
        cardFace face = card.getFace();
        faceCounts[face] += 1;
    }
    //find most common and second most common card counts
    for(int i = 0; i < FACES; i++) {
        const int count = faceCounts[i];
        if (count > 0) {
            if(count >= max) {
                scnd = max;
                max = count;
            }
            else if(max && !scnd) {
                scnd = count; 
            }
        }
    }
    //set variables to counts found
    this->setMostCommonFaceCount(max);
    this->setScndCommonFaceCount(scnd);
}

//determines if all cards in a hand are the same suit. ex: "AC 3C 5C 9C QC"
void Hand::determineOneSuit() {
    Card firstCard = hand[0];
    cardSuit suitToMatch = firstCard.getSuit();

    int matchCount = 0;
    for(Card card : hand) {
        cardSuit currentSuit = card.getSuit();
        if(currentSuit != suitToMatch) {
            this->setHasOnlyOneSuit(false);
            return;
        }
    }
    this->setHasOnlyOneSuit(true);
}

//determines if all cards in the hand make a straight. ex: "6D 5D 4H 3D 2H"
void Hand::determineStraight() {
    if (hasMatches()) {
        this->setIsStraight(false);
    }
    else {
        int maxIdx = getMaxFaceIdx();
        cardFace highFace = hand[maxIdx].getFace();

        int counter = 0;
        while(counter < 4) {
            bool nextCardFound = false;
            if(checkForFace(highFace) >= 0) {
                counter++;
                highFace = cardFace(int(highFace) - 1); //TODO overload subtraction operator
            }
            else{
                this->setIsStraight(false);
                return;            
            }
        }
        this->setIsStraight(true);
    }
}


//returns index of the card with the greatest face value
int Hand::getMaxFaceIdx() {
    int maxIdx = 0;
    for(int i = 1; i < hand.size(); i++) {
        if(hand[i].getFace() > hand[maxIdx].getFace()){
            maxIdx = i;
        }
    }
    return maxIdx;
}

//returns index to the card with a matching face value or -1 if none found
int Hand::checkForFace(const cardFace valueToFind) {
    for(int i = 0; i < hand.size(); i++) {
        const int value = hand[i].getFace(); 
        if(value == valueToFind)
            return i;
    }
    return -1;
}

//returns the count of the card with a matching face value or 0 if none found
int Hand::countFaces(const cardFace valueToFind) {
    int matches = 0;
    for(int i = 0; i < hand.size(); i++) {
        const int value = hand[i].getFace(); 
        if(value == valueToFind)
            matches++;
    }
    return matches;
}

//determine if a hand has any duplicate face cards 
//ex: "AD QD 9H 7S 5S" has no repeats, return false
bool Hand::hasMatches() {
    return (getMostCommonFaceCount() > 1 || getScndCommonFaceCount() > 1);
}

bool Hand::isStraightFlush() {
    return (isStraight && hasOnlyOneSuit);
}

bool Hand::isFourOfKind() {
    return (getMostCommonFaceCount() == 4);
}

bool Hand::isFullHouse() {
    return (getMostCommonFaceCount() == 3 && 
            getScndCommonFaceCount() == 2);
}

void Hand::print() {
    int index = 1;
    int total = hand.size();

    printf("Hand info\nmost common count: %d\nscnd common count: %d\n", mostCommonFaceCount, scndCommonFaceCount);
    printf("one suit: %s", hasOnlyOneSuit ? "true\n" : "false\n");
    printf("straight: %s", isStraight ? "true\n" : "false\n");
    std::cout << "Card num/total: (face, suit)\n";

    for(Card card : hand) {
        printf("card %d/%d: (%d, %d)\n", index, total, card.getFace(), card.getSuit());
        index++;
    }
    std::cout << "\n";
}