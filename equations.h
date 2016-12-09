/*
 * 
 *  File: equations.h
 * 
 */
#ifndef _EQUATIONS_H
#define _EQUATIONS_H

#include "state.h"

int get_system_size(void);

void set_initial_state(state_t *s);

void f(float t, const state_t *s, state_t *ds);

#endif
