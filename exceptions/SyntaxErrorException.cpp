//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#include "SyntaxErrorException.hpp"

SyntaxErrorException::SyntaxErrorException(std::string const &message) : std::invalid_argument(message), line(0) {
}

SyntaxErrorException::SyntaxErrorException(std::string const &message, int line) : std::invalid_argument(message), line(line) {
}

SyntaxErrorException::SyntaxErrorException(int line) : std::invalid_argument("syntax error"), line(line){
}

const char *SyntaxErrorException::what() const noexcept {
    std::string str = std::invalid_argument::what();
    str += " at line: " + std::to_string(line);
    return str.c_str();
}
