#include <conio.h>
#include <iostream>
#include <unistd.h>
#include <windows.h>
#include <cmath>
#include "UI.cpp"
#include "CE_fi.cpp"


using namespace std;

// كلاس لتحكم بنافدة
class Display
{
public:
    // دالة خاصة باعطاء شكل النافدة
    void ws(int i)
    {
        if (i == 0) 
        {
            mainUI();
        }
        else if(i==1)
        {
            ce_fiUI();
        }
        else if (i == 2)
        {
            OperationsUI();
        }
        else if (i == 3)
        {
            ComparisonsUI();
        }
        else if (i == 4)
        {
            aboutUI();
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
        if (a == 2)
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
        else if (a == 3)
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
        int a;
        cout << "This is the PRO program in its quarterly version."
             << endl
             << "The purpose of the project is educational purpose only and not commercial."
             << endl
             << "            Developer: qgm     Date: October 30, 2024"
             << endl;
    }
};






int main()
{
    int a;
    Display dio;
    Tasks to;
    dio.scz(800, 600);
    dio.dmb();
    dio.dr();
    char key;

    while (true)
    {
        dio.ws(0);
        cin >> a;
        switch (a)
        {
        case 1:
            cout<<"1 to ceat project , 2 to ceat file"<<endl;
            int chose;
            cin>>chose;
            if(chose == 1)
            {
                dio.ws(1);
                ceat_proj();
            }
            else if(chose == 2)
            {
                dio.ws(1);
                ceat_file();
            }
            break;
        case 2:
            dio.ws(a);
            to.cin_(a);
            to.Operations();
            cout << "prass Esc to quit" << endl;
            key = getch();
            while (true) { // حلقة انتظار حتى يتم الضغط على Esc
                char key = getch(); // قراءة المفتاح
                if (key == 27) {    // تحقق إذا كان المفتاح هو Esc
                    break;          // الخروج من الحالة
                }
            }
            break;
        case 3:
            dio.ws(a);
            to.cin_(a);
            to.Comparisons();
            cout << "prass Esc to quit" << endl;
            key = getch();
            while (true) { // حلقة انتظار حتى يتم الضغط على Esc
                char key = getch(); // قراءة المفتاح
                if (key == 27) {    // تحقق إذا كان المفتاح هو Esc
                    break;          // الخروج من الحالة
                }
            }
            break;
        case 4:
            dio.ws(a);
            to.about();
            cout << "\n\n\tprass Esc to quit" << endl;
            key = getch();
            while (true) { // حلقة انتظار حتى يتم الضغط على Esc
                char key = getch(); // قراءة المفتاح
                if (key == 27) {    // تحقق إذا كان المفتاح هو Esc
                    break;          // الخروج من الحالة
                }
            }
            break;
        case 5:
            return 0;
            break;
        default:
            cerr << "error a < " << a << "\a" << endl;
            sleep(0.8);
            system("cls");
            break;
        }
    }
    getchar();
}