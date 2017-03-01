#include <stdio.h>
#include <stdlib.h>


struct reg {
    int num;
    char str[255];
    float numf;
};


int main(int argc, char **argv) {

    struct reg p;
    FILE *fp;
    
    fp = fopen(argv[1], "rb\n");
    
    if (fp == NULL) {
        printf("Can't open file\n");
        return EXIT_FAILURE;
    }


    while (fread(&p , sizeof(struct reg),1, fp))
        printf("%d %s %f\n", p.num, p.str, p.numf);

    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    rewind(fp);
    printf("Size in bytes : %d\n", fileSize);

    fclose(fp);
    return EXIT_SUCCESS;
}
