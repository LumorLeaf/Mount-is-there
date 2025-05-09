#ifndef ASP_H
#define ASP_H

#include<string>
#include<vector>

class problem
{
private:
    //std::vector<wchar_t> Scroll;
    //std::vector<int> Scrollmirror;
    int row = 0;
    int col = 0;
    std::string title = "title";
    wchar_t Scroll[100] = {L'床',L'前',L'明',L'月',L'光',L'疑',L'似',L'地',L'上',L'霜',L'举',L'头',L'望',L'明',L'月',L'低',L'头',L'思',L'故',L'乡'};
    int Scrollmirror[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

public:

    //operation
    void operow(int a, int b);
    void opecol(int a, int b);

    //print status
    void print(void);

    //inspect if right
    bool inspect();

    //generate
    void generate_problem();

    //play
    void play();

    //hint
    void hint();

    //answer
    void answer();

    //choose poem
    int choose_poem(int dijishou);
};


#endif