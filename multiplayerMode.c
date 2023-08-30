#include "myFunctions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#include <ctype.h>

struct stories story;

void gameEngine()
{
    // Displaying the welcome message

    char welcome[] = "\nWelcome to The Story Game, Enjoy Playing!\n";
    printString(welcome, DELAY, 1);

    // Taking in the number of players involved in the game
    printf("\n\n\n");
    char playerNumMsg[] = "Please enter the number of players: ";
    printString(playerNumMsg, DELAY, 0);
    int numOfPlayers, rounds;

    chk_int_input(&numOfPlayers);

    printf("\n\n");

    // Requesting for the number of rounds they wish to play
    while (numOfPlayers < 2)
    {
        // If the number of players is less than 2, Display warning message
        char warningMsg[] = "Sorry, number of players must be greater than 1. Enter a number greater than 1: ";
        ;
        printString(warningMsg, DELAY, 0);

        chk_int_input(&numOfPlayers);
        // Taking in the number of players again

        if (numOfPlayers > 1)
        {
            char successMsg[] = "\nGreat, The game is a multiplayer game, you are now ready to play!\n";
            printString(successMsg, DELAY, 0);
            printf("\n");
        }
    }
    if (numOfPlayers > 1)
    {

        // Allocating memory for pointers to individual playernames in string array
        story.playerNames = (char **)malloc(numOfPlayers * sizeof(char *));
        arrayMemAlloc(story.playerNames, numOfPlayers, "Enter name of player");
        printf("\n");

        char listOfPlayerNames[] = "The list of players playing are: \n";
        printString(listOfPlayerNames, DELAY, 1);
        for (int i = 0; i < numOfPlayers; i++)
        {
            printf("Player %d is %s\n", i + 1, story.playerNames[i]);
        }

        printf("\n");
        printStar(35, "*_*");
        printf("\nInteresting you are %d players involved\n\n\n How many rounds would you like to go: ", numOfPlayers);

        // scanf("%d", &rounds);
        // fflush(stdin);
        chk_int_input(&rounds); // replaced scanf with chk_int_input;

        printf("\n");

        // Allocating memory for pointers to individual storylines in string array
        story.storyLines = (char **)malloc(numOfPlayers * rounds * sizeof(char *));

        printf("Ok then %d Rounds you'll go", rounds);
        printf("\n");
        printStar(35, "*_*");

        /**************************************
         * PRINTING OUT INSTRUCTIONS          *
         ***************************************/
        printStar(35, "*_*");
        clearScreen();
        char instructionsMsg[] = "*       BELOW ARE THE GAME INSTRUCTIONS:         *\n";
        printString(instructionsMsg, DELAY, 0);
        printf("*1.  The %d of you are to generate a story        *\n", numOfPlayers);
        printf("*2.  So %s will start by producing the first*\n*    line of the story                           *\n", story.playerNames[0]);
        printf("*3.  Then %s will produce the second line *\n*    of the story and so on                      *\n", story.playerNames[1]);
        printf("*4.  The %d of you will continue to produce the   *\n*    story until the %d round is reached          *\n", numOfPlayers, rounds);
        printf("*5.  The story you produce should be in sync for *\n*     example                                       *\n*     %s: Once upon a time, there lived a man\n*     %s: He was a good man so kind and nice.\n*    so you'll continue untill you finish the story at the last round*\n", story.playerNames[0], story.playerNames[1]);
        printf("*5.  The story you collectively produced would be*\n*     stored and printed out for you                *\n");
        printf("*6.  Enjoy and have fun Creating stories!        *\n");
        printStar(35, "*_*");
        int round = 0;
        while (round < rounds)
        {
            printf("\n");
            printStar(35, "*_*");
            printf("\n* Round %d                                        *\n", round + 1);
            if ((round + 1) == rounds)
            {
                char alert[] = "\n* ALERT! ALERT! This is the Last Round! Work     *\n* towards concluding your Story                  *\n";
                printString(alert, DELAY, 0);
            }
            printStar(35, "*_*");
            printf("\n");

            int start = round * numOfPlayers;
            int end = (round + 1) * numOfPlayers;
            int index = 0;
            for (int i = start; i < end; i++)
            {
                if (i % 2 == 0)
                    change_txt_color("blue");
                else
                    change_txt_color("white");
                if (i < numOfPlayers)
                {
                    index = i;
                }
                else
                {
                    index = i % numOfPlayers;
                }

                char buffer[BUFFER_SIZE];
                int length = 0;
                do
                {
                    printf("Your turn %s : ", story.playerNames[index]);
                    gets(buffer);
                    length = strlen(buffer);
                    if (length == 0)
                        printf("%s, you must enter a story line Please try again\n", story.playerNames[index]);
                } while (length == 0);
                // Allocating memory for each story line
                story.storyLines[i] = (char *)malloc(length * sizeof(char));
                strcpy(story.storyLines[i], buffer);
            }
            round++;
        }
        clearScreen();

        // Printing out the story
        char storyDisp[] = "The story you produced is: \n";
        printString(storyDisp, DELAY, 1);
        for (int i = 0; i < (numOfPlayers * rounds); i++)
        {
            printf("%s\n", story.storyLines[i]);
        }

        printf("\n");

        // Asking if they want to save the story
        char saveStory[] = "Do you want to save the story? (y/n): ";
        printString(saveStory, DELAY, 0);
        char save;
        scanf("%c", &save);
        fflush(stdin);
        if (save == 'y' || save == 'Y')
        {
            // Asking for story title
            char storyTitle[] = "Enter the title of the story: ";
            printString(storyTitle, DELAY, 0);
            fgets(story.title, 50, stdin);
            story.title[strlen(story.title) - 1] = '\0';
            printf("\n");

            // Entering the date
            char dateStr[20];

            strcpy(story.date, date(dateStr));
            char fileName[] = "stories\\";
            filename(fileName);

            saveStoryToFile(fileName, &numOfPlayers, &rounds);
        }
        else if (save == 'n' || save == 'n')
        {
            char notSaved[] = "Ok then, you can always save it later\n";
            printString(notSaved, DELAY, 1);
        }
        else
            printString("Invalid CHARACTER. Ending Game...\n", DELAY, 0);

        char end[] = "THE END WE HOPE YOU ENJOYED THE GAME!\n";
        printString(end, DELAY, 1);

        // Asking if they want to play again
        char playAgain[] = "Do you want to play again? (y/n): ";
        printString(playAgain, DELAY, 0);
        char play;
        scanf("%c", &play);
        fflush(stdin);
        if (play == 'y' || play == 'Y')
        {
            gameEngine();
        }
        else
        {
            char bye[] = "Thank you for playing the game!\n";
            printString(bye, DELAY, 1);
        }

        // Freeing up the memory allocated to the player names
        freeStory(numOfPlayers, rounds);
    }
}

void saveStoryToFile(char fileName[], int *numOfPlayers, int *rounds)
{
    printStar(10, "____---____"); printf("\n");
    FILE *fp;
    fp = fopen(getFullPath(fileName), "ab");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    size_t written = fwrite(&story, sizeof(struct stories), 1, fp);

    if (written != 0)
    {
        printf("Story saved Successfully! on: %s\n", story.date);
        // printing out the number of players that played the game
        printf("Number of players: %d\n", *numOfPlayers);
        // printing out the number of rounds that were played
        printf("Number of rounds: %d\n", *rounds);
        // printing out the title of the story
        printf("Title of the story: %s\n", story.title);
        // printing out the number of story lines
        printf("Number of story lines: %d\n", *numOfPlayers * *rounds);
    }
    else
        printf("Sorry! Something went bad\n");
    fclose(fp);
    printStar(10, "~~~~__~~~~"); printf("\n");
}

void loadStories()
{
    printString("Loading Stories...\n", DELAY, 1);
    system("pause");
    printString("SORRY! THIS FEATURE IS NOT AVAILABLE YET!\n", DELAY, 1);
    system("pause");
    // FILE *fp;
    // char fileName[strlen(plyr.username)];
    // filename(fileName);
    // fp = fopen(getFullPath(fileName), "rb+");
    // if (fp == NULL)
    // {
    //     printf("Error opening file.\n");
    //     exit(1);
    // }

    // struct stories tempStory;

    // while (fread(&tempStory.id, sizeof(int), 1, fp))
    // {
    //     fread(&tempStory.rounds, sizeof(int), 1, fp);
    //     fread(&tempStory.numOfPlayers, sizeof(int), 1, fp);
    //     fread(tempStory.title, sizeof(char), MAX_TITLE_LENGTH, fp);
    //     fread(tempStory.date, sizeof(char), MAX_DATE_LENGTH, fp);
    //     /*TO DO*/
    //     // tempStory.playerNames = malloc((tempStory.numOfPlayers) * sizeof(char *));
    //     // for (int i = 0; i < tempStory.numOfPlayers; i++)
    //     // {
    //     //     tempStory.playerNames[i] = malloc(MAX_NAME_LENGTH * sizeof(char));
    //     //     fread(tempStory.playerNames[i], sizeof(char), 0, fp);
    //     // }

    //     // tempStory.storyLines = malloc(tempStory.rounds * tempStory.numOfPlayers * sizeof(char *));
    //     // for (int i = 0; i < tempStory.rounds * tempStory.numOfPlayers; i++)
    //     // {
    //     //     tempStory.storyLines[i] = malloc(BUFFER_SIZE * sizeof(char));
    //     //     fread(tempStory.storyLines[i], sizeof(char), BUFFER_SIZE, fp);
    //     // }

    //     printf("%d - %s played on %s", tempStory.id, tempStory.title, tempStory.date);
    // }
    /*To Do*/
    // // Free the memory for playerNames
    // for (int i = 0; i < tempStory.numOfPlayers; i++)
    // {
    //     free(tempStory.playerNames[i]);
    // }
    // free(tempStory.playerNames);

    // // Free the memory for storyLines
    // for (int i = 0; i < tempStory.rounds * tempStory.numOfPlayers; i++)
    // {
    //     free(tempStory.storyLines[i]);
    // }
    // free(tempStory.storyLines);

    // // Free the memory for title and date
    // free(tempStory.title);
    // free(tempStory.date);

    // fclose(fp);
}

void freeStory(int numOfPlayers, int rounds)
{
    for (int i = 0; i < numOfPlayers; i++)
    {
        free(story.playerNames[i]);
    }
    free(story.playerNames);
    // Freeing up the memory allocated to the story lines
    for (int i = 0; i < (numOfPlayers * rounds); i++)
    {
        free(story.storyLines[i]);
    }
    free(story.storyLines);
}

void arrayMemAlloc(char **strings, int total, char *print1)
{
    // Creating a temporary string to store player names
    char buffer[BUFFER_SIZE];

    int length = 0;
    for (int i = 0; i < total; i++)
    {
        length = strlen(buffer);
        do
        {
            printf("%s %d: ", print1, i + 1);
            gets(buffer);
            length = strlen(buffer);
            if (length == 0)
                printf("Please enter a valid name\n>> ");
        } while (length == 0);

        // Allocating memory for each player name
        strings[i] = (char *)malloc(length * sizeof(char));
        strcpy(strings[i], buffer);
    }
}

void homeScreen(int *opt)
{
    char firstWelcome[] = "\n\t\t\tHELLO DEAR, WELCOME! LET'S GET YOU STARTED\n\t\t__________________________________________________________\n\n";
    printString(firstWelcome, DELAY, 0);
    char chooseOperationMsg[] = "\nPlease choose your operation\n";
    printString(chooseOperationMsg, DELAY, 0);
    char operations[] = "\n1. Signup \n2. Login \n3. Exit\n";
    printString(operations, DELAY, 0);
    char inputChoiceMsg[] = "\n\nYour Choice: \t";
    printString(inputChoiceMsg, DELAY, 0);
    // scanf("%d", opt);
    // fflush(stdin);
    chk_int_input(opt); // replaced scanf with chk_int_input
}

char *date(char *dateStr)
{
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    int year = localTime->tm_year + 1900;
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    // Store the date in a variable
    sprintf(dateStr, "%d-%02d-%02d", year, month, day);

    // Return the date
    return dateStr;
}

int multiPlayer()
{
    // Asking the user if they want to load previous stories
    char loadStory[] = "Do you want to load a previous story? (Y/N): ";
    printString(loadStory, DELAY, 0);
    char load;
    scanf("%c", &load);
    // printf("Load is: %c", load);
    system("pause");
    fflush(stdin);
    while (load != 'Y' && load != 'y' && load != 'N' && load != 'n')
    {
        printString("Invalid INPUT! please try again\n>> ", DELAY, 0);
        scanf("%c", &load);
        fflush(stdin);
    }

    if (load == 'Y' || load == 'y')
    {
        // Loading the previous stories
        loadStories();
    }
    else if (load == 'N' || load == 'n')
    {
        // Calling the game engine
        gameEngine();
    }

    return 0;
}

void chk_int_input(int *input)
{
    int result;
    do
    {
        result = scanf("%d", input);
        fflush(stdin);

        if (result != 1)
        {
            printString("Invalid input, Input must be an INTEGER\n>> Please try again: ", DELAY, 0);
        }
    } while (result != 1);
    // char ch = getch();
    // if (ch == ENTER)
    // {
    //     play("select");
    // }
}

void filename(char *fileName)
{
    strcat(fileName, plyr.username);
    strcat(fileName, ".bin");
}

int getNextId(FILE *fp)
{
    int id = 1;
    struct stories s;
    while (fread(&s, sizeof(struct stories), 1, fp))
    {
        if (s.id >= id)
        {
            id = s.id + 1;
        }
    }
    return id;
}
