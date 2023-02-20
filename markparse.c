#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum 
{
    TOKEN_ASTERISK,
    TOKEN_CHAR,
    TOKEN_LBRACK,
    TOKEN_RBRACK,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_STRING,
    TOKEN_LINK,
    TOKEN_LIST,
    TOKEN_NEWLINE,
    TOKEN_EMPTY,
    TOKEN_HEADER,
    TOKEN_DIGIT,
    TOKEN_EOF
} TokenType;


typedef struct TokenData 
{
    char * Text;
    int Line_Num;
    token_type Type;
    int Header_Count;
} TokenData;

typedef struct MDDocument 
{
    int Size;
    int *Mem_Data;
    char * Filepath;
} MDDocument;

MDDocument mp_load(MDDocument *doc, const char* filepath) 
{
    MDDocument Loaded_File = {};

    FILE *fp = fopen(filepath, "rb");
    if (!fp)
        perror("Markparse could not find filepath.");
    
    fseek(fp, 0, SEEK_END);
    Loaded_File.Size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    Loaded_File.Mem_Data = malloc(Loaded_File.Size);
    fread(Loaded_File.Mem_Data, Loaded_File.Size, 1, fp);
    fclose(fp);
    
    return(Loaded_File);
}


void mp_free(MDDocument *doc)
{
    free(doc.Mem_Data);
}

int main() 
{

   MDDocument X = mp_load("./markdown.md");
   free(X.Mem_Data);

   return 0;
}

