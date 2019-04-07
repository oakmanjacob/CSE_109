#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <fstream>
#include "hash_set.h"
#include "linked_list.h"

#define filename "names.txt"

using namespace std;

void import_lines(HashSet *set, int numNames)
{
	ifstream file;
	file.open(filename);
	string name = "";
	const char* cname = NULL;
	int i = 0;

	if (file.is_open())
	{
		cout << "Opened File" << endl;
		while (i < numNames && getline(file, name, '\n'))
		{
			cname = name.c_str();
			cout << cname << endl;
			set->insert(cname);
			i++;
		}

	}
	else
	{
		cout << "Could not read file: " << filename << "." << endl;
		exit(0);
	}
}

void test_set()
{

}

int main() {

	cout << filename << endl;
    HashSet *set1 = new HashSet(10);
    HashSet *set2 = new HashSet(100);
    HashSet *set3 = new HashSet(1000);

	import_lines(set1, 1000);

	delete set1;
	delete set2;
	delete set3;
}