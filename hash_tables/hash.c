unsigned int hash(const char *key, unsigned int size)
{
  unsigned int hash;
  unsigned int i;

  hash = 0;
  i = 0;
  while (key && key[i])
  {
    hash = (hash + key[i]) % size;
    ++i;
  }
  return (hash);
}
