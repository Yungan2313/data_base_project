#include "basic.h"
#include "linked_list.h"
//#define DEBUG 1

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
        char food_name[20],store_name[20];
        int price;
        float score;
        tempc[temp-1] = '\0';
        c[i] = strdup(tempc);
        sscanf(c[i],"%s %s %d %f",food_name,store_name,&price,&score);
        insert_front(&new_node,food_name,store_name,price,score);
        i++;
    }
    return new_node;
}