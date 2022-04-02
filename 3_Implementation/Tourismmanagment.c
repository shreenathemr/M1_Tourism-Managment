// C program to implement
// the above approach

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Structure
typedef struct mynode {
	char name[20];
	char gen[6];
	int age;
	struct mynode* link;
} Node;
Node* start = NULL;

// Declaring Function Used
// In This Program
void heading();
void details();
void inter();
void india();
void receipt();

// Global variables
int k, amount;
char type[60], place[30], date[20];

// Driver Code
void main()
{
	int a;

	// Calling heading() function
	heading();

	// Taking Choice From User
	printf("\t\t\t\t1. International "
		"Tour Packages\n");
	printf("\t\t\t\t2. Domestic Tour Packages\n");
	printf("\t\t\t\tEnter Option: ");
	scanf("%d", &a);
	switch (a) {
	// Calling inter() function
	case 1:
		inter();
		break;

	// Calling domestic() function
	case 2:
		domestic();
		break;

	default:
		printf("Enter Right Option...");
		break;
	}

	// Calling details() function
	details();

	// Calling receipt() function
	receipt();
}

// Function To Take Package
// Choice From Domestic
void domestic()
{
	int a;

	// Clearing Screen
	system("cls");

	// Calling heading() function
	heading();
	strcpy(type, "Domestic Tour Package");
	printf("\t\t\t\t1. Chennai Tour Packages "
		"6 Days 7 Nights (18880/-)\n");
	printf("\t\t\t\t2. Delhi Tour Packages "
		"5 Days 4 Nights (35500/-)\n");
	printf("\t\t\t\t3. Mumbai Tour Packages "
		"11 Days 10 Nights (11000/-)\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &a);
	if (a == 1) {
		strcpy(place, "Chennai Tour");
		amount = 18880;
	}
	else if (a == 2) {
		strcpy(place, "Delhi Tour");
		amount = 35500;
	}
	else if (a == 3) {
		strcpy(place, "Mumbai Tour");
		amount = 11000;
	}
	else
		printf("Enter Correct Choice...");
}

// Function To Take Package Choice
// From International
void inter()
{
	int a;

	// Clearing Screen
	system("cls");

	// Calling heading() function
	heading();
	strcpy(type, "International Tour Package");
	printf("\t\t\t\t1. UK Tour Packages "
		"6 Days 7 Nights (28880/-)\n");
	printf("\t\t\t\t2. Honkong Tour Packages "
		"5 Days 4 Nights (15500/-)\n");
	printf("\t\t\t\t3. New York Tour Packages "
		"11 Days 10 Nights (600000/-)\n");
	printf("\t\t\t\tEnter Choice: ");
	scanf("%d", &a);
	if (a == 1) {
		strcpy(place, "UK Tour");
		amount = 28880;
	}
	else if (a == 2) {
		strcpy(place, "Honkong Tour");
		amount = 15500;
	}
	else if (a == 3) {
		strcpy(place, "New York Tour");
		amount = 600000;
	}
	else
		printf("Enter Correct Choice...");
}

// Function To Take Passenger Details
void details()
{
	int i, a;
	char val[20], gen[6];

	// Clearing Screen
	system("cls");

	// Calling heading() function
	heading();
	printf("\t\t\t\tEnter Number Of "
		"Passengers: ");
	scanf("%d", &k);
	printf("\t\t\t\tEnter Date "
		"(DD/MM/YY): ");
	fflush(stdin);
	gets(date);
	for (i = 1; i <= k; i++) {
		system("cls");
		heading();
		printf("\t\t\t\tEnter The %dth "
			"Passenger Name: ",
			i);
		fflush(stdin);
		gets(val);
		printf("\t\t\t\tEnter The %dth "
			" Passenger Gender: ",
			i);
		fflush(stdin);
		gets(gen);
		printf("\t\t\t\tEnter The %dth "
			"Passenger Age: ",
			i);
		fflush(stdin);
		scanf("%d", &a);

		// Calling add_node() function
		add_node(val, gen, a);
	}
}

// Function to add details in
// node for each passengers
void add_node(char lol[20],
			char der[6], int b)
{
	Node *newptr = NULL, *ptr;
	newptr = (Node*)malloc(sizeof(Node));
	strcpy(newptr->name, lol);
	strcpy(newptr->gen, der);
	newptr->age = b;
	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else {
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}

// Function For Printing Receipt
void receipt()
{
	int i, b;
	Node* ptr = start;
	system("cls");
	heading();
	printf("\n\t\t\t\t**Take Screenshots "
		"For Further Use**\n");
	for (i = 1; i <= k; i++) {
		printf("\t\t\t\t%dst Passenger "
			"Name: ",
			i);
		puts(ptr->name);
		printf("\t\t\t\t%dst Passenger "
			"Gender: ",
			i);
		puts(ptr->gen);
		printf("\t\t\t\t%dst Passenger "
			"Age: %d\n\n",
			i, ptr->age);
		ptr = ptr->link;
	}
	printf("\t\t\t\tSelected Type: ");
	puts(type);
	printf("\t\t\t\tPackage: ");
	puts(place);
	printf("\t\t\t\tDate: ");
	puts(date);
	b = amount * k;
	printf("\t\t\t\tTotal Fare: %d", b);
	printf("\n\t\t\t\t**Thank You For Your "
		"registration**");
}

// Function For Printing Heading
// Of Portal
void heading()
{
	printf("\t\t\t\t***Tourism Packages "
		"Management System***\n");
	printf("\t\t\t***Vaccination Certificates "
		"Is Necessary For Travel Purpose***\n\n");
}
