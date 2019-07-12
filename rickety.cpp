#include<iostream.h>
#include<conio.h>

int arr1[6] ={5,10,20,25},arr2[6];
int f1,f2,l1,l2;
int time=0;

void decisionFunc();
void toReached(int,int);
void backWait(int);

 //arr1 = array for waiting queue
 //arr2 = array for reached queue

 //f1 = front flag for arr1
 //l1 = end flag for arr1

 //f2 = front tab for arr2
 //l2 = end tag for arr2

 //time = for calculating total time

//decisionFunc = A function to see whether its the last pair waiting to be crossed or not.


void decisionFunc()
{
 toReached(arr1[f1],arr1[f1+1]);
 f1 = f1+2;
}

void toReached(int a, int b)
{

 if(f2 == 0 && l2 == 0)
 {
  arr2[f2] = a;
  arr2[f2+1] = b;
  l2++;
  if(a>b)
  time = time + a;
  else
  time = time + b;

  backWait(arr2[f2]);
   f2++;
 }
 else
 {
  if( (f2-l2)+1 != 4)
  {
   l2++;
   arr2[l2] = a;
   l2++;
   arr2[l2] = b;

   if(a>b)
   time = time + a;
   else
   time = time + b;

   if( (l2-f2)+1 != 4)
   {
    backWait(arr2[f2]);
    f2++;
   }
  }
 }
}

void backWait(int a)
{
 l1++;
 arr1[l1]=a;
 time = time+a;
}


void main()
{
 clrscr();

 f1 = f2 = l2=0;
 l1 = 3;


 decisionFunc();
 decisionFunc();
 decisionFunc();

 cout<<time<<" minutes";
 getch();

}



