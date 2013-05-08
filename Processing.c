#include"main.h"
/*
    Данный файл включает в себя реализацию функций, которые осуществляют проверку входных данных.
    v. 1.0
    Save [2:33 05.05.2013]
    by Ulturgashev Vladimir
*/
unsigned char Processing(int argc, char *argv[],char *matx)//matx-matrix [9]
{
    int i,c,t;
    char help=0;
    for (i=1; i<argc; i++)
    {
        c=NumberOrLetter(i, argv);
        if(c==4)//processing is user's mod
        {
            if(i+1<argc)//processing image arguments
            {
                t=Users_proc(i+1, argv, matx);
                if(t==1)//processing data user setting
                    i++;
                else
                    return 0;
            }
            else
            {
                printf("Input data is not correct\n");
                return 0;
            }

        }
        switch(c)//processing all setting
        {
            case 1: matx[number]=atoi(argv[i]);
            break;
            case 2: matx[def]=1;//default
            break;
            case 3: matx[all]=1;//all
            break;
            case 4: matx[user]=1;//user
            break;
            case 5: matx[matrix]=1;//matrix
            break;
            case 6: ; return 2;
            break;
            default: printf("Input data is not correct\n");
            return 0;
        }
    }
    if(((matx[2]&matx[3])|(matx[2]&matx[4])|(matx[3]&matx[4]))==1)//control of all sellect
    {
        printf("Input data is not correct\n");
        return 0;
    }
    return 1;
}

unsigned char NumberOrLetter(int argc, char *argv[])//function is processing input data |function is ok...
{
    if(atoi(argv[argc])>0)
        return 1;
    else if (!strcmp(argv[argc], "/d"))
        return 2;
    else if (!strcmp(argv[argc], "/a"))
        return 3;
    else if (!strcmp(argv[argc], "/u"))
        return 4;
    else if (!strcmp(argv[argc], "/m"))
        return 5;
    else if (!strcmp(argv[argc], "/?"))
        return 6;
    else
        return 0;
}

unsigned char Users_proc(int argc, char *argv[],char *matx)//the processing input data of user's |function is ok...
{
    int lenght;
    lenght=strlen(argv[argc]);
    //проверка и ввод
    if(lenght<=4)
    {
        if(strchr(argv[argc],'b')!=0)
            matx[big]=1;
        if(strchr(argv[argc],'s')!=0)
            matx[small]=1;
        if(strchr(argv[argc],'n')!=0)
            matx[numeric]=1;
        if(strchr(argv[argc],'c')!=0)
            matx[simbols]=1;
    }
    else
    {
        printf("Input data is not correct\n");
        return 0;
    }
    //проверка
    if(lenght!=(matx[big]+matx[small]+matx[numeric]+matx[simbols]))//normal test
    {
        printf("Input data is not correct\n");
        return 0;
    }
    return 1;
}
