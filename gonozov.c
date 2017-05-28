#include <stdio.h>
#include <stdlib.h>


struct reg {
int num;
char str[256];
float numf;
};


int main(int argc, char **argv) {

struct reg p;
 printf("%s\n", argv[1]);
FILE *fp;

fp = fopen(argv[1], "rb");
if (fp == NULL) {
printf("Cannot open file\n");
return 1;
}


while (fread(&p , sizeof(struct reg),1, fp))
printf("%d %s %f\n", p.num, p.str, p.numf);

fseek(fp, 0, SEEK_END);
int lSize = ftell(fp);
rewind(fp);
printf("Size in bytes : %d\n", lSize);

fclose(fp);
return 0;
}
