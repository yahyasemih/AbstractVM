//
// Created by Yahya Ez-zainabi on 4/12/22.
//

#ifndef ABSTRACTVM_Int32_HPP
#define ABSTRACTVM_Int32_HPP

#include "BaseOperand.hpp"

class Int32 : public BaseOperand {
public:
    explicit Int32(const std::string &strValue);
    virtual ~Int32();
    virtual eOperandType getType() const override;
};

#endif //ABSTRACTVM_INT8_HPP
