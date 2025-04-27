#include"asp.h"
#include<iostream>

#include<random>//创建随机数

#include<vector>
#include <fstream>
#include <string>
#include <vector>
#include <locale>
#include <windows.h>//实现选择诗歌

using namespace std;

int random_circle_number()
{
    std::random_device ran0;
    std::mt19937 gen(ran0());
    std::uniform_real_distribution<>dis(100, 200);
    return dis(gen);
}
int random_row_or_col()
{
    std::random_device ran1;
    std::mt19937 gen(ran1());
    std::uniform_real_distribution<>dis(12, 19);
    return dis(gen);
}
int random_rowa()
{
    std::random_device ran2;
    std::mt19937 gen(ran2());
    std::uniform_real_distribution<>dis(1, 4);
    return dis(gen);
}
int random_rowb()
{
    std::random_device ran3;
    std::mt19937 gen(ran3());
    std::uniform_real_distribution<>dis(1, 4);
    return dis(gen);
}
int random_cola()
{
    std::random_device ran4;
    std::mt19937 gen(ran4());
    std::uniform_real_distribution<>dis(1, 5);
    return dis(gen);
}
int random_colb()
{
    std::random_device ran5;
    std::mt19937 gen(ran5());
    std::uniform_real_distribution<>dis(1, 5);
    return dis(gen);
}

void problem::operow(int a, int b)//exchange row a with row b
{
    if (a <= 0 || a > row || b <= 0 || b > row) // inspect available number
    {
        std::wcout << L"Invalid row indices" << std::endl;
        return;
    }

    //for (int i = 0; i < 5; i++)//operate Scroll
    //{
    //    wchar_t temp = Scroll[a - 1][i];
    //    Scroll[a - 1][i] = Scroll[b - 1][i];
    //    Scroll[b - 1][i] = temp;
    //}
    for (int j = 0; j < (row + 1); j++)//operate Scroll
    {
        wchar_t tempp = 0;
        tempp = Scroll[(a - 1) * (row+1) + j];
        Scroll[(a - 1) * (row+1) + j] = Scroll[(b - 1) * (row + 1) + j];
        Scroll[(b - 1) * (row + 1) + j] = tempp;
    }

    for (int j = 0; j < (row + 1); j++)//operate Scrollmirror
    {
        int tempp = 0;
        tempp = Scrollmirror[(a - 1) * (row + 1) + j];
        Scrollmirror[(a - 1) * (row + 1) + j] = Scrollmirror[(b - 1) * (row + 1) + j];
        Scrollmirror[(b - 1) * (row + 1) + j] = tempp;
    }
}

void problem::opecol(int a, int b)//exchange column a with col b
{
    if (a <= 0 || a > col || b <= 0 || col > 5) // inspect available number
    {
        std::wcout << L"Invalid column indices" << std::endl;
        return;
    }

    //for (int i = 0; i < 4; i++)//operate Scroll
    //{
    //    wchar_t temp = Scroll[i][a - 1];
    //    Scroll[i][a - 1] = Scroll[i][b - 1];
    //    Scroll[i][b - 1] = temp;
    //}
    for (int j = 0; j < col; j++)//operate Scroll
    {
        wchar_t tempp = 0;
        tempp = Scroll[(a - 1) * col + j];
        Scroll[(a - 1) * col + j] = Scroll[(b - 1) * col + j];
        Scroll[(b - 1) * col + j] = tempp;
    }

    for (int j = 0; j < col; j++)//operate Scrollmirror
    {
        int tempp = 0;
        tempp = Scrollmirror[(a - 1) * col + j];
        Scrollmirror[(a - 1) * col + j] = Scrollmirror[(b - 1) * col + j];
        Scrollmirror[(b - 1) * col + j] = tempp;
    }
}

void problem::print(void)
{
    std::wcout.imbue(std::locale(""));//for cout chinese character
    //for (int i = 0; i < 4; i++)//Scrolllast
    //{
    //    for (int j = 0; j < 5; j++)
    //    {
    //        std::wcout << Scroll[i] << L" ";
    //    }
    //    std::wcout << "\n";
    //}

    for (int i = 0; i < row*col; i++)//Scroll
    {
        std::wcout << Scroll[i] << L" ";
        for (int j = 0; j < row; j++)
        {
            if (i == j*col-1)
            {
                std::cout << std::endl;
            }
        }
    }

    std::cout << std::endl;

    for (int i = 0; i < row*col; i++)//mirror
    {
        std::cout << Scrollmirror[i] << " ";
        for (int j = 0; j < row; j++)
        {
            if (i==j*col-1)
            {
                std::wcout << std::endl;
            }
        }
    }

}

bool problem::inspect()
{
    int inspectnumber = 0;
    for (int i = 0; i < row*col; i++)
    {
        if (Scrollmirror[i] == i + 1)
        {
            inspectnumber++;
        }
    }

    if (inspectnumber == row*col)
    {
        std::cout << "You win!!!!!!!" << std::endl;
        return true;
    }
    else
    {
        return false;
    }


}

void problem::generate_problem()
{

    for (int i = 0; i < random_circle_number(); i++)
    {
        int ran = random_row_or_col();
        if (ran % 2 == 1)//row
        {
            problem::operow(random_rowa(), random_rowb());
        }
        else//col
        {
            problem::opecol(random_cola(), random_colb());
        }
    }
}

void problem::play()
{
    choose_poem(1);

    generate_problem();
    print();

    while (!inspect())
    {
        std::cout << "what do u wan to do? row or col?" << std::endl;
        std::string choose = "choose";
        std::cin >> choose;

        if (choose == "row")
        {
            std::cout << "which twoo row do you want to exchange?" << std::endl;
            int a, b = 0;
            std::cin >> a >> b;
            operow(a, b);
            print();

        }
        else if (choose == "col")
        {
            std::cout << "which twoo col do you want to exchange?" << std::endl;
            int a, b = 0;
            std::cin >> a >> b;
            opecol(a, b);
            print();
        }
        else if (choose == "hint")
        {
            problem::hint();
        }
        else if (choose == "answer")
        {
            problem::answer();
        }
        else
        {
            std::cout << "please enter available words!" << std::endl;
            print();
        }

    }
}

void problem::hint()
{
    bool finish = false;
    for (int i = 0; i < row; i++)
    {
        if (finish == true)
        {
            break;
        }

        for (int j = 0; j < row; j++)
        {
            if (finish == true)
            {
                break;
            }

            int row2 = 0;
            if (i * (row+1) + 1 == Scrollmirror[j])
            {
                row2 = j / (row+1) + 1;
                if (i + 1 != row2)
                {
                    problem::operow(i + 1, row2);
                    std::cout << "row:" << i + 1 << " " << row2 << std::endl;
                    problem::print();
                    finish = true;
                }
                else
                {
                    continue;
                }
            }
        }

    }
    //col2
    for (int i = 0; i < col; i++)
    {
        if (finish == true)
        {
            break;
        }

        for (int j = 0; j < row*col; j++)
        {
            if (finish == true)
            {
                break;
            }

            int col2 = 0;
            if (i == Scrollmirror[j] - 1)
            {
                col2 = j % col + 1;
                if (i + 1 != col2)
                {
                    problem::opecol(i + 1, col2);
                    std::cout << "col:" << j + 1 << " " << col2 << std::endl;
                    problem::print();
                    finish = true;
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

void problem::answer()
{
    //row1
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int row1 = 0;
            if (i * 5 + 1 == Scrollmirror[j])
            {
                row1 = j / 5 + 1;
                problem::operow(i + 1, row1);
                std::cout << "row:" << i + 1 << " " << row1 << std::endl;
                problem::print();
            }
        }
    }

    //col1
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int col1 = 0;
            if (i == Scrollmirror[j] - 1)
            {
                col1 = j % 5 + 1;
                problem::opecol(i + 1, col1);
                std::cout << "col:" << j + 1 << " " << col1 << std::endl;
                problem::print();
            }
        }
    }
}

int problem::choose_poem(int dijishou)
{
    // 设置宽字符支持
    try {
        std::locale::global(std::locale("")); // 使用系统的默认locale
    }
    catch (const exception& e) {
        wcerr << L"设置locale失败: " << e.what() << endl;
        return 1;
    }

    //使用宽字符打开文件
    wstring filename = L"poem.txt";
    wifstream file(filename);
    if (!file.is_open()) {
        wcerr << L"无法打开文件: " << filename << endl;
        return 1;
    }

    //读取方法量
    wstring line;
    //int dijishou = 1; //第几首，从1开始
    int counter = 0;
    bool read_poem = false;

    //读取的结果量
    wstring title;
    int num1 = 0, num2 = 0;
    vector<wchar_t> content;

    //读取过程
    while (getline(file, line))
    {
        if (line == L"-----")
        {
            counter++;
            if (counter == dijishou)
            {
                read_poem = true; // 进入目标诗的读取模式
            }
            else if (counter > dijishou)
            {
                read_poem = false; // 超过目标诗，退出模式
                break;
            }
        }
        else if (read_poem)
        {
            if (title.empty())
            { // 第一行是标题
                title = line;
            }
            else if (num1 == 0 && num2 == 0)
            { // 第二行是数字
                // 解析数字行
                size_t space_pos = line.find(L' ');
                num1 = stoi(line.substr(0, space_pos));
                num2 = stoi(line.substr(space_pos + 1));
            }
            else
            { // 其余行是诗句内容
                for (wchar_t ch : line)
                {
                    content.push_back(ch); // 将每个宽字符存入数组
                    wchar_t n = L'\n';
                    if (ch !=n )
                    {
                        content.push_back(ch);
                    }
                }
            }
        }

        row = num1;
        col = num2;
        //for (int i = 1; i < num1 * num2; i++)
        //{
        //    Scrollmirror.push_back(i);
        //}

    }

    file.close();
    return 0;
}
