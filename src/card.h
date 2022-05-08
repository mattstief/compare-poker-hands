#pragma once

#define FACES 14
#define SUITS 5

//enum representation the face of a card, ordered by point ranking in the game
enum cardFace {
    noface,
    two, 
    three, 
    four, 
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    joker,
    queen,
    king,
    ace
};

//enum representing the suit of a card. 
enum cardSuit {
    nosuit,
    heart, 
    diamond, 
    spade, 
    club,
};
//helper functions to translate input to enums
cardFace getFaceFromChar(char c);
cardSuit getSuitFromChar(char c);

//card class representing a playing card
class Card {
    private:
        cardFace face;  //face value of card, ace, two, joker, king, etc
        cardSuit suit;  //suit of card, heart, diamond, spade, club

    public:
        Card();
        Card(cardFace f, cardSuit s);
        void print();
        //mutators and accessors
        void setFace(cardFace f) { face = f; }
        void setSuit(cardSuit s) { suit = s; }
        cardFace getFace() { return face; }
        cardSuit getSuit() { return suit; }

        
};