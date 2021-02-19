#include<graphics.h>
#include<iostream>
#include<dos.h>
#include<conio.h>
#include<fstream>
#include<math.h>
#include<string.h>
#include<cstdlib>
#include<ctime>
using namespace std;

void reseter();
void saver(int);
void loadgame();
void questionchooser(int );

char solid[9][9][1000],sudoku[9][9],question[9][9],answer[9][9],ch,e,c,d,f;
int i=0,j=0,r,flag=0,flag1=1,gd=DETECT,gm,flag4=0,flag5=0,x=120,y=30,flag2=0,flag6=0,k,l,flag0[9][9],coun=0,counter=0,timer=0,;

int main()
{

for(i=0;i<9;i++)
{
	for(j=0;j<9;j++)
	{
		flag0[i][j]=0;				//	used for specifying whether i,j th element of sudoku is a part of question or not
	}
}

initgraph(&gd,&gm,"c:\\tc\\bgi");

			setcolor(LIGHTCYAN);
			outtextxy(250,200,"NEW GAME");
			outtextxy(250,250,"LOAD GAME");
			rectangle(240,240,340,270);
			outtextxy(250,300,"EXIT GAME");				//used to make user selective options to show various options
			rectangle(240,290,340,320);
			setcolor(LIGHTRED);
			rectangle(240,190,340,220);
i=0;
				while(1)
				{
				c=getch();
								if(c==KEY_DOWN&&i!=2)
								{
								setcolor(LIGHTCYAN);
								rectangle(240,190+50*i,340,220+50*i);
								setcolor(LIGHTRED);
								i++;
								rectangle(240,190+50*i,340,220+50*i);
								}
																				// helpful for visibility of navigation
								else if(c==KEY_UP&&i!=0)
								{
								setcolor(LIGHTCYAN);
								rectangle(240,190+50*i,340,220+50*i);
								setcolor(LIGHTRED);
								i--;
								rectangle(240,190+50*i,340,220+50*i);
								}

					else if(c=='\r')
					{
						if(i==0)									//if new game option is chosen
						{
						cleardevice();
						setcolor(LIGHTCYAN);
						outtextxy(250,200,"EASY");
						outtextxy(250,250,"MEDIUM");
						rectangle(240,240,340,270);					//then selection of difficulty level is provided to user followed by navigation
						outtextxy(250,300,"HARD");
						rectangle(240,290,340,320);
						setcolor(LIGHTRED);
						rectangle(240,190,340,220);
							j=0;
							while(1)
							{
								d=getch();
								if(d==KEY_DOWN&&j!=2)
								{
								setcolor(LIGHTCYAN);
								rectangle(240,190+50*j,340,220+50*j);
								setcolor(LIGHTRED);
								j++;
								rectangle(240,190+50*j,340,220+50*j);
								}
								else if(d==KEY_UP&&j!=0)
								{
								setcolor(LIGHTCYAN);
								rectangle(240,190+50*j,340,220+50*j);
								setcolor(LIGHTRED);
								j--;
								rectangle(240,190+50*j,340,220+50*j);
								}
								else if(d=='\r')
								{
									d=' ';
									r=j;
									flag6=1;
									break;
								}
							}
							questionchooser(r);				// appropriate question is chosen according to the value of r at which option enter is pressed
						}

						else if(i==1)
						{
							cleardevice();
							setcolor(LIGHTCYAN);
							outtextxy(250,200,"EASY");
							outtextxy(250,250,"MEDIUM");		//if load game is chosen followed by its navigation
							rectangle(240,240,340,270);
							outtextxy(250,300,"HARD");
							rectangle(240,290,340,320);
							setcolor(LIGHTRED);
							rectangle(240,190,340,220);
								j=0;
								while(1)
								{
									d=getch();
									if(d==KEY_DOWN&&j!=2)
									{
									setcolor(LIGHTCYAN);
									rectangle(240,190+50*j,340,220+50*j);
									setcolor(LIGHTRED);
									j++;
									rectangle(240,190+50*j,340,220+50*j);
									}
									else if(d==KEY_UP&&j!=0)
									{
									setcolor(LIGHTCYAN);
									rectangle(240,190+50*j,340,220+50*j);
									setcolor(LIGHTRED);
									j--;
									rectangle(240,190+50*j,340,220+50*j);
									}
									else if(d=='\r')
									{
										d=' ';
										r=j;
										flag6=1;
										break;
									}
								}
						questionchooser(r);			//question is entered in 2d array sudoku first
						loadgame();					//then saved game is loaded
						break;
						}

						else if(i==2)
						{
						exit(0);			//if exit is chosen
						}

					}
					if(flag6==1)
					{
					break;
					}
				}

							cleardevice();

setlinestyle(0,0,1);
								for(i=0;i<18;i++)
								{
								setcolor(WHITE);
								cleardevice();
								outtextxy(250,200,"Loading...");
								setcolor(LIGHTBLUE);
								circle(350,210,7);
								circle(350,210,9);
								setcolor(LIGHTCYAN);
								circle(350+7*cos(i),210+7*sin(i),1);
								circle(350+7*cos(i+0.1*3),210+7*sin(i+0.1*3),1);
								circle(350+7*cos(i+0.2*3),210+7*sin(i+0.2*3),1);
								circle(350+7*cos(i+0.3*3),210+7*sin(i+0.3*3),1);
								circle(350+7*cos(i+0.4*3),210+7*sin(i+0.4*3),1);
								circle(350+7*cos(i+0.5*3),210+7*sin(i+0.5*3),1);
								delay(100);
								}
								cleardevice();
	c=' ';

	setlinestyle(1,0,5);
for(i=0;i<10;i++)
{
	if(i%3==0)
	{
	setcolor(LIGHTGREEN);
	}
	else									//for making outer matrix of sudoku that is outline
	{
	setcolor(WHITE);
	}
line(100+50*i,10,100+50*i,460);
line(100,10+50*i,550,10+50*i);
}

for(i=0;i<9;i++)
{
	for(j=0;j<9;j++)
	{
		if(flag0[i][j]==1)
		{
		setcolor(YELLOW);		//	different colour for question and answer
		}
		else
		{
		setcolor(LIGHTGREEN);
		}
	c=sudoku[i][j];
	outtextxy(120+50*i,30+50*j,&c);		//printing number on graphics window
	}
}

	setcolor(LIGHTGREEN);

while(1)
{
	if(x>=120||flag5!=1)
	{
	outtextxy(x-5,y,"-");					//making cursor visible
	}
	for(i=0;i<2;i++)
		{
			for(j=0;j<9;j++)
			{
				outtextxy(15+50*i,30+50*j,"  ");
			}
		}															//for erasing traces of cursor
		for(i=0;i<2;i++)
		{
			for(j=0;j<9;j++)
			{
				outtextxy(565+50*i,30+50*j,"  ");
			}
		}

setcolor(LIGHTCYAN);
rectangle(10,20,60,50);
outtextxy(20,30,"SAVE");
rectangle(10,80,90,120);
outtextxy(15,90,"RESET->>r");
rectangle(560,20,610,50);
outtextxy(570,30,"Check");
rectangle(555,70,630,100);
outtextxy(560,80,"UNDO->>u");
rectangle(10,150,90,190);
outtextxy(15,160,"Restart->m");

	while(!(c=getch()))
	{
	timer++;
	}

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			solid[i][j][counter]=sudoku[i][j];			//storing 2d array sudoku[][] as sclices in 3d array for the sake of undo
		}
	}

setcolor(LIGHTGREEN);
for(i=0;i<9;i++)
{
	for(j=0;j<9;j++)
	{
	outtextxy(115+50*i,25+50*j," ");
	}
}

	if(c==KEY_UP&&y>30)
	{
		if(flag==1&&flag1==0)
		{
		outtextxy(x-5,y,"  ");
		flag=0;
		}
	y=y-50;
	outtextxy(x-5,y,"-");
	flag=1;
	}
	else if(c==KEY_DOWN&&y<410)
	{
		if(flag==1&&flag1==0)
		{
		outtextxy(x-5,y,"  ");
		flag=0;
		}
	y=y+50;
	outtextxy(x-5,y,"-");
	flag=1;
	}
	else if(c==KEY_RIGHT&&x<500)
	{
		if(flag==1&&flag1==0)
		{
		outtextxy(x-5,y,"  ");
		flag=0;
		}									//useful for navigation (for up down left right
	x=x+50;
	outtextxy(x-5,y,"-");
	flag=1;
	}
	else if(c==KEY_LEFT&&x>120)
	{
		if(flag==1&&flag1==0)
		{
		outtextxy(x-5,y,"  ");
		flag=0;
		}
	x=x-50;
	outtextxy(x-5,y,"-");
	flag=1;
	}

	else if(c=='\b'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=' ';
		outtextxy(x,y,"  ");
		flag=0;										//for deleting a character
		flag1=1;
	}

	else if(c=='1'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"1");
		flag=0;
		flag1=1;
	}

	else if(c=='2'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"2");
		flag=0;
		flag1=1;
	}

	else if(c=='3'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x-5,y," ");
		outtextxy(x,y,"3");
		flag=0;
		flag1=1;
	}

	else if(c=='4'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"4");
		flag=0;
		flag1=1;
	}

	else if(c=='5'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"5");
		flag=0;
		flag1=1;
	}

	else if(c=='6'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"6");
		flag=0;
		flag1=1;
	}

	else if(c=='7'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"7");
		flag=0;
		flag1=1;
	}

	else if(c=='8'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"8");
		flag=0;
		flag1=1;
	}

	else if(c=='9'&&flag0[(x-100)/50][(y-10)/50]==0)
	{
		sudoku[(x-100)/50][(y-10)/50]=c;
		outtextxy(x,y,"9");
		flag=0;
		flag1=1;
	}

	else if(flag0[(x-100)/50][(y-10)/50]!=0)
	{
		outtextxy(x-5,y,"-");
	}

	else if(c=='e')
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(sudoku[i][j]!=answer[i][j])
				{
					cout<<"\n";
					cout<<"your answer is wrong"<<endl;
					flag4=1;
					break;
					cout<<"\n";
				}
				else if(i==8&&j==8)
				{
					cout<<"\n";
					cout<<"your answer is correct"<<endl;
					cout<<"\n";
				}
			}
			if(flag4==1)
			{
			break;
			}
		}
	}

	else if (c=='v')
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
			cout<<sudoku[i][j];		//for viewing current state of sudoku
			}
		cout<<"\n";
		}
	}

	else if(c=='u')
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
			if(flag0[i][j]==1)
			{
				setcolor(YELLOW);
			}
			else
			{
				setcolor(LIGHTGREEN);
			}
				sudoku[i][j]=solid[i][j][counter-1];
				c=sudoku[i][j];									//locating slice and making sudoku the 2d array equal to it and printing it
				outtextxy(120+50*i,30+50*j,&c);
			}
		}
	}

	else if (c==KEY_LEFT)
	{
		setlinestyle(1,0,5);
		setcolor(LIGHTRED);
		rectangle(9,19,61,51);
		setlinestyle(1,0,1);
		flag5=1;
		setcolor(BLACK);			//for the sake of selecting option save

		if(getch()=='\r')
		{
			saver(r);
		}
	}

	else if (c==KEY_RIGHT)
	{
		setlinestyle(1,0,5);
		setcolor(LIGHTRED);
		rectangle(559,19,611,51);
		setlinestyle(1,0,1);
		flag5=1;
		setcolor(BLACK);				//for the sake of selecting option end

		if(getch()=='\r')
		{
			for(i=0;i<9;i++)
			{
				for(j=0;j<9;j++)
				{
					if(sudoku[i][j]!=answer[i][j])
					{
						cout<<"\n";
						cout<<"your answer is wrong"<<endl;
						flag4=1;
						break;
						cout<<"\n";
					}

					else if(i==8&&j==8)
					{
						cout<<"\n";
						cout<<"your answer is correct"<<endl;
						cout<<"\n";
					}
				}
				if(flag4==1)
				{
				break;
				}
			}

				exit(0);
		}
	}
	else if(c=='m')
	{
	cleardevice();
		closegraph();
		int i=0;
		j=0;
		flag=0;
		flag1=1;
		flag4=0;
		flag5=0;
		x=120;
		y=30;
		flag2=0;
		flag6=0;
		coun=0;
		counter=0;
		timer=0;
		main();
	}
	else if(c=='r')
	{
		reseter();						//for reseting whole question which will result question to start from beginning
	}
	else if(c=='p')
	{
	cleardevice();
	outtextxy(325,255,"GAME PAUSED");	//option for pausing the game
	}
	else if(c=='c')
	{
	cleardevice();
		for(i=0;i<10;i++)			//for continue or resume the game
		{
		if(i%3==0)
		{
		setcolor(LIGHTGREEN);
		}
		else
		{
		setcolor(WHITE);
		}
		line(100+50*i,10,100+50*i,460);
		line(100,10+50*i,550,10+50*i);
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				if(flag0[i][j]==1)
				{
				setcolor(YELLOW);
				}
				else
				{
				setcolor(LIGHTGREEN);
				}
			c=sudoku[i][j];
			outtextxy(120+50*i,30+50*j,&c);
			}
		}
	}
	if(c!='u')
	{
		counter++;		//incrementing slice number
	}
	if (c==KEY_RIGHT&&flag5==1)
	{
		flag5=0;
		setcolor(BLACK);
		setlinestyle(1,0,5);
		rectangle(9,19,81,51);
        setcolor(LIGHTGREEN);
		outtextxy(x-5,y," ");
	}
	if (c==KEY_LEFT&&flag5==1)
	{
		flag5=0;
		setcolor(BLACK);
		setlinestyle(1,0,5);
		rectangle(9,19,81,51);
        setcolor(LIGHTGREEN);
		outtextxy(x-5,y," ");
	}
}
closegraph();
return 0;
}

void questionchooser(int x)		//function which depends on the number passed as arguement
{
char que[7],ans[7];
switch(x)
{
	case 0:strcpy(que,"q0.txt");
			strcpy(ans,"a0.txt");
			break;
	case 1:strcpy(que,"q1.txt");			//storing names in string que and ans of files having question and answer
			strcpy(ans,"a1.txt");			//various cases corresponding to different values corresponding to arguement
			break;
	case 2:strcpy(que,"q2.txt");
			strcpy(ans,"a2.txt");
			break;
}
fstream fin(que, fstream::in);
while (fin >> noskipws >> ch)
{
    l=coun%9;
	k=coun/9;
	question[k][l]=ch;						//opening the file with que as question
	if(ch!=' ')
	{
	flag0[k][l]=1;
	}
	sudoku[k][l]=ch;
    coun++;
 }
fin.close();
coun=0;
fstream fin1(ans, fstream::in);
while (fin1 >> noskipws >> e)
{
    l=coun%9;
	k=coun/9;
	answer[k][l]=e;							//opening the file with ans as answer
    coun++;
 }
fin1.close();
}

void saver(int r)							//function which is called when enter is pressed after placing cursor on save option in run window
{
		if(r==0)
			{
			ofstream File1("save0.txt");

				for(i=0;i<9;i++)
				{
					for(j=0;j<9;j++)
					{
						File1<<sudoku[i][j];
						File1<<"";
					}
				}
				File1.close();
			}
		else if(r==1)
			{
			ofstream File2("save1.txt");

				for(i=0;i<9;i++)
				{
					for(j=0;j<9;j++)			//depending on level chosen file saving data changes and it is also dependent on same arguement as that of
					{							//	the function questionchooser
						File2<<sudoku[i][j];
						File2<<"";
					}
				}
				File2.close();
			}
		else if(r==2)
			{
			ofstream File3("save2.txt");

				for(i=0;i<9;i++)
				{
					for(j=0;j<9;j++)
					{
						File3<<sudoku[i][j];
						File3<<"";
					}
				}
				File3.close();
			}
}
void loadgame()
{

	if(r==0)
	{
		ifstream File4("save0.txt");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudoku[i][j]=File4.get();
			}
		}
		File4.close();
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
			setcolor(YELLOW);
			c=sudoku[i][j];
			outtextxy(120+50*i,30+50*j,&c);
			}
		}
	}
	else if(r==1)
	{
		ifstream File4("save1.txt");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudoku[i][j]=File4.get();		// loads the saved file if it is loaded
			}
		}
		File4.close();
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
			setcolor(YELLOW);
			c=sudoku[i][j];
			outtextxy(120+50*i,30+50*j,&c);
			}
		}
	}
	else if(r==2)
	{
		ifstream File4("save2.txt");
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				sudoku[i][j]=File4.get();
			}
		}
		File4.close();
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
			setcolor(YELLOW);
			c=sudoku[i][j];
			outtextxy(120+50*i,30+50*j,&c);
			}
		}
	}
}

void reseter()
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
		sudoku[i][j]=question[i][j];
		c=question[i][j];			//this function resets the sudoku by making 2d array sudoku equal to 2d array question
		setcolor(YELLOW);
		outtextxy(120+50*i,30+50*j,&c);
		setcolor(LIGHTGREEN);
		}
	}
}
