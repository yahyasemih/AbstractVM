//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#include <iostream>
#include <cmath>
#include "Double.hpp"
#include "../exceptions/InvalidNumberException.hpp"
#include "../exceptions/OutOfRangeException.hpp"

Double::~Double() = default;

Double::Double(const std::string &strValue) {
    size_t idx = 0;
    try {
        double double_value = std::stod(strValue, &idx);
        if (idx != 0 && idx != strValue.size()) {
            throw InvalidNumberException("not a valid number: " + strValue);
        }
        else if (double_value < std::numeric_limits<double>::lowest()
                 || double_value > std::numeric_limits<double>::max()) {
            throw OutOfRangeException("value `" + strValue + "' out of range");
        }
        value = double_value;
        str_representation = std::to_string(double_value);
        idx = str_representation.size() - 1;
        while (str_representation[idx] == '0' && idx > 0) {
            idx--;
        }
        if (idx != 0) {
            if (str_representation[idx] == '.') {
                idx++;
            }
            str_representation = str_representation.substr(0, idx + 1);
        }
    } catch (const std::invalid_argument &e) {
        throw InvalidNumberException(e.what());
    } catch (const std::out_of_range &e) {
        throw OutOfRangeException(e.what());
    }
}

eOperandType Double::getType() const {
    return eOperandType::Double;
}
