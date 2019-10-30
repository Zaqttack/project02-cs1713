#include <stdio.h>
#include <stdlib.h>
#include "airlinestats.h"

int getRecordCount(FILE* fileIn) {
	int recordLength = 0;
	char buff[1000];
	AirlineInfo count;
	
	while(fgets(buff, sizeof(buff), fileIn) != NULL) {
		fscanf(fileIn, "%d,%d,%d,%d,%s,%s,%s,%s", &count.deptartures, &count.seatsAvl, &count.totalPassengers, &count.cargoWeight, count.airlineCode, count.airlineName, count.airlineCodeOrigin, count.airlineCodeDestination);
		recordLength++;
	}
	
	rewind(fileIn);
	
	return recordLength;
}

void fillRecords(FILE *fileIn, AirlineInfo *data, int length) {
	int i;
	
	for(i = 0; i <= length; i++) {
		fscanf(fileIn, "%d,%d,%d,%d,%[^,]s,%[^,]s,%[^,]s,%[^,]s", &data[i].deptartures, &data[i].seatsAvl, &data[i].totalPassengers, &data[i].cargoWeight, data[i].airlineCode,  data[i].airlineName, data[i].airlineCodeOrigin, data[i].airlineCodeDestination);
	}
}
/*
void sortRecords(AirlineInfo *data, int min, int max) {
	int mid;
	
	if(min < max) {
		mid = (min + max) / 2;
		
		sortRecords(data, min, mid);
		sortRecords(data, mid + 1, max);
		
		merge(data, min, mid, max);
	}
}

void merge(AirlineInfo *data, int min, int mid, int max) {
	int mergedSize = max - min + 1;
	char mergedNames[mergedSize];
	int mergePos;
	int leftPos;
	int rightPos;
	
	mergePos = 0;
	leftPos = min;
	rightPos = mid + 1;
	
	while(leftPos <= mid && rightPos <= max) {
		if(data[leftPos].airlineName < data[rightPos].airlineName) {
			mergedNames[mergePos] = data[leftPos].airlineName;
			++leftPos;
		}
		else {
			mergedNames[mergePos] = data[rightPos].airlineName;
			++rightPos;
		}
		++mergePos;
	}
	
	while(leftPos <= mid) {
		mergedNames[mergePos] = data[leftPos].airlineName;
		++leftPos;
		++mergePos;
	}
	
	while(rightPos <= max) {
		mergedNames[mergePos] = data[rightPos].airlineName;
		++rightPos;
		++mergePos;
	}
	
	for(mergePos = 0; mergePos < mergedSize; mergePos++) {
		data[min + mergePos].airlineName = mergedNames[mergePos];
	}
}
*/
void mergeRecords(AirlineInfo *data, int low , int mid , int high) {
	
}

void printRecord(AirlineInfo data) {
	printf("%d %d %d %d %s %s %s %s\n", data.deptartures, data.seatsAvl, data.totalPassengers, data.cargoWeight, data.airlineCode, data.airlineName, data.airlineCodeOrigin, data.airlineCodeDestination);
}

void printAllRecords(AirlineInfo *data, int length) {
	int i;
	
	for(i = 0; i < length; i++) {
		printRecord(data[i]);
	}
}

AirlineInfo findRecord(AirlineInfo *data, int length, char *code, char *origin, char *destination) {
	
}

void computeStatistics(AirlineInfo *data, int length, SearchType type, char *entry) {
	
}