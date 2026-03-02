#include<iostream> 
using namespace std;

template<typename... Args>
auto sumAll(Args... args) {
	return (0 + ... + args);
}

auto sumAllRecursive() {
	return 0;
}

template<typename T, typename... Args>
auto sumAllRecursive(T first, Args... args) {
	return sumAllRecursive(args...) + first;
}


int main() {
	cout << sumAll(2, 3.5) << endl;
	cout << sumAllRecursive(2, 3.5) << endl;
}
