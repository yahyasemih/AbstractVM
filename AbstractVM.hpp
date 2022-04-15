//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#ifndef ABSTRACTVM_ABSTRACTVM_HPP
#define ABSTRACTVM_ABSTRACTVM_HPP

enum eInstruction {
    Push,
    Pop,
    Dump,
    Assert,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    Print,
    Exit,
    Min,
    Max,
    Avg,
    Empty,
    InvalidInstruction
};

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    InvalidType
};

enum eTokenType {
    Start,
    KeyWord,
    Operand,
    IntegerValue,
    DecimalValue,
    End,
    InvalidToken
};

#endif //ABSTRACTVM_ABSTRACTVM_HPP
