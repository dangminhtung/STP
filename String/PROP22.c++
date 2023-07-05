#include <iostream>
#include <string.h>
using namespace std;
char P[20], S[100];

int str_truoc(int lenP, int lenS)
{
    for (int i = 0; i <= lenS - lenP; i++)
    {
        int check = true;
        for (int j = 0; j < lenP; j++)
        {
            if (P[j] != S[i + j])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            return i + lenP - 1;
        }
    }
    return -1;
}

int str_sau(int lenP, int lenS)
{
    for (int i = lenS - 1; i >= 0; i--)
    {

        int j = 0;
        for (j = 0; j < lenP && i - j >= 0; j++)
        {
            if (P[lenP - j - 1] != S[i - j])
            {

                break;
            }
        }
        if (j == lenP)
        {
            return i - lenP + 1;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {

        cin >> P >> S;
        int check_sao = false;
        int locaDot = 0;
        for (int i = 0; i < strlen(P); i++)
        {
            if (P[i] == '.')
            {
                locaDot = i;
            }
            if (P[i] == '*')
            {
                check_sao = true;
                break;
            }
        }

        if (!check_sao)
        {
            int check = true;
            if (locaDot == strlen(P) - 1)
            {
                int lenT = strlen(P) - 1;
                int vitricuoi = str_truoc(lenT, strlen(S));
                if (S[vitricuoi + 1] == '\0')
                    check = false;
                else
                    cout << "#" << (k + 1) << " " << lenT + 1 << endl;
            }
            else if (locaDot == 0)
            {
                int lenS = strlen(P) - 1;

                int vitridau = str_sau(lenS, strlen(S));
                cout << vitridau << endl;
            }
        }
    }
}