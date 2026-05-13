#include<stdio.h>
#include<conio.h>
void menu();
void register_new_vehicle(int z[100][5],int *count);
void remove_vehicle(int z[100][5],int *count);
void display_all_vehicles(int z[100][5],int *count);
void search_by_vehicle_id(int z[100][5],int *count);
void update_vehicle_entry_time(int z[100][5],int *count);
void welcome_message();
int is_valid_time(int a,int b,int c);
int main()
{
    int x,a,z[100][5],count=0;
    welcome_message();
    printf("\n                            Press any key to start the system.......\n");
    x=getch();
    while(x)
    {
        menu();

    printf("Enter choice:");
    scanf("%d",&a);
    if (a==1)
    {
      register_new_vehicle(z,&count);
    }
    else if(a==2)
    {
       remove_vehicle(z,&count);
    }
    else if(a==3)
    {
      display_all_vehicles(z,&count);
    }
    else if(a==4)
    {
        search_by_vehicle_id(z,&count);
    }
    else if(a==5)
    {
      update_vehicle_entry_time(z,&count);
    }
    else if(a==6)
    {
        printf("===================== Exit Program ====================\n");
    printf("Thank you for using the Vehicle Management System");
        return 0;
    }
    else
        {
            printf("\ninvalid!!");

        }
    }
}
void welcome_message(void)
{
    printf("            ===================================================================================================\n");
    printf("            |                                                                                                 |\n");
    printf("            |                                    VEHICLE MANAGEMENT SYSTEM                                    |\n");
    printf("            |                                                                                                 |\n");
    printf("            ===================================================================================================\n");
    printf("            |   Welcome to vehicle management system                                                          |\n");
    printf("            |                                                                                                 |\n");
    printf("            |   -->Developed by: Depertment of CSE                                                            |\n");
    printf("            |   -->Semester: Spring 2025                                                                      |\n");
    printf("            |                                                                                                 |\n");
    printf("            |  This system allows you to:                                                                     |\n");
    printf("            | - Register new vehicles                                                                         |\n");
    printf("            | - Remove vehicles                                                                               |\n");
    printf("            | - Display all records                                                                           |\n");
    printf("            | - Search & update entry times                                                                   |\n");
    printf("            |                                                                                                 |\n");
    printf("            ===================================================================================================");
}
void menu(void)
{
    printf("\n========================= MENU =======================\n");
    printf("1. Register New Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Display All Vehicle\n");
    printf("4. Search by Vehicle ID\n");
    printf("5. Update Vehicle Entry Time\n");
    printf("6. Exit\n");
}
int is_valid_time(int a,int b,int c)
    {
        if(a<1 || a>12)
        {
            return 1;
        }
        if(b<0 || b>59)
        {
            return 1;
        }
        if(c!=0 && c!=1)
        {
            return 1;
        }
        return 2;
    }
void register_new_vehicle(int z[100][5],int *count)
{
    int h,m,a;
printf("====================Register New Vehicle======================\n");
printf("Enter Vehicle ID:");
scanf("%d",&z[*count][0]);
printf("Enter Type(1-Car,2-Bike,3-Truck):");
scanf("%d",&z[*count][1]);
printf("Entry Hour(1-12):");
scanf("%d",&h);
printf("Entry Minute(0-59):");
scanf("%d",&m);
printf("Enter AM or PM(0 for AM,1 for PM):");
scanf("%d",&a);
if(is_valid_time(h,m,a)==1)
{
printf("Invalid Time Input\n");
return;
}
z[*count][2]=h;
z[*count][3]=m;
z[*count][4]=a;
    (*count)++;
    printf("\nVehicle Registered Successfully!\n");
}
void display_all_vehicles(int z[100][5],int *count)
{
    printf("========================= All Vehicles ======================\n");
    printf("Slot\tID\tType\tTime\n");
    int e;
    for(e=0;e<*count;e++)
        {
            printf("%d\t%d\t",e+1,z[e][0]);
            if(z[e][1]==1)
            {
                printf("Car\t");
            }
            else if(z[e][1]==2)
            {
                printf("Bike\t");
            }
            else
            {
                printf("Truck\t");
            }
          printf("%d:%d ",z[e][2],z[e][3]);
          if(z[e][4]==0)
          {
              printf("AM");
          }
          else
          {
              printf("PM");
          }
          printf("\n");
        }
}
void search_by_vehicle_id(int z[100][5],int *count)
{
    int k,p,found=0;
    printf("========================== Search Vehicle =====================\n");
    printf("\nEnter Vehicle ID:");
    scanf("%d",&p);
    for(k=0;k<*count;k++)
    {
        if(p==z[k][0])
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        printf("Slot:%d\n",k+1);
    printf("ID:%d\n",z[k][0]);
            if(z[k][1]==1)
            {
                printf("Car\n");
            }
            else if(z[k][1]==2)
            {
                printf("Bike\n");
            }
            else
            {
                printf("Truck\n");
            }
    printf("Time:%d:%d",z[k][2],z[k][3]);
    if(z[k][4]==0)
          {
              printf("AM");
          }
          else
          {
              printf("PM");
          }

   }
        else
   {
    printf("The vehicle is not found");
   }
    }
void update_vehicle_entry_time(int z[100][5],int *count)
{
  int k,p,h,m,a,found=0;
  printf("======================== Update Entry Time ========================\n");
  printf("\nEnter Vehicle ID:");
  scanf("%d",&p);
    for(k=0;k<*count;k++)
    {
        if(p==z[k][0])
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        printf("Entery Hour(1-12):");
scanf("%d",&h);
printf("Entery Minute(0-59):");
scanf("%d",&m);
printf("Enter AM or PM(0 for AM,1 for PM):");
scanf("%d",&a);
if(is_valid_time(h,m,a)==1)
{
printf("Invalid Time Input\n");
return;
}
z[k][2]=h;
z[k][3]=m;
z[k][4]=a;
    }

    else
    {
        printf("The vehicle is not found");
    }

}
void remove_vehicle(int z[100][5],int *count)
{
    int k,p,j,l,found=0;
  printf("================ Remove Vehicle ========================\n");
  printf("\nEnter Vehicle ID:");
  scanf("%d",&p);
    for(k=0;k<*count;k++)
    {
        if(p==z[k][0])
        {
            found=1;
            break;
        }
    }
   if(found==1)
   {
        for(j=k;j<*count-1;j++)
    {
        for(l=0;l<5;l++)
        {
            z[j][l]=z[j+1][l];
        }
    }
    (*count)--;
    printf("Vehicle removed successfully");
   }
   else
   {
       printf("The vehicle is not found");
   }
}

