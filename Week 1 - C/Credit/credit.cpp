#include <iostream>

enum cardTypes
{
    AMERICAN_EXPRESS,
    MASTER_CARD,
    VISA,
    INVALID_CARD
};

void CheckCard(unsigned long long card_number);

int main()
{
    // Get the card number
    unsigned long long card;
    do
    {
        printf("Card number: ");
        std::cin >> card;
    } while (card < 0);

    // Check if the card is valid
    CheckCard(card);
    return 0;
}

// Function for credit card check algorithm
void CheckCard(unsigned long long card_number)
{
    int sum = 0;
    int digits_count = 0;
    int last_digit = 0;
    int prev_digit;
    int current_digit;

    while (card_number != 0)
    {
        // Extract the card last digit
        prev_digit = last_digit;
        last_digit = card_number % 10;
        current_digit = last_digit;
        digits_count++;

        // If it's even multiply by 2, if the result is more than 1 digit, sum the last and conserve only 1
        if (digits_count % 2 == 0)
        {
            current_digit *= 2;
            if (current_digit > 9)
            {
                sum += current_digit % 10;
                current_digit /= 10;
            }
        }

        // Add to the sum and delete card last digit
        sum += current_digit;
        card_number /= 10;
    }

    // Sum check
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return;
    }

    // Check AmericanExpress (15 digits and starts with 34 / 37)
    else if (digits_count == 15)
    {
        int first_digits = (last_digit * 10) + prev_digit;
        switch (first_digits)
        {
            case 34:
            case 37:
                printf("AMERICAN EXPRESS\n");
                return;

            default:
                printf("INVALID\n");
                return;
        }
    }

    // Check Visa
    else if (digits_count == 13 && last_digit == 4)
    {
        printf("VISA\n");
        return;
    }

    // Check Master card and Visa
    else if (digits_count == 16)
    {
        if (last_digit == 4)
        {
            printf("VISA\n");
            return;
        }

        int first_digits = (last_digit * 10) + prev_digit;
        switch (first_digits)
        {
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTER CARD\n");
                return;

            default:
                printf("INVALID\n");
                return;
        }
    }

    printf("INVALID\n");
    return;
}