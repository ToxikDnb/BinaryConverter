#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define mdp 48

int main(){
    int isRunning = 1;
    while(isRunning){
        printf("Please enter the number to convert to binary: ");
        char c_response[mdp];
        fgets(c_response, mdp, stdin);
        if(!strcmp(c_response, "exit\n")){
            isRunning = 0;
        }
        else{
            int response = atoi(c_response);
            int storedResponse = response;
            int highestBinNum = 1;
            while(highestBinNum<=response){
                printf("%d", highestBinNum);
                highestBinNum*=2;
            }
            int amountOfDigits = log(highestBinNum)/log(2);
            char num[amountOfDigits];
            int nextFree = 0;
            for(int i = 0; i <= amountOfDigits; i++){
                if(response-highestBinNum >= 0){
                    response -= highestBinNum;
                    num[nextFree] = '1';
                }
                else{
                    num[nextFree] = '0';
                }
                highestBinNum /= 2;
                nextFree++;
            }
            num[nextFree] = '\0';
            printf("\n\n%d in binary = %s\n", storedResponse, num);
        }
    }
    return 0;
}