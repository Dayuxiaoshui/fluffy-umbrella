#include "../exercise.h"


struct Fibonacci {
    int numbers[11];

    // 修改方法签名和实现，使测试通过
    int get(int i) const {
        return numbers[i];
    }
};

int main(int argc, char **argv) {
    // 初始化一个 Fibonacci 对象，constexpr 保证在编译时计算常量表达式
    constexpr Fibonacci FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    
    // 验证斐波那契计算结果是否正确
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;

    return 0;
}
