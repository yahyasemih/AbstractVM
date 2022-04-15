//
// Created by Yahya Ez-zainabi on 4/13/22.
//

#include "Parser.hpp"
#include "exceptions/InvalidNumberException.hpp"
#include "exceptions/InvalidInstructionException.hpp"

int Parser::line;

Parser::Parser() = default;

Parser::~Parser() = default;

Parser::Parser(const Parser &) = default;

Parser &Parser::operator=(const Parser &) {
    return *this;
}

std::vector<Token> Parser::tokenize(std::string const &input) {
    std::vector<Token> tokens;
    std::smatch match;

    tokens.emplace_back(Start);
    if (std::regex_match(input, match, instruction_rule)) {
        if (match.size() != 5) {
            throw InvalidInstructionException("invalid instruction `" + input + "'");
        }
        if (!match[1].str().empty()) {
            tokens.emplace_back(KeyWord, match[1]);
        }
        if (!match[2].str().empty()) {
            tokens.emplace_back(Operand, match[2]);
        }
        if (!match[4].str().empty()) {
            std::smatch m;
            std::string str = match[4].str();
            if (std::regex_match(str, m, integer_rule)) {
                tokens.emplace_back(IntegerValue, str);
            } else if (std::regex_match(str, m, decimal_rule)) {
                tokens.emplace_back(DecimalValue, str);
            } else {
                tokens.emplace_back(InvalidToken, str);
            }
        }
    } else {
        throw InvalidInstructionException("invalid instruction `" + input + "'");
    }
    tokens.emplace_back(End, "EOI");
    return tokens;
}

eInstruction Parser::getInstructionType(std::string const &str) const {
    const auto it = strToInstruction.find(str);
    if (it == strToInstruction.cend()) {
        return InvalidInstruction;
    } else {
        return it->second;
    }
}

eOperandType Parser::getOperandType(std::string const &str) const {
    const auto it = strToOperandType.find(str);
    if (it == strToOperandType.cend()) {
        return InvalidType;
    } else {
        return it->second;
    }
}

InstructionType Parser::parse(std::string const &input) {
    line++;
    size_t idx = input.find(';');
    if (idx == 0) {
        return {Empty, nullptr};
    }
    std::vector<Token> tokens = tokenize(idx == std::string::npos ? input : input.substr(0, idx));
    for (size_t i = 1; i < tokens.size(); ++i) {
        if (!tokens[i - 1].isExpected(tokens[i])) {
            throw SyntaxErrorException("unexpected Token `" + tokens[i].getValue() + "'", line);
        }
    }
    if (tokens.size() == 3) { // Start, KeyWord, End
        eInstruction instruction = getInstructionType(tokens[1].getValue());
        if (instruction == InvalidInstruction) {
            throw InvalidInstructionException("unknown instruction `" + tokens[1].getValue() + "'");
        }
        if (shouldHaveOperand(instruction)) {
            throw SyntaxErrorException("instruction should have operand", line);
        }
        return {instruction, nullptr};
    } else if (tokens.size() == 5) { // Start, KeyWord, Operand, Value, End
        eInstruction instruction = getInstructionType(tokens[1].getValue());
        if (instruction == InvalidInstruction) {
            throw SyntaxErrorException("unknown instruction `" + tokens[1].getValue() + "'", line);
        }
        eOperandType operandType = getOperandType(tokens[2].getValue());
        if (operandType == InvalidType) {
            throw SyntaxErrorException("unknown operand `" + tokens[2].getValue() + "'", line);
        }
        if (!shouldHaveOperand(instruction)) {
            throw SyntaxErrorException("instruction should not have operand", line);
        }
        else {
            if (tokens[3].getType() == eTokenType::IntegerValue
                && (operandType == eOperandType::Float || operandType == eOperandType::Double)) {
                throw InvalidNumberException("expecting decimal number for operand " + tokens[2].getValue()
                        + ", given `" + tokens[3].getValue() + "'");
            }
            if (tokens[3].getType() == eTokenType::DecimalValue
                && (operandType != eOperandType::Float && operandType != eOperandType::Double)) {
                throw InvalidNumberException("expecting integer number for operand " + tokens[2].getValue()
                                             + ", given `" + tokens[3].getValue() + "'");
            }
        }
        return {instruction, operandType,tokens[3].getValue()};
    } else {
        throw InvalidInstructionException("invalid instruction `" + input + "'");
    }
}

bool Parser::shouldHaveOperand(eInstruction instruction) {
    return instruction == Push || instruction == Assert;
}
