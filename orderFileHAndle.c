
int getLastOrderId();
int getTotalOrdersCount();


int writeOrder(orders *bookObj)
{
    FILE *fp=NULL;
    fp = fopen(orderTemp,"ab+");
    if(fp == NULL)
    {
        return 0; 
    }
    else
    {
        fwrite(bookObj,sizeof(orders),1,fp);
        fclose(fp);
        return 1;
    }
}


int getLastOrderID()
{
    int lastorderid =0;
    FILE *fp = NULL;
    fp = fopen(orderTemp,"rb");
    orders *orders_to_find = NULL;
    if(fp !=NULL)
    {
        orders_to_find=(orders *)malloc(sizeof(orders));   //doubt
        while(fread(orders_to_find, sizeof(orders),1,fp))
        {
            lastorderid = orders_to_find->token;
        }
        fclose(fp);
    }
    return lastorderid;
}

food * getfood(int id)
{
    FILE *fp=NULL;
    fp=fopen(menulist,"rb");
    food *food_to_find=NULL;
    if(fp==NULL)
    {
        return food_to_find;
    }
    else
    {
        food_to_find=(food*)malloc(sizeof(food));

        while(fread(food_to_find,sizeof(food),1,fp))
        {
            if(food_to_find->item_id==id)
            {
                fclose(fp);
                return food_to_find;
            }
        }
        fclose(fp);
        return food_to_find;
    }
}



orders * getAllOrders()
{
    FILE *fp = NULL;
    fp = fopen(orderTemp,"rb");
    orders *orders_to_find=NULL;
    int totalOrdercount = getTotalOrdersCount();
    orders *inpatients=(orders*)malloc(sizeof(orders) * totalOrdercount);
    if(fp != NULL)
    {
        orders_to_find=(orders*)malloc(sizeof(orders));
        
        for(int i=0;i<totalOrdercount;i++)
        {
            fread(orders_to_find,sizeof(orders),1,fp);
            inpatients[i].token=orders_to_find->token;
            inpatients[i].qty_=orders_to_find->qty_;
            //strcpy(inpatients[i].admitted_date,inpatient_to_find->admitted_date);
            //inpatients[i].room_num=inpatient_to_find->room_num;
            //strcpy(inpatients[i].disease,inpatient_to_find->disease);
            inpatients[i].item_id=orders_to_find-> item_id;

            food * food_to_find=getfood(orders_to_find->item_id);// to find doctor name(connection between patient and doctor)
                  if(food_to_find!=NULL)
                  {
                   food_to_find->foodname;
                   food_to_find->price;
                  }
            strcpy(inpatients[i].food_name,food_to_find->foodname);
            inpatients[i].price_=food_to_find-> price;


        }
    fclose(fp);
    }
return inpatients;
}



int getTotalOrdersCount()
{
    int count=0;
    FILE *fp=NULL;
    fp=fopen(orderTemp,"rb");
    orders *order_to_find=NULL;
    if(fp!=NULL)
    {
        order_to_find=(orders*)malloc(sizeof(orders));

        while(fread(order_to_find,sizeof(orders),1,fp))
        {
            count++;
        }
        fclose(fp);
    }
    return count;
}





int deleteOrders()
{
    FILE *fp=NULL;
    fp = fopen(orderTemp,"w");
    if(fp == NULL)
    {
        return 0; 
    }
    else
    {
        fprintf(fp,"\n\n");
        
    }
}