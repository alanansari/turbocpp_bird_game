#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
int a,i,j,g,game=1,t,scr=0,o=79,p1=12,p2=18,m,n1,n2,pass=0;
float x=25,y=12;
void score()
{
 gotoxy(35,1);
 cout<<"score: "<<scr;
}
void pipes()
{
 unsigned int seedval;
 time_t t;
 seedval=(unsigned)time(&t);
 srand(seedval);
 o--;
 for(i=2;i<p1;i++)
 {
  gotoxy(o,i);
  cout<<char(219);
 }
 for(i=25;i>p2;i--)
 {
  gotoxy(o,i);
  cout<<char(219);
 }
 if((y<=p1||y>=p2)&&x==o)
  { game=0; }
 if(o==24)
 {scr++;}
 if(o<2)
 {
  o=79;
  p1=(rand()%15)+3;
  p2=p1+5;
 }
 if(o==40)
 {
  pass=1;
  m=79;
  n1=(rand()%16)+3;
  n2=n1+5;
 }
 if(pass==1)
 {
 m--;
 for(i=2;i<n1;i++)
 {
  gotoxy(m,i);
  cout<<char(219);
 }
 for(i=25;i>n2;i--)
 {
  gotoxy(m,i);
  cout<<char(219);
 }
 if((y<=n1||y>=n2)&&x==m)
  { game=0; }
 if(m==24)
 {scr++;}
 }
}
void countdown()
{
 gotoxy(39,12);
 cout<<"3";
 delay(900);
 clrscr();
 gotoxy(39,12);
 cout<<"2";
 delay(900);
 clrscr();
 gotoxy(39,12);
 cout<<"1";
 delay(900);
 clrscr();
}
void main()
{
 retry:
 game=1;scr=0;o=79;p1=12;p2=17;pass=0;y=12;
 _setcursortype(_NOCURSOR);
 clrscr();
 textbackground(10);
 textcolor(0);
 clrscr();
 countdown();
  while(!kbhit())
  {
   a='s';
   change:
   pipes();
   score();
   if(game==0)goto exit;
   if(a=='s')
   y++;
   if(a=='w'||a==' ')
    {
     y-=4;
     a='s';
    }
   if(a=='p')
   {
    getch();
   }
   if(y>25)
   goto exit;
   if(y<2)
   y=2;
   gotoxy(x,y);
   cout<<char(2);
   delay(90);
   clrscr();
  }
  a=getch();
  goto change;
  exit:
  gotoxy(36,11);
  cout<<"GAME OVER";
  gotoxy(32,13);
  cout<<"press r to retry.";
  gotoxy(32,14);
  cout<<"press x to exit";
  again:
  g=getch();
 if(g=='x')
 goto esc;
 if(g=='r')
 goto retry;
 else
 goto again;
 esc:
}