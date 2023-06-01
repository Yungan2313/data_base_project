#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

//struct using linked_list.h thus will be removed during v2
static struct accounts{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

static struct accounts account[20];
int numAcc=0;


//compares input with txt file accounts, login successful/unsuccessful
char *login()
{
    struct linked_list *list;
    //reads txt file
    list = acpd_read("acpd.txt");

    static char username_input[MAX_USERNAME_LENGTH], password_input[MAX_PASSWORD_LENGTH];
    memset(username_input, 0, sizeof(username_input));
    memset(password_input, 0, sizeof(password_input));

    start:
    printf("Username: ");
    scanf("%s", &username_input);

    printf("Password: ");
    scanf("%s", &password_input);

    //compare using linked list rather than arrays (undone)
    for(int i=0; i<numAcc; i++)
    {
        if(strcmp(username_input, account[i].username)==0 && strcmp(password_input, account[i].password)==0)
        {
            printf("You have successfully logged in.");
            return 1; //returns value of database txt in linked list (undone)
        }
        else
        {
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
                    return '\0';
                }
                else
                {
                    continue;
                }
            }
            
        }

    }
}
