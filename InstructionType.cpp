//
// Created by Yahya Ez-zainabi on 4/13/22.
//

#include "InstructionType.hpp"
#include "exceptions/InvalidInstructionException.hpp"
#include "exceptions/InvalidStackStateException.hpp"
#include "exceptions/AssertionErrorException.hpp"
#include "exceptions/ArithmeticException.hpp"

InstructionType::InstructionType() = default;

InstructionType::InstructionType(eInstruction type, IOperand *operand) : type(type), operand(operand), st(nullptr) {
    if (type == InvalidInstruction) {
        delete operand;
        throw InvalidInstructionException("invalid instruction");
    }
}

InstructionType::InstructionType(eInstruction instType, eOperandType opType, std::string const &str) : type(instType),
        operand(factory.createOperand(opType, str)) , st(nullptr) {
    if (type == InvalidInstruction) {
        delete operand;
        throw InvalidInstructionException("invalid instruction");
    }
}

InstructionType::InstructionType(const InstructionType &other) : type(other.type), operand(other.operand),
        st(other.st) {
    if (type == InvalidInstruction) {
        throw InvalidInstructionException("invalid instruction");
    }
}

InstructionType::~InstructionType() = default;

InstructionType &InstructionType::operator=(const InstructionType &other) {
    if (this != &other) {
        this->type = other.type;
        this->operand = other.operand;
        this->st = other.st;
    }
    return *this;
}

IOperand const *InstructionType::getOperand() const {
    return operand;
}

eInstruction InstructionType::getInstruction() const {
    return type;
}

void InstructionType::setStack(Stack<IOperand const *> *stack) {
    this->st = stack;
}

void InstructionType::execute() {
    if (type == InvalidInstruction) {
        return;
    } else {
        (this->*instructionFunctions[type])();
    }
}

void InstructionType::push() {
    st->push(operand);
}

void InstructionType::pop() {
    if (st->empty()) {
        throw InvalidStackStateException("stack empty");
    } else {
        st->pop();
    }
}

void InstructionType::dump() {
    auto it = st->rbegin();
    while (it != st->rend()) {
        const auto *op = reinterpret_cast<const class BaseOperand *>(*it);
        std::cout << op->toString() << std::endl;
        ++it;
    }
}

void InstructionType::doAssert() {
    if (st->top()->getType() != operand->getType()) {
        throw AssertionErrorException("types are different");
    } else {
        const auto *top = reinterpret_cast<const class BaseOperand *>(st->top());
        const auto *op = reinterpret_cast<const class BaseOperand *>(operand);
        if (top->getValue() != op->getValue()) {
            std::string str = op->toString();
            delete operand;
            throw AssertionErrorException(top->toString() + " != " + str);
        }
        delete operand;
    }
}

void InstructionType::add() {
    if (st->size() < 2) {
        throw InvalidStackStateException("Stack has not enough element");
    }
    IOperand const *op1 = st->top();
    st->pop();
    IOperand const *op2 = st->top();
    st->pop();
    st->push(op1->operator+(*op2));
    delete op1;
    delete op2;
}

void InstructionType::sub() {
    if (st->size() < 2) {
        throw InvalidStackStateException("Stack has not enough element");
    }
    IOperand const *op1 = st->top();
    st->pop();
    IOperand const *op2 = st->top();
    st->pop();
    st->push(op1->operator-(*op2));
    delete op1;
    delete op2;
}

void InstructionType::mul() {
    if (st->size() < 2) {
        throw InvalidStackStateException("Stack has not enough element");
    }
    IOperand const *op1 = st->top();
    st->pop();
    IOperand const *op2 = st->top();
    st->pop();
    st->push(op1->operator*(*op2));
    delete op1;
    delete op2;
}

void InstructionType::div() {
    if (st->size() < 2) {
        throw InvalidStackStateException("Stack has not enough element");
    }
    IOperand const *op1 = st->top();
    st->pop();
    IOperand const *op2 = st->top();
    st->pop();
    try {
        st->push(op1->operator/(*op2));
    } catch (const ArithmeticException &e) {
        delete op1;
        delete op2;
        throw e;
    }
    delete op1;
    delete op2;
}

void InstructionType::mod() {
    if (st->size() < 2) {
        throw InvalidStackStateException("Stack has not enough element");
    }
    IOperand const *op1 = st->top();
    st->pop();
    IOperand const *op2 = st->top();
    st->pop();
    try {
        st->push(op1->operator%(*op2));
    } catch (const ArithmeticException &e) {
        delete op1;
        delete op2;
        throw e;
    }
    delete op1;
    delete op2;
}

void InstructionType::print() {
    if (st->empty() || st->top()->getType() != Int8) {
        throw InvalidStackStateException("Stack is empty or top element is not an int8");
    }
    const auto *int8 = reinterpret_cast<const class Int8 *>(st->top());
    char c = static_cast<char>(int8->getValue());
    std::cout << c;
}

void InstructionType::doExit() {
    while (!st->empty()) {
        delete st->top();
        st->pop();
    }
    exit(0);
}

void InstructionType::min() {
    if (st->empty()) {
        throw InvalidStackStateException("min requires at least one element in the stack");
    }
    double min = std::numeric_limits<double>::max();
    auto it = st->begin();
    while (it != st->end()) {
        const auto *op = reinterpret_cast<const class BaseOperand *>(*it);
        if (op->getValue() < min) {
            min = op->getValue();
        }
        ++it;
    }
    std::cout << min << std::endl;
}

void InstructionType::max() {
    if (st->empty()) {
        throw InvalidStackStateException("max requires at least one element in the stack");
    }
    double max = std::numeric_limits<double>::lowest();
    auto it = st->begin();
    while (it != st->end()) {
        const auto *op = reinterpret_cast<const class BaseOperand *>(*it);
        if (op->getValue() > max) {
            max = op->getValue();
        }
        ++it;
    }
    std::cout << max << std::endl;
}

void InstructionType::avg() {
    if (st->empty()) {
        throw InvalidStackStateException("avg requires at least one element in the stack");
    }
    double avg = 0;
    auto it = st->begin();
    while (it != st->end()) {
        const auto *op = reinterpret_cast<const class BaseOperand *>(*it);
        avg += op->getValue();
        ++it;
    }
    std::cout << avg / st->size() << std::endl;
}
