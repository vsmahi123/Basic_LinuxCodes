#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Temperary defines */
#define MinPassLen 6
#define MinUperCase 1
#define MinLowCase 1
#define MinDigit 1
#define MinSplChar 1


/*temp typedefs*/
typedef unsigned int Uint8;
char* readline(int *n);
Uint8 CheckUprCase(int n, char* password);
Uint8 CheckLwrCase(int n, char* password);
Uint8 CheckDigit(int n, char* password);
Uint8 CheckSplChar(int n, char* password);

//Complete the minimumNumber function below.
int minimumNumber(int n, char* password)
{
    Uint8 MinNoFrStrngPass = 0,result=0 ,temp =0;
   puts("CHECKING PASSWORD ... ...");
    if(MinPassLen > n)  //if password length is less than 6
    {
        if(MinUperCase > CheckUprCase(n,password))
        {
            MinNoFrStrngPass++;
        }
        if(MinLowCase > CheckLwrCase(n,password))
        {
            MinNoFrStrngPass++;
        }
        if(MinDigit > CheckDigit(n,password))
        {
            MinNoFrStrngPass++;
        }
        if(MinSplChar > CheckSplChar(n,password))
        {
            MinNoFrStrngPass++;
        }
        if(MinPassLen <= (MinNoFrStrngPass + n ))
        {
            result = MinNoFrStrngPass;

        }
        else
        {
            temp = MinPassLen - (MinNoFrStrngPass + n );
            result = MinNoFrStrngPass + temp;

        }
        if(MinNoFrStrngPass >= 1)
        {
           puts("--YOUR PASSWORD IS WEAK");
        }
    }
    else
    {
        if(MinUperCase > CheckUprCase(n,password))
        {
            MinNoFrStrngPass++;
        }
        if(MinLowCase > CheckLwrCase(n,password))
        {
            MinNoFrStrngPass++;
        }
        if(MinDigit > CheckDigit(n,password))
        {
            MinNoFrStrngPass++;
        }
        if(MinSplChar > CheckSplChar(n,password))
        {
            MinNoFrStrngPass++;
        }

        result = MinNoFrStrngPass;

                if(MinNoFrStrngPass >= 1)
        {
           puts("--YOUR PASSWORD IS WEAK");
        }

    }

return (int)result;
}

int main()
{
    /*FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }*/
    int n=0;
    char* password = readline(&n);


    int answer = minimumNumber(n, password);

    if(answer == 0)
        puts("your password is strong");
    else
    printf( "you have to add total '%d' chars to make your password strong\n", answer);



    return 0;
}

char* readline(int *n) {
    char *data,let=0,iter=0;
    size_t alloc_length = 1024;
    size_t data_length = 0;
    data = malloc(alloc_length);
    int m=0;
    puts("enter pass:");
    while((let=getchar()) != '\n')
    {
            if(iter<100)
            {
                data[iter] = let;

            }
            else break;
            iter++;
    }
    data[iter] = '\0';
m = iter;
*n = m;
    return (char *)data;
}

Uint8 CheckUprCase(int n, char* password)
{
    Uint8 iterator = 0,cnt = 0;
//puts("check upr");
    while(n > iterator )
    {
        if(('A' <= password[iterator] )
           && ('Z' >= password[iterator]))
           {
               cnt++;
           }
            iterator++;
    }
    if(0 == cnt)
    {
        puts("- Upper case char missing \n  *Add at least one UPPER CASE to make your password strong!!\n\n");
    }
    return cnt;

}
Uint8 CheckLwrCase(int n, char* password)
{
    Uint8 iterator = 0,cnt = 0;
//puts("check lwr");
    while(n > iterator )
    {

        if(('a' <= password[iterator] )
           && ('z' >= password[iterator]))
           {
               cnt++;
           }
           iterator++;
    }
    if(0 == cnt)
    puts("- Lower case char missing \n  *Add at least one LOWER CASE to make your password strong!!\n\n");
    return cnt;

}
Uint8 CheckDigit(int n, char* password)
{
    Uint8 iterator = 0,cnt = 0;
//puts("check Dg");
    while(n > iterator )
    {
        if(('0' <= password[iterator] )
           && ('9' >= password[iterator]))
           {
               cnt++;
           }
            iterator++;
    }
    if(0 == cnt)
    puts("- Digit missing \n  *Add at least one DIGIT to make your password strong!!\n\n");
    return cnt;

}
Uint8 CheckSplChar(int n, char* password)
{
    Uint8 iterator = 0,cnt = 0;
//puts("check spl");
    while(n > iterator )
    {
        if(('!' == password[iterator] )
           || ('@' == password[iterator])
           || ('#' == password[iterator])
           || ('$' == password[iterator])
           || ('%' == password[iterator])
           || ('^' == password[iterator])
           || ('&' == password[iterator])
           || ('*' == password[iterator])
           || ('(' == password[iterator])
           || (')' == password[iterator])
           || ('+' == password[iterator])
           || ('-' == password[iterator]))
           {
               cnt++;
           }
            iterator++;
    }
    if(0 == cnt)
    puts("- special char missing \n  *Add at least one SPECIAL CHAR to make your password strong!!\n\n");
    return cnt;

}
