#include <iostream>
#include "../exercise.h"
// READ: 析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>

/// @brief 任意缓存容量的斐波那契类型。
/// @details 可以在构造时传入缓存容量，因此需要动态分配缓存空间。
class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // 动态设置容量的构造函数
    DynFibonacci(int capacity) : cache(new size_t[capacity]), cached(0) {
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < capacity; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        cached = capacity; // 初始缓存长度为 capacity
    }

    // 析构函数，释放缓存空间
    ~DynFibonacci() {
        delete[] cache;
    }

    // 获取斐波那契数列第 i 个数的方法
    size_t get(int i) {
        // 如果需要计算的索引 i 超出了当前缓存的长度，需要扩展缓存
        for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12); // 初始化容量为 12 的 DynFibonacci 对象
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
