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
 * check_elf - Check for an ELF file
 * @e_ident: an array containing the ELF magic characters
 * Description: If an ELF file does not exits quit code 98.
 */
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
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
 * print_magic - print the magic numbers of an ELF
 * @e_ident: an array containing the ELF magic characters
 * Description: magic characters are separated by gaps
 */
void print_magic(unsigned char *e_ident)
{
int index;

printf(" Magic: ");

for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}
/**
 * print_class - print all the class in ELF
 * @e_ident: an array containing the ELF class
 */
void print_class(unsigned char *e_ident)
{
printf(" Class: ");

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
 * print_data - Print all the data in ELF
 * @e_ident: an array containing the ELF data
 */
void print_data(unsigned char *e_ident)
{
printf(" Data: ");

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

/**
 * print_version - Print all the version in an ELF header
 * @e_ident: an array containing the ELF version in the file
 */
void print_version(unsigned char *e_ident)
{
printf(" Version: %d",
e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}
/**
 * print_osabi - print all the OS/ABI in ELF
 * @e_ident: an array containing the ELF version
 */
void print_osabi(unsigned char *e_ident)
{
printf(" OS/ABI: ");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}
/**
 * print_abi - print all the ABI version in ELF
 * @h: an array containing all ELF ABI version
 */
void print_abi(Elf64_Ehdr h)
{
printf(" ABI Version: %d\n",
h.e_ident[EI_ABIVERSION]);
}
/**
 * print_type -print all type of an ELF
 * @h: an array containing the ELF class
 */
void print_type(Elf64_Ehdr h)
{
char *p = (char *)&h.e_type;
int i = 0;
printf(" Type: ");
if (h.e_ident[EI_DATA] == ELFDATA2MSB)
i = 1;
switch (e_type)
{
case ET_NONE:
printf("NONE (None)");
break;
case ET_REL:
printf("REL (Relocatable file)");
break;
case ET_EXEC:
printf("EXEC (Executable file)");
break;
case ET_DYN:
printf("DYN (Shared object file)");
break;
case ET_CORE:
printf("CORE (Core file)");
break;
default:
printf("<unknown>: %x", e_type);
break;
}
printf("\n") :
}
/**
 * print_entry - print the entry point of an ELF
 * @h: the address of entry in the ELF
 */
void print_entry(Elf64_Ehdr h)
int i = 0, len = 0;
unsigned char *p = (unsigned char *)&h.e_entry;
printf(" Entry point address: ");
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
i = h.e_ident{EI_CLASS} == ELFCLASS64 ? 7 : 3;
while (!p[i])
i--;
printf("%x", p[i--]};
for (; i >= 0; i--)
printf("%02x", p[i]);
printf("\n");
}
else
{
i = 0
len = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
while (!p[i])
i++
printf("%x", p[i++]);
for (; i <= len; i++)
printf("%02x", p[i]);
printf("\n");
}
}
/**
 * main - Display the information contained in ELF
 * at the beginning  of an ELF file
 * @argc: arguments supplied to the file
 * @argv: an array of pointers to the arguments
 * Return: 0 on success
 * Description: If the file is not an ELF File or exit code 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
int fd;
Elf64_Ehdr *header;
ssize_t b;

if (ac != 2)
dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
fd = open(argv[1], 0_RDONLY);
if (o == -1)
dprintf(STDERR_FILENO, "Can't read file %s\n", argv[1]);
exit(98);
b = read(fd, &h, sizeof(h));
if (b < 1 || b != sizeof(h))
dprintf(STDERR_FILENO, "Can't read file %s\n", argv[1]);
exit(98);
if (h.e_ident[0] == 0x7f && h.e_ident[1] == 'E' && h.e_ident[2] == 'L' &&
h.e_ident[3] == 'F')
{
printf("ELF Header:\n");
}
else
dprintf(STDERR_FILENO, "Not ELF file: %s\n", argv[1]);
exit(98);

print_magic(header);
print_class(header);
print_data(header);
print_version(header);
print_osabi(header);
print_abi(header);
print_type(header);
print_entry(header);
if close_elf(o);
dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", fd), exit(98);
return (EXIT_SUCCESS);
}
