typedef struct node
{
    int item_id;
    char foodname[50];
    //int quantity;
    float price;
    //int data;
    //struct node *prev;
    //struct node *next;
}food;



typedef struct orderzz
{
    int token;
    int item_id;
    char food_name[50];
    float price_;
    int qty_;

}orders;



typedef struct resstaff
{
    int staff_id;
    char staff_name[50];
}staff;



typedef struct record{
    int recId;
    int amount;
    // char date[15];
    int month,date,year;
}records;


typedef struct reserve
{
    int table_id;
    int tableno;
    int capacity;
    char c_name[50];
    char contact[11];
}table;