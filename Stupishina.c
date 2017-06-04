#include <stdio.h>
#include <string.h>

typedef struct PACK {
int x;
char c[255];
float y;
} PACK;

int main(int argc, char *argv[]) {
FILE *File;
char name[255];
PACK pack;
if (argc != 2) {
printf("Enter file name.\n");
scanf("%s", name);
}
else
strcpy(name, argv[1]);
File = fopen(name, "rb");
while (File==NULL) {
printf("Error. File not found.\n");
scanf("%s", name);
File=fopen(name, "rb");
}
while (fread(&pack, sizeof(PACK), 1, File)) {
printf("%d | %s | %f \n", pack.x, pack.c, pack.y);
}
printf("Size = %ld\n", ftell(File));
fclose(File);
return 0;
}
