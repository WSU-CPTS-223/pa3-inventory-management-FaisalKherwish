#include "Inventory.h"
#include <cassert>
//Hash Table tests
void testInsert();
void testFind();
//Inventory Tests
void testPrint();
void testParsing();
void testRealFind();
void testListInven();


void testInsert()
{
HashTable<int,string> test1;

assert(test1.insert(1,"Hello"));
assert(test1.insert(1002,"Testing"));

}

void testFind()
{
HashTable<int,string> test;

test.insert(1,"Hello");
test.insert(2,"Test");

assert(test.find(1) == true);
assert(test.find(3) == false);

}

void testPrint()
{
HashTable<int,string> test;

test.insert(1000,"Hello");
test.insert(1001,"Test");

test.printHashTable();


}

void testParsing()
{
Inventory test("AmazonData.csv");

test.getSecondHash().printHashTable();


}

void testRealFind()
{
Inventory test("AmazonData.csv");

assert(test.find("40d3cd16b41970ae6872e914aecf2c8e") == true);

}

void testListInven()
{
Inventory test("AmazonData.csv");

test.listInventory("Toys & Games");




}