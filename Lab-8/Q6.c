#include <stdio.h>

int deposit(float *balance, float amount){
    if(amount <= 0){
        return 0;
    }
    *balance = *balance + amount;
    return 1;
}

int withdraw(float *balance, float amount){
    if(amount <= 0 || amount > *balance){
        return 0;
    }
    *balance = *balance - amount;
    return 1;
}

int main(){
    float balance = 1000.0;
    int opt;
    float amt;

    while(1){
        printf("Choose option (1-4): ");
        if(scanf("%d", &opt) != 1){
            break;
        }

        if(opt == 1){
            printf("Enter amount: ");
            scanf("%f", &amt);
            if(deposit(&balance, amt)){
                printf("Amount deposited successfully.\n");
            }else{
                printf("Invalid amount.\n");
            }
        }else if(opt == 2){
            printf("Enter amount: ");
            scanf("%f", &amt);
            if(withdraw(&balance, amt)){
                printf("Amount withdrawn successfully.\n");
            }else{
                printf("Insufficient funds or invalid amount.\n");
            }
        }else if(opt == 3){
            printf("Current balance: %.2f\n", balance);
        }else if(opt == 4){
            printf("Goodbye.\n");
            break;
        }else{
            printf("Invalid option\n");
        }
    }

    return 0;
}
