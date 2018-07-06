#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
static int matris[100][100];
static int length[100];
static int matrisYedek[100][100];
void sifirla()
{
    int i,j;
    for(i=0;i<100;i++)
    {
        length[i]=0;
            for(j=0;j<100;j++)
            {
                matrisYedek[i][j]=0;
                matris[i][j]=0;
            }
    }
}
void gotoxy(int x, int y)
{
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}
int main()
{
    sifirla();
    int a=0,k=0,tmp=0,ifGiris=0,bos=0,ortadami=0;
    int b=0,i,j,l,satir=1,kaydet=0;
    while(1)
    {
    	matris[a][b]=getch();
		//Ok tuslarýný kontrol ettirmek için
		if(matris[a][b]==224)
		{
        matris[a][b]=matrisYedek[a][b];
        matris[a][b]=getch();
        ifGiris=1;
        k=1;
        //Yukarý ok tusu
        if(matris[a][b]==72&&k==1)
		{
		matris[a][b]=0;
		matris[a][b]=matrisYedek[a][b];
        	if(b>length[a-1]-1&&a!=0){
        		a--;
        		b=length[a];
        		b--;
				gotoxy(b,a);
			}
			else if(a==0)
			{
				gotoxy(b,a);
				continue;
			}
			else if(b<=length[a-1]-1&&a!=0)
			{
				a--;
				b--;
				gotoxy(b,a);
			}//gotoxy(10,10);
        	//printf("matris(%d)(%d) : %c",a,b,matris[a][b]);
		}//Aþaðý ok tuþu
        else if(matris[a][b]==80&&k==1)
		{
			matris[a][b]=0;
			matris[a][b]=matrisYedek[a][b];
        	if(b>=length[a+1]&&a!=satir-1){
        		a++;
        		b=length[a];
        		b--;
				gotoxy(b,a);
			}
			else if(a==satir-1)
			{
				gotoxy(b,a);
				continue;
			}
			else
			{
				a++;
				b--;
				gotoxy(b,a);
			}
				//printf("matris(%d)(%d) : %c",a,b,matris[a][b]);
		}
        //Sol ok tuþu
        else if(matris[a][b]==75&&k==1)
        {
            ifGiris=1;
            matris[a][b]=0;
            matris[a][b]=matrisYedek[a][b];
            if(b<=length[a] && b!=0){
                b-=2;
                gotoxy(b,a);
            }
            else if(b==0 && a!=0){
                a--;
                b=length[a]-1;
                gotoxy(b,a);
            }
            else if(b==0 && a==0)
            {
            	b=0;
            	a=0;
                gotoxy(0,0);
                continue;
            }
            int l;
            for(l = 0 ; l < length[a]+3 ; l++)
            matris[a][l]=matrisYedek[a][l];
        //gotoxy(10,10);
        //printf("Left");
        }
        //Sag ok tusu
        else if(matris[a][b]==77&&k==1)
		{
			matris[a][b]=0;
			matris[a][b]=matrisYedek[a][b];
			if(b<length[a]&&b>=0){
				gotoxy(b,a);
			}
			else if(b==length[a]&&a!=satir-1)
			{
				a++;
				b=-1;
				gotoxy(b,a);
			}
			else if(b==length[a]&&a==satir-1)
			{
				gotoxy(b,a);
				continue;
			}
			for(l = 0 ; l < length[a]+3 ; l++)
            matris[a][l]=matrisYedek[a][l];
        //gotoxy(10,10);
        //printf("Right");
		}
		}
		else if(matris[a][b]==0)
		{
			matris[a][b]=getch();
			if(matris[a][b]==60)
        {
        	kaydet=1;
        	ifGiris=1;
        	matris[a][b]=0;
        	matris[a][b]=matrisYedek[a][b];
        	gotoxy(length[satir-1],satir-1);
        	gotoxy(b,a);
        	printf("%c",matris[a][b]);
			FILE *f = fopen("output.txt", "w+");
            int z,y;
            for(z=0; z<satir ; z++)
            {
                for(y=0; y<=length[z]; y++)
                {
                	if(matris[z][y]!=0)
   					{
                    fprintf(f, "%c",matris[z][y]);
                    if(matris[z][y]==13)
                    fprintf(f, "\n");
            		}
				}
            }gotoxy(length[a],satir-1);
            break;
            
        }
        else if(matris[a][b]==59)
		{
			kaydet=1;
			system("cls");
			sifirla();
			a=0;
			b=0;
			gotoxy(0,0);
		}
        else if(matris[a][b]==61)
        {
        	int degisken=0,degisken2=0,i,j;
        	kaydet=1;
        	system("cls");
        	a=0;
        	b=0;
        	satir=1;
        	sifirla();
        	gotoxy(b,a);
        	char c;
 			FILE *f = fopen("output.txt", "r+");
 			if (f) {
   				while ((c = getc(f)) != EOF)
   				{
   					gotoxy(b,a);
					if(c=='\n')
        			{
        			degisken=1;
        			matris[a][b]=0;
        			matrisYedek[a][b]=0;
        			matris[a][b]=13;
        			matrisYedek[a][b]=matris[a][b];
        			length[a]=b;
        			satir++;
        				b=0;
        				a++;
					}
					else
					{
					matris[a][b]=c;
        			matrisYedek[a][b]=matris[a][b];
        			printf("%c",c,matris[a][b]);
        			b++;
        			degisken2=b;
        			length[a]++;
					}			
				}
			  	/*gotoxy(0,0);
				for(i=0;i<satir;i++)
				{
					for(j=0;j<length[i];j++)
					{
					gotoxy(j,i);
						printf("%c",matris[i][j]);
					}
				}*/
        		gotoxy(b,a);
				fclose(f);
			}
    	}
		}
		else if(ifGiris!=1)
		{
			if(b!=length[a]&&matris[a][b]!=8&&matris[a][b]!=27&&matris[a][b]!=13&&matris[a][b]!=83){
				
				ortadami=1;
				tmp=0;
				bos=0;
				b++;
				length[a]++;
					for(i=length[a];i>=b;i--)
				{
					matris[a][i]=0;
					tmp=0;
					tmp=matrisYedek[a][i-1];
                	matris[a][i]=tmp;
                	tmp=0;
                	matrisYedek[a][i]=0;
                	matrisYedek[a][i]=matris[a][i];
                	gotoxy(i,a);
            		printf("%c",matris[a][i]);
				}
				matrisYedek[a][b-1]=0;
				matrisYedek[a][b-1]=matris[a][b-1];
				gotoxy(b-1,a);
				printf("%c",matris[a][b-1]);
			  /*gotoxy(b,a);
				gotoxy(20,20);
				printf("\n                                 %d %d : %c",a,b-4,matrisYedek[a][b-4]);
				printf("\n                                 %d %d : %c",a,b-3,matrisYedek[a][b-3]);
				printf("\n                                 %d %d : %d",a,b-2,matrisYedek[a][b-2]);
				printf("\n                                 %d %d : %d",a,b-1,matrisYedek[a][b-1]);
				printf("\n                                 %d %d : %d",a,b,matrisYedek[a][b]);
				printf("\n                                 %d %d : %d",a,b+1,matrisYedek[a][b+1]);
				printf("\n                                 %d %d : %d",a,b+2,matrisYedek[a][b+2]);
				printf("\n                                 %d %d : %d",a,b+3,matrisYedek[a][b+3]);
				printf("\n                                 %d %d : %d",a,b+4,matrisYedek[a][b+4]);*/
			}
			else if(matris[a][b]!=8&&ortadami!=1&&matris[a][b]!=27&&matris[a][b]!=13)
			{
				matrisYedek[a][b]=matris[a][b];
			}
			gotoxy(b,a);
			printf("%c",matris[a][b]);
		}
			//gotoxy(b,a);
			//printf("                                 %d %d : %c",a,b,matrisYedek[a][b]);
        if(matris[a][b]==13)
        {
			gotoxy(b,a);
			matris[a][b]=13;
        	if(b<length[a])
            {
            ifGiris=1;
			gotoxy(b,a);
				satir++;
				for(i=satir-2;i>a;i--)
                {
						tmp=length[i];
                	 	length[i+1]=tmp;
                	 for(j=0;j<100;j++)
                		{
                			tmp=0;
                			tmp=matrisYedek[i][j];
                			matris[i+1][j]=0;
                	 		matris[i+1][j]=tmp;
                	 		matrisYedek[i+1][j]=0;
                	 		matrisYedek[i+1][j]=matris[i+1][j];
                	 		matris[i][j]=13;
                	 		//matrisYedek[i][j]=0;
                	 		gotoxy(j,i+1);
                	 		printf("%c",matris[i+1][j]);
                	 		gotoxy(j,i);
                	 		printf("%c",matris[i][j]);
                		}matris[i][length[i]]=13;
						}
						length[a+1]=0;
                for(i=b;i<100;i++)
            	{
            		tmp=0;
            		matris[a+1][i-b]=0;
            		tmp=matrisYedek[a][i];
            		matris[a+1][i-b]=tmp;
            		matris[a][i]=0;
            		//matrisYedek[a][i]=0;
            		//matrisYedek[a+1][i-b]=0;
            		//matrisYedek[a+1][i-b]=matris[a+1][i-b];
            		gotoxy(i-b,a+1);
            		printf("%c",matris[a+1][i-b]);
            		gotoxy(i,a);
            		printf("%c",matris[a][i]);
				}
				length[a]=length[a]-b;
				length[a+1]=b;
				matris[a][length[a]]=13;
				a++;
				gotoxy(0,a);
            }
            else
            {
        		satir++;
            	matrisYedek[a][b]=13;
        		ifGiris=0;
				length[a]=b;
            	a++;
            	b=0;
            	/*gotoxy(20,20);
            	printf("satir :%d",satir);*/
            	gotoxy(b,a);
			}
        }
        //EXIT
        else if(matris[a][b]==27)
        {
        	matris[a][b]=0;
        	matris[a][b]=matrisYedek[a][b];
        	gotoxy(b,a);
        	printf("%c",matris[a][b]);
        	gotoxy(length[satir-1],satir-1);
        	break;
		}
		//delete
		else if(matris[a][b]==83)
		{
		ifGiris=1;
			if(b<length[a])
			{
				matris[a][b]=0;
            	matrisYedek[a][b]=0;
				for(i=b;i<length[a];i++)
            	{	matris[a][i]=0;
            		matris[a][i]=matris[a][i+1];
            		matrisYedek[a][i]=0;
            		matrisYedek[a][i]=matrisYedek[a][i+1];
           			//printf("%c",matrisYedek[a][i]);
           			gotoxy(i,a);
            		printf("%c",matrisYedek[a][i]);
            	}
            	matris[a][length[a]]=0;
            	matrisYedek[a][length[a]]=0;
            	gotoxy(length[a],a);
            	printf(" ",matris[a][i]);
				length[a]--;
            	gotoxy(b,a);
			}
			else if(b==0&&a==0)
			{
				gotoxy(0,0);
				printf(" ");
				gotoxy(0,0);
				b==0;
			}
			else if(b==length[a]&&a!=satir-1)
			{
                matris[a][b]=0;
            	matrisYedek[a][b]=0;
				for(i=length[a];i<=length[a]+length[a+1];i++)
            	{
            		tmp=0;
            		tmp=matris[a+1][i-length[a]];
            		matris[a][i]=tmp;
            		matris[a+1][i-length[a]]=0;
            		matrisYedek[a+1][i-length[a]]=0;
            		matrisYedek[a][i]=0;
            		matrisYedek[a][i]=matris[a][i];
            		gotoxy(i,a);
            		printf("%c",matrisYedek[a][i]);
            		gotoxy(i-length[a],a+1);
            		printf("%c",matrisYedek[a+1][i-length[a]]);
				}
				length[a]=length[a]+length[a+1];
				length[a+1]=0;
				for(i=a+1;i<satir;i++)
                {
						tmp=length[i+1];
                	 	length[i]=tmp;
                	 for(j=0;j<100;j++)
                		{
                			tmp=0;
                			tmp=matris[i+1][j];
                			matris[i][j]=0;
                	 		matris[i][j]=tmp;
                	 		matrisYedek[i][j]=0;
                	 		matrisYedek[i][j]=matris[i][j];
                	 		matris[i+1][j]=0;
                	 		matrisYedek[i+1][j]=0;
                	 		gotoxy(j,i);
                	 		printf("%c",matrisYedek[i][j]);
                	 		gotoxy(j,i+1);
                	 		printf("%c",matrisYedek[i+1][j]);
                		}
                	 length[i+1]=0;
				}
				satir--;
				gotoxy(b,a);
			}
		}
        //backspace
        else if(matris[a][b]==8)
        {
            if(b==0&&a>0)
            {
            	gotoxy(b,a);
            	
            	matris[a][b]=0;
				matris[a][b]=matrisYedek[a][b];
				b=length[a-1];
                a--;
                matris[a][b]=0;
            	matrisYedek[a][b]=0;
				for(i=length[a];i<=length[a]+length[a+1];i++)
            	{
            		tmp=0;
            		tmp=matris[a+1][i-length[a]];
            		matris[a][i]=tmp;
            		matris[a+1][i-length[a]]=0;
            		matrisYedek[a+1][i-length[a]]=0;
            		matrisYedek[a][i]=0;
            		matrisYedek[a][i]=matris[a][i];
            		gotoxy(i,a);
            		printf("%c",matris[a][i]);
            		gotoxy(i-length[a],a+1);
            		printf("%c",matris[a+1][i-length[a]]);
				}
				length[a]=length[a]+length[a+1];
				length[a+1]=0;
				//Satýrlarý yukarý yazdýr enterda aþaðý yazdýr halini kullan
				for(i=a+1;i<satir;i++)
                {
						tmp=length[i+1];
                	 	length[i]=tmp;
                	 	/*gotoxy(20,20+i);
                	 		printf("length[%d] : %d",i-2,length[i-2]);
                	 		printf("\nlength[%d] : %d",i-1,length[i-1]);*/
                	 for(j=0;j<100;j++)
                		{
                			tmp=0;
                			tmp=matris[i+1][j];
                			matris[i][j]=0;
                	 		matris[i][j]=tmp;
                	 		matrisYedek[i][j]=0;
                	 		matrisYedek[i][j]=matris[i][j];
                	 		matris[i+1][j]=0;
                	 		matrisYedek[i+1][j]=0;
                	 		gotoxy(j,i);
                	 		printf("%c",matris[i][j]);
                	 		gotoxy(j,i+1);
                	 		printf("%c",matris[i+1][j]);
                		}
                	 length[i+1]=0;
				}
				satir--;
				gotoxy(b,a);
            }
            else if(b==0&&a==0)
            {
            	gotoxy(0,0);
            	printf(" ");
            	gotoxy(0,0);
				continue;
            }
            else if(b==length[a])
            {
            	matris[a][b]=0;
           	    matrisYedek[a][b]=0;
           	    matrisYedek[a][b]=matris[a][b];
                printf(" ");
                b--;
                matris[a][length[a]-1]=0;
        		matrisYedek[a][length[a]-1]=0;
				length[a]--;
                gotoxy(b,a);
            }
            else
            {
                matris[a][b]=0;
                bos=matris[a][b];
				matris[a][b]=matrisYedek[a][b];
				//printf("                         a:%d b:%d matris : %c",a,b,matris[a][b]);
				b--;
                matris[a][b]=0;
				bos=matris[a][b];
				bos=0;
                matrisYedek[a][b]=0;
				for(i=b;i<length[a];i++)
                {
                	tmp=matris[a][i+1];
                	matris[a][i]=tmp;
            		matris[a][i+1]=0;
            		matrisYedek[a][i]=matrisYedek[a][i+1];
            		matrisYedek[a][i+1]=0;
					gotoxy(i,a);
            		//printf("%c",matrisYedek[a][i]);
            		printf("%c",matris[a][i]);
                }
				gotoxy(length[a]-1,a);
				matris[a][length[a]]=0;
        	    matrisYedek[a][length[a]]=0;
        	    printf("%c",matris[a][length[a]]);
			    length[a]--;
              }
			  matrisYedek[a][b]=matris[a][b];
              /*gotoxy(20,20);
			  printf("\n                         a:%d b:%d matris : %c",a,b-4,matrisYedek[a][b-4]);
				printf("\n                         a:%d b:%d matris : %c",a,b-3,matrisYedek[a][b-3]);
				printf("\n                         a:%d b:%d matris : %c",a,b-2,matrisYedek[a][b-2]);
				printf("\n                         a:%d b:%d matris : %c",a,b-1,matrisYedek[a][b-1]);
                printf("\n                         a:%d b:%d matris : %c",a,b,matrisYedek[a][b]);
				printf("\n                         a:%d b:%d matris : %c",a,b+1,matrisYedek[a][b+1]);
				printf("\n                         a:%d b:%d matris : %c",a,b+2,matrisYedek[a][b+2]);
				printf("\n                         a:%d b:%d matris : %c",a,b+3,matrisYedek[a][b+3]);
				printf("\n                         a:%d b:%d matris : %c",a,b+4,matrisYedek[a][b+4]);
			gotoxy(b,a);*/
			}
		else
		{
			if(kaydet!=1)
			{
			if(ortadami!=1)
			b++;
			if(ifGiris!=1&&ortadami!=1)
			length[a]++;
			ifGiris=0;
			gotoxy(b,a);
			}
		}
		gotoxy(40,satir+8);
		printf("                                              ");
		gotoxy(40,satir+7);
		printf("                                              ");
		gotoxy(40,satir+6);
		printf("--------------------------------------------");
		gotoxy(40,satir+5);
		printf("| F1->TEMIZLE F2->KAYDET F3->AC ESC->CIKIS |",a,length[a]);
		gotoxy(40,satir+4);
		printf("--------------------------------------------");
		gotoxy(40,satir+3);
		printf("                                              ");
		gotoxy(40,satir+2);        
		printf("                                              ");
		gotoxy(b,a);
		kaydet=0;
		ortadami=0;
    }
    getch();
    return 0;
}