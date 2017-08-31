/*
 * C program to display the billing(point of sale) of items in a store / shop
 * The inventory maintains details such as name, price, quantity,customer paid
 * amount, customer balance and manufacturing date of each item.
 * It then prints a text document receipt for the transactions made.
 */
#include <stdio.h>
 
int main()
{
	FILE *bill;
	bill = fopen("Receipt Deftec Billing.txt","w+");
	 
    struct date
    {
        int day;
        int month;
        int year;
    };
    struct details
    {
        char name[20];
        int price;
        int code;
        int qty;       
        struct date mfg;
    };
    struct details item[50];
    int n, i;
 
    printf("Enter number of items:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {       
        printf("Item name: \t");
        scanf("%s", item[i].name);      
        printf("Item code: \t");
        scanf("%d", &item[i].code);    
        printf("Quantity: \t");
        scanf("%d", &item[i].qty);
        printf("price: \t");
        scanf("%d",  &item[i].price);      
        printf("Manufacturing date(dd-mm-yyyy): ");
        scanf("%d-%d-%d", &item[i].mfg.day,
        &item[i].mfg.month, &item[i].mfg.year);
    }
    printf("\n             *****  DEFTEC BILLING MANAGEMENT SYSTEM ***** \n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("S.N.|    NAME           |   CODE   |  QUANTITY |  @PRICE  |  TOTAL PRICE   | MFG.DATE \n");
    printf("---------------------------------------------------------------------------------------\n");
  
   float total,cust_amount,balance;
   
    for (i = 0; i < n; i++){   
        printf("%d     %-15s        %-d          %-5d     %-5d         %-5d        %d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,
        item[i].price, item[i].price*item[i].qty,  item[i].mfg.day, item[i].mfg.month,
        item[i].mfg.year);        
        total += item[i].price*item[i].qty;       
        }
    printf("TOTAL COST:                                                     %.2f \n", total);
	
	printf("\nENTER CUSTOMER AMOUNT:  \t\t\t\t\t");
	scanf("%f",&cust_amount);
    balance = cust_amount-total;
    printf("CUSTOMER BALANCE:                                               %.2f \n", balance);
    printf("---------------------------------------------------------------------------------------\n");
    
	    
    
    //Printing on the receipt on a file document    
    fprintf(bill,"\n             *****  DEFTEC BILLING MANAGEMENT SYSTEM ***** \n");
    fprintf(bill,"---------------------------------------------------------------------------------------\n");
    fprintf(bill,"S.N.|    NAME           |   CODE   |  QUANTITY |  @PRICE  |  TOTAL PRICE   | MFG.DATE \n");
    fprintf(bill,"---------------------------------------------------------------------------------------\n");
   
    for (i = 0; i < n; i++){   
        fprintf(bill,"%d     %-15s        %-d          %-5d     %-5d         %-5d        %d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,
        item[i].price, item[i].price*item[i].qty,  item[i].mfg.day, item[i].mfg.month,
        item[i].mfg.year);              
        }
    fprintf(bill,"TOTAL COST:                                                     %.2f \n", total);	
	fprintf(bill,"\nCUSTOMER AMOUNT:  \t\t\t\t\t\t %.2f \n", cust_amount);
    fprintf(bill,"CUSTOMER BALANCE:                                               %.2f \n", balance);
    fprintf(bill,"---------------------------------------------------------------------------------------\n");    
    
    fclose(bill);    
    return 0;
}