//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#ifndef ABSTRACTVM_FLOAT_HPP
#define ABSTRACTVM_FLOAT_HPP


#include "BaseOperand.hpp"

class Float : public BaseOperand {
public:
    explicit Float(const std::string &strValue);
    virtual ~Float();
    eOperandType getType() const override;
};

#endif //ABSTRACTVM_FLOAT_HPP
