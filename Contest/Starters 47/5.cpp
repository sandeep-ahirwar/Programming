#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;

    while (n > 0)
    {
        int m;
        int zero = 0;
        int one = 0;
        char c;
        string str = "";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> c;
            str += c;
            if (int(c) == 0)
                zero++;
            else
                one++;
        }
        string str1 = "";
        string str2 = "";
        string result = "";

        if (m <= 2)
        {
            cout << str << endl;
        }
        else
        {

            for (int i = 0; i < zero; i++)
                str1 += "0";
            for (int i = 0; i < one; i++)
                str2 += "1";

            for (int i = 0; i < str1.size(); i++)
            {
                result = result + str1[i];
            }

            for (int i = 0; i < str2.size(); i++)
            {
                result = result + str2[i]; 
            }

            cout << result << endl;
        }

        n--;
    }

    return 0;
}