#ifndef CUBE_H_
#define CUBE_H_ 
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
typedef int ArI[8];
typedef int SArI[4];
int mygetch();  //int 类型不声明，无警告？ void 不可以
void relocate(int [], int [], int); 
void ForBackRotate(int [], int, int);
void dis(int [],int []);
int ReadFromText(int);
#endif
