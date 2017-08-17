#include <stdio.h>
#include <math.h>
int s2a(int a[], int num, int l){
    if (num < (int)pow(10, l)) {
	    for(int i=0; i<l; i++){
	    	a[i] = num%10;
	    	num = num/10;
	    }
        return 0;
    }
    else{
        printf("too large number.\n");
        return 1;
    }
}
