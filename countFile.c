#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

ssize_t countFile(char* dirPath)
{
    register struct dirent *el = NULL;
    DIR *d = NULL;
    register ssize_t count = 0;

    if(NULL == dirPath) return 1;

    d = opendir(dirPath);
    if(NULL == d) return -1;

    for(errno = 0 ; (el = readdir(d)) ; ((DT_REG == el->d_type) ? (count++) : ((void)0)));

    closedir(d);

    return (errno) ? -1 : count;
}
