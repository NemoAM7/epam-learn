#include<iostream>
#include<chrono>
#include<vector>
using namespace std;

class LargeArray {
    vector<int> data;
public:
    LargeArray(size_t size) : data(size, 0) {
        cout << "constructed array with " << data.size() << "elements" << endl;
    }

    LargeArray(const LargeArray& other) : data(other.data) {
        cout << "copied (deep) array with " << data.size() << "elements" << endl;
    }

    LargeArray(LargeArray&& other) noexcept : data(move(other.data)) {
        cout << "moved (shallow/efficient) array with " << data.size() << "elements" << endl;
    }
};
int main() {
    const size_t N = 10'000'000;
    LargeArray arr1(N);

    auto start = std::chrono::high_resolution_clock::now();
    LargeArray arr2 = arr1; // Copy
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: "
        << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    LargeArray arr3 = std::move(arr1); // Move
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: "
        << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    return 0;
}