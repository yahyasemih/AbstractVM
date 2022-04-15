//
// Created by Yahya Ez-zainabi on 4/12/22.
//

#include <iostream>
#include "Int32.hpp"
#include "../exceptions/OutOfRangeException.hpp"
#include "../exceptions/InvalidNumberException.hpp"

Int32::Int32(const std::string &strValue) {
    // TODO: throw custom exception
    size_t idx = 0;
    try {
        int int_value = std::stoi(strValue, &idx);
        if (idx != 0 && idx != strValue.size()) {
            throw InvalidNumberException("not a valid number: " + strValue);
        }
        else if (int_value < INT32_MIN || int_value > INT32_MAX) {
            throw OutOfRangeException("value `" + strValue + "' out of range");
        }
        value = static_cast<int32_t>(int_value);
        str_representation = std::to_string(int_value);
    } catch (const std::invalid_argument &e) {
        throw InvalidNumberException(e.what());
    } catch (const std::out_of_range &e) {
        throw OutOfRangeException(e.what());
    }
}

eOperandType Int32::getType() const {
    return eOperandType::Int32;
}

