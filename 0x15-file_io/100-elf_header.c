#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks filee is an elf
 * @e_ident: pointer
 * Description: if file isn't elf - exit code 98
 */
void check_elf(unsigned char *e_ident)
{
int index;
for (index = 0; index < 4; index++)
{
if (e_ident[index] != 137 &&
    e_ident[index] != 'E' &&
    e_ident[index] != 'L' &&
    e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * print_magic - prints the magic numbers of ELF
 * @e_ident: a pointer 
 * Description: Magic numbers are seperated by space
 */
void print_magic(unsigned char *e_ident)
{
int index;
printf( "  Magic:   ");

for (index = 0; index < EI_NIDENT, index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
 * print_class - prints class of ELF
 * @e_ident: pointer
 */
void print_class(unsigned char *e_ident)
{
printf("  Class:                           ")

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * print_data - prints data
 * @e_ident: pointer
 */
void print_data(unsigned char *e_ident)
{
printf(" Data:                              ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**print_version: prints version
 * @e_ident: pointer
 */
void print_version(unsigned char *e_ident)
{
printf(" Version:                                 %d"
e_ident[EI_VERSION]);

SWITCH (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf("  (current)\n");
break;

default:
printf("\n");
break;
}
