#include "cube.h"

int mygetch( ) {
	struct termios oldt,newt;
	int ch;
	tcgetattr( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );//不回显
	tcsetattr( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
}

//**************************************************

int ReadFromText(int line){    
	FILE* fptr; 
    int i;
	int Nline=0; 
	extern int CLCornerNum,CLLineNum;   
    fptr = fopen("actlist.txt", "r");  
    if (fptr == NULL)  
    {  
        printf("Cannot Open file for reading\n");  
        return -1;  
    }   
	for ( i=0 ; i <line; i++)  
		fscanf(fptr, "%d %d %d\n", &Nline, &CLCornerNum, &CLLineNum);  
	printf("%d: %d %d %ld\n", Nline, CLCornerNum, CLLineNum, ftell(fptr));
    fclose(fptr);  
    return 0;  
}

//**************************************************

void dis(int a[],int b[]){
	typedef char SArCh[4];
	int i;
	SArCh c1,c2,c3,l1,l2;
	for(i=0;i<4;i++){
		c1[i]=l1[i]='*';
		c2[i]=c3[i]=l2[i]='.';
		if(a[i]==0)
			c1[i]='O';
		else if((a[i]==1&&(i==0||i==3))||(a[i]==2&&(i==1||i==2)))
			c2[i]='|';
			else if(i==0||i==1)
				c3[i]='_';
				else 
				    c3[i]='-';
		if(b[i]==0)
			l1[i]='O';
		else if(i==0)
				l2[i]='_';
			 else 	if(i==2)
				l2[i]='-';
					else 
						l2[i]='|';	
	}
	printf(" %c%c%c\n",c3[0],l2[0],c3[1]);
	printf("%c%c%c%c%c\n",c2[0],c1[0],l1[0],c1[1],c2[1]);
	printf("%c%cO%c%c\n",l2[1],l1[1],l1[3],l2[3]);
	printf("%c%c%c%c%c\n",c2[2],c1[2],l1[2],c1[3],c2[3]);
	printf(" %c%c%c\n",c3[2],l2[2],c3[3]);
}
