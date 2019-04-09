#ifndef hash_set
#define hash_set

#include <linked_list.h>

class HashSet {
	public:
		HashSet(int size);
		~HashSet();
		bool contains(int key);
		bool insert(int key);
		bool remove(int key);
	protected:
		LinkedList** table;
		int size;
		int hash_str(const char* s);
		int hash(int prehash);
};

#endif