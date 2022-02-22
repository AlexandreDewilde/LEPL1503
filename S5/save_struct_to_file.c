#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

typedef struct point 
{
    int x;
    int y;
    int z;
} point_t;
/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename) 
{
    int fd;
    int ret = 0;
    void* ptr;

    ssize_t bytes = size * sizeof(point_t);
    if ((fd = open(filename, O_RDWR | O_CREAT , S_IRWXU)) == -1) return -1;

    if (ftruncate(fd, bytes) == -1)
    {
        if (close(fd) == -1) return -2;
        return -6;
    }

    if ((ptr = mmap(NULL, bytes, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED) 
    {
        if (close(fd) == -1) return -2;
        return -3;
    }

    memcpy(ptr, pt, bytes);

    if (msync(ptr, bytes, MS_SYNC) == -1)
    {
        if (close(fd) == -1) return -2;
        return -5;
    }

    if (munmap(ptr, size) == -1)
    {
        ret = -4;
    }

    if (close(fd) == -1) return -2;
    return ret;
}