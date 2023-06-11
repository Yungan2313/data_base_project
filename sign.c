#include "basic.h"
#include "txtinput.h"
#include "linked_list.h"
#include "sign.h"
char *account();
static char *password(char *account_name);

// 帳號：總字數限20、不可空白、不能含特殊字元(除了英文跟數字以外的) //不能跟其他帳號重複
char *account(){
    int access = 0, choice;
    char* account_name = (char*)malloc(sizeof(char) * 100);
    struct acpd_list *new_node = acpd_read("acpd.txt");
    struct acpd_list *ptr;
    char *password_total,*register_new = malloc(sizeof(char)*100);
    while(access != 1){
        origin:
        printf("Do you want to create a new account?\n[1]Yes\t[2]No\n");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Input your account:(the account name should only use characters and numbers)\n");
            getchar();
            fgets(account_name, 21, stdin);
            if (*(account_name) == '\n'){
                printf("Where is your account?\n");
                printf("Please retype it again\n");
                goto origin;
            }
            for (int i = 0; *(account_name + i) !='\n'; i++){
                if (!((*(account_name + i) <= 'Z' && *(account_name + i) >= 'A') || 
                    (*(account_name + i) <= 'z' && *(account_name + i) >= 'a') ||
                    (*(account_name + i) <= '9' && *(account_name + i) >= '0'))){
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
            
            password_total = password(account_name);
            register_new = acpd_write(account_name, password_total);
            free(password_total);
            free(account_name);
            return register_new;
        }
        else{
            return NULL;
        }
    }
}

// 密碼：至少2個大寫2個小寫、要有數字、字數限20、不可空白、不能跟帳號重複(strcat)或與帳號相似(strstr、非嚴格比對)
static char* password(char* account_name){
    int access = 0,len,temp;
    char *corres_password = (char *)malloc(sizeof(char) * 100),*upload_password;
    int big_word = 0, small_word = 0, number = 0;
    origin:while(access != 1){
        printf("Input your password:(the password need at least two big characters and small characters, and also at least one number)\n");
        printf("If you afraid to type the password on terminal, you can enter your password in a text file and upload it\n");
        printf("    [1]type\n");
        printf("    [2]upload text file\n");
        scanf("%d",&temp);
        getchar();
        if(temp == 2){
            upload_password = malloc(sizeof(char) * 100);
            printf("please enter your file name(please put your file into the folder)\n");
            fgets(upload_password,100,stdin);
            len = strlen(upload_password);
            *(upload_password+len-1) = '\0';
            // printf("%s\n",upload_password);
            FILE *file = fopen(upload_password,"r");
            fgets(corres_password,100,file);
            len = strlen(corres_password);
            *(corres_password+len-1) = '\0';
            // printf("%s\n",corres_password);
            goto upload;
        }
        printf("Input your password\n");
        fgets(corres_password, 21, stdin);
        len = strlen(corres_password);
        *(corres_password+len-1) = '\0';
        // printf("%s\n",corres_password);
        if (*(corres_password) == '\n'){
            printf("Where is your password?\n");
            printf("Please retype it again\n");
            goto origin;
        }
        else if(strcmp(corres_password, account_name) == 0){
            printf("Your password is the same as your account\n");
            printf("Please try a new password: ");
            goto origin;
        }
        upload:
        // printf("%s\n",corres_password);
        big_word = 0;
        small_word = 0;
        number = 0;
        len = strlen(corres_password);
        for(int i = 0; i < len; i++){
            // printf("c:%c\n",*(corres_password + i));
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
                printf("Please try a new password\n");
                goto origin;
            }
        }
        if(big_word < 2 || small_word < 2 || number == 0){
            printf("Your password is in the wrong format.\n");
            printf("Please retype it again\n");
            goto origin;
        }
        char *match;
        account_name[strcspn(account_name, "\n")] = '\0';
        corres_password[strcspn(corres_password, "\n")] = '\0';
        if(strlen(corres_password) <= strlen(account_name)){
            match = strstr(account_name, corres_password);
        }
        else{
            match = strstr(corres_password, account_name);
        }
        if (match != NULL && strlen(match) >= 5){
            printf("Your password is too similar to your account\n");
            goto origin;
        }
        // printf("%s\n", corres_password);
        return corres_password;
    }
}
#ifdef DD
int main(){
    account();
    return 0;
}
#endif