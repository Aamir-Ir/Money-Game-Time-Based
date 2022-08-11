# include "header.h"

int main(int argc, char * argv[])   {
    long long int intial;                         // Intial will be used to calculate the alloted money in game.
    time_t now = time(NULL);                      // Calculates the start time of the program.
    time_t next;                                  // Will store the next successive time when called.
    intial = (long long int)now;                  // Stores current time.
    long long int money = intial - intial;        // Keep track of the wallet.
    int input;                                    // Used for user input.
    long long int income = 5000;                  // Inital income per month (1 sec = 1 month)
    long long int sleeping;                       // Put the program to sleep when user decides to work
    
    // Cookie Business

    long long int cookies = 0;                    // Keeps track of the number of units you own for cookies.
    long long int cookieBy = 1;                   // Keeps track of the multiplier for the cost of 1 unit increase with each successive buy.

    // Pizza Business

    long long int pizzas = 0;                     // Keeps track of the number of units you own for pizzas.
    long long int pizzaBy = 1;                    // Keeps track of the multiplier for the cost of 1 unit increase with each successive buy.
    
    // Ice Cream Business

    long long int iceCreams = 0;                  // Keeps track of the number of units you own for ice cream.
    long long int iceBy = 1;                      // Keeps track of the multiplier for the cost of 1 unit increase with each successive buy.
    
    // Car Business

    long long int cars = 0;                       // Keeps track of the number of units you own for cars.
    long long int carBy = 1;                      // Keeps track of the multiplier for the cost of 1 unit increase with each successive buy.
    
    // Marketing Option.
    long long int marketing = 1;                  // Keeps track of the number of times you choose to market.
    long long int marketBy = 1;                   // Keeps track of the multiplier for the cost of marketing increase with each successive buy.

    setlocale(LC_NUMERIC, "");                    // Used to make reading integers easier.

    // Intial greetig plus rules.

    printf("Welcome to Entrepreneur a game where you try to get as much money as possible.\n");
    printf("Well you just started the game so you should have close to nothing right now.\n");
    printf("You have $%lld right now however you have a basic inome right now of %lld / month (1 sec = 1 month).\n", money, income);
    printf("See the options below of what you can do to earn money at a faster rate.\n\n");

    // Menu.

    input = menu(marketBy, cookieBy, pizzaBy, iceBy, carBy);

    // Once input is given run the program until the user decides to exit.

    while (input != 0)  {
        
        // Possibility 1: Input is in the appropriate range of integers.

        if ((input >= 0) && (input <= 8)) {
            
            // Case 1: The user has chosen to accumalate wealth by working for a certain number of months. 

            if (input == 1) {
                printf("How long do you want to sleep for (in seconds) (1 sec = 1 month): ");
                scanf("%lld", &sleeping);
                sleep(sleeping);
            }
            
            // Case 2: The user has chosen to view his networth. 

            else if (input == 2)   {
                printf("\nWallet: $%'lld.\n", money);
            }

            // Case 3: The user has chosen to release a summary of all the investments they have made. 

            else if (input == 3)    {
                printf("Summary.\n");
                printf("Cookie business unit count: %lld.\n", cookies);
                printf("Pizza business unit count: %lld.\n", pizzas);
                printf("Ice cream business unit count: %lld.\n", iceCreams);
                printf("Car business unit count: %lld.\n", cars);
                printf("Currently the marketing multiplier is: %lld.\n", marketing);
            }

            // Case 4: The user has chosen to invest in the cookie business by buying a unit.

            else if (input == 4)    {
                if (money >= 50000 * cookieBy)    {
                    printf("Congrast You just opened a cookie business + 5000/month income.\n");
                    money -= 50000 * cookieBy;
                    income += 5000;
                    cookies++;
                    cookieBy++;
                }
                else    {
                    printf("Sorry, but you need more money.\n");
                }
            }

            // Case 5: The user has chosen to invest in the cookie business by buying a unit.

            else if (input == 5)    {
                if (money >= 500000 * pizzaBy)    {
                    printf("Congrast You just opened a pizza business + 6000/month income.\n");
                    money -= 500000 * pizzaBy;
                    income += 6000;
                    pizzas++;
                    pizzaBy++;
                }
                else    {
                    printf("Sorry, but you need more money.\n");
                }
            }

            // Case 6: The user has chosen to invest in the ice cream business by buying a unit.

            else if (input == 6)    {
                if (money >= 5000000 * iceBy)    {
                    printf("Congrast You just opened a ice cream business + 7000/month income.\n");
                    money -= 5000000 * iceCreams;
                    income += 7000;
                    iceCreams++;
                    iceBy++;
                }
                else    {
                    printf("Sorry, but you need more money.\n");
                }
            }

            // Case 7: The user has chosen to invest in the car business by buying a unit.

            else if (input == 7)    {
                if (money >= 50000000 * carBy)    {
                    printf("Congrast You just opened a car business + 8000/month income.\n");
                    money -= 50000000 * carBy;
                    income += 8000;
                    cars++;
                    carBy++;
                }
                else    {
                    printf("Sorry, but you need more money.\n");
                }
            }

            // Case 8: The user has chosen to invest in marketing for all their business.

            else if (input == 8)    {
                if (money >= 1000000 * marketBy) {
                    printf("Congrast You have invested in marketing.\n");
                    marketing++;
                    marketBy++;
                }
                else    {
                    printf("Sorry, but you need more money.\n");
                }
            }

            // Calculate the wallet after. 

            next = time(NULL);
            money = marketing * income * (long long int)difftime(next, now);

            // Next operation.

            printf("\nPrevious operation complete.\n");
            input = menu(marketBy, cookieBy, pizzaBy, iceBy, carBy);
            
        }

        // Possibility 2: Input is not in the appropriate range of integers.

        else{
            printf("Invalid input, try again.\n");
            input = menu(marketBy, cookieBy, pizzaBy, iceBy, carBy);
        }
    }

    return 1;
}