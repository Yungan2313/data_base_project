#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#define DEBUG 1
int main(){
    struct linked_list *list = NULL;
    struct acpd_list *acpd_list = NULL;
    char txt[] = "test.txt",acpd_txt[] = "acpd.txt";
    list = data_base_read(txt);
    acpd_list = acpd_read(acpd_txt);
    // printf("ok1\n");
    #ifdef DEBUG
    for(int i=0; list != NULL; i++){
        printf("%d:%s %s %d %0.1f\n",i,list->food_name,list->store_name,list->price,list->score);
        list = list->next;
    }
    // printf("ok\n");
    for(int i=0; acpd_list != NULL;i++){
        printf("%d:%s %s %s\n",i,acpd_list->account,acpd_list->password,acpd_list->data_base_txt);
        acpd_list = acpd_list->next;
    }
    // printf("ok\n");
    #endif
    // printf("ok2\n");
}