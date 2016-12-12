/*
 Name: Joel Graham 
 ID#: 955801190
 Date: 11/17/2011
 Course: CS 163 
 Programming Assignment #3
 
 File: table.cpp
 
 Purpose: This file contains the function definitions for the class "table" found in "table.h".
 These functions are used to carry out proccess that deal with the Table ADT and it's corresponding
 data structures (doubly linked list and hash table). Creating and destroying the table, creating nodes,
 deleting nodes, and extracting data from nodes are some of the operations carried out by this file.
 
 Input:   This file utilizes input provided from main function as entered by the user as well as from the "rental_info" 
 class which supplies the data for each individual node.
 
 Output:  Displays a limited amount of information found in each node out to the user (main function).
 */

#include "table.h"
#include <iostream>
#include <cstring> //Included to allow the use of strcpy, strlen in member functions. Also was required for Unix g++ compile.
#include <cstdlib> //Included to allow the use of atoi (c library function to convert character array to integer). Also was required for g++ compile.

using namespace std;

/*Sets the doubly linked list node pointers in the private section to null. The function also points the head_array pointer
in the private section to a new array of head nodes (See hash.h). The size of the array is determined by the constant found 
in table.h */

table::table()
{
    head = NULL;
    tail = NULL;
    head_array = new chain_node *[HASH_TABLE_SIZE];
}

/*Destroys the table in two parts. First by deleting all the data in the doubly linked list by deleting each node until head is equal to null. 
 The second part runs through the hash table using a for loop. At each array element it runs through the corresponding linked list and deletes 
 each node until the head of that linked list is null. Then it proceeds to the next element in the array. This process continues until the for 
 loop conditional statement reaches the end of the array.*/

table::~table()
{
    dll_node * current;
    chain_node * chain_current;
    
	while(head != NULL)
	{
        current = head;
        head = head->next;
        delete current;
	}
    
    for (int i = 0; i <= (HASH_TABLE_SIZE - 1); i++)
    {   
        while (head_array[i] != NULL)
        {
            chain_current = head_array[i];
            head_array[i] = head_array[i]->next;
            delete chain_current;
        }
    }
    delete [] head_array;
    tail = NULL;
}


/*Takes in "a_rental" object which was passed by reference from the add_rental function in main().
 
 This function is best described as two separate parts:
 
 Part 1 - Insert into DLL: A new dll_node pointer is created that will pass the object into the
 dll_node function depending on what value the private member variables are currently set to. Since
 the doubly linked list needs to be ordered by price, multiple conditionals statements are used to ensure
 that the item is added to the list in the appropriate position. For this reason, two temporary pointers 
 "current" and "trail_current" are used in order to keep track of various places in the list. When the item
 is passed in, the price variable is extracted and saved into the local variable "in_price". If the list is
 empty, then the object is inserted at the the beginning of the list and both the head and tail pointers are
 set to the new node. If the list is not empty, the function continues into a while loop that will check
 the current node's price with the passed in price (in_price). If the in_price is larger, than current is set
 to the next node in the list and the loop continues. If the in_price is less than the current_price than
 the bool value "less_than" is set to true and allows for exiting the loop. If upon exiting the loop, current is
 equal to the first node, the new item is added before it. If current is null, than it is the end of the list so
 the item is added to the tail. If current is neither the first or NULL, the item is added between two
 adjacent nodes. "Current" and "trail_current" are used in updating both the previous and next pointers for each
 new node added to the list depending on the location.
 
 Part 2 - Insert into Hash Table (Bottom): A new chain_node pointer is created that will pass the object into the
 chain_node function depending on what value the private member variables are currently set to. Since the hash 
 table uses a 'hashed' location value to assign the index in which to point the private "head_array" pointer to
 ,the location from the passed in object is extracted and saved to the local variable "location". The location
 is then passed into the hash function which returns a index number which gets assigned to "hashindex". The new 
 chain node's next pointer is set to the head pointer of the provided hashindex and then the head pointer for that 
 hashindex is set to the new node. */

void table::insert(const rental_info& a_rental)
{
    chain_node * new_chain_node = new chain_node(a_rental);
    dll_node * new_dll_node = new dll_node(a_rental);
	dll_node * current = head;
    dll_node * trail_current;
    
	int in_price;
	int current_price;
    int hashindex;
    char location[MAX_CHAR];
    bool less_than = false;
    
	a_rental.get_price(in_price);
    a_rental.get_location(location);
    
	if(head == NULL)
	{
        head = new_dll_node;
        tail = new_dll_node;
	}
	else
	{
		while(current != NULL && less_than != true)
		{
			current->data.get_price(current_price);
            
			if(in_price > current_price)
            {
                trail_current = current;
                current = current->next;
            }
			else
                less_than = true;
		}
        
        if (current == head)
        {
            new_dll_node->next = current;
            head = new_dll_node;
            current->previous = head;
        }
        else
        {
            if (current == NULL)
            {
                trail_current->next = new_dll_node;
                new_dll_node->previous = trail_current;
                tail = new_dll_node;
            }
            else
            {
                trail_current->next = new_dll_node;
                new_dll_node->previous = trail_current;
                new_dll_node->next = current;
                current->previous = new_dll_node;
            }
        }
    }
    
    hashindex = hash(location);
    new_chain_node->next = head_array[hashindex];
    head_array[hashindex] = new_chain_node; 
}


/*This function takes in a character array with a location that the user would like to remove.
 Since a removal requires deletion from both the hash table and the doubly linked list, this function
 can look somewhat confusing. 
 
 Part 1 - Removal from Hash Table: The removal_key is passed into the hash function and the resulting
 value is assigned to "hashindex". The chain_current pointer is then set to the head pointer for that
 particular array element. If the pointer is not null, then the function enters the loop and extracts the
 location variable, saving the value to the local variable "current_location". Then begins the process of
 comparing the removal location with the current location. If there is a match, the price is extracted and
 the head pointer is set to the next node. The current chain_node is then deleted (SEE PART 2).
 If there is not a match, the chain_current pointer is updated to the next node and the loop continues 
 until it has traversed the whole list.
 
 Part 2 - Removal from DLL: Since an item was removed from the hash table, the same item needs to be removed
 from the DLL. Before the item was deleted in the hash table, the price was extracted and saved to remove_price.
 This is useful becuase the DLL is order by price, not by location. A dll_node current pointer is set to head 
 and a while loops begins by checking the removal price against the current node's price. If there is not a match, 
 then current is updated to the next node and the loop continues. If the prices do match, the function then has to 
 check to see if the location matches as well to ensure that it is the same item. If the location does not match, 
 then current is updated and the loop continues. If both the price and then the location match, the process for 
 removal can begin. First, if the current node is also the first node in the list, it sets head to the next node, 
 checks to see if it was the only item before updating the previous pointer and then deletes the node. If current 
 is not the first node, it removes the node updating the previous and next pointers accordingly.
 
 If items were removed, the function returns the number of items that were removed. If nothing was removed, it
 returns zero. */

int table::remove(const char removal_key[])
{
    chain_node * chain_current;
    dll_node * current;
    dll_node * trail_current;
    
    int remove_price;
    int current_price;
    char current_location[MAX_CHAR];
    int hashindex;
    int deleted = 0;
    bool found = false;
    
    hashindex = hash(removal_key);
    chain_current = head_array[hashindex];
    
    while (chain_current != NULL)
    {
        chain_current->data.get_location(current_location);
        
        if (strcmp(removal_key, current_location) == 0)
        {
            chain_current->data.get_price(remove_price);
            head_array[hashindex] = chain_current->next;
            delete chain_current;
            found = true;
            deleted++;
            
            current = head;
            while (current != NULL)
            {
                current->data.get_price(current_price);
                if (current_price == remove_price)
                {
                    current->data.get_location(current_location);
                    if (strcmp(current_location, removal_key) == 0)
                    {
                        if (current == head)
                        {
                            head = head->next;
                            if (head != NULL)
                            {
                                head->previous = NULL;
                            }
                            else
                            {
                                tail = NULL;
                            }
                            delete current;
                        }
                        else
                        {
                            trail_current = current->previous;
                            trail_current->next = current->next;
                            
                            if (current->next != NULL)
                            {
                                current->next->previous = trail_current;
                            }
                            if (current == tail)
                            {
                                tail = trail_current;
                            }
                            delete current;
                        }
                    }
                }
                current = current->next;
            }
        }
        chain_current = chain_current->next;
    }
    
    if (found == false)
    {
        return 0;
    }
    return deleted;
}


/*This function takes in a array of characters as a search word, a search option and a empty array of rental_info objects (passed as reference by default).
 
 Option 1 - Retrieve (Search) by Location: If the user selects '1' from main, then they are asked to search rental properties
 based on location. They enter a location to search for and it is passed into this function along with an empty object array.
 The search word is passed into the hash function and the returned value is assigned to "hashindex". The chain_node current
 pointer is then set to the corresponding head pointer related to that particular array element. While the chain is not null,
 the while loop begins by comparing the search word with the location in the current node. If there is a match, the rest of the
 data variables are extracted and the data is copied into the empty "results" array. Chain_current is then updated to the next 
 node and the loops continues until it has traversed the whole list.
 
 Option 2 - Retrieve (Search) by Price: If search by location is not selected by the user than the function will traverse through
 the doubly linked list instead. The search word that was passed in is converted to an int and the result is saved to search_price.
 Starting at the head of the list, it compares the current price with in_price. If there is a match, the rest of the data variables 
 are extracted and the data is copied into the empty "results" array. Current is then updated to the next node and the loop continues
 until is has traversed the whole list.
 
 The function returns how many items were found and copied into the "results" array. */

int table::retrieve(const char search[], const int search_option, rental_info results[])
{
    chain_node * chain_current;
    dll_node * current;
    
    int hashindex;
    int copyindex = 0;
    int bedrooms;
    int square_feet;
    int price;
    int search_price;
    char location[MAX_CHAR];
    
    if (search_option == 1)
    {
        hashindex = hash(search);
        chain_current = head_array[hashindex];
        
        while (chain_current != NULL)
        {
            chain_current->data.get_location(location);
            if (strcmp(search, location) == 0)
            {
                chain_current->data.get_bedrooms(bedrooms);
                chain_current->data.get_price(price);
                chain_current->data.get_square_feet(square_feet);
                
                results[copyindex].set_bedrooms(bedrooms);
                results[copyindex].set_price(price);
                results[copyindex].set_square_feet(square_feet);
                results[copyindex].set_location(location);
    
                copyindex++;
            }
            chain_current = chain_current->next;
        }
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            current->data.get_price(price);
            search_price = atoi(search);
            
			if(search_price == price)
            {
                current->data.get_bedrooms(bedrooms);
                current->data.get_square_feet(square_feet);
                current->data.get_location(location);
                
                results[copyindex].set_bedrooms(bedrooms);
                results[copyindex].set_price(price);
                results[copyindex].set_square_feet(square_feet);
                results[copyindex].set_location(location);
                
                copyindex++;
            }
            current = current->next;
        }
    }
    return copyindex;
}


/*This function displays all the information stored in the doubly linked list. Since all items inserted into the hash
 table are also inserted into the doubly linked list, the two stuctures contain the same information but the 
 information is organized differently. Since we want to display all rentals ordered by price, the function just traverses 
 through the doubly linked list displaying each node until the end of the list. */

int table::display()
{
    dll_node * current = head;
    int bedrooms;
    int price;
    int square_feet;
    char location[MAX_CHAR];
    
    if (current == NULL) 
    {
        return 0;
    }
    else
    {
        while (current)
        {
            current->data.get_bedrooms(bedrooms);
            current->data.get_price(price);
            current->data.get_square_feet(square_feet);
            current->data.get_location(location);
        
            cout << "\nBedrooms: " << bedrooms << endl;
            cout << "Price: " << price << endl;
            cout << "Square Feet: " << square_feet << endl;
            cout << "Location: " << location << endl;
        
            current = current->next;
        }
        return 1;
    }
}


/*The hash function takes in a key (location). A for loop is used in order to retrieve the integer value
 for each charcter in the character array. For each iteration of the loop, the hash value is added to
 the integer value of each character until it reachs the end of the character array. The function returns
 the hash integer mod'ed against the hash table size so that the resulting value falls within the size
 of the hash table. */

int table::hash(const char key[])
{
    int hash = 0;
    for (int i = 0; i <= strlen(key); i++) 
    {
        hash = (hash + key[i]);
    }
    return (hash % HASH_TABLE_SIZE);
}

