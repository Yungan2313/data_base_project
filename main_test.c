#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#include "action.h"
#define DEBUG 1
// #define DEBUG2 1
#define DEBUG3 1
int main(){
    struct linked_list *list = NULL;
    struct acpd_list *acpd_list = NULL;
    struct comment_list *comment_list = NULL;
    char txt[] = "test.txt",acpd_txt[] = "acpd.txt",comment_txt[] = "comment_test.txt";
    list = data_base_read(txt);
    acpd_list = acpd_read(acpd_txt);
    comment_list = comment_list_read(comment_txt);
    // printf("ok1\n");
    #ifdef DEBUG
    if(list == NULL){
        printf("not 1ok");
    }
    // printf("ok\n");
    for(int i=0; list != NULL; i++){
        printf("%d:%s %s %d %0.1f %s\n",i,list->food_name,list->store_name,list->price,list->score,list->comment_txt);
        list = list->next;
    }
    // printf("ok\n");
    for(int i=0; acpd_list != NULL;i++){
        printf("%d:%s %s %s\n",i,acpd_list->account,acpd_list->password,acpd_list->data_base_txt);
        acpd_list = acpd_list->next;
    }
    // printf("ok\n");
    #endif

    #ifdef DEBUG2
    int type,order;
    scanf("%d %d",&type,&order);
    list = sort_list(list,type,order);
    for(int i=0; list != NULL; i++){
        printf("%d:%10s %10s\t%4d\t%2.1f\t%10s\n",i,list->food_name,list->store_name,list->price,list->score,list->comment_txt);
        list = list->next;
    }
    #endif
    // printf("ok2\n");
    
    #ifdef DEBUG3
    if(comment_list == NULL){
        printf("not ok3\n");
    }
    for(int i=0; comment_list != NULL; i++){
        printf("%d:%s %s %0.1f %s\n",i,comment_list->food_name,comment_list->store_name,comment_list->score,comment_list->comment_txt);
        comment_list = comment_list->next;
    }
    #endif
}