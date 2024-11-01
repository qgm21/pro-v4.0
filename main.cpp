#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <cmath>
#include <fcntl.h>

using namespace std;

// كلاس لتحكم بنافدة
class Display
{
   public:
    void ws(int i)
    {
        if (i == 0)
        {
            system("cls");
            cout << "\n\n"
                 << "\t\t\t\t   ________________________\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |    1  to Operations    |\n"
                 << "\t\t\t\t  |    2 to Comparisons    |\n"
                 << "\t\t\t\t  |       3 to about       |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |________________________|\n"
                 << "\n\n"
                 << ">>";
        }
        else if (i == 1)
        {
            system("cls");
            cout << "\n\n"
                 << "\t\t\t\t   ________________________\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |       Operations       |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |________________________|\n"
                 << "\n\n"
                 << ">>";
        }
        else if (i == 2)
        {
            system("cls");
            cout << "\n\n"
                 << "\t\t\t\t   ________________________\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |       Comparisons      |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |________________________|\n"
                 << "\n\n"
                 << ">>";
        }
        else if (i == 3)
        {
            system("cls");
            cout << "\n\n"
                 << "\t\t\t\t   ________________________\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |         about          |\n"
                 << "\t\t\t\t  |                        |\n"
                 << "\t\t\t\t  |________________________|\n"
                 << "\n\n"
                 << "\t\t\t\t";
        }
    }
    void scz(int width, int height)
    {
        HWND console = GetConsoleWindow();
        RECT rect;
        GetWindowRect(console, &rect);
        MoveWindow(console, rect.left, rect.top, width, height, TRUE);
    }
    void dmb()
    {
        HWND console = GetConsoleWindow();
        LONG style = GetWindowLong(console, GWL_STYLE);
        style &= ~WS_MAXIMIZEBOX;
        SetWindowLong(console, GWL_STYLE, style);
    }
    void dr()
    {
        HWND console = GetConsoleWindow();
        LONG style = GetWindowLong(console, GWL_STYLE);
        style &= ~WS_SIZEBOX;
        SetWindowLong(console, GWL_STYLE, style);
    }
};

// كلاس الاساسي للمهام خاصة برنامج
class Tasks
{
private:
public:
};

int main()
{
    int a;
    Display dio;
    dio.ws(0);
    dio.scz(800,600);
    dio.dmb();
    dio.dr();
    cin>>a;
    switch (a)
    {
    case 1:
        dio.ws(a);
        sleep(3);
        break;
    case 2:
        dio.ws(a);
        sleep(3);
        break;
    case 3:
        dio.ws(a);
        sleep(3);
        break;
    
    default:
        break;
    }
    getchar();
}