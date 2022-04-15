//
// Created by Yahya Ez-zainabi on 4/15/22.
//

#include "InvalidStackStateException.hpp"

InvalidStackStateException::InvalidStackStateException(std::string const &message) : logic_error(message) {
}

const char *InvalidStackStateException::what() const noexcept {
    return logic_error::what();
}
