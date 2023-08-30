#include "myFunctions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#include <ctype.h>


/*GLOBAL LOGIN VARIABLE*/
int loggedIn = 0;
struct player plyr;
/*GLOBAL LOGIN VARIABLE*/

/********************************************************************
 * PLAYER AUTHENTICATION SYSTEM                                     *
 *********************************************************************/

void takeinput(char ch[50])
{
    fflush(stdin);
    fgets(ch, 50, stdin);
    ch[strcspn(ch, "\n")] = 0; // Replaced strlen with strcspn to remove the trailing newline character
}

void generateUserName(char email[50], char username[50])
{
    int i = 0;
    while (email[i] != '@')
    {
        username[i] = email[i];
        i++;
    }
    username[i] = 0;
}

void takepassword(char pwd[50])
{
    fflush(stdin);
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if (ch == BKSP)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == SPACE)
        {
            continue;
        }
        else
        {
            pwd[i] = ch;
            i++;
            printf("*");
        }
    }
    printf("\n"); // Added newline character at the end of password input
}

int authenticator()
{
    FILE *fp;
    int opt;
    struct player player = {
        .gameState = {
            .stage0 = 0,
            .stage1 = 0,
            .stage2 = 0,
            .stage3 = 0,
            .stage4 = 0,
            .stage5 = 0,
            .health = 100,
        },
    };
    char pwdConfirm[50];
    homeScreen(&opt);
    char username[50], password[50];
    switch (opt)
    {
    case 1:
        system("cls");
        printf("\nEnter your full name: \t");
        takeinput(player.fullName);
        do{
            printf("Enter your email: \t");
            takeinput(player.email);
            if(!is_valid_email(player.email))
                printf("Invalid email address! Please try again\n>> ");
        }while(!is_valid_email(player.email));
        printf("Enter your phone number: \t");
        takeinput(player.phone);
        password:
            printf("Enter your password: \t");
            takepassword(player.password);
            printf("\nConfirm your password: \t");
            takepassword(pwdConfirm);
        if (strcmp(player.password, pwdConfirm) == 0)
        {
            generateUserName(player.email, player.username);
            printf("\nPassword Matched!\n");
            change_txt_color("cyan");
            printf("Your username is: %s\n", player.username);
            change_txt_color("");

            // storing user info into a file Players.bin
            fp = fopen("Players.bin", "ab");
            if (fp == NULL)
            {
                printf("Error opening file.\n");
                exit(1);
            }
            size_t written = fwrite(&player, sizeof(struct player), 1, fp);
            if (written != 0){
                printf("Player Registered Successfully! "); 
                change_txt_color("cyan");
                printf("Your username is: %s\n", player.username);
                change_txt_color("");
            }
            else{
                gameBeat(1);
                printf("Sorry! Something went bad\n");
            }
            fclose(fp);
        }
        else
        {
            printf("\nPassword Does Not match\n");
            Beep(500, 500);
            goto password;
        }
        break;
    case 2:
        auth: // added a label to jump to in case of failed login
        printf("\nEnter your username: \t");
        takeinput(username);
        printf("Enter your password: \t");
        takepassword(password);
        fp = fopen("Players.bin", "rb"); // changed to "rb" to read in binary mode
        if (fp == NULL)
        {
            printf("Error opening file.\n");
            exit(1);
        }
        int loginSuccess = 0; // added a flag variable to keep track of login status
        while (fread(&plyr, sizeof(struct player), 1, fp))
        {
            if (strcmp(plyr.username, username) == 0 && strcmp(plyr.password, password) == 0)
            {
                system("cls");
                printf("\nLogin Successful!\n");
                printf("\t\t\t\t--------------------WELCOME %s--------------------\n\n", strupr(plyr.fullName)); // fixed variable name here
                loginSuccess = 1;                                                                                // set flag to indicate successful login
                loggedIn = 1;
                break;
            }
        }
        fclose(fp);

        if (!loginSuccess) // if flag is not set, login failed
        {
            Beep(800, 500);
            printf("\nLogin Failed!\n");
            printf("Username or Password is incorrect\n");
            printf("Please try again\n");
            goto auth;
        }
        break;
    case 3:
        printf("Bye Bye! :)\n");
        loggedIn = 2;
        return 0;
    default:
        printf("Invalid option\n");
        break;
    }
    return 0;
}

/********************************************************************
 * END OF PLAYER AUTHENTICATION SYSTEM                                     *
 *********************************************************************/

void clearScreen()
{
    system("cls");
    printf("\n\t\t\t\t--------------------Welcome %s--------------------\t\t\t\n", plyr.username);
}

int is_valid_email(const char *email) {
    // Regular expression pattern for a valid email address
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    
    regex_t regex;
    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret != 0) {
        // Error compiling regular expression
        return 0;
    }
    
    ret = regexec(&regex, email, 0, NULL, 0);
    regfree(&regex);
    
    if (ret == 0) {
        // Email address matches the pattern
        return 1;
    } else {
        // Email address does not match the pattern
        return 0;
    }
}
