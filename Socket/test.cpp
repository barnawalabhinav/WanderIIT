#include <iostream>
#include <string>

using namespace std;

int main()
{
    char tmp[12];
    sprintf(tmp, "2 %d \n", 423);
    int num = tmp[0] - '0';
    int j = 1;
    while (tmp[j] >= '0' && tmp[j] <= '9')
    {
        num *= 10;
        num += tmp[j] - '0';
        j++;
    }

    cout << num << endl;
    int temp;
    sscanf(tmp, "2 %d", &temp);

    cout << temp << endl;

    cout << stoi(tmp) << endl;
}