#include "../exercise.h"
#include <vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    std::vector<bool> vec(100, true); // Initialize vector with 100 elements, all set to true
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");
    ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value."); // Size of the vector object
    {
        vec[20] = false;
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`.");
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`");
        ref = false;
        ASSERT(!ref, "Fill in `ref` or `!ref`");
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`.");
    }
    return 0;
}
