#include "config.c"
#include "filehandler.c"
#include "helper.c"



int gettotalstaffCount();
int getlaststaffid();

food *searchItem();


int addItem()
{
    char itemName[30];
    float price;
    printf("\n\n\t_________________________ADD CUISINES_________________________\n");
    printf("\n\n\tITEM NAME : "); strcpy(itemName,readstring());
    printf("\n\tITEM PRICE : "); scanf("%f",&price);
    
    food *newItem=NULL;
    newItem=malloc(sizeof(food));
    
    itemIdgenerator=getLastitem();
    newItem->item_id = ++itemIdgenerator;
    strcpy(newItem->foodname,itemName);
    newItem->price = price;

    int result=writeItem(newItem);
    int response=(result==1) ? itemIdgenerator:0;
    free(newItem);
    return response;
}



void viewAllItems()
{
    food *cuisines;
    cuisines = getAllCuisines();
    int totalCuisineCount=getTotalCuisineCount();
    printf("\n\n\t_________________________CUISINES AVILABLE_________________________\n");
    printf("\n\tSL \t\t\t CUISINE NAME \t\t PRICE ");
    printf("\n\t------------------------------------------------------------");
    for(int i=0;i<totalCuisineCount;i++)
    {
        printf("\n\t%d \t\t\t %s \t\t\t %f", cuisines[i].item_id,cuisines[i].foodname,cuisines[i].price);
    }
}

food *searchfood()
{
    int id;
    printf("\n\tENTER ITEM ID:");
    scanf("%d",&id);
    food *response=getitem(id);
    return response;
}

int removeFood()
{
    int result=0;
    food *food_to_delete=searchfood();
    if(food_to_delete!=NULL)
    {
        printf("\n\n\t_________________________DELETE CUISINE_________________________");
        printf("\n\n\tFOOD_ID \t\tFOOD_NAME \t\t\tPRICE ");
        printf("\n\t------------------------------------------------------------");
        printf("\n\t%d\t\t\t%s\t\t\t%f",food_to_delete->item_id,food_to_delete->foodname,food_to_delete->price);
        result = deleteFood(food_to_delete);
        free (food_to_delete);

    }
    return result;
}



int editItem()
{
    char foodName[30];
    float price;
    int result=0;
    food *food_to_find = searchfood();
    if(food_to_find!=NULL)
    {
        printf("Old Food Details...\n");
        printf("_______");
        printf("ITEM_ID: %d\nFOOD_NAME: %s\nPRICE: %f",food_to_find->item_id,food_to_find->foodname,food_to_find->price);
        printf("\n ENTER NEW FOOD DETAILS: \n");
        printf("_______");
        printf("FOOD NAME: ");
        strcpy(foodName,readstring());
        printf("\n ENTER PRICE: ");
        scanf("%f",&price);
        
        food *newfood=NULL;
        newfood=malloc(sizeof(food));
        newfood->item_id= food_to_find->item_id;
        strcpy(newfood->foodname,foodName);
        printf("%f",price);

        result=updatedFood(newfood);
        free(food_to_find);
    }
    return result;
}