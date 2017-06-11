#include "storage.h"

#define FILE_NAME		"myData.bin"
#define MEMORY_SIZE		(64*1024)
uint8_t memory[MEMORY_SIZE];

static int writeDataToFile();
static int readDataFromFile();

bool Storage_Init()
{
	return false;
	return (readDataFromFile() >= 0);
}

int Storage_WriteBuffer(size_t address, uint8_t *buffer, size_t bufferSize)
{
	return -1;
}

int Storage_ReadBuffer(size_t address, uint8_t *buffer, size_t bufferSize)
{
	return -1;
}

size_t Storage_GetMemorySize()
{
	return MEMORY_SIZE;
}

static int writeDataToFile()
{
	return -1;
}

static int readDataFromFile()
{
	return -1;
	/*FILE *fp;
	fp = fopen(FILE_NAME, "r");

	size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

	size_t numOfReadBytes = fread((void*)memory, 1, MEMORY_SIZE, fp);*/
}