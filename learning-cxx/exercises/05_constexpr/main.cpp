#include "../exercise.h"

constexpr unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    unsigned long long a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        unsigned long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // Correcting the code to handle larger Fibonacci numbers
    constexpr auto ANS_N = 100;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
