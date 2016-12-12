/*
 Name: Joel Graham 
 ID#: 955801190
 Date: 11/17/2011
 Course: CS 163 
 Programming Assignment #3
 
 File: table.h
 
 Purpose: This file is the core of the Table ADT and the class "table" created in this file acts as the manager of
 the two data structures used in the project (Hash Table, Doubly Linked List). This class handles the initialization of the table
 (constructor), storing the data into individual nodes based on price and location (insert), removing data from both the hash table
 and doubly linked list (remove), retrieving data by location or by price and returning it to the user (retrive), displaying all
 the stored information back the user (display) and the destruction of the table (destructor).

 This private section of the "table" class contain the two external pointers used by the doubly linked list and the head pointer
 used to access information in the hash table. In addition, the function "hash" in the private section is used to break down the
 passed in key value and return a index number that falls within the HASH_TABLE_SIZE. This function is used when adding, removing and
 retrieving items from the hash table.
 */

#ifndef TABLE_H
#define TABLE_H

#include "dll.h"
#include "hash.h"
#include "rental_info.h"

const int HASH_TABLE_SIZE = 9;

class table
{
public:
    //Constructor
	table();
    
	//Destructor
	~table();
    
	void insert(const rental_info& a_rental); //Adds a rental to both the hash table and doubly linked list
    int remove(const char removal_key[]); //Removes a rental from both the hash table and doubly linked list
    int retrieve(const char search_location[], const int search_price, rental_info results[]); //Returns found items back to main via the passed in array
    int display(); //Displays all stored information, ordered by price (doubly linked lst).
    
    
private:
    
    int hash(const char key[]); //Used for assigning an index value for hash table insert, remove, and retrive.
    
    dll_node * head;
    dll_node * tail;
    chain_node ** head_array;

};
#endif
