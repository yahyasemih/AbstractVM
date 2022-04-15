//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#ifndef ABSTRACTVM_OPERANDFACTORY_HPP
#define ABSTRACTVM_OPERANDFACTORY_HPP

#include "IOperand.hpp"
#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"

class OperandFactory {
private:
    IOperand const *createInt8(std::string const &value) const;
    IOperand const *createInt16(std::string const &value) const;
    IOperand const *createInt32(std::string const &value) const;
    IOperand const *createFloat(std::string const &value) const;
    IOperand const *createDouble(std::string const &value) const;

    typedef IOperand const *(OperandFactory::*OperandFunction)(std::string const &value) const;

    const OperandFunction operandFunctions[6] {
        &OperandFactory::createInt8,
        &OperandFactory::createInt16,
        &OperandFactory::createInt32,
        &OperandFactory::createFloat,
        &OperandFactory::createDouble,
        nullptr
    };
public:
    IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif //ABSTRACTVM_OPERANDFACTORY_HPP
