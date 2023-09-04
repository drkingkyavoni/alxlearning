#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char *msg)
{
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(98);
}

void display_elf_header(const char *filename)
{
    int i, fd;
	Elf64_Ehdr elf_header;
	ssize_t bytes_read;

	fd = open(filename, O_RDONLY);
    if (fd == -1)
        print_error("Error: Unable to open file");


    bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr))
        print_error("Error: Unable to read ELF header");

    close(fd);

    printf("ELF Header:\n");
    printf("  Magic: ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", elf_header.e_ident[i]);
    printf("\n");

    printf("  Class: \t\t\t%d-bit\n", (elf_header.e_ident[EI_CLASS] == ELFCLASS32) ? 32 : 64);
    printf("  Data: \t\t\t%s\n", (elf_header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version: \t\t\t%d\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI: \t\t\t%s\n", (elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX System V ABI" : "Unknown");
    printf("  ABI Version: \t\t\t%d\n", elf_header.e_ident[EI_ABIVERSION]);

    printf("  Type: \t\t\t");
    switch (elf_header.e_type)
    {
        case ET_NONE:
            printf("NONE (No file type)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    printf("  Entry point address: \t\t0x%lx\n", elf_header.e_entry);
}

int main(int argc, char **argv)
{
	const char *elf_filename;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    elf_filename = argv[1];
    display_elf_header(elf_filename);

    return 0;
}
