/*
Patrick Copp
1007602
Assignment 2
February 2019
*/

#include <stdio.h>
#include <time.h>
void bruteForce2(double values[30000][2]);
int bruteForce(int [50000]);
int mergeSort(int arr[], int temp[], int left, int right);
int mergeArrays(int arr[], int temp[], int left, int mid, int right);
void convexHull(double values[30000][2]);

int main()
{
  int count=0;
  double sum=0;
  int values[50000];
  FILE *fp=fopen("data1.txt","r");
  while (!feof (fp))
  {
    fscanf (fp,"%d", &values[count]);
    sum+=values[count];
    count++;
  }

  clock_t start, end;
  double time;

  start=clock();
  int bruteForceHold=bruteForce(values);
  end=clock();
  time=((double)(end-start)/CLOCKS_PER_SEC);
  printf("Inversion Counter:\n");
  printf("Brute Force:\n");
  printf("Number of inversions: %d\nTime taken: %lf seconds\n",bruteForceHold,time);

  int temp[50000];
  start=clock();
  int mergeSorts=mergeSort(values,temp,0,49999);
  end=clock();
  time=((double)(end-start)/CLOCKS_PER_SEC);

  printf("Merge Algorithm:\n");
  printf("Number of inversions: %d\nTime taken: %lf seconds\n",mergeSorts,time);
  printf("**************************************************\n");
  printf("Convex Hull:\n");
  printf("Brute Force:\n");
  count=0;
  int lr=0;
  sum=0;
  double values2[30000][2];
  fp=fopen("data2.txt","r");
  while (!feof (fp) && count<30000)
  {
    fscanf (fp,"%lf", &values2[count][lr]);
    lr = 1-lr;
    count+=(1*(1-lr));
  }

  bruteForce2(values2);
  printf("Divide and Conquer:\n");
  convexHull(values2);


  return 0;
}
