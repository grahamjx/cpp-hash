/*
 Name: Joel Graham 
 ID#: 955801190
 Date: 11/17/2011
 Course: CS 163 
 Programming Assignment #3
 
 File: hash.h
 
 Purpose: This file declares the struct "chain_node". This struct is used to build the "chaining" elements of the hash table
 and store the data provided in the "rental_info" class into a linked list inside an array element. It uses an in-declaration 
 function to grab the data out of the passed in object "a_rental" and sets it to the corresponding data object "data" 
 for each new node. This allows the program to build a node based upon each incoming rental property entered by the user. 
 Since it is a different linear linked list for each array element, the external pointer is declared in the table class as an 
 array of head pointers (See table.h). */

#ifndef HASH_H
#define HASH_H

#include "rental_info.h"

struct chain_node
{
    rental_info data;
    chain_node * next;
    
    chain_node(const rental_info& a_rental)
    {
        int bedrooms;
        int price;
        int square_feet;
        char location[MAX_CHAR];
        
        a_rental.get_bedrooms(bedrooms);
        a_rental.get_price(price);
        a_rental.get_square_feet(square_feet);
        a_rental.get_location(location);
        
        data.set_bedrooms(bedrooms);
        data.set_price(price);
        data.set_square_feet(square_feet);
        data.set_location(location);
    }
};
#endif