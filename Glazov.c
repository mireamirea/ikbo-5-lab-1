#include <stdio.h>
#include <stdlib.h>

struct package{
    int x;
    char c[255];
    float y;
};

int main (int argc, char* argv[]) {
    FILE *f;
    f = fopen("data.dat", "rb");
    if (f == NULL) {
        printf("Can't open file\n");
        return 0;
    }
    struct package p;
    int i = 0;
    while (fread(&p, sizeof(struct package), 1, f)){
        printf("%d | %s | %f \n", p.x, p.c, p.y);
    }
    fseek(f, 0, SEEK_END);
    int fileSize = ftell(f);
    rewind(f);
    printf("Size in bytes : %d\n", fileSize);

    fclose(f);
    return 0;
}
