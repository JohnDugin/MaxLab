#include "VectorStack.h"

void VectorStack::pushStack(const ValueType &value) {
    this->pushFront(value);
}

void VectorStack::popStack() {
    this->erase(0);
}

const ValueType &VectorStack::topStack() const {
    return this->getValue(0);
}

// проверка на пустоту
bool VectorStack::isEmptyStack() const {
    return (this->size() == 0) ? true : false;
}

// размер
size_t VectorStack::sizeStack() const {
    return this->size();
}
