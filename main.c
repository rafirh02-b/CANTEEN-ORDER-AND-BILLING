#include <stdio.h>

/* Global Variables */
int code, quantity;
double price, subtotal, discount, total;
double payment, change;

/* Function Declarations */
void showMenu(void);
double getPrice(int code);
double calculateSubtotal(double price, int quantity);
double calculateDiscount(double subtotal);
double calculateTotal(double subtotal, double discount);
void printBill(void);
void takePayment(void);

int main(void)
{
    /* Display Menu */
    showMenu();

    /* Get Item Code */
    printf("\nEnter item code: ");
    scanf("%d", &code);

    /* Get Item Price Automatically */
    price = getPrice(code);

    if (price == 0)
    {
        printf("Invalid item code!\n");
        return 0;
    }

    printf("Selected item price: %.2f Tk\n", price);

    /* Get Quantity */
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0)
    {
        printf("Invalid quantity!\n");
        return 0;
    }

    /* Calculate Bill */
    subtotal = calculateSubtotal(price, quantity);
    discount = calculateDiscount(subtotal);
    total = calculateTotal(subtotal, discount);

    /* Display Bill and Take Payment */
    printBill();
    takePayment();

    return 0;
}

/* Display Menu */
void showMenu(void)
{
    printf("============================================\n");
    printf("          CANTEEN ORDER AND BILLING         \n");
    printf("============================================\n");

    printf("--------------------------------------------\n");
    printf("%-6s%-20s%-12s%10s\n",
           "CODE", "ITEM", "CATEGORY", "PRICE");
    printf("--------------------------------------------\n");

    printf("%-6d%-20s%-12s%10.2f\n",
           101, "Chicken Meal", "Meal", 180.00);

    printf("%-6d%-20s%-12s%10.2f\n",
           102, "Beef Burger", "Meal", 220.00);

    printf("%-6d%-20s%-12s%10.2f\n",
           103, "French Fries", "Snack", 80.00);

    printf("%-6d%-20s%-12s%10.2f\n",
           104, "Samosa", "Snack", 30.00);

    printf("%-6d%-20s%-12s%10.2f\n",
           105, "Soft Drink", "Drink", 40.00);

    printf("%-6d%-20s%-12s%10.2f\n",
           106, "Mineral Water", "Drink", 20.00);

    printf("--------------------------------------------\n");
}

/* Get Price Using Item Code */
double getPrice(int code)
{
    if (code == 101)
        return 180.00;
    else if (code == 102)
        return 220.00;
    else if (code == 103)
        return 80.00;
    else if (code == 104)
        return 30.00;
    else if (code == 105)
        return 40.00;
    else if (code == 106)
        return 20.00;
    else
        return 0.0;
}

/* Calculate Subtotal */
double calculateSubtotal(double price, int quantity)
{
    return price * quantity;
}

/* Calculate 15 Percent Discount */
double calculateDiscount(double subtotal)
{
    return subtotal * 0.15;
}

/* Calculate Final Total */
double calculateTotal(double subtotal, double discount)
{
    return subtotal - discount;
}

/* Display Customer Bill */
void printBill(void)
{
    printf("\n============================================\n");
    printf("                 CUSTOMER BILL             \n");
    printf("============================================\n");

    printf("Item Code:       %d\n", code);
    printf("Unit Price:      %.2f Tk\n", price);
    printf("Quantity:        %d\n", quantity);

    printf("--------------------------------------------\n");

    printf("Subtotal:        %.2f Tk\n", subtotal);
    printf("Discount (15%%):  %.2f Tk\n", discount);
    printf("Total Bill:      %.2f Tk\n", total);

    printf("============================================\n");
}

/* Take Payment and Calculate Change */
void takePayment(void)
{
    printf("\nEnter payment amount: ");
    scanf("%lf", &payment);

    if (payment < total)
    {
        printf("\nInsufficient payment!\n");
        printf("You still owe: %.2f Tk\n", total - payment);
        return;
    }

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


