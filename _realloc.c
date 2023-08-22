#include "shell.h"
/**
 * *_realloc - reallocate memory size function
 * @ptr: pointer to address of old memory location
 * @size: unsigned int type of memory size
 * Return:  return pointer to array
 */
void *_realloc(void *ptr, size_t size)
{
	void *newPtr;

	if (ptr == NULL)
	{
		return (malloc(size));
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	newPtr = malloc(size);
	if (newPtr == NULL)
	{
		return (NULL);
	}
	_memcpy(newPtr, ptr, size);
	free(ptr);
	return (newPtr);
}
