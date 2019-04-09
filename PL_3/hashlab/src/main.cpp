#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <fstream>
#include "hash_set.h"
#include "linked_list.h"

#define A 54059   /* a prime */
#define B 76963   /* another prime */
#define C 86969   /* yet another prime */
#define FIRSTH 37 /* also prime */

using namespace std;

int hash_str(const char *s)
{
	unsigned long h = FIRSTH;
	while (*s)
	{
		h = (h * A) ^ (s[0] * B);
		s++;
	}

	return h % INT32_MAX; // or return h % C;
}

void import_names(HashSet *set, int *names, int numNames)
{
	for (unsigned int i = 0; i < numNames && i < sizeof(names); i++)
	{
		set->insert(names[i]);
	}
}

void import_names(LinkedList *list, int *names, int numNames)
{
	for (unsigned int i = 0; i < numNames && i < sizeof(names); i++)
	{
		list->insert_tail(names[i]);
	}
}

void read_file(string filename, int numNames, int *names)
{
	ifstream file;
	file.open(filename);
	string name = "";

	unsigned int i = 0;
	if (file.is_open())
	{
		while (i < numNames && getline(file, name, '\n'))
		{
			names[i] = hash_str(name.c_str());
			i++;
		}

	}
	else
	{
		cout << "Could not read file: " << filename << "." << endl;
		exit(0);
	}
}

int main() {
	clock_t t;
	string filename = "names.txt";
	int numNames = 1000;
	int* names = new int[numNames];

	read_file(filename, numNames, names);

	LinkedList *list = new LinkedList();
    HashSet *set1 = new HashSet(10);
    HashSet *set2 = new HashSet(100);
    HashSet *set3 = new HashSet(1000);

	t = clock();
	import_names(list, names, 1000);

	t = clock() - t;
	cout << t << endl;

	t = clock() - t;
	import_names(set1, names, 1000);

	t = clock() - t;
	cout << t << endl;

	import_names(set2, names, 1000);
	t = clock() - t;
	cout << t << endl;

	import_names(set3, names, 1000);
	t = clock() - t;
	cout << t << endl;



	delete set1;
	delete set2;
	delete set3;
}