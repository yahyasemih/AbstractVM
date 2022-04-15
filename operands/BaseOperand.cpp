//
// Created by Yahya Ez-zainabi on 4/13/22.
//

#include <iostream>
#include <cmath>
#include "BaseOperand.hpp"
#include "OperandFactory.hpp"
#include "../exceptions/ArithmeticException.hpp"

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
        res = std::to_string(static_cast<int64_t >(rhVal + getValue()));
    } else {
        res = std::to_string(rhVal + getValue());
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator-(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(rhVal - getValue()));
    } else {
        res = std::to_string(rhVal - getValue());
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator*(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(rhVal * getValue()));
    } else {
        res = std::to_string(rhVal * getValue());
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator/(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    if (getValue() == 0) {
        throw ArithmeticException("Division by 0");
    }
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(rhVal / getValue()));
    } else {
        res = std::to_string(rhVal / getValue());
    }
    return factory.createOperand(opType, res);
}

IOperand const *BaseOperand::operator%(IOperand const &rhs) const {
    OperandFactory factory;
    eOperandType opType = getPrecision() >= rhs.getPrecision() ? getType() : rhs.getType();
    double rhVal = dynamic_cast<BaseOperand const &>(rhs).getValue();
    if (getValue() == 0) {
        throw ArithmeticException("Modulo by 0");
    }
    std::string res;
    if (opType != eOperandType::Double && opType != eOperandType::Float) {
        res = std::to_string(static_cast<int64_t >(std::fmod(rhVal, getValue())));
    } else {
        res = std::to_string(std::fmod(rhVal, getValue()));
    }
    return factory.createOperand(opType, res);
}

std::string const &BaseOperand::toString() const {
    return str_representation;
}
