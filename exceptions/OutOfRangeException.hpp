//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#ifndef ABSTRACTVM_OUTOFRANGEEXCEPTION_HPP
#define ABSTRACTVM_OUTOFRANGEEXCEPTION_HPP

#include <string>

class OutOfRangeException : public std::out_of_range {
public:
    explicit OutOfRangeException(std::string const &message);

    const char* what() const noexcept override;
};

#endif //ABSTRACTVM_OUTOFRANGEEXCEPTION_HPP
