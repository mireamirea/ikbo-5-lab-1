#include <stdio.h>
#include <string.h>
#define N 255
struct package {
	int x;
	char c[N];
	float y;
};
int main(int argc, char *argv[]) {
	FILE *TextFile;
	char name[N];
	int i=0, size = 0;
	struct package p;
	if (argc != 2) {
		printf("Enter file name.\n");
		scanf("%s", name);
	}
	else
		strcpy(name, argv[1]);
	TextFile = fopen(name, "rb");
	while (TextFile == NULL) {
		printf("File not found.\nTry again.\n");
		scanf("%s", name);
		TextFile = fopen(name, "rb");
	}
	printf("Your data:\n");
	while (fread(&p, sizeof(struct package),1, TextFile)) {
		printf("%2d | %s | %f \n", p.x, p.c, p.y);
		i++;
	}
	size = i * sizeof(struct package);
	printf("File size:%d", size);
	return(0);
}