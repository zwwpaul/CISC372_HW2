/* Implementation of the evens library. */
#include <stdio.h>
#include<stdlib.h>
#include "evens_lib.h"
// add other #includes as needed

int * find_evens(int * p, int n, int * num_evens) {
  //If the no ints in the given sequence, return NULL value
  if(n==0){
	  return NULL;
  }else{
	int* result;
	int index;
	int countEven;

	//Only positive natural number can be counted.
	for(int i=0;i<n;i++){
		if(p[i]!=0){
			if(p[i]%2==0){
				countEven++;
			}
		}
	}
	//If there is no even number, return NULL value
	if(countEven==0){
		return NULL;
	}else{
		//Allocate memory for the new sequence we will return,
		//and put all the even numbers into the sequence
		*num_evens=countEven;
		result=(int*)malloc(sizeof(int)*countEven);
		for(int i=0;i<n;i++){
			if(p[i]!=0){
			if(p[i]%2==0){
				result[index]=p[i];
				index++;
			}
			}
		}
	return result;
	}

  return NULL;
}
}

void print_array(int * p, int n) {
  printf("The even numbers are: ");
  for (int i = 0; i < n; i++)
    printf("%d ", p[i]);
  printf("\n");
  fflush(stdout);
}

