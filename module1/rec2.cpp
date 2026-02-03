#include<iostream>
#include<chrono>
using namespace std;

/*
 * File : StairCaseProblem.cpp
 * Author: Ayaan Mandal
 * Description : A C++ program to compute the number of way we can climb a staircase
 * with N total steps given that we can climb either 1 or 2 stair at one time.
*/


int g_fib[100];

// Uses memoized recursion to compute totalSteps in O(n)
int stairCaseCounter(int totalSteps) {
	if (totalSteps < 0) return 0;
	if (g_fib[totalSteps] == 0) {
		g_fib[totalSteps] = stairCaseCounter(totalSteps - 1) + stairCaseCounter(totalSteps - 2);
	}
	return g_fib[totalSteps];

}


int main() {
	//base case initialization
	g_fib[0] = 1;
	g_fib[1] = 1;

	int totalSteps;
	cout << "How many steps are there? : ";
	cin >> totalSteps;
	cout << "There are  " << stairCaseCounter(totalSteps) << " paths available.\n";

	// Performance analysis
	auto start = chrono::high_resolution_clock::now(); // timestamp before function execution
	cout << stairCaseCounter(totalSteps) << endl; // execute function
	auto end = chrono::high_resolution_clock::now(); // timestamp after function execution
	cout << duration_cast<std::chrono::nanoseconds>(end - start).count() << " ns\n"; // difference to compute the runtime

}