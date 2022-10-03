#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdbool.h>
#include <thread>

#define screen_x 80
#define screen_y 25

HANDLE wHnd;
HANDLE rHnd;
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
CHAR_INFO consoleBuffer[screen_x * screen_y];

void gotoxy(int,int);
void draw_ship(int x,int y);
void draw_bullet(int x, int y);
void erase_ship (int x, int y);
void erase_bullet (int x, int y);
void setcursor(bool visible);
void setcolor(int fg,int bg);
char cursor(int x, int y);
void gen_star(int);
void scoreboard(int);
int random(int lower, int upper);
int setConsole(int x, int y);
int setMode();
void change_color();

int main()
{
    char ch='.';
    char direction = '.';
    char shoot = '.';
    bool play = true;
    int x=38,y=20;
    int count = -1;
    int check = 0;
    int score = 0;
    int x_bullet[10] = {-1,-1,-1,-1,-1,-1}, y_bullet[10] = {-1,-1,-1,-1,-1,-1};
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;

    setConsole(screen_x, screen_y);
    setcursor(0);
    setMode();
    srand( time( NULL ) );
    gen_star(20);
    draw_ship(x,y);
    do
    {
        scoreboard(score);
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0)
        {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i)
            {
                if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true )
                {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
                    {
                        play = false;
                    }
                    else if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == 'c')
                    {
                        change_color();
                    }
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT)
                {
                    int posx2 = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    int posy2 = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    int posx1 = x;
                    int posy1 = y;

                    if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        consoleBuffer[posy2 * screen_x + posx2].Attributes = random(0, 255);
                    }
                    if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED)
                    {
                        draw_ship(posx2, posy2);
                        erase_ship(posx1, posy1);
                        posx1 = posx2;
                        posy1 = posy2;
                    }
                }
            }
            delete[] eventBuffer;
            if (kbhit())
            {
                ch=getch();
                if(ch=='a')
                {
                    direction = 'L'; //Left
                }
                if(ch=='d')
                {
                    direction = 'R'; //Right
                }
                if(ch=='s')
                {
                    direction = 'P'; //Pause
                }
                if (ch == 'c')
                {
                    change_color();
                }
                if((ch==' ') && (check < 5))
                {
                    check++;
                    if (x_bullet[0] == -1)
                    {
                        count = 0;
                    }
                    else if (x_bullet[1] == -1)
                    {
                        count = 1;
                    }
                    else if (x_bullet[2] == -1)
                    {
                        count = 2;
                    }
                    else if (x_bullet[3] == -1)
                    {
                        count = 3;
                    }
                    else if (x_bullet[4] == -1)
                    {
                        count = 4;
                    }
                    x_bullet[count] = x + 3;
                    y_bullet[count] = y - 1;
                    shoot = 'S'; //Shoot
                }
                fflush(stdin);
            }
            if (direction != '.')
            {
                if (direction == 'L')
                {
                    draw_ship(--x,y);
                    erase_ship(x + 8, y);
                    if (x <= 0)
                    {
                        x++;
                    }
                }
                if (direction == 'R')
                {
                    draw_ship(++x,y);
                    erase_ship(x - 2, y);
                    if (x >= 80)
                    {
                        x--;
                    }
                }
                if (direction == 'P')
                {
                    direction = ' ';
                }
                if (shoot == 'S')
                {
                    if (x_bullet[0] != -1)
                    {
                        draw_bullet(x_bullet[0], --y_bullet[0]);
                        erase_bullet(x_bullet[0], y_bullet[0] + 1);
                        if (y_bullet[0] == 0)
                        {
                            --check;
                            erase_bullet(x_bullet[0], 0);
                            x_bullet[0] = -1;
                        }
                        if (cursor(x_bullet[0],y_bullet[0]-1) == '*')
                        {
                            --check;
                            erase_bullet(x_bullet[0], y_bullet[0]-1);
                            erase_bullet(x_bullet[0], y_bullet[0]);
                            score+=100;
                            gen_star(1);
                            x_bullet[0] = -1;
                            std::thread q(Beep, 700, 500);
                            q.detach();
                        }
                    }
                    if (x_bullet[1] != -1)
                    {
                        draw_bullet(x_bullet[1], --y_bullet[1]);
                        erase_bullet(x_bullet[1], y_bullet[1] + 1);
                        if (y_bullet[1] == 0)
                        {
                            --check;
                            erase_bullet(x_bullet[1], 0);
                            x_bullet[1] = -1;
                        }
                        if (cursor(x_bullet[1],y_bullet[1]-1) == '*')
                        {
                            --check;
                            erase_bullet(x_bullet[1], y_bullet[1]-1);
                            erase_bullet(x_bullet[1], y_bullet[1]);
                            score+=100;
                            gen_star(1);
                            x_bullet[1] = -1;
                            std::thread q(Beep, 700, 500);
                            q.detach();
                        }
                    }
                    if (x_bullet[2] != -1)
                    {
                        draw_bullet(x_bullet[2], --y_bullet[2]);
                        erase_bullet(x_bullet[2], y_bullet[2] + 1);
                        if (y_bullet[2] == 0)
                        {
                            --check;
                            erase_bullet(x_bullet[2], 0);
                            x_bullet[2] = -1;
                        }
                        if (cursor(x_bullet[2],y_bullet[2]-1) == '*')
                        {
                            --check;
                            erase_bullet(x_bullet[2], y_bullet[2]-1);
                            erase_bullet(x_bullet[2], y_bullet[2]);
                            score+=100;
                            gen_star(1);
                            x_bullet[2] = -1;
                            std::thread q(Beep, 700, 500);
                            q.detach();
                        }
                    }
                    if (x_bullet[3] != -1)
                    {
                        draw_bullet(x_bullet[3], --y_bullet[3]);
                        erase_bullet(x_bullet[3], y_bullet[3] + 1);
                        if (y_bullet[3] == 0)
                        {
                            --check;
                            erase_bullet(x_bullet[3], 0);
                            x_bullet[3] = -1;
                        }
                        if (cursor(x_bullet[3],y_bullet[0]-1) == '*')
                        {
                            --check;
                            erase_bullet(x_bullet[3], y_bullet[3]-1);
                            erase_bullet(x_bullet[3], y_bullet[3]);
                            score+=100;
                            gen_star(1);
                            x_bullet[3] = -1;
                            std::thread q(Beep, 700, 500);
                            q.detach();
                        }
                    }
                    if (x_bullet[4] != -1)
                    {
                        draw_bullet(x_bullet[4], --y_bullet[4]);
                        erase_bullet(x_bullet[4], y_bullet[4] + 1);
                        if (y_bullet[4] == 0)
                        {
                            --check;
                            erase_bullet(x_bullet[4], 0);
                            x_bullet[4] = -1;
                        }
                        if (cursor(x_bullet[4],y_bullet[4]-1) == '*')
                        {
                            --check;
                            erase_bullet(x_bullet[4], y_bullet[4]-1);
                            erase_bullet(x_bullet[4], y_bullet[4]);
                            score+=100;
                            gen_star(1);
                            x_bullet[4] = -1;
                            std::thread q(Beep, 700, 500);
                            q.detach();
                        }
                    }
                }
            }
            Sleep(100);
        }
    }
    while (ch!='x' || play == true);
    return 0;
}
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x,int y)
{
    gotoxy(x,y);
    setcolor(2, 4);
    printf(" <-0-> ");
}
void draw_bullet(int x, int y)
{
    gotoxy(x, y);
    setcolor(5, 12);
    printf("|");
}
void erase_ship (int x, int y)
{
    setcolor(0, 0);
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf("       ");
}
void erase_bullet (int x, int y)
{
    setcolor(0, 0);
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    printf(" ");
}
void setcursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console,&lpCursor);
}
void setcolor(int fg,int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg*16+fg);
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x,y};
    DWORD num_read;
    if(!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}
void gen_star(int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = random(10, 70);
        int y = random(2, 5);
        setcolor(6, 0);
        gotoxy(x, y);
        printf("*");
    }
}
int random(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}
void scoreboard(int score)
{
    setcolor(11, 5);
    gotoxy(74, 0);
    printf("%06d", score);
}
int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}
int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
              ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}
void change_color()
{
    setcolor(random(0, 255), (0, 255));
}
