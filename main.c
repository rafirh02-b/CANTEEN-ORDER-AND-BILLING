#include <stdio.h>

int code, quantity;
double price, subtotal, discount, total;
double payment, change;
char choice;

void showMenu(void);
double getPrice(int code);
double calculateSubtotal(double price, int quantity);
double calculateDiscount(double subtotal);
double calculateTotal(double subtotal, double discount);
void printBill(void);
void takePayment(void);

int main(void)
{
    showMenu();

    subtotal = 0;

    do
    {
        printf("\nEnter item code: ");
        scanf("%d", &code);

        price = getPrice(code);

        if (price == 0)
        {
            printf("Invalid item code!\n");
        }
        else
        {
            printf("Selected item price: %.2f Tk\n", price);

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity <= 0)
            {
                printf("Invalid quantity!\n");
            }
            else
            {
                subtotal = subtotal + calculateSubtotal(price, quantity);

                printf("Item added successfully!\n");
            }
        }

        printf("\nDo you want to order another item? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    if (subtotal <= 0)
    {
        printf("\nNo valid items were ordered.\n");
        return 0;
    }

    discount = calculateDiscount(subtotal);
    total = calculateTotal(subtotal, discount);

    printBill();
    takePayment();

    return 0;
}

void showMenu(void)
{
    printf("============================================\n");
    printf("          CANTEEN ORDER AND BILLING         \n");
    printf("============================================\n");

    printf("--------------------------------------------\n");
    printf("%-6s%-20s%-12s%10s\n",
           "CODE", "ITEM", "CATEGORY", "PRICE");
    printf("--------------------------------------------\n");

    printf("%-6d%-20s%-12s%10.2f\n", 101, "Chicken Meal", "Meal", 180.00);

    printf("%-6d%-20s%-12s%10.2f\n", 102, "Beef Burger", "Meal", 220.00);

    printf("%-6d%-20s%-12s%10.2f\n", 103, "French Fries", "Snack", 80.00);

    printf("%-6d%-20s%-12s%10.2f\n", 104, "Samosa", "Snack", 30.00);

    printf("%-6d%-20s%-12s%10.2f\n", 105, "Soft Drink", "Drink", 40.00);

    printf("%-6d%-20s%-12s%10.2f\n", 106, "Mineral Water", "Drink", 20.00);

    printf("--------------------------------------------\n");
}

double getPrice(int code)
{
    switch (code)
    {
        case 101:
            return 180.00;

        case 102:
            return 220.00;

        case 103:
            return 80.00;

        case 104:
            return 30.00;

        case 105:
            return 40.00;

        case 106:
            return 20.00;

        default:
            return 0.0;
    }
}

double calculateSubtotal(double price, int quantity)
{
    return price * quantity;
}

double calculateDiscount(double subtotal)
{
    return subtotal * 0.15;
}

double calculateTotal(double subtotal, double discount)
{
    return subtotal - discount;
}

void printBill(void)
{
    printf("\n============================================\n");
    printf("                 CUSTOMER BILL             \n");
    printf("============================================\n");

    printf("Subtotal:        %.2f Tk\n", subtotal);
    printf("Discount (15%%):  %.2f Tk\n", discount);
    printf("Total Bill:      %.2f Tk\n", total);

    printf("============================================\n");
}

void takePayment(void)
{
    do
    {
        printf("\nEnter payment amount: ");
        scanf("%lf", &payment);

        if (payment < total)
        {
            printf("Insufficient payment!\n");
            printf("You still owe: %.2f Tk\n", total - payment);
        }

    } while (payment < total);

    change = payment - total;

    printf("\n============================================\n");
    printf("               PAYMENT RECEIPT             \n");
    printf("============================================\n");

    printf("Total Bill:      %.2f Tk\n", total);
    printf("Payment:         %.2f Tk\n", payment);
    printf("Change:          %.2f Tk\n", change);

    printf("--------------------------------------------\n");
    printf("Thank you for ordering!\n");
    printf("Please visit again.\n");
    printf("============================================\n");
}




