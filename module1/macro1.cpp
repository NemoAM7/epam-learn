#ifndef PLATFORM_H
#define PLATFORM_H

#include<iostream>

#if defined(WINDOWS)
#define OS_DETECTED "This is a windows operating system!"
#elif defined(LINUX)
#define OS_DETECTED "This is a linux operating system!"
#elif defined(MAC)
#define OS_DETECTED "This is a mac operatiendng system!"
#else
#define OS_DETECTED "Unknown OS"
#endif

inline void printOS() {
	std::cout << OS_DETECTED << std::endl;
}

#endif