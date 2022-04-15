//
// Created by Yahya Ez-zainabi on 4/13/22.
//

#include <iostream>
#include <cmath>
#include "BaseOperand.hpp"
#include "OperandFactory.hpp"
#include "../exceptions/ArithmeticException.hpp"

BaseOperand::BaseOperand() = default;

BaseOperand::BaseOperand(const BaseOperand &other) = default;

BaseOperand::~BaseOperand() = default;

BaseOperand &BaseOperand::operator=(const BaseOperand &other) = default;

double BaseOperand::getValue() const {
    return value;
}

int BaseOperand::getPrecision() const {
    return static_cast<int>(getType());
}

IOperand const *BaseOperand::operator+(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(getValue() + rhVal));
    } else {
        res = std::to_string(getValue() + rhVal);
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator-(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(getValue() - rhVal));
    } else {
        res = std::to_string(getValue() - rhVal);
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator*(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(getValue() * rhVal));
    } else {
        res = std::to_string(getValue() * rhVal);
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator/(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    if (rhVal == 0) {
        throw ArithmeticException("Division by 0");
    }
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(getValue() / rhVal));
    } else {
        res = std::to_string(getValue() / rhVal);
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator%(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    if (rhVal == 0) {
        throw ArithmeticException("Modulo by 0");
    }
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(std::fmod(getValue(), rhVal)));
    } else {
        res = std::to_string(std::fmod(getValue(), rhVal));
    }
    return factory.createOperand(opType, res);
}

std::string const &BaseOperand::toString() const {
    return str_representation;
}
