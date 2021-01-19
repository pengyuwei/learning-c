#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/*
http://www.cplusplus.com/reference/cstdio/fwrite/
http://www.cplusplus.com/reference/cstdio/fread/
*/

int write_bin(const char* tmpfile)
{
    FILE* fp = fopen(tmpfile, "wb");
    assert(fp != NULL);

    char buf[1024] = {0};
    fwrite(buf, sizeof(buf), 1, fp);
    fclose(fp);

    return 0;
}

int read_bin(const char* tmpfile)
{
    FILE* fp = fopen(tmpfile, "rb");
    assert(fp != NULL);

    char buf[2048] = {0};
    size_t n = fread(buf, 1, sizeof(buf), fp);
    printf("read %zu bytes\n", n);

    if (feof(fp)) {
        printf("EOF\n");
    } else if (ferror(fp)) {
        perror("ERROR!");
    } else {
        printf("OK\n");
    }

    fclose(fp);
    return 0;
}

int delete_file(const char* tmpfile)
{
    system("rm /tmp/fileio.test");
    return 0;
}

int main(int argc, char** argv)
{
    const char* tmpfile = "/tmp/fileio.test";

    write_bin(tmpfile);
    system("ls -l /tmp/fileio.test");
    read_bin(tmpfile);

    delete_file(tmpfile);
    return 0;
}