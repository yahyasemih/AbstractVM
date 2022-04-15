//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#include "ArithmeticException.hpp"

ArithmeticException::ArithmeticException(std::string const &message) : domain_error(message) {
}

const char *ArithmeticException::what() const noexcept {
    return domain_error::what();
}
