/*
Patrick Copp
1007602
Assignment 2 
February 2019
*/
#include <stdio.h>
#include <stdbool.h>

int mergeSort(int arr[], int temp[], int left, int right);
int mergeArrays(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int temp[], int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left) / 2;
    inv_count = mergeSort(arr, temp, left, mid);
    inv_count += mergeSort(arr, temp, mid + 1, right);
    inv_count += mergeArrays(arr, temp, left, mid + 1, right);
  }
  return inv_count;
}

int mergeArrays(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;

  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }

  while (i <= mid - 1)
  {
    temp[k++] = arr[i++];
  }
  while (j <= right)
  {
    temp[k++] = arr[j++];
  }

  for (i = left; i <= right; i++)
  {
    arr[i] = temp[i];
  }


    return inv_count;
}
