/********************************************************************
 Name        : project of C programming course
 Author      : Basma Ashraf Kamel
 Date        : 5/8/2024
 Diploma     : 89
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the student structure
struct student{
	int id;
	char name[50];
	int age;
	float gpa;
}info;

// Definition of the node structure for the linked list
struct node{
	struct student data;
	struct node *next;
};

// Pointer to the head of the linked list
struct node *head=NULL;

// Function prototypes
void addStudent(const struct student *const ptr);
int findItemInTheList(int item);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
void displayMenu(void);


int main(){
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	struct student *ptr=&info;// Pointer to store student information
	int YourChoice , Student_id, Update , delete ;
	float AVG;
	while(1){
		displayMenu();
		printf("\nEnter your choice:");
		scanf("%d",&YourChoice);
		printf("\n======================================\n");
		// Switch statement to handle menu choices
		switch(YourChoice){
		case 1:
			// Read student data from user
			printf("enter the student id:");
			scanf("%d" , &ptr->id);
			printf("enter the student name:");
			scanf("%s",ptr->name);
			printf("enter the student age:");
			scanf("%d" , &ptr->age);
			printf("enter the student gpa:");
			scanf("%f" , &ptr->gpa);
			printf("======================================\n");
			addStudent(ptr);
			break;
		case 2:
			displayStudents();
			break;
		case 3:
			printf("enter id to search:");
			scanf("%d",&Student_id);
			searchStudentByID(Student_id);
			break;
		case 4:
			printf("enter id to update student data:");
			scanf("%d",&Update);
			updateStudent(Update);
			break;
		case 5:
			printf("enter id to delete student data:");
			scanf("%d",&delete);
			deleteStudent(delete);
			break;
		case 6:
			AVG=calculateAverageGPA();
			printf("The average of gpa=%f" , AVG);
			printf("\n======================================\n");
			break;
		case 7:
			searchHighestGPA();
			break;
		case 8:
			printf("Exit program");
			return 0;
		}

	}
	return 0;
}


/********************************************************************
 * Function to check if the student id is already exist or not
 *********************************************************************/
int findItemInTheList(int item)
{
	struct node *current = NULL;
	current = head;
	//looping until reache to the end of list
	while(current != NULL){
		if(current->data.id == item){

			printf("This id is already exist");
			printf("\n======================================\n");
			return 1;
		}
		current = current->next;
	}
	return 0;
}

/********************************************************************
 * Function to display the menu to make user choose option
 *********************************************************************/
void displayMenu(void){
	printf("1.Add student information\n");
	printf("2.Display all students information\n");
	printf("3.Search by id\n");
	printf("4.Update student information by id\n");
	printf("5.Delete student data by id\n");
	printf("6.calculate average gpa of all students\n");
	printf("7.Search for highest gpa\n");
	printf("8.Exist program");
}

/********************************************************************
 * if user chooses 1 this function will called
 * allowed user to enter data
 * check if id is already exist or not
 * if id is not exist it check if memory allocation is failed or not
 * If memory allocation is successful, it copies the student data to the new
 * node and adds the node to the end of the linked list
 *********************************************************************/
void addStudent(const struct student *const ptr){
	int checker;
	// Check if the student ID already exists
	checker=findItemInTheList(ptr->id);
	if(checker==1){
		return;
	}
	// Allocate memory for a new node
	else{
		struct node *current = NULL;
		struct node *link = (struct node*) malloc(sizeof(struct node));
		if(link==NULL){
			printf("memory allocation fails");
			printf("======================================\n");
			return;
		}
		else{
			// Copy student data to the new node
			link->data.id = ptr->id;
			strcpy(link->data.name, ptr->name);
			link->data.age = ptr->age;
			link->data.gpa = ptr->gpa;
			link->next = NULL;
			if(head==NULL){
				head = link;
				return;
			}
			current = head;

			while(current->next != NULL){

				current = current->next;
			}

			current->next = link;
		}
	}
}

/********************************************************************
 * if user chooses 2 this function will called
 * Displays all students in the linked list.
 * If the list is empty, it prints a message no students are present.
 * Otherwise, it traverses the list and prints the details of each student.
 *********************************************************************/

void displayStudents(void){
	struct node *ptr = head;
	if(ptr==NULL){
		printf("No students are present.");
		printf("\n======================================\n");
	}
	//start looping from the head until the last node
	while(ptr != NULL)
	{
		printf("{ID=%d  Name:%s  AGE=%d  GPA=%f}\n",ptr->data.id ,ptr->data.name,ptr->data.age,ptr->data.gpa);
		ptr = ptr->next;
	}
	printf("\n======================================\n");
}

/********************************************************************
 * if user chooses 3 this function will called
 * It searches for a student by their ID in the linked list.
 * If the student is found, it prints their details.
 * If the student is not found, it prints a message indicating the student was
 *not found
 *********************************************************************/

void searchStudentByID(int id){
	// pointer to loop in linked list
	struct node *current = NULL;
	if(head==NULL){
		printf("No students are present.");
		printf("\n======================================\n");
		return;
	}
	// start checking from the first node
	current = head;
	while(current != NULL)
	{
		if(current->data.id == id)
		{
			printf("{ID=%d  Name:%s  AGE=%d  GPA=%f}" , current->data.id ,current->data.name,current->data.age,current->data.gpa);
			printf("\n======================================\n");
			return;
		}
		current = current->next;
	}
	// item not found in the list
	printf("student was not found");
	printf("\n======================================\n");
}

/********************************************************************
 * if user chooses 4 this function will called
 * Updates the details of a student with a given ID in the linked list.
 * If the student is found, then update the student's information (student
 *name, age, gpa).
 *If the student is not found, it prints a message indicating the student was
 *not found.
 *********************************************************************/
void updateStudent(int id){
	// pointer to loop in linked list
	struct node *current = NULL;
	if(head==NULL){

		printf("No students are present.");
		printf("\n======================================\n");
		return;
	}
	current = head;
	while(current != NULL)
	{
		if(current->data.id == id)
		{
			printf("New name:");
			scanf("%s",current->data.name);
			printf("New age:");
			scanf("%d" , &current->data.age);
			printf("New gpa:");
			scanf("%f" , &current->data.gpa);
			printf("\n======================================\n");
			return;
		}
		current = current->next;
	}
	printf("student was not found");
	printf("\n======================================\n");
}

/********************************************************************
 *if user chooses 6 this function will called
 *Calculates and returns the average GPA of all students in the linked list.
 * It traverses the list to sum the GPAs of all students and counts the number
 *of students.
 * If the list is empty, it returns 0.0.
 * Otherwise, it computes and returns the average GPA by dividing the total
 *sum of GPAs by the number of students
 *********************************************************************/
float calculateAverageGPA(void){
	struct node *current = head;
	float sum=0.0 ;
	int counter=0;
	if(head==NULL){
		return 0.0;
	}
	while(current != NULL){
		sum=sum+current->data.gpa;
		counter++;
		current = current->next;
	}
	return sum/counter;
}

/********************************************************************
 * if user chooses 7 this function will called
 * Searches for the student with the highest GPA in the linked list.
 * It traverses the list, keeping track of the student with the highest GPA
 *encountered.
 *If the list is empty, it prints a message indicating that there are no students.
 *After finding the student with the highest GPA, it prints the details of that
 *student
 *********************************************************************/
void searchHighestGPA(void){
	struct node *current = NULL;
	if(head==NULL){

		printf("There are no students.");
		printf("\n======================================\n");
		return;
	}
	current = head;
	struct node *max=head;
	while(current != NULL)
	{
		if(current->data.gpa >= max->data.gpa)
		{
			max=current;
		}
		current = current->next;
	}
	printf("{ID=%d  Name:%s  AGE=%d  GPA=%f}" , max->data.id ,max->data.name,max->data.age,max->data.gpa);
	printf("\nThe max GPA=%f" , max->data.gpa);
	printf("\n======================================\n");
}

/********************************************************************
 * if user chooses 5 this function will called
 * Iterates through the linked list of students starting with the Head of it to
 *find the student with the given ID.
 *If the student is found, it adjusts the pointers to remove the node from the
 *list, frees the memory allocated for the node, and prints a success message.
 *If the student is not found, it prints a message indicating the student was
 *not found.
 *********************************************************************/
void deleteStudent(int id){
	struct node *current = NULL;
	struct node *prev = NULL;
	// pointer to point the node that will be deleted
	struct node * delete_node = NULL;

	if(head==NULL)
	{
		printf("No students are present");
		printf("\n======================================\n");
		return;
	}
	// If the student to be deleted is the head of the list
	if(head->data.id == id)
	{
		delete_node = head;
		head = head->next;
		free(delete_node);
		printf("student data deleted successfully");
		printf("\n======================================\n");
		return;
	}
	current = head->next;
	prev = head;
	// Search for the student to be deleted
	while(current != NULL)
	{
		if(current->data.id == id){
			delete_node = current;
			prev->next = current->next;
			free(delete_node);
			printf("student data deleted successfully");
			printf("\n======================================\n");
			return;
		}
		prev = current;
		current = current->next;
	}
	printf("student was not found");
	printf("\n======================================\n");

}
