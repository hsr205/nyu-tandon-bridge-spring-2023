#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> getMapFromString(string inputString)
{

    map<char, int> resultMap;

    for (char character : inputString)
    {
        bool isNotSpace = !isspace(character);
        bool isAlpha = isalpha(character);

        if (isNotSpace && isAlpha)
        {
            character = tolower(character);
            resultMap[character]++;
        }
    }

    return resultMap;
}

bool isAnagram(map<char, int> map1, map<char, int> map2)
{

    int cnt = 0;
    auto iterator1 = map1.begin();
    auto iterator2 = map2.begin();
    bool isSameSize = map1.size() == map2.size();

    if (isSameSize)
    {
        while (iterator1 != map1.end() && iterator2 != map2.end())
        {
            bool isKeysEqual = iterator1->first == iterator2->first;
            bool isValuesEqual = iterator1->second == iterator2->second;

            if (isKeysEqual && isValuesEqual)
            {
                cnt++;
                if (cnt == map1.size() && cnt == map2.size())
                {
                    return 1;
                }
            }

            ++iterator1;
            ++iterator2;
        }
    }

    return 0;
}

void getCheckInput()
{

    string stringInput1;
    string stringInput2;

    cout << "Please enter two sentences: " << endl;
    getline(cin, stringInput1);
    getline(cin, stringInput2);

    map<char, int> map1 = getMapFromString(stringInput1);
    map<char, int> map2 = getMapFromString(stringInput2);

    if (isAnagram(map1, map2))
    {

        cout << "The two sentences are anagrams" << endl;
    }
    else
    {
        cout << "The two sentences are not anagrams" << endl;
    }
}

int main()
{
    getCheckInput();

    return 0;
}
