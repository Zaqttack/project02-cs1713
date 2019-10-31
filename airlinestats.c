#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airlinestats.h"

int getRecordCount(FILE* fileIn) {
	int recordLength = 0;
	char buff[1000];
	AirlineInfo count;
	
	while(fgets(buff, sizeof(buff), fileIn) != NULL) {
		fscanf(fileIn, "%d,%d,%d,%d,%[^,],%[^,],%[^,],%[^\n,]", &count.deptartures, &count.seatsAvl, &count.totalPassengers, &count.cargoWeight, count.airlineCode, count.airlineName, count.airlineCodeOrigin, count.airlineCodeDestination);
		recordLength++;
	}
	
	rewind(fileIn);
	
	return recordLength;
}

void fillRecords(FILE *fileIn, AirlineInfo *data, int length) {
	int i;
	
	for(i = 0; i <= length; i++) {
		fscanf(fileIn, "%d,%d,%d,%d,%[^,],%[^,],%[^,],%[^\n,]", &data[i].deptartures, &data[i].seatsAvl, &data[i].totalPassengers, &data[i].cargoWeight, data[i].airlineCode,  data[i].airlineName, data[i].airlineCodeOrigin, data[i].airlineCodeDestination);
	}
}

void sortRecords(AirlineInfo *data, int low, int high) {
	int mid;
	
	if(low < high) {
		mid = (low + high) / 2;
		
		sortRecords(data, low, mid);
		sortRecords(data, mid + 1, high);
		
		mergeRecords(data, low, mid, high);
	}
}

void mergeRecords(AirlineInfo *data, int low , int mid , int high) {
	int mergedSize = high - low + 1;
	AirlineInfo mergedNames[mergedSize];
	int mergePos = 0;
	int leftPos = low;
	int rightPos = mid + 1;
	
	while(leftPos <= mid && rightPos <= high) {
		if(strcmp(data[leftPos].airlineName, data[rightPos].airlineName) < 0) {
			mergedNames[mergePos++] = data[leftPos++];
		}
		else {
			mergedNames[mergePos++] = data[rightPos++];
		}
	}
	
	while(leftPos <= mid) {
		mergedNames[mergePos++] = data[leftPos++];
	}
	
	while(rightPos <= high) {
		mergedNames[mergePos++] = data[rightPos++];
	}
	
	for(mergePos = 0; mergePos < mergedSize; ++mergePos) {
		data[low + mergePos] = mergedNames[mergePos];
	}
}

void printRecord(AirlineInfo data) {
	printf("%-11d%-12d%-12d%-12d%-12s%-50s%-12s%s\n", data.deptartures, data.seatsAvl, data.totalPassengers, data.cargoWeight, data.airlineCode, data.airlineName, data.airlineCodeOrigin, data.airlineCodeDestination);
}

void printAllRecords(AirlineInfo *data, int length) {
	int i;
	printf("nDeparts   nSeats      nPassengers freight     airlineCode airlineName                                       oiriginCode destCode\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	for(i = 0; i < length; i++) {
		printRecord(data[i]);
	}
}

AirlineInfo findRecord(AirlineInfo *data, int length, char *code, char *origin, char *destination) {
	AirlineInfo noRecordFound;
	noRecordFound.deptartures = -999;
	int i;
	for(i = 0; i < length; i++) {
		printf("%s = %s\n", data[i].airlineCode, code);
		printf("%s = %s\n", data[i].airlineCodeOrigin, origin);
		printf("%s = %s\n", data[i].airlineCodeDestination, destination);
		if(strcmp(data[i].airlineCode, code) == 0 && strcmp(data[i].airlineCodeOrigin, origin) == 0 && strcmp(data[i].airlineCodeDestination, destination) == 0) {
			return data[i];
		}
		else {
			return noRecordFound;
		}
	}
}

void computeStatistics(AirlineInfo *data, int length, SearchType type, char *entry) {
	
}