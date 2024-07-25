#include "../exercise.h"

// READ: 移动构造函数 https://zh.cppreference.com/w/cpp/language/move_constructor
// READ: 移动赋值 https://zh.cppreference.com/w/cpp/language/move_assignment
// READ: 运算符重载 https://zh.cppreference.com/w/cpp/language/operators

class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // 动态设置容量的构造器
    DynFibonacci(int capacity): cache(new size_t[capacity]), cached(0) {}

    // 复制构造器（被删除）
    DynFibonacci(DynFibonacci const &other) = delete;

    // 移动构造器（被删除）
    DynFibonacci(DynFibonacci &&other) noexcept = delete;

    // 复制赋值运算符（被删除）
    DynFibonacci &operator=(DynFibonacci const &other) = delete;

    // 移动赋值运算符（被删除）
    DynFibonacci &operator=(DynFibonacci &&other) noexcept = delete;

    // 析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 缓存优化斐波那契计算
    size_t operator[](int i) {
        for (; cached <= i; ++cached) {
            if (cached == 0) {
                cache[cached] = 0;
            } else if (cached == 1) {
                cache[cached] = 1;
            } else {
                cache[cached] = cache[cached - 1] + cache[cached - 2];
            }
        }
        return cache[i];
    }

    // 不要修改这个方法
    bool is_alive() const {
        return cache;
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    // 尝试使用移动构造和移动赋值会导致编译错误
    // DynFibonacci const fib_ = std::move(fib);
    // fib0 = std::move(fib1);

    return 0;
}
