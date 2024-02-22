#include <stdio.h>

int main ()
{
    FILE *clientPtr;
    clientPtr = fopen("client.dat", "r");
    if (clientPtr != NULL) {
        int loop = 1;
        unsigned int account;
        char name[30];
        double balance;

        while (loop) {        
            printf("Enter Request\n1- List accounts with zero balances\n2- List accounts with credit balances\n3- List accounts with debit balances\n4- End of run\n");
            unsigned int request;
            scanf("%u", &request);

            fscanf(clientPtr, "%d%29s%lf", &account, name, &balance);
            switch (request) {
                case 1:
                    printf("\nAccounts with zero balances:\n");
                    while (!feof(clientPtr)) {
                        if (balance == 0)
                        { printf("%-10d%-13s%7.2f\n", account, name, balance); }
                        fscanf(clientPtr, "%d%29s%lf", &account, name, &balance);
                    }
                    printf("\n");
                    rewind(clientPtr);
                    break;
                case 2:
                    printf("Accounts with credit balances:\n");
                    while (!feof(clientPtr)) {
                        if (balance < 0)
                        { printf("%-10d%-13s%7.2f\n", account, name, balance); }
                        fscanf(clientPtr, "%d%29s%lf", &account, name, &balance);
                    }
                    printf("\n");
                    rewind(clientPtr);
                    break;
                case 3:
                    printf("Accounts with debit balances:\n");
                    while (!feof(clientPtr)) {
                        if (balance > 0)
                        { printf("%-10d%-13s%7.2f\n", account, name, balance); }
                        fscanf(clientPtr, "%d%29s%lf", &account, name, &balance);
                    }
                    printf("\n");
                    rewind(clientPtr);
                    break;
                case 4:
                    loop = 0;
                    break;
            }
        }
        printf("End of the file.\n");
        fclose(clientPtr);
    }
    else
    { printf("File could not be opened.\n"); }
}