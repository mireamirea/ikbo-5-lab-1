#include <stdio.h>
#include <string.h>

struct package {
	int x;
	char c[255];
	float y;
};
int main(int argc, char *argv[]) {
	FILE *fp;
   	char name[255];
	int i=0, size = 0;
	struct package p;
	if (argc != 2) {
		printf("Enter file name.\n");
		scanf("%s", name);
	}
	else
    	strcpy(name, argv[1]);
	fp = fopen(name, "rb");
	while (fp == NULL) {
		printf("Can't open file. Try again.\n");
		scanf("%s", name);
		fp = fopen(name, "rb");
	}
	printf("Open file:\n");
	while (fread(&p, sizeof(struct package),1, fp)) {
		printf("%d | %s | %f \n", p.x, p.c, p.y);
		i++;
	}
	fclose(fp);
	size = i * sizeof(struct package);
	printf("File size: %d bytes.\n", size);
	return(0);
}




