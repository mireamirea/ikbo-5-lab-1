#include <stdio.h>
#include <string.h>
#define n 255
struct package {
	int x;
	char c[n];
	float y;
};
int main(int argc, char *argv[])
{
	FILE *Text;
	char name[n];
	int i=0, size = 0;
	struct package s;
	if (argc != 2) {
		printf("Enter file name.\n");
		scanf("%s", name);
	}
	else
		strcpy(name, argv[1]);
	Text = fopen(name, "rb");
	while (Text == NULL) {
		printf("File not found.\nPls enter name again.\n");
		scanf("%s", name);
		Text = fopen(name, "rb");
	}
	printf("Your data:\n");
	while (fread(&s, sizeof(struct package),1, Text)) {
		printf("%2d|%s|%f\n", s.x, s.c, s.y);
		i++;
	}
	size = i * sizeof(struct package);
	printf("File size:%d \n", size);
	return(0);
}
