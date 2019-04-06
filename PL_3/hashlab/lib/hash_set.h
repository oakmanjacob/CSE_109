#include <linked_list.h>

class HashSet {
	public:
		HashSet(int size);
		~HashSet();
		bool contains(char* s);
		bool insert(char* s);
		bool remove(char* s);
	protected:
		LinkedList** table;
		int size;
		int hash_str(char* string);
		int hash(int prehash);
};