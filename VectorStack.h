#pragma once

#include "StackImplementation.h"
#include "Vector.h" // меняете на include вашего вектора

// вариант с использованием ранее написанного вектора и множественного наследования
// если бы вектор не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class VectorStack : public StackImplementation, public Vector {

    void pushStack(const ValueType &value);

    // удаление с хвоста
    void popStack();


    const ValueType &topStack() const;

    // проверка на пустоту
    bool isEmptyStack() const;

    // размер
    size_t sizeStack() const;
};
