#include <iostream>
#include <chrono>
#include <cmath>

#if _WIN32

#include <windows.h>

#endif


using namespace std;


class Screen
{
public:
    Screen()
    {
#ifdef _WIN32
        _hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
        hideCursor();
        saveCursorPosition();
    }


    void clear()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                _screen[i][j] = 'x';
            }
        }
    }


    void draw(char value, float x, float y)
    {
        int xPos = lround(x);
        int yPos = lround(y);
        if (xPos < width && yPos < height)
        {
            _screen[yPos][xPos] = value;
        }
    }


    void flush()
    {
        restoreCursorPosition();


        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (_screen[i][j] != 'x')
                {
                    setRedFont();
                }
                else
                {
                    setWhiteFont();
                }
                cout << _screen[i][j];
            }
            cout << "\n";
        }
    }


private:
    void hideCursor()
    {
#ifdef _WIN32
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(_hConsole, &cursorInfo);
        cursorInfo.dwSize = 1;
        cursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo(_hConsole, &cursorInfo);
#else
        cout << "\33[?25l";//disable cursor
#endif


    }


    void saveCursorPosition()
    {
#ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO coninfo;
        GetConsoleScreenBufferInfo(_hConsole, &coninfo);
        _prevPos = coninfo.dwCursorPosition;
#else
        cout << "\33[s";
#endif

    }


    void restoreCursorPosition()
    {
#ifdef _WIN32
        SetConsoleCursorPosition(_hConsole, _prevPos);
#else
        cout << "\338";
#endif
    }


    void setRedFont()
    {
#ifdef _WIN32
        WORD attributes = FOREGROUND_RED;
        SetConsoleTextAttribute(_hConsole, attributes);
#else
        cout << "\33[31m";//red color
#endif
    }


    void setWhiteFont()
    {
#ifdef _WIN32
        WORD attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
        SetConsoleTextAttribute(_hConsole, attributes);
#else
        cout << "\33[37m";//white color
#endif
    }


    static constexpr int width{60};
    static constexpr int height{20};
    char _screen[height][width];
#ifdef _WIN32
    HANDLE _hConsole;
    COORD _prevPos;
#endif
};


struct Position
{
    float x;
    float y;
};


using Pixel = char;


class Engine
{
public:
    void update(chrono::milliseconds deltaTime)
    {
        if (numberOfTransitionFromAtoB < 40u)
        {
            numberOfTransitionFromAtoB += 1u;
            position.x += 1.f;
        }
        else if (numberOfTransitionFromBtoC < 60u)
        {
            numberOfTransitionFromBtoC += 1u;
            delayOfTransitionFromBtoC++;
            if (delayOfTransitionFromBtoC % 6 == 0)
            {
                position.y += 1.f;
            }
        }
        else if (numberOfTransitionFromCtoA < 20u)
        {
            numberOfTransitionFromCtoA += 1u;
            delayOfTransitionFromCtoA++;
            if (delayOfTransitionFromCtoA % 2 == 0)
            {
                position.y -= 1.f;
            }
            else
            {
                position.x -= 4.f;
            }
        }
        else
        {
            counterOfCompletedTransitions++;
            if (counterOfCompletedTransitions < 5)
            {
                numberOfTransitionFromAtoB = 0;
                numberOfTransitionFromBtoC = 0;
                numberOfTransitionFromCtoA = 0;
            }
            else
            {
                std::cout << "The algorithm was run 5 times " << std::endl;
            }
        }

        std::cout << "x: " << position.x << " y: " << position.y << "  time A to B: " << numberOfTransitionFromAtoB
                  << " "
                  << static_cast<unsigned >(counterOfCompletedTransitions) << std::endl;
    }


    void render(Screen &screen)
    {
        screen.draw(pixel, position.x, position.y);
    }

    uint8_t getCounterOfCompletedTransitions() const
    {
        return counterOfCompletedTransitions;
    }

private:
    Pixel pixel{1};
    Position position{0.0f, 0.0f};

    uint32_t numberOfTransitionFromAtoB{0u};
    uint32_t numberOfTransitionFromBtoC{0u};
    uint32_t numberOfTransitionFromCtoA{0u};
    uint8_t delayOfTransitionFromBtoC{0};
    uint8_t delayOfTransitionFromCtoA{0};
    uint8_t counterOfCompletedTransitions{0};
};


int main()
{
    Engine engine;
    Screen screen;


    auto startTime = chrono::high_resolution_clock::now();
    while (engine.getCounterOfCompletedTransitions() < 5)
    {
        auto now = chrono::high_resolution_clock::now();
        auto deltaTime = chrono::duration_cast<chrono::milliseconds>(now - startTime);
        if (deltaTime >= 50ms)
        {
            screen.clear();
            engine.update(deltaTime);
            engine.render(screen);
            screen.flush();
            startTime = now;
        }
    }


    return 0;
}