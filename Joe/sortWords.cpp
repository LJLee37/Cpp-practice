#include <iostream>
#include <string>
#include <vector>
using namespace std;
int wordAmount = 0;
vector<string> sort(vector<string> wordList)
{
    int newIndex[wordAmount];
    bool sorted = false;
    int currentSorted = -1;
    vector<string> retval;
    while(!sorted)
    {
        char temp1 = 'z';
        int temptarget = wordList.size();
        for (int i = 0; i < wordList.size(); i++)
            if(temp1 > wordList[i][0])
            {
                temp1 = wordList[i][0];
                temptarget = i;
            }
            else if(temp1 == wordList[i][0])
            {
                if (temptarget == wordList.size())
                    temptarget = i;
                else
                {
                    bool isTempTargetPrier = false;
                    int shorterlen = (wordList[i].length() > wordList[temptarget].length() ) ? wordList[i].length() : wordList[temptarget].length();
                    for (int j = 1; j < shorterlen; j++)
                        if(wordList[i][j] < wordList[temptarget][j])
                        {
                            temptarget = i;
                            break;
                        }
                        else if(wordList[i][j] > wordList[temptarget][j])
                        {
                            isTempTargetPrier = true;
                            break;
                        }
                    if((!isTempTargetPrier && temptarget != i) && (wordList[i].length() < wordList[temptarget].length()))
                        temptarget = i;
                }
            }
        retval.push_back(wordList[temptarget]);
        wordList[temptarget] = wordList.back();
        wordList.pop_back();
        if(wordList.size() == 0)
            sorted = true;
    }
    return retval;
}

int main()
{
    cin >> wordAmount;
    vector<string> wordList;
    string tempString;
    for (int i = 0; i < wordAmount; i++)
    {
        cin >> tempString;
        wordList.push_back(tempString);
    }
    wordList = sort(wordList);
    for (int i = 0; i < wordAmount; i++)
        cout << wordList[i] << endl;
    return 0;
}
