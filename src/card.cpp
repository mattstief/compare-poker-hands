#include "card.h"

//default constructor
Card::Card() {
    face = cardFace::noface;
    suit = cardSuit::nosuit;
}

//parameterized constructor
Card::Card(cardFace f, cardSuit s) {
    face = f;
    suit = s;
}

//returns the card face enum associated with a character
//enum translation
cardFace getFaceFromChar(char c) {
    switch(c) {
        case '2':
            return cardFace::two;
        case '3':
            return cardFace::three;
        case '4':
            return cardFace::four;
        case '5':
            return cardFace::five;
        case '6':
            return cardFace::six;
        case '7':
            return cardFace::seven;
        case '8':
            return cardFace::eight;
        case '9':
            return cardFace::nine;
        case '1':
            return cardFace::ten;
        case 'J':
            return cardFace::joker;
        case 'Q':
            return cardFace::queen;
        case 'K':
            return cardFace::king;
        case 'A':
            return cardFace::ace;
        default:
            return cardFace::noface;
    }
}

//returns the card suit enum associated with a character
//enum translation
cardSuit getSuitFromChar(char c) {
    switch(c) {
        case 'H':
            return cardSuit::heart;
        case 'D':
            return cardSuit::diamond;
        case 'S':
            return cardSuit::spade;
        case 'C':
            return cardSuit::club;
        default:
            return cardSuit::nosuit;
    }
}