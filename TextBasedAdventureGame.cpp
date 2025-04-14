
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Food constants (for EatFood)
const int CANDY = 0;
const int STEAK = 1;
const int POTION = 2;
const int CANDY_RESTORE = 10;
const int STEAK_RESTORE = 20;
const int POTION_RESTORE = 40;

// Creature constants (for FightBattle)
const int BUNNY = 0;
const int DWARF = 1;
const int TROLL = 2;
const int BUNNY_DAMAGE = 5;
const int DWARF_DAMAGE = 10;
const int TROLL_DAMAGE = 20;

// Other constants
const int TUITION = 50;
const int BEER = 10;

// Function prototypes
int FindTreasure(const int max_gold);
void EatFood(const int food, int &health);
int FightBattle(const int creature);
char GetDirection();
void Room1(int &gold, int &health);
void Room2(int &gold, int &health);
void Room3(int &gold, int &health);
void Room4(int &gold, int &health);
void Room5(int &gold, int &health);
void Room6(int &gold, int &health);
void Room7(int &gold, int &health);
void Room8(int &gold, int &health);
void Exit(int &gold, int &health);

//------------------------------------------------------------
// Purpose: To calculate how much treasure is found
// Input:   Maximum amount of gold possible
// Output:  Actual amount of gold found
//------------------------------------------------------------
int FindTreasure(const int max_gold)
{
    int gold = 1 + random() % max_gold;
    if (gold < max_gold / 2)
        cout << "\nYou find " << gold << " gold pieces on the floor.\n";
    else
        cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";
    return gold;
}

//------------------------------------------------------------
// Purpose: To eating food item to restore health.
// Input:   Food item number between [0..2]
// Output:  Health value after eating food.
//------------------------------------------------------------
void EatFood(const int food, int &health)
{
    switch (food)
    {
    case CANDY:
        health = health + CANDY_RESTORE;
        cout << "\nYou find a half eaten energy bar on the floor "
             << "which restores your health by " << CANDY_RESTORE << endl;
        break;
    case STEAK:
        health = health + STEAK_RESTORE;
        cout << "\nYou find a warm and juicy steak on the table "
             << "which restores your health by " << STEAK_RESTORE << endl;
        break;
    case POTION:
        health = health + POTION_RESTORE;
        cout << "\nYou find a green glowing potion on a shelf "
             << "which restores your health by " << POTION_RESTORE << endl;
        break;
    default:
        cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
        break;
    }

    // Check maximum value for health
    if (health > 100)
        health = 100;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int FightBattle(const int creature)
{
    int damage = 0;
    switch (creature)
    {
    case BUNNY:
        damage = 1 + random() % BUNNY_DAMAGE;
        cout << "\nYou trip over a cute bunny and do "
             << damage << " damage to your health.\n";
        break;
    case DWARF:
        damage = 1 + random() % DWARF_DAMAGE;
        cout << "\nA drunken dwarf hits you with a beer mug and does "
             << damage << " damage to your health.\n";
        break;
    case TROLL:
        damage = 1 + random() % TROLL_DAMAGE;
        cout << "\nAn angry troll kicks you in the rear and does "
             << damage << " damage to your health.\n";
        break;
    default:
        cout << "\nIt is ghostly quiet here, you must be alone\n";
        break;
    }
    return damage;
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
    cout << "\nWhat direction would you like to go (N,S,E,W): ";
    char direction;
    cin >> direction;
    direction = toupper(direction);
    while ((direction != 'N') && (direction != 'S') &&
           (direction != 'E') && (direction != 'W'))
    {
        cout << "Sorry, You can not go that way...\n";
        cout << "What direction would you like to go (N,S,E,W): ";
        cin >> direction;
        direction = toupper(direction);
    }
    return direction;
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room1(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou just stumbled into a hole in the ground. When you\n";
    cout << "shake off the dirt and leaves you realize you are in\n";
    cout << "the entrance to a cave that looks man made. As you\n";
    cout << "take a look around, you decide it might be fun to explore.\n";

    gold += FindTreasure(20);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'E')
        Room2(gold, health);
    else
        Room1(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room2(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered the throne room. In the middle\n";
    cout << "of the room there is a giant wooden throne with\n";
    cout << "intricate carvings. As you take a closer look at the\n";
    cout << "carvings, you see that they show trolls chasing humans.\n";
    cout << "Hmmm, maybe this is not a great place to stop for a rest.\n";

    health -= FightBattle(TROLL);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'W')
        Room1(gold, health);
    else if (direction == 'E')
        Room3(gold, health);
    else if (direction == 'S')
        Room7(gold, health);
    else
        Room2(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room3(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered an abandoned pub. There are piles\n";
    cout << "of dirty dishes and empty beer mugs all over the place.\n";
    cout << "You hear someone coming and duck behind a table to hide.\n";

    gold += FindTreasure(5);
    health -= FightBattle(DWARF);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'W')
        Room2(gold, health);
    else if (direction == 'S')
        Room5(gold, health);
    else
        Room3(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room4(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered a huge storage room filled with empty boxes.\n";
    cout << "Looking at the side of one box, you see 'ACME troll food'.\n";
    cout << "You better get out of here before you end up on the menu.\n";

    gold += FindTreasure(15);
    health -= FightBattle(BUNNY);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'N')
        Room7(gold, health);
    else if (direction == 'W')
        Room6(gold, health);
    else
        Room4(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room5(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered an eerie room that is extremely cold and icy.\n";
    cout << "There is a troll and a goblin frozen together in ice and a sign next to it.\n";
    cout << "You go closer to the sign and it reads 'The great goblin king and troll queen.\n";
    cout << "Fascinated you look around the room for a way out unable to handle the cold.\n";

    EatFood(CANDY, health);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'W')
        Room7(gold, health);
    else if (direction == 'N')
        Room3(gold, health);
    else
        Room5(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room6(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered a huge cozy room with three small dainty houses. You walk past\n";
    cout << "the houses slowly when you see a drunk dwarf napping on the floor. The drunk dwarf has\n";
    cout << "a tool belt around his waist. It appears he is the blacksmith. However you do not want to \n";
    cout << "wake him up and get him mad. You quietly try to find your way out of the cave.\n";

    gold += FindTreasure(20);
    EatFood(STEAK, health);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'S')
        Room8(gold, health);
    else if (direction == 'E')
        Room4(gold, health);
    else
        Room6(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room7(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered a room filled with rocks that are purple.\n";
    cout << "The rocks have a mysterious symbol and emit a purple glow.\n";
    cout << "You hear a roar in the distance and hide behind a boulder.\n";

    gold += FindTreasure(10);
    health -= FightBattle(TROLL);
    health -= FightBattle(TROLL);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'N')
        Room2(gold, health);
    else if (direction == 'S')
        Room4(gold, health);
    else if (direction == 'E')
        Room5(gold, health);
    else
        Room7(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room8(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou have entered a huge room filled with trees and birds.\n";
    cout << "The room is filled with echoes of a waterfall and\n";
    cout << "the air is damp and cool. You see a ray of light\n";
    cout << "coming from a tunnel to the south.\n";

    EatFood(POTION, health);

    cout << "\nHealth: " << health << " Gold: " << gold << endl;

    char direction = GetDirection();
    if (direction == 'S')
        Exit(gold, health);
    else if (direction == 'N')
        Room6(gold, health);
    else
        Room8(gold, health);
}

//------------------------------------------------------------
// Purpose: To exit the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Exit(int &gold, int &health)
{
    cout << "\n------------------------------------------------------------\n";
    cout << "\nYou crawl out of the cave and blink your eyes to\n";
    cout << "adjust to the bright sunshine. Congratulations,\n";
    cout << "you made it out of the cave with " << health << " health!\n";

    if (gold >= TUITION)
    {
        cout << "\nYou empty your pockets and discover " << gold << " gold coins.\n";
        cout << "This will pay for tuition next semester!!!\n";
    }
    else if (gold >= BEER)
    {
        cout << "\nYou notice that you have " << gold << " gold coins in your pocket.\n";
        cout << "This will pay for beer and pizza next semester!!!\n";
    }
    else
    {
        cout << "\nYou check your pocket and find " << gold << " gold coins.\n";
        cout << "Exploring caves sure is a hard way to make money!!!\n";
    }

    // Leave program
    exit(0);
}

//------------------------------------------------------------
// Purpose: Main function of the game
// Input:   None
// Output:  None
//------------------------------------------------------------
int main()
{
    // Initialize game
    int gold = 0;
    int health = 100;
    srandom(time(NULL));

    // Start the game
    Room1(gold, health);
    return 0;
}