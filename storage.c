#include "storage.h"
#include <stdio.h>

#ifndef UNITTESTS
    #define STATIC
#else
    #define STATIC static
#endif

#define FILE_NAME		"myData.txt"
#define MEMORY_SIZE		(4 * 1024)
uint8_t memory[MEMORY_SIZE];

STATIC bool writeDataToFile();
STATIC bool readDataFromFile();

bool Storage_Init()
{
	bool result = readDataFromFile();
	return result;
}

bool Storage_WriteBuffer(size_t address, uint8_t *buffer, size_t bufferSize)
{
	if (address + bufferSize > MEMORY_SIZE)
	{
		return false;
	}
	memcpy((&memory[address]), buffer, bufferSize);
	bool result = writeDataToFile();
	return result;
}

bool Storage_ReadBuffer(size_t address, uint8_t *buffer, size_t bufferSize)
{
	if (address + bufferSize > MEMORY_SIZE)
	{
		return false;
	}
	memcpy(buffer, (&memory[address]), bufferSize);
	return true;
}

size_t Storage_GetMemorySize()
{
	return MEMORY_SIZE;
}

void Storage_PrintMemory(size_t numOfBytes)
{
	for (int i = 0; i < numOfBytes; i+=16)
	{
		printf("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n",
			memory[i],
			memory[i+1],
			memory[i+2],
			memory[i+3],
			memory[i+4],
			memory[i+5],
			memory[i+6],
			memory[i+7],
			memory[i+8],
			memory[i+9],
			memory[i+10],
			memory[i+11],
			memory[i+12],
			memory[i+13],
			memory[i+14],
			memory[i+15]);
	}
}

STATIC bool writeDataToFile()
{
	FILE *fp;
	fp = fopen(FILE_NAME, "w+");
	if (fp == 0)
	{
		return -1;
	}
	size_t numOfWrittenBytes = fwrite((const void*)memory, 1, MEMORY_SIZE, fp);
	fclose(fp);
	return numOfWrittenBytes == MEMORY_SIZE;
}

STATIC bool readDataFromFile()
{
	FILE *fp;
	fp = fopen(FILE_NAME, "r");
	if (fp == 0)
	{
		return -1;
	}
	fread((void*)memory, 1, MEMORY_SIZE, fp);
	fclose(fp);
	return true;
}