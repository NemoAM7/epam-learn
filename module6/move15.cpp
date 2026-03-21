#include <iostream>
#include <vector>
#include <string>
#include <memory>

class ModernResource {
public:
    std::vector<int> data;
    std::string name;
    std::unique_ptr<int> meta;

    ModernResource(std::string n, std::initializer_list<int> d)
        : data(d), name(std::move(n)), meta(std::make_unique<int>(123)) {
    }

    void print(const char* tag) const {
        std::cout << tag << " " << name << ":";
        for (int x : data) std::cout << " " << x;
        std::cout << " | meta=" << *meta << std::endl;
    }
};

class ManualResource {
    int* arr;
    size_t n;
public:
    ManualResource(size_t sz) : arr(new int[sz]), n(sz) { std::fill(arr, arr + n, 0); }
    ManualResource(const ManualResource& o) : arr(new int[o.n]), n(o.n) {
        std::copy(o.arr, o.arr + o.n, arr);
    }
    ManualResource& operator=(const ManualResource& o) {
        if (this != &o) {
            delete[] arr;
            n = o.n;
            arr = new int[n];
            std::copy(o.arr, o.arr + n, arr);
        }
        return *this;
    }
    ManualResource(ManualResource&& o) noexcept : arr(o.arr), n(o.n) {
        o.arr = nullptr; o.n = 0;
    }
    ManualResource& operator=(ManualResource&& o) noexcept {
        if (this != &o) {
            delete[] arr;
            arr = o.arr; n = o.n; o.arr = nullptr; o.n = 0;
        }
        return *this;
    }
    ~ManualResource() { delete[] arr; }
};


int main() {
    ModernResource m1("first", { 1,2,3 });
    ModernResource m2 = m1;           // copy
    ModernResource m3("third", { 3,4 });
    m3 = std::move(m1);               // move
    m2.print("m2:");
    m3.print("m3:");
    // No leaks, safe operations, no custom copy/move/dtor code needed!
    return 0;
}
