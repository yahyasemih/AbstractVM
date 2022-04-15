//
// Created by Yahya Ez-zainabi on 4/13/22.
//

#ifndef ABSTRACTVM_INSTRUCTIONTYPE_HPP
#define ABSTRACTVM_INSTRUCTIONTYPE_HPP


#include "Stack.hpp"
#include <iostream>
#include "AbstractVM.hpp"
#include "operands/IOperand.hpp"
#include "operands/OperandFactory.hpp"

class InstructionType {
private:
    OperandFactory factory;
    eInstruction type;
    IOperand const *operand;
    Stack<IOperand const *> *st;

    void push();
    void pop();
    void dump();
    void doAssert();
    void add();
    void sub();
    void mul();
    void div();
    void mod();
    void print();
    void doExit();

    typedef void (InstructionType::*InstructionFunction)();

    const InstructionFunction instructionFunctions[12] {
            &InstructionType::push,
            &InstructionType::pop,
            &InstructionType::dump,
            &InstructionType::doAssert,
            &InstructionType::add,
            &InstructionType::sub,
            &InstructionType::mul,
            &InstructionType::div,
            &InstructionType::mod,
            &InstructionType::print,
            &InstructionType::doExit,
            nullptr
    };
public:
    InstructionType(eInstruction type, IOperand *operand);
    InstructionType(eInstruction instType, eOperandType opType, const std::string &str);

    eInstruction getInstruction() const;
    void setStack(Stack<IOperand const *> *stack);
    void execute();
};

#endif //ABSTRACTVM_INSTRUCTIONTYPE_HPP
