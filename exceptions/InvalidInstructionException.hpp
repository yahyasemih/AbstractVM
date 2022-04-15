//
// Created by Yahya Ez-zainabi on 4/15/22.
//

#ifndef ABSTRACTVM_INVALIDINSTRUCTIONEXCEPTION_HPP
#define ABSTRACTVM_INVALIDINSTRUCTIONEXCEPTION_HPP

#include <stdexcept>

class InvalidInstructionException : public std::invalid_argument {
public:
    explicit InvalidInstructionException(std::string const &message);

    const char* what() const noexcept override;
};

#endif //ABSTRACTVM_INVALIDINSTRUCTIONEXCEPTION_HPP
