#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * @pre filename != NULL
 * @post return 0 if the file {filename} exist. -1 Otherwise.
 */
int file_exists(char *filename)
{
    int res = open(filename, O_RDONLY);
    close(res);
    if (res == -1) return res;
    return 0;
}