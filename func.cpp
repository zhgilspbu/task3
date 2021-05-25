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


void add(robber* a[], int* num){

cout<<"vvedite dannie o razboinike \n";
string name;
int horse,sword,rub,jew,wife,coin;
cin>>name>>horse>>sword>>rub>>jew>>wife>>coin;
robber* tmp = new robber;
tmp->alive=1;
tmp->coin=coin; //1
tmp->horse=horse; //500
tmp->jew=jew; //200
tmp->name=name;
tmp->rub=rub; //350
tmp->sword=sword; //600
tmp->wife=wife; //400
tmp->proper=coin+500*horse+jew*200+rub*350+sword*600-wife*400;
a[(*num)]=tmp;
*num=(*num)+1;
}


void kill(robber* a[],string name,int num){

for (int i=0;i<num;i++){
    if (a[i]->name == name && a[i]->alive){
        a[i]->alive=0;
        i=num;
    }
}
}


void show_all(robber* a[], int num){

cout<<"name"<<setw(10)<<"alive"<<setw(10)<<"sword"<<setw(10)<<"horse"<<setw(7)<<"rub"<<setw(7)<<"jew"<<setw(7)<<"coin"<<setw(7)<<"wife"<<setw(10)<<"property"<<endl;
for (int i=0;i<num;i++){
        cout<<a[i]->name<<setw(7)<<a[i]->alive<<setw(10)<<a[i]->sword<<setw(10)<<a[i]->horse<<setw(7)<<a[i]->rub<<setw(7)<<a[i]->jew<<setw(7)<<a[i]->coin<<setw(7)<<a[i]->wife<<setw(10)<<a[i]->proper<<endl;
}


}

void show_alive(robber* a[],int num){
cout<<"name"<<setw(10)<<"alive"<<setw(10)<<"sword"<<setw(10)<<"horse"<<setw(7)<<"rub"<<setw(7)<<"jew"<<setw(7)<<"coin"<<setw(7)<<"wife"<<setw(10)<<"property"<<endl;
for (int i=0;i<num;i++){
        if (a[i]->alive){
        cout<<a[i]->name<<setw(7)<<a[i]->alive<<setw(10)<<a[i]->sword<<setw(10)<<a[i]->horse<<setw(7)<<a[i]->rub<<setw(7)<<a[i]->jew<<setw(7)<<a[i]->coin<<setw(7)<<a[i]->wife<<setw(10)<<a[i]->proper<<endl;
}}

}


void get_info(robber* a[],string name,int num){
cout<<"name"<<setw(10)<<"alive"<<setw(10)<<"sword"<<setw(10)<<"horse"<<setw(7)<<"rub"<<setw(7)<<"jew"<<setw(7)<<"coin"<<setw(7)<<"wife"<<setw(10)<<"property"<<endl;
for (int i=0;i<num;i++){
    if (a[i]->name == name){
        cout<<a[i]->name<<setw(7)<<a[i]->alive<<setw(10)<<a[i]->sword<<setw(10)<<a[i]->horse<<setw(7)<<a[i]->rub<<setw(7)<<a[i]->jew<<setw(7)<<a[i]->coin<<setw(7)<<a[i]->wife<<setw(10)<<a[i]->proper<<endl;
    }
}
}

void ful_property(robber* a[],int num){

int sword=0,jew=0,horse=0,rub=0,wife=0,coin=0, property=0;
for (int i=0;i<num;i++){
        if (a[i]->alive){
    sword+=a[i]->sword;
    jew+=a[i]->jew;
    horse+=a[i]->horse;
    rub+=a[i]->rub;
    wife+=a[i]->wife;
    coin+=a[i]->coin;
    property+=a[i]->proper;
        }

}
cout<<"sword"<<setw(10)<<"horse"<<setw(7)<<"rub"<<setw(7)<<"jew"<<setw(7)<<"coin"<<setw(7)<<"wife"<<setw(10)<<"property"<<endl;
cout<<sword<<setw(10)<<horse<<setw(8)<<rub<<setw(8)<<jew<<setw(7)<<coin<<setw(7)<<wife<<setw(9)<<property;
}

void get_rich(robber* a[], int n){

int m=a[0]->proper;
for (int i=1;i<n;i++){
    if (a[i]->proper>m){
        m=a[i]->proper;
    }
}

cout<<"name"<<setw(10)<<"alive"<<setw(10)<<"sword"<<setw(10)<<"horse"<<setw(7)<<"rub"<<setw(7)<<"jew"<<setw(7)<<"coin"<<setw(7)<<"wife"<<setw(10)<<"property"<<endl;
for (int i=0;i<n;i++){
    if (a[i]->proper == m && a[i]){
        cout<<a[i]->name<<setw(7)<<a[i]->alive<<setw(10)<<a[i]->sword<<setw(10)<<a[i]->horse<<setw(7)<<a[i]->rub<<setw(7)<<a[i]->jew<<setw(7)<<a[i]->coin<<setw(7)<<a[i]->wife<<setw(10)<<a[i]->proper<<endl;
    }
}

}

void diagram(robber* a[], int n){
int num;
if (n>10){
    num=10;
}else{

num=n;
}

int sum=0;
for (int i=0;i<num;i++){
        if (a[i]->alive){
    sum+=a[i]->horse;}
}
int gd = CUSTOM;
int gm = CUSTOM_MODE(600,600);
initgraph(&gd, &gm,"");

for (int i=0;i<num;i++){
    setcolor(GREEN);
    if (a[i]->alive){
    rectangle(50*(i+1),550-(500*(a[i]->horse/double(sum))),50*(i+1)+30,550);
    outtextxy(50*(i+1),550-(500*(a[i]->horse/double(sum)))-20,a[i]->name.c_str());
}}
readkey();
}


void round_diagram(robber* a[], int n){

//centr okruzhnosti (300,300) radius- 100
int num;
if (n>=5){
    num=5;
}else {
num=n;
}

double sum=0.0;
double ang=0.0;
for (int i=0;i<num;i++){
    if (a[i]->alive ){
        sum+=a[i]->horse;
    }
}
int gd = CUSTOM;
int gm = CUSTOM_MODE(600,600);
initgraph(&gd, &gm,"");
setcolor(GREEN);
circle(300,300,100);
line(300,300,400,300);

for (int i=0;i<num-1;i++){
          if (a[i]->alive){
    if (ang>PI/2 && ang<3*PI/2){
        outtextxy(cos(ang)*100+260,300-sin(ang)*100,a[i]->name.c_str());
    }else{
        outtextxy(cos(ang)*100+300+5,300-sin(ang)*100-10,a[i]->name.c_str());
    }



    ang+=2*PI*(a[i]->horse/sum);
    line(300,300,cos(ang)*100+300,300-sin(ang)*100);

  }
}
if (a[n-1]->alive){
    if (ang>PI/2 && ang<3*PI/2){
        outtextxy(cos(ang)*100+260,300-sin(ang)*100,a[n-1]->name.c_str());
    }else{
        outtextxy(cos(ang)*100+300+5,300-sin(ang)*100-10,a[n-1]->name.c_str());
    }}
readkey();
}


