#include "header.c"
#include "itemshandler.c"
#include "orderhandle.c"
#include "staffhandler.c"
#include "adminrecord.c"
#include "tablehandler.c"



int main()
{
    int choice;
    int infinite = 1;
    int success;
    // char admin_id[30],password[30];
    // system("clear");
    // printf("\n\n\t\t\t*************************HELLO, WELCOME TO RESTAURANT MANAGEMENT SYSTEM************************");
    // printf("\n\n\t\t\tUSERNAME : "); scanf("%s",admin_id);
    // printf("\n\n\t\t\tPASSWORD : "); scanf("%s",password);
    // if((admin_id == "pass123") && (password == "pass123"))
    // {

    
    system("clear");
    do 
    {
        printf("\n\n\n\t************************************ RESTAURANT MANAGEMENT SYSTEM ***********************************");
    
        printf("\n\n\t1. ITEMS");
        printf("\n\n\t2. CUISINES LIST");
        printf("\n\n\t3. TABLE RESERVATION");
        printf("\n\n\t4. ORDER AND BILL");
        printf("\n\n\t5. STAFF MODULE");
        printf("\n\n\t6. BILLINGS & RESERVATIONS");
        printf("\n\n\t7. CLEAR SCREEN");
        printf("\n\n\t8. EXIT APPLICATION");



        printf("\n\n\n\tENTER YOUR CHOICE :"); scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                items();
                break;

            case 2:
                viewAllItems();
                break;
            case 3:
                    int c;
                    printf("\n\n\n\t_____________________________________WELCOME TO RESERVATION SYSTEM___________________________________\n");
                    
                //     printf("\n\tENTER NUMBER OF CUSTOMERS : "); scanf("%d",&c);
                    allottable();
                    break;
            case 4:
                    addOrder();
                    break;

            case 5:
                    staff_fun();
                    break;

            case 6:
                    record_fun();
                    break;
            
            
            case 7:
                    system("clear");
                    break;
            case 8:
                printf("\n\n\n");
                exit(1);    
                
        }
    }while(infinite>0);
    // }
    // else
    // {
    //     printf("\n\n\t\tACCESS DENIDE");
    // }
        
    return 0;
}