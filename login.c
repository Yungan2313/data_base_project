#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"

//compares input with txt file accounts, login successful/unsuccessful
char *login()
{
    struct acpd_list *list;
    struct linked_list *acpdlist;
    //reads txt file
    list = acpd_read("acpd.txt");

    static char username_input[20], password_input[20];
    memset(username_input, 0, sizeof(username_input));
    memset(password_input, 0, sizeof(password_input));

    start:
    printf("Username: ");
    scanf("%s", username_input);

    printf("Password: ");
    scanf("%s", password_input);

    //compare using linked list rather than arrays (done)
    struct acpd_list *current=list;
    while(current!=NULL)
    {
        if(strcmp(username_input, current->account)==0 && strcmp(password_input, current->password)==0)
        {
            printf("You have successfully logged in.");
            char *result= current->data_base_txt; 
            free_acpd_list(list);
            return result;
        }
        current=current->next;
    }

    int yn=0;
    printf("Account was not found. Are you sure that you have an account?\n");

    while(1)
    {
        printf("[0]Yes\n[1]No\n");
        scanf("%d", &yn);
        if(yn==0)
        {
            goto start;
        }
        else if(yn==1)
        {
            return NULL;
        }
        else
        {
            continue;
        }
    }
    free_acpd_list(list);
    return NULL;
}

#ifdef debug
int main(){
    login();
    return 0;
}
#endif
