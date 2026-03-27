#include<iostream>

class Logger {
private:
	std::string name;
	bool isOpen;
public:
	Logger(const std::string& name): name(name), isOpen(true) {
		std::cout << "Logger '" << name << "' created" << std::endl;
	}

	void log(const std::string& msg) const {
		if (isOpen) {
			std::cout << "[" << name << "]: " << msg << std::endl;
		}
	}

	void close() {
		if (isOpen) {
			isOpen = false;
			std::cout << "Logger '" << name << "' closed" << std::endl;
		}
	}

	std::string getName() const {
		return name;
	}

	~Logger() {
		close();
		std::cout << "Logger '" << name << "' destroyed" << std::endl;
	}
};

int main() {
	std::unique_ptr<Logger> logger = std::make_unique<Logger>("Main logger");
	logger->log("Hello from main logger!");
	
	std::cout << "-------------------" << std::endl;
 	logger = std::make_unique<Logger>("Secondary logger");
	logger->log("Hello from secondary logger!");

	std::cout << "-------------------" << std::endl;
	logger.reset(new Logger("Temporary logger"));
	logger->log("I replaced the previous logger");

	std::cout << "-------------------" << std::endl;
	logger.reset();	
	std::cout << "Logger is now " << (logger ? "not null" : "nullptr") << std::endl;
	logger = nullptr;
	
	std::cout << "-------------------" << std::endl;
	logger = std::make_unique<Logger>("New logger");
	logger->log("Back in business");

	std::cout << "-------------------" << std::endl;
	auto logger2 = std::make_unique<Logger>("Logger 2");
	logger = std::move(logger2);
	logger->log("Now I own logger 2's resource");
	std::cout << "Logger2 is " << (logger2 ? "not null" : "nullptr") << std::endl;

	std::cout << "-------------------" << std::endl;
	logger = std::move(logger);
	logger->log("Self move didnt destroy me!");

	return 0;
}

