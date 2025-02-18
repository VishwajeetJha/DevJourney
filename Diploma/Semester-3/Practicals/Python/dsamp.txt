/*                  ***DOCUMENTATION***
Data Structures and Algorithms Microproject
Work started on 10/11/2023 9:22 PM IST

Topic: Develop a C Program that perform banking operations like withdraw cash,
deposit cash and mini statement using appropriate data structure. 


Schematic:-
account related functions - create, delete, modify account,  etc
account functions - withdraw, credit money and mini-statement
main function:-
    switch case to (acc. related functions)

10/11/2023:-
Work Stated, currently working on making things work, implemented duplicacy 
                        prevention from very core, later it would've been hard.


NOTES:-
10/11/23 11:10:-
1. Work on the address being printed before proceeding further into the code
    eg. randomnumbersaddress -> valid_input -> valid_input -> NULL
    to
        valid_input -> valid_input -> NULL

11/11/2023 11:12:-
1. Remember modification in memory requires two pointers? **
    implement it and try again!
2.remAcc(){..
    //find accNo and delete that node, will require two pointers or just one using (node->next)->next
    //11:03-Used two pointers
    ..}

12/11/2023 10:11:-
1. Fixed issues, to make a new account use "first=createAcc(first);" callout.
2. create withdraw, deposit and mini statement functions and do here and there tampering with basic 
    bank account functions like create delete modify..
    The Related functions should require admin password, that would be 12345 xD
    The Inside Functions should be withdraw, dep, and the mini statement. Well brb.
3. use "remAcc(&first, AccountNumber);" callout to remove an account with Account Number "AccountNumber"

13/11/2023 13:12:-
1. if(remAcc(&first, 3)){
        printf("Success\n");
    }
    else{
        printf("Failed\n");
    }

    --this can be used to check whether the function worked.
    but I didn't use it, its useless.

2. Creating return codes and states
3. 9:42:-
    . Implemented file system here and there
    . Balance will have capacity related to Account Type: Minor, Standard and Enterprise.
    . 

16/11/2023 09:24PM:-
1. Lost track, did file implementation here and there again..
2. idk
x3. currently log out and log in ain't working.
x4. if there are no accounts, user is automatically gaining admin access..! URGENT FIX REQUIRED
x    Priority 10:43PM --> Modify, Load+Save accounts

18/11/2023 4:59PM:-
1. Modify accounts completed..!
2. Save+Load accounts completed..!
3. Actually both the above were done yesterday itself.
x4. modAcc (like Removed Account: ... )--> INCLUDE TRANSACTIONS LOG --> DONE
x5. Add time stamp to all logs and transactions. Accounts dont require one. --> DONE
x6. PRIORITY: GOING BACK TO ACCOUNT SELECTION  --> DONE
x7. Transactions logs timeSTAMP --> DONE

Lost track between 18 and 21

*********************************
1. Create/Add
2. Remove
3. Modify
4. Withdraw
5. Deposit

*********************************

COs Covered:-
a. Perform basic operations on arrays and strings. (c)
b. Demonstrate algorithms to insert and delete elements from the stack and queue data structure. (p)
c. Apply basic operations on the linked list data structure. (c) 
d. Apply different sorting and searching algorithms to the small data sets. (c)

    Legends:-
    c - Complete
    p - Partially
    td - To Do

Tried:-
1. Quick Sort:
Useless! Asked ChatGPT turns out I'll need to swap all values from one node to another for each and every
node exchange!! TimeComplexity+++

2. MergeSort: Trying Merge Sort
06/12/23 14:22: MergeSort is easier since I think it is solely based on doing stuff with lists/arrays/etc
    14:32: But still requires a helper function which makes things complex... So, let's do that first.
    14:51: Helper Function Done. Now, Let's implement MergeSort 
    15:20: Implemented MergeSort. It works perfectly fine but takes more time than what we want. 
        We can optimize this by using two pointers method.
Didn't even look at Bubble/Selection/Insertion/Radix etc. Why? Because I can.

ISSUES:-
None for now :3

PROJECT COMPLETION: 08/12/2023
*/

//Too many header files (crying emoji)
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_LINE_SIZE 512  //max length for buffer, reading from file

int const PWD=12345; //password for administrative privileges like create, remove or modify account
int adminPrivileges=0; //whether user is admin, by default 0
char StackOfFunctionCalls[150][MAX_LINE_SIZE];        //max size for string and max index for stack
int IndexForStack=0;

//File Management
FILE *transactions, *logs, *accounts;

// Global Timestamp variables
time_t rawtime;
struct tm *timeinfo;

//Bank Account Linked List
typedef struct BankAcc {
    char *AccHolder;
    short AccType;
    int AccNumber;
    float Balance;
    struct BankAcc *next;
} BankAcc;

//Prototypes
BankAcc *AccNode(BankAcc *node, int AcNo);
void mmHeader();
void STATES(short a);
void AccTYPES(short a);

//Pushing Function calls to stack
void PushCall(char const log[150]){
    if(IndexForStack >= MAX_LINE_SIZE-1){
        printf("Stack Overflow: Cannot push more function calls!\n");
        getch();
    }
    else{
        strcpy(StackOfFunctionCalls[IndexForStack], log);
        logs = fopen("mp/logs/functioncalls.txt", "a");
        if(logs==NULL){
            printf("ERROR: Can't open file: mp/logs/functioncalls.txt\n");
            getch();
        }
        else{
        fprintf(logs, "%s\n", StackOfFunctionCalls[IndexForStack]);
        }
        fclose(logs);
        IndexForStack++;
    }
}

/* Sorting Accounts in Order */
BankAcc* merge(BankAcc* left, BankAcc* right) {
    BankAcc dummy;
    BankAcc* tail = &dummy;

    while (left != NULL && right != NULL) {
        if (left->AccNumber <= right->AccNumber) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = (left != NULL) ? left : right;

    return dummy.next;
}

void split(BankAcc* source, BankAcc** front, BankAcc** back) {
    BankAcc* fast;
    BankAcc* slow;

    if (source == NULL || source->next == NULL) {
        *front = source;
        *back = NULL;
    } else {
        slow = source;
        fast = source->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }
}

int mergeSort(BankAcc** head) {
    BankAcc* current = *head;
    BankAcc* left;
    BankAcc* right;

    if (current == NULL || current->next == NULL) {
        return 0;
    }

    split(current, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *head = merge(left, right);

    return 12;
}

//Modifying Account
void modAcc(BankAcc *fr){ 
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Modify Account Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if (fr == NULL) {
        STATES(0);
        getch();
        return ;
    }
    BankAcc *acc,*tmp;

    int acno,newType,oldType,ch,i;
    int AccountFound=0; //Keeping track whether account has been found or not
    char oldName[150],newName[150];
    char inputBuffer[20];  // Assuming a reasonable maximum length for the input

accsel:
    tmp=fr;
    mmHeader();
    printf("Account Number\t%-30s\tType\tBalance\n","Holder");
    while(tmp!=NULL){
        printf("%d\t\t%-30s\t%d\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->AccType,tmp->Balance);
        tmp=tmp->next;
    }
    
    while (getchar() != '\n');  // Flush the input buffer

    printf("Enter Account number to modify: ");
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
        printf("Error reading input. Press any key to continue..\n");
        getch();
        system("cls");
    }

    // Convert the input to an integer
    if (sscanf(inputBuffer, "%d", &acno) != 1) {
        printf("WARNING: Please enter a valid account number!\nPress any key to continue..\n");
        getch();
        system("cls");
        goto accsel;
    }

    acc=AccNode(fr,acno);
    if(acc==NULL){
        printf("ERROR: Account not found or doesn't exists!\n");
        getch();
        return ;
    }

    i=0;
    while(acc->AccHolder[i] != '\0'){
        oldName[i]=acc->AccHolder[i];
        i++;
    }
    oldName[i] = '\0';
    //strcpy(oldName,acc->AccHolder); //Keeping track of old name before editing the new one.
    oldType=acc->AccType; //also the acc type 

strt:
    mmHeader();
    printf("Selected Account:-\n");
        printf("Account Number: %d\n", acc->AccNumber);
        printf("Account Holder: %s\n", acc->AccHolder);
        printf("Account Type: %d\n", acc->AccType);
    printf("Select the information to modify:\n");
    printf("1. Account Holder Name\n");
    printf("2. Account Type\n");
    printf("3. Re-Select Account\n");
    printf("4. Back\n");
    printf("   --->");
    scanf("%d", &ch);
    while(getchar() != '\n');       //Flushing newline buffer

    switch (ch) {
        case 1:
            printf("Enter new Account Holder Name: ");
            gets(newName);

            //Process the new name and copy, using string operations
            i=0;
            while(newName[i] != '\0'){
                //first letter Upper case
                if(i==0){
                    if(newName[i] >= 'a' && newName[i] <= 'z'){
                        acc->AccHolder[i] = newName[i] - 32;
                    }
                    else{
                        acc->AccHolder[i] = newName[i];
                    }
                }
                //any first thing after a space will be Upper case
                else if(newName[i] == ' '){
                    acc->AccHolder[i] = ' '; 
                    i++;
                    if(newName[i] >= 'a' && newName[i] <= 'z'){
                        acc->AccHolder[i] = newName[i] - 32;
                    }
                    else{
                        acc->AccHolder[i] = newName[i];
                    }
                }
                //normal copy with Lower casing anything after-between first letter and space 
                else{
                    if(newName[i] >= 'A' && newName[i] <= 'Z'){
                        acc->AccHolder[i] = newName[i] + 32;
                    }
                    else{
                        acc->AccHolder[i]=newName[i];
                    }
                }
                i++;
            }
            acc->AccHolder[i] = '\0';
            printf("Success: Holder name changed.\n");
            getch();
            //strcpy(acc->AccHolder,newName); //use string operations algo instead of this
            break;

        case 2:
        typ:
            printf("\n********************************\n");
            printf("Available Account Types:-\n");
            printf("0. Minor\n");
            printf("1. Standard\n");
            printf("2. Enterprise\n");
            printf("Select Account Type:\n    --->");
            while(1){
                if(scanf("%d", &newType)){
                    break;
                }
                else{
                    printf("Invalid input, please go again..\n");
                    goto typ;
                }
            }
            if(newType<0 || newType>2){       
                printf("\nInvalid Input!! Please enter correct value:\n");
                goto typ;
            }
            else{
                acc->AccType=newType;
            }
            printf("Success: Account type changed.\n");
            getch();
            break;

        case 3:
            goto accsel;
            break;

        case 4:
            return ;
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            getch();
            goto strt;
    }
    
    if(ch == 1 && acc != NULL){           //Holder change
        logs=fopen("mp/logs/accountslog.txt","a");
        if(logs==NULL){
            printf("ERROR: Failed to open file: accountslog.txt");
            getch();
        }
        else{
            fprintf(logs,"[%04d-%02d-%02d %02d:%02d]Modified Account %d (Name): %s  -TO-  %s\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
           timeinfo->tm_hour, timeinfo->tm_min, acno, oldName, acc->AccHolder);
        }
        fclose(logs);
    }
    else if(ch == 2 && acc != NULL){      //Type change
        logs=fopen("mp/logs/accountslog.txt","a");
        if(logs==NULL){
            printf("ERROR: Failed to open file: accountslog.txt");
        }
        else{
            fprintf(logs,"[%04d-%02d-%02d %02d:%02d]Modified Account %d (Type): %d  -TO-  %d\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
           timeinfo->tm_hour, timeinfo->tm_min, acno, oldType, newType);
        }
        fclose(logs);
    }
    else{
        STATES(7);  //ISSUE IN FINDING THE ACCOUNT AND REMAKING THE DATABASE
        getch();
    }
}

//Adding Account to the database
int addAcc(BankAcc *na, BankAcc **fr) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Add Account Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if (*fr == NULL) {
        *fr = na;
        logs=fopen("mp/logs/accountslog.txt","a");
        if(logs==NULL){
            printf("ERROR: Failed to open file: accountslog.txt");
            getch();
        }
        else{
            fprintf(logs,"[%04d-%02d-%02d %02d:%02d]Created Account: %d\t-\t%s\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, na->AccNumber,na->AccHolder);
        }
        fclose(logs);
        return 3;
    } 
    else{
        // Traverse the list to find the last node
        BankAcc *last = *fr;
        while (last->next != NULL) {
            last = last->next;
        }
        // Connect the last node to the new node
        last->next = na;

        // FILE OPERATIONS
        logs=fopen("mp/logs/accountslog.txt","a");
        if(logs==NULL){
            printf("ERROR: Failed to open file: accountslog.txt");
        }
        else{
            fprintf(logs,"[%04d-%02d-%02d %02d:%02d]Created Account: %d\t-\t%s\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, na->AccNumber,na->AccHolder);
        }
        fclose(logs);
        return 4;
    }
}

//Remove Account from database
int remAcc(BankAcc **fr) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr, "[%04d-%02d-%02d %02d:%02d]Remove Account Function Called.", timeinfo->tm_year + 1900,
            timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min);

    PushCall(tempStr);

    BankAcc* pre = *fr;
    BankAcc* suc = pre;

    int tmpacno, AccNo, i = 0;
    char tmpname[128];

    // Check if there are any accounts in the system
    if (*fr == NULL) {
        return 0;
    } else {
        printf("Enter account number to remove: ");
        scanf("%d", &AccNo);
        // If there's only one node and it matches the given account number OR first node
        if (pre->AccNumber == AccNo) {
            if(pre->Balance != 0){
                mmHeader();
                printf("ERROR: Account balance currently active.\n");
                printf("1. Set Balance to NULL and Continue\n");
                printf("2. Back\n");
                int ch;
                printf("  --->");
                scanf("%d", &ch);
                switch(ch){
                    case 1:
                        mmHeader();
                        pre->Balance=0;
                        printf("Success: Balance set to NULL\n");
                        getch();
                        break;

                    case 2:
                        return 99;
                    
                    default:
                        printf("Invalid choice. Please go again..\n");
                }
            }
            tmpacno = pre->AccNumber;
            i = 0;
            while (pre->AccHolder[i] != '\0') {
                tmpname[i] = pre->AccHolder[i];
                i++;
            }
            tmpname[i] = '\0';

            // Update the first pointer
            *fr = pre->next;    //incase of first, the node moves to next.
                                //incase of only one, fr ptr becomes NULL

            // FILE OPERATIONS
            logs = fopen("mp/logs/accountslog.txt", "a");
            if (logs == NULL) {
                printf("ERROR: Failed to open file: accountslog.txt");
                getch();
            } else {
                fprintf(logs, "[%04d-%02d-%02d %02d:%02d]Removed Account: %d\t-\t%s\n", timeinfo->tm_year + 1900,
                        timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, tmpacno, tmpname);
            }
            fclose(logs);

            // Renaming transactions log filename
            char acc_transactions_log[50];
            sprintf(acc_transactions_log, "mp/transactions/%d_transactions", tmpacno);
            char deleted_acc_transactions_log[50];
            sprintf(deleted_acc_transactions_log, "mp/transactions/DELETED_%s", acc_transactions_log);
            rename(acc_transactions_log, deleted_acc_transactions_log);

            // Free allocated memory
            free(pre->AccHolder);
            free(pre);

            return 1;
        } else {
            // If the account to remove is in the middle of the list
            while (suc != NULL && pre->next != NULL) {
                suc = suc->next;
                if (AccNo == suc->AccNumber) {
                    if(suc->Balance != 0){
                    mmHeader();
                    printf("ERROR: Account balance currently active.\n");
                    printf("1. Set Balance to NULL and Continue\n");
                    printf("2. Back\n");
                    int ch;
                    printf("  --->");
                    scanf("%d", &ch);
                    switch(ch){
                        case 1:
                            mmHeader();
                            suc->Balance=0;
                            printf("Success: Balance set to NULL\n");
                            getch();
                            break;

                        case 2:
                            return 99; 
                    
                        default:
                            printf("Invalid choice.. please go again\n");
                        }
                    }
                    pre->next = suc->next;
                    tmpacno = suc->AccNumber;
                    i = 0;
                    while (suc->AccHolder[i] != '\0') {
                        tmpname[i] = suc->AccHolder[i];
                        i++;
                    }
                    tmpname[i] = '\0';

                    // FILE OPERATIONS
                    logs = fopen("mp/logs/accountslog.txt", "a");
                    if (logs == NULL) {
                        printf("ERROR: Failed to open file: accountslog.txt");
                        getch();
                    } else {
                        fprintf(logs, "[%04d-%02d-%02d %02d:%02d]Removed Account: %d\t-\t%s\n",
                                timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
                                timeinfo->tm_hour, timeinfo->tm_min, tmpacno, tmpname);
                    }
                    fclose(logs);

                    // Renaming transactions log filename
                    char acc_transactions_log[50];
                    sprintf(acc_transactions_log, "mp/transactions/%d_transactions", tmpacno);
                    char deleted_acc_transactions_log[50];
                    sprintf(deleted_acc_transactions_log, "mp/transactions/DELETED_%s", acc_transactions_log);
                    rename(acc_transactions_log, deleted_acc_transactions_log);

                    // Free allocated memory
                    free(suc->AccHolder);
                    free(suc);

                    return 1;
                }
                pre = pre->next;
            }
        }
    }
    return 7;
}

//Creating Account
BankAcc *createAcc(BankAcc *a) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStri[150];
    sprintf(tempStri,"[%04d-%02d-%02d %02d:%02d]Create Account Node Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStri);

    BankAcc *new = (BankAcc *)malloc(sizeof(BankAcc));
    BankAcc *tmp = a;
    new->next = NULL;
    new->AccHolder = (char *)malloc(150 * sizeof(char)); // Adjust the size as needed

    int state,i,accno;
    char tempstr[100];

initial:
    printf("Enter Account Number: ");
    while(1){
        if(scanf("%d", &accno)){
            break;
        }
        else{
            printf("Please make a valid input!\n");
            getch();
            goto initial; 
        }
    }
    while (getchar() != '\n');      //flushing newline(\n) buffer
    a = tmp;
    while (a != NULL) {
        if (accno == a->AccNumber) {
            printf("\n\nERROR: Account already exists as per the account number provided!\n");
            printf("Please try again..:-\n\n");
            goto initial;
        }
        a = a->next; // Move to the next node
    }
rename:
    printf("Enter Account Holder Name: ");
    gets(tempstr);

    //Process the new name and copy, using string operations
    i=0;
    while(tempstr[i] != '\0'){
        //first letter Upper case
        if(i==0){
            if(!isalpha(tempstr[i])){
                printf("Invalid Input! Please enter a valid name.\n");
                goto rename;
            }
            else{
                if(tempstr[i] >= 'a' && tempstr[i] <= 'z'){
                    new->AccHolder[i] = tempstr[i] - 32;
                }
                else{
                    new->AccHolder[i] = tempstr[i];
                }
            }
        }
        //any first thing after a space will be Upper case
        else if(tempstr[i] == ' '){
            new->AccHolder[i] = ' '; 
            i++;
            if(tempstr[i] >= 'a' && tempstr[i] <= 'z'){
                new->AccHolder[i] = tempstr[i] - 32;
            }
            else{
                new->AccHolder[i] = tempstr[i];
            }
        }
        //Ignoring and removing any and all digits if input by mistake in name
        else if(!isalpha(tempstr[i])){
            printf("Digit encountered in name! Ignored..\n");
        }
        //normal copy with Lower casing anything after-between first letter and space 
        else{
            if(tempstr[i] >= 'A' && tempstr[i] <= 'Z'){
                new->AccHolder[i] = tempstr[i] + 32;
            }
            else{
                new->AccHolder[i]=tempstr[i];
            }
        }
        i++;
    }
    new->AccHolder[i] = '\0';

    int ty;
typ:
    printf("\n********************************\n");
    printf("Available Account Types:-\n");
    printf("0. Minor\n");
    printf("1. Standard\n");
    printf("2. Enterprise\n");
    printf("Select Account Type:\n    --->");
    while(1){
        if(scanf("%d", &ty)){
            break;
        }
        else{
            printf("Invalid input, please go again..\n");
            goto typ;
        }
    }
    while (getchar() != '\n');      //flushing newline(\n) buffer
    if(ty<0 || ty>2){
        printf("Invalid Input!! Please enter correct value:-\n");
        goto typ;
    }
    else{
        new->AccType=ty;
    }

    new->Balance=0;
    new->AccNumber = accno;
    state=addAcc(new, &tmp);

    STATES(state);
    getch();
    return tmp; // Return the modified linked list
}

BankAcc *AccNode(BankAcc *node, int AcNo) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Find Account Node Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if(node==NULL){
        STATES(0);
        getch();
        return NULL;
    }
    else{
        while (node != NULL) {
            if(node->AccNumber==AcNo){
                return node;
            }
            node = node->next;
        }
        return NULL;
    }
}

//Withdraw Money
void withCash(BankAcc *a,float amt){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Withdraw Cash Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if(a==NULL){
        STATES(7);
        return ;
    }

    //current balance - amount to withdraw
    float bal = a->Balance-amt;
    if(bal<=0){
        printf("ERROR: Insufficient Balance!\n");
    }
    else if(a->AccType==2 && bal<10000){
        printf("ERROR: Account type: Enterprise. Lower limit reached!\n");
        return ;
    }
    else{
        a->Balance=bal;
        printf("Success: Amount Withdraw\n");
        
        //Saving the Transaction to txt file for statement
        char filePath[50]; // Assuming a reasonable maximum length for the file path lol
        sprintf(filePath, "mp/transactions/%d_transactions.txt", a->AccNumber);
        transactions = fopen(filePath, "a");
        if(transactions==NULL){
            printf("ERROR: Failed to save transaction.\n");
            getch();
        }
        else{
            fprintf(transactions, "[%04d-%02d-%02d %02d:%02d]Withdrawl,%.2f\n", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, amt);
        }
        fclose(transactions);
    }
}

//Deposit Cash
void depCash(BankAcc *a,float amt){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Find Account Node Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if(a==NULL){
        STATES(7);
        return ;
    }

    //current balance + amount to deposit
    float bal = a->Balance + amt;
    if(a->AccType==0 && bal>50000){
        printf("ERROR: Account type: Minor. Balance Capacity reached!\n");
        return ;
    }
    else if(a->AccType==1 && bal>500000){
        printf("ERROR: Account type: Standard. Balance Capacity reached!\n");
        return ;
    }
    else if(a->AccType==3 && bal>500000){
        printf("ERROR: Account type: Enterprise. Balance Capacity reached!\n");
        return ;
    }
    else{
        a->Balance=bal;
        printf("Success: Cash deposited.\n");

        //Saving the Transaction to txt file for statement
        char filePath[50];
        sprintf(filePath, "mp/transactions/%d_transactions.txt", a->AccNumber);
        transactions = fopen(filePath, "a");
        if(transactions==NULL){
            printf("ERROR: Failed to save transaction.\n");
            
        }
        else{
            fprintf(transactions, "[%04d-%02d-%02d %02d:%02d]Deposit,%.2f\n",timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, amt);
        }
        fclose(transactions);
    }
}

//Empty File checking function
int isFileEmpty(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        // Handle the case where the file couldn't be opened
        printf("ERROR: Couldn't open file\n");
        return -1;  // You can choose an appropriate error code
    }

    fseek(file, 0, SEEK_END);  // Move the file pointer to the end of the file

    /* ftell--> used to find current position of a file pointer */
    if (ftell(file) == 0) {        //if end of the file == 0 i.e. EOF=START OF THE FILE lol
        // File is empty
        fclose(file);
        return 1;
    } else {
        // File is not empty
        fclose(file);
        return 0;
    }
}

//Print Mini Statement
void MiniStmnt(BankAcc *a) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Mini Statement Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if(a==NULL){
        STATES(7);
        return ;
    }

    int amt,tyear,tmonth,tday,thr,tmin;
    char action[30];
    char filePath[50];
    char buffer[MAX_LINE_SIZE];

    sprintf(filePath, "mp/transactions/%d_transactions.txt", a->AccNumber);
    if(isFileEmpty(filePath)){
        printf("ERROR: No Transaction History Found!\n");
        return ;
    }
    transactions = fopen(filePath, "r");
    if (transactions == NULL) {
        printf("ERROR: Failed to open file: %d_transactions.txt\n", a->AccNumber);
        return;
    }
    else{
        int i=0;
        printf("Account %d Transactions:\n", a->AccNumber);
        // Use fgets to read lines into buffer and sscanf to parse them
        while (fgets(buffer, sizeof(buffer), transactions) != NULL) {
            i++;
            //Reading
            sscanf(buffer, "[%04d-%02d-%02d %02d:%02d]%29[^,],%d",&tyear, &tmonth, &tday, &thr, &tmin, action, &amt);
            
            //Writing
            printf("[%02d-%02d-%04d %02d:%02d]%s - %d\n", tday, tmonth, tyear, thr, tmin, action, amt);
        }
        printf("%d Records\n", i);
    }
    fclose(transactions);
}

void printLog(){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Print Logs Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    char filePath[50];

    sprintf(filePath, "mp/logs/accountslog.txt");
    logs = fopen(filePath, "r");
    if (logs == NULL) {
        printf("ERROR: Failed to open file: mp/accounts/accountslogs.txt\n");
        getch();
        return;
    }
    else if(isFileEmpty(filePath)){
        printf("WARNING: Admin Logs empty!\n");
        getch();
    }
    else{
        int tmpacno,tyear,tmonth,tday,thr,tmin;
        char action[50],tmpname[150];
        char buffer[MAX_LINE_SIZE];
        printf("Admin Logs:-\n");
        // Use fgets to read lines into buffer and sscanf to parse them
        while (fgets(buffer, sizeof(buffer), logs) != NULL) {
            //Reading
            sscanf(buffer, "[%04d-%02d-%02d %02d:%02d]%49[^,]: %d\t-\t%149[^,]",&tyear, &tmonth, &tday, &thr, &tmin, action, &tmpacno, tmpname);
            
            //Writing
            printf("[%02d-%02d-%04d %02d:%02d]%s: %d\t-\t%s\n", tday, tmonth, tyear, thr, tmin, action, tmpacno, tmpname);
        }
        printf("--Logs End--\n");
        getch();
    }
    fclose(logs);
}

void clearLog(){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Clear Logs Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    char filePath[50];
    sprintf(filePath, "mp/logs/accountslog.txt");
    if(isFileEmpty(filePath)){
        printf("WARNING: Admin Logs already empty!\n");
        getch();
        return ;
    }
    logs = fopen(filePath, "w");
    if (logs == NULL) {
        printf("ERROR: Failed to open file: mp/accounts/accountslogs.txt\n");
        getch();
        return;
    }
    else{
        printf("Success: Admin Logs cleared.");
        getch();
    }
    fclose(logs);
}

void mmHeader(){
    system("cls");
    printf("****************************\n");
    printf("    Bank Accounts System      \n");
    printf("****************************\n");
}

//Truncate accounts database
void delAccDB(){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]DATABASE TRUNCATED -->delAccDB Function Called", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    char filePath[50];
    sprintf(filePath, "mp/accounts/accounts.csv");
    if(isFileEmpty(filePath)){
        printf("WARNING: Accounts Database already empty!\n");
        return;
    }
    accounts = fopen(filePath, "w");
    if (accounts == NULL) {
        printf("ERROR: Failed to open file: mp/accounts/accounts.csv\n");
        return;
    }
    else if(isFileEmpty(filePath)){
        printf("Success: Database truncated.\n");
    }
    else{
        printf("WARNING: Unknown error occured.\n");
    }
    fclose(accounts);
}

//Truncate accounts of/in session/memory
void delAccSession(BankAcc **first){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]DATA IN MEMORY TRUNCATED --> delAccSession Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if(*first==NULL){
        STATES(0);
        getch();
        return ;
    }
    else{
        // Free existing nodes; or truncate the accounts
        BankAcc *current = *first;
        BankAcc *nextAcc;

        while (current != NULL) {
            nextAcc = current->next;
            free(current->AccHolder); // Free memory for the account holder's name
            free(current);             // Free memory for the current node
            current = nextAcc;
        }

        *first=NULL;

        printf("Success: Session truncated.\n");
        return ;
    }
}

//Loading back data from file
int LastSave(BankAcc **first){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Last Save Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    // Free existing nodes; or truncate the accounts
    BankAcc *current = *first;
    BankAcc *nextAcc;

    while (current != NULL) {
        nextAcc = current->next;
        free(current->AccHolder); // Free memory for the account holder's name
        free(current);             // Free memory for the current node
        current = nextAcc;
    }

    *first=NULL;    // Resetting the linked list to be empty

    BankAcc *tmp=*first;
    char buffer[MAX_LINE_SIZE];

    accounts = fopen("mp/accounts/accounts.csv", "r");
    if(accounts==NULL){
        printf("ERROR: Failed to open file: accounts.csv\n");
        fclose(accounts);
        return 11;
    }
    else{
        while (fgets(buffer, sizeof(buffer), accounts) != NULL) {
            // Allocate memory for AccHolder
            tmp=(BankAcc *)malloc(sizeof(BankAcc));
            tmp->AccHolder = (char *)malloc(150 * sizeof(char));

            // Use sscanf to parse the line into variables
            if (sscanf(buffer, "%d,%149[^,],%d,%f\n", &tmp->AccNumber, tmp->AccHolder, 
                                                    &tmp->AccType, &tmp->Balance) == 4) {
                // Initialize the next node
                tmp->next = NULL;

                // Link the new node to the list
                if (*first == NULL) {    
                    *first = tmp;
                }
                else{
                    BankAcc *current = *first;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = tmp;
                }
            }
            else{
                printf("ERROR: Couldn't parse the line: %s", buffer);
                free(tmp->AccHolder); // Free memory for the account holder's name
                free(tmp);            // Free memory for the current node
                fclose(accounts);
                return 77;
            }
        }
    }
    fclose(accounts);

    return 9;
}

int SaveAccounts(BankAcc *fileOps){
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Save Accounts Function Called.", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    if(fileOps==NULL){
        accounts=fopen("mp/accounts/accounts.csv","w");
        if(accounts==NULL){
            printf("ERROR: Failed to open file: accounts.csv\n");
            fclose(accounts);
            return 8;
        }
    }
    else{
        accounts=fopen("mp/accounts/accounts.csv","w");
        if(accounts==NULL){
            printf("ERROR: Failed to open file: accounts.csv\n");
            fclose(accounts);
            return 10;
        }
        else{
            while(fileOps != NULL){
                fprintf(accounts,"%d,%s,%d,%.2f\n", fileOps->AccNumber, fileOps->AccHolder, fileOps->AccType, fileOps->Balance);
                fileOps=fileOps->next;
            }
        }
        fclose(accounts);
        return 8;
    }
}

int main() {
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char tempStr[150];
    sprintf(tempStr,"\n[%04d-%02d-%02d %02d:%02d]---SESSION STARTED---", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    // Initializations
    int state,delcnf;
    char confirmation;
    BankAcc *first = NULL; // Initialize to NULL
    BankAcc *tmp = first; // temperorary; Initialize a pointer to the current node
    BankAcc *acc;

    /*  LOADING ACCOUNTS AND SORTING  */
    LastSave(&first);
    mergeSort(&first);

    /* MAIN CODE START */
    int ch,pass,accNo;
    float amnt;

    mmHeader();
str:
    printf("0  -- To login as a/an customer/user\n");
    printf("9  -- Exit\n");
    printf("Enter access code:-\n");
    printf("   --->");
    while(1){
        if(scanf("%d",&pass)){
            break;
        }
        else{
            printf("Invalid input, please go again..\n");
            goto str;
        }
    }
    while (getchar() != '\n');      //flushing newline(\n) buffer
    if(pass==9){
        ch=9;
        mmHeader();
        printf("Exiting..!\n");
    }
    else if(first == NULL && pass != PWD && pass != 9){
        STATES(0);
        printf("Please login as admin or exit...\n");
        getch();
        mmHeader();
        goto str;
    }
    else if(pass==0){
    restr:
        mmHeader();
        printf("Enter your account number(9 to go back): ");
        scanf("%d", &accNo);
        //find account node
        acc=AccNode(first,accNo);
        if(accNo == 9 && acc == NULL){
            goto str;
        }
        else if(acc == NULL){
            STATES(7);
            printf("Press any key to continue...\n");
            getch();
            goto restr;
        }
        adminPrivileges=0;
    }
    else if(pass==PWD){
        adminPrivileges=1;
    }
    else{
        printf("Wrong password, please try again:-\n");
        goto str;
    }

    //switch cases and main code(lol) -- Try to keep this collapsed
    while(ch != 9){
        mmHeader();
        printf("1. Customer Options\n");
        if(adminPrivileges==0){
            printf("3. Log in as admin\n");
        }
        else if(adminPrivileges==1){
            printf("2. Admin Tools\n");
            printf("3. Log out as Admin\n");
        }
        printf("9. Exit\n");
        printf("   --->");
        scanf("%d", &ch);
        switch (ch){
            case 1:
            while(ch != 8 & ch !=9){
                mmHeader();
                printf("1. Account Details\n");
                printf("2. Fetch Balance\n");
                printf("3. Withdraw Money\n");
                printf("4. Deposit Money\n");
                printf("5. Mini Statement\n");
                printf("8. Back\n");
                printf("9. Exit\n");
                printf("   --->");
                scanf("%d", &ch);
                switch(ch){
                    case 1:
                        mmHeader();
                        if(first==NULL){
                            STATES(0);
                            getch();
                        }
                        else{                            
                            if(adminPrivileges){
                                    tmp = first;
                                    printf("Account Number\t%-30s\tBalance\n","Holder");
                                    while(tmp!=NULL){
                                        printf("%d\t\t%-30s\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->Balance);
                                        tmp=tmp->next;
                                    }
                                    printf("\nEnter Account number for details:\n    --->");
                                    scanf("%d", &accNo);
                                    acc=AccNode(first,accNo);
                                    if(acc==NULL){
                                        printf("ERROR: Account not found or doesn't exists!");
                                        getch();
                                        break;
                                    }
                                    else{
                                        printf("Account Details:-\n");
                                        printf("Account Number: %d\n", acc->AccNumber);
                                        printf("Account Holder: %s\n", acc->AccHolder);
                                        printf("Balance: %.2f\n", acc->Balance);
                                        printf("Account Type:-");
                                        AccTYPES(acc->AccType);
                                        printf("\nPress any key to continue..\n");
                                        getch();
                                    }
                            }
                            else if(acc != NULL && adminPrivileges==0){
                                
                                printf("Your account details:-\n");
                                printf("Account Number: %d\n", acc->AccNumber);
                                printf("Account Holder: %s\n", acc->AccHolder);
                                printf("Balance: %.2f\n", acc->Balance);
                                printf("Account Type:-\n");
                                AccTYPES(acc->AccType);
                                printf("\nPress any key to continue..\n");
                                getch();
                            }
                        }

                        break;

                    case 2:
                        mmHeader();
                        if(first==NULL){
                            STATES(0);
                            getch();
                        }
                        else{                            
                            if(adminPrivileges){
                                    tmp = first;
                                    printf("Account Number\t%-30s\tBalance\n","Holder");
                                    while(tmp!=NULL){
                                        printf("%d\t\t%-30s\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->Balance);
                                        tmp=tmp->next;
                                    }
                                    printf("\nPress any key to continue..\n");
                                    getch();
                            }
                            else if(acc != NULL && adminPrivileges==0){
                                printf("Balance: %.2f\n", acc->Balance);
                                printf("Account Type:-\n");
                                AccTYPES(acc->AccType);
                                printf("\nPress any key to continue..\n");
                                getch();
                            }
                        }

                        break;

                    case 3:
                        mmHeader();
                        if(first==NULL){
                            STATES(0);
                            getch();
                        }
                        else{                            
                            if(adminPrivileges){
                                    tmp = first;
                                    printf("Account Number\t%-30s\tBalance\n","Holder");
                                    while(tmp!=NULL){
                                        printf("%d\t\t%-30s\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->Balance);
                                        tmp=tmp->next;
                                    }
                                    printf("\nEnter Account number to withdraw from:\n    --->");
                                    scanf("%d", &accNo);
                                    acc=AccNode(first,accNo);
                                    if(acc==NULL){
                                        printf("ERROR: Account not found or doesn't exists!");
                                        getch();
                                        break;
                                    }
                                    else{
                                        printf("Account Type Details:-\n");
                                        AccTYPES(acc->AccType);
                                        printf("Enter amount to withdraw: ");
                                        scanf("%f", &amnt);
                                        withCash(acc, amnt);
                                        printf("New Balance: %.2f", acc->Balance);
                                        printf("\nPress any key to continue..\n");
                                        getch();
                                    }
                            }
                            else if(acc != NULL && adminPrivileges==0){
                                printf("Your account:-\n");
                                printf("Account Number\t%-30s\tBalance\n","Holder");
                                printf("%d\t\t%-30s\t%.2f\n",acc->AccNumber,acc->AccHolder,acc->Balance);
                                printf("Account Type Details:-\n");
                                AccTYPES(acc->AccType);
                                printf("Enter amount to withdraw: ");
                                scanf("%f", &amnt);
                                withCash(acc, amnt);
                                printf("New Balance: %.2f", acc->Balance);
                                printf("\nPress any key to continue..\n");
                                getch();
                            }
                        }
                        break;
                    
                    case 4:
                        mmHeader();
                        if(first==NULL){
                            STATES(0);
                            getch();
                        }
                        else{                            
                            if(adminPrivileges){
                                tmp = first;
                                printf("Account Number\t%-30s\tBalance\n","Holder");
                                while(tmp!=NULL){
                                    printf("%d\t\t%-30s\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->Balance);
                                    tmp=tmp->next;
                                }
                                printf("\nEnter Account number to deposit into:\n    --->");
                                scanf("%d", &accNo);
                                acc=AccNode(first,accNo);
                                if(acc==NULL){
                                    STATES(7);
                                    getch();
                                    break;
                                }
                                else{
                                    printf("Account Type Details:-\n");
                                    AccTYPES(acc->AccType);
                                    printf("Enter amount to deposit: ");
                                    scanf("%f", &amnt);
                                    depCash(acc, amnt);
                                    printf("New Balance: %.2f", acc->Balance);
                                    printf("\nPress any key to continue..\n");
                                    getch();
                                }
                            }
                            else if(acc != NULL && adminPrivileges==0){
                                printf("Your account:-\n");
                                printf("Account Number\t%-30s\tBalance\n","Holder");
                                printf("%d\t\t%-30s\t%.2f\n",acc->AccNumber,acc->AccHolder,acc->Balance);
                                printf("Account Type Details:-\n");
                                AccTYPES(acc->AccType);
                                printf("Enter amount to deposit: ");
                                scanf("%f", &amnt);
                                depCash(acc,amnt);
                                printf("New Balance: %.2f", acc->Balance);
                                printf("\nPress any key to continue..\n");
                                getch();
                            }
                        }
                        break;
                    
                    case 5:
                        mmHeader();
                        if(first==NULL){
                            STATES(0);
                            getch();
                        }
                        else{                            
                            if(adminPrivileges){
                                tmp = first;
                                printf("Account Number\t%-30s\tBalance\n","Holder");
                                while(tmp!=NULL){
                                    printf("%d\t\t%-30s\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->Balance);
                                    tmp=tmp->next;
                                }
                                printf("\nEnter Account number for Mini Statement:\n    --->");
                                scanf("%d", &accNo);
                                acc=AccNode(first,accNo);
                                if(acc==NULL){
                                    STATES(7);
                                    getch();
                                    break;
                                }
                                else{
                                    printf("*********************************\n");
                                    MiniStmnt(acc);
                                    printf("*********************************\n");
                                    printf("Press any key to continue..\n");
                                    getch();
                                }
                            }
                            else if(acc != NULL){
                                printf("*********************************\n");
                                printf("Your account:-\n");
                                printf("Account Number\t%-30s\tBalance\tType\n","Holder");
                                printf("%d\t\t%-30s\t%.2f\t%d\n",acc->AccNumber,acc->AccHolder,acc->Balance,acc->AccType);
                                AccTYPES(acc->AccType);
                                printf("*********************************\n");
                                MiniStmnt(acc);
                                printf("*********************************\n");
                                printf("Press any key to continue..\n");
                                getch();
                            }
                        }
                        break;
                    
                    case 8:
                        break;
                        
                    case 9:
                        mmHeader();
                        printf("Exiting..!\n");
                        break; //when ch becomes 9 loop will be over

                    default:
                        mmHeader();
                        printf("Wrong option please select again:-\n");
                }
            }
                break;

            case 2:
            while(ch != 8 & ch !=9){
                mmHeader();
                if(adminPrivileges==0){
                    printf("YOU ARE NOT WELCOME HERE (angryface emoji)!!\n");
                    printf("Press any key to continue.");
                    getch();
                    break;
                }
                printf("1. Create Account\n");
                printf("2. Modify Account\n");
                printf("3. Remove Account\n");
                printf("4. Display Accounts\n");
                printf("5. Sort Accounts(Overhead!)\n");
                printf("6. Advanced\n");
                printf("8. Back\n");
                printf("9. Exit\n");
                printf("   --->");
                scanf("%d", &ch);
                switch(ch){
                    case 1: 
                        mmHeader();
                        first=createAcc(first);
                        break;
                    
                    case 2:
                        mmHeader();
                        modAcc(first);
                        state=SaveAccounts(first);
                        STATES(state);
                        break;
                    
                    case 3:
                        tmp=first;
                        mmHeader();
                        if(tmp==NULL){
                            STATES(0);
                            getch();
                            break;
                        }
                        else{
                            printf("Accounts currently in system:-\n");
                            printf("Account Number\t%-30s\tType\tBalance\n","Holder");
                            while(tmp!=NULL){
                                printf("%d\t\t%-30s\t%d\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->AccType,tmp->Balance);
                                tmp=tmp->next;
                            }
                        }
                        state=remAcc(&first);
                        STATES(state);
                        state=SaveAccounts(first);
                        STATES(state);
                        getch();
                        break;

                    case 4:
                        tmp = first;
                        mmHeader();
                        if(tmp==NULL){
                            STATES(0);
                        }
                        else{
                            printf("Accounts currently in system:-\n");
                            printf("Account Number\t%-30s\tType\tBalance\n","Holder");
                            while(tmp!=NULL){
                                printf("%d\t\t%-30s\t%d\t%.2f\n",tmp->AccNumber,tmp->AccHolder,tmp->AccType,tmp->Balance);
                                tmp=tmp->next;
                            }
                            printf("\nPress any key to coninue.\n");
                        }
                        getch();
                        break;

                    case 5:
                        mmHeader();
                        //Clocking Merge Sort Start Time
                        clock_t st = clock();
                        printf("Sorting the accounts.. Please wait..!\n");
                        state = mergeSort(&first);
                        if(state == 12){
                            clock_t et = clock();
                            double time_taken = ((double)et - st) / CLOCKS_PER_SEC;
                            printf("Time Taken to Sort: %f\n", time_taken);
                            STATES(state);
                            printf("Press any key to continue..\n");
                        }
                        else{
                            printf("WARNING: SORTING WAS INCOMPLETED.\nPOSSIBLE DB DAMAGE DONE!\n");
                        }
                        getch();
                        break;

                    case 6:
                    while(ch != 7 && ch != 9){
                        mmHeader();
                        printf("1. Reload Accounts(last commit)\n");
                        printf("2. Save Accounts data\n");
                        printf("3. Delete all accounts\n");
                        printf("4. Admin Logs\n");
                        printf("5. Clear Admin Logs\n");
                        printf("6. Logs of this session\n");
                        printf("7. Back\n");
                        printf("9. Exit\n");
                        printf("   --->");
                        scanf("%d", &ch);
                        switch(ch){
                            case 1:
                                mmHeader();
                                printf("WARNING: THIS WILL TRUNCATE ALL DATA OF CURRENT SESSION\n");
                                printf("      AND LOAD DATA FROM LAST COMMIT TO DATABASE!\n");
                                printf("DO YOU WISH TO CONTINUE? (y/n): ");
                                scanf("%s", &confirmation);
                                if(confirmation == 'Y' || confirmation == 'y'){
                                    state=LastSave(&first);
                                    STATES(state);
                                    mergeSort(&first);
                                    getch();
                                }
                                else{
                                    printf("WARNING: INVALID INPUT.\nGOING BACK\n");
                                }
                                break;
                    
                            case 2:
                                mmHeader();
                                mergeSort(&first);
                                state=SaveAccounts(first);
                                STATES(state);
                                getch();
                                break;
                            
                            case 3:
                                mmHeader();
                                printf("WARNING: THIS WILL TRUNCATE ALL DATA FROM CURRENT SESSION\n");
                                printf("      AND POTENTIALLY FROM THE DATABASE!\n");
                                printf("DO YOU WISH TO CONTINUE? (y/n): ");
                                scanf("%s", &confirmation);
                                if(confirmation == 'Y' || confirmation == 'y'){
                                delType:
                                    mmHeader();
                                    printf("Where would you like to delete the accounts from?\n");
                                    printf("1. Session(Memory)\n");
                                    printf("2. Database\n");
                                    printf("3. Both\n");
                                    printf("4. GO BACK\n");
                                    printf("CHOOSE WITH CAUTION!\n");
                                    printf("    --->");
                                    scanf("%d", &delcnf);
                                    switch(delcnf){
                                        case 1:
                                            mmHeader();
                                            delAccSession(&first);
                                            getch();
                                            break;
                                        
                                        case 2:
                                            mmHeader();
                                            delAccDB();
                                            getch();
                                            break;

                                        case 3:
                                            mmHeader();
                                            printf("WARNING: THIS WILL DELETE ALL THE DATA OF CURRENT SESSION\n");
                                            printf("      AND THE DATA FROM DATABASE!\n");
                                            printf("IT IS ADVICED THAT YOU GO BACK(b) OR ATLEAST KEEP LOCAL BACKUP!\n");
                                            printf("DO YOU WISH TO CONTINUE? (y/n/b): ");
                                            scanf("%s", &confirmation);
                                            if(confirmation == 'Y' || confirmation == 'y'){
                                                delAccSession(&first);
                                                delAccDB();
                                                getch();
                                            }
                                            else if(confirmation == 'B' || confirmation == 'b'){
                                                goto delType;
                                            }
                                            break;

                                        case 4:
                                            break;

                                        default:
                                            mmHeader();
                                            printf("Wrong input, going back!\n");
                                            getch();
                                            break;
                                    }
                                }
                                else{
                                    break;
                                }
                                break;

                            case 4:
                                mmHeader();
                                printLog();
                                break;

                            case 5:
                                mmHeader();
                                clearLog();
                                break;

                            case 6:
                                mmHeader();
                                printf("Logs:-\n");
                                for(int i=0;i<IndexForStack;i++){
                                    printf("%s\n", StackOfFunctionCalls[i]);
                                }
                                printf("--Logs End--\nPress Any key to conitnue..");
                                getch();
                                break;

                            case 7:
                                break;
                            
                            case 9:
                                mmHeader();
                                printf("Exiting..\n");
                                break;

                            default:
                            mmHeader();
                            printf("Wrong selection.. please try again..\n"); 
                        }
                    }
                        
                    case 8:
                        break;
                    
                    case 9:
                        mmHeader();
                        printf("Exiting..!\n");
                        break; //when ch becomes 9 loop will be over
                    
                    default:
                        mmHeader();
                        printf("Wrong selection.. please try again..\n");
                }
            }
            break;

            case 3:
                mmHeader();
                if(adminPrivileges==0){
                    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Admin Logged In", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
                    PushCall(tempStr);
                st:
                    printf("Enter admin password(99 to go back): ");
                    scanf("%d",&pass);
                    if(pass==PWD){
                        adminPrivileges=1;
                        printf("Admin Privileges Enabled.\n");
                        printf("Press any key to continue.\n");
                        getch();
                    }
                    else if(pass==99){
                        continue;
                    }
                    else{
                        mmHeader();
                        printf("Wrong password, please try again:-\n");
                        goto st;
                    }
                }
                else if(pass==PWD && adminPrivileges==1){
                    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]Admin Logged Out", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
                    PushCall(tempStr);
                    mmHeader();
                    printf("Logged out!\n");
                    adminPrivileges=0;
                    if(first==NULL){
                        mmHeader();
                        STATES(0);
                        printf("Exiting..\n");
                        ch=9;
                        getch();
                    }
                    else{
                        printf("Enter your account number: ");
                        scanf("%d", &accNo);
                        //find account node
                        acc=AccNode(first,accNo);
                    }
                }
                break;
            
            case 9:
                mmHeader();
                printf("Exiting..!\n");
                break;
            
            default:
                mmHeader();
                printf("Wrong option please select again:-\n");
        }
    }


    /* MAIN CODE END */

    /*  SORTING AND SAVING ACCOUNTS  */
    mergeSort(&first);
    SaveAccounts(first);

    /* FREEING NODES AFTER USAGE */
    BankAcc *current = first; 
    BankAcc *nextAcc;

    while (current != NULL) {
        nextAcc = current->next;
        free(current->AccHolder); // Free memory for the account holder's name
        free(current);             // Free memory for the current node
        current = nextAcc;
    }

    sprintf(tempStr,"[%04d-%02d-%02d %02d:%02d]---SESSION ENDED---", timeinfo->tm_year + 1900, 
                                    timeinfo->tm_mon + 1, timeinfo->tm_mday,timeinfo->tm_hour, timeinfo->tm_min);
    PushCall(tempStr);

    return 0;
}

void STATES(short a){
    switch(a){
        case 0:    
        printf("ERROR: NO ACCOUNTS CURRENTLY IN SYSTEM!\n");
        break;

        case 1:    
        printf("Success: Account removed.\n");
        break;

        case 3:    
        printf("Success: Account Created.\n");
        break;

        case 4:    
        printf("Success: Account Added.\n");
        break;

        case 5:    
        printf("Success: Cash withdrawn.\n");
        break;

        case 6:
        printf("Success: Cash deposited.\n");
        break;

        case 7:
        printf("ERROR: No account with that account number found!\n");
        break;

        case 8:
        printf("Success: Accounts Saved.\n");
        break;

        case 9:
        printf("Success: Accounts Loaded.\n");
        break;

        case 10:
        printf("ERROR: Accounts NOT Saved.\n");
        break;

        case 11:
        printf("ERROR: Accounts NOT Loaded.\n");
        break;

        case 12:
        printf("Success: Accounts successfully sorted!\n");
        break;

        case 99:
        break;

        default:
        printf("WARNING: Unknown error occured.\n");
    }
}

void AccTYPES(short a){
    //Type 0:-
    printf("\nAccount Type\tUp Limit\tDown Limit\n");
    if(a==0){
        printf("%-13s\t50000\tN/A\n", "Minor");
    }
    else if(a==1){
        //Type 1:-
        printf("%-13s\t500000\t\tN/A\n", "Standard");
    }
    else{
        //Type 2:-
        printf("%-13s\t10000000\t\t10000\n", "Enterprise");
    }
}

/* End of Program */