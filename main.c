//Mark Haywood
//C3281980
//Project 1
//Due Date: 29/04/2019



#include <stdio.h>
#include <string.h>




void validate_data(char* data, int length)
{
    int i;

    while((((data[i] > 'a') && (data[i] < 'z')) || ((data[i] > 'A') && (data[i] < 'z')) || (data[i] == ' ')) && (i < length))           //validate the entered data
    {
        i++;
    }
    data[i] = 0;                                                  //terminate data string at first illegal character
}
void validate_cipher(char* cipher)                                //function testing thet cipher is entered correctly
{
    int cipher_valid;
    int count;
    int i = 0;
    int c;

                do
            {
                printf("Enter alphabet substitution in lowercase: \n");
                scanf("%s", cipher);
                if(strlen(cipher) == 26)                          //validating that user has entered correct amount of letters
                {
                    cipher_valid = 1;

                    for(c = 'a'; c <= 'z'; c++)                   //looping through each character in the alphabet
                    {
                        count = 0;
                        for(i = 0; i < 26; i++)                  //looping through the cipher to match character
                        {
                            if(cipher[i] == c)                    //count how many matching characters are found - there should be 1 of each character
                            {
                                count++;
                            }
                        }
                        if(count > 1)                             //character was found more than once
                        {
                            printf("Duplicate %c entered in cipher!\n", c);
                            cipher_valid = 0;
                        }
                        else if(count == 0)                       //character wasnt found
                        {
                            printf("Missing %c in cipher!\n", c);
                            cipher_valid = 0;
                        }
                    }
                }
                else                                              //not enough characters entered
                {
                    printf("Cipher needs to be 26 characters long!\n");
                    cipher_valid = 0;
                }
            }
            while(cipher_valid == 0);

}
void rotation(char* data, char* result, int k)
{
    int m;
    int i = 0;
                while(data[i]!=0)
            {
                if((data[i]>='a') && (data[i]<='z'))              //testing if charcter is lowercase
                {
                    m = data[i] - 'a';                            //rotation of ascii code
                    m = (m + k)%26;                               //calculation for new charcter
                    result[i] = m + 'a';                          //put new character back into result string
                }
                else if((data[i]>='A') && (data[i]<='Z'))         //test if character is uppercase
                {
                    m = data[i] - 'A';
                    m = (m + k)%26;
                    result[i] = m + 'A';
                }
                else                                              //dont encrypted other characters, for example 'space'
                {
                    result[i] = data[i];
                }
                i++;
            }
            result[i] = 0;
}
void substitution_encryption(char* data, char* result)
{
    char cipher[27];
    int i = 0;
    int m;

        validate_cipher(cipher);
        i = 0;

            while(data[i]!=0)
            {
                if((data[i]>='a') && (data[i]<='z'))              //testing if charcter is lowercase
                {
                    m = data[i] - 'a';                            //convert character into 0 based code
                    result[i] = cipher[m];                        //placing substituted character into string
                }
                else if((data[i]>='A') && (data[i]<='Z'))         //tetsing if character is uppercase
                {
                    m = data[i] - 'A';
                    result[i] = cipher[m];
                }
                else                                              //dont encrypted illegal characters
                {
                    result[i] = data[i];
                }
                i++;
            }
            result[i] = 0;
}
void substitution_decryption(char* data, char* result)
{
    char cipher[27];
    int i = 0;
    int j;

        validate_cipher(cipher);
        i = 0;                                                    //re-initialising loop variable

            while(data[i]!=0)
            {
                j = 0;
                while(data[i] != cipher[j])                       //searching the cipher for matching character
                {
                    j++;
                }
                result[i] = j + 'a';
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
            validate_data(data, 100);
            printf("Enter rotation amount: \n");
            scanf("%d", &k);

            rotation(data, result, k);

            break;

        case 2:
            printf("Enter message to be encrypted: \n");
            fgets(data, 100, stdin);                            //this command removes unwanted new line character from stdin
            fgets(data, 100, stdin);
            validate_data(data, 100);
            substitution_encryption(data, result);

            break;

        case 3:
            printf("Enter message to be decrypted\n");
            fgets(data, 100, stdin);                            //this command removes unwanted new line character from stdin
            fgets(data, 100, stdin);
            validate_data(data, 100);
            printf("Enter rotation amount: \n");
            scanf("%d", &k);

            rotation(data, result, -k);

            break;

        case 4:
            printf("Enter message to be decrypted: \n");
            fgets(data, 100, stdin);                            //this command removes unwanted new line character from stdin
            fgets(data, 100, stdin);
            validate_data(data, 100);
            substitution_decryption(data, result);

            break;



    }
    printf("%s", result);
    return 0;
}
