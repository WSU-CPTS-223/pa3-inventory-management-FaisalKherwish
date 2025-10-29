#include <iostream>
#include <string>
#include <functional>
#include <utility>

using namespace std;


class Product {
public:
Product();
~Product() = default;

Product(string newData, string newName, string newAsin,string brand,string newCat) :
 inventoryid(newData), productName(newName), brandName(brand), asin(newAsin),category(newCat) {}

string inventoryid;
string productName;
string brandName;
string asin;
string category;



};
ostream& operator<<(iostream& lhs,Product& rhs);

ostream& operator<<(ostream& lhs,const Product& rhs)
{
lhs << "ID: " << rhs.inventoryid << "\n" 
    << "Product Name: " << rhs.productName << "\n"
    << "Brand Name: " << rhs.brandName << "\n"
    << "Asin: " << rhs.asin << "\n"
    << "Category: " << rhs.category << endl;

    return lhs;
}