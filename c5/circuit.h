/*
 *         File: circuit.h
 *       Author: Steve Gunn
 *      License: MIT License
 *         Date: 27th October 2018
 *  Description: Data structures and interfaces for modified nodal analysis of a circuit containing
 *               voltage sources, current sources and resistors.
 */

#ifndef _CIRCUIT_H
#define _CIRCUIT_H

#include "vector.h"
#include "matrix.h"

/* Data Structures */

// typedef enum
// {
//     /* TODO */

//     voltage;
//     current;
//     resistor;
//     capacitor
// }
// CompType;
typedef enum
{
    voltage,
    current,
    resistor
} ComType;

typedef struct
{
    /* TODO */
    char name[32]; // should be name[32], don't use a pointer.
    unsigned int n1;
    unsigned int n2;
    double value;
    ComType type;
} Component;

typedef struct
{
    /* TODO */
    // c.nC c.comp c.nR c.nV c.nI c.nN
    /*nc= counter(number of components) comp= component nR= number of resistors nV= number of voltage source nI= number of current nN= number of nodes*/
    unsigned int nC;
    unsigned int nR;
    unsigned int nV;
    unsigned int nI;
    unsigned int nN;
    Component *comp;

} Circuit;

/* Interfaces */

Circuit createCircuitFromFile(const char *filename);
void destroyCircuit(Circuit c);
void analyseCircuit(const Circuit c);
Vector solveLinearSystem(Matrix A, Vector b);

#endif