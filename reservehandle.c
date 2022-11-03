int allottable();
int getLasttable();
// int getTotalReserveCount();


int writetable(table *tableObj)
{
    FILE *fp=NULL;
    fp=fopen(reserve,"ab+");
    if(fp==NULL)
    {
        return 0;
    }
    else
    {
        fwrite(tableObj,sizeof(table),1,fp);
        fclose(fp);
        return 1;
    }
}
int getLasttable()
{
    int Lasttable=0;
     FILE *fp=NULL;
     fp=fopen(reserve,"rb");
     table *table_to_find=NULL;
     if(fp!=NULL)
     {
        table_to_find=(table*)malloc(sizeof(table));
        while(fread(table_to_find,sizeof(table),1,fp))
        {
            Lasttable=table_to_find->table_id;

        }
        fclose(fp);
     }
     return Lasttable;
}



