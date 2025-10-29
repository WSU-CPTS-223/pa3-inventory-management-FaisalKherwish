#include "Hashtable.h"
#include <fstream>
#include <sstream>
#include <vector>

class Inventory{
public: 
Inventory() = default;
Inventory(string file);
~Inventory() = default;

//Function for removing empty fields when parsing a line
string removeEmptyFields(const string& line);

bool find(string newData);
bool listInventory(string findCategory);
HashTable<string,Product> getFirstHash() {return this->uniqIDHash;}
HashTable<string,Product> getSecondHash() {return this->categoryHash;}



private:
HashTable<string,Product> uniqIDHash;
HashTable<string,Product> categoryHash;


};

Inventory::Inventory(string file)
{
ifstream infile(file);
string lineHolder = "";

if(!infile.is_open()) 
{
    cout << "Could not open file" <<endl;
    return;
}

getline(infile,lineHolder);



while(getline(infile,lineHolder))
{
lineHolder = removeEmptyFields(lineHolder);

stringstream temp(lineHolder);
string cats;
vector<string> buffer;




for(int i = 0; i < 5 && getline(temp,cats,','); i++)
{
buffer.push_back(cats);
}



string id = buffer[0];
string name = buffer[1];
string br = buffer[2];
string as = buffer[3];
string categoryTemp = buffer[4];


Product tempProd(id,name,br,as,categoryTemp);

uniqIDHash.insert(id,tempProd);
categoryHash.insert(categoryTemp,tempProd);

}


}


string Inventory::removeEmptyFields(const string& line)
{
string fixedLine = line;

while(fixedLine.find(",,") != string::npos)
{
fixedLine.replace(fixedLine.find(",,"),2,",NA,");
}


if(fixedLine.front() == ',') fixedLine = "NA" + fixedLine;
if(fixedLine.back() == ',') fixedLine = fixedLine + "NA";


return fixedLine;

}

bool Inventory::find(string newData)
{
if(uniqIDHash.find(newData)) return true;
return false;
}

bool Inventory::listInventory(string findCategory)
{
    bool hml = false;

cout << "Products in this category: \n";

for(int i = 0; i < TABLE_SIZE;i++)
{
List<pair<string,Product>>& curBuck = categoryHash.getList(i);
Node<pair<string,Product>>* pCur = curBuck.getHead();

while(pCur != nullptr)
{
const string& categoryProd = pCur->getProduct().first;

if(categoryProd.find(findCategory) != string::npos)
{ cout << pCur->getProduct().second << endl;
hml = true;
}
pCur = pCur->getNxtPtr();

}
}

if(!hml) cout << "No Products in Category" << endl;
return false;
}

