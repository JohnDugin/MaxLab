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
    Stack s2;
    s2 = s1;
    int len = s2.sizeStack();
    for (int i = 0; i < len; ++i) {
        cout << s2.topStack() << "  ";
        s2.popStack();
    }
    bool flag = s2.isEmptyStack();
    if(flag)
        cout << "true";
    else
        cout << "false";
    return 0;
}
