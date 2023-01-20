using System;

class Program
{
    static void Main()
    {
        string[] game = new string[] { "sang", "kaghaz", "gheychi" };
        string player1, player2;
        int Splayer1 = 0, Splayer2 = 0;
        Random rand = new Random();

        Console.ForegroundColor = ConsoleColor.Yellow;
        Console.Title = "sang";
        Console.SetWindowSize(35, 20);
        Console.Clear();

        while (Splayer1 < 3 && Splayer2 < 3)
        {
            Console.WriteLine("\t    Welcome     \n");
            Console.WriteLine("    sang     kaghaz    gheychi");
            Console.WriteLine("==== shoma {0} va computer {1} ast ====", Splayer1, Splayer2);
            Console.WriteLine("-----------------------------------");
            Console.WriteLine("Enter your choice");
            Console.Write("--->"); player1 = Console.ReadLine();
            while (true)
            {
                bool x = false;
                for (int i = 0; i < 3; i++)
                {
                    if (player1 == game[i])
                    { x = true; break; }
                }
                if (x == false)
                {
                    Console.WriteLine("*******");
                    Console.WriteLine("   use: sang -- kaghaz -- gheychi");
                    Console.WriteLine("*******");
                    Console.Write("--->"); player1 = Console.ReadLine();
                }
                else
                    break;
            }

            Console.WriteLine("-----------------------------------");
            Console.WriteLine("shoma-----> {0}", player1);
            player2 = game[rand.Next(0,3)];
            Console.WriteLine("computer--> {0} \n", player2);

            //-----if
            string win_user = "->shoma barande shodid!";
            string win_computer = "->computer barande shod!";

            if (player1 == player2)
                Console.WriteLine("->mosavi");
            else if (player1 == game[0] && player2 == game[1])
            { Splayer2++; Console.WriteLine(win_computer); }

            else if (player1 == game[0] && player2 == game[2])
            { Splayer1++; Console.WriteLine(win_user); }

            else if (player1 == game[1] && player2 == game[0])
            { Splayer1++; Console.WriteLine(win_user); }

            else if (player1 == game[1] && player2 == game[2])
            { Splayer2++; Console.WriteLine(win_computer); }

            else if (player1 == game[2] && player2 == game[0])
            { Splayer2++; Console.WriteLine(win_computer); }

            else if (player1 == game[2] && player2 == game[1])
            { Splayer1++; Console.WriteLine(win_user); }
            else Console.WriteLine("<-- if ERORR --> ");
            //-----end if

            Console.WriteLine("Press any key to continue . . .");
            Console.ReadKey();
            if (Splayer1 < 3 && Splayer2 < 3)
                Console.Clear();
            else
                continue;
        }

        Console.WriteLine("===================================");
        if (Splayer1 < Splayer2)
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("computer bazi ra {0} be {1} bord !!!", Splayer2, Splayer1);
        }
        else if(Splayer1 > Splayer2)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("shoma bazi ra {0} be {1} bordid !!!", Splayer1, Splayer2);
        }

        Console.Write("\nPress any key to Exit ...."); Console.ReadKey();
    }
}
