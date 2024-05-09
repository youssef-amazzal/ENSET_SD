#include "hashtable.hpp"
HashTable::HashTable(int ts) : tableSize(ts), count(0)
{
    table = new hashEntry *[tableSize];
    for (int i = 0; i < tableSize; ++i)
    {
        table[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    clear();
    delete[] table;
}

int HashTable::get(int key)
{
    int hash = hashFunction(key);
    while (table[hash] != nullptr && table[hash]->key != key)
    {
        hash = (hash + 1) % tableSize;
    }
    if (table[hash] == nullptr) return -1; // Key not found
    return table[hash]->value;
}

void HashTable::insert(int key, int value)
{
    if (count == tableSize)
    {
        cout << "Table is full. Cannot insert more elements." << endl;
        return;
    }
    int hash = hashFunction(key);
    while (table[hash] != nullptr && table[hash]->key != key)
    {
        hash = (hash + 1) % tableSize;
    }
    if (table[hash] != nullptr)
    {
        delete table[hash];
    }
    table[hash] = new hashEntry(key, value);
    count++;
}

void HashTable::remove(int key)
{
    int hash = hashFunction(key);
    while (table[hash] != nullptr)
    {
        if (table[hash]->key == key)
        {
            delete table[hash];
            table[hash] = nullptr;
            count--;
            return;
        }
        hash = (hash + 1) % tableSize;
    }
    cout << "Key not found. Cannot remove." << endl;
}

void HashTable::list()
{
    for (int i = 0; i < tableSize; ++i)
    {
        if (table[i] != nullptr)
        {
            cout << "Key: " << table[i]->key << ", Value: " << table[i]->value << endl;
        }
    }
}

void HashTable::clear()
{
    for (int i = 0; i < tableSize; ++i)
    {
        if (table[i] != nullptr)
        {
            delete table[i];
            table[i] = nullptr;
        }
    }
    count = 0;
}

int HashTable::hashFunction(int key)
{
    return key % tableSize;
}
