//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#ifndef ABSTRACTVM_DOUBLE_HPP
#define ABSTRACTVM_DOUBLE_HPP

#include "BaseOperand.hpp"

class Double : public BaseOperand {
public:
    explicit Double(const std::string &strValue);
    virtual ~Double() = default;
    eOperandType getType() const override;
};

#endif //ABSTRACTVM_DOUBLE_HPP
