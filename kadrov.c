#include <stdio.h>
 struct rega {
 int num;
 char str[256];
 float numf;
 };
             int main(int argc, char **argv) {
             struct rega p ;
             FILE *f;
             char strv;
             f = fopen(argv[1], "rb");
 if (f== NULL) {
 printf("cannot open file\n");
 }
     while (!f) {
     printf("write file name\n");
     scanf("%s",&strv);
     f = fopen(strv, "rb");
     }
 while (fread(&p , sizeof(struct rega),1, f))
 printf("%d %s %f\n", p.num, p.str, p.numf);
 fseek(f, 0, SEEK_END);
 int lSize = ftell(f);
 rewind(f);
 printf("Size in bytes : %d\n", lSize);
 fclose(f);
 return 1;
 }