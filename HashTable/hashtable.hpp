#pragma once
#include <iostream>

using namespace std;

struct hashEntry
{
    int key;
    int value;
    hashEntry(int key, int value) : key(key), value(value) {}
};

class HashTable
{
private:
    hashEntry **table;
    int tableSize;
    int count;

public:
    HashTable(int ts);
    ~HashTable();
    int get(int key);
    void insert(int key, int value);
    void remove(int key);
    void list();
    void clear();
    int hashFunction(int key);
};
