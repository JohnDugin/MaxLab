#include "Stack.h"
#include "OneListStack.h"
#include "VectorStack.h"
#include "StackImplementation.h"

#include <stdexcept>

Stack::Stack(StackContainer container)
        : _containerType(container) {
    switch (container) {
        case StackContainer::List: {
            _pimpl = new OneListStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case StackContainer::Vector: {
            _pimpl = new VectorStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
}


Stack::Stack(const ValueType *valueArray, const size_t arraySize, StackContainer container)
        : _containerType(container) {
    // принцип тот же, что и в прошлом конструкторе
    switch (container) {
        case StackContainer::List: {
            _pimpl = new OneListStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case StackContainer::Vector: {
            _pimpl = new VectorStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }

    for (int i = arraySize - 1; i >= 0; i--)
        _pimpl->pushStack(valueArray[i]);
}


Stack::Stack(const Stack &copyStack) {
    int copyStackSize = copyStack.sizeStack();
    switch (copyStack._containerType) {
        case StackContainer::List: {
            _pimpl = new OneListStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case StackContainer::Vector: {
            _pimpl = new VectorStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    ValueType *array = new ValueType[copyStackSize];
    for (int i = copyStackSize - 1; i >= 0; i--) {
        array[i] = copyStack._pimpl->topStack();
        copyStack._pimpl->popStack();
    }
    for (int i = 0; i < copyStackSize; i++) {
        _pimpl->pushStack(array[i]);
        copyStack._pimpl->pushStack(array[i]);
    }
    delete[] array;
}


Stack &Stack::operator=(const Stack &copyStack) {
    int copyStackSize = copyStack.sizeStack();
    switch (copyStack._containerType) {
        case StackContainer::List: {
            _pimpl = new OneListStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        case StackContainer::Vector: {
            _pimpl = new VectorStack();    // конкретизируйте под ваши конструкторы, если надо
            break;
        }
        default:
            throw std::runtime_error("Неизвестный тип контейнера");
    }
    ValueType *array = new ValueType[copyStackSize];
    for (int i = copyStackSize - 1; i >= 0; i--) {
        array[i] = copyStack._pimpl->topStack();
        copyStack._pimpl->popStack();
    }
    for (int i = 0; i < copyStackSize; i++) {
        _pimpl->pushStack(array[i]);
        copyStack._pimpl->pushStack(array[i]);
    }
    delete[] array;
    return *this;
    // TODO: вставьте здесь оператор return
}


Stack::~Stack() {
    delete _pimpl;        // композиция!
}


void Stack::pushStack(const ValueType &value) {
    // можно, т.к. pushStack определен в интерфейсе
    _pimpl->pushStack(value);
}


void Stack::popStack() {
    _pimpl->popStack();
}


const ValueType &Stack::topStack() const {
    return _pimpl->topStack();
}


bool Stack::isEmptyStack() const {
    return _pimpl->isEmptyStack();
}


size_t Stack::sizeStack() const {
    return _pimpl->sizeStack();
}

