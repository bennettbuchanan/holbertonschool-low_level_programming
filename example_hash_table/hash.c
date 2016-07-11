/*
 * hash() - Find the index of the key passed, or if it does not exist, return
 * an empty array index.
 * @key: The key to find in the hash table.
 * @size: The size of the hash table.
 *
 * Return: The index of the item.
 */
unsigned int hash(const char *key, unsigned int size)
{
        unsigned int hash;
        unsigned int i;

        hash = 0;
        i = 0;
        while (key && key[i]) {
                hash = (hash + key[i]) % size;
                ++i;
        }
        return (hash);
}
