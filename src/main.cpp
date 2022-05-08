#include "judge.h"
#include <fstream>
#define HANDS_PER_FILE 2

void getLinesFromFile(std::string filename, std::vector<std::string> &lines);

int main(int argc, char* argv[]) {
    for(int i = 1; i < argc; ++i) {
        std::vector<std::string> inputLines;
        std::string filename(argv[i]);

        getLinesFromFile(filename, inputLines);
        if(inputLines.size() < HANDS_PER_FILE) {
            std::cout << "parsed input too small\n";
            exit(0);
        }
        //print each line of input
        std::cout << "\n" << filename << "\nvvvvvvvvvvvvvvvv\n" <<  
        inputLines.at(0) << "\n" << inputLines.at(1) << "\n"; 
        //construct hands then populate them with cards
        Hand hand1, hand2;
        hand1.populateHand(inputLines.at(0));
        hand2.populateHand(inputLines.at(1));
        int winner = Judge::checkWinner(&hand1, &hand2);
        //print the judges decision
        if(!winner) {
            std::cout << "It's a tie!\n";
        }
        else {
            std::cout << "Hand " << winner << " wins!\n";
        }
        std::cout << "^^^^^^^^^^^^^^^^\n";
    }
    return 0;
}

//stores each line of text in <filename> into provided vector <lines>
void getLinesFromFile(std::string filename, std::vector<std::string> &lines) {
    std::ifstream input(filename);
    if(!input) {
        std::cout << "error opening file, exiting....\n";
        exit(0); 
    }

    std::string tempLine;
    while(std::getline(input, tempLine)) {
        lines.push_back(tempLine);
    }
    input.close();
}