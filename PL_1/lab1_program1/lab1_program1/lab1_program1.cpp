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
	string input;

	// cin << input doesn't work
	getline(cin, input);

	// Loop through the input string
	for (int i = 0; i < input.size(); i++)
	{
		// Input each character on a new line
		cout << input.substr(i, 1) << endl;
	}

	return 0;
}
