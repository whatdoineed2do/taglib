#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int fepos(FILE* f_)
{
    int cur = ftell(f_);
    fseek(f_, 0, SEEK_END);
    int  pos = ftell(f_);
    fseek(f_, cur, SEEK_SET);
    return pos;
    
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        return -1;
    }

    const char*  file = argv[1];

    int fd;
    if ( (fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0660)) < 0) {
        printf("failed to create data file '%s' - %s\n", file, strerror(errno));
        return -1;
    }

    const char*  data = "0123456789abcdef";
    write(fd, data, strlen(data));
    fsync(fd);
    close(fd);
    fd = -1;

    char buf[1024];
    FILE*  f = fopen(file, "rb+");
    if (f == NULL) {
        printf("failed to open file '%s'", file);
        return -1;
    }
    fread(buf, 1, 8, f);  // prime stream's internal buffer

    int  epos = fepos(f);
    printf("epos %ld\n", epos);

    fseek(f, 10, SEEK_SET);
    ftruncate(fileno(f), 10);
    if (*argv[2] == '0') {
        printf("NOT flushing post truncate, old data remains\n");
    }
    else {
        printf("flushing post truncate\n");
        fflush(f);
    }

    epos = fepos(f);
    printf("epos after truncate %ld\n", epos);

    // this reads the contents of the file as BEFORE the truncate
    int r = fread(buf, 1, sizeof(buf), f);
    buf[r] = '\0';
    printf("fread %ld - '%s'\n", r, buf);

    fclose(f);


   return 0;
}
