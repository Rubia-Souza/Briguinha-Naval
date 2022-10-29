#include "doctest.hpp"
#include <stdio.h>
#include <string>
#include <stdexcept>

#include "TxtReader.hpp"
#include "TxtWriter.hpp"

bool compareResults(MatchResults a, MatchResults b){
    if (a.getPlayer1Name() != b.getPlayer1Name() || a.getPlayer2Name() != b.getPlayer2Name()) return false;

    Score aPlayer1Score = b.getPlayer1Score(), aPlayer2Score = a.getPlayer2Score();
    Score bPlayer1Score = b.getPlayer1Score(), bPlayer2Score = b.getPlayer2Score();

    if (aPlayer1Score.getDestroyedTroops() != bPlayer1Score.getDestroyedTroops()) return false;
    if (aPlayer2Score.getDestroyedTroops() != bPlayer2Score.getDestroyedTroops()) return false;
    if (aPlayer1Score.getHitShoots() != bPlayer1Score.getHitShoots()) return false;
    if (aPlayer2Score.getHitShoots() != bPlayer2Score.getHitShoots()) return false;
    if (aPlayer1Score.getLostTroops() != bPlayer1Score.getLostTroops()) return false;
    if (aPlayer2Score.getLostTroops() != bPlayer2Score.getLostTroops()) return false;
    if (aPlayer1Score.getRemainingTroops() != bPlayer1Score.getRemainingTroops()) return false;
    if (aPlayer2Score.getRemainingTroops() != bPlayer2Score.getRemainingTroops()) return false;
    if (aPlayer1Score.getTotalAmountShoots() != bPlayer1Score.getTotalAmountShoots()) return false;
    if (aPlayer2Score.getTotalAmountShoots() != bPlayer2Score.getTotalAmountShoots()) return false;
    return true;
}

TEST_CASE("Open a file for writing, write and check for matching MatchResults") {
    Score score1(1,2,3,5,4), score2(6,7,8,10,9);
    MatchResults match("Jogador 1", score1, "Jogador 2", score2, "2022/07/08-12:30:22");
    TxtWriter fileWrite("teste.txt");
    fileWrite.writeResults(match);

    TxtReader fileRead("teste.txt");
    MatchResults resultFile = fileRead.getMatches()[0];

    CHECK(compareResults(resultFile, match));
    remove("teste.txt");
}

TEST_CASE("Write multiple matchresults, and search for one with a valid id") {
    std::vector<MatchResults> vector;
    for (int i=0; i<6; i++){
        vector.push_back(MatchResults("Jogador 1", Score(i, i+1, i+2, i+4, i+3), "Jogador 2", Score(i+5,i+6,i+7,i+9,i+8), std::to_string(i)));
    }

    TxtWriter writer("teste.txt");

    for(MatchResults &x : vector){
        writer.writeResults(x);
    }

    TxtReader reader("teste.txt");

    for (int i = 0; i < 6; i++) {
        CHECK(compareResults(vector[i], reader.findMatch(std::to_string(i))));
    }
    remove("teste.txt");
}

TEST_CASE("Write multiple matchresuslts, and search for one with invalid id") {
    std::vector<MatchResults> vector;
    for (int i=0; i<6; i++){
        vector.push_back(MatchResults("Jogador 1", Score(i, i+1, i+2, i+4, i+3), "Jogador 2", Score(i+5,i+6,i+7,i+9,i+8), std::to_string(i)));
    }

    TxtWriter writer("teste.txt");

    for(MatchResults &x : vector){
        writer.writeResults(x);
    }

    TxtReader reader("teste.txt");

    CHECK_THROWS_AS(reader.findMatch("aaa"), std::invalid_argument);

    remove("teste.txt");
}