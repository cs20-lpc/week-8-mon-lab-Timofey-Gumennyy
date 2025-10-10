#include <iostream>
#include "ArrayStack.hpp"
#include <string>

int main() {
    using std::cout; using std::endl;

    cout << "=== Integer stack tests ===\n";
    ArrayStack<int> a(5);
    for (int i = 1; i <= 5; ++i) a.push(i);
    cout << "Stack A (after pushes):\n" << a << endl;

    // copy constructor
    ArrayStack<int> b = a;
    cout << "Stack B (copy constructed from A):\n" << b << endl;

    // mutate A, B should remain unchanged (deep copy)
    a.pop();
    cout << "Stack A (after pop):\n" << a << endl;
    cout << "Stack B (should be unchanged):\n" << b << endl;

    // assignment operator
    ArrayStack<int> c(2);
    c = b;
    cout << "Stack C (assigned from B):\n" << c << endl;

    // clear test
    c.clear();
    cout << "Stack C (after clear): length=" << c.getLength() << ", isEmpty=" << c.isEmpty() << endl;
    cout << c << endl;

    // rotate tests
    cout << "Rotate B LEFT (move top to bottom):\n";
    b.rotate(Stack<int>::LEFT);
    cout << b << endl;

    cout << "Rotate B RIGHT (move bottom to top):\n";
    b.rotate(Stack<int>::RIGHT);
    cout << b << endl;

    // test overflow handling
    try {
        for (int i = 0; i < 7; ++i) a.push(i);
    } catch (const std::string& e) {
        cout << "Expected overflow exception: " << e << endl;
    }

    // test pop/peek exceptions
    ArrayStack<int> emptyStack(3);
    try { emptyStack.pop(); } catch (const std::string& e) { cout << "Expected pop on empty: " << e << endl; }
    try { emptyStack.peek(); } catch (const std::string& e) { cout << "Expected peek on empty: " << e << endl; }

    cout << "\n=== String stack tests ===\n";
    ArrayStack<std::string> s(4);
    s.push("apple"); s.push("banana"); s.push("cherry");
    cout << "String stack s:\n" << s << endl;

    ArrayStack<std::string> s2 = s; // copy constructor
    s.pop();
    cout << "s after pop:\n" << s << endl;
    cout << "s2 (copied before pop) should be unchanged:\n" << s2 << endl;

    cout << "\nAll tests done.\n";
    return 0;
}
