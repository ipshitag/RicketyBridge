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

//decisionFunc = A function to send 2 pairs to the the function and increasing the f1
//toReached = A function to send the pair to the reached queue(insert), and sending the first one to backWait, and also to check whether all of them have reached, i.e. whether the length of arr2 is 4
//backWait = A function to insert the 1st person in reached(arr2) back to waiting, i.e. this function is used for the person who carries the torch back


void decisionFunc()
{
   //Sending first 2 elements to toReached
   toReached(arr1[f1],arr1[f1+1]);
   f1 = f1+2;
}


void toReached(int a, int b)
{
   //checking if its the beginning of the queue
   if(f2 == 0 && l2 == 0)
   {
    arr2[f2] = a;
    arr2[f2+1] = b;
    l2++;

   //Time is added of the one being slower
   
    if(a>b)
      time = time + a;
    else
      time = time + b;
 
   //Sending first person of reached
   backWait(arr2[f2]);
   f2++;
   }
 
 else
  {
   
    if( (f2-l2)+1 != 4)    //checking if all of them have reached or not
     {
      //inserting into arr2 array i.e. reached queue
      l2++;
      arr2[l2] = a;
      l2++;
      arr2[l2] = b;
 
      //time of slower is added
      if(a>b)
       time = time + a;
      else
       time = time + b;

     //if all of them have reached, then, we do not need to send anyone back with torch
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
  //adding the element to the end of arr1 i.e. the waiting queue
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
