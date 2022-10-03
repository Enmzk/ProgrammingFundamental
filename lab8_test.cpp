#include <windows.h>
#include <time.h>

#define screen_x 100
#define screen_y 100

HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x-1,screen_y-1 };
int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}
int random(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}
void fill_data_to_buffer()
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[x + screen_x * y].Char.AsciiChar =char(random(65, 90));
            consoleBuffer[x + screen_x * y].Attributes = random(0, 255);
        }
    }
}
void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,
                        &windowSize);
}

int main()
{
    srand( time( NULL ) );
    setConsole(screen_x, screen_y);
    fill_data_to_buffer();
    fill_buffer_to_console();
    Sleep(5000);
    return 0;
}
