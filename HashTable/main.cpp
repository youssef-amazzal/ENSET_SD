#include <iostream>
#include "hashtable.hpp"
#include "hashtableTemp.hpp"
using namespace std;

int main()
{
    cout << "without template" << endl;
    HashTable ht(10);
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(11, 30);
    ht.insert(21, 40);
    ht.insert(31, 50);

    cout << "1= " << ht.get(1) << endl;
    cout << "2= " << ht.get(2) << endl;
    cout << "11=" << ht.get(11) << endl;
    cout << "21= " << ht.get(21) << endl;
    cout << "32= " << ht.get(31) << endl;

    cout << "List " << endl;
    ht.list();

    ht.remove(2);
    ht.list();

    ht.clear();
    ht.list();

    cout << "with template" << endl;
    HashTableTemp<int, int> htTemp(10);
    htTemp.insert(1, 10);
    htTemp.insert(2, 20);
    htTemp.insert(11, 30);
    htTemp.insert(21, 40);
    htTemp.insert(31, 50);

    cout << "1= " << htTemp.get(1) << endl;
    cout << "2= " << htTemp.get(2) << endl;
    cout << "11= " << htTemp.get(11) << endl;
    cout << "21= " << htTemp.get(21) << endl;
    cout << "31= " << htTemp.get(31) << endl;

    cout << "List: " << endl;
    htTemp.list();

    htTemp.remove(2);
    htTemp.list();

    htTemp.clear();
    htTemp.list();

    return 0;
}