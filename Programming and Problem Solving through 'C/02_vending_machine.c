#include <stdio.h>

int main(void)
{
    int choice;
    int money;
    int price;
    int change;

    printf("=== Vending Machine ===\n");
    printf("1. Water     120 yen\n");
    printf("2. Green Tea 150 yen\n");
    printf("3. Coffee    130 yen\n");

    printf("Choose a drink (1-3): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (choice == 1) {
        price = 120;
    } else if (choice == 2) {
        price = 150;
    } else if (choice == 3) {
        price = 130;
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Insert money: ");
    if (scanf("%d", &money) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (money < price) {
        printf("Not enough money.\n");
        printf("You need %d more yen.\n", price - money);
        return 0;
    }

    change = money - price;

    printf("You bought: ");
    if (choice == 1) {
        printf("Water\n");
    } else if (choice == 2) {
        printf("Green Tea\n");
    } else {
        printf("Coffee\n");
    }

    printf("Change: %d yen\n", change);

    return 0;
}
