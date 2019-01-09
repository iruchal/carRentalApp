#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100


struct available
{
	char* plateNumber;
	int miles;
	int returnDate;
	struct available* next;

};


struct available* head = NULL;

struct rented
{
	char* plateNumber;
	int miles;
	int returnDate;
	struct rented* next;

};

struct rented* rentHead = NULL;

struct repair
{
	char* plateNumber;
	int miles;
	int returnDate;
	struct repair* next;

};

struct repair* repairHead = NULL;

int token = 0;
int totalRev = 0;

void LoadRented();
void LoadAvailable();
void LoadRepair();
void PrintRented();
void PrintAvailable();
void PrintRepair();
void rentedToAvail(char* plateNo, int mileage);
void rentedToRepair(char* plateNo, int mileage);
void repairToAvail(char* plateNo);
void rentFirstAvailable(int returnDate);
void addNewCar(char* plateNo, int mileage);
void addRented(char* plateNo, int mileage, int dateOfReturn);
void addRepair(char* plateNo, int mileage);
void PrintAll();
void calculateRev(int mileage);

int main()
{

	int userDecision = 0;
	int resume = 1;
	char* plateNo = malloc(25);
	int mileage = 0;
	int dateOfReturn = 0;



	while(resume != 0)
	{
	printf("Here are the transactions available\n");

	printf("1. add a new car to the available-for-rent list\n");
	printf("2. add a returned car to the available-for-rent list\n");
	printf("3. add a returned car to the repair list\n");
	printf("4. transfer a car from the repair list to the available-for-rent list \n");
	printf("5. rent the first available car\n");
	printf("6. print all the lists\n");
	printf("7. quit\n");
	printf("Please enter the desired transaction.\n");

	scanf("%d", &userDecision);


	if (userDecision < 1 && userDecision > 7)
	{
		while(userDecision >= 1 && userDecision <= 7)
			printf("Please enter a transaction between 1 and 7\n");
	}
	if (userDecision == 1 || userDecision == 2 || userDecision == 3)
	{
		printf("Please enter the plate number:  \n");
		scanf("%s", plateNo);
		printf("Please enter the mileage:  \n");
		scanf("%d", &mileage);

	}

		if (userDecision == 1)
		{
		addNewCar(plateNo, mileage);
		calculateRev(mileage);
		printf("The car with the plate number %s and mileage of %d has been added to the Available linked list. \n", plateNo, mileage);

		

		}	

	if (userDecision == 2)
		{
		rentedToAvail(plateNo, mileage);
		printf("The car with the plate number %s and mileage of %d has been moved from the Rented linked list to the Available linked list. \n", plateNo, mileage);
		calculateRev(mileage);
		}

	if (userDecision == 3)
	{
		rentedToRepair(plateNo, mileage);
		calculateRev(mileage);
		printf("The car with the plate number %s and mileage of %d has been moved from the Rented linked list to the Repair linked list. \n", plateNo, mileage);
	}

	if (userDecision == 4)
	{
		printf("Please enter the plate number:  \n");
		scanf("%s", plateNo);
		repairToAvail(plateNo);
		printf("The car with the plate number %s and mileage of %d has been moved from the repair linked list to the Available linked list. \n", plateNo, mileage);
	}

	if (userDecision == 5)
	{

		printf("Please enter the expected return date in yymmdd format:  \n");
		scanf("%d", &dateOfReturn);
		rentFirstAvailable(dateOfReturn);
		printf("The car with the plate number %s and mileage of %d has been moved from the repair linked list to the Available linked list. \n", plateNo, mileage);
		

	}

	if (userDecision == 6)
	{
		while(token == 0)
		{
		PrintAll();
		printf("\n\n");
		LoadRented();
		LoadAvailable();
		LoadRepair();
		token = token + 1;
		}

		
		
		PrintAvailable();
		printf("------------------\n");
		printf("\n\n");
		PrintRented();
		printf("------------------\n");
		printf("\n\n");
		PrintRepair();
		printf("------------------\n");
	}


	if (userDecision == 7)
	{

	
	}


	
	printf("Would you like to perform another transaction? Enter any number for YES and 0 for NO\n");
	scanf("%d", &resume);
	}


	}


	void calculateRev(int mileage)
	{
		int extra = 0;
		int charge = 0;

		if (mileage <= 100)
		{
			printf("The fee for this transaction was $40.\n");

			charge = 40;
			totalRev = charge;
		}

		else if(mileage > 100)
		{
			extra = mileage - 100;
			charge = extra * 0.15;
			charge = 40 + charge;
			printf("The fee for this transaction was %d.\n", charge);
			totalRev = charge;

		}
	}



void addNewCar(char* plateNo, int mileage)
{
	struct available* temp = (struct available*)(malloc(sizeof(struct available))); 
	struct available* current;
	struct available* temp2;

	temp->plateNumber = malloc(25);
	strcpy(temp->plateNumber,plateNo);
	temp->miles = mileage;
	temp->next = NULL;


	if (head == NULL || temp->miles < head->miles)
	{
		temp->next = head;
		head = temp;
		
	}

	else
	{

		current = head;

		while (current->next != NULL && current->miles < temp->miles)
		{
			temp2 = current;
			current = current->next;
		}

		if (current->miles >= temp->miles)
		{
			temp2->next = temp;
			temp->next = current;
			
		}

		else if (current->next == NULL)
		{
			current->next = temp;
		}


	}

} 


void addRented(char* plateNo, int mileage, int dateReturn)
{
	struct rented* temp = (struct rented*)(malloc(sizeof(struct rented))); 
	struct rented* current;
	struct rented* temp2;


	temp->plateNumber = plateNo;
	temp->miles = mileage;
	temp->returnDate = dateReturn;
	temp->next = NULL;


	
	if (rentHead == NULL || temp->returnDate < rentHead->returnDate)
	{
		temp->next = rentHead;
		rentHead = temp;
		
	}

	else
	{

		current = rentHead;

		while (current->next != NULL && current->returnDate < temp->returnDate)
		{
			temp2 = current;
			current = current->next;
		}

		if (current->returnDate > temp->returnDate)
		{
			temp2->next = temp;
			temp->next = current;
			
		}

		else if (current->next == NULL)
		{
			current->next = temp;
		}


		}

}


void addRepair(char* plateNo, int mileage)
{
	struct repair* temp = (struct repair*)(malloc(sizeof(struct repair))); 
	struct repair* current;
	struct repair* temp2;


	temp->plateNumber = plateNo;
	temp->miles = mileage;
	temp->returnDate = 0;
	temp->next = NULL;

	if (repairHead == NULL)
	{
		temp->next = repairHead;
		repairHead = temp;
		
	}

	else
	{

		current = repairHead;

		while (current->next != NULL)
		{
			temp2 = current;
			current = current->next;
		}

		if (current->next == NULL)
		{
			current->next = temp;
		}

}

}


void rentedToAvail(char* plateNo, int mileage)
{
	struct rented* current;
	struct rented* temp = malloc(sizeof(struct rented));
	struct rented* temp2;

	temp->plateNumber = malloc(strlen(plateNo)+1);
	strcpy(temp->plateNumber, plateNo);
	temp->miles = mileage;

	current = rentHead;


	if((strcmp(rentHead->plateNumber,temp->plateNumber) == 0) && rentHead->miles == temp->miles)
		{
		
			addNewCar(rentHead->plateNumber, rentHead->miles);
			temp2 = rentHead;
			rentHead = rentHead->next;
			free(temp2);
			return;
		}
 


	while(current->next != NULL || ((current->next == NULL && (strcmp(current->plateNumber,temp->plateNumber) == 0) && (current->miles == temp->miles))))
	{
		if ((strcmp(current->plateNumber,temp->plateNumber) == 0) && (current->miles == temp->miles))
		{
			
			addNewCar(current->plateNumber, current->miles);
			struct rented* toBeDelete = current;
			temp2->next = current->next;

			current = current->next;

			// printf("CAR FOUND\n");
			// printf("%s\n", current->plateNumber);
			// printf("%d\n", current->miles);
		
			free(toBeDelete);
			return;
		}

		else
		{
			temp2 = current;
			current = current->next;
		}
	}


/*
	while(current != NULL && strcmp(current->plateNumber, plateNo) != 0) {
		temp2 =  current;
		current = current->next;

	}
	if(current == NULL) {
		printf("Car cant be found");
		return;
	}

	addNewCar(current->plateNumber, current->miles);

	temp2->next = current->next;
	free(current);
*/

	//printf("There is no such car. \n");


}


void rentedToRepair(char* plateNo, int mileage)
{
	struct rented* current;
	struct rented* temp = malloc(sizeof(struct rented));
	struct rented* temp2;

	temp->plateNumber = malloc(strlen(plateNo)+1);
	strcpy(temp->plateNumber, plateNo);
	temp->miles = mileage;

	current = rentHead;


	if((strcmp(rentHead->plateNumber,temp->plateNumber) == 0) && rentHead->miles == temp->miles)
		{
		
			addRepair(rentHead->plateNumber, rentHead->miles);
			temp2 = rentHead;
			rentHead = rentHead->next;
			free(temp2);
			return;
		}



	while(current->next != NULL || ((current->next == NULL && (strcmp(current->plateNumber,temp->plateNumber) == 0) && (current->miles == temp->miles))))
	{
		if ((strcmp(current->plateNumber,temp->plateNumber) == 0) && (current->miles == temp->miles))
		{
			
			addRepair(current->plateNumber, current->miles);
			struct rented* toBeDelete = current;
			temp2->next = current->next;
			current = current->next;
			free(toBeDelete);
			return;
		}

		else
		{
			temp2 = current;
			current = current->next;
		}
	}
}



void repairToAvail(char* plateNo)
{
	struct repair* current;
	struct repair* temp = malloc(sizeof(struct repair));
	struct repair* temp2;

	temp->plateNumber = malloc(strlen(plateNo)+1);
	strcpy(temp->plateNumber, plateNo);


	current = repairHead;


	if((strcmp(repairHead->plateNumber,temp->plateNumber) == 0))
		{	
			addNewCar(repairHead->plateNumber, repairHead->miles);
			temp2 = repairHead;
			repairHead = repairHead->next;
			free(temp2);
			return;
		}



	while(current->next != NULL || ((current->next == NULL && (strcmp(current->plateNumber,temp->plateNumber) == 0) && (current->miles == temp->miles))))
	{
		if ((strcmp(current->plateNumber,plateNo) == 0))
		{	
			addNewCar(current->plateNumber, current->miles);
			temp2->next = current->next;
			current->next = NULL;
		
			free(current);
			return;
		}

		else
		{
			temp2 = current;
			current = current->next;
		}
	}




}


void rentFirstAvailable(int returnDate)
{
	struct available* current;
	struct available* temp;

		current = head;
		current->returnDate = returnDate;
		addRented(current->plateNumber, current->miles, current->returnDate);
		temp = current;
		current = current->next;
		head = current;
		free(temp);
}


void PrintAvailable()
{
	struct available* temp; 	
	temp = head;
	printf("CONTENTS OF AVAILABLE FOR RENT LINKED LIST:\n\n");
	while(temp->next != NULL) 
	{

		printf("Plate Number: %s \n", temp->plateNumber);
		printf("Mileage: %d \n", temp->miles);
		printf("\n");
		temp = temp->next;
	}

	printf("Plate Number: %s \n", temp->plateNumber);
	printf("Mileage: %d \n", temp->miles);
}

void PrintRented()
{
	struct rented* temp; 	
	temp = rentHead;

	printf("CONTENTS OF RENTED LINKED LIST:\n\n");
	while(temp->next != NULL) 
	{
		printf("Plate Number:%s \n", temp->plateNumber);
		printf("Mileage: %d \n", temp->miles);
		printf("Return Date: %d \n", temp->returnDate);
		printf("\n");
		temp = temp->next;
	}

		printf("Plate Number:%s \n", temp->plateNumber);
		printf("Mileage: %d \n", temp->miles);
		printf("Return Date: %d \n", temp->returnDate);
}

void PrintRepair()
{
	struct repair* temp; 	
	temp = repairHead;

	printf("CONTENTS OF REPAIR LINKED LIST:\n\n");
	while(temp->next != NULL) 
	{
		printf("Plate Number: %s \n", temp->plateNumber);
		printf("Mileage: %d \n", temp->miles);
		printf("\n");
		temp = temp->next;
	}

	printf("Plate Number: %s\n", temp->plateNumber);
	printf("Mileage: %d \n", temp->miles);

}



void PrintAll()
{

	FILE* fp;
	FILE* fpTwo;
	FILE* fpThree;

	fp = fopen("AFR.txt", "r");
	char* line = malloc(LENGTH);

	if(fp!= NULL)
	{
		printf("Contents of AFR.txt\n");
		while(fgets(line, LENGTH, fp))
		{
			printf("%s", line);
		}
		printf("\n");
	}

	fclose(fp);

	printf("\n\n");
	
	fpTwo = fopen("rented.txt", "r");
	line = malloc(LENGTH);

	if(fpTwo!= NULL)
	{
		printf("Contents of rented.txt\n");
		while(fgets(line, LENGTH, fpTwo))
		{
			printf("%s", line);
		}
		printf("\n");
	}

	fclose(fpTwo);	

	printf("\n\n");

	fpThree = fopen("repair.txt", "r");
	line = malloc(LENGTH);

	if(fpTwo!= NULL)
	{
		printf("Contents of repair.txt\n");
		while(fgets(line, LENGTH, fpThree))
		{
			printf("%s", line);
		}
		printf("\n");
	}

	fclose(fpThree);	

	
}
		

void LoadAvailable()
{
	FILE* fp;
	fp = fopen("AFR.txt", "r");

	int mileage = 0;

	while(!feof(fp))
	{
		char* plateNo = malloc(8);
		fscanf(fp,"%s %d\n", plateNo, &mileage);
		addNewCar(plateNo, mileage);

	}

	fclose(fp);
}

void LoadRented()
{
	FILE* fp;
	fp = fopen("rented.txt", "r");

	int mileage = 0;
	int returnDate = 0;

	while(!feof(fp))
	{
		char* plateNo = malloc(8);
		fscanf(fp,"%s %d %d\n", plateNo, &mileage, &returnDate);
		addRented(plateNo, mileage,returnDate);

	}
	
	fclose(fp);
}

void LoadRepair()
{
	FILE* fp;
	fp = fopen("repair.txt", "r");

	int mileage = 0;
	

	while(!feof(fp))
	{
		char* plateNo = malloc(8);
		fscanf(fp,"%s %d \n", plateNo, &mileage);
		addRepair(plateNo, mileage);

	}
	
	

	fclose(fp);
}



