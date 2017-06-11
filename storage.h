#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool Storage_Init();
bool Storage_WriteBuffer(size_t address, uint8_t *buffer, size_t bufferSize);
bool Storage_ReadBuffer(size_t address, uint8_t *buffer, size_t bufferSize);
size_t Storage_GetMemorySize();
void Storage_PrintMemory(size_t numOfBytes);