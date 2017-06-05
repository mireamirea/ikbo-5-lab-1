#include <stdio.h>
#include <locale.h>
struct package
{
    int a;
    char b [255];
    float c;
};
int main( int argc, char *argv[] )
{
    setlocale(LC_ALL, "RUS");
    FILE *mf;
    char fn [255];
    struct package temp;
    int i = 0;

    if ( ! ( mf = fopen( argv[ 1 ], "rb" )) || ( argc == 1 ))
    {
        printf( "������� �������� �����\n" );
        scanf( "%s", fn );
        if ( ! ( mf = fopen( fn, "rb" )))
        {
            printf( "���������� ������������ ������ ����" );
            return 0;
        }
        else printf("������������ ���� %s \n", fn);
    }
    else printf("������������ ���� %s \n", argv[ 1 ]);

    while ( fread( &temp, sizeof(struct package), 1, mf ))
    {
        printf( "%d | %s | %.1f \n", temp.a, temp.b, temp.c );
        i++;
    }
    printf( "������: %d ����\n", i * sizeof( struct package ));
    fclose( mf );
    return 0;
}
