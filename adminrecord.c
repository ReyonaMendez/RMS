
records *searchData();








void viewAllRecords()
{
    records *datas = NULL;
    datas = getAlldatas();
    int totalRecordCount=getTotalDatasCount();
    printf("\n\n\t_________________________RECORDED ORDER DATAS_________________________\n");
    printf("\n\tID \t\t\t AMOUNT \t\t DATE ");
    printf("\n\t------------------------------------------------------------");
    for(int i=0;i<totalRecordCount;i++)
    {
        printf("\n\t%d \t\t\t %d \t\t\t %d-%d-%d", datas[i].recId, datas[i].amount, datas[i].date, datas[i].month, datas[i].year);
    }
}


records *searchData()
{
    int id;
    printf("\n\tENTER MONTH:");
    scanf("%d",&id);
    records *response=getdata(id);
    return response;
}

int removeData()
{
    int result=0;
    records *food_to_delete=searchData();
    if(food_to_delete!=NULL)
    {
        printf("\n\n\t_________________________DELETE DATA_________________________");
        printf("\n\n\tID \t\tAMOUNT \t\t\tDATE ");
        printf("\n\t------------------------------------------------------------");
        printf("\n\t%d\t\t\t%d\t\t\t%d-%d-%d",food_to_delete->recId, food_to_delete->amount,food_to_delete->date, food_to_delete->month, food_to_delete->year);
        result = deleteData(food_to_delete);
        free (food_to_delete);

    }
    return result;
}



void viewAllReservations()
{

    table *datas = NULL;
    datas = getAll();
    int totalRecordCount=getTotalReserveCount();
    printf("\n\n\t________________________________RESERVATIONS________________________________\n");

    printf("\n\tID \tCUSTOMER NAME\t\tCONTACT\t\t\tSEATS\t\tTABLENO");
    printf("\n\t----------------------------------------------------------------------------");
   
    for(int i=0;i<totalRecordCount;i++)
    {
        printf("\n\t%d\t%s\t\t%s\t\t %d\t\t%d", datas[i].table_id, datas[i].c_name, datas[i].contact, datas[i].capacity, datas[i].tableno);
    }
    free(datas);
}




void record_fun()
{
    int ch;
    int success;
    int infinite = 1;



    system("clear");

        printf("\n\n\n\t****************************************** ADMIN MANAGEMENT *****************************************");
        printf("\n\n\t1. VIEW SALES");
        // printf("\n\n\t2. REMOVE DATAS");
        // printf("\n\n\t3. FIND DATAS");
        printf("\n\n\t2. VIEW RESERVATIONS");



        printf("\n\n\n\tENTER YOUR CHOICE :"); scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:
                    viewAllRecords();
                    break;
            
            

            // case 2:
            //         success = removeData();
            //         if (success>0)
            //         {
            //             printf("\n\n\tSUCCESSFULLY DELETED");
            //         }
            //         else
            //         {
            //             printf("\n\n\tNOT FOUND, INVALID");
            //         }
                        
            //         break;

                
            //     case 3:
            //         records *item_to_find=searchData();
            //         int totalRecordCount=getTotalDatasCount();
            //         if(item_to_find!=NULL )
            //         {
            //             printf("\n\n\t_________________________ DATA RECORDS _________________________\n");
            //             printf("\n\tID \t\tAMOUNT \t\t\tDATE ");
            //             printf("\n\t------------------------------------------------------------");
            //             for(int i=0;i<totalRecordCount;i++)
            //             {
            //                 printf("\n\t%d\t\t%d\t\t%d-%d-%d",item_to_find->recId,item_to_find->amount,item_to_find->date, item_to_find->month, item_to_find->year);
            //             }
            //             free(item_to_find);
            //         }
            //         else
            //         {
            //             printf("\n\n\tNO ITEMS FOUND");
            //         }
            //         break;

                case 2:
                        viewAllReservations();  
                        break;



            default :
                printf("\n\tINVALID CHOICE");
    
        }
    
    




}




