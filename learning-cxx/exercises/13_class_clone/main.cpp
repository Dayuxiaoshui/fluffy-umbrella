#include "../exercise.h"

// READ: 析构函数 https://zh.cppreference.com/w/cpp/language/destructor

/// @brief 任意缓存容量的斐波那契类型。
/// @details 可以在构造时传入缓存容量，因此需要动态分配缓存空间。
class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // 动态设置容量的构造器
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(0) {}

    // 析构器，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 缓存优化斐波那契计算
    size_t get(int i) {
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

    // 禁止复制构造
    DynFibonacci(DynFibonacci const &other) = delete;

    // 实现移动构造函数
    DynFibonacci(DynFibonacci &&other) noexcept
        : cache(other.cache), cached(other.cached) {
        other.cache = nullptr; // 确保资源转移后原对象不再拥有
        other.cached = 0;
    }

    // 实现移动赋值运算符
    DynFibonacci& operator=(DynFibonacci &&other) noexcept {
        if (this != &other) {
            delete[] cache; // 释放当前对象资源
            cache = other.cache; // 转移资源所有权
            cached = other.cached;
            other.cache = nullptr; // 确保资源转移后原对象不再拥有
            other.cached = 0;
        }
        return *this;
    }

    // 注意：不要修改这个方法
    // 名字相同参数也相同，但 const 修饰不同的方法是一对重载方法，可以同时存在
    // 本质上，方法是隐藏了 this 参数的函数
    // const 修饰作用在 this 上，因此它们实际上参数不同
    size_t get(int i) const {
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = std::move(fib); // 移动语义示例
    ASSERT(fib_.get(10) == 55, "Object cloned");
    return 0;
}



