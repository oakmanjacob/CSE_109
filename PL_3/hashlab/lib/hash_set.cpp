#include <cstdlib>
#include <hash_set.h>
#include <linked_list.h>

#define A 54059   /* a prime */
#define B 76963   /* another prime */
#define C 86969   /* yet another prime */
#define FIRSTH 37 /* also prime */

/**
 * Initialize table to size
 */
HashSet::HashSet(int size)
{
	this->table = new LinkedList*[size];

	this->size = size;
}

/**
 * Clear out the table
 */
HashSet::~HashSet()
{
	for (int i = 0; i < size; i++)
	{
		if (this->table[i] != NULL)
		{
			delete this->table[i];
		}
	}
}

/**
 * Returns true if the hash set contains the supplied key, false otherwise
 */
bool HashSet::contains(const char* s)
{
	int data = this->hash_str(s);
	int hash = this->hash(data);

	if (table[hash] != NULL)
	{
		return table[hash]->find(data) >= 0;
	}
	
	return false;
}

/**
 * Inserts the given key into the hash set. Returns true on success, false
 * otherwise
 */
bool HashSet::insert(const char* s)
{
	int data = this->hash_str(s);
	int hash = this->hash(data);

	if (!this->contains(s))
	{
		if (table[hash] == NULL)
		{
			table[hash] = new LinkedList();
		}
		
		table[hash]->insert_tail(data);
	}
	return false;
}

/**
 * Removes the given key from the hash set. Returns true on success, false
 * otherwise
 */
bool HashSet::remove(const char *s)
{
	int data = this->hash_str(s);
	int hash = this->hash(data);

	if (this->contains(s))
	{
		int index = this->table[hash]->find(data);
		this->table[hash]->remove_at_index(index);
		return true;
	}
	return false;
}

// Protected functions 

/**
 * Takes a character array and returns an integer
 */
int HashSet::hash_str(const char *s)
{
	int h = FIRSTH;
	while (*s)
	{
		h = (h * A) ^ (s[0] * B);
		s++;
	}
	return h; // or return h % C;
}

/**
 * Takes a pre-hashed integer and returns an index in the hash set
 */
int HashSet::hash(int prehash)
{
	return prehash % size;
}