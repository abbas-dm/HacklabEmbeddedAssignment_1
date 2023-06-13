#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef enum{
    Green,
    Yellow,
    Red
}TrafficLight;

int main(){
    TrafficLight currentState = Green;
    TrafficLight nextState = Green;

    while(1){
        currentState = nextState;
        switch (currentState)
        {
        case Green:
            printf("In Green State for 360 sec \n");
            nextState = Yellow;
            sleep(360);
            break;
        
        case Yellow:
            printf("In Yellow State for 10 sec \n");
            nextState = Red;
            sleep(10);
            break;

        case Red:
            printf("In Red State for 120 sec \n");
            nextState = Green;
            sleep(120);

        default:
            break;
        }
    }
    return 0;
}