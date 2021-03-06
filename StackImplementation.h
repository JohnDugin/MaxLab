#pragma once

#include <iostream>
// приходится тянуть ValueType во все места,
// наглядная демонстрация того, почему с шаблонами было бы легче.
// Ждем, когда дойдете до этого на МиСП.
using ValueType = double;

// интерфейс для конкретных реализаций контейнера для стека
class StackImplementation {
public:

    // добавление в хвост
    virtual void pushStack(const ValueType &value) = 0;

    // удаление с хвоста
    virtual void popStack() = 0;

    virtual const ValueType &topStack() const = 0;

    // проверка на пустоту
    virtual bool isEmptyStack() const = 0;

    // размер
    virtual size_t sizeStack() const = 0;

    // виртуальный деструктор
    ~StackImplementation() = default;

};
