#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <iostream>
#include<iomanip>
#include<conio.h>
#include<graphics.h>
#include<cmath>
#define PI 3.1415926

using namespace std;
typedef struct robber{

string name;
int alive;
int horse;
int sword;
int rub;
int jew;
int wife;
int coin;
int proper;
} robber;


void add(robber *a[],int*);
void kill(robber *a[],int);
void show_all(robber* a[], int num);
void show_alive(robber* a[],int num);
void get_info(robber* a[],string name,int num);
void ful_property(robber* a[],int num);
void get_rich(robber* a[], int n);
void diagram(robber* a[], int n);
void round_diagram(robber* a[], int n);


#endif // FUNC_H_INCLUDED
