#include <stdio.h> 
#include <stdlib.h> 

struct zzz { 
int x; 
char rr[255]; 
float y; 
}; 
int main(int argc, char *argv[]) 
{ 
struct zzz p1; 
FILE *fp; 
int i = 0; 
if ( (argc != 2) || ( !( fopen(argv[1], "rb") ) ) ) 
{ 
printf("fael: %s name\n", argv[0]); 
return 1; 
} 
fp = fopen(argv[1], "rb"); 
while (fread(&p1, sizeof(struct zzz), 1, fp)) 
{ 
printf("%d,%s,%f\n", p1.x, p1.rr, p1.y); 
i++; 
} 
fclose(fp); 
printf("-----------------------------"); 
printf("Size of file: %lu", (unsigned long)(i* sizeof(struct zzz))); 

return 0; 
}
