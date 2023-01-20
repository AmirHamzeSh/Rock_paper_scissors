from os import system
from random import choice

game=["sang", "kaghaz", "gheychi"]
player1 = None
player2 = None
Splayer1 = 0
Splayer2 = 0

system("color e")
system("title sang")
system("cls")

while (Splayer1 < 3 and Splayer2 < 3):

    print( "\t    Welcome     \n")
    print( "    sang     kaghaz    gheychi")
    print(f"==== shoma {Splayer1} va computer {Splayer2} ast ====")
    print("-----------------------------------")
    print("Enter your choice")
    player1 = input("--->")
    
    while (player1 not in game):
        print("*******\n   use: sang -- kaghaz -- gheychi\n*******")
        player1 = input('-->').lower()

    
    print("-----------------------------------")
    print(f"shoma-----> {player1}")
    player2 = choice(game)
    print(f"computer--> {player2}\n")
    
    win_user     = "->shoma barande shodid!" 
    win_computer = "->computer barande shod!"
        
    if player1 == player2:
        print("->mosavi")
    elif player1 == game[0] and player2 == game[1]:
        Splayer2 += 1; print(win_computer)
        
    elif player1 == game[0] and player2 == game[2]:
        Splayer1 += 1; print(win_user)
        
    elif player1 == game[1] and player2 == game[0]:
        Splayer1 += 1; print(win_user)
        
    elif player1 == game[1] and player2 == game[2]:
        Splayer2 += 1; print(win_computer)
        
    elif player1 == game[2] and player2 == game[0]:
        Splayer2 += 1; print(win_computer)
        
    elif player1 == game[2] and player2 == game[1]:
        Splayer1 += 1; print(win_user)
    else:
        print("<-- if ERORR --> ")
    
    system("pause")
    if (Splayer1 < 3 and Splayer2 < 3):
        system("cls")
    else:
        pass

print("===================================")
if (Splayer1 < Splayer2):
    print(f"computer bazi ra {Splayer2} be {Splayer1} bord !!!")
    system("color c")
else:
    print(f"shoma bazi ra {Splayer1} be {Splayer2} bordid !!!")
    system ("color a")

input("\nPress Enter to Exit ....")