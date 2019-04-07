#include <linked_list.h>

class HashSet {
	public:
		HashSet(int size);
		~HashSet();
		bool contains(const char* s);
		bool insert(const char* s);
		bool remove(const char* s);
	protected:
		LinkedList** table;
		int size;
		int hash_str(const char* s);
		int hash(int prehash);
};