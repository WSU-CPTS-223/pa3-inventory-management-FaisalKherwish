#include "Product.h"


template <typename T>
class Node
{
public:
Node<T>() : product(), nxtPtr(nullptr){}
~Node<T>() = default;

Node<T>(const T& newData,Node<T>* newPtr) : product(newData),nxtPtr(newPtr) {}

T getProduct() const{return this->product;}
Node<T>* getNxtPtr() const{return this->nxtPtr;}

void setProduct(const T& newProduct) {this->product = newProduct;}
void setNxtPtr(Node<T>* newPtr) {this->nxtPtr = newPtr;}


private:
T product;
Node<T>* nxtPtr;

};