#include <stdio.h>
struct package
{
    int x;
    char c [255];
    float y;
};
int main( int argc, char *argv[] )
{
    FILE *mf;
    char fn [255];
    struct package pack;
    int i = 0;

    if ( ! ( mf = fopen( argv[ 1 ], "rb" )) || ( argc == 1 ))
    {
        printf( "Enter file name\n" );
        scanf( "%s", fn );
        if ( ! ( mf = fopen( fn, "rb" )))
        {
            printf( "Cant use this file" );
            return 0;
        }
        else printf("Using file %s \n", fn);
    }
    else printf("Using file %s \n", argv[ 1 ]);

    while ( fread( &pack, sizeof(struct package), 1, mf ))
    {
        printf( "%d | %s | %f \n", pack.x, pack.c, pack.y );
        i++;
    }
    printf( "Size: %d \n", i * sizeof( struct package ));
    fclose( mf );
    return 0;
}
