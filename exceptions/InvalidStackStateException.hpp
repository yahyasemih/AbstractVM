//
// Created by Yahya Ez-zainabi on 4/15/22.
//

#ifndef ABSTRACTVM_INVALIDSTACKSTATEEXCEPTION_HPP
#define ABSTRACTVM_INVALIDSTACKSTATEEXCEPTION_HPP

#include <stdexcept>

class InvalidStackStateException : public std::logic_error {
public:
    explicit InvalidStackStateException(std::string const &message);

    const char* what() const noexcept override;
};

#endif //ABSTRACTVM_INVALIDSTACKSTATEEXCEPTION_HPP
