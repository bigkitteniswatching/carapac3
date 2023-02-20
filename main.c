#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int wiki_readdir(const char *dir) 
{
    DIR *folder;
    int i = 0;
    struct dirent *entry;
    struct stat filestat;
    // Open given directory
    folder = opendir(dir);
    if(!folder) 
    {
        printf("No posts directory could be found.\n");
        return 1;
    }

    // Read in files, check if its null, if not, check the type of the file, and print it.
    while((entry = readdir(folder))) 
    {
        stat(entry->d_name, &filestat);
        if (entry->d_name[0] != '.') 
        {
            i++;
            FILE *fp;
            fp = fopen("./index.html", "a");
            fprintf(fp, "<li>");
            fprintf(fp, "<a href=");
            fprintf(fp, "./posts/");
            fprintf(fp, "%s>", entry->d_name);
            fprintf(fp, "%s", entry->d_name);
            fprintf(fp, "</a>");
            fprintf(fp, "</li>\n");
            fclose(fp);
        }
    }
    closedir(folder);
    
    
    return 0;
}

void wiki_toptemplate()
{
    // Function has side-effects: Makes a file index.html in top directory.
    FILE *fp;
    fp = fopen("./index.html", "w+");
    fprintf(fp, "<!DOCTYPE html><html lang='en'><head> <meta charset='UTF-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'> <meta name='viewport' content='width=device-width, initial-scale=1.0'></head><body>\n");
    fprintf(fp, "<h1>Bear's cave</h1>");
    fprintf(fp, "<style>");
    fprintf(fp, "<link rel='preconnect' href='https://fonts.bunny.net'>\
<link href='https://fonts.bunny.net/css?family=dotgothic16:400' rel='stylesheet' />");
    fprintf(fp, "ul {\
          list-style-type: none;\
          margin: 0;\
          padding: 0;\
        }\
\
        li a {\
        font-family: 'DotGothic16', sans-serif;\
          display: block;\
          width: 60px;\
        }");
        fprintf(fp, "</style>");
        fclose(fp);
    }


void wiki_bottomtemplate() {
    FILE *fp;
    fp = fopen("./index.html", "a");
    fprintf(fp, "Powered by exoC!");
    fclose(fp);
};

int main() 
{
    wiki_toptemplate();
    wiki_readdir("posts");
    wiki_bottomtemplate();
    return 0;
}
