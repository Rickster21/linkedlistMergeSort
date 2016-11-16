#include <iostream>
#include <string>
using namespace std;

// YOLO!

struct Node{

		string info;
		Node* next;
};
void print();
void enque(string x);
void deque();
void mergSort(Node** Tophead);
void divide(Node* head, Node **front, Node **back);
void printRev(Node* head);
void insertX(Node** head , string x);
void print(Node* head);
void deleteNode(Node **head, string valueToRemove);
Node *front =NULL, *rear=NULL;
int main()
{
	string x = "xion", t = "tim", f = "fuck";
	/*Node* orignal = 0;
	int sizze;
	string x , deleteMe;
	cout << "How many numbers do you want to enter: ";
	cin  >> sizze;
	for (int i = 0; i < sizze; i++)
	{
		cout << "Enter some intergers: ";
		cin >> x;

		insertX(&orignal,  x);
	};

		
	//mergSort(&orignal);
	print(orignal);
	cout << endl << endl << endl ;
	cout << "Enter a number to delete:	";
	cin >> deleteMe;
	deleteNode(&orignal,deleteMe);
	printRev(orignal); */

	enque(x);
	enque(t);
	enque(f);
	cout << endl << endl;
	print(front);
	deque();

	print(front);
	
	
	deque();

	print(front);
		

	 










return 0;
};

void enque(string x)
{
	Node *temp = new Node;
	temp->info = x;
	temp->next=NULL;
	if (front == NULL && rear == NULL)
	{
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void deque()
{
	Node *temp = front;
	
	if (rear == NULL)
		{
			front = rear = NULL;
		}
	else
	{
	front = front->next;

	}
	delete temp;

}
void deleteNode(Node **head, string valueToRemove)
{
	Node *prev, *current;
	prev = NULL;
	current = *head;
	
	if (current->info == valueToRemove)
	{
		*head = current->next;
		delete current;

	}
	else
	{
		while (current != NULL)
		{
			prev = current;
			current = current->next;
			if (current->info == valueToRemove)
				break;
		}
	prev->next = current->next;
	delete current;
	}

	/*do {
		prev = current;
		current = current->next;

	} while (current->info != valueToRemove);*/


};

void print()
{
	Node * temp = front;
	while (temp != NULL)
	{
		cout << temp->info;
		temp = temp->next;

	}
}

void print( Node* head)
{	
	Node* current = head;

	while ( current!= NULL)
	{
		cout << current->info;
		current = current->next;
	    cout << " ";
	}
	
	cout << endl;


};

void printRev(Node* head)
{
	Node *prev= NULL, *current, *next;
	current = head;
	if (head == NULL)
	{
		head = current;

	}
	else
	{
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
		print(head);
	}



};

void insertX(Node** head , string x)
{

	Node* newNode = new Node;
	newNode->info = x;
	newNode->next = NULL;


	if (*head == NULL)
	{
		*head = newNode;			
	}
	else {

		Node *findEnd = *head;
		while (findEnd->next != NULL)
				{
					findEnd = findEnd->next;
				}

		findEnd->next = newNode;
		}
		
		 
}

	 /******************************************************/

int lengthofArr(struct Node *head)
{
	int len = 0;
	while (head !=  NULL)
	{

		len++;
		head = head->next;
	}
	return len;
}

void divide(Node*head, Node ** front, Node** back) /*<----- put theese in here for merge sort, Node* front, Node* back*/
{
	Node 	*fast = head->next;
	Node    *slow = head;

	if (head == NULL || head->next == NULL)
			{
		*front = head;
		*back = NULL;
			}
	

		while (fast != NULL)
		{
			fast = fast->next;

			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
			
		}


		*front = head;
		*back = slow->next;
		slow->next = NULL;
		
	}

 Node*  mergeArr(Node *leftArr, Node *rightArr2)
{
	Node *result = NULL;

	if (leftArr == NULL) 
		return rightArr2;
		
		
	else if(rightArr2 == NULL)
		
			return leftArr;
		

	if (leftArr->info <= rightArr2->info)
	{
		result = leftArr;

		result->next = mergeArr(leftArr->next, rightArr2);
			
	}
	else
	{

		result = rightArr2;
		result->next = mergeArr(leftArr, rightArr2->next);

	}
	return result;



}

void mergSort(Node **Tophead)
{
	Node * front, *back;
	Node * head = *Tophead;
	if (head == NULL || head->next == NULL)
		return;

	divide(head, &front, &back);
	mergSort(&front);
	mergSort(&back);
	*Tophead = mergeArr(front, back);
	
	
};
		// *front = head;		// *back = slow->next;

		/* Node* runner = head->next;

		 while (runner != null) {
			 runner = list->next
				 if (runner == runner->next)
					 break;
			 runner = runner->next;
			 list = list->next;
		 }
		 Node toReturn = list->next;
		 list->next = null;
		 return  toReturn;*/
		 
		 

//z

			

			




		 

