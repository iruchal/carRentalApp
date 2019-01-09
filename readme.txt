This program uses linked lists to maintain the data structure for a car rental company. 
It allows you to perform several types of transactions to keep the rental lists up-to-date.
Write a program in which linked lists are used to maintain the data structure for a
car rental company. The program allows several types of transactions to be applied to the data
structure in order to keep the lists up-to-date.

I recommend that the first step be transaction 6 as that will print out the text files and load them into their respective linked lists. Then you may select any transaction you would like. Let's say you wanted to run transaction 2 for instance. You would look at the cars in rented linked list, choose one from the list and enter the details when prompted. The program will then move that specific car to the available for rent linked list and free it from the rented linked list. That is how you should go about running the program.

Run it on terminal by entering "make" followed by "./rental" to run the program.

Transaction 1 : 
prompts user for plate number and mileage
Puts the prompted information into the available-for-rent linked list 

Transaction 2 : 
prompts user for plate number and mileage
Looks for a car in the rented linked list that matches the prompted information
When found, it moves that car into the available-for-rent linked list
and frees it from the rented linked list

Transaction 3 : 
prompts user for plate number and mileage
Looks for a car in the rented linked list that matches the prompted information
When found, it moves that car into the repair linked list
and frees it from the rented linked list

Transaction 4: Prompts for a plate number
Looks for the plate number in the repair linked list
Moves it into the Available linked list
and frees it from the repair linked list

Transaction 5: Prompts for a return date
Enters that into the available-for-rent linked list head node
Moves it into the rented linked list
and frees it from the rented linked list

Transaction 6: Prints the 3 text files only on first execution
Prints the three linked lists every time you call the function.

Transaction 7: It exits the program

EXAMPLE: 

Would you like to perform another transaction? Enter any number for YES and 0 for NO
1
Here are the transactions available
1. add a new car to the available-for-rent list
2. add a returned car to the available-for-rent list
3. add a returned car to the repair list
4. transfer a car from the repair list to the available-for-rent list 
5. rent the first available car
6. print all the lists
7. quit
Please enter the desired transaction.
2
Please enter the plate number:  
ALI
Please enter the mileage:  
50
The car with the plate number ALI and mileage of 50 has been moved from the Rented linked list to the Available linked list. 
The fee for this transaction was $40.
Would you like to perform another transaction? Enter any number for YES and 0 for NO
