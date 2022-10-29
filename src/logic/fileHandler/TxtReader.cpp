#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "TxtReader.hpp"

//TODO - ADD EXCEPTIONS FOR INCORRECT FILES

TxtReader::TxtReader(const std::string nome) : FileHandler(nome, 'r') {}

TxtReader::~TxtReader() {}

void TxtReader::resetFile() {
    file.clear();
    file.seekg(0);

    return;
}

MatchResults TxtReader::strToMatchResult(const std::string line) const {
    std::stringstream stream(line);
    std::string id = "", player1Name = "", player2Name = "";
    unsigned int player1Values[5], player2Values[5];

    stream >> id;
    stream >> player1Name;

    for(int i=0; i < 5; i++) {
        stream >> player1Values[i];
    }

    stream >> player2Name;

    for(int i=0; i < 5; i++) {
        stream >> player2Values[i];
    }

    Score player1Score(player1Values[0], player1Values[1], player1Values[2], player1Values[3], player1Values[4]);
    Score player2Score(player2Values[0], player2Values[1], player2Values[2], player2Values[3], player2Values[4]);

    return MatchResults(unparseName(player1Name), player1Score, unparseName(player2Name), player2Score, id);
}

std::string TxtReader::unparseName(std::string name) const {
    std::replace(name.begin(), name.end(), PLACEHOLDERCHAR, ' ');
    return name;
}

MatchResults TxtReader::findMatch(const std::string id) {
    resetFile();
    
    std::string line = "";
    while(std::getline(file, line)){
        std::stringstream stream(line);
        std::string _id;
        stream >> _id;

        if(id == _id){
            return strToMatchResult(line);
        }
    }

    throw std::invalid_argument("No matching date and time found");
}

#pragma region .: Gets-Sets :.

std::vector<MatchResults> TxtReader::getMatches() {
    std::vector<MatchResults> matchVector;
    resetFile();

    std::string line = "";
    while(std::getline(file, line)){
        matchVector.push_back(strToMatchResult(line));
    }

    return matchVector;
}

#pragma endregion
