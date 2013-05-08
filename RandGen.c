#include "main.h"
/*
    Данный файл включает в себя реализацию функций для генерации паролей
    v 1.0
    Save [17:40 07.05.2013]
    by Ulturgashev Vladimir
*/
int itRandomNumber(void)//make random numbers
{
    int numN;
    numN=rand()%10+48;
    return numN;
}
//====================================================================<<
int itRandomBigLetter(void)//make random small latter
{
    int numB;
    numB=rand()%26+65;
    return numB;
}
//====================================================================<<
int itRandomSmallLetter(void)//make random small latter
{
    int numL;
    numL=rand()%26+97;
    return numL;
}
//====================================================================<<
int itRandomSimbol(void)//returned any simbols
{
    char mass[]={"!@#$%^&*()_-=+\|/{}][';:>.<?,~`№"};
    return(mass[rand()%strlen(mass)]);
}
//====================================================================<<
int choiceRandom(int N)//selection function
{
    int i=rand()%N;
    switch(i)
    {
        case 0: return (itRandomNumber());
        break;
        case 1: return (itRandomBigLetter());
        break;
        case 2: return (itRandomSmallLetter());
        break;
        case 3: return (itRandomSimbol());
        break;
        default: printf("Error when generation passwords");
        return 0;
    }
}
//====================================================================<<
void Mixer(char *summ)//fuction for mixers arrays
{
    int t1,t2,i;
    char tmp;
    int revers=strlen(summ)*15;

    for(i=0;i<revers;i++)
    {
        t1=rand()%strlen(summ);
        t2=rand()%strlen(summ);
        tmp=summ[t1];
        summ[t1]=summ[t2];
        summ[t2]=tmp;
    }
}
//====================================================================<<
void keyGen(char *matx)//make string of password
{
    int i,j,N;
    int KeyS[matx[number]];
    int KeyM[matx[number]][matx[number]];
    //the select variant
    if(matx[def]==1)
        N=3;//default
    else
    if(matx[all]==1)
        N=4;//all simbols
    if(matx[matrix]==0)//string
    {
        for(i=0;i<matx[number];i++)//make and printf
        {
            KeyS[i]=choiceRandom(N);
            printf("%c",KeyS[i]);
        }
    }
    else//matrix
    {
        for(i=0;i<matx[number];i++)
        {
            for(j=0;j<matx[number];j++)
            {
                KeyM[i][j]=choiceRandom(N);
                printf("%c",KeyM[i][j]);
            }
            printf("\n");
        }

    }
}
//====================================================================<<
void keyGenUser(char *matx)//make password of user's setting
{
    char aBig[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char aSmall[] = {"abcdefghijklmnoprstuvwxyz"};
    char aNumb[] = {"1234567890"};
    char aSimb[] = {"!@#$%^&*()_-=+\|/{}][';:>.<?,~`"};
    char *summ;
    int i,j;
    int KeyS[matx[number]];
    int KeyM[matx[number]][matx[number]];

    summ=(char *)calloc(&summ,sizeof(char));
    if(matx[big]==1)
    {
        summ=(char *)realloc(summ,strlen(aBig)*sizeof(char));
        strcat(summ,aBig);
    }
    if(matx[small]==1)
    {
        summ=(char *)realloc(summ,strlen(aSmall)*sizeof(char));
        strcat(summ,aSmall);
    }
    if(matx[numeric]==1)
    {
        summ=(char *)realloc(summ,strlen(aNumb)*sizeof(char));
        strcat(summ,aNumb);
    }
    if(matx[simbols]==1)
    {
        summ=(char *)realloc(summ,strlen(aSimb)*sizeof(char));
        strcat(summ,aSimb);
    }

    Mixer(summ);//this is mix of array summ

    if(matx[matrix]==0)//string
    {
        for(i=0;i<matx[number];i++)//make and printf
        {
            KeyS[i]=summ[rand()%strlen(summ)];
            printf("%c",KeyS[i]);
        }
    }
    else//matrix
    {
        for(i=0;i<matx[number];i++)
        {
            for(j=0;j<matx[number];j++)
            {
                KeyM[i][j]=summ[rand()%strlen(summ)];
                printf("%c",KeyM[i][j]);
            }
            printf("\n");
        }
    }


    free(summ);
}
//====================================================================<<
