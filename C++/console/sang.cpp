#include <iostream>//cin , cout , string
using namespace std;
#include <conio.h> //getch()
#include <stdlib.h> //rand()

string game[3]={"sang", "kaghaz", "gheychi"};
string player1 , player2;
int Splayer1, Splayer2; // in the global int variable  defalt value is 0

int main()
{
	system("color e");
	system("title sang");
	system("mode con cols=35 lines=20");
	system("cls");
	while(Splayer1 < 3 && Splayer2 < 3)
	{
		cout << "\t    Welcome     \n" << endl ;
		cout << "    sang     kaghaz    gheychi" << endl;
		cout <<"==== shoma "<<Splayer1<<" va computer "<<Splayer2<<" ast ===="<<endl;
		cout <<"-----------------------------------"<<endl;
		cout <<"Enter your choice"<<endl;
		cout <<"--->";cin>>player1;
		// check input ----------	
		while (1)
		{
			bool x = false;
			for(int i = 0 ; i<3 ; i++)
			{
				if (player1 == game[i])
					{x = true;break;}
			}
			
			if (x == false)
			{
				cout <<"*******"<<endl;
				cout <<"   use: sang -- kaghaz -- gheychi"<<endl;
				cout <<"*******"<<endl;
				cout <<"--->";cin>>player1;	
			}else
				break;
		}
		// end check input ------
		cout<<"-----------------------------------"<<endl;
		cout<<"shoma-----> "<<player1<<endl; 
		player2 = game[rand()%(3-0+1)+0];
		cout<<"computer--> "<<player2<<"\n"<<endl;
		
		//-----if
		string win_user     = "->shoma barande shodid!" ;
		string win_computer = "->computer barande shod!";
			
	    if (player1 == player2)
	        cout<<"->mosavi"<<endl;
	    else if (player1 == game[0] && player2 == game[1])
	    {Splayer2++; cout<<win_computer<<endl;}
	        
	    else if (player1 == game[0] && player2 == game[2])
		{Splayer1++; cout<<win_user<<endl;}
			
	    else if (player1 == game[1] && player2 == game[0])
		{Splayer1++; cout<<win_user<<endl;}
			
	    else if (player1 == game[1] && player2 == game[2])
		{Splayer2++; cout<<win_computer<<endl;}
			
	    else if (player1 == game[2] && player2 == game[0])
		{Splayer2++; cout<<win_computer<<endl;}
			
	    else if (player1 == game[2] && player2 == game[1])
		{Splayer1++; cout<<win_user<<endl;}	
	    else cout<<"<-- if ERORR --> "<<endl;
		//-----end if
		
		system("pause");
		if(Splayer1 < 3 && Splayer2 < 3)
			system("cls");
		else
			continue;
	}
	cout<<"==================================="<<endl;
	if (Splayer1 < Splayer2)
		{cout<<"computer bazi ra "<<Splayer2<<" be "<<Splayer1<<" bord !!!"<<endl;system("color c");}
	else
		{cout<<"shoma bazi ra "<<Splayer1<<" be "<<Splayer2<<" bordid !!!"<<endl; system ("color a");}
	
	cout<<"\nPress any key to Exit ....";getch();
	return 0 ;
}
