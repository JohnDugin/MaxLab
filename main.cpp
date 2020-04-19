#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack s1(StackContainer::List);
    s1.pushStack(1);
    s1.pushStack(2);
    cout << s1.topStack() << "\n";
    s1.popStack();
    cout << s1.topStack() << "\n";
    s1.pushStack(2);

    Stack s3(s1);
    s3.pushStack(333);

    Stack s2;
    s2.pushStack(222);
    cout << s2.topStack() << endl;
    s2 = s1;

    s2.pushStack(222);

    int len = s1.sizeStack();
    cout << "s1: ";
    for (int i = 0; i < len; ++i) {
        cout << s1.topStack() << "  ";
        s1.popStack();
    }
    cout << endl;


    len = s2.sizeStack();
    cout << "s2: ";
    for (int i = 0; i < len; ++i) {
        cout << s2.topStack() << "  ";
        s2.popStack();
    }
    cout << endl;


    len = s3.sizeStack();
    cout << "s3: ";
    for (int i = 0; i < len; ++i) {
        cout << s3.topStack() << "  ";
        s3.popStack();
    }
    cout << endl;


    double *d = new double[10];
    for (int j = 0; j < 10; ++j) {
        d[j] = j;
    }
    Stack s4 (d, 10);

    len = s4.sizeStack();
    cout << "s4: ";
    for (int i = 0; i < len; ++i) {
        cout << s4.topStack() << "  ";
        s4.popStack();
    }
    cout << endl;

    return 0;
}
