#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct available
{
	char* plateNumber;
	int miles;
	struct available* next;
};

struct available* head = NULL;

void addList(char* plateNo, int mileage)
{
	struct available* temp = malloc(sizeof(struct available));
	struct available* current;


	temp->plateNumber = plateNo;
	temp->miles = mileage;
	temp->next = NULL;

	current = head;

	if (head == NULL)
	{
		temp->next = head;
		head = temp;
	}

	else {
	
		while (current->next != NULL)
		{
			current = current->next;

		}	

		if (current->next == NULL)
		{
			current->next = temp;
		}

		}
	}

void PrintList()
{
	struct available* temp;

	temp = head;

	while (temp != NULL)
	{
		printf("Platenumber: %s\n", temp->plateNumber);
		printf("Miles: %d\n", temp->miles);
		temp = temp->next;
	}

}

void removeList(char* plateNo, int mileage)
{
	struct available* current;
	struct available* temp2;
	struct available* temp = malloc(sizeof(struct available));

	temp->plateNumber = plateNo;
	temp->miles = mileage;

	current = head;



	while(current->next != NULL)
	{
		temp2 = current;

		if((strcmp(current->plateNumber,temp->plateNumber) == 0) && current->miles == temp->miles)
		{
			printf("MATCH FOUND\n");	
			temp2 = head;
			head = head->next;
			free(temp2);
			return;
		}


		else if ((current->plateNumber == plateNo) && (current->miles == mileage))
		{
			printf("MATCH FOUND 2\n");
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
printf("NO CAR EXISTS: \n");

}


int main()
{
	char* plateNo = NULL;
	int mileage;
	int numInput = 0;
	int i = 0;


	printf("Please enter the amount of inputs: \n");
	scanf("%d", &numInput);

	for (i = 0; i<numInput; ++i)
	{
		plateNo = malloc(15);
		printf("Please enter the plate number: \n");
		scanf("%s", plateNo);
		printf("Please enter the mileage: \n");
		scanf("%d", &mileage);
		addList(plateNo, mileage);
	}

	PrintList();

	printf("Please enter the plate number you want to remove: \n");
	scanf("%s", plateNo);
	printf("Please enter the mileage: \n");
	scanf("%d", &mileage);

	removeList(plateNo, mileage);

	PrintList();

}

