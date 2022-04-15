//
// Created by Yahya Ez-zainabi on 4/12/22.
//

#ifndef ABSTRACTVM_INT16_HPP
#define ABSTRACTVM_INT16_HPP

#include "BaseOperand.hpp"

class Int16 : public BaseOperand {
public:
    explicit Int16(const std::string &strValue);
    virtual ~Int16();
    virtual eOperandType getType() const override;
};

#endif //ABSTRACTVM_INT8_HPP
