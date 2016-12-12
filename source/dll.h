/*
 Name: Joel Graham 
 ID#: 955801190
 Date: 11/17/2011
 Course: CS 163 
 Programming Assignment #3
 
 File: dll.h
 
 Purpose: This file declares the struct "dll_node". This struct is used to build the doubly linked list and 
 store the data provided in the "rental_info" class into each node (See rental_info.h). It uses an in-declaration function 
 to grab the data out of the passed in object "a_rental" and sets it to the corresponding data object "data" for each 
 new node. This allows the program to build a node based upon each incoming rental property entered by the user. Since it 
 is a doubly linked list, there is two external pointers "head" and "tail" that track the beginning and end of the list.
 Since this struct definition is separated from table ADT implementation, the external pointers are declared in the table
 class (See table.h). */

#ifndef DLL_H
#define DLL_H

#include "rental_info.h"
#include <iostream>

struct dll_node
{
    rental_info data;
    dll_node * next;
    dll_node * previous;
    
    dll_node(const rental_info& a_rental)
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
        
        next = NULL;
        previous = NULL;
    }
};
#endif