#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number = get_long("Number: ");
    int sum = 0;
    int count = 0;
    string id = 0;

    while (number)
    {
        if (count % 2 == 0) //Verifica el lugar del digito de la tarjeta desde el ultimo al primero,
        {
            sum = sum + number % 10;
        }
        else if (number % 10 * 2 >= 10)
        {
            sum = sum + number % 10 * 2 - 9;
        }
        else
        {
            sum = sum + number % 10 * 2;
        }

        number = (number - (number % 10)) / 10;

        if (number > 33 && number < 56)
        {
            if (number > 50)
            {
                id = "MASTERCARD";
            }
            else if (number > 39 && number < 50)
            {
                id = "VISA";
            }
            else if (number == 34 || number == 37)
            {
                id = "AMEX";
            }
        }

        count++;

    };

    if ((((count < 13 || count > 16) || count == 14) || sum % 10 != 0) || id == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("%s\n", id);
    }
}
