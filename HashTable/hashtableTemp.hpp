#pragma once
#include <iostream>
#include <list>

template <typename KeyType, typename ValueType>
struct HashEntry
{
    KeyType key;
    ValueType value;
    HashEntry(const KeyType &key, const ValueType &value) : key(key), value(value) {}
};

template <typename KeyType, typename ValueType>
class HashTableTemp
{
private:
    std::list<HashEntry<KeyType, ValueType>> *table;
    int tableSize;

public:
    HashTableTemp(int ts);
    ~HashTableTemp();
    ValueType get(const KeyType &key);
    void insert(const KeyType &key, const ValueType &value);
    void remove(const KeyType &key);
    void list();
    void clear();
    int hashFunction(const KeyType &key);
};
