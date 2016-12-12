/*
 Name: Joel Graham 
 ID#: 955801190
 Date: 11/17/2011
 Course: CS 163 
 Programming Assignment #3
 
 File: rental_info.h
 
 Purpose: This file declares the class "rental_info". This class handles the construction of the data that is used in both the table class.
 Since the data members are private, the public member functions of the class are made of up the constructor and destructor as well as four 
 functions that "get" the data pointed to by the private member variables and four functions that "set" the data pointed to by the private member variables.
 */

#ifndef RENTAL_INFO_H
#define RENTAL_INFO_H

const int MAX_CHAR = 101; //Used on local variables found in multiple functions. This is merely to hold information coming out of the email_item data class.
 
class rental_info
{
public: 
	//Constructor
	rental_info(void);

	//Destructor
    ~rental_info(void);
	
	void get_bedrooms(int& out_bedrooms) const; //Gets the number pointed to by the private member variable "bedrooms" and assigns it to the passed in int.
    void get_price(int& out_price) const; //Gets the number pointed to by the private member variable "price" and assigns it to the passed in int.
    void get_square_feet(int& out_square_feet) const; //Gets the number pointed to by the private member variable "square_feet" and assigns it to the passed in int.
    void get_location(char out_location[]) const; //Gets the location pointed to by the private member variable "location" and assigns it to the passed in char array.
    
	void set_bedrooms(const int in_bedrooms); //Sets the private member variable "bedrooms" to the int value passed into the function.
	void set_price(const int in_price); //Sets the private member variable "price" to the int value passed into the function.
    void set_square_feet(const int in_square_feet); //Sets the private member variable "square_feet" to the int value passed into the function.
    void set_location(const char in_location[]); //Sets the private member variable "location" to the char array passed into the function.
    
private:
    int*  bedrooms;
	int*  price;
	int*  square_feet;
    char* location;
};  
#endif
