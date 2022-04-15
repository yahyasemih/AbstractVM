//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#ifndef ABSTRACTVM_TOKEN_HPP
#define ABSTRACTVM_TOKEN_HPP

#include "AbstractVM.hpp"

#include <string>

class Token {
private:
    eTokenType type;
    std::string value;
public:
    Token();
    Token(const Token &t);
    Token(eTokenType type, std::string value);
    explicit Token(eTokenType type);
    ~Token() = default;

    Token &operator=(const Token &t);

    eTokenType getType() const;
    const std::string &getValue() const;
    bool isExpected(const Token &t) const;
};

#endif //ABSTRACTVM_TOKEN_HPP
