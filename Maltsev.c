#include <stdio.h>
#include <stdlib.h>


struct package
{
    int a;
    char b[255];
    float c;
};
int main(int argc , char *argv[])
{
    FILE *otcr;
    char rz [255];
    struct  package pack;
    int i=0;
    if(!(otcr=fopen(argv[1],"rb")) || (argc==1))
    { printf("Enter the file name\n");
    scanf("%s",rz);
    if (!(otcr=fopen(rz,"rb")))
    {printf("Cant use this file");
     return 0;
    }
 else printf ("Using file %s\n", rz);
    }
else printf("Using file %s\n", argv[1]);
while ( fread(&pack, sizeof(struct package),1,otcr))
{
    printf("%d| %s| %f \n",pack.a, pack.b, pack.c);
    i++;
}
printf("Size:%d\n",i+sizeof(struct package));
fclose (otcr);
return 0;
}
