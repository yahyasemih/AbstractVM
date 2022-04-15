//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#include <iostream>
#include "Int8.hpp"
#include "../exceptions/OutOfRangeException.hpp"
#include "../exceptions/InvalidNumberException.hpp"

Int8::~Int8() = default;

Int8::Int8(const std::string &strValue) {
    size_t idx = 0;
    try {
        int int_value = std::stoi(strValue, &idx);
        if (idx != 0 && idx != strValue.size()) {
            throw InvalidNumberException("not a valid number: " + strValue);
        }
        else if (int_value < INT8_MIN || int_value > INT8_MAX) {
            throw OutOfRangeException("value `" + strValue + "' out of range");
        }
        value = static_cast<int8_t>(int_value);
        str_representation = std::to_string(int_value);
    } catch (const std::invalid_argument &e) {
        throw InvalidNumberException(e.what());
    } catch (const std::out_of_range &e) {
        throw OutOfRangeException(e.what());
    }
}

eOperandType Int8::getType() const {
    return eOperandType::Int8;
}
