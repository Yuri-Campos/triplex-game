#include <iostream>
#include <ctime>

int RandomDifficulty()
{
    int difficulty = rand() % 10 + 1;
    std::cout << difficulty << "\n";
    return difficulty;
}

void Intro()
{
    std::cout << "You are a survior trying to break into a pharmacy locker room\n";
    std::cout << "You need to insert the correct code to unlock it...\n";
    std::cout << "Near the door there's a deceased employee and blood stains are all over the keypad and you notice that only even numbers are imprinted with the poor guy's blood\n";
    std::cout << "In his jacket you find a note saing that he must not forget the 3-digit code and hints that those numbers make the last 3-digits of the pharmacy owner's id\n\n";
}

void FightSequence()
{
    // the hp has no pratical effect on this version
    int PlayerHp = 50;
    int ZedHp = 150;
    std::cout << "The infected reaches the door as you look at his dead eyes, after a small standoff he runs towards you...\n\n";

    // hp bar, only visual for now
    std::cout << "--------------------\n"
              << "YOUR HP: " << PlayerHp << "\nZOMBIE HP: " << ZedHp << "\n--------------------\n"
              << std::endl;

    // player selects an action to fight the zombie
    std::cout << "THINK QUICKLY: ";
    std::cout << "\n1-ATTACK \n2-DEFEND \n3-DODGE";
    int PlayerAction;
    std::cin >> PlayerAction;

    // if else statments to print the consequences
    if (PlayerAction == 1)
    {
        std::cout << "You stand your ground and swing your baseball bat perfectly to bash his damn brains out, congratulations you live to die another day";
    }
    if (PlayerAction == 2)
    {
        std::cout << "Block a zombie attack, really? You made a really bad decision and got bit +1 to the zombie army";
    }
    if (PlayerAction == 3)
    {
        std::cout << "As the infected attacks you manage to roll and he misses falling to the ground, right now is the time to run or smash his head to the ground\n 1-KILL\n 2-RUN";
        std::cin >> PlayerAction;
        if (PlayerAction == 1)
        {
            std::cout << "As you prepare to kick the face of this poor zombie he grabs your leg and you fall losing your bat in the process, overconfidence is really bad sometimes.\n as he's about to taste your precious flesh his head blows like a watermelon\n when you look back 3 soldiers dressed in black approach you, they're the ghosts, survivors of a Delta Force Team sent in the inital breakdown to exctract a scientist...\n\n continues...";
        }
        else
        {
            std::cout << "You run as fast as you can, without the medicine of course, your group may not like this and feels like trouble is coming soon...";
        }
        exit(0);
    }
}

void PlayGuessingGame(int SafeDifficulty)
{

    // Declaring the 3 numbers of the code
    int CodeA = rand() % SafeDifficulty + 1;
    int CodeB = rand() % SafeDifficulty + 1;
    int CodeC = rand() % SafeDifficulty + 1;

    // Logic around tips for the user
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;

    // std::cout << CodeA <<"\n" << CodeB << "\n" << CodeC << "\n" << SafeDifficulty << "\n"; //debug purposes
    if (SafeDifficulty == 1)
    {
        std::cout << "UNLOCK DIFFICULTY: EASY\n\n";
    }
    if (SafeDifficulty >= 2 && SafeDifficulty <= 7)
    {
        std::cout << "UNLOCK DIFFICULTY: MEDIUM\n\n";
    }
    if (SafeDifficulty >= 8)
    {
        std::cout << "UNLOCK DIFFICULTY: HARD\n\n";
    }

    // Print the clues
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code...\n";
    std::cout << "+ These numbers add to: " << CodeSum;
    std::cout << "\n+ Those same numbers multiply to give: " << CodeProd << std::endl;

    // declare, input and print the user guesses
    int GuessA, GuessB, GuessC;
    int Chances = 3;
    int GuessSum;
    int GuessProd;
    int NumbersRight;
    while (Chances > 0)
    {
        NumbersRight = 0;

        std::cin >> GuessA >> GuessB >> GuessC;
        std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

        // Logic around the sum and product of the guesses to provide tips for the users
        GuessSum = GuessA + GuessB + GuessC;
        GuessProd = GuessA * GuessB * GuessC;

        // if else statments to print the tips
        if (GuessA == CodeA || GuessA == CodeB || GuessA == CodeC)
        {
            NumbersRight++;
        }
        if (GuessB == CodeB || GuessB == CodeC)
        {
            NumbersRight++;
        }
        if (GuessC == CodeC)
        {
            NumbersRight++;
        }

        if (NumbersRight > 0)
        {
            std::cout << NumbersRight << " Of the selected number(s) is(are) right\n\n";
        }
        if (GuessSum == CodeSum)
        {
            std::cout << "You got the sum combination right\n";
        }
        else
        {
            std::cout << "The sum combination is wrong\n";
        }

        if (GuessProd == CodeProd)
        {
            std::cout << "You got the product combination right\n";
        }
        else
        {
            std::cout << "The product combination is wrong\n";
        }

        // logic around the code guessing part of the game
        if (GuessA == CodeA && GuessB == CodeB && GuessC == CodeC)
        {
            std::cout << "**DOOR UNLOCKS**";
            std::cout << "The combination is right, the door opens to reveal an almost untouched stash of medicine...\n\n";
            std::cout << "But through the shelves you see an infected and he runs towards you, as an experienced survivor you back up and prepare to stand your ground\n\n\n\n\n\n\n";
            FightSequence();
        }
        else
        {
            Chances--;
            if (Chances == 0)
            {
                std::cout << "**LOUD ALARM NOISES**\n";
                std::cout << "The loud noises attract all the zombies in the area, you watch from the window as they trumble towards the store\n";
                std::cout << "CONGRATULATIONS YOU ARE DEAD!!!!!\n";
            }
            if (Chances > 0)
            {
                std::cout << "**BEEP BEEP**\n";
                std::cout << "The combination is wrong and the screen warns that you have only " << Chances << " more chance(s)\n";
            }
        }
    }
    exit(0);
}

int main()
{
    srand(time(0));
    int SafeDifficulty = RandomDifficulty();
    Intro();
    PlayGuessingGame(SafeDifficulty);

    return 0;
}