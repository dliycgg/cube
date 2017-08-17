#include "cube.h"
extern ArI ChgLocCorner,ChgLocLine;

void relocate(int a[], int b[], int flag) {
    ForBackRotate(a, 3, flag);
    ForBackRotate(b, 2, flag);
}

void ForBackRotate(int a[],int p, int fbrflag){
    int i,k,*pa,sa[4];
	for(i=0;i<4;i++)
		sa[i]=a[i];
    if (fbrflag == 6){
	    if(3==p){
	    	a[0]=sa[2];
	    	a[1]=sa[0];
	    	a[2]=sa[3];
	    	a[3]=sa[1];
	    }
	    else{
	    	int temp=a[0];
	    	for(i=0;i<3;i++)
	    		a[i]=a[i+1];
	    	a[3]=temp;
	    }
    }
    else{
	    if(3==p)pa=ChgLocCorner;
	    else pa=ChgLocLine;
        if (fbrflag == 8){ 
	        for(i=0;i<4;i++){
	        	k=*(pa+3-i);
	        	a[k]=(*(pa+7-i)+sa[i])%p;
                } 
        }
        else{ //if(fbrflag == 2) 
	        for(i=0;i<4;i++){
	        	k=*(pa+3-i);
	        	a[i]=(sa[k]-*(pa+7-i));
	        	if(a[i]<0)a[i]+=p;
            }
        }
    }
}

