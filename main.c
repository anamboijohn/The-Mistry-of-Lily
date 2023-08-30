#include "myFunctions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#include <ctype.h>


int main()
{
    change_txt_color("red");
    play("atari");
    do
    {
        authenticator();
    } while (loggedIn == 0);

    if (loggedIn == 1)
    {

        char playAgain;
        do
        {
            int gameChoice = 0;
            do
            {
                printString("\nPlease Select Your Game of Choice: \n1 - The Adventures of Lily \n2 - A Multi player story game\n", DELAY, 0);
                printString("Select: ", DELAY, 0);
                // scanf("%d", &gameChoice);
                // fflush(stdin);
                chk_int_input(&gameChoice); // Added function to check for integer input

                if (gameChoice <= 0 || gameChoice > 2)
                    printString("Invalid Selection Please try again", DELAY, 0);
            } while (gameChoice <= 0 || gameChoice > 2);

            if (gameChoice == 1)
            {
                Sleep(1000);
                play("lily");
                lilyAdventure();
            }
            else
            {
                Sleep(1000);
                play("atari");
                multiPlayer();
            }

            do
            {
                // Asking if playing will like to play again and then storing answer in variable playAgain;
                printString("Would you like to play again? (Y/N): ", DELAY, 0);

                fflush(stdin);
                scanf("%c", &playAgain);
                fflush(stdin); // Added fflush(stdin) to clear the input buffer after

                if (playAgain == 'Y' || playAgain == 'y')
                {
                    reset();
                }
            } while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && playAgain != 'n');

        } while (playAgain == 'Y' || playAgain == 'y');
    }
    else if (loggedIn == 0)
    {
        char notLoggedIn[] = "You are not logged in. Please login to play the game.\n";
        printString(notLoggedIn, DELAY, 1);
    }

    //printString("NAMES OF GROUP MEMBERS\n1. Anamboi John Aduko - 7091821\n2. Bonse Nzakame 7111821\n3. Amoateng Godfred Kofi - 7091321\n4. Nana Kwame Asare-Brobbey - 7093221\n5. DERKONG-DERY Justice Lincoln - 3029820\n6. Helechi Carl-Bright -7100021\n", DELAY, 1);
    return 0;
}

void play(char *music)
{
    PlaySound(TEXT(music), NULL, SND_ASYNC);
}

void reset()
{
    plyr.gameState.stage0 = 0;
    plyr.gameState.stage1 = 0;
    plyr.gameState.stage2 = 0;
    plyr.gameState.stage3 = 0;
    plyr.gameState.stage4 = 0;
    plyr.gameState.stage5 = 0;
    plyr.gameState.health = 100;
}
