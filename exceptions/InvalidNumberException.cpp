//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#include "InvalidNumberException.hpp"

InvalidNumberException::InvalidNumberException(std::string const &message) : std::invalid_argument(message) {
}

const char *InvalidNumberException::what() const noexcept {
    return std::invalid_argument::what();
}
