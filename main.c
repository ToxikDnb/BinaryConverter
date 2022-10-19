#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define mdp 48

void DToB();
void BToD();

int main(){
    int wr = 1;
    while(wr){
        char command[7];
        printf("\nPlease enter your command: ");
        fgets(command, 7, stdin);
        if(!strcmp(command, "help\n")){
            printf("Usage: <Type Input> <Type Output>\n\nSupported types:\n\nBinary : b\nDenary : d");
        }
        else if(!strcmp(command, "d b\n")){
            DToB();
        }
        else if(!strcmp(command, "b d\n")){
            BToD();
        }
        else if(!strcmp(command, "exit\n")){
            wr = 0;
        }
        else{
            printf("\nUnknown Command, please type help for more information.\n");
        }
    }
    return 0;
}

void DToB(){
    int isRunning = 1;
    while(isRunning){
        printf("Please enter the number to convert to binary: ");
        char c_response[mdp];
        fgets(c_response, mdp, stdin);
        if(!strcmp(c_response, "exit\n")){
            isRunning = 0;
        }
        else{
            long long response = atol(c_response);
            long long storedResponse = response;
            long long highestBinNum = 1;
            while(highestBinNum<=response){
                printf("\n%ld\n", highestBinNum);
                highestBinNum*=2;
            }
            int amountOfDigits = log(highestBinNum)/log(2);
            char* num;
            num = (char *)malloc(amountOfDigits*sizeof(char));
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
}

void BToD(){
    printf("\n\n");
}