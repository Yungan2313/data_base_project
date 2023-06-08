#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#include "action.h"
#include "comment.h"
#define DEBUG_function 1
// #define DEBUG 1
// #define DEBUG2 1
// #define DEBUG3 1
// #define DEBUG4 1
// #define DEBUG5 1
// #define DEBUG6 1
#define DEBUG7 1
// #define DEBUG8 1
// #define DEBUG9 1
// #define DEBUG10 1
// #define DEBUG11 1
int main(){
    struct linked_list *list = NULL,*temp,*seach_list = NULL;
    struct acpd_list *acpd_list = NULL;
    struct comment_list *comment_list = NULL;
    char txt[] = "lanpa.txt",acpd_txt[] = "acpd.txt",comment_txt[] = "comment_test.txt";
    #ifdef DEBUG_function
    list = data_base_read(txt);
    acpd_list = acpd_read(acpd_txt);
    comment_list = comment_list_read(comment_txt);
    #endif
    // printf("ok1\n");
    #ifdef DEBUG //讀取data_base acpd
    if(list == NULL){
        printf("not 1ok");
    }
    // printf("ok\n");
    temp = list;
    for(int i=0; list != NULL; i++){
        printf("%d:%s %s %d %0.1f %s\n",i,list->food_name,list->store_name,list->price,list->score,list->comment_txt);
        list = list->next;
    }
    // printf("ok\n");
    // for(int i=0; acpd_list != NULL;i++){
    //     printf("%d:%s %s %s\n",i,acpd_list->account,acpd_list->password,acpd_list->data_base_txt);
    //     acpd_list = acpd_list->next;
    // }
    // printf("ok\n");
    #endif

    #ifdef DEBUG2 // sort 處理
    int type,order;
    scanf("%d %d",&type,&order);
    list = sort_list(list,type,order);
    for(int i=0; list != NULL; i++){
        printf("%d:%10s %10s\t%4d\t%2.1f\t%10s\n",i,list->food_name,list->store_name,list->price,list->score,list->comment_txt);
        list = list->next;
    }
    #endif
    // printf("ok2\n");
    
    #ifdef DEBUG3 //comment 讀取
    if(comment_list == NULL){
        printf("not ok3\n");
    }
    for(int i=0; comment_list != NULL; i++){
        printf("%d:%s %0.1f %s\n",i,comment_list->account,comment_list->score,comment_list->comment_txt);
        comment_list = comment_list->next;
    }
    #endif
   
    #ifdef DEBUG4//acpd 新增
    char *acpd_write_txt = malloc(sizeof(char));
    strcpy(acpd_write_txt,acpd_write("golin","abcde"));
    printf("%s",acpd_write_txt);
    printf("ok2\n");
    #endif

    #ifdef DEBUG5//新增東西到評論
    insert_data("commentsssss","test","golin",9.6,2);
    #endif

    #ifdef DEBUG6//刪除評論內的評價跟comment
    delete_data("commentsssss","test","golin");
    #endif

    #ifdef DEBUG7//讀取評論collect內的評論
    printf("%s",comment_search("comment_lanpa_bbccsb8787.txt"));
    #endif

    #ifdef DEBUG8//測試action新增
    // printf("ok\n");
    list = temp;
    list = add_list(list,"lanpa");
    for(int i=0; list != NULL; i++){
        printf("%d:%s %s %d %0.1f %s\n",i,list->food_name,list->store_name,list->price,list->score,list->comment_txt);
        list = list->next;
    }
    #endif

    #ifdef DEBUG9//測試action刪除
    list = temp;
    list = delete_list(list,"lanpa",0);
    for(int i=0; list != NULL; i++){
        printf("%d:%s %s %d %0.1f %s\n",i,list->food_name,list->store_name,list->price,list->score,list->comment_txt);
        list = list->next;
    }
    #endif

    #ifdef DEBUG10//測試search(記得做main的時候，search_list要初始化(=NULL))
    list = temp;
    seach_list = search_list(list);
    if(seach_list == NULL){
        printf("not ok\n");
    }
    for(int i=0; seach_list != NULL; i++){
        printf("%d:%s %s %d %0.1f %s\n",i,seach_list->food_name,seach_list->store_name,seach_list->price,seach_list->score,seach_list->comment_txt);
        seach_list = seach_list->next;
    }
    #endif

    #ifdef DEBUG11//測試logout(將linked list存回txt)
    list = temp;
    log_out(list,"lanpa");
    #endif
}