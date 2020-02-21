#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;
char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';
bool posAvailable(int c);
void Draw()
{
	int i,j;
	system("cls");
	cout << "		";
	cout << "-------------" << endl;
	for (i=0;i<3;i++)
	{	cout << "		";
		for (j=0;j<3;j++)
		{
			cout <<	"| " << matrix [i][j] << " ";
		}
		
		cout <<	"|" << endl;
			cout << "		";
		cout << "-------------" << endl;
	
	}
}

void markOnAnyBox(){
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++)
		{
			if (matrix[i][j]!='X' && matrix[i][j] != 'O'){
				matrix[i][j] = 'O';
				return;
			}
		}
	}
}
						
char Win()
{
	// for 1st row
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
	{
		return 'X';
	}
	
	else if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
	{
		return 'O';
	}
	
	// for 2nd row
	else if (matrix[1][0] == 'X' && matrix [1][1] == 'X' && matrix[1][2] == 'X')
	{
		return 'X';
	}
	
	else if (matrix[1][0] == 'O' && matrix [1][1] == 'O' && matrix[1][2] == 'O')
	{
		return 'O';
	}

	// for 3rd row
	else if (matrix[2][0] == 'X' && matrix [2][1] == 'X' && matrix[2][2] == 'X')
	{
		return 'X';
	}

	else if (matrix[2][0] == 'O' && matrix [2][1] == 'O' && matrix[2][2] == 'O')
	{
		return 'O';
	}	
	
	// for 1st column
	
	else if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
	{
		return 'X';
	}
	
	else if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
	{
		return 'O';
	}
	
	// for 2nd column
	
	else if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
	{
		return 'X';
	}

	else if (matrix[0][1] == 'O' && matrix [1][1] == 'O' && matrix[2][1] == 'O')
	{
		return 'O';
	}	
	
	// for 3rd column
	
	else if (matrix[0][2] == 'X' && matrix [1][2] == 'X' && matrix[2][2] == 'X')
	{
		return 'X';
	}

	else if (matrix[0][2] == 'O' && matrix [1][2] == 'O' && matrix[2][2] == 'O')
	{
		return 'O';
	}
	
	// for diagonals
	
	else if (matrix[0][0] == 'X' && matrix [1][1] == 'X' && matrix[2][2] == 'X')
	{
		return 'X';
	}

	else if (matrix[0][0] == 'O' && matrix [1][1] == 'O' && matrix[2][2] == 'O')
	{
		return 'O';
	}	
	
	else if (matrix[0][2] == 'X' && matrix [1][1] == 'X' && matrix[2][0] == 'X')
	{
		return 'X';
	}

	else if (matrix[0][2] == 'O' && matrix [1][1] == 'O' && matrix[2][0] == 'O')
	{
		return 'O';
	}	
	
	else
	{
		return 'Z';
	}
}

int MatchTie()
{
	int flag;
	int i,j;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			flag = 0;
			if (matrix[i][j] == 'X' || matrix [i][j] == 'O')
			{
				flag = 1;
			}
			else
			{
				return 0;
			}
		}
	}
	return flag;
}


void toggleplayer()
{
	if (player == 'X')
	{
		player = 'O';
	}
	else 
	{
		player = 'X';
	}
}

void play()
{	
	int choice;
	int flag=0;
	while (1)
	{
			Draw();
			if (flag == 1)
			{
				cout << "\nThe position has been already choosen.\nPlease choose a different position." << endl;
			}
		
			flag = 0;
			cout << "\n" << player << " turn : ";
			cin >> choice;
			cin.ignore();
		
			if (choice == 1)
			{
				if (matrix[0][0] == 'X' || matrix[0][0] == 'O')
				{				
					flag = 1;
				}
				else
				{
					matrix[0][0] = player;
				}
			}
				else if (choice == 2)
				{	
					if (matrix[0][1] == 'X' || matrix[0][1] == 'O')
					{
						flag = 1;
					}
					else 
					{
						matrix[0][1] = player;
					}
				}
					else if (choice == 3)
					{
						if (matrix[0][2] == 'X' || matrix[0][2] == 'O')
						{
							flag = 1;
						}	
						else 
						{
							matrix[0][2] = player;
						}
					}
						else if (choice == 4)
						{
							if (matrix[1][0] == 'X' || matrix[1][0] == 'O')
							{
								flag = 1;
							}
							else 
							{
								matrix[1][0] = player;
							}
						}
							else if (choice == 5)
							{
								if (matrix[1][1] == 'X' || matrix[1][1] == 'O')
								{
									flag = 1;
								}
								else 
								{
									matrix[1][1] = player;
								}
							}
								else if (choice == 6)
								{
									if (matrix[1][2] == 'X' || matrix[1][2] == 'O')
									{
										flag = 1;
									}
									else 
									{
										matrix[1][2] = player;
									}
								}
									else if (choice == 7)
									{
										if (matrix[2][0] == 'X' || matrix[2][0] == 'O')
										{
											flag = 1;
										}
										else 
										{
											matrix[2][0] = player;
										}
									}
										else if (choice == 8)
										{
											if (matrix[2][1] == 'X' || matrix[2][1] == 'O')
											{	
												flag = 1;
											}
											else 
											{
												matrix[2][1] = player;
											}
										}
											else if (choice == 9)
											{
												if (matrix[2][2] == 'X' || matrix[2][2] == 'O')
												{
													flag = 1;
													continue;
												}
												else 
												{
													matrix[2][2] = player;
												}
											}
		
	
			if (Win() == 'X')
			{
				system("cls");
				Draw();
				cout << "Player X wins !" << endl ;
				break;
			}		
			
				else if (Win() == 'O')
				{
					system("cls");
					Draw();
					cout << "Player O wins ! " << endl;
					break;
				}
			
					else if (MatchTie())
					{
						system("cls");
						Draw();
						cout <<	"Match Tied." << endl;
						break;
					}	
			if (flag != 1)
			{
				toggleplayer();		
			}
	}
}

void play2()
{
	int choice;
	int flag=0;
	int flag2=0;
		while (1)
		{
				Draw();
				
				if (flag == 1)
				{
					cout << "\nThe position has been already choosen.\nPlease choose a different position." << endl;
					flag = 0;
					if (flag2 == 0)
					{
						flag2 = 1;
					}
					else
					{
						flag2 = 0;
					}
				}
				
//				flag = 0;			
				
				if (flag2 == 0)
				{
					cout << "\nYour turn : ";
					cin >> choice;
					cin.ignore();
					flag2 = 1;
				}
				else
				{	// CPU's logic to play the game
					
					// Defense
					if ((matrix[0][1] == 'X' && matrix[0][2] == 'X') || (matrix[1][0] == 'X' && matrix[2][0] == 'X') || (matrix[1][1] == 'X' && matrix[2][2] == 'X'))
					{
						choice = 1;
					}
					
					else if ((matrix[0][0] == 'X' && matrix[0][2] == 'X') || (matrix[1][1] == 'X' && matrix[2][1] == 'X'))
					{
						choice = 2;
					}
					
					else if ((matrix[0][0] == 'X' && matrix[0][1] == 'X') || (matrix[1][2] == 'X' && matrix[2][2] == 'X') || (matrix[1][1] == 'X' && matrix[2][0] == 'X'))
					{
						choice = 3;
					}
					
					else if ((matrix[0][0] == 'X' && matrix[2][0] == 'X') || (matrix[1][1] == 'X' && matrix[1][2] == 'X'))
					{
						choice = 4;
					}
					
					else if ((matrix[0][0] == 'X' && matrix[2][2] == 'X') || (matrix[0][2] == 'X' && matrix[2][0] == 'X') || (matrix[1][0] == 'X' && matrix[1][2] == 'X') || (matrix[0][1] == 'X' && matrix[2][1] == 'X'))
					{
						choice = 5;
					}
					
					else if ((matrix[1][0] == 'X' && matrix[1][1] == 'X') || (matrix[0][2] == 'X' && matrix[2][2] == 'X'))
					{
						choice = 6;
					}
					
					else if ((matrix[0][0] == 'X' && matrix[1][0] == 'X') || (matrix[2][1] == 'X' && matrix[2][2] == 'X') || (matrix[1][1] == 'X' && matrix[0][2] == 'X'))
					{
						choice = 7;
					}
					
					else if ((matrix[0][1] == 'X' && matrix[1][1] == 'X') || (matrix[2][0] == 'X' && matrix[2][2] == 'X'))
					{
						choice = 8;
					}
					
					else if ((matrix[0][2] == 'X' && matrix[1][2] == 'X') || (matrix[2][1] == 'X' && matrix[2][0] == 'X') || (matrix[1][1] == 'X' && matrix[0][0]) == 'X')
					{
						choice = 9;
					}
					
					// Attack
					
					else if ((matrix[0][1] == 'O' && matrix[0][2] == 'O') || (matrix[1][0] == 'O' && matrix[2][0] == 'O') || (matrix[1][1] == 'O' && matrix[2][2] == 'O'))
					{
						choice = 1;
					}
					
					else if ((matrix[0][0] == 'O' && matrix[0][2] == 'O') || (matrix[1][1] == 'O' && matrix[2][1] == 'O'))
					{
						choice = 2;
					}
					
					else if ((matrix[0][0] == 'O' && matrix[0][1] == 'O') || (matrix[1][2] == 'O' && matrix[2][2] == 'O') || (matrix[1][1] == 'O' && matrix[2][0] == 'O'))
					{
						choice = 3;
					}
					
					else if ((matrix[0][0] == 'O' && matrix[2][0] == 'O') || (matrix[1][1] == 'O' && matrix[1][2] == 'O'))
					{
						choice = 4;
					}
					
					else if ((matrix[0][0] == 'O' && matrix[2][2] == 'O') || (matrix[0][2] == 'O' && matrix[2][0] == 'O') || (matrix[1][0] == 'O' && matrix[1][2] == 'O') || (matrix[0][1] == 'O' && matrix[2][1] == 'O'))
					{
						choice = 5;
					}
					
					else if ((matrix[1][0] == 'O' && matrix[1][1] == 'O') || (matrix[0][2] == 'O' && matrix[2][2] == 'O'))
					{
						choice = 6;
					}
					
					else if ((matrix[0][0] == 'O' && matrix[1][0] == 'O') || (matrix[2][1] == 'O' && matrix[2][2] == 'O') || (matrix[1][1] == 'O' && matrix[0][2] == 'O'))
					{
						choice = 7;
					}
					
					else if ((matrix[0][1] == 'O' && matrix[1][1] == 'O') || (matrix[2][0] == 'O' && matrix[2][2] == 'O'))
					{
						choice = 8;
					}
					
					else if ((matrix[0][2] == 'O' && matrix[1][2] == 'O') || (matrix[2][1] == 'O' && matrix[2][0] == 'O') || (matrix[1][1] == 'O' && matrix[0][0]) == 'O')
					{
						choice = 9;
					}
					
					else
					{
//						markOnAnyBox();
//						flag2 = 0;
//						toggleplayer();
//						continue;
						choice = 1 + rand() % 9;
//						if(flag == 1){
//						choice = 1 + rand() % 9;
//							
//						}
//						while(posAvailable(choice)){
//							cout << choice;
//						choice = 1 + rand() % 9;	
//						}
					}
					
					
					flag2 = 0;	
				}
				flag=0;
				
				// Placing Mark (X or O) on the chose position
				if (choice == 1)
				{
					if (matrix[0][0] == 'X' || matrix[0][0] == 'O')		// 1 means the position is already selected
					{				
						flag = 1;
//						continue;
					}
					else												// set mark on the position
					{
						matrix[0][0] = player;
					}
				}
					else if (choice == 2)
					{	
						if (matrix[0][1] == 'X' || matrix[0][1] == 'O')
						{
							flag = 1;
//							continue;
						}
						else 
						{
							matrix[0][1] = player;
						}
					}
						else if (choice == 3)
						{
							if (matrix[0][2] == 'X' || matrix[0][2] == 'O')
							{
								flag = 1;
//								continue;
							}	
							else 
							{
								matrix[0][2] = player;
							}
						}
							else if (choice == 4)
							{
								if (matrix[1][0] == 'X' || matrix[1][0] == 'O')
								{
									flag = 1;
//									continue;
								}
								else 
								{
									matrix[1][0] = player;
								}
							}
								else if (choice == 5)
								{
									if (matrix[1][1] == 'X' || matrix[1][1] == 'O')
									{
										flag = 1;
//										continue;
									}
									else 
									{
										matrix[1][1] = player;
									}
								}
									else if (choice == 6)
									{
										if (matrix[1][2] == 'X' || matrix[1][2] == 'O')
										{
											flag = 1;
//											continue;
										}
										else 
										{
											matrix[1][2] = player;
										}
									}
										else if (choice == 7)
										{
											if (matrix[2][0] == 'X' || matrix[2][0] == 'O')
											{
												flag = 1;
//												continue;
											}
											else 
											{
												matrix[2][0] = player;
											}
										}
											else if (choice == 8)
											{
												if (matrix[2][1] == 'X' || matrix[2][1] == 'O')
												{	
													flag = 1;
//													continue;
												}
												else 
												{
													matrix[2][1] = player;
												}
											}
												else if (choice == 9)
												{
													if (matrix[2][2] == 'X' || matrix[2][2] == 'O')
													{
														flag = 1;
//														continue;
													}
													else 
													{
														matrix[2][2] = player;
													}
												}
			
				if (flag != 1)
				{
					toggleplayer();		
				}
		
				if (Win() == 'X')
				{
					system("cls");
					Draw();
					cout << "Player X wins !" << endl ;
					break;
				}		
				
					else if (Win() == 'O')
					{
						system("cls");
						Draw();
						cout << "Player O wins ! " << endl;
						break;
					}
				
						else if (MatchTie())
						{
							system("cls");
							Draw();
							cout <<	"Match Tied." << endl;
							break;
						}
				

				
		}
	
}					
bool posAvailable(int c){
	switch (c){
		case 1:
			if (matrix[0][0] == 'X' || matrix[0][0] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		
		case 2:
			if (matrix[0][1] == 'X' || matrix[0][1] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		
		case 3:
			if (matrix[0][2] == 'X' || matrix[0][2] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		case 4:
			if (matrix[1][0] == 'X' || matrix[1][0] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		case 5:
			if (matrix[1][1] == 'X' || matrix[1][1] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		case 6:
			if (matrix[1][2] == 'X' || matrix[1][2] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		case 7:
			if (matrix[2][0] == 'X' || matrix[2][0] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		case 8:
			if (matrix[2][1] == 'X' || matrix[2][1] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		case 9:
			if (matrix[2][2] == 'X' || matrix[2][2] == 'O')	
					{
						return false;
					}
					else {
						return true;
					}
			break;
		default:
			return true;
		}
}
int main()
{
	int choice;
	cout << "Press 1 for multiplayer or 2 for singleplayer : " ;
	cin >> choice;
	if (choice == 1)
	{
		play();	
	}
	else
	{
		play2();
	}
	return 0;
}
