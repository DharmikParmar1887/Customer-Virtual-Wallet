#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include<stdlib.h>

  struct account {
	char name[100];
	int acct_no;
	long long int mobile_no;
	char city[100];
	float balance;
  }customer[1000];
int cust_count = 5,act_no = 0, id = 10006;
int i = 0;
int a;

void dummy_account(){
    FILE *fp , *fo;
    fp = fopen("input1.txt", "r");
    fo = fopen("output1.txt", "w");
    for(int i = 0; i < 5; i++){
              
                //   printf("\n\t Customer ID is:- ");
                  fscanf(fp, "%d", &customer[i].acct_no);
                  fprintf(fo, "%d ", customer[i].acct_no);
                //   printf("\t Customer name:- ");
                  fscanf(fp , "%s", customer[i].name);
                  fprintf(fo, "%s ", customer[i].name);
                 // printf("\t Customer mobile number:- ");
                  fscanf(fp, "%lld", &customer[i].mobile_no);
                  fprintf(fo, "%lld ", customer[i].mobile_no);
                  //printf("\t Customer city name:- ");
                  fscanf(fp, "%s", customer[i].city);
                  fprintf(fo, "%s \n", customer[i].city);
                  //printf("\t Account balance:- ");
                  fscanf(fp, "%f", &customer[i].balance);
                 // fprintf(fo, "HI\n");
              
    }
    fclose(fp);
    fclose(fo);
    return;
}

int createAccount(int ind)
    {
        FILE *fp = NULL;
        fp = fopen("myaccount.txt" , "a");
          customer[ind].acct_no = id++;
          printf("\nEnter the name of the customer:- ");
          scanf("%s", customer[ind].name);
          printf("Enter the Mobile Number:-\t");
          scanf("%lld", &customer[ind].mobile_no);
          printf("Enter the city:- ");
          scanf("%s", customer[ind].city);
          printf("How much balance you want to maintain:- ");
          scanf("%f", &customer[ind].balance);
          
          fprintf(fp,"%d %s %lld %s\n\n",customer[ind].acct_no,customer[ind].name, customer[ind].mobile_no, customer[ind].city);
          fclose(fp);
          return customer[ind].acct_no;
      }
      void searchACustomer(int act_no)
      {
          bool flag = 0;
          for(int i = 0; i < cust_count; i++){
              if(customer[i].acct_no == act_no){
                  flag = 1;
                  printf("\n\t Customer ID is:- %d\n", customer[i].acct_no);
                  printf("\t Customer name:- %s\n", customer[i].name);
                  printf("\t Customer mobile number:- %lld\n", customer[i].mobile_no);
                  printf("\t Customer city name:- %s\n", customer[i].city);
                  printf("\t Account balance:- %.2f\n\n", customer[i].balance);
              }
          }
          if(flag == 0)
          {
              printf("Enter the correct account number.\n\n");
          }
          return;
      }
      void payBill(int act_no)
      {
          float amount = 0;
          bool flag = 0;
          for(int i = 0; i < cust_count; i++){
              if (customer[i].acct_no == act_no){
                  flag = 1;
                  printf("Enter the bill amount to Pay:- ");
                  scanf("%f", &amount);
                  if (customer[i].balance >= amount) {
                      customer[i].balance -= amount;
                      printf("Bill paid successfully.\nUpdated Balance is:- %.2f\n\n", customer[i].balance);
                  } else {
                      printf("Insufficient Balance! Please try again after topping up the balance.\n\n");
                  }
              }
          }
          if(flag == 0)
          {
              printf("Enter the correct account number.\n\n");
          }
          return;
      }
      void addBalance(int act_no)
      {
          float amount = 0;
          bool flag = 0;
          for(int i =0; i < cust_count; i++){
              if (customer[i].acct_no == act_no){
                  flag = 1;
                  printf("Enter the amount to add in your Wallet:- ");
                  scanf("%f", &amount);
                  customer[i].balance += amount;
                  printf("Balance updated successfully. The updated account balance is:- %.2f\n\n", customer[i].balance);
              }
          }
          return;
      }
      void printAllCustomers() {
          for (int i = 0; i < cust_count ; i++ )
          {
              printf("\nCUSTOMER-- %d\n", (i+1));
              printf("\t Customer ID:- %d\n", customer[i].acct_no);
              printf("\t customer name:- %s\n", customer[i].name);
              printf("\t customer mobile number:- %lld\n", customer[i].mobile_no);
              printf("\t Customer city name:- %s\n", customer[i].city);
              printf("\t Customer Balance:- %.2f\n\n", customer[i].balance);
          }
          return;
      }

void main()
{
    dummy_account();    
    while(1){

        printf("<-------------------- Customer Virtual Wallet ----------------------->\n");
        printf("1: Add New Customer Wallet.\n");
	    printf("2: Search Existing Customer Account.\n");
        printf("3: Pay the Bills.\n");
        printf("4: Print All Customers Details.\n");
        printf("5: Top-Up Balance.\n");
        printf("6: Exit\n<----------------- This are the services we provide -------------------->\n");
        printf("\nSelect the service you want ?:- ");
        
        scanf("%d",&a); 

        switch (a){
            case 1:
                cust_count += 1;
                 printf("Serial number:- %d", cust_count);
                int id = createAccount(cust_count - 1);
                printf("Your Account Number is:- %d\n\n", id);
                break;
            case 2:
                printf("Enter the Account Number:- ");
                scanf("%d", &act_no);
                searchACustomer(act_no);
                break;
            case 3:
                printf("Enter the Account Number:- ");
                scanf("%d", &act_no);
                payBill(act_no);
                break;
            case 4:
                printAllCustomers();
                break;
            case 5:
                printf("Enter Your Account Number:- ");
                scanf("%d", &act_no);
                addBalance(act_no);
                break;
            case 6:
                printf("<------------ Hope that we haven't disappointed you :) ----------->\n <------------ Thank you for choosing us! ----------->");
                exit(0);
                break;
            default : 
            printf("Enter a correct number.\n");
        }
    }
      return;
 }
   