#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursorBased.h"

Student newStudent(int studID, String studName, char sex, String program) {
	Student s;
	
	s.studID = studID;
	strcpy(s.studName, studName);
	s.sex = sex;
	strcpy(s.program, program);
	
	return s;
}

VirtualHeap newVirtualHeap() {
	VirtualHeap vh;
	int i;
	
	for(i = 0; i < MAX; ++i) {
		vh.elems[i].elem = newStudent(0, "", ' ', "");
		vh.elems[i].next = i-1;
	}
	vh.avail = MAX - 1;
	
	return vh;
}

int allocSpace(VirtualHeap *vh) {
	int retVal = vh->avail;
	
	if(retVal != -1) {
		vh->avail = vh->elems[vh->avail].next;
		
	}
	return retVal;
}

void insertFront(VirtualHeap *vh, List *list, Student s) {
	List temp = allocSpace(vh);
	
	if(temp != -1) {
		vh->elems[temp].next = *list;
		vh->elems[temp].elem = s;
		*list = temp;
	}
}

void visualizeSpace(VirtualHeap vh) {
	int i;
	printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
	printf("---------------------------------------------\n");

	for(i = 0; i < MAX; ++i) {
		printf("%5d | ", i);
		if(vh.elems[i].elem.studID == 0) {
			printf("%30s | ", "EMPTY");
		} else {
			printf("%4d - %23s | ", vh.elems[i].elem.studID, vh.elems[i].elem.studName);
		}
		printf("%3d\n", vh.elems[i].next);
	}
	printf("---------------------------------------------\n");
	printf("AVAILABLE: %d \n\n", vh.avail);
	
}

void displayList(VirtualHeap vh, List list) {
	List trav;
	printf("\n");
	
	for(trav = list; trav != -1; trav = vh.elems[trav].next) {
		printf("%4d | %23s | %3c | %7s \n", vh.elems[trav].elem.studID, vh.elems[trav].elem.studName, vh.elems[trav].elem.sex, vh.elems[trav].elem.program);
	}
	
}

void deallocSpace(VirtualHeap *vh, int index) {
	if(index != -1  && index < MAX) {
		vh->elems[index].next = vh->avail;
		vh->elems[index].elem = newStudent(0, "", ' ', "");
		vh->avail = index;
	}
}


Student removeStudent(VirtualHeap *vh, List *list, String keyword) {
    List trav = *list;
    List prev = -1;

    while (trav != -1) {
        if (strcmp(keyword, vh->elems[trav].elem.studName) == 0) {
            if (prev == -1) {
                *list = vh->elems[trav].next;
            } else {
                vh->elems[prev].next = vh->elems[trav].next;
            }

            Student removedStudent = vh->elems[trav].elem;
            deallocSpace(vh, trav);
            return removedStudent;
        }

        prev = trav;
        trav = vh->elems[trav].next;
    }

    // Return a default student if the specified student is not found
    Student defaultStudent;
    defaultStudent.studID = 0;
    defaultStudent.sex = ' ';
    strcpy(defaultStudent.studName, "");
    strcpy(defaultStudent.program, "");
    return defaultStudent;
}

