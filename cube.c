#include "cube.h"
#include "s2a.h"
ArI ChgLocCorner, ChgLocLine;
int CLCornerNum, CLLineNum;
int main (void){
	ArI NPos;
	SArI PoseCorner, PoseLine;
	int i, ActRange = 1, ActNum, ShowNPosNum;
	char ch;//, sw = 1
	for (i = 0; i < 4; i++) PoseCorner[i] = PoseLine[i] = 0;	
	for (i = 0; i < 8; i++) NPos[i] = ChgLocCorner[i] = ChgLocLine[i] = 0;
	for (i = 0; i < 3; i++) ChgLocCorner[i] = ChgLocLine[i] = 3-i;
	while (ActRange){
		ShowNPosNum = 1;
		printf ("select 1p 3a 8t 2r 6g  ： ");
		ch = mygetch ();
        ActNum = ch - '0';
		printf ("%c\n", ch);
		switch (ActNum){
            case 1:	{ //{}cannot be omitted?
				int NPosNum, temp;				
				printf ("Normal Pose(refer OLL charts,0:loaded): ");
				scanf ("%d", &NPosNum);
				while (getchar () != '\n');
				s2a (NPos, NPosNum, 8);
				
                /*reading habit is continuous from 1 to 8, 
                  so adjust corner elements from 1 3 6 8, line elements from 2 4 5 7 */
                temp = NPos[3];
				for (i = 3;i > 0;i--)
					NPos[i] = NPos[i-1];
				NPos[0] = temp;
				for (i = 0;i < 4;i++){
			 		PoseCorner[i] = NPos[7-2*i];
			 		PoseLine[i] = NPos[6-2*i];
				}	
                
		        ShowNPosNum = 0;
				break;
			}
			case 3:{
				int line = 0;
				SArI ChgCorner, ChgLine;
				printf ("ChangeChart(0 only for check):");
				scanf ("%d", &line);
				while (getchar () != '\n');
				ReadFromText (line);
				s2a (ChgLocCorner, CLCornerNum, 8);
				s2a (ChgLocLine, CLLineNum, 8);
			 	for (i = 0;i < 4;i++)
			 		ChgCorner[i] = ChgLine[i] = 0;
                relocate(ChgCorner, ChgLine, 2);
				dis (ChgCorner, ChgLine);
				break;
			}
			case 8: 
			case 2:
			case 6: 
		        relocate(PoseCorner, PoseLine, ActNum);	
				break;
			case 5: 
		        relocate(PoseCorner, PoseLine, 6);	
		        relocate(PoseCorner, PoseLine, 6);	
				break;
            default:
                ShowNPosNum = 0;
                ActRange = 0;
		}

        /* reverse to reading habit continuous */
		if (ShowNPosNum){
			for (i = 0;i < 4;i++){
				if (i == 2)
					printf ("%d ", PoseLine[3]); 
				printf ("%d ", PoseCorner[i]);
				if (i != 3) printf ("%d ", PoseLine[i]);
			}
			printf ("\n");
		}

		if (ActRange) dis (PoseCorner, PoseLine);						
	}
	return 0;
}
