#include"asp.h"
#include<iostream>

void problem::operow(int a,int b)//exchange row a with row b
{
    if (a < 0 || a >= 4 || b < 0 || b >= 4) // inspect available number
    {
        std::wcout << L"Invalid row indices" << std::endl;
        return;
    }

    for (int i = 0; i < 5; i++)//operate Scroll
    {
        wchar_t temp=temp=Scroll[a][i];
        Scroll[a][i]=Scroll[b][i];
        Scroll[b][i]=temp;
    }

    for (int j = 0;  j< 5; j++)//operate Scrollmirror
    {
        int tempp = 0;
        tempp = Scrollmirror[a*5+j];
        Scrollmirror[a * 5 + j] = Scrollmirror[b * 5 + j];
        Scrollmirror[b * 5 + j] = tempp;
    }
}

void problem::opecol(int a,int b)//exchange column a with col b
{
    if (a < 0 || a >= 5 || b < 0 || b >= 5) // inspect available number
    {
        std::wcout << L"Invalid column indices" << std::endl;
        return;
    }

    for (int i = 0; i < 5; i++)//operate Scroll
    {
        wchar_t temp=Scroll[i][a];
        Scroll[i][a]=Scroll[i][b];
        Scroll[i][b]=temp;
    }

    for (int j = 0; j < 5; j++)//operate Scrollmirror
    {
        int tempp = 0;
        tempp = Scrollmirror[a + j * 5];
        Scrollmirror[a + j * 5] = Scrollmirror[b + j * 5];
        Scrollmirror[b + j * 5] = tempp;
    }
}

void problem::print(void)
{
    std::wcout.imbue(std::locale(""));//for cout chinese character
    for(int i=0;i<4;i++)//Scroll
    {
        for(int j=0;j<5;j++)
        {
            std::wcout<<Scroll[i][j]<<L" ";
        }
        std::wcout<<"\n";
    }

    for (int i = 0; i < 20; i++)//mirror
    {
        std::cout << Scrollmirror[i] << " ";
        if (i == 4||i==9||i==14||i==19)
        {
            std::cout << std::endl;
        }
    }
}

bool problem::inspect()
{
    int inspectnumber=0;
    for(int i=0;i<20;i++)
    {
        if(Scrollmirror[i]==i+1)
        {
            inspectnumber++;
        }
    }

    if (inspectnumber == 20)
    {
        return true;
    }
    else
    {
        return false;
    }

    
}
