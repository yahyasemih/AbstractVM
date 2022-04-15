//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#ifndef ABSTRACTVM_ARITHMETICEXCEPTION_HPP
#define ABSTRACTVM_ARITHMETICEXCEPTION_HPP

#include <stdexcept>

class ArithmeticException : public std::domain_error {
public:
    explicit ArithmeticException(std::string const &message);

    const char* what() const noexcept override;
};

#endif //ABSTRACTVM_ARITHMETICEXCEPTION_HPP
