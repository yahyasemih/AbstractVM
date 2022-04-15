//
// Created by Yahya Ez-zainabi on 4/13/22.
//

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <map>
#include "InstructionType.hpp"
#include "Token.hpp"
#include "exceptions/SyntaxErrorException.hpp"

class Parser {
private:
    const std::regex instruction_rule{
        "^[ ]*([a-z]+)[ ]*([a-z]+[0-9]*)?[ ]*(\\([ ]*([-]?[0-9]+[.]?[0-9]*)?[ ]*\\))?[ ]*$"
    };
    const std::regex integer_rule{"^[-]?[0-9]+$"};
    const std::regex decimal_rule{"^[-]?[0-9]+.[0-9]+$"};
    const std::map<std::string, eOperandType> strToOperandType {
        {"int8", Int8},
        {"int16", Int16},
        {"short", Int16},
        {"int32", Int32},
        {"int", Int32},
        {"float", Float},
        {"double", Double}
    };
    const std::map<std::string, eInstruction> strToInstruction {
        {"push", Push},
        {"pop", Pop},
        {"dump", Dump},
        {"assert", Assert},
        {"add", Add},
        {"sub", Sub},
        {"mul", Mul},
        {"div", Div},
        {"mod", Mod},
        {"and", And},
        {"or", Or},
        {"xor", Xor},
        {"print", Print},
        {"exit", Exit},
        {"min", Min},
        {"max", Max},
        {"avg", Avg},
        {"dup", Dup},
        {"clear", Clear},
        {"str", Str}
    };
    static int line;

    std::vector<Token> tokenize(std::string const &input);
    static bool shouldHaveOperand(eInstruction instruction);
    eInstruction getInstructionType(const std::string &str) const;
    eOperandType getOperandType(const std::string &str) const;
public:
    Parser();
    Parser(const Parser &p);
    ~Parser();

    Parser &operator=(const Parser &p);

    InstructionType parse(std::string const &input);
};

#endif //ABSTRACTVM_PARSER_HPP
