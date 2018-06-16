/*
 * Author: Suraj Rajendra Bhosale.
 * Description: This is a practice code for illustrating Object Oriented Programming approach in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_oop.h"

/* 
 * Structure used as class
 */

typedef class student{
    int rollno;
    char name[100];
    float percentage;
    
    void (*setValuesPtr)(class student *,int, char *, float);
    void (*printValuesPtr)(class student *);
}student;


/*
 * Student class's member function definitions
 */
void setValues(student *this, int rollno, char *name, float percentage) {
   
    if(this==NULL) {
        perror("Create object first [use constructor]");
        return;
    }

    this->rollno=rollno;
    this->percentage=percentage;
    strcpy(this->name,name);
}


void printValues(student *this) {
   
    if(this==NULL) {
        perror("Create object first [use constructor]");
        return;
    }


    fprintf(stdout,"Roll no:- %d\n",this->rollno);
    fprintf(stdout,"Name:- %s\n",this->name);
    fprintf(stdout,"Percentage:- %f\n\n",this->percentage);
}


/*
 * This is the student class default constructor
 */
student * __student() {

    student *temp=(student *) malloc(sizeof(student));
    temp->setValuesPtr=setValues;
    temp->printValuesPtr=printValues;
}



/*
 * Wrapper main function
 */
int main() {

    student *obj1 = __student();
    obj1->setValuesPtr(obj1,16205,"Suraj Rajendra Bhosale",80.64);
    obj1->printValuesPtr(obj1);
    
    student *obj2 = __student();
    obj2->setValuesPtr(obj2,16201,"Pravin Vinayak Ahire",89.64);
    obj2->printValuesPtr(obj2);
 

    return 0;
}
