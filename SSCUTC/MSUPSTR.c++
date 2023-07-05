#include <iostream>
#include <string.h>
using namespace std;

int MAX = 3005;
int getLength(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
int main(int argc, char const *argv[])
{
    char str[MAX];
    int testcase;
    cin >> testcase;
    for (int k = 0; k < testcase; k++)
    {
        cin >> str;
        int length = getLength(str);
        int sub_len = length;
        int number;
        while (true)
        {
            int finish = false;
            number = 0;
            for (int i = 0; i < length; i++)
            {
                int check = true;
                // điều kiện thoát khỏi vòng lặp for để test TH ngắn hơn
                if (sub_len + i > length)
                    break;
                // TH sub_len về còn 2 or 1
                else if (sub_len == 1 || (sub_len == 2 && str[i] == str[i + 1]))
                {
                    number++;
                    finish = true;
                }
                else
                {
                    for (int j = 0; j <= (sub_len - 1) / 2; j++)
                    {
                        if (str[j + i] != str[sub_len - 1 - j + i])
                        {
                            check = false;
                            break;
                        }
                    }
                    if (check == true)
                    {
                        number++;
                        finish = true;
                    }
                }
            }
            if (finish == true)
                break;
            if (sub_len == 1)
                break;
            sub_len--;
        }
        cout << sub_len << " " << number << endl;
    }

    return 0;
}
