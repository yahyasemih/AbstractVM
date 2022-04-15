//
// Created by Yahya Ez-zainabi on 4/11/22.
//

#include <readline/readline.h>
#include <readline/history.h>
#include <iostream>
#include "Stack.hpp"
#include "Parser.hpp"
#include "exceptions/InvalidNumberException.hpp"
#include "exceptions/OutOfRangeException.hpp"
#include "exceptions/ArithmeticException.hpp"
#include "exceptions/AssertionErrorException.hpp"
#include "exceptions/InvalidStackStateException.hpp"
#include "exceptions/InvalidInstructionException.hpp"

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) {
            std::cerr << "Error while opening file " << argv[1] << std::endl;
            return 1;
        }
    }

    Stack<const IOperand *> st;
    std::vector<InstructionType> instructions;
    bool hasErrors = false;
    try {
        Parser p;
        std::string line;
        char *l = nullptr;

        while ((l = readline("> ")) != nullptr) {
            line = l;
            if (*l) {
                add_history(l);
            }
            free(l);
            if (line == ";;") {
                if (argc == 1)
                    break;
                else
                    continue;
            } else if (line.empty()) {
                continue;
            }
            try {
                auto instruction = p.parse(line);
                if (instruction.getInstruction() == InvalidInstruction) {
                    throw InvalidInstructionException("invalid instruction");
                } else if (instruction.getInstruction() == eInstruction::Empty) {
                    continue;
                }
                instruction.setStack(&st);
                instructions.emplace_back(instruction);
            } catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
                hasErrors = true;
            }
        }
        if (!hasErrors) {
            for (auto &i : instructions) {
                i.execute();
            }
            while (!st.empty()) {
                delete st.top();
                st.pop();
            }
            throw InvalidInstructionException("exit instruction not found");
        } else {
            for (auto &i : instructions) {
                delete i.getOperand();
            }
        }
    } catch (const SyntaxErrorException &e) {
        std::cerr << "Syntax error: " << e.what() << std::endl;
    } catch (const InvalidNumberException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const OutOfRangeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const ArithmeticException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const AssertionErrorException &e) {
        std::cerr << "Assertion failed: " << e.what() << std::endl;
    } catch (const InvalidInstructionException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const InvalidStackStateException &e) {
        std::cerr << "Stack error: " << e.what() << std::endl;
    }
    while (!st.empty()) {
        delete st.top();
        st.pop();
    }
    return 0;
}
