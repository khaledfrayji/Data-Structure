#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50

// defining hashtable to be an array of length MAX_SIZE
typedef int HashTable[MAX_SIZE];

// Initialize all elements of the hashtable to -1.
void CreateHashTable(HashTable table)
{
  for (int i = 0; i < MAX_SIZE; i++)
    table[i] = -1;
}

// returns a hash value, you can implement whatever hash function you like,
// I find this an easy efficient one
unsigned int hash(int X)
{
  return (X % 37) % MAX_SIZE;
}
// returns 1 if the element is found else 0
int search(HashTable table, int data)
{
  int hashValue = hash(data);
  int index = hashValue;
  if (index < 0)
    index += MAX_SIZE;
  do
  {
    if (table[index] == data)
      return 1;

    index = (index + 1) % MAX_SIZE;
  } while (index != hashValue);

  return 0;
}
// add the element according the hash value,
// In case of a duplicate, we return 1 as if insertion works but we don't actually insert the element
int insert(HashTable table, int data)
{
  int hashValue = hash(data);
  int index = hashValue;
  if (index < 0)
    index += MAX_SIZE;
  if (search(table, data))
    return 0;
  while (table[index] != -1)
  {
    if (table[index] == data)
      return 0;

    index = (index + 1) % MAX_SIZE; // this means that there is a collision
    if (index == hashValue)
    {
      printf("Hash table is full. Cannot insert data.\n");
      return 0;
    }
  }

  table[index] = data;

  return 1;
}

// deletes an element if found in table
int delete(HashTable table, int data)
{
  int hashValue = hash(data);
  int index = hashValue;
  if (index < 0)
    index += MAX_SIZE;
  do
  {
    if (table[index] == data)
    {
      table[index] = -1;
      return 1;
    }

    index = (index + 1) % MAX_SIZE;
  } while (index != hashValue);

  return 0;
}

// !!!!!!!!!!!
// in all above functions we use
// Linear Probing (index+1%MAX_SIZE) in case of collisions.
// collision happen when 2 elements have the same hashcode, so the same index in the table
// when this happens we use linear probing when inserting, searching or deleting

void printHashTable(HashTable table)
{
  printf("Hash Table Contents:\n");
  printf("--------------------\n");
  for (int i = 0; i < MAX_SIZE; i++)
    if (table[i] != -1)
      printf("Key: %d, Data: %d\n", i, table[i]);
  printf("--------------------\n");
}


int unique(int arr[],int size){
    HashTable h;
    CreateHashTable(h);
    for(int i=0;i<size;i++){
        if(!search(h,arr[i])) {
    printf("%d ",arr[i]);
    insert(h,arr[i]);
        }
    }
}
void outOfRange(int *a,int N,int low,int high){
    HashTable h;
    CreateHashTable(h);
    for(int i=0;i<N;i++){
        insert(h,a[i]);
    }
    for(int i=low;i<=high;i++){
        if(!search(h,i));
        printf("\n%d",i);
    }
}
int product(int *arr,int N,int x){
    HashTable(h);
    CreateHashTable(h);
    for(int i=0;i<N;i++){
      if(arr[i]==0 && x==0 )
     return 1;

      if(x%arr[i]==0 && search(h,x/arr[i])) return 1;
      insert(h,arr[i]);
    }
    return 0;
}
int sum(int *arr,int N,int x){
    HashTable h;
    CreateHashTable(h);
    
    for(int i=0;i<N;i++){
       if(h[x-arr[i]])
       printf("%d %d ",arr[i],x-arr[i]);
       insert(h,arr[i]);
    }
  
}

int main(){
    int arr[]={1,2,3,4,4,5,6};
   outOfRange(arr,10,7,13);
   printf("%d ",product(arr,10,81));
}