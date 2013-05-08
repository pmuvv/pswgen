#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
//included header's files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//the defined variables
#define number  0
#define matrix  1
#define def     2
#define all     3
#define user    4
#define big     5
#define small   6
#define numeric 7
#define simbols 8
//function prototipe

int itRandomNumber(void);//make random numbers
int itRandomBigLetter(void);//make random big letters
int itRandomSmallLetter(void);//make random small latters
int itRandomSimbol(void);//returned any simbols
int choiceRandom(int N);//selection function
void Mixer(char *summ);//fuction for mixers arrays
void keyGen(char *matx);//function for generic string of pass
void keyGenUser(char *matx);//make password of user's setting

unsigned char printHelp(void);//function is print help of cansole

unsigned char NumberOrLetter(int argc, char *argv[]);//function  for processing input data
unsigned char Processing(int argc, char *argv[],char *matx);//function is processing input data |function is ok...
unsigned char Users_proc(int argc, char *argv[],char *matx);//the processing input data of user's |function is ok...

#endif // MAIN_H_INCLUDED
