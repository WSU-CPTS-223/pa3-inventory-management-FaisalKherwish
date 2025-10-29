#include "Node.hpp"


template <typename T>
class List
{
    public:
    List<T>() : pHead(nullptr){}
    ~List<T>();

    Node<T>* getHead() {return this->pHead;}
    void setHead(Node<T>* newHead) {this->pHead = newHead;}

    void insertAtFront(const T& newData); 
    void printList();
    void findData(const T& productKey);
    void deleteList();



private:
Node<T>* pHead;

};

template <typename T>
List<T>::~List()
{
deleteList();
}


//I chose to use insert at front because it's constant time insertion
template<typename T>
void List<T>::insertAtFront(const T& newData)
{
    Node<T>* temp = new Node<T>(newData,pHead);
    pHead = temp;
}

template<typename T>
void List<T>::printList()
{
    Node<T>* pCur = pHead;

    while(pCur != nullptr) 
    {
        cout << pCur->getProduct().second << endl;
        pCur = pCur->getNxtPtr();
    }


}

template <typename T>
void List<T>::findData(const T& productKey)
{
   Node<T>* pCur = pHead;

   while(pCur != nullptr && pCur->getProduct() != productKey)
   {
    pCur = pCur->getNxtPtr();
   }
    if(pCur == nullptr) cout << "Could Not Find Product" << endl;
    else
    {
        cout << pCur->getProduct();
    }

}

template<typename T>
void List<T>::deleteList()
{
Node<T>* pCur = this->pHead;
Node<T>* temp;

while(pCur != nullptr)
{
temp = pCur->getNxtPtr();
delete pCur;
pCur = temp;
}

pHead = nullptr;

}
 