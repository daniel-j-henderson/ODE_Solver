/*
 *  NOTE: Change File path for
 *  File: observer.c
 *
 *  This file implements the ability to "observe" the state vector of
 *  a system of equations by writing that state in some format to a file
 *  for later viewing or plotting.
 *
 */

#include "observer.h"
#include <stdio.h>
#include <stdlib.h>


 FILE * fp; //create a file pointer for use by all the functions in this module


/***********************************************************************
 *
 *  Function: observer_init
 *
 *  Initializes the observer module by, e.g., opening files for later
 *  writing. This routine must be called before the first call
 *  to observer_write().
 *
 ***********************************************************************/
void observer_init(void)
{
    /*
     * NOTE: Due to limitations of CodeBlocks, the executable doesn't run in the directory it appears to be sitting in (inside
     * my ODE_Solver folder), so I had to route the data.txt as below in order to be able to find the text file at the end.
     *
     * If I need to change machines, then this data path must be adjusted to "data.txt"
     *
     */

	 fp = fopen("data.txt", "w+"); //opens a file called data.txt that we'll print to
}


/***********************************************************************
 *
 *  Function: observer_write
 *
 *  Formats and writes the contents of the state vector s to a file.
 *
 ***********************************************************************/
void observer_write(const state_t *s)
{
	 int m = s->n;
	 int l;
	 for (l = 0; l < m; l++) {
        fprintf(fp, "%f ", s->x[l]); //prints each element x, y, z of the state, followed by a space (delimiter)
	 }
	 fprintf(fp, "\n"); //prints newline
}


/***********************************************************************
 *
 *  Function: observer_finalize
 *
 *  Finalizes the observer module by, e.g., closing any files that were
 *  opened by the module. This routine must be called only once after
 *  all calls to observer_write() have been made.
 *
 ***********************************************************************/
void observer_finalize(void)
{
	 fclose(fp); //closes the filestream
}
