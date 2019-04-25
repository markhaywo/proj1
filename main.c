#include <stdio.h>

int main ()
{
    char data[100];
    char result[100];
    int k = 5;
    int i = 0;
    int m;

    printf("Enter message to be encrypted\n");
    scanf("%s", data);

    while(data[i]!=0)
    {
        if((data[i]>='a') && (data[i]<='z'))
        {
            m = data[i] - 'a';
            m = (m + k)%26;
            result[i] = m + 'a';
        }
        else if((data[i]>='A') && (data[i]<='Z'))
        {
            m = data[i] - 'A';
            m = (m + k)%26;
            result[i] = m + 'A';
        }
        else
        {
            result[i] = data[i];
        }
        i++;
    }
    result[i] = 0;
    printf("%s", result);
    return 0;
}
