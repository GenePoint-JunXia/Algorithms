#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Print(int *arr,int size)
{
	printf("Arr : ");
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
/*Alg_01 */
void sort_INSERT(int* arr,int size);
/*Alg_02 */
void sort_SELECTION(int* arr,int size);
/*Alg_03 */
void sort_BUBBLE(int* arr,int size);

int main(int argc,char* argv[])
{
	if(argc!=2){
		printf("usage:./a.out <int>index\n");
		return 0;
	}
	int arr[10]={4,3,7,8,2,0,9,6,1,5};

	int index=atoi(argv[1]);
	switch(index){
		case 1:sort_INSERT(arr,10);break;
		case 2:sort_SELECTION(arr,10);break;
		case 3:sort_BUBBLE(arr,10);break;
		
		default:printf("wrong input!\n");break;
	}	
	return 0;
}

void sort_INSERT(int* arr,int size){
	printf("sort by INSERT method.\n");
	Print(arr,size);
	
	for(int i=1;i<size;i++){
		int j=i-1;
		int key=arr[i];
		while(j>=0 && arr[j]>key){

			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
	
	Print(arr,size);
}

void sort_SELECTION(int* arr,int size){
	printf("sort by SELECTION method.\n");
	Print(arr,size);

	for(int i=0;i<size;i++){
		int min=arr[i];
		int k=i;
		for(int j=i;j<size;j++){
			if(arr[j]<min){
				min=arr[j];
				k=j;
			}
		}
		int tmp=arr[i];
		arr[i]=min;
		arr[k]=tmp;
	}
	
	Print(arr,size);	
}

void sort_BUBBLE(int* arr,int size){
	printf("sort by BUBBLE.\n");
	Print(arr,size);
	
	int exch=0;
	for(int i=0;i<size;i++){	//冒泡排序每次会排出一个最值，这样最多循环size次，就能完成排序;
		for(int j=0;j<size-1;j++){
			if(arr[j]>arr[j+1]){
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				
				exch++;
			}
		}
		if(exch==0)
			break;
		else
			exch=0;
	}
	
	Print(arr,size);
}
