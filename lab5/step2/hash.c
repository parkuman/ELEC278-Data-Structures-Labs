// HASH.C
// Program for use with ELEC278 Lab 5 Part 2.
//
// History:
// 161106	HF	First release
// 171102	DA	Minor tweaks

#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"
#include <time.h>
#include <math.h>

#define SG1 0
#define SG2 0
#define SG3 1

typedef struct HashTable
{
	LinkedList **a;
	int size;
	int collisions;
} HashTable;

HashTable *initHashTable(int s)
{
	HashTable *h = malloc(sizeof(HashTable));
	int i;
	h->size = s;
	h->a = malloc(sizeof(LinkedList) * s);
	for (i = 0; i < s; i++)
		h->a[i] = init();
	h->collisions = 0;
	return h;
} //initHashTable()

long h(char *x)
// This function computes a hash code for a given string.  Note that hash
// code is unbounded - it needs to be reduced modulo the size of the array
// used to store the data. (You will see another function hash() below that
// completes the index calculation.)
{
	long sum = 0;
	//#########################COMPLETE THIS FUNCTION##########################
	// Requirements given in lab instructions.
	// ---<SNIP>---

	int n = strlen(x);

	for (int i = 0; i < n; i++)
	{
		sum += (int)x[i] * pow(31, (n - 1 - i));
	}

	// ---<SNIP>---
	return sum;
} //h()

double loadFactor(HashTable *ht)
{
	double nonempty = 0;
	int i;
	// count number of non-empty hash table slots
	for (i = 0; i < ht->size; i++)
	{
		if (isEmpty(ht->a[i]) == 0)
			nonempty++;
	}
	return nonempty / ht->size * 100;
} //loadFactor()

int hash(char *x, int size)
// Index calculation. Function h() computes general hash for the string;
// this function turns the hash into a valid index, given the size of the
// array.
{
	return h(x) % size;
}

void insert(HashTable *ht, char *x)
{
	//#########################COMPLETE THIS FUNCTION##########################
	// ---<SNIP>---

	// for ease of reading, calcualte the hash of string x and store it in int address
	int hashCode = hash(x, ht->size);

	// if there is already something stored in that address (linked list) in the hash table, collision occurs
	if (ht->a[hashCode]->head != NULL)
	{
		ht->collisions++;
	}
	// regardless, add to the table
	addFront(ht->a[hashCode], x);

	// ---<SNIP>---
} //insert()

int findInTable(HashTable *ht, char *x)
{
	//#########################COMPLETE THIS FUNCTION##########################
	// ---<SNIP>---
	printf("\nFinding %s in hash table . . . ", x);
	// loop through each linked list and use the find function
	for (int i = 0; i < ht->size; i++)
	{

		// if the find function returns 1 (it found it), then return the linked list/address/hashcode it was found at
		if (find(ht->a[i], x))
		{
			printf("Found in hashcode %d!\n\n", i);
			// return index of linked list in table
			return i;
		}
	}
	printf("Could not find.\n\n");
	// return a non-existent index
	return -1;

	// ---<SNIP>---
}

void printTable(HashTable *ht)
{
	int i;
	printf("----------\n");
	for (i = 0; i < ht->size; i++)
	{
		printf("%d --> ", i);
		print(ht->a[i]);
	}
	printf("# of Collisions=%d\n", ht->collisions);
	printf("Load Factor %%=%.2f\n----------", loadFactor(ht));
}

// STRETCH GOAL 5.1
int removeKey(HashTable *ht, char *x)
// removes the data with the specified key from the hash table
{
	printf("\nRemoving key: %s\n", x);
	int hashCode = findInTable(ht, x);

	if (hashCode == -1)
	{
		printf("Cannot remove key that does not exist in table\n");
		return 0;
	}
	else
	{
		// only node
		if (strcmp(ht->a[hashCode]->head->value, x) == 0 && strcmp(ht->a[hashCode]->head->value, x) == 0)
		{
			// set head equal to NULL
			ht->a[hashCode]->head = ht->a[hashCode]->head = NULL;

			// set tail equal to NULL
			ht->a[hashCode]->head = ht->a[hashCode]->tail = NULL;
		}
		// first node has key
		else if (strcmp(ht->a[hashCode]->head->value, x) == 0)
		{
			// set head equal to the next node in list
			ht->a[hashCode]->head = ht->a[hashCode]->head->next;
			// remove the previous node, head should not have previous node
			ht->a[hashCode]->head->prev = NULL;
		}
		// last node has key
		else if (strcmp(ht->a[hashCode]->tail->value, x) == 0)
		{
			// set tail equal to previous node in list
			ht->a[hashCode]->tail = ht->a[hashCode]->tail->prev;
			// remove the next node, tail should not have a next node
			ht->a[hashCode]->tail->next = NULL;
		}
		// node is somewhere in the middle
		else
		{
			Node *tempNode = ht->a[hashCode]->head;
			while (tempNode->next != NULL)
			{
				if (strcmp(tempNode->value, x) == 0)
				{
					// set the previous node's next pointer to skip the current node
					tempNode->prev->next = tempNode->next;
					// set the next node's previous pointer to skip the current node
					tempNode->next->prev = tempNode->prev;
					return 1;
				}
				tempNode = tempNode->next;
			}
		}

		// successful removal, return 1
		return 1;
	}
}

// STRETCH GOAL 5.2
HashTable *enlargeTable(HashTable *ht)
{
	printf("\nLoad factor too large, doubling size to %d\n", ht->size * 2);
	// create the new table that will be returned that is double the size of the given hash table
	HashTable *newTable = initHashTable(ht->size * 2);

	// loop through each hashcode/address in original hash table and copy it over to new hash table
	for (int i = 0; i < ht->size; i++)
	{
		newTable->a[i] = ht->a[i];
	}

	// carry over original hashtable's collisions to this one
	newTable->collisions = ht->collisions;

	// return the new table
	return newTable;
}

int main()
{

	int i = 0;
	HashTable *h = initHashTable(101);

	// STRETCH GOAL 5.3
	if (SG3)
	{
		FILE *fp;
		fp = fopen("words.txt", "r");
		if (fp == NULL)
		{
			printf("Invalid Text File\n");
			return 0;
		}

		// can only read words with max 1000 characters
		char word[1000];
		while (fgets(word, 1000, fp))
		{
			word[strlen(word)-1] = '\0';
			insert(h, word);
			
			// STRETCH GOAL 5.2
			if (SG2 && loadFactor(h) > 60)
			{
				h = enlargeTable(h);
			}
		}

		fclose(fp);
	}
	else
	{
		// Generate a set of random strings (given the way this works, everyone
		// gets the same set of random strings!) insert each into the hash table
		// and then print the table.
		for (i = 0; i < 100; i++)
		{
			int x = rand() % 5 + 1;
			char *p = malloc(sizeof(char) * x);
			int j = 0;
			for (j = 0; j < x; j++)
				p[j] = rand() % 26 + 97;
			p[j] = '\0';
			insert(h, p);

			// STRETCH GOAL 5.2
			if (SG2 && loadFactor(h) > 60)
			{
				h = enlargeTable(h);
			}

			// TEST PRINT for Randomization to check answers
			// printf("%d -> %s\n", hash(p, h->size), p);
		}
	}

	printTable(h);

	// STRETCH GOAL 5.1
	if (SG1)
	{
		removeKey(h, "kakzx");
		printTable(h);
	}

	return 0;
}
