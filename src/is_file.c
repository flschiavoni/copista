#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int is_file(const char *path){
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
