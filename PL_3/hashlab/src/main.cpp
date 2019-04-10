#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <chrono>
#include <fstream>
#include "hash_set.h"
#include "linked_list.h"

#define A 54059   /* a prime */
#define B 76963   /* another prime */
#define C 86969   /* yet another prime */
#define FIRSTH 37 /* also prime */

using namespace std;

/**
 * Convert a character array into an integer representation 
 */
int hash_str(const char *s)
{
	unsigned long h = FIRSTH;
	while (*s)
	{
		h = (h * A) ^ (s[0] * B);
		s++;
	}

	return h % __INT32_MAX__; // or return h % C;
}

/**
 * Overload Method for inserting into the HashLab
 * Uses the insert_tail method because it is O(n)
 */
void import_names(HashSet *set, int *names, unsigned int numNames)
{
	int counter = 0;
	for (unsigned int i = 0; i < numNames; i++)
	{
		if (set->insert(names[i]))
		{
			counter++;
		}
	}
}

/**
 * Overload Method for inserting into the LinkedList
 * Uses the insert_tail method because it is O(n)
 */
void import_names(LinkedList *list, int *names, unsigned int numNames)
{
	int counter = 0;
	for (unsigned int i = 0; i < numNames; i++)
	{
		if (list->insert_tail(names[i]))
		{
			counter++;
		}
	}
}

void test_hashset(HashSet* set, int numValues, int* names)
{
	cout << "Testing structure with " << numValues << " values" << endl;
	chrono::duration<double> duration;
	auto start = chrono::system_clock::now();

	import_names(set, names, numValues);

	duration = chrono::system_clock::now() - start;
    cout << "Total insertion time: " << duration.count() * 1000 << "ms" << endl;

	start = chrono::system_clock::now();
	int found = 0;
	for (int i = 0; i < numValues; i++)
	{
		if (set->contains(names[i]))
		{
			found++;
		}
	}

	duration = chrono::system_clock::now() - start;
	// cout << "Found " << found << " out of " << numValues << " inserted names" << endl;
    cout << "Total find time: " << duration.count() * 1000 << "ms" << endl << endl;
}

void test_linkedlist(LinkedList* list, int numValues, int* names)
{
	cout << "Testing structure with " << numValues << " values" << endl;
	auto start = chrono::system_clock::now();
	chrono::duration<double> duration;

	import_names(list, names, numValues);

	duration = chrono::system_clock::now() - start;
    cout << "Total insertion time: " << duration.count() * 1000 << "ms" << endl;

	start = chrono::system_clock::now();
	int found = 0;
	for (int i = 0; i < numValues; i++)
	{
		if (list->find(names[i]) >= 0)
		{
			found++;
		}
	}

	duration = chrono::system_clock::now() - start;
	// cout << "Found " << found << " out of " << numValues << " inserted names" << endl;
    cout << "Total find time: " << duration.count() * 1000 << "ms" << endl << endl;
}

int main() {
	string filename = "names.txt";
	unsigned int numNames = 1000;
	int* names = new int[numNames];

	/**
	 * Read the first 1000 names from the file and store the prehashed ints
	 * in an array
	 */

	ifstream file;
	file.open(filename);
	string name = "";

	unsigned int nameCounter = 0;
	if (file.is_open())
	{
		while (nameCounter < numNames && getline(file, name))
		{
			names[nameCounter] = hash_str(name.c_str());
			nameCounter++;
		}

	}
	else
	{
		cout << "Could not read file: " << filename << "." << endl;
		exit(0);
	}

	cout << endl <<
		"   _____  _____ ______   __  ___   ___                  " 		<< endl <<
		"  / ____|/ ____|  ____| /_ |/ _ \\ / _ \\                 " 	<< endl <<
		" | |    | (___ | |__     | | | | | (_) |                " 		<< endl <<
		" | |     \\___ \\|  __|    | | | | |\\__, |                " 	<< endl <<
		" | |____ ____) | |____   | | |_| |  / /                 " 		<< endl <<
		"  ______|_____/|________ __|\\___/ _/_/                 " 		<< endl <<
		"                                                 ____  " 		<< endl <<
		" | |  | |   /\\    / ____| |  | | | |        /\\   |  _ \\ " 	<< endl <<
		" | |__| |  /  \\  | (___ | |__| | | |       /  \\  | |_) |" 	<< endl <<
		" |  __  | / /\\ \\  \\___ \\|  __  | | |      / /\\ \\ |  _ < "<< endl <<
		" | |  | |/ ____ \\ ____) | |  | | | |____ / ____ \\| |_) |" 	<< endl <<
		" |_|  |_/_/    \\_|_____/|_|  |_| |______/_/    \\_|____/ " 	<< endl <<
		"  __  __   ____  ___  ____  _______   __" 						<< endl <<
		" /  \\/  \\ / ___/  _ \\|  _ \\| ____\\ \\ / /" 				<< endl <<
		" \\      / | |  | | | | |_) |  _|  \\ V / "					<< endl <<
		"  \\    /  | |__| |_| | _ < | |___  | |  " 					<< endl <<
		"   \\ /    \\____\\ ___/|_|\\_ |_____| |_|  " 					<< endl << endl << endl;

	// Test LinkedList with 10, 100 and 1000 names
	LinkedList* list = NULL;
	cout << "--------- " << "LinkedList" << " ---------" << endl;
	for (int i = 10; i <= 1000; i *= 10)
	{
		list = new LinkedList();
		test_linkedlist(list, i, names);
		delete list;
	}

	// Test HashSets with size 10, 100, 1000
	// And 10, 100, 1000 names
	HashSet* set = NULL;
	for (int i = 10; i <= 1000; i *= 10)
	{
		cout << "--------- " << "HASHSET SIZE " << i << " ---------" << endl;
		for (int j = 10; j <= 1000; j *= 10)
		{
			set = new HashSet(i);
			test_hashset(set, j, names);
			delete set;
		}
	}

}