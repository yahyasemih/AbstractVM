//
// Created by Yahya Ez-zainabi on 4/14/22.
//

#ifndef ABSTRACTVM_STACK_HPP
#define ABSTRACTVM_STACK_HPP

#include <stack>
#include <deque>

template<typename T>
class Stack : public std::stack<T> {
public:
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::reverse_iterator reverse_iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    reverse_iterator rbegin() {
        return this->c.rbegin();
    }

    reverse_iterator rend() {
        return this->c.rend();
    }
};

#endif //ABSTRACTVM_STACK_HPP
