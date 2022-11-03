// #include "config.c"
#include "stafffilehandler.c"
// #include "helper.c"

int addstaff()
{
    char staffname[30];
    printf("\n\t_________________________NEW STAFF ENTRY_________________________");

    printf("\n\tSTAFF NAME :");
    strcpy(staffname,readstring());
    

    staff *newstaff=NULL;
    newstaff=malloc(sizeof(staff));

    staffidgenerator=getlaststaffid();

    newstaff->staff_id=++staffidgenerator;
    strcpy(newstaff->staff_name,staffname);
    int result=writestaff(newstaff);

    int response=(result==1)?staffidgenerator:0;
    free(newstaff);
    return response;
}

staff* searchstaff(){

    int id;
    printf("\n\tENTER STAFF ID :");
    scanf("%d",&id);
staff *response = getstaff(id);
    return response;
}


void viewallstaff(){

    staff *staffs;
    staffs = getallstaffs();
    int totalstaffcount = gettotalstaffcount();


    printf("\n\t_________________________STAFF DETAILS_________________________");
    printf("\n\n\tSTAFF ID\t\tSTAFF NAME");
    printf("\n__________________________________________________");
    for(int i=0;i<totalstaffcount;i++){

        printf("\n\t%d\t\t%s",staffs[i].staff_id,staffs[i].staff_name);

    }
    // printf("\n**************************************************************************************");
}

int editstaff(){

    char staffname[30];
    int result = 0;

    staff *staff_to_edit = searchstaff();

    if(staff_to_edit != NULL){

        printf("\n\t_________________________OLD STAFF DETAILS_________________________");
        

        printf("\n\tSTAFF ID : %d\n\tSTAFF NAME : %s",staff_to_edit->staff_id,staff_to_edit->staff_name);

        printf("\n\t_________________________ENTER NEW STAFF DETAILS_________________________");
       

        printf("\n\tSTAFF NAME : ");
        strcpy(staffname,readstring());

        staff *newstaff = NULL;
        newstaff = malloc(sizeof(staff));

        newstaff->staff_id = staff_to_edit->staff_id;
        strcpy(newstaff->staff_name,staffname);

        result = updatestaff(newstaff);

        free(staff_to_edit);

    }

    return result;

}

int removestaff(){

    int result = 0;

    staff *staff_to_delete = searchstaff();

    if(staff_to_delete != NULL){

        printf("\n\t_________________________DELETED STAFF DETAILS_________________________\n");
        // printf("***************************\n");

        printf("\n\tSTAFF ID : %d\nSTAFF NAME : %s\n",staff_to_delete->staff_id,staff_to_delete->staff_name);

        result = deletestaff(staff_to_delete);

        free(staff_to_delete);

    }

    return result;
}