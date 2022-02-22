#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>


/*
 * @pre filename != NULL, index >= 0
 * @post return the integer at the index {index}
 *       of the array in the file {filename}.
 *       return -1 in case of error.
 *       return -2 if index >= length of array.
 */
int get(char *filename, int index)
{
    int fd;
    int ret = -1;
    int* ptr;
    struct stat file_stat;

    if ((fd = open(filename, O_RDONLY)) == -1) return -1;

    if (fstat(fd, &file_stat) == -1) 
    {
        close(fd);
        return -1;
    }

    ssize_t bytes = file_stat.st_size;

    if (bytes <= index)
    {
        if (close(fd) == -1) return -1;
        return -2;
    }

    if ((ptr = mmap(NULL, bytes, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    {
        close(fd); 
        return -1;
    }


    ret = ptr[index];

    if (munmap(ptr, bytes) == -1) ret = -1;

    if (close(fd) == -1) return -1;
    return ret;
}


/*
 * @pre filename != NULL, index >= 0
 * @post set the element in the file {filename}
 *       at index {index} at value {value}.
 *       do nothing in case of errors
 */
void set(char *filename, int index, int value) 
{
    int fd;
    int* ptr;
    struct stat file_stat;

    if ((fd = open(filename, O_RDWR)) == -1) return;

    if (fstat(fd, &file_stat) == -1)
    {
        close(fd);
        return;
    }

    ssize_t bytes = file_stat.st_size;

    if (bytes <= index)
    {
        close(fd);
        return;
    }

    if ((ptr = mmap(NULL, bytes, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED) 
    {
        close(fd);
        return;
    }

    ptr[index] = value;
    msync(ptr, bytes, MS_SYNC);


    munmap(ptr, bytes);

    close(fd);
}
