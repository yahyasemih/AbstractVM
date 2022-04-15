//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#ifndef ABSTRACTVM_INVALIDNUMBEREXCEPTION_HPP
#define ABSTRACTVM_INVALIDNUMBEREXCEPTION_HPP

#include <stdexcept>

class InvalidNumberException : public std::invalid_argument {
public:
    explicit InvalidNumberException(std::string const &message);

    const char* what() const noexcept override;
};

#endif //ABSTRACTVM_INVALIDNUMBEREXCEPTION_HPP
