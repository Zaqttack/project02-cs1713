# project02-cs1713

This project is to create a program that analyzes airline data. The data shows the number of departures (flights), seats available, actual passengers carried, amount of freight/cargo carried, airline code, airline name, origin airport and destination airport for a specific route operated by any airline flight into or out of a US city. This data will be brought into the program through an external CSV file. The attached CSV file comes from the US Bureau of Transportation Statistics (https://www.transtats.bts.gov). This data includes the number of passengers and freight (cargo) carried on all international segments between the US and other countries in March 2018. Each record represents a unique segment between an origin and destination operated by an airline.  

LIST FOR STRUCT
	Column 1: Total number of departures
	Column 2: Total number of seats available 
	Column 3: Total number of actual passengers
	Column 4: Total weight of freight/cargo (assume in tons)
	Column 5: 2(or 3)-letter IATA airline code
	Column 6: Airline name
	Column 7: 3-letter IATA airport code of the origin
	Column 8: 3-letter IATA airport code of the destination

Note that there is no header row so you can more easily read in the CSV file. Your CSV file will have thousands of records, but your program must work for any number of records. There are two files attached (a long one airlinestats.csv and a short one airlinestats-short.csv). You may want to start with the short one first. 

main.h
	This header file contains the prototype for the printMenu() and the header guard. You do not need to modify anything in this file.

TASK 1: Complete airlinestats.h
	Create a struct Record that will hold a single row in the CSV file. See the CSV file description for the required data members. You will need to write this struct.
	An enum has been created for you. This enum, SearchType, has three possible values: AIRLINE, ORIGIN, and DESTINATION. This value is used by computeStatistics() to determine what type of information will be used to compute the statistics: by airline, by origin, or by departure. 
	This file also includes the prototypes. They have all been written for you. There is no need to add the function comments for the prototypes.

TASK 2: Write all functions in airlinestats.c
Write the following functions. 
	getRecordCount( FILE * fileIn ) - This function returns the count of the records in the CSV file. At the end, it will reset the file pointer back to the beginning of the file (rewind or fseek). The value returned will be used in the main to dynamically allocate the array of Record struct's.
	void fillRecords( FILE *fileIn, Record *data, int length ) - This function reads in each record from the CSV and parses the individual pieces, and stores it in the array of Record struct's. The length of the array, which was dynamically allocated after the getRecordCount() call in the main, is passed in.
	void sortRecords( Record *data, int min, int max ) - This function sorts your array by the airline's full name, alphabetically from A to Z. An airline will have many records, but you will not need a further level of sorting. So long as the different airlines are sorted with each other by their name, it is fine. Use the merge sort algorithm for sorting. This function should be called immediately after fillRecords(). 
	void mergeRecords( Record *data, int low, int mid, int high ) - This function will help you with sortRecords().
	void printRecord( Record data ) - It prints a single record. You may select the format, but it is recommended to just print all the Record's data members in one row formatted in columns.
	void printAllRecords( Record *data, int length ) - Prints all the records. Call printRecord() to help with this function. Because the data will already be sorted, using the sortRecords() function, this function will automatically print the records in alphabetical order by the airline name.
	Record findRecord( Record *data, int length, char *code, char *origin, char *destination ) - This function goes through the data array and finds a record whose airline code, origin airport code, and destination airport code matches their respective values passed through the parameter. If it does match, return that Record struct. If no match was found, create a dummy Record struct with the departures set to an error value like -999. In the main(), you will check this value to either print out the record or print out an error message saying it was not found. 
	void computeStatistics( Record *data, int length, SearchType type, char *entry ) - This function takes the array of Record struct's, the length, the SearchType, and an entry. If SearchType's value is AIRLINE, the entry is the airline's 2-letter IATA code. If SearchType's value is ORIGIN, the entry is the origin airport's 3-letter IATA code. If SearchType's value is DESTINATION, the entry is the destination airport's 3-letter IATA code. There should only be one loop in this function. As you traverse the loop, keep track of the total number of passengers, seats available, departures, amount of freight, and number of records that fit this search criteria.
		If records were found, print out the sum for all these amounts, including average occupancy (total number of passengers divided by seats available) and average amount of freight (total amount of freight divided by the number of departures). If no records were found, do not print out summary statistics. Simply print "No records found."

TASK 3: Complete main.c
	The main function takes in one argument: the name of the CSV file. If the file does not exist or if this argument is not provided through the command line, print out of an error and end the program. If the file exists, the main() will open the file and call the appropriate functions in airlinestats.c to load the contents into an array of Record struct. After it has loaded, it will go into an infinite loop where it will call the printMenu() function and ask the user to make a selection.
	The switch statement will process the user input. Depending on the selection, the main() will ask the user for more inputs and then call the appropriate functions in airlinestats.c. The base code for the main has already been started for you. You need to write code where the comments are mentioned.
	
	
TASK 4: Makefile
	Create a makefile that will create the executable.

Output
	The sample output file shows an example of a user entering various options. Your output does not need to match exactly in terms of format, but it should be similar. The sample output only demonstrates part of the output for the printAllRecords() functionality as the complete listing would be too long.

Submission
	makefile. and airlinestats.c, airlinestats.h,, main.h, main.cBe sure that your code follows the class coding style requirements. Your output should be similar in format as compared to the sample output attached. Submit your program on Blackboard as individual files (or as a zip file) before the due date –  main.c, main.h, airlinestats.c, airlinestats.h, and makefile.