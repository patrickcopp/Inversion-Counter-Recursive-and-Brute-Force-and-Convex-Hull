/*
Patrick Copp
1007602
Assignment 2 
February 2019
*/
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
bool dupCheck(double values[30000][2],int returns[1000],int j,int size);
void bubbleSort(double values[30000][2], int returns[], int);

void bruteForce2(double values[30000][2])
{
  clock_t start,end;
  double time;
  start=clock();
  int returns[1000];
  double newLine;
  bool left=true;
  double x1,x2,x3,y1,y2,y3;
  int vertexCount=0;
  for(int i=0;i<30000;i++)
  {
    for(int j=0;j<30000;j++)
    {
      if(i==j)continue;
      left=true;
      for(int k=0;k<30000;k++)
      {
        if(k==i || k==j)continue;
        x1=values[i][0];
        y1=values[i][1];
        x2=values[j][0];
        y2=values[j][1];
        x3=values[k][0];
        y3=values[k][1];
        newLine=((x3-x1)*(y2-y1)-((y3-y1)*(x2-x1)));
        if(newLine>0)
        {
          left=false;
          break;
        }
      }
      if(left)
      {
        if(dupCheck(values,returns,j,vertexCount+1))
        {
          returns[vertexCount]=j;
          vertexCount++;
        }
      }
    }
  }
  end=clock();
  time=((double)(end-start)/CLOCKS_PER_SEC);
  bubbleSort(values, returns,vertexCount);
  for(int i=0;i<vertexCount;i++)
  {
    printf("%d.\t%lf\t%lf\n",i+1,values[returns[i]][0],values[returns[i]][1]);
  }
  printf("Time taken: %lf seconds\n",time);
}

bool dupCheck(double values[30000][2],int returns[1000],int j,int size)
{

  for(int i=0;i<size-1;i++)
  {
    if(values[returns[i]][0]==values[j][0] && values[returns[i]][1]==values[j][1])
    {
      return false;
    }
  }
  return true;
}

void bubbleSort(double values[30000][2],int returns[1000],int size)
{
  int hold;
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size-i-1;j++)
    {
      if(values[returns[j]][0]>values[returns[j+1]][0])
      {
        hold=returns[j];
        returns[j]=returns[j+1];
        returns[j+1]=hold;
      }
    }
  }
}
