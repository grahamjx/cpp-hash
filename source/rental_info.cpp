/*
 Name: Joel Graham 
 ID#: 955801190
 Date: 11/17/2011
 Course: CS 163 
 Programming Assignment #3
 
 File: rental_info.cpp
 
 Purpose: This file contains the function definitions for the class "rental_info" found in "rental_info.h".
 These functions are used to carry out proccess that deal wth dynamically allocating memory for each
 member variable as well as functions to "get" and "set" the data which the member variables point to.
 
 Input: Since the member variables are private, "set" functions are used to set the data that the member variables
 are pointing to. This file utilizes input provided from the main() function add_rental. Functions from table
 including insert, retrive, remove and display, utlize this class to set the data for storage in the table as well as grab data out of
 objects in order to display the contents to the user.
 
 Output:  Member variables are private thus their access is limited to "getting" them out and setting them to some local variable
 where the "get" function is called from.
 */

#include "rental_info.h"
#include <cstring> //Included to allow the use of strcpy, strlen in member functions. Also was required for Unix g++ compile.

//Points the member variables to a new memory location on construction of an object
rental_info::rental_info(void)
{
	bedrooms = new int;
    price = new int;
    square_feet = new int;
	location = new char[NULL];
}


//Deallocates memory for each member variable.
rental_info::~rental_info()
{
	if(bedrooms)
		delete bedrooms;
	if(price)
		delete price;
    if(square_feet)
        delete square_feet;
    if(location)
        delete [] location;
}


//The passed in reference argument out_bedrooms is assigned the value pointed to by the member variable "bedrooms"
void rental_info::get_bedrooms(int& out_bedrooms) const
{
	out_bedrooms = *bedrooms;
}


//The passed in reference argument out_price is assigned the value pointed to by the member variable "price"
void rental_info::get_price(int& out_price) const
{
	out_price = *price;
}


//The passed in reference argument out_square_feet is assigned the value pointed to by the member variable "square_feet"
void rental_info::get_square_feet(int& out_square_feet) const
{
	out_square_feet = *square_feet;
}


//The passed in reference argument out_location is assigned the value pointed to by the member variable "location"
void rental_info::get_location(char out_location[]) const
{
	strcpy(out_location, location);
}


/* This function checks to see if member variable "bedrooms" is null, deallocating that memory if it is not.
 It then points "bedrooms" to a new int memory location and assigns it the value passed in by in_bedrooms. */

void rental_info::set_bedrooms(const int in_bedrooms)
{
	if(bedrooms!=NULL)
		delete bedrooms;
	this->bedrooms = new int;
	*bedrooms = in_bedrooms;
}


/* This function checks to see if member variable "price" is null, deallocating that memory if it is not.
 It then points "price" to a new int memory location and assigns it the value passed in by in_price. */

void rental_info::set_price(const int in_price)
{
	if(price!=NULL)
		delete price;
	this->price = new int;
	*price = in_price;
}


/* This function checks to see if member variable "square_feet" is null, deallocating that memory if it is not.
 It then points "square_feet" to a new int memory location and assigns it the value passed in by in_square_feet. */

void rental_info::set_square_feet(const int in_square_feet)
{
	if(square_feet!=NULL)
		delete square_feet;
	this->square_feet = new int;
	*square_feet = in_square_feet;
}


/* This function checks to see if member variable "localtion" is null, deallocating that memory if it is not.
 It then points "location" to a new char memory location with an array size exaclty as large as it need to be in
 order to hold the message. Using strlen, it measures the length of the character array in_location being passed
 in and sets the new memory location to that value + 1 to accomodate the null character. Then the in_location
 is copied in to the new memory location that "location" points to. */

void rental_info::set_location(const char in_location[])
{
	if(location!=NULL)
		delete [] location;
	this->location = new char[strlen(in_location)+1];
	strcpy(location, in_location);
}


