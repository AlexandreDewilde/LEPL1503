#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

/*
 * @pre filename != NULL, name of the file
 * @post returns the sum of all integers stored in the binary file.
 *       return -1 if the file can not be open.
 *       return -2 if the file can not be closed.
 *       return -3 if mmap() fails.
 *       return -4 if munmap() fails.
 *       return -5 if fstat() fails.
 */
int sum_file(char *filename)
{
        int fd;
    int sum = 0;
    struct stat file_stat;

    if ((fd = open(filename, O_RDONLY)) == -1) return -1;
    
    if (fstat(fd, &file_stat) == -1)
    {
        if (close(fd) == -1) return -2;
        return -5;
    }
    ssize_t bytes = file_stat.st_size;

    if (bytes == 0)
    {
        if (close(fd) == -1) return -2;
        return 0;
    }
    int* ptr = mmap(NULL, bytes, PROT_READ, MAP_PRIVATE, fd, 0);

    if (ptr == MAP_FAILED)
    {
        if (close(fd) == -1) return -2;
        return -3;
    }

    for (int i = 0; i < bytes/sizeof(int); i++)
    {
        sum += ptr[i];
    }


    if (munmap(ptr, bytes) == -1) 
    {
        if (close(fd) == -1) return -2;
        return -4;
    }

    if (close(fd) == -1) return -2;
    return sum;
}
