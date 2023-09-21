
#include <stdio.h>
#include <string.h>

int namefilepointposition(char *fullname){
   int i;
   for(i=0;i<strlen(fullname);i++){
       if(fullname[i]=='.')
        break;
   } 
   if(i>=strlen(fullname))
        return -1;
    else
        return i;
}



int word2vec(char *pNomeTxtEntrada){
    FILE *arqent, *arqsaida;
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeTxtEntrada);
    int pp;
    char c;
//Generating Output filename    
    if(pointidx>=0){
        for(pp=0;pp<pointidx;pp++)
            nomarq[pp] = pNomeTxtEntrada[pp];
        nomarq[pp] = '\0';//End of string
    }
    else
        strcpy(nomarq,  pNomeTxtEntrada);
        
    strcat(nomarq,  "_Vocabulo");
    strcat(nomarq,  ".txt");
    printf("\nRecebi no nome do arquivo: %s", nomarq);

//Generating the output:
    arqent = fopen("AcimaDoSol.txt", "r");
    arqsaida = fopen("AcimaDoSol_Vocabulo.txt", "w");

    if(arqsaida != NULL){

    while((c = getc(arqent)) != EOF){
        if(c == ' '){
            fputs("\n", arqsaida);
            continue;
        }else if (c == '\n'){
            fputs("\n", arqsaida);
            continue;
        }
        else{
            fputc(c, arqsaida);
        }
    }

    }else
    printf('Não foi possivel abrir o arquivo.');

    fclose(arqent);
    fclose(arqsaida);
    return 1;
}


int main()
{
    char nomearq[30];
    printf("Entre com nome do arquivo:");
    scanf("%s",nomearq);
    if (!word2vec(nomearq))
        printf("\nErro na geração do vocábulo!");
    else
        printf("\nGerei o vocábulo!");
    

    return 0;
}
