//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#include "OperandFactory.hpp"

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
    if (type == InvalidType) {
        return nullptr;
    } else {
        return (this->*operandFunctions[type])(value);
    }
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
    return new class Int8(value);
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
    return new class Int16(value);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    return new class Int32(value);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    return new class Float(value);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
    return new class Double(value);
}
