#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculate_monthly_payment(int Loan_amount,float interest_rate, float repayment_period_on_years)
{
    // M = P * (r * (1 + r) ^ n) / ((1 + r) ^ n - 1)

    /*M = Monthly payment
    P = Principal amount (loan amount)
    r = Monthly interest rate (annual interest rate divided by 12)
    n = Number of payments (loan term in years x 12)*/
    float M ;
    float P = Loan_amount;
    float r = ((interest_rate / 12)/100) ;
    float n = repayment_period_on_years * 12 ;
    M = P * (r * pow((1 + r), n)) / (pow((1 + r), n) - 1);
    printf("\n\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
    printf("\n\nYour estimated monthly payment is %.2fDH\n\n", M);
    printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");


}

int main()
{


    int  Loan_amount;
    float interest_rate;
    float repayment_period_on_years;
    char permision;
    int j = 1;

//  Warning the user about how much attempts are allowed

    printf("\n!!! Up to 10 attempts are allowed. Please take your time and enter carefully !!!\n");


    do
    {
        printf("\n#### Chaabi Lil Iskane Mortgage Loan Payment Calculator %d ####\n\n", j);

// get the informations of how much is the loan

        printf("- What is the principal amount of the loan? : ");
        scanf("%d", &Loan_amount);

        do
        {
// get the informations of how many years he will pay the loan
            printf("- How many years is the loan term set? (Minimum term is 5 years)? : ");
            scanf("%f", &repayment_period_on_years);
            if( repayment_period_on_years < 5)
            {
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n It's important to note that the minimum repayment period is 5 years!! \n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
            }
        }
        while(repayment_period_on_years < 5);


        do
        {
// get the informations of how much is the interest of the lona
            printf("- What is the interest rate (3%%-7%%) : ");
            scanf("%f", &interest_rate);
            if((interest_rate < 3) || (interest_rate > 7))
            {
                printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n The interest rate should be between 3%% and 7%%!! \n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");
            }
        }
        while((interest_rate < 3) || (interest_rate > 7));
// call the function to calculate how much he will pay every month .
        calculate_monthly_payment(Loan_amount,interest_rate,repayment_period_on_years);


        printf("\n\n##############################################################\n\n");
        if(j > 9)
        {
            printf("Unfortunately, you have reached the maximum number of attempts (10). Please try again later.\n");
            break;
        }
        else
        {
            printf("Do you want to repeat again Y/n : ");
            scanf(" %c", &permision);
            j++;
            printf("\n\n##############################################################\n\n");
        }


    }
    while((permision == 'Y' || permision == 'y') );


    return 0;
}
