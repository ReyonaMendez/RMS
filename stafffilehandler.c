


int gettotalstaffcount();
int getlaststaffid();



int writestaff(staff *staffobj)
{
    FILE *fp=NULL;
    fp=fopen(restaurantstaff,"ab+");
    if(fp==NULL)
    {
           return 0;
    }
    else
    {
      fwrite(staffobj,sizeof(staff),1,fp);
      fclose(fp);
      return 1;
    }
}


int getlaststaffid()
{
    int laststaffid=0;
    FILE *fp=NULL;
    fp=fopen(restaurantstaff,"rb");
    staff *staff_to_find=NULL;
    if(fp!=NULL)
    {
        staff_to_find=(staff*)malloc(sizeof(staff));
        while(fread(staff_to_find,sizeof(staff),1,fp))
        {
            laststaffid=staff_to_find->staff_id;
        }
        fclose(fp);
    }
    return laststaffid;
}




staff *getallstaffs(){

    FILE *fp = NULL;
    fp = fopen(restaurantstaff,"rb");
    staff *staff_to_find = NULL;

    int totalstaffcount = gettotalstaffcount();

    staff *staffs = (staff*)malloc(sizeof(staff) * totalstaffcount);

    if(fp != NULL){

        staff_to_find = (staff*)malloc(sizeof(staff));

        for(int i=0;i<totalstaffcount;i++){

            fread(staff_to_find,sizeof(staff),1,fp);

            staffs[i].staff_id = staff_to_find->staff_id;

            strcpy(staffs[i].staff_name,staff_to_find->staff_name);
        


        }
        fclose(fp);
    }
    
    return staffs; 

}





int gettotalstaffcount(){

    int count = 0;
    FILE *fp = NULL;
    fp = fopen(restaurantstaff,"rb");
    staff *staff_to_find = NULL;

    if(fp != NULL){

        staff_to_find = (staff*) malloc(sizeof(staff));

        while(fread(staff_to_find,sizeof(staff),1,fp)){

            count++;


        }
    fclose(fp);

    }

    return count;


}




staff *getstaff(int id)
{

    FILE *fp = NULL;
    fp = fopen(restaurantstaff,"rb");
    staff *staff_to_find = NULL;

    if(fp == NULL)
    {

        return staff_to_find;
    }
    else{

        staff_to_find = (staff*)malloc(sizeof(staff));

        while(fread(staff_to_find,sizeof(staff),1,fp))
        {
            if(staff_to_find->staff_id == id){

                fclose(fp);
                return staff_to_find;
            }
        }
        fclose(fp);
        return staff_to_find;
    }
}




int updatestaff(staff *updatestaffobj){

    FILE *fp = NULL;
    FILE *fu = NULL;

    fp = fopen(restaurantstaff,"rb");
    fu = fopen(temp,"wb");

    if(fp == NULL || fu == NULL){

        return 0;

    }
    else{

        rewind(fp);

        staff *no_change_staff = (staff*)malloc(sizeof(staff));

        while(fread(no_change_staff,sizeof(staff),1,fp) == 1)
        {
            if(updatestaffobj->staff_id != no_change_staff->staff_id){

                fwrite(no_change_staff,sizeof(staff),1,fu);
            }
            else{

                fwrite(updatestaffobj,sizeof(staff),1,fu);

            }
        }

        fclose(fp);
        fclose(fu);

        free(no_change_staff);


        remove(restaurantstaff);
        rename(temp,restaurantstaff);

        return 1;

    }
    


}


int deletestaff(staff *discardstaffobj){

    FILE *fp = NULL;
    FILE *fu = NULL;

    fp = fopen(restaurantstaff,"rb");
    fu = fopen(temp,"wb");

    if(fp == NULL || fu == NULL){

        return 0;

    }
    else{

        rewind(fp);

        staff *keep_staff = (staff*)malloc(sizeof(staff));

        while(fread(keep_staff,sizeof(staff),1,fp) == 1)
        {
            if(discardstaffobj->staff_id != keep_staff->staff_id){

                fwrite(keep_staff,sizeof(staff),1,fu);
            }
        }

        fclose(fp);
        fclose(fu);

        free(keep_staff);

        remove(restaurantstaff);
        rename(temp,restaurantstaff);


    }    


}