#include<iostream>
#include<memory>


class FileHandler {
private:
public:
	FileHandler() {
		std::cout << "File opened." << std::endl;
	}
	~FileHandler() {
		std::cout << "File closed." << std::endl;
	}
	void write(const std::string& message) {
		std::cout << "Writing: " << message << std::endl;
	}
};

std::unique_ptr<FileHandler> createFileHandler() {
	return std::make_unique<FileHandler>();
}

void processFileHandler(std::unique_ptr<FileHandler> filePtr) {
	filePtr->write("hey!!");
}

int main() {
	std::unique_ptr<FileHandler> filePtr = createFileHandler();
	processFileHandler(std::move(filePtr));
	filePtr->write("hii!!");

	// After std::move, filePtr is now nullptr (moved-from state)
	// Attempting to use it would cause undefined behavior or crash
	// filePtr->write("hii!!"); // This would crash - dereferencing nullptr!
	if (filePtr == nullptr) {
		std::cout << "filePtr is now nullptr after move" << std::endl;
	}
}
