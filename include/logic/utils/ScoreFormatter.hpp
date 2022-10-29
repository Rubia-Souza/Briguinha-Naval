#ifndef SCORE_FORMATTER_HPP
#define SCORE_FORMATTER_HPP

#include <string>

namespace ScoreFormatter {
    /**
     * @brief Build a string combaning the label and value.
     * @param label is the score category text.
     * @param value is the value of the score category.
     * 
     * @return the built string combaning the label and value.
     */
    std::string buildLabelWithValue(const std::string label, const unsigned int value);

    /**
     * @brief Built a string combaning the label and two values in a porportion.
     * @param label is the score category text.
     * @param overValue is the numerator on the division.
     * @param underValue is the denominator on the division.
     * 
     * @return the built string combaning the label and two values in the porportion.
     */
    std::string buildProportionLabel(const std::string label, const unsigned int overValue, const unsigned int underValue);
}

#endif
