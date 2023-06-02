#include "basic.h"
#include "txtinput.h"

char *account();
static char *password(char *account_name);

// 帳號：總字數限20、不可空白、不能含特殊字元(除了英文跟數字以外的) //不能跟其他帳號重複
char *account(){
    int access = 0, choice;
    char* account_name = (char*)malloc(sizeof(char) * 21);
    struct acpd_list *new_node = acpd_read("acpd.txt");
    struct acpd_list *ptr;
    while(access != 1){
        origin:
        printf("Do you want to create a new account?\n[1]Yes\t[2]No\n");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Input your account\n");
            fgets(account_name, 21, stdin);
            for (int i = 0; i < strlen(account_name) + 1; i++){
                if (~(*(account_name + i) >= 'Z' && *(account_name + i) <= 'A') && 
                    ~(*(account_name + i) >= 'z' && *(account_name + i) <= 'a') &&
                    ~(*(account_name + i) >= '9' && *(account_name + i) <= '0')){
                    printf("Invalid account.\n");
                    printf("Please try a new name\n");
                    goto origin;
                }
                else if(*(account_name + i) == ' '){
                    printf("Space character is forbidden.\n");
                    printf("Please try a new password");
                    goto origin;
                }
            }
            for(ptr = new_node; ptr != NULL; ptr = ptr->next){
                if(strcmp(ptr->account, account_name) == 0){
                    printf("Account already exists\n");
                    goto origin;
                }
            }
            char *password_total, register_new;
            strcpy(password_total, password(account_name));
            register_new = acpd_write(account_name, password_total);
            return "acpd.txt";
        }
        else{
            return NULL;
        }
    }
}

// 密碼：至少2個大寫2個小寫、要有數字、字數限20、不可空白、不能跟帳號重複(strcat)或與帳號相似(strstr、非嚴格比對)
static char* password(char* account_name){
    int access = 0;
    char *corres_password = (char *)malloc(sizeof(char) * 21);
    origin:while(access != 1){
        printf("Input your password\n");
        fgets(corres_password, 21, stdin);
        if(strcmp(corres_password, account_name) == 0){
            printf("Your password is the same as your account");
            printf("Please try a new password");
            goto origin;
        }
        int big_word = 0, small_word = 0, number = 0;
        for(int i = 0; i < 21; i++){
            if (*(corres_password + i) <= 'Z' && *(corres_password + i) >= 'A'){
                big_word++;
            }
            else if (*(corres_password + i) <= 'z' && *(corres_password + i) >= 'a'){
                small_word++;
            }
            else if (*(corres_password + i) <= '9' && *(corres_password + i) >= '0'){
                number++;
            }
            else if (*(corres_password + i) == ' '){
                printf("Space character is forbidden.\n");
                printf("Please try a new password");
                goto origin;
            }
        }
        if(big_word < 2 || small_word < 2 || number == 0){
            printf("Your account name is in the wrong format.\n");
            printf("Please retype it again\n");
            goto origin;
        }
        if (*(corres_password) = '\n'){
            printf("Where is your password?\n");
            printf("Please retype it again\n");
            goto origin;
        }
        if (strstr(account_name, corres_password) != NULL && strlen(strstr(account_name, corres_password)) >= 5){
            printf("Your password is too easy\n");
            goto origin;
        }
        return corres_password;
    }
}