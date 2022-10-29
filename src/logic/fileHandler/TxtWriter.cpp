#include <string>
#include <sstream>
#include <algorithm>

#include "TxtWriter.hpp"

TxtWriter::TxtWriter(const std::string name) : FileHandler(name, 'a') {}

TxtWriter::~TxtWriter() {}

std::string TxtWriter::getScoreString(const std::string name, const Score score) const {
    std::stringstream stream;
    stream.clear();

    stream << name << " " << score.getDestroyedTroops() << " " << score.getRemainingTroops() << " " << score.getLostTroops() << " " << score.getTotalAmountShoots() << " " << score.getHitShoots();

    return stream.str();
}

std::string TxtWriter::parsePlayerName(std::string name) const {
    std::replace(name.begin(), name.end(), ' ', PLACEHOLDERCHAR);
    return name;
}

void TxtWriter::writeResults(const MatchResults& match) {
    file << match.getId() << " ";

    std::string player1ParsedName = parsePlayerName(match.getPlayer1Name());
    std::string player2ParsedName = parsePlayerName(match.getPlayer2Name());

    file << getScoreString(player1ParsedName, match.getPlayer1Score()) << " " << getScoreString(player2ParsedName, match.getPlayer2Score()) << std::endl;
    return;
}
