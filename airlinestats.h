#ifndef AIRLINESTATS_H
#define AIRLINESTATS_H

/* Your Record struct declaration will go here */
typedef struct AirlineInfo_struct {
	int deptartures;
	int seatsAvl;
	int totalPassengers;
	int cargoWeight;
	char airlineCode[3];
	char airlineName[100];
	char airlineCodeOrigin[4];
	char airlineCodeDestination[4];
} AirlineInfo;

/* This enumeration will be used to support the computeStatistics() function 
   by denoting the type of search (by airline, origin airport, or destination
   airport */
typedef enum SearchType {
	AIRLINE,
	ORIGIN,
	DESTINATION
}SearchType;

/* Prototypes have been provided to you. No further comments or code is needed here. */
void printRecord(AirlineInfo);
void printAllRecords(AirlineInfo*, int);
AirlineInfo findRecord(AirlineInfo*, int, char*, char*, char*);
int getRecordCount(FILE*);
void fillRecords(FILE*, AirlineInfo*, int);
void computeStatistics(AirlineInfo*, int, SearchType, char*);
void mergeRecords(AirlineInfo*, int, int, int);
void sortRecords(AirlineInfo*, int, int);

#endif