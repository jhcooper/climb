#include <stdio.h>
#include <stdlib.h>
int climb(int n , int *save){
	if( n<0 ){//if n<0, add 0 because this is not a valid path
		return 0;
	}
	else if( save[n-1] != 0){//if the answer has already been found, use it
		return save[n-1];
	}
	else if(n==0){//if n=0, add one to the number of valid solutions
		return 1;
	}
	else{//otherwise, recursively calls with the n-1th,n-3rd, n-5th stair
		save[n-1] = climb(n-1, save) + climb(n-3,save) + climb(n-5,save);//saves the number of solutions for n stairs
		return save[n-1];
	}
}

int main(){
	int n;
	int ans;
	printf("Enter the number of steps for your staircase: ");
	scanf("%d",&n);
	int *save =  (int*)calloc(n, sizeof(int));//allocates space for an integer array of size n and initializes all elements to 0
	ans = climb(n,save);
	printf("There are %d ways to climb %d stairs. \n",ans,n);
	return 0;
}

