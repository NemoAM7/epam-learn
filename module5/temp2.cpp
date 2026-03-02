#include<iostream>
#include<tuple>
#include<string>
using namespace std;

template<typename... Args>
class MyTuple {
	tuple<Args...> data;
public:
	MyTuple(Args... args) : data(args...) {}

	void print() const {
		printHelper<0>();
	}

private:
	template<size_t Index>
	void printHelper() const {
		if constexpr (Index < sizeof...(Args)) {
			cout << get<Index>(data) << " ";
			printHelper<Index + 1>();
		}
	}

};

int main() {
	MyTuple<int, double, string> t(1, 2.5, "hello");
	t.print();
}