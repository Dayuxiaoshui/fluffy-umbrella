#include "../exercise.h"

static unsigned long long fibonacci(int i) {
    // 缓存数组初始化
    static unsigned long long cache[128] = {0};
    
    // 初始值设置
    cache[0] = 0;
    cache[1] = 1;

    // 计算并缓存斐波那契数
    for (int j = 2; j <= i; ++j) {
        cache[j] = cache[j - 1] + cache[j - 2];
    }
    
    return cache[i];
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT(fibonacci(0) == 0, "fibonacci(0) should be 0");
    ASSERT(fibonacci(1) == 1, "fibonacci(1) should be 1");
    ASSERT(fibonacci(2) == 1, "fibonacci(2) should be 1");
    ASSERT(fibonacci(3) == 2, "fibonacci(3) should be 2");
    ASSERT(fibonacci(10) == 55, "fibonacci(10) should be 55");

    auto fib100 = fibonacci(100);
    std::cout << "fibonacci(100) = " << fib100 << std::endl;
    ASSERT(fib100 == 3736710778780434371, "fibonacci(100) should be 3736710778780434371");
    return 0;
}
