#pragma once
#ifndef DEBUG_H
#define DEBUG_H

#include<iostream>
using namespace std;

#define DEBUG

// Check if DEBUG macro is defined
#ifdef DEBUG
	// Define DEBUG_PRINT to print debug info
#define DEBUG_PRINT(x) cout << "Debug output : " << x << endl;
#else
	// Define DEBUG_PRINT to do nothing
#define DEBUG_PRINT(x) 
#endif 

#endif // DEBUG_H