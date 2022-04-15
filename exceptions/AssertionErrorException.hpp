//
// Created by Yahya Ez-zainabi on 4/15/22.
//

#ifndef ABSTRACTVM_ASSERTIONERROREXCEPTION_HPP
#define ABSTRACTVM_ASSERTIONERROREXCEPTION_HPP

#include <stdexcept>

class AssertionErrorException : public std::logic_error {
public:
    explicit AssertionErrorException(std::string const &message);

    const char* what() const noexcept override;
};

#endif //ABSTRACTVM_ASSERTIONERROREXCEPTION_HPP
