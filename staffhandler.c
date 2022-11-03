// #include "structure.c"
#include "workershandle.c"


int staff_fun()
{
      int choice;
    int infinite = 1;
    int success,c;
    do 
    {
          printf("\n\n\n\t*************************STAFF MODULE*************************");

        printf("\n\n\t1. ADD STAFF");
        printf("\n\n\t2. REMOVE STAFF");
        printf("\n\n\t3. UPDATE STAFF");
        printf("\n\n\t4. VIEW STAFF");
        printf("\n\n\t5. SEARCH STAFF");
        printf("\n\n\t6. EXIT");



        printf("\n\n\n\tENTER YOUR CHOICE :"); 
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                  success=addstaff();
                  if(success>0)
                  {
                        printf("\n\tSTAFF ADDED SUCCESSFULLY :%d\n",success);
                  }
                  else
                  {
                        printf("\n\tTRY AGAIN LATER\n");
                  }
                  break;
            case 2:
                  success = removestaff();

                  if(success > 0){

                        printf("\n\t UPDATED SUCCESSFULLY");

                  }      
                  else{

                        printf("\n\tNO STAFF DETAILS FOUND");

                  }
                  break;

            case 3:
                  success = editstaff();

                  if(success > 0){

                        printf("\n\tSTAFF UPDATED SUCCESSFULLY");

                  }
                  else{

                        printf("\n\tNO STAFF DETAILS FOUND");
            

                  }
                  break;
            

            case 4:
                  viewallstaff();
                  break;

            case 5:
                  printf("\n");
                  staff *staff_to_find = searchstaff();
                  if(staff_to_find != NULL){

                        printf("\n\tSTAFF ID : %d\n\tSTAFF NAME : %s\n\t",staff_to_find->staff_id,staff_to_find->staff_name);

                  }
                  else{

                        printf("\n\tNO STAFF AVAILABLE !!!");

                  }
                  break;

            case 6:
                  // break;
                  exit(1);     

            default:
                 
                  printf("\n\t INVALID INPUT");
                  break;
        } 
      }
    while(infinite>0);
    return 0;
 }  