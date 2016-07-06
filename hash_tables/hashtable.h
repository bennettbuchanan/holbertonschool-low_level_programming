#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

/*
 * @key : The key string of a pair
 * The key is unique in the HashTable
 *
 * @value : The value corresponding to a key
 * A value is not unique. It can correspond to several keys
 *
 * @next : A pointer to the next node of the List
 */
typedef struct List
{
  char *key;
  char *value;
  struct List *next;
} List;

/*
 * @size : The size of the array
 *
 * @array : An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct HashTable
{
  unsigned int size;
  List **array;
} HashTable;

/*
 * @key : The key to hash
 *
 * @size : The size of the hashtable
 *
 * @return : An integer N like 0 <= N < @size
 * This integer represents the index of @key in an array of size @size
 */
unsigned int hash(const char *key, unsigned int size);

#endif
