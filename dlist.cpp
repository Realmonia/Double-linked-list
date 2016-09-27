#ifndef DICKER_H
#define DICKER_H

//orz LukeXuan
//orz Vortex
#include<iostream>
#include<string>
#include<cstdlib>
#include<cassert>
#include "dlist.h"

using namespace std;

template <class T>
bool Dlist<T>::isEmpty() {
	return !first;
}

template <class T>
void Dlist<T>::insertFront(T *op) {
	node *np = new node;
	if (isEmpty()) {
		np->op = op;
		np->next = NULL;
		np->prev = NULL;
		first = np;
		last = np;
	}
	else {
		np->op = op;
		np->next = first;
		first->prev = np;
		np->prev = NULL;
		first = np;
	}

}

template <class T>
void Dlist<T>::insertBack(T* op) {
	node *np = new node;
	if (isEmpty()) {
		np->op = op;
		np->next = NULL;
		np->prev = NULL;
		first = np;
		last = np;
	}
	else {
		np->op = op;
		np->prev = last;
		last->next = np;
		np->next = NULL;
		last = np;
	}
}

template <class T>
T* Dlist<T>::removeFront() {
	node *victim = first;
	T* result;
	if (isEmpty()) {
		emptyList e;
		throw  e;
	}
	first = victim->next;
	if (!first) {
		last=NULL;
	}
	else{
		first->prev = NULL;
	}
	result = victim->op;
	delete victim;
	return result;
}

template <class T>
T* Dlist<T>::removeBack() {
	node *victim = last;
	T* result;
	if (isEmpty()) {
		emptyList e;
		throw  e;
	}
	last = victim->prev;
	if (last) {
		last->next = NULL;
	}
	else {
		first = NULL;
	}
	result = victim->op;
	delete victim;
	return result;
}

template <class T>
Dlist<T>::Dlist(): first(NULL), last(NULL) {}

template <class T>
Dlist<T>::Dlist(const Dlist &l): first(NULL), last(NULL) {
	copyAll(l);
}

template <class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l){
	copyAll(l);
	return *this;
}

template <class T>
Dlist<T>::~Dlist(){
	removeAll();
}

template <class T>
void Dlist<T>::removeAll() {
	while (!isEmpty()){
		T* victim=removeFront();
		delete victim;
	}
}

template <class T>
void Dlist<T>::copyAll(const Dlist &l) {
	if (!isEmpty()){
		removeAll();
	}
	if (!l.first) {
		return;
	}
	node* currentNode=l.first;
	do{
		T* op=new T(*currentNode->op);
		insertBack(op);
		currentNode=currentNode->next;
	} while (currentNode);
}

#endif
