#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    char password[6] = "";
     
    int x, i = 0;
    for (int i = 1; i <= 99999; ++i)
    {
        int num = i;
        for (int j = 4; j >= 0; --j)
        {
            password[j] = (char)((num % 10) + 48);
            num /= 10;
        }
        for (int j = 0; j < 5; ++j)
        {
            cout << password[j];
        }
        cout << endl;
        for (int i = 0; i < 5; ++i)
        {
            password[i] -= '0';
        }
        int v3 = password[2];
        if (((password[4] * password[3] * password[2]) % 10) == password[1]
            && ((password[3] + password[2] + password[1]) % 10) == password[0])
        {
            cout << "Got right pass\n ";
            
            cout << endl;
            for (int i = 2; i < 5; ++i)
            {
                cout << (char)(int)(password[i] + 60) << '\t';
            }
            cout << endl;
        }
    }
        /*
        && username[0] % 10 == password[2]
        && username[1] % 10 == password[3]
        && username[2] % 10 == password[4])
        Got right pass --> 
        99911-E0313
        E==
        */
}
