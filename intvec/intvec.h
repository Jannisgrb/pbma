/*
 * intvec.h
 *
 *  Created on: 01.04.2026
 *      Author: n3030503
 */

#ifndef INTVEC_H_
#define INTVEC_H_
#include <iostream>
using namespace std;

struct intvec {
	size_t capacity;
	size_t size;
	int *arr;
};

void ivec_init(intvec* ivec, size_t cap);
//Initialisiert ein frisches intvec, das
//zum Beispiel auf dem Stack liegt, mit angegebener Kapazität und Größe 0.

void ivec_clear(intvec* ivec);
//Gibt den Freispeicher wieder frei, damit nichts
//böses passiert, werden die Attribute des struct passend gesetzt.

void ivec_pushback(intvec* ivec, int ele);
//Hängt ein Element an das Ende des Arrays an. Falls zu wenig Speicher
//da ist, dann wird das Array durch ein Array mit doppelt so großer
//Kapazität ersetzt, die alten Werte bleiben erhalten.

int& ivec_at(intvec* ivec, size_t idx);
//Den Wert an der Stelle idx oder einen
//Abbruch, wenn der Wert nicht existiert/gültig ist.

int ivec_sum(intvec* ivec);
//Berechnet die Summe der verwalteten Werte.


#endif /* INTVEC_H_ */
