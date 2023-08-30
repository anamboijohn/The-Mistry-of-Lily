#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

#define BUFFER_SIZE 4096
#define MAX_TITLE_LENGTH 50
#define MAX_DATE_LENGTH 11
#define MAX_NAME_LENGTH 50
#define MAX_ROUNDS 100
#define MAX_PLAYERS 10
#define DELAY 0

////////////////////////////////////////////////////
#define ENTER 13 ///*
#define TAB 9    ///*
#define BKSP 8   ///*
#define SPACE 32 ///*
#define ESC 27   ///*
#define UP 72    ///*
///////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#include <ctype.h>
#include <regex.h>


// Function declarations go here
int multiPlayer();
int authenticator();
int lilyAdventure();
void reset();

//Functions from multiplayer mode
void printStar(int number, char *character);
void arrayMemAlloc(char **strings, int total, char *print1);
void printString(char *string, int number, int star);
void gameEngine();
void clearScreen();
void homeScreen(int *opt);
char *date(char *dateStr);
void loadStories();
void filename(char* filename);
void freeStory(int numofPlayers, int rounds);
void saveStoryToFile(char fileName[], int* numOfPlayers, int* rounds);


//Adventure Mode Functions
void change_txt_color(char* color);
void printChoices(char *choices[], int len, int *tempChoices);
void makeChoice(int *tempChoices);
void gameBeat(int num);
void invalidMsg();
void save_game(const char *filename);
void load_game(const char *filename);
char *getFullPath(const char *filename);
int is_valid_email(const char *email);

// first layer
void gameStage();
void gameStage1(BOOL proceed);
void gameStage2(BOOL proceed);
void gameStage3(BOOL proceed);
void gameStage4(BOOL proceed);
void gameStage5(BOOL proceed);

// Second layer//
// one
void gameStage11(BOOL proceed);
void gameStage12(BOOL proceed);
void gameStage13(BOOL proceed);
void gameStage14(BOOL proceed);
void gameStage15(BOOL proceed);

// two
void gameStage21(BOOL proceed);
void gameStage22(BOOL proceed);
void lily();

// ThirdLayer//
//  three
void gameStage132(BOOL proceed);
void gameStage211(BOOL proceed);

//Fourth Layer//
void gameStage1321(BOOL proceed);
void gameStage2112(BOOL proceed);


extern int loggedIn;

void play(char *music);
void chk_int_input(int *input);
void reset();
char *getFullPath(const char *filename);
int getNextId(FILE *fp);

struct GameState
{
    int stage0;
    int stage1;
    int stage2;
    int stage3;
    int stage4;
    int stage5;
    int health;
};

struct stories
{ // struct to store the story
    int id;
    int rounds;
    int numOfPlayers;
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH];
    char **playerNames;
    char **storyLines;
};

extern struct stories story;

struct storiesB
{ // struct to store the story
    int id;
    int rounds;
    int numOfPlayers;
    char title[MAX_TITLE_LENGTH];
    char date[MAX_DATE_LENGTH];
    char playerNames[MAX_PLAYERS][MAX_NAME_LENGTH];
    char storyLines[500][BUFFER_SIZE];
};
//extern struct storiesB story;

struct player
{
    char fullName[50];
    char email[50];
    char username[50];
    char password[50];
    char phone[50];
    struct GameState gameState;
};
extern struct player plyr;
//static int id = 0;

//Functions from authentication.c
void takeinput(char ch[50]);
void generateUserName(char email[50], char username[50]);
void takepassword(char pwd[50]);

#endif /* MY_FUNCTIONS_H */
