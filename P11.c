/*
Patrick Copp
1007602
Assignment 2
February 2019
*/
#include <stdio.h>
#include <stdbool.h>

int bruteForce(int values[50000])
{
  int invCount=0;
  for(int i=0;i<50000;i++)
  {
    for(int i2=i;i2<50000;i2++)
    {
      if(values[i]>values[i2])
      {
        invCount++;
      }
    }
  }
  return invCount;
}
