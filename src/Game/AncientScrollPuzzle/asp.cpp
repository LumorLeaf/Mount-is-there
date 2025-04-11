#include"asp.h"
#include<iostream>
#include<random>

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
    if (a <= 0 || a > 4 || b <= 0 || b > 4) // inspect available number
    {
        std::wcout << L"Invalid row indices" << std::endl;
        return;
    }

    for (int i = 0; i < 5; i++)//operate Scroll
    {
        wchar_t temp = Scroll[a - 1][i];
        Scroll[a - 1][i] = Scroll[b - 1][i];
        Scroll[b - 1][i] = temp;
    }

    for (int j = 0; j < 5; j++)//operate Scrollmirror
    {
        int tempp = 0;
        tempp = Scrollmirror[(a - 1) * 5 + j];
        Scrollmirror[(a - 1) * 5 + j] = Scrollmirror[(b - 1) * 5 + j];
        Scrollmirror[(b - 1) * 5 + j] = tempp;
    }
}

void problem::opecol(int a, int b)//exchange column a with col b
{
    if (a <= 0 || a > 5 || b <= 0 || b > 5) // inspect available number
    {
        std::wcout << L"Invalid column indices" << std::endl;
        return;
    }

    for (int i = 0; i < 4; i++)//operate Scroll
    {
        wchar_t temp = Scroll[i][a - 1];
        Scroll[i][a - 1] = Scroll[i][b - 1];
        Scroll[i][b - 1] = temp;
    }

    for (int j = 0; j < 4; j++)//operate Scrollmirror
    {
        int tempp = 0;
        tempp = Scrollmirror[a - 1 + j * 5];
        Scrollmirror[a - 1 + j * 5] = Scrollmirror[b - 1 + j * 5];
        Scrollmirror[b - 1 + j * 5] = tempp;
    }
}

void problem::print(void)
{
    std::wcout.imbue(std::locale(""));//for cout chinese character
    for (int i = 0; i < 4; i++)//Scroll
    {
        for (int j = 0; j < 5; j++)
        {
            std::wcout << Scroll[i][j] << L" ";
        }
        std::wcout << "\n";
    }

    for (int i = 0; i < 20; i++)//mirror
    {
        std::cout << Scrollmirror[i] << " ";
        if (i == 4 || i == 9 || i == 14 || i == 19)
        {
            std::cout << std::endl;
        }
    }
}

bool problem::inspect()
{
    int inspectnumber = 0;
    for (int i = 0; i < 20; i++)
    {
        if (Scrollmirror[i] == i + 1)
        {
            inspectnumber++;
        }
    }

    if (inspectnumber == 20)
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
    for (int i = 0; i < 4; i++)
    {
        if (finish == true)
        {
            break;
        }

        for (int j = 0; j < 20; j++)
        {
            if (finish == true)
            {
                break;
            }

            int row = 0;
            if (i * 5 + 1 == Scrollmirror[j])
            {
                row = j / 5 + 1;
                if (i + 1 != row)
                {
                    problem::operow(i + 1, row);
                    std::cout << "row:" << i + 1 << " " << row << std::endl;
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
    //col
    for (int i = 0; i < 5; i++)
    {
        if (finish == true)
        {
            break;
        }

        for (int j = 0; j < 20; j++)
        {
            if (finish == true)
            {
                break;
            }

            int col = 0;
            if (i == Scrollmirror[j] - 1)
            {
                col = j % 5 + 1;
                if (i + 1 != col) 
                {
                    problem::opecol(i + 1, col);
                    std::cout << "col:" << j + 1 << " " << col << std::endl;
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
    //row
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int row = 0;
            if (i * 5 + 1 == Scrollmirror[j])
            {
                row = j / 5 + 1;
                problem::operow(i + 1, row);
                std::cout << "row:" << i + 1 << " " << row << std::endl;
                problem::print();
            }
        }
    }

    //col
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            int col = 0;
            if (i == Scrollmirror[j] - 1)
            {
                col = j % 5 + 1;
                problem::opecol(i + 1, col);
                std::cout << "col:" << j + 1 << " " << col << std::endl;
                problem::print();
            }
        }
    }
}
