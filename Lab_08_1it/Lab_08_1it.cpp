// Перевіряє наявність трійки знаків оклику "!!!" у рядку та замінює кожну таку трійку на "**" (ітераційний спосіб).

#include <iostream>
#include <cstring>

using namespace std;

bool HasTripleExclamation(const char* str)
{
    if (strlen(str) < 3)
        return false;

    for (int i = 0; str[i + 2] != '\0'; i++)
        if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!')
            return true;

    return false;
}

char* ReplaceTripleExclamation(char* str)
{
    size_t len = strlen(str);
    char* tmp = new char[len + 1];

    size_t i = 0;
    size_t k = 0;
    while (i < len)
    {
        if (str[i + 1] != '\0' && str[i + 2] != '\0' &&
            str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!')
        {
            tmp[k++] = '*';
            tmp[k++] = '*';
            i += 3;
        }
        else
        {
            tmp[k++] = str[i++];
        }
    }
    tmp[k] = '\0';

    for (size_t j = 0; j <= k; j++)
        str[j] = tmp[j];

    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (HasTripleExclamation(str))
        cout << "String contains '!!!'" << endl;
    else
        cout << "String does NOT contain '!!!'" << endl;

    char* dest = ReplaceTripleExclamation(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}