

int getTotalCuisineCount(); 
int getLastitem();


int writeItem(food *itemObj)
{
    FILE *fp=NULL;
    fp=fopen(menulist,"ab+");
    if(fp==NULL)
    {
        return 0;
    }
    else
    {
        fwrite(itemObj,sizeof(food),1,fp);
        fclose(fp);
        return 1;
    }
}


int getLastitem()
{
    int Lastitem=0;
     FILE *fp=NULL;
     fp=fopen(menulist,"rb");
     food *item_to_find=NULL;
     if(fp!=NULL)
     {
        item_to_find=(food*)malloc(sizeof(food));
        while(fread(item_to_find,sizeof(food),1,fp))
        {
            Lastitem=item_to_find->item_id;

        }
        fclose(fp);
     }
     return Lastitem;
}



food *getAllCuisines()
{
    FILE *fp=NULL;
    fp = fopen(menulist,"rb");
    food *food_to_find = NULL;
    int totalBookCount = getTotalCuisineCount();   
    food *cuisines = (food*)malloc(sizeof(food)*totalBookCount);
    if(fp!=NULL)
    {
        food_to_find = (food*) malloc(sizeof(food));
        for(int i=0; i<totalBookCount;i++)
        {
            fread(food_to_find,sizeof(food),1,fp);
            cuisines[i].item_id = food_to_find->item_id; //-> is to access read value
            strcpy(cuisines[i].foodname, food_to_find->foodname);
            cuisines[i].price = food_to_find->price;
        }
        fclose(fp);
    }
    return cuisines;

}


int getTotalCuisineCount()
{
    int count = 0;
    FILE *fp = NULL;
    fp = fopen(menulist,"rb");
    food *book_to_find =NULL;
    if(fp != NULL)
    {
        book_to_find = (food*)malloc(sizeof(food));
        while (fread(book_to_find,sizeof(food),1,fp))
        {
            count++;
        }
        fclose(fp);
    }
    return count;
}


food *getitem(int id)
{
    FILE *fp=NULL;
    fp=fopen(menulist,"rb");
    food *item_to_find=NULL;
    if(fp==NULL)
    {
        return item_to_find;
    }
    else
    {
        item_to_find=(food*)malloc(sizeof(food));
        while(fread(item_to_find,sizeof(food),1,fp))
        {
            if(item_to_find->item_id==id)
            {
                fclose(fp);
                return item_to_find;
            }

        }
        fclose(fp);
        return item_to_find;
    }
     
}



int deleteFood(food *discardFoodObj)
{
    FILE *fp = NULL;
    FILE *fu = NULL;
    fp = fopen(menulist,"rb");
    fu = fopen(temp,"wb");

    if(fp==NULL || fu ==NULL)
    {
        return 0;

    }
    else
    {
        rewind(fp);
        food *keep_food = (food*)malloc(sizeof(food));
        while(fread (keep_food,sizeof(food),1,fp)==1)
        {
            if(discardFoodObj -> item_id !=keep_food->item_id)
                fwrite(keep_food,sizeof(food),1,fu);
        }
        fclose(fp);
        fclose(fu);
        free(keep_food);
        remove(menulist);
        rename(temp,menulist);
        return 1;

    }
}




int updatedFood(food *updatedFoodObj)
{
    FILE *fp = NULL;
    FILE *fu = NULL;
    fp = fopen(menulist,"rb");
    fu = fopen(temp,"wb");
    if(fu==NULL || fu==NULL)
    {
        return 0;
    }
    else {
        rewind(fp);
        food *no_change_food=(food *) malloc(sizeof(food));
        while(fread(no_change_food,sizeof(food),1,fp)==1)
        {
            if(updatedFoodObj->item_id=no_change_food->item_id)
            {
                fwrite(no_change_food,sizeof(food),1,fu);
            }
            else {
                fwrite(updatedFoodObj,sizeof(food),1,fu);
            }
        }
        fclose(fp);
        fclose(fu);
        free(no_change_food);
        remove(menulist);
        rename(temp,menulist);
        return 1;
    }
}




