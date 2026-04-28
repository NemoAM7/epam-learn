#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

const int CACHE_CAPACITY = 6;

void accessCache(list<int>& cache, int value) {
	auto it = cache.begin();
	while (it != cache.end() && *it != value) ++it;
	if (it != cache.end()) cache.erase(it);
	cache.push_front(value);
	if (cache.size() > CACHE_CAPACITY) cache.pop_back();
}

void printCache(list<int>& cache) {
	for (const auto& element : cache) cout << element << " ";
	cout << endl;
}

int main() {
	std::list<int> cache;
	cout << "Enter the value access in a space seperated format. (-1 to break)" << endl;
	int v;
	while (cin >> v && v != -1) {
		accessCache(cache, v);
		printCache(cache);
	}
	return 0;
}