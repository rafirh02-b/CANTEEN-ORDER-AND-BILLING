#include <stdio.h>

int main(void)
{
    printf("============================================\n");
    printf("          CANTEEN ORDER AND BILLING        \n");
    printf("============================================\n");

    printf("1. Show Menu\n");
    printf("2. Add to Order\n");
    printf("3. Remove an Item\n");
    printf("4. Print Bill\n");
    printf("5. Take Payment\n");
    printf("6. Save Order\n");
    printf("7. Load Order\n");
    printf("8. Exit\n");

    printf("--------------------------------------------\n");
    printf("                    MENU                    \n");
    printf("--------------------------------------------\n");

    printf("%-6s%-20s%10s%12s\n", "CODE", "ITEM", "CATEGORY", "PRICE");

    printf("%-6d%-20s%10s%12.2f\n", 101, "Chicken Meal", "Meal", 180.00);

    printf("%-6d%-20s%10s%12.2f\n", 102, "Beef Burger", "Meal", 220.00);

    printf("%-6d%-20s%10s%12.2f\n", 103, "French Fries", "Snack", 80.00);

    printf("%-6d%-20s%10s%12.2f\n", 104, "Samosa", "Snack", 30.00);

    printf("%-6d%-20s%10s%12.2f\n", 105, "Soft Drink", "Drink", 40.00);

    printf("%-6d%-20s%10s%12.2f\n", 106, "Mineral Water", "Drink", 20.00);

    printf("--------------------------------------------\n");

    printf("\n              CURRENT ORDER                \n");
    printf("--------------------------------------------\n");

    printf("%-6s%-20s%8s%12s\n","CODE", "ITEM", "QTY", "TOTAL");

    printf("%-6d%-20s%8d%12.2f\n",101, "Chicken Meal", 2, 360.00);

    printf("%-6d%-20s%8d%12.2f\n",105, "Soft Drink", 2, 80.00);

    printf("%-6d%-20s%8d%12.2f\n",104, "Samosa", 3, 90.00);

    printf("--------------------------------------------\n");

    printf("Subtotal:                      %.2f\n", 530.00);
    printf("Combo Discount:                %.2f\n", 40.00);
    printf("Total Bill:                    %.2f\n", 490.00);

    printf("--------------------------------------------\n");
    printf("Payment Received:              %.2f\n", 500.00);
    printf("Change:                        %.2f\n", 10.00);

    printf("--------------------------------------------\n");
    printf("Change Breakdown:\n");
    printf("  10 x 1\n");

    printf("--------------------------------------------\n");
    printf("Thank you for ordering!\n");
    printf("Please visit again.\n");
    printf("============================================\n");

    return 0;
}
