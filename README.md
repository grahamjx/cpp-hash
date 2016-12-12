##C++ - Rental Database App

###Foreword
Repos like this one contain old work that I did during my time at Portland State University. Most of these projects were completed in the Data Structures or Computer Systems Programming courses. These projects demonstrate my solid understanding of programming basics as well as familiarity with fundamental system architectures. Each project is meticulously commented and the provided design write-up discusses some of the implementation choices I made when creating these projects.

###Getting Started

Simply run the compiled executable from any unix-based terminal

```bash
  $> cd /path/to/your-project-folder
  $> ./cs-rentaldb
  ```
Of course if you want to compile it from source a simple ```$> make run ``` from the source directory will do the trick.

###Purpose:
This program simulates a rental information database application. Each property will be passed into the corresponding ADT which handles storage and manipulation of the data. Each property will be stored in two different data structures, a hash table and a doubly linked list. The properties are inserted into the hash table based upon location and into the doubly linked list based on price, with the cheapest property being first. The user has the option to add, remove and search for properties as well as display all stored property information.

###Input:   
When executing this program, a_table (table.h) object is created as well as an rental_info object that passes the user information into the corresponding ADT. Rental properties are stored differently in two separate data structures. The data provided to the table is managed by the class "rental_info" (See rental_info.h). The overall structure of the program back-end is managed by the table class (table.h / table.cpp).

###Output:  
The rental properties can be displayed in two ways. The main display function displays all the stored property information ordered by price. This is done by utilizing the "display" table class member function which traverses the doubly linked list, outputting the data in each node. The second output is done using the search function. An empty array of rental_info objects is passed into the "retrieve" table class member function where items that match the requested search word are copied into the array. The data inside the "results" array is then displayed to the user.
