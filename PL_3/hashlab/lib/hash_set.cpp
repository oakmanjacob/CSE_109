#include <cstdlib>
#include <iostream>
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
bool HashSet::contains(int key)
{
	int hash = this->hash(key);

	if (table[hash] != NULL)
	{
		return table[hash]->find(key) >= 0;
	}
	
	return false;
}

/**
 * Inserts the given key into the hash set. Returns true on success, false
 * otherwise
 */
bool HashSet::insert(int key)
{
	int hash = this->hash(key);

	if (!this->contains(key))
	{
		if (table[hash] == NULL)
		{
			table[hash] = new LinkedList();
		}
		
		table[hash]->insert_tail(key);
	}
	return false;
}

/**
 * Removes the given key from the hash set. Returns true on success, false
 * otherwise
 */
bool HashSet::remove(int key)
{
	int hash = this->hash(key);

	if (this->contains(key))
	{
		int index = this->table[hash]->find(key);
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
	unsigned long h = FIRSTH;
	while (*s)
	{
		h = (h * A) ^ (s[0] * B);
		s++;
	}

	return h % INT32_MAX; // or return h % C;
}

/**
 * Takes a pre-hashed integer and returns an index in the hash set
 */
int HashSet::hash(int prehash)
{
	return prehash % size;
}