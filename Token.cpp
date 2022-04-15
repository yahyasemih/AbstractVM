//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#include "Token.hpp"

#include <utility>

Token::Token() : type(eTokenType::InvalidToken), value() {
}

Token::Token(const Token &t) = default;

Token::Token(eTokenType type, std::string value) : type(type), value(std::move(value)) {
}

Token::Token(eTokenType type) : type(type), value() {
}

Token &Token::operator=(const Token &t) = default;

eTokenType Token::getType() const {
    return type;
}

const std::string &Token::getValue() const {
    return value;
}

bool Token::isExpected(const Token &t) const {
    switch (getType()) {
        case Start:
            return t.getType() == KeyWord;
        case KeyWord:
            return t.getType() == Operand
                || t.getType() == End;
        case Operand:
            return t.getType() == IntegerValue
                || t.getType() == DecimalValue;
        case DecimalValue:
        case IntegerValue:
            return t.getType() == End;
        default:
            return false;
    }
}
