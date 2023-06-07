#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
// #define DEBUG 1
// #define DEBUG_DIR 1
static int folder_line_count_txt(char txt[],char folder[]){
    int line_count = 0;
    char *buffer;
    buffer = malloc(sizeof(char)*100);
    DIR *dir = opendir(folder);
    struct dirent *entry;
    #ifdef DEBUG_DIR
    if (dir == NULL) {
        printf("無法打開資料夾\n");
    }
    else{
        printf("ok");
    }
    #endif
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, txt) == 0) {  // 判斷是否為.txt檔案
            char path[100];
            sprintf(path, "%s/%s",folder, entry->d_name);  // 構造檔案路徑
            FILE *fp = fopen(path, "r");  // 打開檔案
            if (fp != NULL) {
                while (fgets(buffer, 100, fp) != NULL) {
                    line_count++;
                }
            }
            fclose(fp);
            break;
        }
    }
    closedir(dir);
    // printf("\n%d\n",line_count);
    return line_count;
}
static int line_count_txt(char txt[]){
    int line_count = 0;
    char *buffer;
    buffer = malloc(sizeof(char)*100);
    FILE *fp = fopen(txt, "r");
    while (fgets(buffer, 100, fp) != NULL) {
        line_count++;
    }
    fclose(fp);
    return line_count;
}

struct linked_list *data_base_read(char txt[]){
    int line_count;
    line_count = folder_line_count_txt(txt,"data_base");
    struct linked_list *new_node = NULL;
    
    DIR *dir = opendir("data_base");
    struct dirent *entry;
    #ifdef DEBUG_DIR
    if (dir == NULL) {
        printf("無法打開資料夾\n");
    }
    else{
        printf("ok");
    }
    #endif
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, txt) == 0) {  // 判斷是否為.txt檔案
            char path[100];
            sprintf(path, "data_base/%s", entry->d_name);  // 構造檔案路徑

            FILE *p = fopen(path, "r");  // 打開檔案
            if (p != NULL) {
                // printf("1:line count:%d",line_count);
                char *c[line_count],tempc[1000];
                #ifdef DEBUG_DIR
                if (p == NULL) {
                    printf("xxx!\n");
                    return 0;
                }
                else{
                    printf("read ok!\n");
                }
                #endif
                int i = 0;
                while(fgets(tempc,100,p)!=NULL){
                    int temp = strlen(tempc);
                    int count = 0;
                    char food_name[20],store_name[20],comment_txt[20]; 
                    int price;
                    float score;
                    if(tempc[temp-1] != '\n'){
                        tempc[temp] = '\0';
                    }
                    else{
                        tempc[temp-1] = '\0';
                    }
                    c[i] = strdup(tempc);
                    sscanf(c[i],"%s %s %d %f %s",food_name,store_name,&price,&score,comment_txt);
                    insert_front(&new_node,food_name,store_name,price,score,comment_txt);
                    i++;
                }
                for (int j = 0; j < i; j++) {
                    free(c[j]);
                }
                fclose(p);  // 關閉檔案
                break;
            }
            // else{
            //     printf("problem is here\n");
            // }
        }
        // printf("ok?");
    }
    closedir(dir);
    // printf("ok?");
    // printf("%s %s %d %0.1f %s\n",new_node->food_name,new_node->store_name,new_node->price,new_node->score,new_node->comment_txt);
    return new_node;
}
struct acpd_list *acpd_read(char txt[]){
    int line_count;
    line_count = line_count_txt(txt);
    struct acpd_list *new_node = NULL;
    char *c[line_count],tempc[1000];
    FILE *p;
    p = fopen(txt, "r");
    #ifdef DEBUG
    if (p == NULL) {
        printf("xxx!\n");
        return 0;
    }
    else{
        printf("read ok!\n");
    }
    #endif
    int i = 0;
    while(fgets(tempc,100,p)!=NULL){
        int temp = strlen(tempc);
        int count = 0;
        char account[20],password[20],data_base_txt[20];
        if(tempc[temp-1] != '\n'){
            tempc[temp] = '\0';
        }
        else{
            tempc[temp-1] = '\0';
        }
        c[i] = strdup(tempc);
        sscanf(c[i],"%s %s %s",account,password,data_base_txt);
        insert_front_acpd(&new_node,account,password,data_base_txt);
        i++;
    }
    // printf("okkkk\n");
    fclose(p);
    return new_node;
}
struct comment_list *comment_list_read(char txt[]){
    int line_count;
    line_count = folder_line_count_txt(txt,"comment_data_base");
    struct comment_list *new_node = NULL;
    
    DIR *dir = opendir("comment_data_base");
    struct dirent *entry;
    #ifdef DEBUG_DIR
    if (dir == NULL) {
        printf("無法打開資料夾\n");
    }
    else{
        printf("ok");
    }
    #endif
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, txt) == 0) {  // 判斷是否為.txt檔案
            char path[100];
            sprintf(path, "comment_data_base/%s", entry->d_name);  // 構造檔案路徑
            // printf("ok?\n");
            FILE *p = fopen(path, "r");  // 打開檔案
            if (p != NULL) {
                // printf("line cpumt = %d\n", line_count);
                char *c[10],tempc[1000];
                #ifdef DEBUG
                if (p == NULL) {
                    printf("xxx!\n");
                    return 0;
                }
                else{
                    printf("read ok!\n");
                }
                #endif
                int i = 0;
                while(fgets(tempc,100,p)!=NULL){
                    // printf("ok?\n");
                    int temp = strlen(tempc);
                    int count = 0;
                    char account[20],comment_txt[20]; 
                    float score;
                    // printf("ok22?\n");
                    if(tempc[temp-1] != '\n'){
                        tempc[temp] = '\0';
                    }
                    else{
                        tempc[temp-1] = '\0';
                    }
                    // printf("i = %d\n",i);
                    // printf("tempc = %s\n",tempc);
                    // printf("temp = %d\n",temp);
                    // printf("%p\n", strdup(tempc));
                    // printf("ok222?\n");
                    // fflush(stdout);
                    c[i] = strdup(tempc);
                    sscanf(c[i],"%s %s %f %s",account,&score,comment_txt);
                    // printf("%s %s %f %s\n",food_name,store_name,score,comment_txt);
                    // printf( "ok?\n");
                    // fflush(stdout);
                    insert_front_comment(&new_node,account,score,comment_txt);
                    // printf("%s %s %0.1f %s\n",new_node->food_name,new_node->store_name,new_node->score,new_node->comment_txt);
                    // free(c[i]);
                    i++;
                }
                for (int j = 0; j < i; j++) {
                    free(c[j]);
                }
                fclose(p);  // 關閉檔案
                break;
            }
        }
    }
    closedir(dir);
    // printf("%s %s %0.1f %s\n",new_node->food_name,new_node->store_name,new_node->score,new_node->comment_txt);
    return new_node;
}

char *acpd_write(char account[],char password[]){
    char *account_p = malloc(sizeof(char)*20),*path = malloc(sizeof(char)*100);
    strcpy(account_p, account);
    FILE *file = fopen("acpd.txt", "a"),*new_file;
    #ifdef DEBUG
    if (file == NULL) {
        printf("無法打開檔案\n");
    }
    else{
        printf("read ok\n");
    }
    #endif
    fprintf(file, "%s %s %s.txt\n",account,password,account);
    strcat(account_p, ".txt");

    DIR *dir = opendir("data_base");
    strcat(strcpy(path,"data_base/"),account_p);
    sprintf(account_p, path);
    new_file = fopen(account_p, "w");
    closedir(dir);
    fclose(file);
    fclose(new_file);
    return account_p;
}