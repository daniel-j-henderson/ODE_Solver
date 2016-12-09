/*
 *
 *  File: equations.c
 *
 *  This file implements a system of ODEs by providing routines
 *  to query the size of the system's state vector, get initial
 *  conditions, and return the time-derivative of the state vector given
 *  the current state. The state vector and its time-derivative are
 *  represented using the state_t structure.
 *
 */

#include "equations.h"
#include <stdio.h>

float beta = (float)8/(float)3;
float rho = 28.0;
float sigma = 10.0;

/***********************************************************************
 *
 *  Function: get_system_size
 *
 *  Returns the size of the state vector for the system.
 *
 ***********************************************************************/
int get_system_size(void)
{
	return 3; //that's the size for this system
}


/***********************************************************************
 *
 *  Function: set_initial_state
 *
 *  Initializes a system state vector. Upon returning, the elements of s
 *  have been set to contain the initial condition of the system.
 *
 ***********************************************************************/
void set_initial_state(state_t *s)
{
    int d = 0;
    float a, b, c;            //Well I went ahead and just added user-input-initial conditions.
    printf("\nSET INITIAL CONDITIONS OF THE SYSTEM\n        x0 = ");
    while (!d) {if (scanf("%f", &a)) d = 1; else printf("\nInput a float please\n\n        x0 = "); scanf("%*[^\n]%*c");}
    printf("\n        y0 = ");
    d = 0;
    while (!d) {if (scanf("%f", &b)) d = 1; else printf("\nInput a float please\n\n        y0 = "); scanf("%*[^\n]%*c");}
    printf("\n        z0 = ");
    d = 0;
    while (!d) {if (scanf("%f", &c)) d = 1; else printf("\nInput a float please\n\n        z0 = "); scanf("%*[^\n]%*c");}
    printf("\n\n");

	 s->x[0] = a; //I read that it doesn't matter the initial conditions for this system (as long as they're not all 0)
	 s->x[1] = b; //so I just went with this. I also messed around with 0, 1, 1.05, I saw that on the internet.
	 s->x[2] = c; //Also did y'all want the user to input these? It's not hard to do, could add that right here.

}


/***********************************************************************
 *
 *  Function: f
 *
 *  This function returns a tendency vector, ds/dt, for the system, given
 *  the current state of the system.
 *
 ***********************************************************************/
void f(float t, const state_t *s, state_t *ds)
{
	 ds->x[0] = sigma * (s->x[1] - s->x[0]);        //evaluating the tendency at each state.
	 ds->x[1] = s->x[0]*(rho - s->x[2]);            //Since we are using Euler's method (and the time derivative is dependent only on position),
     ds->x[2] = s->x[0]*s->x[1] - beta * s->x[2];   //we don't need the current time t for this system
}
