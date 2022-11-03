
int getTotalDatasCount(); 
int getTotalReserveCount();


int writeRecord(records *itemObj)
{
    FILE *fp=NULL;
    fp=fopen(recordDatas,"ab+");
    if(fp==NULL)
    {
        return 0;
    }
    else
    {
        fwrite(itemObj,sizeof(records),1,fp);
        fclose(fp);
        return 1;
    }
}


int writeRecordFile(records *itemObj)
{
    FILE *fp=NULL;
    fp=fopen(TXTFILE,"ab+");
    if(fp==NULL)
    {
        return 0;
    }
    else
    {
        fwrite(itemObj,sizeof(records),1,fp);
        fclose(fp);
        return 1;
    }
}


int getTotalDatasCount()
{
    int count = 0;
    FILE *fp = NULL;
    fp = fopen(recordDatas,"rb");
    records *data_to_find =NULL;
    if(fp != NULL)
    {
        data_to_find = (records*)malloc(sizeof(records));
        while (fread(data_to_find,sizeof(records),1,fp))
        {
            count++;
        }
        fclose(fp);
    }
    return count;
}



records *getdata(int id)
{
    FILE *fp=NULL;
    fp=fopen(recordDatas,"rb");
    records *item_to_find=NULL;
    if(fp==NULL)
    {
        return item_to_find;
    }
    else
    {
        item_to_find=(records*)malloc(sizeof(records));
        while(fread(item_to_find,sizeof(records),1,fp))
        {
            if(item_to_find->month==id)
            {
                fclose(fp);
                return item_to_find;
            }

        }
        fclose(fp);
        return item_to_find;
    }
     
}




records *getAlldatas()
{
    FILE *fp=NULL;
    fp = fopen(recordDatas,"rb");
    records *data_to_find = NULL;
    int totalDataCount = getTotalDatasCount();   
    records *Data = (records*)malloc(sizeof(records)*totalDataCount);
    if(fp!=NULL)
    {
        data_to_find = (records*) malloc(sizeof(records));
        for(int i=0; i<totalDataCount;i++)
        {
            fread(data_to_find,sizeof(records),1,fp);
            Data[i].recId = data_to_find->recId; //-> is to access read value
            // strcpy(Data[i].date, data_to_find->date);
            Data[i].amount = data_to_find->amount;
            Data[i].date = data_to_find->date;
            Data[i].month = data_to_find->month;
            Data[i].year = data_to_find->year;
        }
        fclose(fp);
    }
    return Data;

}





int deleteData(records *discardFoodObj)
{
    FILE *fp = NULL;
    FILE *fu = NULL;
    fp = fopen(recordDatas,"rb");
    fu = fopen(temp,"wb");

    if(fp==NULL || fu ==NULL)
    {
        return 0;

    }
    else
    {
        rewind(fp);
        records *keep_food = (records*)malloc(sizeof(records));
        while(fread (keep_food,sizeof(records),1,fp)==1)
        {
            if(discardFoodObj -> month !=keep_food->month)
                fwrite(keep_food,sizeof(records),1,fu);
        }
        fclose(fp);
        fclose(fu);
        free(keep_food);
        remove(recordDatas);
        rename(temp,recordDatas);
        return 1;

    }
}






table *getAll()
{
    FILE *fp=NULL;
    fp = fopen(reserve,"rb");
    table *data_to_find = NULL;
    int totalReserveCount = getTotalReserveCount();   
    table *Data = (table*)malloc(sizeof(table)*totalReserveCount);
    if(fp!=NULL)
    {
        data_to_find = (table*) malloc(sizeof(table));
        for(int i=0; i<totalReserveCount;i++)
        {
            fread(data_to_find,sizeof(table),1,fp);
            Data[i].table_id = data_to_find->table_id; //-> is to access read value
            // strcpy(Data[i].date, data_to_find->date);
            Data[i].tableno = data_to_find->tableno;
            Data[i].capacity = data_to_find->capacity;
            strcpy(Data[i].c_name, data_to_find->c_name);
            strcpy(Data[i].contact, data_to_find->contact);


        }
        fclose(fp);
    }
    return Data;

}



int getTotalReserveCount()
{
    int count = 0;
    FILE *fp = NULL;
    fp = fopen(reserve,"rb");
    table *data_to_find =NULL;
    if(fp != NULL)
    {
        data_to_find = (table*)malloc(sizeof(table));
        while (fread(data_to_find,sizeof(table),1,fp))
        {
            count++;
        }
        fclose(fp);
    }
    return count;
}