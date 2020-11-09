#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int
main ( int argc, char ** argv )
{
  if ( argc < 2 )
  {
    fprintf ( stderr, "Give me file name.\n" );
    exit ( 1 );
  }

  FILE * fp = fopen ( argv[1], "r" );

  size_t len;
  char * line = 0;

  int count = 1;

  while ( 1 )
  {
    if ( -1 == getline ( & line, & len, fp ) )
      break;

    ++ count;
  }

  double ninety_nine_percent = 0.99 * count;

  rewind ( fp );

  count = 0;

  while ( 1 )
  {
    getline ( & line, & len, fp );
    ++ count;

    if ( count > ninety_nine_percent )
    {
      fprintf ( stdout, "%s", line );
      break;
    }
  }

  
  return 0;
}

