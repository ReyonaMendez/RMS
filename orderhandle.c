#include "orderFileHAndle.c"
#include "adminrecFileHandle.c"




int addRecord(int amount)
{
    time_t t = time(NULL);
    int month,date,year;
    // printf("\n Current date and time is : %s", ctime(&t));
    struct tm tm = *localtime(&t);
    date = tm.tm_mday;
    month =  tm.tm_mon+1;
    year = tm.tm_year+1900;
    // printf("Current Date: %d-%d-%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    // getch();


    records *newRecord = NULL;
    newRecord = malloc(sizeof(records));

    newRecord->recId = ++recordIdgenerator;
    // strcpy(newRecord->date,&tm);
    newRecord->amount = amount;
    newRecord->date = date;
    newRecord->month = month;
    newRecord->year = year;
    int result = writeRecord(newRecord);
    int response=(result==1) ? recordIdgenerator :0;
    free(newRecord);

}




int viewAllAdmittedOrders()
{
    orders *Allorder;
    Allorder =getAllOrders();
    time_t t = time(NULL);
    int month,date,year,h,m,s;
    // printf("\n Current date and time is : %s", ctime(&t));
    struct tm tm = *localtime(&t);
    date = tm.tm_mday;
    month =  tm.tm_mon+1;
    year = tm.tm_year+1900;
    h = tm.tm_hour;
    m = tm.tm_min;
    s = tm.tm_sec;
    int totalOrdercount=getTotalOrdersCount();
    int grandtotal=0;
   
    printf("\n\n\n\n\t*****************************************************************************************************\n");
    printf("\n\t\t\t\t\t\t  BILL \t\t\t\n\n");
    printf("\tDATE:\t %d-%d-%d", date, month, year);
    printf("\t\t\t\t\t\t\t\tTIME:\t %d:%d:%d",h,m,s);

    printf("\n\n\t*****************************************************************************************************\n");
    
    printf("\n\t ITEM ID \t\t ITEM NAME \t\t PRICE \t\t QUANTITY \t\t TOTAL \t\t \n");
    printf("\t=====================================================================================================\n");
    
    for(int i=0;i<totalOrdercount;i++)
    {
        int total =0;
        total = Allorder[i].price_ * Allorder[i].qty_ ;
        grandtotal = grandtotal+total;
       
        printf("\n\t %d\t\t\t%s\t\t%f\t\t%d\t\t\t%d\t\t",Allorder[i].item_id,Allorder[i].food_name,Allorder[i].price_,Allorder[i].qty_,total);
    }

    printf("\n\t=====================================================================================================");
    printf("\n\n\t\t\t\t\tFINAL TOTAL \t\t\t\t%d",grandtotal);
    printf("\n\t=====================================================================================================");  
    printf("\n\n\t------------------------------------------- THANK YOU ^_^ -------------------------------------------");
    printf("\n\n\t*****************************************************************************************************\n\n\n\n");
    
    addRecord(grandtotal);
    free(Allorder);

}








int addOrder()
{

    char authorname[60],bookname[60];
    int itemId=0,qty=0,cho=0;

    viewAllItems();
    printf("\n\n\n");
    do
    {
        
        printf("\n\tEnter Item id:"); scanf("%d",&itemId);
        printf("\n\tEnter Quantity :"); scanf("%d",&qty);

        orders *newOrder = NULL; //To avoid gurbage value;
        newOrder = malloc(sizeof(orders));

        OrderIdGenerator = getLastOrderID();    //FileHandler.c
        newOrder->token = ++OrderIdGenerator;
        newOrder->item_id=itemId;
        newOrder->qty_ = qty;
        int result = writeOrder(newOrder);
        int response=(result==1) ? OrderIdGenerator :0;
        printf("\n\n\tDo you want to continue ordering (y=1 / n=0) :"); scanf("%d",&cho);
        free(newOrder);
        
    }while(cho!=0);
    // return response;





   
    viewAllAdmittedOrders();
    
    deleteOrders();
      
}


