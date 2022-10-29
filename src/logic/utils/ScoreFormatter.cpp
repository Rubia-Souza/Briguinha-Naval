#include <string>
#include <sstream>

#include "ScoreFormatter.hpp"

std::string ScoreFormatter::buildLabelWithValue(const std::string label, const unsigned int value) {
    std::stringstream labelWithValue;
    labelWithValue.clear();
    labelWithValue << label << std::to_string(value);

    return labelWithValue.str();
}

std::string ScoreFormatter::buildProportionLabel(const std::string label, const unsigned int overValue, const unsigned int underValue) {
    std::stringstream labelWithValue;
    labelWithValue.clear();
    labelWithValue << label <<  std::to_string(overValue) << "/" << std::to_string(underValue);

    return labelWithValue.str();
}
