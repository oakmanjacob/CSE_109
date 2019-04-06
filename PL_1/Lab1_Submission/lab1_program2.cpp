/*
 * Lab 1 CSE 109
 * Jacob Oakman
 * Brian Zhao
*/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string output;
	string input;

	// cin >> input wont work for detecting end of input
	getline(cin, input);
	while (input.length() > 0)
	{
		// Add each character to an output string with ... following and get next line
		output += input + "...";
		getline(cin, input);
	}
	
	// Output the output string
	cout << output << endl;

	return 0;
}
