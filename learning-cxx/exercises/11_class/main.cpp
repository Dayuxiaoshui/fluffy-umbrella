#include "../exercise.h"
class Fibonacci {
    size_t cache[16];
    int cached;

public:
    // 构造函数，用于初始化缓存数组和计数器
    Fibonacci() : cached(0) {
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < 16; ++i) {
            cache[i] = cache[i - 1] + cache[i - 2];
        }
        cached = 16; // 初始缓存长度为 16
    }

    // 获取斐波那契数列第 i 个数的方法
    size_t get(int i) {
        // 如果需要计算的索引 i 超出了当前缓存的长度，需要扩展缓存
        for (; cached <= i; ++cached) {
            if (cached >= 16) {
                std::cerr << "Error: Fibonacci number out of cache bounds." << std::endl;
                break;
            }
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}

