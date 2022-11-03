
#include "structure.c"
#include "foodhandler.c"


int items()
{
    int choice, c, success;
    int infinite = 1;
    do 
    {
        printf("\n\n\n\n\n\t*************************ITEMS HANDLE************************");
    
        printf("\n\n\t1. ADD ITEM");
        printf("\n\n\t2. EDIT ITEM");
        printf("\n\n\t3. REMOVE ITEM ");
        printf("\n\n\t4. SEARCH ITEM");
        printf("\n\n\t5. LIST ITEM");



        printf("\n\n\n\tENTER YOUR CHOICE :"); scanf("%d",&choice);

        switch(choice)
        {
                case 1:
                        success=addItem();
                        if(success>0)
                        {
                                printf("\n\tITEM ADDED SUCCESSFULLY WITH ITEM ID:%d\n",success);
                        }       
                        else
                        {
                                printf("\n\tTRY AGAIN LATER\n");
                        }
                        goto jump;
                
                
                case 2:
                        success=editItem();
                        if (success>0)
                        {
                                printf("\n\t FOOD EDITED SUCCESSFULLY....\n");
                        }
                        else {
                                printf("\n\t No FOOD DETAILS FOUND.....\n");
                        }
                        break;
                        goto jump;
                
                case 3:
                        success = removeFood();
                        if (success>0)
                        {
                                printf("\n\n\tSUCCESSFULLY DELETED");
                        }
                        else
                        {
                                printf("\n\n\tNOT FOUND, INVALID FOOD ID");
                        }
                        
                        goto jump;

                
                case 4:
                        food *item_to_find=searchfood();
                        if(item_to_find!=NULL )
                        {
                                printf("\n\n\t_________________________CUISINE DETAILS_________________________\n");
                                        printf("\n\tFOOD_ID \t\tITEM NAME \t\t\tPRICE ");
                                        printf("\n\t------------------------------------------------------------");

                                printf("\n\t%d\t\t%s\t\t%f",item_to_find->item_id,item_to_find->foodname,item_to_find->price);
                                free(item_to_find);
                        }
                        else
                        {
                                printf("\n\n\tNO ITEMS FOUND");
                        }
                        goto jump;

                case 5:
                        viewAllItems();
                        goto jump;
                default:
                        jump :
                                printf("\n\n\tDO YOU WANT TO CONTINUE (Y=1 /N=0):");
                                scanf("%d",&c);
                                if(c==0)
                                        infinite=0;
                                        break;

        }
    }while(infinite>0);

    
        
}