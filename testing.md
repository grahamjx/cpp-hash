Exhaustive Program Testing
 1. Adding rental information. a. Input both large and small integer values for bedrooms, price and square footage. i Bedroom – 3, 10, 300 ii Rent – 100, 1000, 100000 iii Square Feet – 300, 800, 2400 b. Input a large variety of locations for each rental property. iv Locations – NW Portland, Beaverton, 9414 SW Iowa

2. Displaying all the stored information. a. This information should be sorted by price starting from least to greatest. b. All information relating to a particular entry should be the same as what was entered previously. v Example: Bedrooms – 3, Rent – 100, SF – 300, Location – NW Portland.

3. Removing rental information. a. Enter a rental location that you would like to delete. vi Example – NW Portland. Ø Will return with the number of items that was deleted. b. To check for accuracy, run the display all function again. vii Items with that previous location should have been removed and will no longer be present in the displayed list. c. Enter a rental location that you know does not exist. viii Example: SW Walker Ø Will return that no items were found for deletion. Ø Run the display all function to check that nothing was removed.

4. Search rental information. a. Chose if you would like to search by price or by location. b. Search by price. ix Enter a price that you know is associated with one or more rental items (Example: 1000).
Ø If items match the entered search price, they will be displayed back to the user. § Verify that the entries information is the same as what was entered previously. • Bedrooms – 10, Rent – 1000, SF – 800, Beaverton. x Search by location. Ø If items match the entered location they will be displayed back to the user. § Verify that the entries information is the same as what was entered previously. • Bedrooms – 3, Rent – 100, SF – 300, NW Portland. c. Enter more information with locations and prices that are the same and then re-run search. xi Multiple items should be found that match the search price / location. d. Run the remove function again and remove items on a particular location. xii Search for the removed location. Ø No items should be found.

5. Advanced testing procedures. a. Increase the size of the hash table. xiii Go through the previous processes again. Ø The client side should not display / act differently than before.

6. General client testing. a. Input various options at menu screens to see if input checking is utilized. b. Quit the program upon completion of all testing.
