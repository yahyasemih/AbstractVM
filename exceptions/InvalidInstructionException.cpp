//
// Created by Yahya Ez-zainabi on 4/15/22.
//

#include "InvalidInstructionException.hpp"

InvalidInstructionException::InvalidInstructionException(std::string const &message) : invalid_argument(message) {
}

const char *InvalidInstructionException::what() const noexcept {
    return invalid_argument::what();
}
