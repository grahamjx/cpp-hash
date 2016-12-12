### Design Write-Up
Following the guidelines of the assignment, I created a class "table" that acts as a manager of two data structures, a doubly linked list and a hash table. For my implementation, a second class is used for the data containing each rental property entered by the user.

The table class lies at the center of my implementation of the Table ADT and it's public process are limited to inserting, retrieving, removing and displaying information. I opted to separate the two data structures used by the class into their own .h files so that there would be less confusion about which definition went with which data structure. I found this particularly helpful since both data structures utilize a version of a linked list and keeping the them separate made it less confusing and easier to avoid mistakes.

For all my member functions, I decided to keep the processing on each data structure together instead of separating them out into different functions such as insert_dll insert_hash, remove_dll remove_hash, ect. This made sense from an efficiency stand point because process on both data structures could be carried out with one function call and it would cut down on the amount of items I would have to pass as reference.

For hash table portion of my table ADT, I created an array of head pointers that were associated with linear linked lists. The chain nodes were populated using an in-struct function that set the data for each node with the information that the user entered. The use of the in-struct function helped keep the overall insert function cleaner which was important because it dealt with the insertion of information for the hash table as well as the doubly linked list. Since the hash table is an array of pointers, insertion position is determined by which array element the external head_array pointer points to. I decided to create a separate function that would hash the location and return an index value that fell within the range of the table size. Separating the function from insert made sense in order to maintain solid organization and allow only what was necessary for public access to be made available. I placed the hash function definition in the private section of my table class since its use was only required by the corresponding member functions and would avoid unassociated use by the client side of the program.

For the actual hashing of the location for this program, I broke down the character array into integers and then added them together. This allowed each hash value to be unique for every location that was different. The importance of this became apparent when I made my hash table really large. The larger the hash table, the less collisions there was and the use of memory became more efficient. Since there were fewer collision, searching through items was faster since it would generally only have to look at the head node when doing a comparison rather than having a long chain to traverse through. Another benefit is that when a location was entered that was the same as a previous one such as "NW Portland", the item would get assigned to the same array element. When a search was run, it was likely that every node in the corresponding chain had the same location. Of course, if you're using a really large hash table with only four possible locations, there is a ton of empty array space that isn't being utilized. In that case, a smaller hash table would be more efficient since there wouldn't be a need to have any more than four positions and items with the same location would be associated with the same array element. Overall, I feel that run-time efficiency of for this hash table comes down to how much differentiation of each location there is. A small hash table with a large variety of locations isn't a very good option since collision chains will then contain a large variety of locations and possibly require lengthy traversals to find information. From a search and remove stand point, this can be a costly process.

For the doubly linked list portion of my table ADT, I created two external pointers for the head and the tail that were associated with the dll node type. I again used and in-struct function to populate the data for each node as it was passed in from main. Adding data to the doubly linked list was somewhat tedious since the list is order by price. Once the item is passed in, the price is extracted and then compared against each node in the list. If the price of the passed in item is greater than the current item, then it would move to the next item in the list. Once the passed in price was less than the current price or the loop had reached the end of the list, the item could be added. Of course when dealing with a doubly linked list there is multiple cases that you have to deal with. If the new price was less than the first node's price then the the item is added before it. If the new price falls between two nodes then the item has to be added between them. Of course, if the new price is greater than all the other items it gets added at the end. The process on paper is relatively straight forward but implementing these multiple cases while managing two temporary pointers to keep track of placement, was very tedious and cumbersome from a coding perspective. This is likely the point of biggest inefficiency in my implementation. Every time I added or removed from the dll I had to establish two temporary pointers to keep track of my movements through the list. In retrospect, I feel like this is somewhat wasteful. If I would have implemented a third external pointer that would act as a constant tracker, I would be able to start at the last place of insert and traverse up or down depending on the price. This would likely lead to less time traversing the list since if a price falls close to the active pointer it might only take one or two movements to add the new item. For my implementation, it begins at the top of the list every time. This is an efficient solution if the new prices always land close to the head of the list but if they do not it has to traverse to that location every time. This is particularly costly if items are entered with prices on an increasing basis. Overall, I have a working solution for keeping the dll ordered but at the cost of an extra temporary pointer and possible long traversal times depending on the input.

For the data that contained rental information, I decided to create a class instead of a struct and separate it into its own .h and .cpp file.  I enjoyed the ability to segment my program into different parts. It helped me look at each section of my program more thoroughly and made it easier for debugging issues as well as providing clarity when programming. Unfortunately, using a class in this particular case does add additional code since I had to get and set the private member functions of the class in a variety of situations. Overall, it behaves very similar to a struct but it did allow me to easily organize my member functions and made the process of allocating and deallocating memory easier for me personally.

As far as using a hash table as one of my data structures for my table class, I found it to be a welcome change from the somewhat ordinary usage of linked lists in the past. I rather enjoyed mixing the benefits of fast access provided by an array with the smart flexibility of a linked list. For this assignment I feel like the hash table worked very well. All the process of insert, retrieve and remove were done with relative ease. The amount of code required to manage the hash table is also considerably less when compared against the doubly linked list. As long as a reasonable hash table size is chosen and the function for hashing the location is done in a unique manner, I think it was a great data structure to use for this assignment. One possible alternative to a hash table for this assignment would be a flexible array. The items could be ordered by location while using an additional temporary pointer to keep track of the previous node during traversal and each item of the same location could be added to the corresponding array. For each different location, a new node would be created and the data would be saved to an array element. When adding items, the new item would be added to the next position in the array. When removing items, you could either delete the array and then delete the node for the corresponding location or have the option to delete one location at a time from the array. Of course, this depends on how large you make the corresponding arrays for each node which could lead to possible waste of memory.

As far as using the doubly linked list for my second data structure in my implementation, I think it was a poor choice. The sheer amount of management and special case code for adding items to the dll was at times complicated and tedious. I found that the benefit of traversing up or down the list wasn't used to its potential and all together didn't serve any practical purpose. A linear linked list could have been used to accomplish the same thing at the cost of only one extra temporary pointer to track the previous node. Overall, the additional overhead  required by a dll just doesn't seem necessary for this assignment and the benefit of traversing up or down the list wasn't utilized in the extent where it would have been useful. I would recommend using a linear linked list with an additional temp pointer to track the previous node when constructing a ordered list. The overhead is lower and the amount of code to update pointers is also considerably less.

If I had more time to solve the problem, I would like to incorporate an additional external pointer that would track the current added element. That way when a new item was added to the list, I could traverse up or down the dll depending on what the value was. Another thing I would like to look into is how I could store locations with "similar" locations in the same chain. Such as hashing the location so that entries like "SW Iowa" and "9414 SW Iowa" would be hashed to the same array position.