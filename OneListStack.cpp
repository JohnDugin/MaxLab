#include "OneListStack.h"


void OneListStack::pushStack(const ValueType &value) {
    this->pushFront(value);
}

void OneListStack::popStack() {
    this->removeFront();
}

const ValueType &OneListStack::topStack() const {
    return getNode(0)->value;
}

// проверка на пустоту
bool OneListStack::isEmptyStack() const {
    return (this->size() == 0) ? true : false;
}

// размер
size_t OneListStack::sizeStack() const {
    return this->size();
}

