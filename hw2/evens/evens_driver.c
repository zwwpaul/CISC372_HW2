/* Driver for evens libary */
#include<stdio.h>
#include<stdlib.h>
#include "evens_lib.h"

// add other #includes as needed

// ADD A GOOD COMMENT HERE.  Explain exactly what the
// main function does.
int main(int argc, char *argv[]) {
  //Initialize the global variables
  int elementNum=argc;
  int* num_evens;
  int* input_array;
  //This array is for temporarily using to store the result of "find_evens" function 
  int* temp_array;
  
  //Allocate memory for pointer stuff
  num_evens=malloc(sizeof(int));
  input_array=malloc(sizeof(int));
  temp_array=malloc(sizeof(int));
  //Put data from user input into an new array
  for(int i=0;i<elementNum;i++){
	  input_array[i]=atoi(argv[i]);
  }
  temp_array=find_evens(input_array,elementNum, num_evens);
  print_array(temp_array,*num_evens);
  
  //Release the allocated memory
  free(num_evens);
  free(input_array);
  return 0;
}

