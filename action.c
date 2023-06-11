#include "basic.h"
#include "linked_list.h"
#include "action.h"
#include "comment.h"
#define FLOAT_TOLERANCE 0.01
// #define DEBUG 1
static struct linked_list *node_switch(struct linked_list *node1, struct linked_list *node2){
    node1->next = node2->next;
    node2->next = node1;
    return node2;
}

static char *change_space(char *strings){
    int i = 0;
    while(*(strings + i)!='\0'){
        if(*(strings + i) == ' '){
            *(strings + i) = '_';
        }
        i++;
    }
    return strings;
}
static int check_repeat_food_store(struct linked_list *list,char *food,char *store){
    while(list!=NULL){
        if(strcmp(food,list->food_name)==0 && strcmp(store,list->store_name)==0){
            return -1;
        }
        list = list->next;
    }
    return 1;
}
//新增(要注意重複食物_店家)
struct linked_list *add_list(struct linked_list *list,char user[]){
    char *food_name = malloc(sizeof(char)*21),*store_name = malloc(sizeof(char)*21),*comment_txt = malloc(sizeof(char)*100);
    int price,len,temp,check = 1;
    float score;
    while(check){
        printf("please enter the name of the food:(the limit of the char is 20)\n");
        printf("enter: ");
        fgets(food_name, sizeof(char)*21, stdin);
        len = strlen(food_name);
        *(food_name+len-1) = '\0';
        food_name = change_space(food_name);
        printf("please enter the store of the food:(the limit of the char is 20)\n");
        printf("enter: ");
        fgets(store_name, sizeof(char)*21, stdin);
        len = strlen(store_name);
        *(store_name+len-1) = '\0';
        store_name = change_space(store_name);
        check = 0;
        if(check_repeat_food_store(list,food_name, store_name) == -1){
            printf("you already score this food, maybe try a new one\n");
            check = 1;
        }
    }
    strcat(strcat(strcat(strcpy(comment_txt,food_name),"_"),store_name),".txt");//food_store.txt
    printf("please enter the price of the food:");
    scanf("%d",&price);
    printf("please enter the score of the food:");
    scanf("%f",&score);
    printf("Do you want to comment this food?\n");
    printf("    [1]Yes\n");
    printf("    [2]No\n");
    printf("enter:");
    scanf("%d",&temp);
    getchar();
    temp == 1 ? (temp = 2): (temp = 1);//yes = 2,no = 1
    temp == 2 ? insert_front(&list,food_name,store_name,price,score,comment_txt): insert_front(&list,food_name,store_name,price,score,"0"); 
    // printf("problem one\n");
    // printf("%s----------------------------------------------\n",user);
    insert_data(food_name,store_name,user,score,temp);
    // printf("problem two\n");
    //printf("%s %s %s\n",food_name,store_name,comment_txt);
    free(food_name);
    free(store_name);
    free(comment_txt);
    return list;
}
//刪除
struct linked_list *delete_list(struct linked_list *list,char user[],int page){
    int ID;
    struct linked_list *node = list;
    printf("which ID you want to delete?\n");
    printf("enter:");
    scanf("%d",&ID);
    getchar();
    ID += page*10;//確認UI return的數值
    // printf("%d",ID);
    for(int i=0;i<ID;i++){
        node = node->next;
        if(node==NULL){
            printf("there is no data to delete!\n");
            return list;
        }
    }
    // printf("%s %s\n",node->food_name,node->store_name);
    delete_data(node->food_name,node->store_name,user);
    // printf("here\n");
    list = delete_linked_list(list,ID);
    printf("here\n");
    return list;
}
//排列(回傳的只有兩個，price、score)
struct linked_list *sort_list(struct linked_list *list,int type,int order){
    struct linked_list *node = list,*test_line = list,*test = list,*prev = list;
    int list_count = 0;
    while(test_line!= NULL){
        list_count++;
        test_line = test_line->next;
    } 
    if(list == NULL || list->next == NULL){
        return list;
    }
    // int size = linked_list_len(list),swapped,i;
    switch(type){
        case 1:
            for(int i=0;i<list_count;i++){
                int change = 0;
                prev = list;
                while(node->next!=NULL){
                    if(node->price>node->next->price){
                        #ifdef DEBUG
                        printf("xxx%s %s %d %0.1f %s\n",node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                        printf("xnx%s %s %d %0.1f %s\n",node->next->food_name,node->next->store_name,node->next->price,node->next->score,node->next->comment_txt);
                        #endif
                        if(order == 2){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    else{
                        if(order == 1){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    prev = node;
                    node = node->next;
                    test = list;
                    for(int i=0; test != NULL; i++){
                        #ifdef DEBUG
                        printf("%d:%s %s %d %0.1f %s\n",i,test->food_name,test->store_name,test->price,test->score,test->comment_txt);
                        #endif
                        test = test->next;
                    }
                }
                if(change == 0){
                    break;
                }
                node = list;
            }
            return list;
        case 2:
            for(int i=0;i<list_count;i++){
                int change = 0;
                prev = list;
                while(node->next!=NULL){
                    if(node->score - node->next->score > FLOAT_TOLERANCE){
                        #ifdef DEBUG
                        printf("xxx%s %s %d %0.1f %s\n",node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                        printf("xnx%s %s %d %0.1f %s\n\n",node->next->food_name,node->next->store_name,node->next->price,node->next->score,node->next->comment_txt);
                        #endif
                        if(order == 2){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    else{
                        if(order == 1){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    prev = node;
                    node = node->next;
                    test = list;
                    for(int i=0; test != NULL; i++){
                        #ifdef DEBUG
                        printf("%d:%s %s %d %0.1f %s\n",i,test->food_name,test->store_name,test->price,test->score,test->comment_txt);
                        #endif
                        test = test->next;
                    }
                }
                if(change == 0){
                    break;
                }
                node = list;
            }
            return list;
    }
}
//尋找(回傳值為一個新的linked list)(end search 要 free)
struct linked_list *search_list(struct linked_list *list){
    struct linked_list *new_list = NULL,*node = list;
    int temp,price,len;
    float score;
    char *txt = malloc(sizeof(char)*100);
    printf("which one you want to search?\n"); 
    printf("    [1]food\n");
    printf("    [2]store\n");
    printf("    [3]price\n");
    printf("    [4]score\n");
    printf("enter: ");
    scanf("%d",&temp);
    getchar();
    printf("enter you searching: ");
    switch(temp){
        case 1:
            fgets(txt, sizeof(char)*21, stdin);
            len = strlen(txt);
            *(txt+len-1) = '\0';
            txt = change_space(txt);
            // printf("%s\n",txt);
            while(node!=NULL){
                // printf("%s %s\n",node->food_name,txt);
                if(strcmp(node->food_name,txt) == 0){
                    insert_front(&new_list,node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                }
                node = node->next;
            }
            return new_list;
        case 2:
            fgets(txt, sizeof(char)*21, stdin);
            len = strlen(txt);
            *(txt+len-1) = '\0';
            txt = change_space(txt);
            while(node!=NULL){
                if(strcmp(node->store_name,txt) == 0){
                    insert_front(&new_list,node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                }
                node = node->next;
            }
            return new_list;
        case 3:
            scanf("%d",&price);
            getchar();
            while(node!=NULL){
                if(node->price == price){
                    insert_front(&new_list,node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                }
                node = node->next;
            }
            return new_list;
        case 4:
            scanf("%f",&score);
            getchar();
            while(node!=NULL){
                if(node->score == score){
                    insert_front(&new_list,node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                }
                node = node->next;
            }
            return new_list;
    }
}
//給list找ID輸出comment_txt;
char *comment_choose(struct linked_list *list,char user[],int page){
    int ID;
    printf("waht comment you want to see?\n");
    printf("enter:(ID) ");
    scanf("%d",&ID);
    getchar();
    ID += page*10;
    for(int i = 0;i<ID;i++){
        list = list->next;
    }
    return list->comment_txt;
}


//要把資料存入txt 還要清空list
void log_out(struct linked_list *list,char user[]){
    char path[200],*user_txt = malloc(sizeof(char)*100);
    struct linked_list *node = list; 
    DIR *dir = opendir("data_base");
    sprintf(path,"data_base/%s",strcat(strcpy(user_txt,user),".txt"));
    FILE *new_file = fopen(path,"w");
    while(node!=NULL){
        fprintf(new_file,"%s %s %d %0.1f %s\n",node->food_name,node->store_name,node->price,node->score,node->comment_txt);
        node = node->next;
    }
    fclose(new_file);
    closedir(dir);
    free_linked_list(list);
    free(user_txt);
}