#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <string>
#include <algorithm>

// Get console dimensions
void getConsoleDimensions(int& width, int& height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// Calculate starting positions based on console size
int calculateStartX() {
    int width;
    int height;
    getConsoleDimensions(width, height);
    return (width - 25) / 2;  // Center the game horizontally
}

int calculateStartY() {
    int width;
    int height;
    getConsoleDimensions(width, height);
    return (height - 10) / 2;  // Center the game vertically
}

using namespace std;

void hideCursor(void)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);
}
void screenClear(void) {
    system("cls");
}
void cursorMovement(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void border(void)
{
    int i, bar1 = 219;
    int width = 25, height = 10;

    cursorMovement(calculateStartX(), calculateStartY());
    for (i = 0; i < width; i++)
    {
        cout << char(bar1);
    }
    for (i = 0; i < height; i++)
    {
        cursorMovement(width - 1 + calculateStartX(), i + calculateStartY());
        cout << char(bar1);
    }
    for (i = 0; i < width; i++)
    {
        cursorMovement(width - i - 1 + calculateStartX(), height - 1 + calculateStartY());
        cout << char(bar1);
    }
    for (i = 0; i < height; i++)
    {
        cursorMovement(0 + calculateStartX(), height - i - 1 + calculateStartY());
        cout << char(bar1);
    }
    cursorMovement(0, height + 3);
}
void printIntro(void) {

    string stickMan[3] = { "  O   ", " /|\\    ", " / \\  " };
    string stickManUpsideDown[3] = { "     \\ /   ", "      |     ", "     /O\\   " };

    cout << "\n\n\t\t\t\t=========================================" << endl;
    cout << "\t\t\t\t|  |  __         ___            __          " << endl;
    cout << "\t\t\t\t|__| |  | |\\  | |     |\\    /| |  | |\\  |" << endl;
    cout << "\t\t\t\t|  | |__| | \\ | | __  | \\  / | |__| | \\ |" << endl;
    cout << "\t\t\t\t|  | |  | |  \\| |___| |  \\/  | |  | |  \\|" << endl;
    cout << "\t\t\t\t=========================================\n" << endl;
    cout << "\t\t\t\tBy Akin Bektas\n" << endl;
    cout << "\n";
    cout << "\t\t\t\tGuess the word in less than 9 mistakes to win.\n" << endl;
    cout << "\n";

    system("COLOR 0e");

    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    int i, width = 25, height = 10;

    cursorMovement(calculateStartX()-8, calculateStartY() + 10);
    cout << "Loading...";
    cout << "\n\n\t\t\t\t\t";

    for (int i = 0; i < 25; i++)
        cout << (char)bar1;

    cout << "\r";
    cout << "\t\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cursorMovement(calculateStartX()-8 + i, calculateStartY() + 11 + j);
            cout << stickMan[j];
        }
        cursorMovement(calculateStartX()-8+ i, calculateStartY() + 12);
        cout << (char)bar2;
        Sleep(150);
    }

    cout << endl;
    string startSign;
    cout << "\n\t\t\t\t" << "Please Type Any Button To Start Game " << (char)1 << (char)1 << endl;;
    startSign = _getch();

    screenClear();

    cursorMovement(calculateStartX(), calculateStartY());
    srand(time(NULL));
    int ColorIndex;
    for (i = 0; i < width; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cout << char(bar2);
        Sleep(5);
    }
    for (i = 0; i < height; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(width - 1 + calculateStartX(), i + calculateStartY());
        cout << char(bar2);
        Sleep(5);
    }
    for (i = 0; i < width; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(width - i - 1 + calculateStartX(), height - 1 + calculateStartY());
        cout << char(bar2);
        Sleep(5);
    }
    for (i = 0; i < height; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(0 + calculateStartX(), height - i - 1 + calculateStartY());
        cout << char(bar2);
        Sleep(5);
    }
    cursorMovement(0, height + 3);

    screenClear();

    string hangedman[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |   /|\\  " ,"  |   / \\  " ,"  |         ","__|__       " };

    for (int i = 0; i < 7; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        border();
        cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
        cout << hangedman[i];
        Sleep(300);
    }
}
void printHangedMan(int guessesLeft) {

    int i, ColorIndex;
    cursorMovement(calculateStartX(), calculateStartY());
    if (guessesLeft == 10) {
        cursorMovement(calculateStartX() + 6, calculateStartY() + 4);
        cout << "Man Is Alive ";
        cursorMovement(calculateStartX() + 6, calculateStartY() + 5);
        cout << "Don't Worry !";
    }
    if (guessesLeft == 9) {

        string guessesLeft9[6] = { "  |  ", "  |  ", "  |  ", "  |  ", "  |  ", "__|__" };

        for (i = 0; i < 6; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 2);
            cout << guessesLeft9[i];
        }
    }
    if (guessesLeft == 8) {

        string guessesLeft8[7] = { "  ______    " ,"  |         " ,"  |         " ,"  |         " ,"  |         " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft8[i];
        }
    }
    if (guessesLeft == 7) {

        string guessesLeft7[7] = { "  ______    " ,"  |    |    " ,"  |         " ,"  |         " ,"  |         " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft7[i];
        }
    }
    if (guessesLeft == 6) {

        string guessesLeft6[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |         " ,"  |         " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft6[i];
        }
    }
    if (guessesLeft == 5) {
        string guessesLeft5[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |    |    " ,"  |         " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft5[i];
        }
    }
    if (guessesLeft == 4) {
        string guessesLeft4[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |   /|    " ,"  |         " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft4[i];
        }
    }
    if (guessesLeft == 3) {
        string guessesLeft3[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |   /|\\  " ,"  |         " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft3[i];
        }
    }
    if (guessesLeft == 2) {
        string guessesLeft2[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |   /|\\  " ,"  |   /     " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft2[i];
        }
    }
    if (guessesLeft == 1) {
        string guessesLeft1[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |   /|\\  " ,"  |   / \\  " ,"  |         ","__|__       " };

        for (i = 0; i < 7; i++)
        {
            cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
            cout << guessesLeft1[i];
        }
    }
    cursorMovement(calculateStartX() + 5, calculateStartY() + 14);
}
void outroLost(void)
{
    screenClear();
    srand(time(NULL));
    int ColorIndex = 6;
    string lost[] = { " _____     __   __   ________   ______       ________   ______   ___    ___    ","|     \\   |  | |  | /  ______| |   ___|     |__    __| |  _   |  \\  \\  /  / ","|  |\\  \\  |  | |  | |  |       |  |___         |  |    | |_|  |   \\  \\/  / ","|  | \\  \\ |  | |  | |  |       |   ___|        |  |    |     _|    \\    /   ","|  |  \\  \\|  | |  | |  |_____  |  |___         |  |    |  |\\  \\     |  |   ","|__|   \\_____| |__| \\________| |______|        |__|    |__| \\__\\    |__|   " };

    for (int i = 0; i < 6; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(calculateStartX() + 23, calculateStartY() + 5 + i);
        cout << lost[i];
        Sleep(100);
    }
}
void outroWin(void)
{
    screenClear();
    srand(time(NULL));
    int ColorIndex = 6;
    string win[] = { " ___      ____      ___   _____     " ," \\  \\    /    \\    /  /  |  _  | ","  \\  \\  /  __  \\  /  /   |   __| ","   \\  \\/  /  \\  \\/  /    |  |   ","    \\    /    \\    /     |  |     ","     \\__/      \\__/      |__|     " };

    for (int i = 0; i < 6; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(calculateStartX() + 38, calculateStartY() + 5 + i);
        cout << win[i];
        Sleep(100);
    }
}
void hiddenWord(string* word) {/*Girilen kelimeyi gizlemek için oluşturulmuş fonksiyon*/
    string flag, hidden;
    flag = *word;

    for (int i = 0; i < flag.length(); i++)
    {
        if (flag[i] >= 65 && flag[i] <= 90)
        {
            hidden = hidden + "_";
            continue;
        }

        hidden = hidden + " ";
    }
    *word = hidden;
}
int livesWillTaken(char letter, string str) {
    int minDistance = INT_MAX;
    char closest = '\0';

    for (char let : str) {
        int distance = abs(let - letter);
        if (distance < minDistance) {
            minDistance = distance;
            closest = let;
        }
    }
    return abs(closest - letter);
}
void write(string array[], int size, int heig)
{
    for (int i = 0; i < size; i++)
    {
        cursorMovement(calculateStartX() + 5, calculateStartY() + heig + i);
        cout << array[i];
        Sleep(100);
    }
}
void write2(string array[], int size, int startx, int starty)
{
    for (int i = 0; i < size; i++)
    {
        cursorMovement(startx + 5 + i, starty + 13);
        cout << array[i];
        Sleep(50);
    }
}
void rulebook(void)
{
    const string reset("\033[0m");
    string start[5] = { "Really ?","You want to see rulebook for hangman ?","Easiest game ever made ?","Whateverrr...","Wait A Second" };
    string rules[8] = { "1) Choose one person to be the host and make the puzzle.","2) Pick the secret word if you are the host.","3) Draw a blank line for each letter in the word.","4) Start guessing letters if you are the player.", "5) Fill the letter in the blanks if the players guess correctly.", "6) Draw part of the hangman when the players guess wrong.", "7) The players win when they guess the correct word.", "8) Play multiplayer or single player to practice by yourself." };
    int ColorIndex;

    for (int i = 0; i < 5; i++)
    {
        screenClear();
        cursorMovement(calculateStartX() + 35, calculateStartY() + 10);
        cout << start[i];
        Sleep(1500);
    }
    screenClear();
    for (int i = 0; i < 8; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(calculateStartX() + 30, calculateStartY() + 10 + i);
        cout << rules[i];
        Sleep(300);
    }
    cout << reset;
}
void multiplayerOutro(string name1, string name2)
{
    int gun = 218, i, j;
    const string red("\033[0;31m");
    const string reset("\033[0m");

    string hangman[3] = { "       O    " ,"      /|\\  " ,"      / \\  " };
    string hangmanWin[3] = { "      \\O/    " ,"       |    " ,"      / \\  " };
    string hangmanGun[3] = { "       O___  " ,"       |/  " ,"      / \\  " };
    string hangmanDead[3] = { "__" ,"_" ,"__    o  " };
    string bullet = "-";

    cursorMovement(calculateStartX() + 22, calculateStartY() + 6);
    cout << name1;
    cursorMovement(calculateStartX() + 76, calculateStartY() + 6);
    cout << name2;

    for (i = 0; i < 3; i++)
    {
        cursorMovement(calculateStartX() + 15, calculateStartY() + 8 + i);
        cout << hangman[i];
        cursorMovement(calculateStartX() + 69, calculateStartY() + 8 + i);
        cout << hangman[i];
    }
    Sleep(1000);
    for (i = 0; i < 50; i++)
    {
        screenClear();
        cursorMovement(calculateStartX() + 22, calculateStartY() + 6);
        cout << name1;
        cursorMovement(calculateStartX() + 76, calculateStartY() + 6);
        cout << name2;
        for (j = 0; j < 3; j++)
        {
            cursorMovement(calculateStartX() + 15, calculateStartY() + 8 + j);
            cout << hangmanGun[j];
            cursorMovement(calculateStartX() + 69, calculateStartY() + 8 + j);
            cout << hangman[j];
        }
        cursorMovement(calculateStartX() + 27 + i, calculateStartY() + 8);
        cout << bullet[0];

        Sleep(5);
    }
    screenClear();
    for (i = 0; i < 3; i++)
    {

        cout << reset;
        cursorMovement(calculateStartX() + 22, calculateStartY() + 6);
        cout << name1;
        cursorMovement(calculateStartX() + 15, calculateStartY() + 8 + i);
        cout << hangmanWin[i];
        cout << red;
        cursorMovement(calculateStartX() + 76, calculateStartY() + 6);
        cout << name2;
        cursorMovement(calculateStartX() + 69 + i, calculateStartY() + 10);
        cout << hangmanDead[i];
    }
}

void printQuitStart(void) {

    int bar1 = 177, bar2 = 219;
    int i, width = 25, height = 10;

    screenClear();

    cursorMovement(calculateStartX(), calculateStartY());
    srand(time(NULL));
    int ColorIndex;
    for (i = 0; i < width; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cout << char(bar2);
        Sleep(5);
    }
    for (i = 0; i < height; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(width - 1 + calculateStartX(), i + calculateStartY());
        cout << char(bar2);
        Sleep(5);
    }
    for (i = 0; i < width; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(width - i - 1 + calculateStartX(), height - 1 + calculateStartY());
        cout << char(bar2);
        Sleep(5);
    }
    for (i = 0; i < height; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        cursorMovement(0 + calculateStartX(), height - i - 1 + calculateStartY());
        cout << char(bar2);
        Sleep(5);
    }

    screenClear();

    string hangedman[7] = { "  ______    " ,"  |    |    " ,"  |    O    " ,"  |   /|\\  " ,"  |   / \\  " ,"  |         ","__|__       " };

    for (int i = 0; i < 7; i++)
    {
        ColorIndex = rand() % 14 + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
        border();
        cursorMovement(calculateStartX() + 6, calculateStartY() + i + 1);
        cout << hangedman[i];
        Sleep(300);
    }
}
void borderRemove(void)
{
    int i, bar1 = 219;
    int width = 25, height = 10;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);

    for (i = 0; i < height; i++)
    {
        cursorMovement(calculateStartX(), calculateStartY() + i);
        cout << char(bar1);
        Sleep(10);
    }
    for (i = 0; i < width; i++)
    {
        cursorMovement(calculateStartX() + i, calculateStartY() + height - 1);
        cout << char(bar1);
        Sleep(10);
    }
    for (i = 0; i < height; i++)
    {
        cursorMovement(calculateStartX() + width - 1, calculateStartY() + height + calculateStartY() - i - 1);
        cout << char(bar1);
        Sleep(10);
    }
    for (i = 0; i < width; i++)
    {
        cursorMovement(calculateStartX() + width - i, calculateStartY());
        cout << char(bar1);
        Sleep(10);
    }
    cursorMovement(0, height + 3);
}
void goodBye(int size)
{
    string goodBye[13] = { "*****************************   " ,"  _____  ___    ___  ______     "," |     \\ \\  \\  /  / |   ___| " ," |  -  /  \\  \\/  /  |  |___   "," |  --|    \\    /   |   ___|   "," |  -  \\    |  |    |  |___    "," |_____/    |__|    |______|    " ,"  " ,"*****************************   ","              | ","              | ","              | ","              | " };

    for (int i = 0; i < size; i++)
    {
        cursorMovement(calculateStartX() - 1, calculateStartY() + 5 + i);
        cout << goodBye[i];
    }

}
void hangedManFallAnimation(void)
{
    const string reset("\033[0m");
    string hangedman[2][3] = { {"       O    " ,"      /|\\  " ,"      / \\  "}, {"      \\O/   ", "       |    ", "      / \\  "} };

    int flagStartY = calculateStartY() + 3;
    int countSize = 0;

    cout << reset;
    for (int i = 0; i < 15; i++)
    {
        if ((i % 2) == 0)
        {
            screenClear();
            for (int j = 0; j < 3; j++)
            {
                cursorMovement(calculateStartX() + 6, flagStartY + 3 + j);
                cout << hangedman[0][j];
            }
            flagStartY = flagStartY + 1;
        }
        else
        {
            screenClear();
            for (int j = 0; j < 3; j++)
            {
                cursorMovement(calculateStartX() + 6, flagStartY + 3 + j);
                cout << hangedman[1][j];
            }
            flagStartY = flagStartY + 1;
        }
        if (flagStartY >= calculateStartY() + 4)
        {
            countSize++;
            goodBye(countSize);
        }
        Sleep(200);
    }
}
void Quit(void)
{
    const string reset("\033[0m");

    printQuitStart();
    borderRemove();

    string hangedman[3] = { "       O    " ,"      /|\\  " ,"      / \\  " };
    string removeRope[4] = { "__|__       " ,"  |         " ,"  |    |    " ,"  ______    " };

    for (int j = 0; j < 2; j++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        cursorMovement(calculateStartX() + 6, calculateStartY() + 7 - j);
        cout << removeRope[j];
        Sleep(300);
    }
    for (int i = 2; i > -1; i--)
    {
        cout << reset;
        cursorMovement(calculateStartX() + 6, calculateStartY() + 3 + i);
        cout << hangedman[i];
        Sleep(300);
    }
    for (int j = 1; j < 3; j++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        cursorMovement(calculateStartX() + 6, calculateStartY() + 3 - j);
        cout << removeRope[j];
        Sleep(300);
    }

    hangedManFallAnimation();
    cursorMovement(calculateStartX(), calculateStartY() + 20);
}

struct Player {
    string name;
    int point;
};

int main()
{
    const string reset("\033[0m");
    hideCursor();
    printIntro();
menu:
    cout << reset;
    string menu[] = { "1-) Singleplayer","2-) Multiplayer","3-) RuleBook","4-) Quit" };
    write(menu, 4, 13);

    string Word, hiddenW;
    string words[49] = { "antifungal","antifungals","bifunctional","cofunction","cofunctions","foxglove","frazzled","frizzled","fuchsia","funny","gabby","galaxy","galvanize","gazebo","giaour","gizmo","glowworm","psyche","quiz","khaki", "kilobyte", "shiv", "strength", "stronghold", "stymied", "zodiac", "zombie", "zipper", "yippee", "wizard", "xylophone", "whiskey", "waxy", "walkway", "voodoo", "vodka", "voyeurism", "triphthong", "transcript", "syndrome", "subway", "swivel", "luxury", "lucky", "marquis", "megahertz", "microwave", "nowadays", "oxygen" };
    char letter;
    int lives = 10;
    char Answerflag;

    Answerflag = _getch();
    const int Answer = Answerflag;

    if (Answer == 49)
    {
        string wrongLetters, allLetters;
        screenClear();
        /*Kelimelerin bulundğ arrayden rastgele kelime çekme ksmı*/
        srand(time(NULL));
        int RandIndex = rand() % 49;
        Word = words[RandIndex];
        transform(Word.begin(), Word.end(), Word.begin(), ::toupper);
        hiddenW = Word;
        hiddenWord(&hiddenW);

        border();
        printHangedMan(lives);
        string message[] = { "G","O","O","D"," ","L","U","C","K"," ","!","!" ,"!" };
        write2(message, 13, calculateStartX(), calculateStartY());
        Sleep(1000);
        screenClear();

        do
        {
        x:
            border();
            printHangedMan(lives);

            int countTrue = 0;
            cursorMovement(calculateStartX(), calculateStartY() + 12);
            cout << hiddenW << endl;
            cursorMovement(calculateStartX(), calculateStartY() + 16);
            cout << "Wrong Letters You Have Already Tried: " << wrongLetters << endl;
            cursorMovement(calculateStartX(), calculateStartY() + 17);
            cout << "Can You Enter A Letter: ";
            letter = _getch();

            if (letter == 27)
            {
                screenClear();
                border();
                printHangedMan(10);
                goto menu;
            }
            else
            {
                letter = toupper(letter); /*Girilen harfi büyük harfe eviriyor*/
                screenClear();

                for (int i = 0; i < allLetters.length(); i++)
                {
                    if (letter == allLetters[i])
                    {
                        cursorMovement(calculateStartX(), calculateStartY() + 18);
                        cout << "You Have Already Entered This Letter!" << endl;
                        goto x;
                    }
                }

                /*Girilen harfi tm kelime içerisinde arayıp, gizlenmiş olanda açıa çkarıyor*/
                for (int i = 0; i < Word.length(); i++)
                {
                    if (letter == Word[i])
                    {
                        hiddenW[i] = letter;
                        countTrue++;
                        allLetters = allLetters + letter;
                    }
                }
                if (countTrue == 0)
                {
                    cursorMovement(calculateStartX(), calculateStartY() + 18);
                    cout << "Wrong letter" << endl;
                    wrongLetters = wrongLetters + letter + " ";
                    allLetters = allLetters + wrongLetters;

                    /*Ceza ksmı (gidecek olan can)*/
                    if (livesWillTaken(letter, Word) <= 5) {
                        lives = lives - 1;
                    }
                    else if (livesWillTaken(letter, Word) > 5 && livesWillTaken(letter, Word) <= 10) {
                        lives = lives - 2;
                    }
                    else if (livesWillTaken(letter, Word) > 10 && livesWillTaken(letter, Word) <= 15) {
                        lives = lives - 3;
                    }
                    else if (livesWillTaken(letter, Word) > 15 && livesWillTaken(letter, Word) <= 20) {
                        lives = lives - 4;
                    }
                    else if (livesWillTaken(letter, Word) > 20 && livesWillTaken(letter, Word) <= 25) {
                        lives = lives - 5;
                    }
                }
                /*Kaybetme durumu*/
                if (lives < 1)
                {
                    outroLost();
                    string quit[] = { "To Return To The Main Menu Press R","To Close The Game Press Q" };
                again:
                    for (int i = 0; i < 2; i++)
                    {
                        int ColorIndex = rand() % 14 + 1;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
                        cursorMovement(calculateStartX() + 38, calculateStartY() + 13 + i);
                        cout << quit[i];
                        Sleep(100);
                    }
                    char answer;
                    answer = _getch();

                    if ((answer == 'Q') || (answer == 'q'))
                    {
                        Quit();
                        return 0;
                    }
                    if ((answer == 'R') || (answer == 'r'))
                    {
                        goto menu;
                    }
                    else
                    {
                        goto again;
                    }
                }
                /*Kazanma durumu*/
                if (hiddenW == Word)
                {
                    outroWin();
                    string quit2[] = { "To Return To The Main Menu Press R","To Close The Game Press Q" };
                again2:
                    for (int i = 0; i < 2; i++)
                    {
                        int ColorIndex = rand() % 14 + 1;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
                        cursorMovement(calculateStartX() + 38, calculateStartY() + 13 + i);
                        cout << quit2[i];
                        Sleep(100);
                    }
                    char answer;
                    answer = _getch();

                    if ((answer == 'Q') || (answer == 'q'))
                    {
                        Quit();
                        return 0;
                    }
                    if ((answer == 'R') || (answer == 'r'))
                    {
                        goto menu;
                    }
                    else
                    {
                        goto again2;
                    }
                }
            }


        } while (1);
    }
    if (Answer == 50)
    {
        int lastPoint;
        bool turn = true;
        screenClear();
        /*iki oyunculu moddaki oyuncuların isim ve puan verileri kayıtı*/
        Player player1, player2;

        border();
        printHangedMan(lives);

        string messageplayer1[] = { "P","l","a","y","e","r","1",":"," " };
        string messageplayer2[] = { "P","l","a","y","e","r","2",":"," " };
        string messagepoint[] = { "T","h","e"," ","P","o","i","n","t"," ","W","h","i","c","h"," ","G","a","m","e"," ","W","i","l","l"," ","E","n","d"," ",":"," " };

        write2(messageplayer1, 9, calculateStartX(), calculateStartY());
        cin >> player1.name;

        cursorMovement(calculateStartX() + 5, calculateStartY() + 15);
        write2(messageplayer2, 9, calculateStartX(), calculateStartY() + 1);
        cin >> player2.name;

        cursorMovement(calculateStartX() + 5, calculateStartY() + 16);
        write2(messagepoint, 32, calculateStartX(), calculateStartY() + 2);
        cin >> lastPoint;

        player1.point = 0;
        player2.point = 0;

        screenClear();

        do {

            string wrongLetters2, allLetters2;
            if (turn == true)
            {
                lives = 10;
                border();
                printHangedMan(lives);

                cursorMovement(calculateStartX() + 2, calculateStartY() + 14);
                cout << "Word Writing Tour For " << player1.name << endl;

                cursorMovement(calculateStartX() + 2, calculateStartY() + 15);
                cout << "Please Type Your Word: ";
                cin >> Word;
                transform(Word.begin(), Word.end(), Word.begin(), ::toupper);

                hiddenW = Word;
                hiddenWord(&hiddenW);

                do
                {
                y:
                    border();
                    printHangedMan(lives);
                    cout << "\n";
                    int countTrue = 0;

                    cursorMovement(calculateStartX() + 2, calculateStartY() + 12);
                    cout << hiddenW << endl;

                    cursorMovement(calculateStartX() + 2, calculateStartY() + 14);
                    cout << "Wrong Letters You Have Already Tried: " << wrongLetters2 << endl;


                    cursorMovement(calculateStartX() + 2, calculateStartY() + 15);
                    cout << player2.name << " Please Enter Your Guess: ";
                    letter = _getch();

                    if (letter == 27)
                    {
                        screenClear();
                        border();
                        printHangedMan(10);
                        goto menu;
                    }
                    else
                    {
                        letter = toupper(letter); /*Girilen harfi büyük harfe eviriyor*/
                        screenClear();

                        for (int i = 0; i < allLetters2.length(); i++)
                        {
                            if (letter == allLetters2[i])
                            {

                                cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                                cout << "You Have Already Entered This Letter!" << endl;

                                cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                                cout << player1.name << ": " << player1.point << endl;

                                cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                                cout << player2.name << ": " << player2.point << endl;
                                goto y;
                            }
                        }

                        /*Girilen harfi tm kelime içerisinde arayıp, gizlenmiş olanda açıa çkarıyor*/
                        for (int i = 0; i < Word.length(); i++)
                        {
                            if (letter == Word[i])
                            {
                                hiddenW[i] = letter;
                                countTrue++;
                                allLetters2 = allLetters2 + letter;
                            }
                        }
                        if (countTrue == 0)
                        {
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                            cout << "Wrong letter" << endl;
                            wrongLetters2 = wrongLetters2 + letter + " ";
                            allLetters2 = allLetters2 + wrongLetters2;

                            /*Ceza ksmı (gidecek olan can)*/
                            if (livesWillTaken(letter, Word) <= 5) {
                                lives = lives - 1;
                            }
                            else if (livesWillTaken(letter, Word) > 5 && livesWillTaken(letter, Word) <= 10) {
                                lives = lives - 2;
                            }
                            else if (livesWillTaken(letter, Word) > 10 && livesWillTaken(letter, Word) <= 15) {
                                lives = lives - 3;
                            }
                            else if (livesWillTaken(letter, Word) > 15 && livesWillTaken(letter, Word) <= 20) {
                                lives = lives - 4;
                            }
                            else if (livesWillTaken(letter, Word) > 20 && livesWillTaken(letter, Word) <= 25) {
                                lives = lives - 5;
                            }
                        }
                        /*Kaybetme durumu*/
                        if (lives < 1)
                        {
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                            cout << player1.name << " Got One Point" << endl;
                            player1.point++;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                            cout << player1.name << ": " << player1.point << endl;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                            cout << player2.name << ": " << player2.point << endl;
                            Sleep(500);
                            goto finish;
                        }
                        /*Kazanma durumu*/
                        if (hiddenW == Word)
                        {
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                            cout << player2.name << " Got One Point" << endl;
                            player2.point++;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                            cout << player1.name << ": " << player1.point << endl;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                            cout << player2.name << ": " << player2.point << endl;
                            Sleep(500);
                            goto finish;
                        }
                        cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                        cout << player1.name << ": " << player1.point << endl;
                        cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                        cout << player2.name << ": " << player2.point << endl;
                    }

                } while (1);
            }
            if (turn == false)
            {
                lives = 10;
                border();
                printHangedMan(lives);

                cursorMovement(calculateStartX() + 2, calculateStartY() + 14);
                cout << "Word Writing Tour For " << player2.name << endl;

                cursorMovement(calculateStartX() + 2, calculateStartY() + 15);
                cout << "Please Type Your Word: ";
                cin >> Word;
                transform(Word.begin(), Word.end(), Word.begin(), ::toupper);

                hiddenW = Word;
                hiddenWord(&hiddenW);

                do
                {
                z:
                    border();
                    printHangedMan(lives);
                    cout << "\n";
                    int countTrue = 0;

                    cursorMovement(calculateStartX() + 2, calculateStartY() + 12);
                    cout << hiddenW << endl;

                    cursorMovement(calculateStartX() + 2, calculateStartY() + 14);
                    cout << "Wrong Letters You Have Already Tried: " << wrongLetters2 << endl;


                    cursorMovement(calculateStartX() + 2, calculateStartY() + 15);
                    cout << player1.name << " Please Enter Your Guess: ";
                    letter = _getch();

                    if (letter == 27)
                    {
                        screenClear();
                        border();
                        printHangedMan(10);
                        goto menu;
                    }
                    else
                    {
                        letter = toupper(letter); /*Girilen harfi büyük harfe eviriyor*/
                        screenClear();

                        for (int i = 0; i < allLetters2.length(); i++)
                        {
                            if (letter == allLetters2[i])
                            {

                                cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                                cout << "You Have Already Entered This Letter!" << endl;

                                cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                                cout << player1.name << ": " << player1.point << endl;

                                cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                                cout << player2.name << ": " << player2.point << endl;
                                goto z;
                            }
                        }

                        /*Girilen harfi tm kelime içerisinde arayıp, gizlenmiş olanda açıa çkarıyor*/
                        for (int i = 0; i < Word.length(); i++)
                        {
                            if (letter == Word[i])
                            {
                                hiddenW[i] = letter;
                                countTrue++;
                                allLetters2 = allLetters2 + letter;
                            }
                        }
                        if (countTrue == 0)
                        {
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                            cout << "Wrong letter" << endl;
                            wrongLetters2 = wrongLetters2 + letter + " ";
                            allLetters2 = allLetters2 + wrongLetters2;

                            /*Ceza ksmı (gidecek olan can)*/
                            if (livesWillTaken(letter, Word) <= 5) {
                                lives = lives - 1;
                            }
                            else if (livesWillTaken(letter, Word) > 5 && livesWillTaken(letter, Word) <= 10) {
                                lives = lives - 2;
                            }
                            else if (livesWillTaken(letter, Word) > 10 && livesWillTaken(letter, Word) <= 15) {
                                lives = lives - 3;
                            }
                            else if (livesWillTaken(letter, Word) > 15 && livesWillTaken(letter, Word) <= 20) {
                                lives = lives - 4;
                            }
                            else if (livesWillTaken(letter, Word) > 20 && livesWillTaken(letter, Word) <= 25) {
                                lives = lives - 5;
                            }
                        }
                        /*Kaybetme durumu*/
                        if (lives < 1)
                        {
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                            player2.point++;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                            cout << player1.name << ": " << player1.point << endl;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                            cout << player2.name << ": " << player2.point << endl;
                            Sleep(500);
                            goto finish;
                        }
                        /*Kazanma durumu*/
                        if (hiddenW == Word)
                        {
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 16);
                            cout << player1.name << " Got One Point" << endl;
                            player1.point++;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                            cout << player1.name << ": " << player1.point << endl;
                            cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                            cout << player2.name << ": " << player2.point << endl;
                            Sleep(500);
                            goto finish;
                        }
                        cursorMovement(calculateStartX() + 2, calculateStartY() + 17);
                        cout << player1.name << ": " << player1.point << endl;
                        cursorMovement(calculateStartX() + 2, calculateStartY() + 18);
                        cout << player2.name << ": " << player2.point << endl;
                    }
                } while (1);
            }

        finish:

            if (player1.point == lastPoint)
            {
                multiplayerOutro(player1.name, player2.name);
                string quit2[] = { "To Return To The Main Menu Press R","To Close The Game Press Q" };
            again3:
                cout << reset;
                cursorMovement(calculateStartX() + 43, calculateStartY() + 2);
                cout << player1.name << "WON !!!";
                for (int i = 0; i < 2; i++)
                {
                    int ColorIndex = rand() % 14 + 1;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
                    cursorMovement(calculateStartX() + 30, calculateStartY() + 13 + i);
                    cout << quit2[i];
                    Sleep(100);
                }
                char answer;
                answer = _getch();

                if ((answer == 'Q') || (answer == 'q'))
                {
                    Quit();
                    return 0;
                }
                if ((answer == 'R') || (answer == 'r'))
                {
                    goto menu;
                }
                else
                {
                    goto again3;
                }
            }
            if (player2.point == lastPoint)
            {
                multiplayerOutro(player2.name, player1.name);
                string quit2[] = { "To Return To The Main Menu Press R","To Close The Game Press Q" };
            again4:
                cout << reset;
                cursorMovement(calculateStartX() + 43, calculateStartY() + 2);
                cout << player2.name << " WON !!!";
                for (int i = 0; i < 2; i++)
                {
                    int ColorIndex = rand() % 14 + 1;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorIndex);
                    cursorMovement(calculateStartX() + 30, calculateStartY() + 13 + i);
                    cout << quit2[i];
                    Sleep(100);
                }
                char answer;
                answer = _getch();

                if ((answer == 'Q') || (answer == 'q'))
                {
                    Quit();
                    return 0;
                }
                if ((answer == 'R') || (answer == 'r'))
                {
                    goto menu;
                }
                else
                {
                    goto again4;
                }
            }

            turn = !(turn);

        } while (1);

    }
    if (Answer == 51)
    {
        rulebook();
        cursorMovement(calculateStartX() + 30, calculateStartY() + 19);
        string startSign;
        cout << "Please Type Any Button To Start Game ";
        startSign = _getch();
        screenClear();
        border();
        printHangedMan(10);
        goto menu;
    }
    if (Answer == 52)
    {
        Quit();
    }
    else {
        goto menu;
    }

    return 0;
}