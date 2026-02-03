// config.h
#ifndef CONFIG_H_
#define CONFIG_H_

#include <iostream>

// Define the version number (e.g., 2, 3, or 4)
#define VERSION 2

// Check the version number using preprocessor directives
#if VERSION >= 3
#define VERSION_MSG "Stable version"
#else
#define VERSION_MSG "Beta version"
#endif

inline void printVersion() {
    std::cout << "Project Version: " << VERSION << " (" << VERSION_MSG << ")" << std::endl;
}

#endif // CONFIG_H_
