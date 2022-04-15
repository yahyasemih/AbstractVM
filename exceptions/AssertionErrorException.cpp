//
// Created by Yahya Ez-zainabi on 4/15/22.
//

#include "AssertionErrorException.hpp"

AssertionErrorException::AssertionErrorException(std::string const &message) : logic_error(message) {

}

const char *AssertionErrorException::what() const noexcept {
    return logic_error::what();
}
