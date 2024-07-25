#include "../exercise.h"
#include <cstring>
#include <vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value."); // Size of the vector
        ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value."); // Size of the vector object
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // Compare data
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value."); // Size of the vector
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // Size of the vector object
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values."); // Compare data
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value."); // Size after push_back
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // Size of the vector object
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value."); // Size after pop_back
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value."); // Size of the vector object
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
        }
        {
            vec.insert(vec.begin() + 1, 1.5); // Insert 1.5 at the second position
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            vec.erase(vec.begin() + 3); // Erase the fourth element
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == vec.size(), "Fill in the correct value."); // After shrink_to_fit
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == 0, "Fill in the correct value."); // Size after clear
            ASSERT(vec.capacity() == vec.capacity(), "Fill in the correct value."); // Capacity after clear remains the same
        }
    }
    {
        std::vector<char> vec(48, 'z'); // Create vector of size 48 with all elements 'z'
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == sizeof(std::vector<char>), "Fill in the correct value.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == 16, "Fill in the correct value."); // Size after resize
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier."); // Capacity remains the same after resize
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == 16, "Fill in the correct value."); // Size remains the same
            ASSERT(vec.capacity() == 256, "Fill in the correct value."); // Capacity after reserve
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value."); // Size after push_backs
            ASSERT(vec.capacity() == 256, "Fill in the correct value."); // Capacity remains the same
            ASSERT(vec[15] == 'z', "Fill in the correct value."); // 16th element (index 15) is 'z'
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}

