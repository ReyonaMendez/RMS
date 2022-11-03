
#include  "reservehandle.c"

int getLasttable();

int allottable()
{
    char c_name[50],contact[11];

    int id, tableno=0,capacity=0,amt=0;
    printf("\n\tCUSTOMER NAME :"); strcpy(c_name,readstring());
    printf("\n\tCUSTOMER PHONE:"); strcpy(contact,readstring());
    printf("\n\tNO OF PERSONS:"); scanf("%d",&capacity);
    printf("\n\tENTER TABLE NO : "); scanf("%d",&tableno);
    amt = capacity * 50;
    
    
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

    table *newtable=NULL;
    newtable=malloc(sizeof(table));
    tableIdgenerator=getLasttable();
    newtable->table_id=++tableIdgenerator;
    strcpy(newtable->c_name,c_name);
    strcpy(newtable->contact,contact);
    newtable->capacity=capacity;
    newtable->tableno=tableno;

    int result=writetable(newtable);
    int response=(result==1)?tableIdgenerator:0;
    free(newtable);
    printf("\n\n\n\t**************************************************************");
    printf("\n\t\t\t RESERVED SUCCESSFULLY\n");
    printf("\tDATE:\t %d-%d-%d \t\t\tTIME:\t%d:%d:%d",date, month, year, h, m, s);
    printf("\n\t==============================================================");
    printf("\n\n\tCUSTOMER NAME \t: %s",c_name);
    printf("\n\tCUSTOMER PHONE \t: %s",contact);
    printf("\n\tNUMBER OF SEATS\t: %d",capacity);
    printf("\n\n\tTABLE NO       \t: %d",tableno);
    printf("\n\t==============================================================");
    printf("\n\t\t\t\tAMOUNT\t\t\t%d",amt);
    printf("\n\t==============================================================");
    printf("\n\t\t\tTHANK YOU! ENJOY OUR DINNING ^_^ ");
    printf("\n\t..............................................................");
    printf("\n\n\n");
    // free(newtable);
    return response;
}


/*

available tables


if book a table dec that table
table booked successfully

date and time of booking
after 5 hour free that table



*/


// void viewAllReservations()
// {

//     table *datas = NULL;
//     datas = getAll();
//     int totalRecordCount=getTotalReserveCount();
//     printf("\n\n\t_________________________RESERVATIONS_________________________\n");
//     printf("\n\tID \tCUSTOMER NAME\t\tCONTACT\t\tSEATS\t\tTABLENO");
//     printf("\n\t------------------------------------------------------------");
//     for(int i=0;i<totalRecordCount;i++)
//     {
//         printf("\n\t%d\t%s\t\t%s\t\t %d\t\t%d", datas[i].table_id, datas[i].c_name, datas[i].contact, datas[i].capacity, datas[i].tableno);
//     }
// }
