#include "hashtableTemp.hpp"
template <typename KeyType, typename ValueType>
HashTableTemp<KeyType, ValueType>::HashTableTemp(int ts) : tableSize(ts)
{
    table = new std::list<HashEntry<KeyType, ValueType>>[tableSize];
}

template <typename KeyType, typename ValueType>
HashTableTemp<KeyType, ValueType>::~HashTableTemp()
{
    delete[] table;
}

template <typename KeyType, typename ValueType>
ValueType HashTableTemp<KeyType, ValueType>::get(const KeyType &key)
{
    int index = hashFunction(key);
    for (const auto &entry : table[index])
    {
        if (entry.key == key)
        {
            return entry.value;
        }
    }
    throw std::out_of_range("Key not found in hash table");
}

template <typename KeyType, typename ValueType>
void HashTableTemp<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value)
{
    int index = hashFunction(key);
    table[index].push_back(HashEntry<KeyType, ValueType>(key, value));
}

template <typename KeyType, typename ValueType>
void HashTableTemp<KeyType, ValueType>::remove(const KeyType &key)
{
    int index = hashFunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it)
    {
        if (it->key == key)
        {
            table[index].erase(it);
            return;
        }
    }
    throw std::out_of_range("Key not found in hash table");
}

template <typename KeyType, typename ValueType>
void HashTableTemp<KeyType, ValueType>::list()
{
    for (int i = 0; i < tableSize; ++i)
    {
        std::cout << "Bucket " << i << ": ";
        for (const auto &entry : table[i])
        {
            std::cout << "(" << entry.key << ", " << entry.value << ") ";
        }
        std::cout << std::endl;
    }
}

template <typename KeyType, typename ValueType>
void HashTableTemp<KeyType, ValueType>::clear()
{
    for (int i = 0; i < tableSize; ++i)
    {
        table[i].clear();
    }
}

template <typename KeyType, typename ValueType>
int HashTableTemp<KeyType, ValueType>::hashFunction(const KeyType &key)
{
    // Basic hash function using modulus operator
    return std::hash<KeyType>{}(key) % tableSize;
}

template class HashTableTemp<int, int>;
