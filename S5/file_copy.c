#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>


/*
 * @pre file_name != NULL, name of the original file
 *      new_file_name != NULL, name of the new file (the copy)
 *
 * @post copy the contents of {file_name} to {new_file_name}.
 *       return 0 if the function terminates with success, -1 in case of errors.
 */
int copy(char *file_name, char *new_file_name) 
{

    int fd, fd_new_file;
    void* ptr, *ptr_new_file;
    struct stat file_stat;
    int ret = -1;


    if ((fd = open(file_name, O_RDONLY)) == -1) return -1;


    if (fstat(fd, &file_stat) == -1)
    {
        close(fd);
        return -1;
    }

    if ((fd_new_file = open(new_file_name, O_RDWR | O_CREAT, file_stat.st_mode)) == -1)
    {
        close(fd_new_file);
        close(fd);
        return -1;
    }

    if (ftruncate(fd_new_file, file_stat.st_size) == -1)
    {
        close(fd_new_file);
        close(fd);
        return -1;
    }

    if ((ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED) 
    {
        close(fd_new_file);
        close(fd);
        return -1;
    }

    if ((ptr_new_file = mmap(NULL, file_stat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd_new_file, 0)) == MAP_FAILED)
    {
        close(fd_new_file);
        close(fd);
        return -1;
    }

    memcpy(ptr_new_file, ptr, file_stat.st_size);
    if (msync(ptr_new_file, file_stat.st_size, MS_SYNC) < 0)
    {
        close(fd_new_file);
        close(fd);
        return -1;
    }
    
    ret = 0;

    if (munmap(ptr_new_file, file_stat.st_size) == -1) ret = -1;

    if (munmap(ptr, file_stat.st_size) == -1) ret = -1;

    
    if (close(fd_new_file) == -1) ret = -1;

    if (close(fd) == -1) ret = -1;
    return ret;
}