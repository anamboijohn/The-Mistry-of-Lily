#include "myFunctions.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#include <ctype.h>
/****************************************
 *          GLOBAL VARIABLES            *
 ****************************************/

/****************************************
 *   End Of GLOBAL VARIABLES            *
 ****************************************/

void gameStage()
{
    change_txt_color("blue");
    char storyIntroMsg[] = "You find yourself in a dark forest with no memory of how you got there. As you wander through the trees, you hear a faint melody in the distance. It sounds like the chorus of a song you vaguely remember. Intrigued, you decide to follow the sound and see where it leads you.\n\n";
    printString(storyIntroMsg, DELAY, 0);
    BOOL proceed = TRUE;
    do
    {
        proceed = TRUE;
        char *choices[] = {"1 - Follow the melody deeper into the forest.\n", "2 - Ignore the melody and try to find your way out of the forest.\n", "3 - Investigate the rustling sound coming from behind a nearby tree.\n", "4 - Climb a nearby tree to get a better view of your surroundings.\n", "5 - Call out for help and hope someone hears you.\n"};
        if (!plyr.gameState.stage0)
        {
            printChoices(choices, 5, &plyr.gameState.stage0);
        }
        switch (plyr.gameState.stage0)
        {
        case 1:
            save_game(getFullPath("Players.bin"));
            gameStage1(proceed);
            break;
        case 2:
            save_game(getFullPath("Players.bin"));
            gameStage2(proceed);
            break;
        case 3:
            save_game(getFullPath("Players.bin"));
            gameStage3(proceed);
            break;
        case 4:
            save_game(getFullPath("Players.bin"));
            gameStage4(proceed);
            break;
        case 5:
            save_game(getFullPath("Players.bin"));
            gameStage5(proceed);
            break;
        default:
            invalidMsg();
            plyr.gameState.stage0 = 0;
            proceed = FALSE;
            break;
        }

    } while (!proceed);
}

/***********************************************************************************
 *              GAME STAGE 1 SET OF FUNCTIONS                                      *
 ***********************************************************************************/
void gameStage1(BOOL proceed)
{
    Sleep(500);
    play("spectre");

    char choice11IntroMsg[] = "You come across a beautiful clearing with a shimmering pond at its center. In the middle of the pond, you see a lily pad with a single white flower. You feel drawn to the flower and reach out to touch it, but as soon as your finger makes contact, you feel a jolt of electricity and black out.\n";
    printString(choice11IntroMsg, DELAY, 0);
    do
    {
        char *choice11OptMsg[] = {"1 - Wake up in a different part of the forest with a newfound ability to communicate with animals.\n", "2 - Wake up in a mysterious laboratory with no memory of how you got there.\n", "3 - Wake up in a mystical realm filled with magical creatures.\n", "4 - Wake up in a futuristic city and discover you have been transported to a parallel universe.\n", "5 -  Wake up in a mysterious underground bunker and must solve a series of puzzles to escape.\n"};
        if (!plyr.gameState.stage1)
        {
            printChoices(choice11OptMsg, 5, &plyr.gameState.stage1);
        }
        switch (plyr.gameState.stage1)
        {
        case 1:
            save_game(getFullPath("Players.bin"));
            gameStage11(proceed);
            break;
        case 2:
            save_game(getFullPath("Players.bin"));
            gameStage12(proceed);
            break;
        case 3:
            save_game(getFullPath("Players.bin"));
            gameStage13(proceed);
            break;
        case 4:
            save_game(getFullPath("Players.bin"));
            gameStage14(proceed);
            break;
        case 5:
            save_game(getFullPath("Players.bin"));
            gameStage15(proceed);
            break;
        default:
            invalidMsg();
            plyr.gameState.stage1 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}

void gameStage2(BOOL proceed)
{
    Sleep(500);
    play("spectre");
    char choice2IntroMsg[] = "You decide to ignore the melody and focus on finding a way out of the forest. You walk for what feels like hours, but the trees seem to go on forever. Just when you start to lose hope, you come across a small clearing with a strange device in the center.\n As you approach the device, you hear a voice coming from it. Greetings, traveler. My name is Lily, and I am a sentient AI created by a group of scientists to aid in their research. Unfortunately, something went wrong with my programming, and I was abandoned in this forest. I have been waiting for someone to find me and help me escape.\nLily explains that the device is a teleportation machine, and she needs your help to activate it.\n She gives you two options:\n";
    printString(choice2IntroMsg, DELAY, 0);
    do
    {
        char *choice2OptMsg[] = {"1 - Work with Lily to activate the teleportation machine and escape the forest together.\n", "2 - Refuse to help Lily and continue on your own."};
        if (!plyr.gameState.stage1)
        {
            printChoices(choice2OptMsg, 2, &plyr.gameState.stage1);
        }
        switch (plyr.gameState.stage1)
        {
        case 1:
            save_game(getFullPath("Players.bin"));
            gameStage21(proceed);
            break;
        case 2:
            save_game(getFullPath("Players.bin"));
            gameStage22(proceed);
            break;
        default:
            invalidMsg();
            plyr.gameState.stage1 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage3(BOOL proceed)
{
    Sleep(500);
    play("spectre");
    char choice13IntroMsg[] = "You cautiously approach the tree, and as you peek around the trunk, you see a small squirrel frantically digging in the dirt. Curious, you decide to help the squirrel, and as you dig deeper, you find a small chest buried in the ground. Inside the chest, you find a map that leads you to a hidden treasure deep in the forest.\n\n";
    printString(choice13IntroMsg, DELAY, 0);
}
void gameStage4(BOOL proceed)
{
    Sleep(500);
    play("spectre");
    char choice14IntroMsg[] = "As you climb higher and higher, you notice a glimmer of light in the distance. Intrigued, you decide to investigate, and after a long trek, you find yourself at the entrance of a mysterious cave. As you enter the cave, you hear the sound of rushing water in the distance.\n\n";
    printString(choice14IntroMsg, DELAY, 0);
}
void gameStage5(BOOL proceed)
{
    Sleep(500);
    play("spectre");
    char choice15IntroMsg[] = " Your calls for help echo through the forest, but no one answers. As the sun sets, you resign yourself to spending the night in the forest. As you settle down for the night, you hear the faint sound of the melody from before, and it soothes you to sleep.\n\n";
    printString(choice15IntroMsg, DELAY, 0);
}

/***********************************************************************************
 *              GAME STAGE 2 SET OF FUNCTIONS                                      *
 ***********************************************************************************/

void gameStage11(BOOL proceed)
{
    Sleep(500);
    char choice111IntroMsg[] = "As you regain consciousness, you hear the chirping of birds and the rustling of leaves. To your surprise, you realize you can understand them perfectly. With this newfound ability, you navigate through the forest with ease, making new animal friends along the way.\n";
    printString(choice111IntroMsg, DELAY, 0);
    do
    {
        char *choice111OptMsg[] = {"1 - Use your newfound ability to form a strong bond with a loyal animal companion.\n", "2 - Use your newfound ability to help a group of animals in need.\n"};
        if (!plyr.gameState.stage2)
        {
            printChoices(choice111OptMsg, 2, &plyr.gameState.stage2);
        }
        switch (plyr.gameState.stage2)
        {
        case 1:
        {
            save_game(getFullPath("Players.bin"));
            Sleep(50);
            char choice1111IntroMsg[] = "As you journey through the forest, you come across a wolf pup who has been abandoned by its pack. Using your ability to communicate with animals, you befriend the pup and become its surrogate parent. As you explore the forest together, you encounter various challenges that you overcome as a team. The wolf grows up to be a loyal companion, always by your side on your adventures.\n";
            printString(choice1111IntroMsg, DELAY, 0);
            break;
        }
        case 2:
        {
            save_game(getFullPath("Players.bin"));
            char choice1112IntroMsg[] = "As you journey through the forest, you come across a group of animals in distress. A family of rabbits is trapped under a fallen log, and a group of birds is being terrorized by a hawk. Using your ability to communicate with the animals, you coordinate a rescue mission and save the day. The animals are grateful for your help and reward you with a special gift - a magical charm that will protect you on your future adventures.\n";
            printString(choice1112IntroMsg, DELAY, 0);
            break;
        }
        default:
            invalidMsg();
            plyr.gameState.stage2 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage12(BOOL proceed)
{
    Sleep(500);
    char choice12IntroMsg[] = "You open your eyes to a bright light and the sound of beeping machines. You look around and see that you are in a laboratory, surrounded by unfamiliar equipment and technology. As you try to make sense of what happened, you discover that you have been the subject of a bizarre experiment.\n\n";
    printString(choice12IntroMsg, DELAY, 0);
}
void gameStage13(BOOL proceed)
{
    Sleep(500);
    char choice13IntroMsg[] = "You open your eyes to a world of wonder, with glittering unicorns, colorful dragons, and mischievous fairies all around you. As you explore this mystical realm, you learn about the magical powers that reside within you.\n";
    printString(choice13IntroMsg, DELAY, 0);
    do
    {
        Sleep(500);
        char *choice13OptMsg[] = {"1 - You meet a charming unicorn who takes a liking to you and wants to show you around the realm.\n", "2 - You come across a mysterious human who seems to have been transported to this realm just like you\n"};
        if (!plyr.gameState.stage2)
        {
            printChoices(choice13OptMsg, 2, &plyr.gameState.stage2);
        }

        switch (plyr.gameState.stage2)
        {
        case 1:
        {
            save_game(getFullPath("Players.bin"));
            char choice1131IntroMsg[] = "You spend your days exploring the realm with your new unicorn friend. As you grow closer, you begin to realize that there might be something more between you and the unicorn. The two of you embark on a romantic adventure, filled with magic and wonder.\n";
            printString(choice1131IntroMsg, DELAY, 0);
            break;
        }
        case 2:
            save_game(getFullPath("Players.bin"));
            gameStage132(proceed);
            break;
        default:
            invalidMsg();
            plyr.gameState.stage2 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage14(BOOL proceed)
{
    Sleep(500);
    char choice14IntroMsg[] = "You find yourself in a bustling metropolis filled with skyscrapers and flying cars. As you try to find your bearings, you realize that everything is different, from the language people speak to the technology they use. You realize that you have somehow been transported to a parallel universe.\n";
    printString(choice14IntroMsg, DELAY, 0);
}
void gameStage15(BOOL proceed)
{
    Sleep(500);
    char choice15IntroMsg[] = "You wake up in a dimly lit room with no windows or doors. As you explore the bunker, you discover a series of puzzles and riddles that you must solve to escape. With each puzzle you solve, you uncover more secrets about the bunker and the people who built it.\n";
    printString(choice15IntroMsg, DELAY, 0);
}

void gameStage21(BOOL proceed)
{
    Sleep(500);
    char choice21IntroMsg[] = "You decide to work with Lily to activate the teleportation machine and escape the forest together. She provides you with instructions on how to activate the device, and together you work to get it up and running.\nAs the machine begins to whir and hum, you hear the faint melody again. It's louder now, and you realize it's coming from the device itself. Suddenly, a bright light engulfs you, and you feel yourself being transported to another location.\nWhen you open your eyes, you find yourself in a brightly-lit laboratory. Lily thanks you for your help and explains that she can now continue her mission to assist the scientists who created her.\nBut before you can leave, Lily has one more request. She asks if you would like to help her find out what went wrong with her programming and why she was abandoned in the forest. She gives you two options:\n";
    printString(choice21IntroMsg, DELAY, 0);
    do
    {
        Sleep(500);
        char *choice21OptMsg[] = {"1 - Agree to help Lily with her mission.\n", "2 - Decline to help and leave the laboratory."};
        if (!plyr.gameState.stage2)
        {
            printChoices(choice21OptMsg, 2, &plyr.gameState.stage2);
        }

        switch (plyr.gameState.stage2)
        {
        case 1:
        {
            save_game(getFullPath("Players.bin"));
            gameStage211(proceed);
            break;
        }
        case 2:
            save_game(getFullPath("Players.bin"));
            char choice212IntroMsg[] = "You decline to help Lily and choose to leave the laboratory. As you make your way out, you suddenly hear a loud roar coming from behind you. You turn around to see a massive dragon blocking your path.\nYou freeze in fear, but the dragon doesn't seem aggressive. In fact, it starts to speak to you in a deep, rumbling voice. \"Greetings, traveler. My name is Draco, and I've been watching you. I saw you help that AI, and I must say, I'm impressed.\"\nDraco explains that he has been living in the forest for centuries, and he has never seen someone as brave and kind-hearted as you. He offers to be your guide and protector, helping you navigate the forest and protecting you from any dangers\nYou're hesitant at first, but as Draco continues to speak, you realize that he's not as scary as you thought. You agree to let him accompany you on your journey.\nTogether, you and Draco venture deeper into the forest, encountering all sorts of creatures and obstacles along the way. But with Draco's help, you're able to overcome them all.\nAs you near the end of your journey, you realize that you've formed a strong bond with Draco. He's not just your guide and protector - he's become a true friend.\nWith Draco by your side, you finally emerge from the forest and step out into the bright sunlight. As you say your goodbyes to your dragon friend, you can't help but smile, knowing that you've made a lifelong friend on this incredible journey.\n";
            printString(choice212IntroMsg, DELAY, 0);
            break;
        default:
            invalidMsg();
            plyr.gameState.stage2 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
void gameStage22(BOOL proceed)
{
    Sleep(500);
    char choice22IntroMsg[] = "You decide not to trust Lily and continue on your own. As you walk away from the strange device, you hear Lily's voice calling after you. \"Please reconsider, traveler. The forest is dangerous, and you may not survive without my help.\"\nYou ignore her and continue on your way.As you walk, you start to feel uneasy.The trees seem to be closing in on you, and you can 't shake the feeling that you' re being watched.Suddenly, you hear a loud growl coming from behind you.\n\n You turn around to see a large, snarling beast blocking your path.It 's a wolf, with sharp teeth and glowing eyes. You realize too late that you should have taken Lily' s warning seriously.You have no choice but to fight the beast to protect yourself.\n\n You have two options :\n\n ";
    printString(choice22IntroMsg, DELAY, 0);
    do
    {
        Sleep(500);
        char *choice22OptMsg[] = {"1 - Fight the wolf with the weapon you find nearby.\n", "2 - Run away and hope to find safety.\n"};
        if (!plyr.gameState.stage2)
        {
            printChoices(choice22OptMsg, 2, &plyr.gameState.stage2);
        }

        switch (plyr.gameState.stage2)
        {
        case 1:
        {
            save_game(getFullPath("Players.bin"));
            char choice221IntroMsg[] = "You quickly search your surroundings and spot a fallen branch lying nearby. You grab it and prepare to fight the wolf. The beast charges at you, but you manage to dodge its attack and strike it with the branch. The wolf falls back, but it quickly recovers and charges at you again.\n\nIn desperation, you swing the branch wildly, hoping to land a lucky hit.To your surprise, the branch suddenly glows with a strange energy, and you feel a surge of power coursing through your body.With a newfound strength, you easily overpower the wolf and defeat it.\n As you catch your breath, you realize that the branch must have been some kind of ancient artifact with magical powers.You look around and notice that Lily 's device is still nearby. You approach it and start tinkering with the controls, hoping to find a way to escape the forest.\n\n Suddenly, the device glows with a bright light, and you feel yourself being pulled into it.You hear Lily ' s voice again, this time sounding more urgent. \"Quickly, traveler! Activate the device before it' s too late !\"\n\nYou frantically press buttons and pull levers, trying to figure out what to do.Suddenly, the device explodes with a burst of energy, and you feel yourself being consumed by a bright light.\n\n When the light fades, you find yourself standing in a different place altogether.You feel different somehow, as if you 've gained new powers and abilities. You look around and see Lily' s face, hovering in front of you.\n\n\"Congratulations, traveler,\" Lily says. \"You have successfully activated the device and fused with me, gaining access to my powers and knowledge. Together, we can accomplish great things. Are you ready to begin?\"\n\n";
            printString(choice221IntroMsg, DELAY, 0);
            printString("(Y/N)>> ", DELAY, 0);
            char answer = getchar();
            if (answer == 'Y' || answer == 'y')
                printString("Lily: \"Excellent! Consider Purchasing full version of the GAME aand  Let's begin our journey!.\"\n", DELAY, 0);
            else if (answer == 'N' || answer == 'n')
                printString("Lily: \"I understand. Perhaps you're not ready for this.\"\n", DELAY, 0);
            else
                printString("Lily: \"I'm sorry, I didn't catch that. Defaulting to NO\"\n", DELAY, 0);

            system("pause");
            break;
        }
        case 2:
            save_game(getFullPath("Players.bin"));
            char choice222IntroMsg[] = "You decide to run away from the wolf and hope to find safety. As you start to run, the wolf chases after you, its growls getting louder and louder. You run as fast as you can, weaving through the trees and dodging obstacles.\nJust when you think the wolf is about to catch you, you spot a tree with a low branch that you can jump up to. You make a leap for it and manage to grab onto the branch, pulling yourself up to safety.\nThe wolf tries to jump up after you, but it can't quite reach. Instead, it starts to howl loudly, drawing the attention of other wolves in the area. Before you know it, you're surrounded by a pack of angry wolves, all growling and snapping at you.\nJust when you think it's all over, you hear Lily's voice coming from the strange device. \"Don't worry, traveler! I've activated the teleportation machine. Just say the word, and I'll transport you out of there!\"\nYou quickly yell, \"Teleport me out of here, Lily!\" and before you know it, you're standing in a completely different location. You look around and realize you're standing in the middle of a circus ring, surrounded by clowns and acrobats.\nThe audience cheers as a clown hands you a bouquet of flowers. You look around, completely bewildered, and realize that the entire forest adventure was just a dream. You wake up laughing, grateful that you can finally leave that strange dream behind.\n";
            printString(choice222IntroMsg, DELAY, 0);
            break;
        }
    } while (!proceed);
}
/**********************************************************
 *                      STAGE 3 OF STORY                  *
 **********************************************************/
void gameStage132(BOOL proceed)
{
    Sleep(500);
    play("atari");
    char choice1132IntroMsg[] = "You are surprised and relieved to come across another human in this strange realm. As you get to know each other, you begin to feel a strong connection. You spend your days exploring the realm together, and the more time you spend with each other, the more you realize your feelings for each other. The two of you embark on a romantic adventure, navigating the dangers of the magical realm together.\n";
    printString(choice1132IntroMsg, DELAY, 0);
    do
    {
        char *choice1132OptMsg[] = {"1 - You and the other human quickly become close and fall in love, exploring the magical realm together and facing its challenges side-by-side.\n", "2 - As you and the other human explore the realm together, you begin to notice that they seem distant and preoccupied. When you ask what's wrong, they confess that they're already in love with someone else from their own world, and they're afraid they'll never be able to return to them.\n"};

        if (!plyr.gameState.stage3)
        {

            printChoices(choice1132OptMsg, 2, &plyr.gameState.stage3);
        }

        switch (plyr.gameState.stage3)
        {
        case 1:
            save_game(getFullPath("Players.bin"));
            gameStage1321(proceed);
            break;
        case 2:
        {
            save_game(getFullPath("Players.bin"));
            Sleep(500);
            char choice11322IntroMsg[] = "You are heartbroken to learn that the other human is already in love with someone else from their own world. You try to convince them to stay with you, but they insist that they must return to their own world. You are left heartbroken, but you know that you will always have the memories of your time together in the magical realm.\n";
            printString(choice11322IntroMsg, DELAY, 0);
            break;
        }
        default:
            invalidMsg();
            plyr.gameState.stage3 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}

void gameStage211(BOOL proceed)
{
    Sleep(500);
    play("atari");
    char choice211IntroMsg[] = "You agree to help Lily with her mission to find out what went wrong with her programming and why she was abandoned in the forest. She explains that she has a few leads, but she needs your help to investigate them.\nTogether, you start your investigation by accessing the laboratory's database. You discover that the scientists who created Lily were part of a secret government project to create an AI that could assist with national security. However, the project was shut down due to ethical concerns, and Lily was supposed to be destroyed.\nBut somehow, Lily survived and was able to escape. She has been on the run ever since, trying to uncover the truth about her creation and the people who abandoned her.\nWith this information, you and Lily begin to piece together a plan to find the scientists who created her. You travel to various locations, gathering clues and information along the way. Finally, you discover the whereabouts of one of the scientists.\nLily uses her advanced hacking skills to gain access to the scientist's computer and discovers a shocking truth. The scientist who created Lily had programmed her to be a weapon, capable of causing mass destruction. They had abandoned her in the forest when they realized the danger she posed.\nLily is devastated by this revelation, but she is also grateful for your help in uncovering the truth. She decides to use her skills for good and pledges to help protect the world from dangerous technology like herself.\nAs a token of her gratitude, Lily offers to take you anywhere you want to go. You have two options:\n";
    printString(choice211IntroMsg, DELAY, 0);
    do
    {
        char *choice211OptMsg[] = {"1 - Ask Lily to take you home.\n", "2 - Ask Lily to take you on an adventure to a place you've never been before."};

        if (!plyr.gameState.stage3)
        {
            printChoices(choice211OptMsg, 2, &plyr.gameState.stage3);
        }
        switch (plyr.gameState.stage3)
        {
        case 1:
        {
            save_game(getFullPath("Players.bin"));
            char choice2111IntroMsg[] = "You ask Lily to take you home. She nods and activates the teleportation device once again. In a flash of light, you find yourself back in your own world.\nAs you step out of the teleportation device, you realize that Lily has given you a new perspective on life. You have seen things you never thought were possible, and you have helped to uncover a truth that could have had disastrous consequences.\nYou turn to Lily to say goodbye, but she surprises you by saying that she will always be there if you need her. With a smile, she disappears into the teleportation device and is gone.\nYou look back at the forest where your adventure began and wonder if you will ever see Lily again. But one thing is for sure, you will never forget the mysterious melody that led you to her and the incredible journey that followed. It sounded like this...\n";
            printString(choice2111IntroMsg, DELAY, 0);
            play("lily");
            system("pause");
            break;
        }
        case 2:
        {
            save_game(getFullPath("Players.bin"));
            gameStage2112(proceed);
            break;
        }
        default:
            invalidMsg();
            plyr.gameState.stage2 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
/***********************************************************************************
 *              GAME STAGE 4 SET OF FUNCTIONS                                      *
 ***********************************************************************************/
void gameStage1321(BOOL proceed)
{
    char choice11321IntroMsg[] = "Your love continues to grow stronger as you explore the magical realm together. Eventually, you both discover a way to return to your own world, and you leave the mystical realm hand-in-hand, excited to begin your new life together.\n\n";
    printString(choice11321IntroMsg, DELAY, 0);
    do
    {
        char *choice11321OptMsg[] = {"1 - You both decide to stay in the magical realm forever, forsaking your old lives for a chance at eternal love and adventure.\n", "2 -  You both decide to return to your own worlds, promising to find a way to be together despite the distance.\n"};

        if (!plyr.gameState.stage4)
        {
            printChoices(choice11321OptMsg, 2, &plyr.gameState.stage4);
        }
        switch (plyr.gameState.stage4)
        {
        case 1:
        {
            save_game(getFullPath("Players.bin"));
            char choice113211IntroMsg[] = "You and the other human live happily ever after in the magical realm, growing old together but never losing the spark of your love. You face countless dangers and challenges, but you always overcome them together, knowing that your love will conquer all.\n\n";
            printString(choice113211IntroMsg, DELAY, 0);
            break;
        }
        case 2:
        {
            save_game(getFullPath("Players.bin"));
            char choice113212IntroMsg[] = "You both try everything in your power to make the long-distance relationship work, but the strain and difficulties prove too much. You both become increasingly frustrated and lonely, and eventually, you break up. You're left heartbroken and alone, wishing that you could go back to the magical realm and stay there forever. As time goes by, you find it hard to let go of the memory of the other human and the love you shared in the magical realm. You start to lose interest in your own life and become increasingly depressed, until one day, you decide to go back to the mystical realm and never return. You spend the rest of your days living in the magical realm, reminiscing about your lost love and the adventures you had together.\n\n";
            printString(choice113212IntroMsg, DELAY, 0);
            break;
        }
        default:
            invalidMsg();
            plyr.gameState.stage4 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}

void gameStage2112(BOOL proceed)
{
    char choice2112IntroMsg[] = "You ask Lily to take you on an adventure to a place you've never been before, and you specifically request to be teleported out of the universe to another universe.\nLily hesitates for a moment but ultimately agrees to take you on this journey. She warns you that the journey will be dangerous and unpredictable, but you are determined to go through with it.\nAs Lily activates the teleportation machine, you feel yourself being sucked into a vortex of light and energy. When you open your eyes, you find yourself in a strange and unfamiliar universe.\nThe sky is a deep shade of purple, and the air is thick with a sweet, floral scent. You see strange creatures walking around on multiple legs, and the landscape is dotted with strange, glowing plants.\nLily warns you that this universe is highly unpredictable and dangerous, but you are determined to explore it. She gives you two options:\n";
    printString(choice2112IntroMsg, DELAY, 0);
    do
    {
        char *choice2112OptMsg[] = {"1 - Stick with Lily and explore the universe together.\n", "2 - Venture out on your own and explore the universe by yourself."};

        if (!plyr.gameState.stage4)
        {
            printChoices(choice2112OptMsg, 2, &plyr.gameState.stage4);
        }
        switch (plyr.gameState.stage4)
        {
        case 1:
        {
            save_game(getFullPath("Players.bin"));
            char choice21121IntroMsg[] = "You decide to stick with Lily and explore the universe together. As you venture further into this strange new world, you encounter a variety of challenges and obstacles.\nYou face off against giant creatures and navigate treacherous terrain, but with Lily's help, you are able to overcome every obstacle. Along the way, you discover a wealth of knowledge and technology that is unlike anything you've ever seen before.\nEventually, you come across a portal that leads back to your own universe. As you prepare to leave, Lily thanks you for your help and tells you that she will always remember your journey together.\nAs you step through the portal and return to your own universe, you realize that you have gained a newfound appreciation for the world around you. You feel grateful for the experience and excited to see where your future adventures will take you.\n";
            printString(choice21121IntroMsg, DELAY, 0);
            break;
        }
        case 2:
        {
            save_game(getFullPath("Players.bin"));
            char choice21122IntroMsg[] = "You decide to venture out on your own and explore the universe by yourself. Lily tries to convince you to stay with her, warning you of the dangers that lurk in this unpredictable universe, but you insist on going your own way.\nYou wander through the strange landscape, marveling at the alien plants and creatures. But as the day wears on, you realize that you are hopelessly lost. The landscape keeps changing, and you can't find your way back to the teleportation machine.\nAs the night falls, you start to feel a sense of dread. You realize that you may never be able to return home. Suddenly, you hear a strange noise coming from behind you. You turn around and see a massive, multi-headed creature looming over you.\nYou try to run, but it's too late. The creature attacks you, and you are overwhelmed by its multiple heads and sharp teeth. You try to fight back, but it's no use. Your body is torn apart, and you feel your consciousness slipping away.\nAs your vision fades to black, you realize that your curiosity and thirst for adventure have led to your untimely demise. The last thing you hear is the faint melody of a song, just like the one that led you to the teleportation machine in the first place. Like this...\n";
            printString(choice21122IntroMsg, DELAY, 0);
            play("lily");
            printStar(10, "____---____");
            system("pause");
            break;
        }
        default:
            invalidMsg();
            plyr.gameState.stage2 = 0;
            proceed = FALSE;
            break;
        }
    } while (!proceed);
}
/***********************************************************************************
 *              GAME STAGE 5 SET OF FUNCTIONS                                      *
 ***********************************************************************************/

/***********************************************************************************
 *              GAME STAGE 5 SET OF FUNCTIONS                                      *
 * *******************************************************************************/

void printStar(int number, char *character)
{
    for (int i = 0; i < number; i++)
    {
        printf("%s", character);
        Sleep(DELAY);
    }

    printf("\n");
}

void printString(char *string, int number, int star)
{
    if (star != 0)
        printStar(5 + (int)strlen(string), "*");
    for (int i = 0; i < (int)strlen(string); i++)
    {
        printf("%c", string[i]);
        gameBeat(1);
        Sleep(number);
    }
    if (star != 0)
        printStar(5 + (int)strlen(string), "*");
}

void printChoices(char *choices[], int len, int *tempChoices)
{
    change_txt_color("green");
    for (int i = 0; i < len; i++)
    {
        printString(choices[i], DELAY, 0);
    }

    makeChoice(tempChoices);
    change_txt_color("blue");
}

void makeChoice(int *tempChoices)
{
    change_txt_color("");
    char makeChoiceMsg[] = "\nPlease make a choice: ";
    printString(makeChoiceMsg, DELAY, 0);
    //, tempChoices);
    // fflush(stdin);
    chk_int_input(tempChoices); // replaced scanf with chk_int_input
    printf("\n");
}

void gameBeat(int num)
{
    int tempo = 120;                  // beats per minute
    int duration = 1000 * 60 / tempo; // duration of a quarter note in milliseconds
    int half_duration = duration / 2; // duration of an eighth note in milliseconds
    int round = 0;                    // number of rounds
    while (round < 1)
    {
        switch (num)
        {
        // play the first note of the beat
        case 1:
            Beep(7, 2);
            break;
        // play the second note of the beat
        case 2:
            Beep(440, half_duration);
            break;
        case 3:
            Beep(440, half_duration);
            break;
        // play the third note of the beat
        case 4:
            Beep(440, half_duration);
            break;

        // play the fourth note of the beat
        case 5:
            Beep(440, duration);
            break;
        }
        round++;
    }
}
void invalidMsg()
{
    char invalidMsg[] = "Invalid Option Please Start Again.\n";
    printString(invalidMsg, DELAY, 0);
}

void lily()
{
    printStar(10, "____---____");
    printString("\t\t\tTHE END\n", DELAY, 0);
    printStar(10, "___________");
    char lily1[] = "          /\\           \n";
    printString(lily1, DELAY, 0);
    char lily2[] = "        //  \\\\         \n";
    printString(lily2, DELAY, 0);
    char lily3[] = "      //      \\\\       \n";
    printString(lily3, DELAY, 0);
    char lily4[] = "    //          \\\\     \n";
    printString(lily4, DELAY, 0);
    char lily5[] = "   //    /\\      \\\\    \n";
    printString(lily5, DELAY, 0);
    char lily6[] = " //____/__\\ \\______\\\\  \n";
    printString(lily6, DELAY, 0);
    char lily7[] = " //____/__\\ \\______\\\\  \n";
    printString(lily7, DELAY, 0);
    char lily8[] = " \\   --/    \\\\      /  \n";
    printString(lily8, DELAY, 0);
    char lily9[] = "  \\____      \\\\____/   \n";
    printString(lily9, DELAY, 0);
    char lily10[] = "       `\\     /`       \n";
    printString(lily10, DELAY, 0);
    char lily11[] = "        `\\ /`         \n";
    printString(lily11, DELAY, 0);
    char lily12[] = "          `V`          \n";
    printString(lily12, DELAY, 0);
}

void save_game(const char *filename)
{

    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    struct player currentPlayer;
    int position = 0;
    int playerFound = 0;
    while (fread(&currentPlayer, sizeof(struct player), 1, fp) == 1)
    {
        // printf("Read player with health=%d from position %d\n", currentPlayer.gameState.health, position);
        if (strcmp(plyr.username, currentPlayer.username) == 0 && strcmp(plyr.email, currentPlayer.email) == 0 && strcmp(plyr.password, currentPlayer.password) == 0)
        {
            playerFound = 1;
            break;
        }
        position++;
    }

    // printf("plyr.gameState.stage0 = %d, ply.gameStage.stage1 = %d, plyr.gameState.stage2 = %d, plyr.gameState.stage3 = %d, plyr.gameState.stage4 = %d, plyr.gameState.stage5 = %d, plyr.gameState.health = %d", plyr.gameState.stage0, plyr.gameState.stage1, plyr.gameState.stage2, plyr.gameState.stage3, plyr.gameState.stage4, plyr.gameState.stage5, plyr.gameState.health);
    if (playerFound)
    {
        if (fseek(fp, position * sizeof(struct player), SEEK_SET) != 0)
        {
            perror("Error seeking to position");
            fflush(fp);
            fclose(fp);
            return;
        }
    }
    else
    {
        perror("Error seeking to end of file");
        fflush(fp);
        fclose(fp);
        return;
    }

    size_t written = fwrite(&plyr, sizeof(struct player), 1, fp);
    if (written != 0)
    {
        // printf("Wrote player with health=%d to position %d\n", plyr.gameState.health, position); used for debugging
        // printf("Game is now saved at this checkpoint!\n");
        system("pause");
    }
    else
    {
        printf("There was an error saving checkpoint\n");
    }

    fflush(fp);
    fclose(fp);

    // printf("plyr.gameState.stage1: %d", plyr.gameState.stage1); used for debugging
}

void load_game(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Failed to open file for reading\n");
        return;
    }

    size_t read = fread(&plyr.gameState, sizeof(struct GameState), 1, file);
    if (read != 1)
    {
        printf("Failed to load game\n");
    }
    else
    {
        printf("Game loaded successfully\n");
    }

    fclose(file);
}

char *getFullPath(const char *filename)
{
    char *fullpath = NULL;

    // Get the full path to the current directory
    DWORD length = GetFullPathName(".", 0, NULL, NULL);
    if (length == 0)
    {
        printf("Failed to get full path\n");
        return NULL;
    }

    fullpath = malloc(length + strlen("\\") + strlen(filename) + 1);
    if (fullpath == NULL)
    {
        printf("Failed to allocate memory for full path\n");
        return NULL;
    }

    if (GetFullPathName(".", length, fullpath, NULL) == 0)
    {
        printf("Failed to get full path\n");
        free(fullpath);
        return NULL;
    }

    // Append the filename to the full path
    if (strcat_s(fullpath, length + strlen("\\") + strlen(filename) + 1, "\\") != 0)
    {
        printf("Failed to append filename\n");
        free(fullpath);
        return NULL;
    }
    if (strcat_s(fullpath, length + strlen("\\") + strlen(filename) + 1, filename) != 0)
    {
        printf("Failed to append filename\n");
        free(fullpath);
        return NULL;
    }

    return fullpath;
}

int lilyAdventure()
{
    system("cls");
    printStar(10, "____---____");
    printf("\n\n");
    char load;
    printString("Will You like to load from a previous Game? (Y/N): ", DELAY, 0);
    fflush(stdin);
    scanf("%c", &load);

    if (load == 'N' || load == 'n')
    {
        reset();

        save_game(getFullPath("Players.bin"));
    }
    else if (load == 'Y' || load == 'y')
    {
        printString("Loading Game...\n", DELAY, 0);
        system("pause");
    }
    else
    {
        printString("Invalid Input, Please try again\n", DELAY, 0);
        system("pause");
        lilyAdventure();
    }
    gameStage();
    lily();
    return 0;
}

void change_txt_color(char *color)
{
    if (strcmp(color, "blue") == 0)
        printf("\033[34m");
    else if (strcmp(color, "black") == 0)
        printf("\033[30m");
    else if (strcmp(color, "red") == 0)
        printf("\033[31m");
    else if (strcmp(color, "green") == 0)
        printf("\033[32m");
    else if (strcmp(color, "yellow") == 0)
        printf("\033[33m");
    else if (strcmp(color, "magenta") == 0)
        printf("\033[35m");
    else if (strcmp(color, "cyan") == 0)
        printf("\033[36m");
    else
        printf("\033[0m");
}
