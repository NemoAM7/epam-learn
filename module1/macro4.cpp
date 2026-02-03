//env.h
#ifndef ENV_H
#define ENV_H

#include<iostream>

//If DEV env is defined
#if defined(DEV)
#define API_URL "http://localhost"

//Elif TEST is defined
#elif defined(TEST)
#define API_URL "http://test-server"

//Else assume PROD
#else
#define API_URL "http://prod-server"

#endif

#endif // ENV_H

inline void getUrl() {
	std::cout << API_URL << std::endl;
}

