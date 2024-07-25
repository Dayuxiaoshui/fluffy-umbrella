#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;
    Fibonacci() : cached(2) {
        cache[0] = 0;
        cache[1] = 1;
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
       if (i < cached) {
            return cache[i];
        }

        // 计算并缓存从已缓存的最后一个索引到第 i 个斐波那契数列值
        for (int idx = cached; idx <= i; ++idx) {
            cache[idx] = cache[idx - 1] + cache[idx - 2];
        }

        // 更新已缓存的数目
        cached = i + 1;

        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
   
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
