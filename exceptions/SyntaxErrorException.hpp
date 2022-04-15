//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#ifndef ABSTRACTVM_SYNTAXERROREXCEPTION_HPP
#define ABSTRACTVM_SYNTAXERROREXCEPTION_HPP

#include <string>

class SyntaxErrorException : public std::invalid_argument {
private:
    int line;
public:
    explicit SyntaxErrorException(std::string const &message);
    explicit SyntaxErrorException(int line);
    SyntaxErrorException(std::string const &message, int line);

    const char* what() const noexcept override;
};

#endif //ABSTRACTVM_SYNTAXERROREXCEPTION_HPP
