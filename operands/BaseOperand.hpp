//
// Created by Yahya Ez-zainabi on 4/13/22.
//

#ifndef ABSTRACTVM_BASEOPERAND_HPP
#define ABSTRACTVM_BASEOPERAND_HPP

#include "IOperand.hpp"

class BaseOperand : public IOperand {
private:
    bool support_bitwise() const;
protected:
    double value;
    std::string str_representation;
public:
    BaseOperand();
    BaseOperand(const BaseOperand &other);
    virtual ~BaseOperand();

    BaseOperand &operator=(const BaseOperand &other);

    virtual double getValue() const;
    virtual int getPrecision() const override;
    virtual eOperandType getType() const override = 0;

    IOperand const *operator+(IOperand const &rhs) const override;
    IOperand const *operator-(IOperand const &rhs) const override;
    IOperand const *operator*(IOperand const &rhs) const override;
    IOperand const *operator/(IOperand const &rhs) const override;
    IOperand const *operator%(IOperand const &rhs) const override;
    IOperand const *operator&(IOperand const &rhs) const override;
    IOperand const *operator|(IOperand const &rhs) const override;
    IOperand const *operator^(IOperand const &rhs) const override;
    virtual std::string const &toString() const override;
};

#endif //ABSTRACTVM_BASEOPERAND_HPP
