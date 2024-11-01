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
                 << "\t\t\t\t  |         4 exit         |\n"
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
    char op;
    double x;
    double y;
    double z;

public:
    void cin_(int a)
    {
        if (a == 1)
        {
            cout << "enter Operations :" << endl;
            cin >> x >> op;
            if (op == 's' || op == 'S' || op == 'c' || op == 't')
                ;
            else
            {
                cin >> y;
            }
        }
        else if (a == 2)
        {
            cout << "Enter first number : ";
            cin >> x;
            cout << "Enter second number : ";
            cin >> y;
        }
    }
    void Operations()
    {
        switch (op)
        {
        case '+':
            cout << x + y << endl;
            break;
        case '-':
            cout << x - y << endl;
            break;
        case '*':
            cout << x * y << endl;
            break;
        case '/':
            cout << x / y << " The remainder of the division is " << fmod(x, y) << endl;
            break;
        case 'p':
            cout << pow(x, y) << endl;
            break;
        case 's':
            cout << sqrt(x) << endl;
            break;
        case 'S':
            cout << sin(x) << endl;
            break;
        case 'c':
            cout << cos(x) << endl;
            break;
        case 't':
            cout << tan(x) << endl;
            break;

        default:
            cerr << "error op != 's' || op !='S'||op != 'c'|| op!='t'|| op != '+'|| op != '-'|| op != '*'|| op != '/' " << endl;
            break;
        }
    }
    void Comparisons()
    {
        if (x > y || y > x)
        {
            cout << "The big number is " << max(x, y) << " , The small number is " << min(x, y) << endl;
        }
        else
        {
            cout << "Two equal numbers " << x << " = " << y << endl;
        }
    }
    void about()
    {
    }
};

int main()
{
    int a;
    Display dio;
    Tasks to;
    dio.ws(0);
    dio.scz(800, 600);
    dio.dmb();
    dio.dr();
    cin >> a;
    switch (a)
    {
    case 1:
        dio.ws(a);
        to.cin_(a);
        to.Operations();
        break;
    case 2:
        dio.ws(a);
        to.cin_(a);
        to.Comparisons();
        break;
    case 3:
        dio.ws(a);
        to.about();
        break;
    case 4:
        
        break;
    default:
        cerr<<"error a < "<<a<<"\a"<<endl;
        sleep(0.8);
        system("cls");
        break;
    }
    getchar();
}