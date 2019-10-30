/* 
    main.c
    Project 2 
    Firstname Lastname

    This is the driver for the airline statistics program. It displays 
    the main menu presenting a selection of options for the user to get 
    information about the airlines' international segments in and out of 
    the United States. The main function will then call functions in 
    airlinestats.c to compute and retrieve information.
*/
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "airlinestats.h"

int main(int argc, char *argv[]) 
{
	/* declare all your variables here */
	FILE *infp;
	AirlineInfo *Record;
	int recordLength, choice;

	/* check for the command line argument here, print out error message and 
		end program if it is not present */
	if (argc < 1) {
		printf("missing argument\n");
		exit(-1);
	}
	
	/* open file with the file name passed in through command line argument,
		print an error message end the program if the file does not open */
	infp = fopen(argv[1], "r");
	if (infp == NULL) {
		printf("file not available\n");
		exit(-1);
	}
	
	/* dynamically allocate your array of Record struct's, and load the the CSV
		contents with the information by using the getRecordCount() and fillRecords(). 
		then, call the sortRecords() function to sort the array by airline name. */
	recordLength = getRecordCount(infp);
	//fillRecords(Record, 0, recordLength - 1);
	//sortRecords();
	
	/* close the file pointer */
	fclose(infp);
	
	while(1)
	{
		/* Call the function to print the menu */
		printMenu();
		/* Get the menu choice from the user */
		scanf("%d", &choice);
		printf("\n");
		switch(choice)
        {
			case 1:
				/* 1) ask the user to enter an airline code
				   2) call the computeStatistics() function */
				   
				break;
            case 2:
                /* 1) ask the user to enter an origin airport code
                   2) call the computeStatistics() function */
				   
                break;
            case 3:
                /* 1) ask the user to enter a destination airport code
                   2) call the computeStatistics() function */
				   
				break;
            case 4:
                /* 1) ask the user to enter an airline code, an origin 
                      airport code, and a destination airport code
                   2) call findRecord() 
                   3) if the Record returned has a bad value, print out
                      that the record was not found.
                   4) otherwise, print out the record */
				   
                break;
            case 5:
                /* call printAllRecords() */
				printAllRecords(Record, recordLength);
                break;
            case 0:
            default:
                printf("Good-bye!\n\n");
                return 0;
        }
    }
    return 0;
}

/* 
    printMenu
    ---------------------------
    This function prints the main menu.
    Returns: Nothing
*/
void printMenu()
{
    printf("\n#########################################\n");
    printf("#         Airline Statistics Menu       #\n");
    printf("#########################################\n");
    printf("\t1 - Statistics by Airline\n");
    printf("\t2 - Statistics by Origin\n");
    printf("\t3 - Statistics by Destination\n");
    printf("\t4 - Find a record\n");
    printf("\t5 - Print all records\n");
    printf("\t0 - Quit\n");
    printf("Enter your selection: ");
}