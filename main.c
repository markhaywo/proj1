#include <stdio.h>
#include <string.h>







void rotation(char* data, char* result, int k)
{
    int m;
    int i = 0;
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
}
void substitution(char* data, char* result)
{
    char cipher[27];
    int cipher_valid;
    int count;
    int i = 0;
    int c;
    int m;
            do
            {
                printf("Enter alphabet substitution in lowercase: \n");
                scanf("%s", cipher);
                if(strlen(cipher) == 26)
                {
                    cipher_valid = 1;

                    for(c = 'a'; c <= 'z'; c++)
                    {
                        count = 0;
                        for(i = 0; i <= 26; i++)
                        {
                            if(cipher[i] == c)
                            {
                                count++;
                            }
                        }
                        if(count > 1)
                        {
                            printf("Duplicate %c entered in cipher!\n", c);
                            cipher_valid = 0;
                        }
                        else if(count == 0)
                        {
                            printf("Missing %c in cipher!\n", c);
                            cipher_valid = 0;
                        }
                    }
                }
                else
                {
                    printf("Cipher needs to be 26 characters long!\n");
                    cipher_valid = 0;
                }
            }
            while(cipher_valid == 0);

            i = 0;

            while(data[i]!=0)
            {
                if((data[i]>='a') && (data[i]<='z'))
                {
                    m = data[i] - 'a';
                    result[i] = cipher[m];
                }
                else if((data[i]>='A') && (data[i]<='Z'))
                {
                    m = data[i] - 'A';
                    result[i] = cipher[m];
                }
                else
                {
                    result[i] = data[i];
                }
                i++;
            }
            result[i] = 0;
}

int main ()
{
    char data[100];
    char result[100];
    int k = 0;
    int star;




    printf("1.Encryption using rotation cipher\n2.Encryption using substitution cipher\n3.Decryption using rotation cipher\n4.Decryption using substitution cipher\n");
    scanf("%d", &star);


    switch(star)
    {
        case 1:
            printf("Enter message to be encrypted\n");
            fgets(data, 100, stdin);                            //this command removes unwanted new line character from stdin
            fgets(data, 100, stdin);
            printf("Enter rotation amount: \n");
            scanf("%d", &k);

            rotation(data, result, k);

            break;

        case 2:
            printf("Enter message to be encrypted: \n");
            fgets(data, 100, stdin);                            //this command removes unwanted new line character from stdin
            fgets(data, 100, stdin);

            substitution(data, result);

            break;

        case 3:
            printf("Enter message to be decrypted\n");
            fgets(data, 100, stdin);                            //this command removes unwanted new line character from stdin
            fgets(data, 100, stdin);
            printf("Enter rotation amount: \n");
            scanf("%d", &k);

            rotation(data, result, -k);

            break;


    }
    printf("%s", result);
    return 0;
}
