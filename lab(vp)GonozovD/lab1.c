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
 fp = fopen("data.dat", "rb");
if (fp == NULL) { // открыть файл удалось?
printf("Ne ydalos otkrit");
return 0;
}


while (fread(&p , sizeof(struct reg),1, fp))
printf("%d %s %f\n", p.num, p.str, p.numf);

// определяем размер файла
fseek(fp, 0, SEEK_END); // устанавливаем позицию в конец файла
int lSize = ftell(fp); // получаем размер в байтах
rewind(fp);
printf("Size in bytes : %d\n", lSize);

fclose(fp);

}
