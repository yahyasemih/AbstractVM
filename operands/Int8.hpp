//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#ifndef ABSTRACTVM_INT8_HPP
#define ABSTRACTVM_INT8_HPP

#include "BaseOperand.hpp"

class Int8 : public BaseOperand {
public:
    explicit Int8(const std::string &strValue);
    virtual ~Int8();
    eOperandType getType() const override;
};

#endif //ABSTRACTVM_INT8_HPP
