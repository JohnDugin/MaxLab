#include <iostream>

// стратегия изменения capacity
enum class ResizeStrategy {
    Additive,
    Multiplicative
};

// тип значений в векторе
// потом будет заменен на шаблон
using ValueType = double;

class Vector {
public:
    Vector(size_t size = 0, ResizeStrategy = ResizeStrategy::Multiplicative, float coef = 1.5f, int delta = 3);
    Vector(size_t size, ValueType value, ResizeStrategy = ResizeStrategy::Multiplicative, float coef = 1.5f, int delta = 3);
    Vector(const Vector& copy); //Готово
    Vector& operator= (const Vector& copy);
    ~Vector();

    // для умненьких — реализовать конструктор и оператор для перемещения (was ist das???)

    size_t capacity() const;
    size_t size() const;
    ValueType* begin();
    ValueType* end();
    float loadFactor();

    // доступ к элементу,
    // должен работать за O(1)
    ValueType& operator[] (const size_t i) const;
    ValueType& getValue (const size_t i) const;

    // добавить в конец,
    // должен работать за amort(O(1))
    void pushBack(const ValueType& value);
    void pushFront(const ValueType& value);
    // вставить,
    // должен работать за O(n)
    void insert(const size_t i, const ValueType& value); // версия для одного значения
    void insert(const size_t i, const Vector& vector); // версия для вектора

    // удалить с конца,
    // должен работать за amort(O(1))
    void popBack();
    // удалить
    // должен работать за O(n)
    void erase( const size_t i);
    void erase(const size_t i, const size_t len); // удалить len элементов начиная с i

    // найти элемент,
    // должен работать за O(n)
    // если isBegin == true, найти индекс первого элемента, равного value, иначе последнего
    // если искомого элемента нет, вернуть -1
    long long int find(const ValueType& value, bool isBegin = true) const;

    // зарезервировать память (принудительно задать capacity)
    void reserve( const size_t capacity);

    // изменить размер
    // если новый размер больше текущего, то новые элементы забиваются дефолтными значениями
    // если меньше - обрезаем вектор
    void resize(const size_t size, const ValueType = 0.0);

    // очистка вектора, без изменения capacity
    void clear();

    void print();
private:
    ValueType* _data;
    size_t _size;
    size_t _capacity;
    float _cf;
    int _delta;
    ResizeStrategy _rStrategy;
};
