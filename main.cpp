// تضمين المكتبات اللازمة
#include <conio.h>   // للتعامل مع إدخال/إخراج الكونسول
#include <iostream>  // للإدخال والإخراج القياسي
#include <unistd.h>  // لوظائف النظام مثل sleep()
#include <windows.h> // للتعامل مع واجهة ويندوز
#include <cmath>     // للدوال الرياضية
#include "UI.cpp"    // واجهات المستخدم
#include "CE_fi.cpp" // وظائف إنشاء الملفات والمشاريع

using namespace std;

// كلاس للتحكم في إعدادات نافذة الكونسول
class Display
{
public:
    // دالة لتحديد واجهة المستخدم حسب القيمة المدخلة
    void ws(int i)
    {
        if (i == 0)
        {
            mainUI(); // الواجهة الرئيسية
        }
        else if (i == 1)
        {
            ce_fiUI(); // واجهة إنشاء الملف/المشروع
        }
        else if (i == 2)
        {
            OperationsUI(); // واجهة العمليات الحسابية
        }
        else if (i == 3)
        {
            ComparisonsUI(); // واجهة المقارنات
        }
        else if (i == 4)
        {
            aboutUI(); // واجهة حول البرنامج
        }
    }

    // ضبط أبعاد نافذة الكونسول
    void scz(int width, int height)
    {
        HWND console = GetConsoleWindow();
        RECT rect;
        GetWindowRect(console, &rect);
        MoveWindow(console, rect.left, rect.top, width, height, TRUE);
    }

    // تعطيل زر التكبير
    void dmb()
    {
        HWND console = GetConsoleWindow();
        LONG style = GetWindowLong(console, GWL_STYLE);
        style &= ~WS_MAXIMIZEBOX;
        SetWindowLong(console, GWL_STYLE, style);
    }

    // تعطيل تغيير الحجم
    void dr()
    {
        HWND console = GetConsoleWindow();
        LONG style = GetWindowLong(console, GWL_STYLE);
        style &= ~WS_SIZEBOX;
        SetWindowLong(console, GWL_STYLE, style);
    }
};

// كلاس رئيسي للوظائف الأساسية للبرنامج
class Tasks
{
private:
    char op;  // عملية حسابية
    double x; // رقم أول
    double y; // رقم ثاني
    double z; // رقم ثالث (غير مستخدم حاليا)

public:
    // دالة إدخال البيانات حسب نوع العملية
    void cin_(int a)
    {
        if (a == 2) // حالة العمليات الحسابية
        {
            cout << "enter Operations :" << endl;
            cin >> x >> op;
            // إذا كانت العملية من الدوال المثلثية لا تحتاج لرقم ثاني
            if (op == 's' || op == 'S' || op == 'c' || op == 't')
                ;
            else
            {
                cin >> y;
            }
        }
        else if (a == 3) // حالة المقارنات
        {
            cout << "Enter first number : ";
            cin >> x;
            cout << "Enter second number : ";
            cin >> y;
        }
    }

    // تنفيذ العمليات الحسابية
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

    // مقارنة بين رقمين
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

    // معلومات عن البرنامج
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

// الدالة الرئيسية
int main()
{
    int a;
    Display dio;       // كائن للتحكم في العرض
    Tasks to;          // كائن للمهام
    dio.scz(800, 600); // ضبط أبعاد النافذة
    dio.dmb();         // تعطيل التكبير
    dio.dr();          // تعطيل تغيير الحجم
    char key;

    while (true)
    {
        dio.ws(0); // عرض الواجهة الرئيسية
        cin >> a;
        switch (a)
        {
        case 1: // إنشاء مشروع أو ملف
            cout << "1 to ceat project , 2 to ceat file" << endl;
            int chose;
            cin >> chose;
            if (chose == 1)
            {
                dio.ws(1);
                ceat_proj(); // استدعاء دالة إنشاء المشروع
            }
            else if (chose == 2)
            {
                dio.ws(1);
                ceat_file(); // استدعاء دالة إنشاء الملف
            }
            break;
        case 2: // العمليات الحسابية
            dio.ws(a);
            to.cin_(a);
            to.Operations();
            cout << "prass Esc to quit" << endl;
            key = getch();
            while (true)
            {
                char key = getch();
                if (key == 27)
                    break; // الخروج عند الضغط على Esc
            }
            break;
        case 3: // المقارنات
            dio.ws(a);
            to.cin_(a);
            to.Comparisons();
            cout << "prass Esc to quit" << endl;
            key = getch();
            while (true)
            {
                char key = getch();
                if (key == 27)
                    break;
            }
            break;
        case 4: // معلومات البرنامج
            dio.ws(a);
            to.about();
            cout << "\n\n\tprass Esc to quit" << endl;
            key = getch();
            while (true)
            {
                char key = getch();
                if (key == 27)
                    break;
            }
            break;
        case 5: // إنهاء البرنامج
            return 0;
            break;
        default: // حالة الإدخال الخاطئ
            cerr << "error a < " << a << "\a" << endl;
            sleep(0.8);
            system("cls");
            break;
        }
    }
    getchar();
}