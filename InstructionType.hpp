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
    IOperand const *operand{};
    Stack<IOperand const *> *st{};

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
    void min();
    void max();
    void avg();
    void dup();
    void clear();
    void str();

    typedef void (InstructionType::*InstructionFunction)();

    const InstructionFunction instructionFunctions[18] {
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
            &InstructionType::min,
            &InstructionType::max,
            &InstructionType::avg,
            &InstructionType::dup,
            &InstructionType::clear,
            &InstructionType::str,
            nullptr
    };
public:
    InstructionType();
    InstructionType(eInstruction type, IOperand *operand);
    InstructionType(eInstruction instType, eOperandType opType, const std::string &str);
    InstructionType(const InstructionType &other);
    ~InstructionType();

    InstructionType &operator=(const InstructionType &other);

    eInstruction getInstruction() const;
    IOperand const *getOperand() const;
    void setStack(Stack<IOperand const *> *stack);
    void execute();
};

#endif //ABSTRACTVM_INSTRUCTIONTYPE_HPP
