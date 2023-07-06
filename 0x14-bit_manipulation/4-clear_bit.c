#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @n: a pointer
 * @index: The index to set the value at - indices starr at 0
 * Return: if an error - -1
 * Otherwise - 1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= (sizeof(unsigned long int) * 8))
return (-1);
*n &= ~(1 << index);
return (1);
}
