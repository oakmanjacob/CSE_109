#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <fstream>
#include <unistd.h>
#include "hash_set.h"
#include "linked_list.h"

#define filename "names.txt"

using namespace std;

void import_lines(HashSet *set, int numNames)
{
	ifstream file;
	file.open(filename, ios::in);
	string name = "";
	char* cname = NULL;


	if (!file.is_open())
	{
		for (int i = 0; i < numNames; i++)
		{
			if (getline(file, name)){
				cout << "'" << name << "'" <<  endl;
				strcpy(cname, name.c_str());
				set->insert(cname);
			}
			else
			{
				cout << "Could not read any more lines" << endl;
				break;
			}
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
    HashSet *set1 = new HashSet(10);
    HashSet *set2 = new HashSet(100);
    HashSet *set3 = new HashSet(1000);

	import_lines(set1, 1000);

	delete set1;
	delete set2;
	delete set3;
}