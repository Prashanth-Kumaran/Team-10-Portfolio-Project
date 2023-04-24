
//Importing Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Function Prototypes
int InitialList(char[][20], int[]);
int PrintList(char[][20], int[]);
void RatingContext();
void ViewRating(char[][20], int[], int);
void ChangeRating(char[][20], int[], int);
void AddLocation(char[][20], int[], int);

//Main Function
int main(){
	
	//Declaring Variables
	char names[106][20];
	int ratings [106];
	int choice;
	int length;
	//Looping
	char cont = 'y';
	
	//Introduction 
	printf("Welcome to the Single-Use Disposable Database. This app rates dining locations across Oakland on how much single use \ndisposable waste they produce.\n");
	printf("Here is a list of the current locations in our database:\n"); 
	length = InitialList(names, ratings);
	
	do{
		//List of Features
		printf("\nIf you would like to view the rating of a dining location, press (1).\n");
		printf("If you would like to change the rating of an existing location, press (2).\n");
		printf("If you would like to add a new location, press (3).\n");
		
		
		//Choosing between features
		printf("Input your choice here: ");
		scanf("%d", &choice);
		printf("\n");
		//Error checking menu input
		while(choice < 1 || choice > 3){
			printf("Please input a valid choice: ");
			scanf("%d", &choice);
			printf("\n");
		}
		
		switch(choice){
			//Feature 1: Veiwing the Rating of a Dining Location
			case 1:
				printf("You have chosen to view the rating for a dining location.\n");
				RatingContext();
				printf("\n\nOnce again, here is a list of dining locations you can chose from: \n");
				length = PrintList(names, ratings);
				ViewRating(names, ratings, length);
			break;
			
			//Feature 2: Changing the rating of an existing Dining Location
			case 2:
				printf("You have chosen to change the rating of an existing dining location.\n");
				ChangeRating(names, ratings, length);
			break;
			//Feature 3: Adding a new location to the database
			case 3:
				printf("You have chosen to add a new dining location to the database.\n");
				AddLocation(names, ratings, length);
				length++;
				
				
			break;
		}
		//Looping
		printf("Would you like to view another location or update our database? (y/n)?\n");
		scanf(" %c", &cont);
		//Error check looping input
		while(cont !='y' && cont !='n'){
			printf("Please enter either y to continue, or n to end the program.\n");
			scanf(" %c", &cont);
		}
	}while(cont == 'y');

	printf("Thank you for using the Single-Use Disposable Database, we hope you are able to use this information to dine at \nenviornmentally sustainable establishments.\n");
	printf("Enjoy your meal!");
	
	
	
	
	return 0;
	
}

//Creates an inital database of locations and returns the number of locations
int InitialList(char names[][20], int ratings[]){
	//Resets the array
	int length;
	for(int i = 0; i < 106; i++){
		ratings[i] = 0;
	}
	strcpy(names[0], "The Eatery");
	ratings[0] = 1;
	
	strcpy(names[1], "The Perch");
	ratings[1] = 5;
	
	strcpy(names[2], "Stack\'d Oakland");
	ratings[2] = 4;
	
	strcpy(names[3], "The Porch");
	ratings[3] = 4;
	
	length = PrintList(names,ratings);
	return length;
}

//Prints the list of locations and returns the number of locations
int PrintList(char names[][20], int ratings[]){
	int i = 0;
	while(ratings[i] != 0){
		printf("%d. %s\n", i+1, names[i]);
		i++;
	}
	return i;
}

//Prints out the description of each rating
void RatingContext(){
	printf("Dining locations are rated on a scale of 1-5.\n");
	printf("Here are the criteria for each rating:\n");
	printf("1: This location exclusively relies on single use disposable utensils, plates, and packaging.\n");
	printf("2: This location serves food that does not usually require utensils, but still uses disposable packaging.\n");
	printf("3: This location uses compostable/eco-friendly disposable utensils, and uses minimal packaging.\n");
	printf("4: This location has a majority of menu items where single use disposables can be completly avoided.\n");
	printf("5: This location is completely avoids single use disposables.\n");
}

//Asks the user for which location they want to view, then displays the rating and sustainability tips based on the rating
void ViewRating(char names[][20], int ratings[], int length){
	int input;
	int choice;
	do{
		printf("Input the number of the dining location you want to view: ");
		scanf("%d", &input);
		printf("\n");
		choice = input - 1;
		if(choice < 0 || input > length){
			printf("That location does not exist. Please input a valid number.\n");
		}
	}while(choice < 0 || input > length);
	

	
	printf("The rating of %s is %d.\n", names[choice], ratings[choice]);
	
	switch(ratings[choice]){
		case 1:
		case 2:
			printf("If you are planning on dining at this location, please bring our own utensils to minimize the waste you produce.\n");
		break;
		case 3:
		case 4:
			printf("For this location, try and order items that do not use utensils, or bring your own resuable utensils.\n");
		break;
		case 5:
			printf("This location is already committed to reducing plastic waste, there is no need to bring your own utensils :^).\n");
		break;
	}
	
}

//Asks the user for a location, then asks the user for a new rating
void ChangeRating(char names[][20], int ratings[], int length){
	int input;
	int choice;
	int newRating;
	do{
		printf("Input the number of the dining location you want to change: ");
		scanf("%d", &input);
		printf("\n");
		choice = input - 1;
		if(choice < 0 || input > length){
			printf("That location does not exist. Please input a valid number.\n");
		}
	}while(choice < 0 || input > length);
	
	RatingContext();
	printf("Please enter your new rating for the location based on your most recent experience: ");
	scanf("%d", &newRating);
	printf("\n");
	while(newRating < 1 || newRating > 5){
		printf("Please enter a valid rating: \n");
		scanf("%d", &newRating);
		printf("\n");
	}
	ratings[choice] = newRating;
	printf("The location %s now has a rating of %d.\n", names[choice], ratings[choice]);
	
}

//Asks the user for a location name and rating, then adds it to the end of the list.
void AddLocation(char names[][20], int ratings[], int length){
	printf("Enter the name of the dining location you want to add: \n");
	//Scans strings with spaces
	scanf(" %[^\n]s", names[length]);
	printf("\n");
	RatingContext();
	printf("Based on the criteria, enter the rating of your dining location: \n");
	scanf("%d", &ratings[length]);
	printf("\n");
	while(ratings[length] < 1 || ratings[length] > 5){
		printf("Please enter a valid rating: \n");
		scanf("%d", &ratings[length]);
		printf("\n");
	}
	printf("The location %s has been added with a rating of %d\n", names[length], ratings[length]);
	printf("Here is the new list of locations\n");
	PrintList(names, ratings);
	
}
