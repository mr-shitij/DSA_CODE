#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "SearchEngine.h"

int main(int argc, char* argv[]){
    char str[200];

    if(argc >= 3){
        if(strcmp(argv[1],"-s") == 0){
            // char str[200];
            for(int i = 2; i < argc; i++){
                strcat(str, argv[i]);
                strcat(str, " ");
            }
            get_Search(str);
            printf("\n\tSearching ");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".\n");
        }
        if(strcmp(argv[1],"-j") == 0){
            root t = load_From_File(); 
            char str2[20];
            strcpy(str2, argv[2]);
            print_suggestion(t, argv[2]);
            destroy(&t);
            t = NULL;
        }
        if(strcmp(argv[1],"-a") == 0){
            for(int i = 2; i < argc; i++){
                strcat(str, argv[i]);
                strcat(str, " ");
            }
            root t = load_From_File();
            search(t, str);
            printf("\n");
            re_Write(t);
            destroy(&t);
            t = NULL;
        }
        if(strcmp(argv[1],"-f") == 0){
            if(strcmp(argv[2],"m") == 0){
                root t = load_From_File();
                frequency(t, 1);
                destroy(&t);
                t = NULL;
            }
            if(strcmp(argv[2],"l") == 0){
                root t = load_From_File();
                frequency(t, 0);
                destroy(&t);
                t = NULL;
            }
        }
    }
    else if(argc == 2){
        if(strcmp(argv[1],"-d") == 0){
            root t = load_From_File();
            display(t);
            destroy(&t);
            t = NULL;
        }
        if(strcmp(argv[1],"-f") == 0){
            root t = load_From_File();
            frequency(t, 2);
            destroy(&t);
            t = NULL;
        }
        if(strcmp(argv[1],"-r") == 0){
            root t = load_From_File();
            recent(t);
            destroy(&t);
            t = NULL;
        }
        if(strcmp(argv[1],"-e") == 0){
            store_History();
            printf("\n\n\tTHANK YOU FOR VISITING..!!!\n");
        }
        if(strcmp(argv[1],"-c") == 0){
            fclose(fopen("backup.txt", "w"));
            fclose(fopen("backup_key.txt", "w"));
            fclose(fopen("backup_freq.txt", "w"));
            printf("\n\n\tBrowser history cleared..!!!\n");
        }
        if(strcmp(argv[1],"-h") == 0){
            display_History();
        }
    }

    return 0;
}
