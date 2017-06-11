#include "unity.h"
#include "storage.h"

void setUp()
{
}

void tearDown()
{
}

void test_InitStorage()
{
	bool result = Storage_Init();
	TEST_ASSERT(result);
}
