#include <cassert>
#include "Vector.h"


//КОНСТРУКТОРЫ и ДИСТРУКТОР------------------------------------------
Vector::Vector(size_t size, ResizeStrategy strategy, float coef, int delta) {
    _size = size;
    _capacity = 1;
    _data = nullptr;
    _cf = coef;
    _rStrategy = strategy;
    _delta = delta;
}

Vector::Vector(size_t size, ValueType value, ResizeStrategy strategy, float coef, int delta) {
    _cf = coef;
    _size = 0;
    _capacity = 1;
    for (int i = 0; i < size; i++)
        this->pushBack(value);
    _rStrategy = strategy;
    _delta = delta;
}

Vector::Vector(const Vector &copy) {
    _cf = copy._cf;
    delete[] _data;
    _size = 0;
    _capacity = 1;
    for (int i = 0; i < copy._size; i++)
        this->pushBack(copy[i]);
    _rStrategy = copy._rStrategy;
    _delta = copy._delta;
}

Vector &Vector::operator=(const Vector &copy) {
    _size = copy._size;
    _capacity = copy._capacity;
    _data = copy._data;
    _rStrategy = copy._rStrategy;
    _cf = copy._cf;
    _delta = copy._delta;
    return *this;
}

Vector::~Vector() {
    delete[] _data;
    _data = nullptr;
    _size = 0;
    _capacity = 0;
    _cf = 0;
    _delta = 0;
}


//функции GET--------------------------------------------------------
size_t Vector::capacity() const {
    return _capacity;
}

size_t Vector::size() const {
    return _size;
}

ValueType* Vector::begin(){
    return _data;
}

ValueType* Vector::end(){
    return _data + _size;
}

float Vector::loadFactor() {
    if ((_size / _capacity) > 1) {
        _capacity *= _cf;
        float k = _capacity * _cf;
        return k;
    } else if ((_size / _capacity) < 1 / (_cf * _cf)) {
        int a = _capacity / _cf;
        float k = _capacity / _cf;
        if (a >= _size && a != 0)
            return k;
        return _capacity;
    }
    return _capacity;
}


//перегрузка = ------------------------------------------------------
ValueType &Vector::operator[](const size_t i) const {
    return _data[i];
}

ValueType& Vector::getValue(const size_t i) const{
    return _data[i];
}


//функции PUSH и INSERT----------------------------------------------
void Vector::pushBack(const ValueType &value) {
    resize(_size + 2);
    _data[_size] = value;
    _size++;
}

void Vector::pushFront(const ValueType &value) {
    resize(_size + 2);
    int a = _data[0], b;
    for (int i = 1; i < _size + 1; i++) {
        b = _data[i];
        _data[i] = a;
        a = b;
    }
    _data[0] = value;
    _size++;
}

void Vector::insert(const size_t index, const ValueType &value) {
    if (index < 0 || index > _size)
        assert(index < 0 || index >= _size);
    else if (index == 0) {
        pushFront(value);
    } else if (index == _size) {
        pushBack(value);
    } else if (index < _size) {
        if (loadFactor())
            reserve(loadFactor());
        ValueType a1, a2;
        a1 = _data[index];
        _data[index] = value;
        for (int i = index; i < _size - 1; i++) {
            a2 = _data[i + 1];
            _data[i + 1] = a1;
            a1 = a2;
        }
        _data[_size] = a1;
        _size++;
    } else {
        pushBack(value);
    }
}

void Vector::insert(const size_t index, const Vector &vector) {
    for (int i = 0; i < vector._size; i++) {
        this->insert(index + i, vector[i]);
    }
}


//POP BACK-----------------------------------------------------------
void Vector::popBack() {
    if (_size != 0) {
        _data[_size - 1] = '\0';
        _size--;
        resize(loadFactor());
    }
}


//ERASE--------------------------------------------------------------
void Vector::erase(const size_t index) {
    if (index < 0)
        assert(index < 0);
    if (index < _size) {
        for (int i = index; i < _size; i++)
            _data[i] = _data[i + 1];
        _size--;
    }
    resize(loadFactor());
}

void Vector::erase(const size_t index, const size_t len) {
    if (index < 0)
        assert(index < 0);
    else if (index < this->_size) {
        for (int i = 0; i < len; i++) {
            erase(index);
        }
    }
}


//функция RESERVE----------------------------------------------------
void Vector::reserve(const size_t capacity) {
    _capacity = (_capacity == 0) ? 1 : _capacity;
    while (_capacity < capacity)
        _capacity++;
    if (_data == 0)
        _data = new ValueType[_capacity];
    else {
        ValueType *newData = new ValueType[_capacity];
        memcpy(newData, _data, _size * sizeof(ValueType));
        delete[] _data;
        _data = newData;
    }
}


//функция FIND-------------------------------------------------------
long long int Vector::find(const ValueType &value, bool isBegin) const {
    if (isBegin == true) {
        for (int i = 0; i < this->_size; i++) {
            if (this->_data[i] == value) {
                return i;
            }
        }
    } else {
        for (int i = this->_size - 1; i > 0; i--) {
            if (this->_data[i] == value) {
                return i;
            }
        }
    }
    return -1;
}


//функция RESIZE-----------------------------------------------------
void Vector::resize(const size_t size, const ValueType) {
    if (size > this->_size) {
        reserve(size);
        ValueType *new_data = new ValueType[size];
        memcpy(new_data, this->_data, size * sizeof(ValueType));
        delete[] this->_data;
        this->_data = new_data;
        for (int i = this->_size; i < size; i++) {
            _data[i] = 0;
        }
        this->_capacity = size;
    } else {
        ValueType *new_data = new ValueType[size];
        memcpy(new_data, this->_data, size * sizeof(ValueType));
        delete[] this->_data;
        this->_data = new_data;
        this->_capacity = size;
    }
}


//функция CLEAR------------------------------------------------------
void Vector::clear() {
    erase(0, this->_size);
}


//функция PRINT------------------------------------------------------
void Vector::print() {
    std::cout << "size: " << this->_size << "\n";
    std::cout << "capacity: " << this->_capacity << "\n";
    for (int i = 0; i < this->_size; i++)
        std::cout << "[" << i << "] - " << this->_data[i] << "\n";
    std::cout << "\n";
}


