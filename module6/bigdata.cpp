#include"bigdata.hpp"
//heavy includes here!
#include<vector>
#include<map>
#include<string>
#include<iostream>

struct BigData::Impl {
	std::vector<int> bigVector;
	std::map<std::string, int> bigMap;
	std::string name;

	Impl() {
		bigVector.resize(1'000'000, -1);
		name = "BigData resource";
		bigMap["test"] = 67;
		std::cout << "[Impl] constructed with heavy data.\n";
	}

	~Impl() {
		std::cout << "[Impl] destroyed.\n";
	}
};


BigData::BigData(): impl(std::make_unique<Impl>()) {}
BigData::~BigData() = default;

void BigData::process() {
	impl->bigVector[0]++;
	impl->bigMap["process"] = int(impl->bigVector[0]);
	std::cout << "Processing " << impl->name << ": " << impl->bigVector[0] << std::endl;
}

size_t BigData::getSize() const {
	return impl->bigVector.size();
}