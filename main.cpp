#include <iostream>
#include <vector>
using namespace std;

int countDataSize = 0;

struct Node
{
  int data;
  struct Node *next;
};

void addSorted(struct Node** head, struct Node* newNode)
{
  struct Node* current = *head;

  if (current == nullptr)
  {
     newNode->next = newNode;
     *head = newNode;
  }

  else if (current->data >= newNode->data)
  {
    while(current->next != *head)
    {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = *head;
    *head = newNode;
  }

  else
  {
    while (current->next!= *head &&
           current->next->data < newNode->data)
    {
      current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
  }
}

void printMediana(struct Node *start)
{
  struct Node *temp;
  int incount = 0;
  int middle1 = 0;
  int middle2 = 0;
   bool even = (countDataSize % 2 == 0);
   countDataSize /=2;

  if(start != nullptr)
  {
    temp = start;
    printf("\n");
    do {

        ++incount;
      if(!even && incount == countDataSize +1)
      {
        cout<< "Mediana odd = " << temp->data << endl;
      }
      else if(even && incount == countDataSize)
      {
        middle1 = temp->data;
      }
      else if(even && incount == countDataSize + 1)
      {
        middle2 = temp->data;
        cout<< "Mediana even = " << (middle1 + middle2)/2 << endl;
      }

      temp = temp->next;

    } while(temp != start);
  }
}

int main()
{
  vector<int> arr = {250, 250, 150, 250, 150,
                     250,150, 250, 150, 300,
                     150, 300, 150, 300, 150,
                     600, 150,600, 150, 1250,1500};

  struct Node *start = nullptr;
  struct Node *temp;

  std::cout << "Please enter some integers (enter 0 to end):\n";
  //  do {
  //    std::cin >> i;

  //    temp = new Node();
  //    if(i > 0){
  //    temp->data = i;
  //    addSorted(&start, temp);
  //    countDataSize++;
  //    }
  //  } while (i);

  for (int i = 0; i< arr.size(); i++)
   {
     temp = new Node();
     temp->data = arr[i];
     addSorted(&start, temp);
   }

   countDataSize = arr.size();

   printMediana(start);

  return 0;
}
