#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
// #define DEBUG 1

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
    line_count = line_count_txt(txt);
    struct linked_list *new_node = NULL;
    FILE *p;
    char *c[line_count],tempc[100];
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
    fclose(p);
    return new_node;
}
struct acpd_list *acpd_read(char txt[]){
    int line_count;
    line_count = line_count_txt(txt);
    struct acpd_list *new_node = NULL;
    char *c[line_count],tempc[100];
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