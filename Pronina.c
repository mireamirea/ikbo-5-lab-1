#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define n 255


struct package {
	int x;
	char c[n];
	float y;
};

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Russian");
	int i, size;
	char name[n];
	FILE *file;
	i = 0; size = 0;
	struct package pack;
	if (argc != 2) {
		printf("Введите название файла.\n");
		scanf("%s", name);
	}
	else
		strcpy(name, argv[1]);
	file = fopen(name, "rb");

	while (file == NULL) {
		printf("Файл не найден. Попробуйте еще раз.\n");
		scanf("%s", name);
		file = fopen(name, "rb");
	}
	printf("Файл:\n");
	while (fread(&pack, sizeof(struct package), 1, file)) {
		printf("%2d | %s | %f \n", pack.x, pack.c, pack.y);
		i++;
	}
	fclose(file);
	size = i * sizeof(struct package);
	printf("Размер файла:%d", size);
	return(0);
}
