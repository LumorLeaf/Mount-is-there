#include"AncientScrollPuzzle.h"
#include<iostream>
#include<random>
using namespace std;














int gerannum()
{
	std::random_device rdn;
	std::mt19937 gen(rdn());

	std::uniform_int_distribution<>dis(1, 5);

	return dis(gen);
}

int initgame()
{
	int random1[5]={'0'};
    int random2[5]={'0'};
    int random3[5]={'0'};
    int random4[5]={'0'};
    for(int i=0,i<5,i++)
    {   
        //used to row
        random1[i]=gerannum();
        random2[i]=gerannum();
    
        //used to column
        random3[i]=gerannum();
        random4[i]=gerannum();
    }

    void exchange()
    {
        for(int i=0,i<5,i++)
        {
            //used to char
            for(int j=0,j<5,j++)//row
            {
                char temp='t';
                temp=Scroll[random1][j];
                Scroll[random2][j]=Scroll[random1][j];
                Scroll[random1][j]=temp;
            }

            for(int j=0,j<5,j++)//column
            {
                char temp='t';
                temp=Scroll[j][random3];
                Scroll[j][random4]=Scroll[j][random3];
                Scroll[j][random3]=temp;
            }

             //used to int
            for(int j=0,j<5,j++)//row
            {
                int temp='t';
                temp=Scrollmirror[random1][j];
                Scrollmirror[random2][j]=Scrollmirror[random1][j];
                Scrollmirror[random1][j]=temp;
            }

            for(int j=0,j<5,j++)//column
            {
                int temp='t';
                temp=Scrollmirror[j][random3];
                Scrollmirror[j][random4]=Scrollmirror[j][random3];
                Scrollmirror[j][random3]=temp;
            }


        }
        cout<<"succeed"<<endl;
    }

}

int operation()
{
    
}