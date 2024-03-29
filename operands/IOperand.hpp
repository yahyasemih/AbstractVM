//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#ifndef ABSTRACTVM_IOPERAND_HPP
#define ABSTRACTVM_IOPERAND_HPP

#include <string>

#include "../AbstractVM.hpp"

class IOperand {
public:
    virtual int getPrecision() const = 0; // Precision of the type of the instance
    virtual eOperandType getType() const = 0; // Type of the instance
    virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
    virtual IOperand const *operator-(IOperand const &rhs) const = 0; // Difference
    virtual IOperand const *operator*(IOperand const &rhs) const = 0; // Product
    virtual IOperand const *operator/(IOperand const &rhs) const = 0; // Quotient
    virtual IOperand const *operator%(IOperand const &rhs) const = 0; // Modulo
    virtual IOperand const *operator&(IOperand const &rhs) const = 0; // And
    virtual IOperand const *operator|(IOperand const &rhs) const = 0; // Or
    virtual IOperand const *operator^(IOperand const &rhs) const = 0; // Xor
    virtual std::string const &toString() const = 0; // String representation of the instance
    virtual ~IOperand() = default;
};

#endif //ABSTRACTVM_IOPERAND_HPP
