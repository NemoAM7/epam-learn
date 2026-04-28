#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<iomanip>
#include<chrono>
#include<functional>

using namespace std;

const int NUM_WORDS = 100000;
const int NUM_LOOKUP_TESTS = 10000;
const int NUM_NONEXISTENT_WORDS = 10000;

using WordVector = vector<string>;
using MilliSeconds = std::chrono::duration<double, std::milli>;

template<typename Func>
double measureTime(const std::string& description, Func func) {
	auto start = std::chrono::high_resolution_clock::now();
	func();
	auto end = std::chrono::high_resolution_clock::now();
	MilliSeconds duration_ms = end - start;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << " " << std::left << std::setw(35) << description + ":" << duration_ms.count() << " ms" << std::endl;
	return duration_ms.count();
}

WordVector generateWords(int count, const std::string& prefix) {
	WordVector words;
	words.reserve(count);
	for (int i = 0; i < count; ++i) {
		words.push_back(prefix + std::to_string(i));
	}
	return words;
}

template<typename MapType>
void conditionallyReserve(MapType& map, size_t count) {
	if constexpr (is_same_v<MapType, unordered_map<string, int>>) {
		map.reserve(count);
		std::cout << " (Reserved " << count << " buckets for unordered_map)" << std::endl;
	}
}

template<typename MapType>
void benchmarkContainer(const string& container_name, const WordVector& words_to_insert, const WordVector& non_existent_words) {
	MapType my_container;
	conditionallyReserve(my_container, words_to_insert.size());

	cout << "Benchmarking: " << container_name << endl;

	measureTime("Insertion", [&]() {
		for (int i = 0; i < words_to_insert.size(); ++i) {
			my_container[words_to_insert[i]] = i;
		}
		});

	volatile int found_count = 0;
	measureTime("Lookup (Existing Keys)", [&]() {
		for (int i = 0; i < NUM_LOOKUP_TESTS; ++i) {
			auto it = my_container.find(words_to_insert[i]);
			if (it != my_container.end()) {
				found_count++;
			}
		}
		});

	volatile int not_found_count = 0;
	measureTime("Lookup (Non-Existing Keys)", [&]() {
		for (int i = 0; i < NUM_NONEXISTENT_WORDS; ++i) {
			auto it = my_container.find(non_existent_words[i]);
			if (it == my_container.end()) {
				not_found_count++;
			}
		}
		});

	cout << "Final size: " << my_container.size() << endl;
}

int main() {
	cout << "Benchmarking maps" << endl;
	std::cout << "Generating " << NUM_WORDS << " unique words..." << std::endl;
	WordVector words_to_insert = generateWords(NUM_WORDS, "word_");


	std::cout << "Generating " << NUM_WORDS << " non-existent unique words..." << std::endl;
	WordVector nonexistent_words = generateWords(NUM_WORDS, "non-existent-word_");

	benchmarkContainer<map<string, int>>("std::map", words_to_insert, nonexistent_words);
	benchmarkContainer<unordered_map<string, int>>("std::unordered_map", words_to_insert, nonexistent_words);

	cout << "Thanks!" << endl;
}


