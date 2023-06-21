#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CursorBased.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	VirtualHeap myHeap = newVirtualHeap();
	List myList = -1;
	//List anotherList = -1;
	
	
	
	insertFront(&myHeap, &myList, newStudent(101, "Jonathan", 'm', "BSIT"));
	insertFront(&myHeap, &myList, newStudent(105, "Sebastian", 'm', "BSCS"));
	insertFront(&myHeap, &myList, newStudent(109, "Andrea", 'f', "BSIS"));
	insertFront(&myHeap, &myList, newStudent(103, "Kate", 'f', "BSCS"));
	insertFront(&myHeap, &myList, newStudent(111, "Goliath", 'm', "BSIT"));
	
	visualizeSpace(myHeap);
	
	//printf("%d", myList);
	
	//insertFront(&myHeap, &anotherList, newStudent(100, "Cleo", 'f', "BSCS"));
	
	//displayList(myHeap, myList);
	
	//deallocSpace(&myHeap, 7);
	
	Student removedStudent = removeStudent(&myHeap, &myList, "Andrea");
	displayList(myHeap, myList);
	
	//visualizeSpace(myHeap);
	
	printf("\nRemoved Student: \n%4d | %23s | %3c | %7s \n", removedStudent.studID, removedStudent.studName, removedStudent.sex, removedStudent.program);
	
	return 0;
}
