/* Program for ragged question */
#include <stdio.h>
#include<stdlib.h>
 
// 1. lengths. Type: pointer-to-int
// 2. data. Type: pointer-to-pointer-to-int.
int *lengths;
int **data;
// ADD A GOOD COMMENT HERE.  Explain exactly what the
// main function does.
int main(int argc, char **argv) {
  int row = argc;
  int count=0;
  //To allocate the memory for the 2-d array.
  data=(int**)malloc(row*sizeof(int*));
  lengths=malloc(sizeof(int));
  for(int i=0;i<row;i++){
	  data[i]=(int*)malloc(lengths[i]*sizeof(int));
  }

  //Print the whole 2d array
  for(int i=0;i<row;i++){
	  lengths[i]=atoi(argv[i]);
	  for(int j=0;j<lengths[i];j++){
		 data[i][j]=count;
		 printf("%d ",data[i][j]);
		 count++;
	  }
	  printf("\n");
  }

  //Free the allocated memory
  for(int i=0;i<row;i++){
	  free(data[i]);
  }
  free(data);
  free(lengths);
  	 
  return 0;
}

