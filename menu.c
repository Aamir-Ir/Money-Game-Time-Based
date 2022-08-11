# include "header.h"

/*
    A function name menu() to print the menu to reduce redundancy.
*/

int menu(long long int marketBy, long long int cookieBy, long long int pizzaBy, long long int iceBy, long long int carBy) {   
    int num;                                // Used for input.
    long long int marketing = 1000000;                // Keep track of the intial price for marketing.
    long long int cookieIntial = 50000;               // Keep track of the intial price for cookie business.
    long long int pizzaIntial = 500000;               // Keep track of the intial price for pizza business.
    long long int iceCreamIntial = 5000000;           // Keep track of the intial price for ice cream business.
    long long int carIntial = 50000000;               // Keep track of the intial price for car business.

    // Menu for all possible operations.

    printf("1) Work (Accumulates income for every second which is a months worth of income).\n");
    printf("2) View Wallet.\n");
    printf("3) Business Summary.\n");
    printf("\nInvest and grow options.\n\n");
    printf("4) Cookie Business (+5000/month income) currently requires %'lld.\n", cookieIntial * cookieBy);
    printf("5) Pizza Business (+6000/month income) currently requires %'lld.\n", pizzaIntial * pizzaBy);
    printf("6) Ice Cream Business (+7000/month income) currently requires %'lld.\n", iceCreamIntial * iceBy);
    printf("7) Car Business (+8000/month income) currently requires %'lld.\n", carIntial * carBy);
    printf("8) Increase Marketing (Increases Income Multiplier for all business) currently requires %'lld.\n", marketing * marketBy);
    printf("Quit: 0\n");
    scanf("%d", &num);

    // Return users selections.
    
    return num;
}