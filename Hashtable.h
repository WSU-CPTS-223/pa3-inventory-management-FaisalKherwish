#include "LinkedList.hpp"
#define TABLE_SIZE 1001

template<typename K, typename V>
class HashTable
{
public:
HashTable<K,V>();
~HashTable<K,V>();

bool insert(const K& keyVal, const V& val);
bool find(const K& keyVal);
void printHashTable();
List<pair<K,V>>& getList(int in) {return this->listArr[in];}


private:
List<pair<K,V>>* listArr;
int arrSize;
hash<K> hasher;
};

template<typename K, typename V>
HashTable<K,V>::HashTable()
{
arrSize = TABLE_SIZE;
listArr = new List<pair<K,V>>[arrSize];
}

template<typename K, typename V>
HashTable<K,V>::~HashTable()
{
    delete[] listArr;
}



template<typename K, typename V>
bool HashTable<K,V>::insert(const K& keyVal,const V& val)
{
pair<K,V> holder(keyVal,val);

size_t temp = hasher(keyVal);
int hashIndex = temp % arrSize;

listArr[hashIndex].insertAtFront(holder);
return true;

}

template<typename K, typename V>
bool HashTable<K,V>::find(const K& keyVal)
{
size_t temp = hasher(keyVal);
int hashIndex = temp%arrSize;

Node<pair<K,V>>* pCur = listArr[hashIndex].getHead();

while(pCur != nullptr)
{
if(keyVal == pCur->getProduct().first)
{
    cout << pCur->getProduct().second << endl;
return true;
}
pCur = pCur->getNxtPtr();
}

return false;

}


template<typename K, typename V>
void HashTable<K,V>::printHashTable()
{
  
for(int i = 0; i < arrSize ; i++)
{
listArr[i].printList();
}

}

