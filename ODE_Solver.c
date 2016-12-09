#include <stdio.h>
#include <stdlib.h>
#include "observer.h"
#include "equations.h"


int main()
{
    // Here's all the local variables for main
    int i, j; //I use these later in some for loops.
    int num = -1; //number of steps to take
    float step_size = -1.0; //delta t - time step size.
    float time = 0;
    state_t state; //the state of the system at each time step, in x, y, z.
    state_t tendency; //the value of the x, y, and z derivatives at each time step

    // User input section for step size and number
    while (num < 0) {
        printf("\nHow many steps through time will we take?\nInput a positive integer\n"); //get the user input
        if (!scanf("%d", &num)) {
            printf("\nYou must input an integer, friend\n");
            scanf("%*[^\n]%*c"); //clear input buffer
            num = -1;
        }
    }
    while (step_size < 0) {
        printf("\nWhat step size (delta t) in seconds?\nInput a positive float\n"); //get the user input
        if (!scanf("%f", &step_size)) {
            printf("\nYou must input a float, friend\n");
            scanf("%*[^\n]%*c"); //clear input buffer
            step_size = -1;
        }
    }
   // printf("\nWhat step size (delta t) in seconds?\n");
   // scanf("%f", &step_size);

    //After getting the system size, use that to allocate memory for the state vector then initialize the system
    state.n = get_system_size();
    tendency.n = get_system_size();
    state.x = (float *) malloc(sizeof(float)*state.n); //allocate memory for the data that the pointer 'x' points to, float pointer typecast
    tendency.x = (float *) malloc(sizeof(float)*tendency.n);
    set_initial_state(&state); //initialize the system

    observer_init(); //initialize the write file

    // Numerical Analysis Section
    // For each time step, we'll determine the tendency vector and next state vector using Euler's method.
    for (i = 0; i < num; i++) { //step through each time step specified by the user

        observer_write(&state); //print the current state to the data file
        f(time, &state, &tendency); //set the tendency vector for the current state in order to get the new state
        for (j = 0; j < state.n; j++) state.x[j] += step_size*tendency.x[j]; //Euler's method
        time += step_size;

    }

    // All done, now we can clean up
    observer_finalize(); //close the data file

    free(state.x); //deallocate the previously allocated memory
    state.x = NULL;
    free(tendency.x);
    tendency.x = NULL;

    printf("\nOk we've written a file to this directory called 'data.text'\nand it contains %d states that are %f seconds apart.\n\n\n", num, step_size);

    return 0;


}
