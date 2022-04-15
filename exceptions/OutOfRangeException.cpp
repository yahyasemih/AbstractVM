//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string const &message) : std::out_of_range(message) {
}

const char *OutOfRangeException::what() const noexcept {
    return std::out_of_range::what();
}
