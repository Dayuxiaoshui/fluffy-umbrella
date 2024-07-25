#include <iostream>
#include "../exercise.h"

// READ: 静态字段 <https://zh.cppreference.com/w/cpp/language/static>
// READ: 虚析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>

struct A {
    static int num_a;

    A() {
        ++num_a;
    }
    virtual ~A() { // Make the destructor virtual
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};

int A::num_a = 0; // Correctly initialize the static field

struct B final : public A {
    static int num_b;

    B() {
        ++num_b;
    }
    ~B() {
        --num_b;
    }

    char name() const final {
        return 'B';
    }
};

int B::num_b = 0; // Correctly initialize the static field

int main(int argc, char **argv) {
    auto a = new A;
    auto b = new B;
    ASSERT(A::num_a == 2, "A::num_a should be 2 after creating one A and one B instance");
    ASSERT(B::num_b == 1, "B::num_b should be 1 after creating one B instance");
    ASSERT(a->name() == 'A', "a->name() should return 'A'");
    ASSERT(b->name() == 'B', "b->name() should return 'B'");

    delete a;
    delete b;
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    A *ab = new B; // 派生类指针可以随意转换为基类指针
    ASSERT(A::num_a == 1, "A::num_a should be 1 after creating one B instance via A pointer");
    ASSERT(B::num_b == 1, "B::num_b should be 1 after creating one B instance via A pointer");
    ASSERT(ab->name() == 'B', "ab->name() should return 'B'");

    // 基类指针无法随意转换为派生类指针，补全正确的转换语句
    B &bb = dynamic_cast<B&>(*ab);
    ASSERT(bb.name() == 'B', "bb.name() should return 'B'");

    delete ab; // 通过指针可以删除指向的对象，即使是多态对象
    ASSERT(A::num_a == 0, "Every A was destroyed");
    ASSERT(B::num_b == 0, "Every B was destroyed");

    return 0;
}
