#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#include "comment.h"
static void insert_comment(char *comment_collect_txt);
static void delete_comment(char comment_collect_txt[]);
//將新的資料傳進食物data儲存(包含使用者、評價、comment.txt)(comment_bool = 1(沒評論) 2(有評論))
static int folder_line_count_txt(char txt[],char folder[]){
    int line_count = 0;
    char *buffer;
    buffer = malloc(sizeof(char)*100);
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
void insert_data(char food_name[],char store_name[],char user[],float score,int comment_bool){
    char *comment_txt = malloc(sizeof(char)*100),*comment_collect_txt = malloc(sizeof(char)*100);
    strcat(strcat(strcat(strcpy(comment_txt,food_name),"_"),store_name),".txt");//food_store.txt
    //搜尋有沒有該食物_店家的txt檔
    DIR *dir = opendir("comment_data_base");
    struct dirent *entry;
    int found_file = 0;
    while((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name, comment_txt) == 0){
            found_file = 1;
            char path[100];
            sprintf(path, "comment_data_base/%s", entry->d_name); 
            FILE *p = fopen(path, "a");
            if(comment_bool == 2){//要寫comment
                strcat(strcat(strcat(strcat(strcat(strcpy(comment_collect_txt,user),"_"),food_name),"_"),store_name),".txt");//user_food_store.txt
                fprintf(p, "%s %0.1f %s\n",user,score,comment_collect_txt);
                insert_comment(comment_collect_txt);
            }
            else{
                fprintf(p, "%s %0.1f %c\n",user,score,'0');
            }
            fclose(p);
            break;
        }
    }
    if(found_file  == 0){
        char file_name[1000];
        strcat(strcpy(file_name,"comment_data_base/"),comment_txt);
        FILE *new_file = fopen(file_name,"w");
        if(comment_bool == 2){//要寫comment
            strcat(strcat(strcat(strcat(strcat(strcpy(comment_collect_txt,user),"_"),food_name),"_"),store_name),".txt");//user_food_store.txt
            // printf("%s %0.1f %s\n",user,score,comment_collect_txt);
            fprintf(new_file, "%s %0.1f %s\n",user,score,comment_collect_txt);
            insert_comment(comment_collect_txt);
        }
        else{
            fprintf(new_file, "%s %0.1f %c\n",user,score,'0');
        }
        fclose(new_file);
    }
    closedir(dir);
}
//新增一個新的txt檔儲存comment，程式會包含input
static void insert_comment(char *comment_collect_txt){
    // printf("%s\n",comment_collect_txt);//-----------------------------------------------------------
    char path[100],*comment_write = malloc(sizeof(char)*200);
    DIR *dir = opendir("comment_collect");
    sprintf(path,"comment_collect/%s",comment_collect_txt);
    FILE *new_file = fopen(path,"w");
    printf("please write down your comment:\n");
    fgets(comment_write,200,stdin);
    printf("wait for a second, data is sending\n");//不知道為甚麼，把這個打上就可以跑了==
    fprintf(new_file,comment_write);
    printf("");//不知道為甚麼，把這個打上就可以跑了==
    fclose(new_file);
    closedir(dir);
}
//將資料刪除(刪除要包含將comment刪除)(要檢查她有沒有comment('0'))
void delete_data(char food_name[],char store_name[],char user[]){
    char *comment_txt = malloc(sizeof(char)*100),*comment_collect_txt = malloc(sizeof(char)*100);
    strcat(strcat(strcat(strcpy(comment_txt,food_name),"_"),store_name),".txt");//food_store.txt
    strcat(strcat(strcat(strcat(strcat(strcpy(comment_collect_txt,user),"_"),food_name),"_"),store_name),".txt");//user_food_store.txt
    int line_count;
    line_count = folder_line_count_txt(comment_txt,"comment_data_base");
    struct linked_list *new_node = NULL;
    // printf("%s %s\n",comment_txt,comment_collect_txt);
    DIR *dir = opendir("comment_data_base");
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name, comment_txt) == 0){
            char path[100],path_temp[100],path_cpy[100],path_temp_cpy[100];
            sprintf(path, "comment_data_base/%s", entry->d_name);
            // printf("%s\n", path);
            strcpy(path_cpy, path);
            sprintf(path_temp, "comment_data_base/%s", "temp.txt"); 
            strcpy(path_temp_cpy, path_temp);
            FILE *p = fopen(path, "r");
            FILE *temp_file = fopen(path_temp, "w");
            char *c[line_count],tempc[1000];
            int i = 0;
            while(fgets(tempc,100,p)!=NULL){
                int temp = strlen(tempc);
                char account[100],comment_txt_check[100];
                float score;
                c[i] = strdup(tempc);
                sscanf(c[i],"%s %f %s",account,&score,comment_txt_check);
                if(strcmp(comment_txt_check,"0")!=0){
                    // printf("ok delete\n");
                    delete_comment(comment_txt_check);
                }
                // printf("%s %s\n",account,user);
                if(strcmp(account,user) == 0){
                    continue;
                }
                fputs(tempc,temp_file);
                i++;
            }
            for (int j = 0; j < i; j++) {
                free(c[j]);
            }
            if(fgets(tempc,100,temp_file) == NULL){
                fclose(p);
                fclose(temp_file);
                remove(path_cpy);
                remove(path_temp_cpy);
            }
            else{
                fclose(p);
                fclose(temp_file);
                remove(path_cpy);
                // printf("%s\n",path_temp_cpy);
                rename(path_temp_cpy,path_cpy);
            }
            fclose(p);
            fclose(temp_file);
            remove(path_cpy);
            // printf("%s\n",path_temp_cpy);
            rename(path_temp_cpy,path_cpy);
            break;
        }
    }
    closedir(dir);
}
//將comment.txt刪除
static void delete_comment(char comment_collect_txt[]){
    char path[100],comment_write[200];
    DIR *dir = opendir("comment_collect");
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        if(strcmp(entry->d_name, comment_collect_txt) == 0){
            char path[100];
            sprintf(path, "comment_collect/%s", entry->d_name); 
            remove(path);
        }
    }
    
    closedir(dir);
}
//搜尋這個食物的評價，並回傳struct comment
// struct comment_list *comment_data_search(char txt[]){
    
// }
//將comment回傳
char *comment_search(char txt[]){
    char *comment = malloc(sizeof(char)*1000);
    char path[100];
    DIR *dir = opendir("comment_collect");
    sprintf(path,"comment_collect/%s",txt);
    FILE *comment_file = fopen(path,"r");
    fgets(comment, sizeof(char)*1000, comment_file);
    return comment;
}