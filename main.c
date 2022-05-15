#include <stdio.h>
#include <time.h>
int main() {
FILE * fp;

char mainbody[800];
char author[800];
time_t currentdate;
int day, month, year;



time(&currentdate);

struct tm *local = localtime(&currentdate);



day = local->tm_mday;
month = local->tm_mon + 1;
year = local->tm_year + 1900;
// Initial input
printf("Enter body ");
fgets(mainbody, 800, stdin);
printf("Enter author name ");
fgets(author, 800, stdin);

fp = fopen("index.html", "w+");
rewind(fp);
fprintf(fp, "<!DOCTYPE html><html lang='en'><head> <meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1.0'></head><body>\n");


fprintf(fp, "<h1>the shrimp blog</h1>\n");
fprintf(fp, "<p>%s<p>\n", mainbody);
fprintf(fp, "<title>test</title>\n");
fprintf(fp, "<p>author: %s date: %d/%d/%d <p> ", author, day, month, year); 
fclose(fp);

}
