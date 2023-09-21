/* Creating a file copy */
#include <stdio.h>
int main(){

  FILE *fOriginal, *fCopia;
  char ch;
  fOriginal = fopen ("arquivo1.txt", "r" );
  if (fOriginal == NULL )
  {
    puts ( "Nao foi possivel abrir o arquivo!!!" ) ;
    
  }
  fCopia = fopen ("Copia_Arquivo1.txt", "w" );
  if (fCopia == NULL )
  {
    puts ( "Nao foi possivel gravar o arquivo!!!" ) ;
    
  }
  while ( 1 )
  {
    ch = fgetc(fOriginal);
    if(ch==EOF)
      break;
    fputc (ch, fCopia);
  }
  fclose (fOriginal);
  fclose (fCopia);
  return 0;
}