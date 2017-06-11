#include "unity.h"
#include "storage.h"
#include <stdbool.h>

void setUp()
{
}

void tearDown()
{
}

void test_InitStorage()
{
	TEST_ASSERT(Storage_Init());
	TEST_ASSERT(Storage_GetMemorySize() != 0);
}

void test_writeDataToFile()
{
	TEST_ASSERT(writeDataToFile());
}

void test_readDataFromBFile()
{
	TEST_ASSERT(readDataFromFile());
}

void test_WriteBuffer()
{
	uint8_t buffer[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	TEST_ASSERT(Storage_WriteBuffer(10, buffer, 10));
}

void test_CheckWriteBufferBounds()
{
	size_t memorySize = Storage_GetMemorySize();
	uint8_t buffer[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	TEST_ASSERT(Storage_WriteBuffer(memorySize - 10, buffer, 10) == true);
	TEST_ASSERT(Storage_WriteBuffer(memorySize - 10, buffer, 11) == false);
	TEST_ASSERT(Storage_WriteBuffer(memorySize - 9, buffer, 9) == true);
}

void test_ReadBuffer()
{
	uint8_t buffer[20];
	TEST_ASSERT(Storage_ReadBuffer(10, buffer, 10));
}

void test_CheckReadBufferBounds()
{
	size_t memorySize = Storage_GetMemorySize();
	uint8_t buffer[20];
	TEST_ASSERT(Storage_ReadBuffer(memorySize - 10, buffer, 10) == true);
	TEST_ASSERT(Storage_ReadBuffer(memorySize - 10, buffer, 11) == false);
	TEST_ASSERT(Storage_ReadBuffer(memorySize - 9, buffer, 9) == true);
}

void test_dataStored()
{
	uint8_t buffer[20];
	memset(buffer, 0, 20);
	TEST_ASSERT(Storage_WriteBuffer(5, buffer, 20) == true);
	uint8_t readBuffer[20];
	TEST_ASSERT(Storage_ReadBuffer(5, readBuffer, 20) == true);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, readBuffer, 20);
	
	memset(buffer, 40, 20);
	TEST_ASSERT(Storage_WriteBuffer(5, buffer, 20) == true);
	TEST_ASSERT(Storage_ReadBuffer(5, readBuffer, 20) == true);
	TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer, readBuffer, 20);
}