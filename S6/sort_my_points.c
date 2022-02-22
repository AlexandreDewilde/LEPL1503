#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>


typedef struct points 
{
    int NOMA;
    float LEPL1103;
    float LEPL1203;
    float LEPL1108;
    float LEPL1302;
    float LEPL1402;
    float average;
} points_t;

/*
* Function used to compare two structures based on their averages.
*
* @s1 : a pointer to the first structure
* @s2 : a pointer to the second structure
*
* @return an integer less than, equal to, or greater than zero if the first argument is considered to be
*        respectively less than, equal to, or greater than the second
*/
int compar(const void* s1, const void* s2)
{
    points_t *p1, *p2;
    p1 = (points_t*) s1;
    p2 = (points_t*) s2;


    if (p1->average == p2->average) return 0;
    if (p1->average < p2->average) return -1;
    return 1;
}


/*
* Function used to update the file with the structures stored in it
*
* @filename : the path indicating where to find the file (!= NULL)
*
* @return 0 if no error
*        -1 if open failed
*        -2 if mmap failed
*        -3 if munmap failed
*        -4 if msync failed
*        -5 if fstat failed
*        -6 if close failed
*/
int sort(char* filename)
{
        int fd;
    int* ptr;
    int ret = 0;
    points_t* p1;
    ssize_t bytes;
    struct stat file_stat;

    if ((fd = open(filename, O_RDWR)) == -1) return -1;

    if (fstat(fd, &file_stat) == -1)
    {
        if (close(fd) == -1) return -6;
        return -5;
    }

    bytes = file_stat.st_size;

    if ((ptr = mmap(NULL, bytes, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED) 
    {
        if (close(fd) == -1) return -6;
        return -2;
    }
    int size = bytes / sizeof(points_t);
    p1 = (points_t*) ptr;
    for (int i=0; i < size; i++)
    {
        p1->average = (p1->LEPL1103 + p1->LEPL1203 + p1->LEPL1108 + p1->LEPL1302 + p1->LEPL1402) / 5;
        ++p1;
    }
    qsort(ptr, size, sizeof(points_t), compar);
    if (msync(ptr, bytes, MS_SYNC) == -1)
    {
        ret = -4;
    }


    if (munmap(ptr, bytes) == -1)
    {
        ret = -3;
    }

    if (close(fd) == -1) return -6;
    return ret;
}