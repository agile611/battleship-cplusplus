#include <iostream>
#include <cstdlib>
#include <ctime>



using namespace std;


int main() {

        cout << "                                     |__"<<endl;
        cout << "                                     |\\/"<<endl;
        cout << "                                     ---"<<endl;
        cout << "                                     / | ["<<endl;
        cout << "                              !      | |||"<<endl;
        cout << "                            _/|     _/|-++'"<<endl;
        cout << "                        +  +--|    |--|--|_ |-"<<endl;
        cout << "                     { /|__|  |/\\__|  |--- |||__/"<<endl;
        cout << "                    +---------------___[}-_===_.'____                 /\\"<<endl;
        cout << "                ____`-' ||___-{]_| _[}-  |     |_[___\\==--            \\/   _"<<endl;
        cout << " __..._____--==/___]_|__|_____________________________[___\\==--____,------' .7"<<endl;
        cout << "|                        Welcome to Battleship                         BB-61/"<<endl;
        cout << " \\_________________________________________________________________________|"<<endl;

        InitializeGame();

        StartGame();
    
}

void StartGame(){

         cout << "                  __"<<endl;
         cout << "                 /  \ "<<endl;
         cout << "           .-.  |    | "<<endl;
         cout << "   *    _.-'  \  \__/ "<<endl;
         cout << "    \.-'       \ "<<endl;
         cout << "   /          _/ "<<endl;
         cout << "  |      _  /"""<<endl;
         cout << "  |     /_\ "<<endl;
         cout << "   \    \_/ "<<endl;
         cout << "    """""""" "<<endl;

         do
         {
            cout << "Player, it's your turn"<<endl;
            cout << "Enter coordinates for your shot :"<<endl;
            var position = ParsePosition(Console.ReadLine());
            var isHit = GameController.CheckIsHit(enemyFleet, position);
            if (isHit)
            {
               Console.Beep();

               cout << "                \         .  ./"<<endl;
               cout << "              \      .:"";'.:..""   /"<<endl;
               cout << "                  (M^^.^~~:.'"")."<<endl;
               cout << "            -   (/  .    . . \ \)  -"<<endl;
               cout << "               ((| :. ~ ^  :. .|))"<<endl;
               cout << "            -   (\- |  \ /  |  /)  -"<<endl;
               cout << "                 -\  \     /  /-"<<endl;
               cout << "                   \  \   /  /"<<endl;
            }

            cout << isHit ? "Yeah ! Nice hit !" : "Miss"<<endl;

            position = GetRandomPosition();
            isHit = GameController.CheckIsHit(myFleet, position);
            cout << );
            cout << "Computer shot in {0}{1} and {2}", position.Column, position.Row, isHit ? "has hit your ship !" : "miss"<<endl;
            if (isHit)
            {
               cout << '\a'; //Console Beep, more indie

               cout << "                \         .  ./"<<endl;
               cout << "              \      .:"";'.:..""   /"<<endl;
               cout << "                  (M^^.^~~:.'"")."<<endl;
               cout << "            -   (/  .    . . \ \)  -"<<endl;
               cout << "               ((| :. ~ ^  :. .|))"<<endl;
               cout << "            -   (\- |  \ /  |  /)  -"<<endl;
               cout << "                 -\  \     /  /-"<<endl;
               cout << "                   \  \   /  /"<<endl;

            }
         }
         while (true);
}

Position ParsePosition(string input)
{
         var letter = (Letters)Enum.Parse(typeof(Letters), input.ToUpper().Substring(0, 1));
         var number = int.Parse(input.Substring(1, 1));
         return new Position(letter, number);
}

Position GetRandomPosition()
{
          int rows = 8;
          int lines = 8;
          var random = new Random();
          var letter = (Letters)random.Next(lines);
          var number = random.Next(rows);
          var position = new Position(letter, number);
          return position;
}

void InitializeGame()
{
         InitializeMyFleet();

         InitializeEnemyFleet();
}

void InitializeMyFleet()
{
         myFleet = GameController.InitializeShips().ToList();

         Console.WriteLine("Please position your fleet (Game board size is from A to H and 1 to 8) :");

         foreach (var ship in myFleet)
         {
            Console.WriteLine();
            Console.WriteLine("Please enter the positions for the {0} (size: {1})", ship.Name, ship.Size);
            for (var i = 1; i <= ship.Size; i++)
            {
               Console.WriteLine("Enter position {0} of {1} (i.e A3):", i, ship.Size);
               ship.AddPosition(Console.ReadLine());
            }
         }
      }

void InitializeEnemyFleet()
{
         enemyFleet = GameController.InitializeShips().ToList();

         enemyFleet[0].Positions.Add(new Position { Column = Letters.B, Row = 4 });
         enemyFleet[0].Positions.Add(new Position { Column = Letters.B, Row = 5 });
         enemyFleet[0].Positions.Add(new Position { Column = Letters.B, Row = 6 });
         enemyFleet[0].Positions.Add(new Position { Column = Letters.B, Row = 7 });
         enemyFleet[0].Positions.Add(new Position { Column = Letters.B, Row = 8 });

         enemyFleet[1].Positions.Add(new Position { Column = Letters.E, Row = 6 });
         enemyFleet[1].Positions.Add(new Position { Column = Letters.E, Row = 7 });
         enemyFleet[1].Positions.Add(new Position { Column = Letters.E, Row = 8 });
         enemyFleet[1].Positions.Add(new Position { Column = Letters.E, Row = 9 });

         enemyFleet[2].Positions.Add(new Position { Column = Letters.A, Row = 3 });
         enemyFleet[2].Positions.Add(new Position { Column = Letters.B, Row = 3 });
         enemyFleet[2].Positions.Add(new Position { Column = Letters.C, Row = 3 });

         enemyFleet[3].Positions.Add(new Position { Column = Letters.F, Row = 8 });
         enemyFleet[3].Positions.Add(new Position { Column = Letters.G, Row = 8 });
         enemyFleet[3].Positions.Add(new Position { Column = Letters.H, Row = 8 });

         enemyFleet[4].Positions.Add(new Position { Column = Letters.C, Row = 5 });
         enemyFleet[4].Positions.Add(new Position { Column = Letters.C, Row = 6 });
      }
}
