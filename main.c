/*
            "PSWGEN"
    The program by make for genirated passwords
    Data make: 08.05.2013 v.1.0
    by Ulturgashev Vladimir
*/
#include "main.h"

int main(char argc,char *argv[])
{
    srand(time(NULL));
    int i,a;
    char lop[]={0,0,0,0,0,0,0,0,0};//int matrix
    a=Processing(argc,argv,lop);
    if(a==1)
    {
        if(lop[user]==1)
            keyGenUser(lop);
        else
        if(lop[def]==1 | lop[all]==1)
            keyGen(lop);
    }
    else
    if(a==2)
        printHelp();
    else
        return 0;
}
