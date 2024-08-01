#include <stdio.h>
int largest(int arr[], int n)
{
	int i;
	int max = arr[0];
	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
int main()
{
    int n,arr[100];
	printf("enter a number: ");
    scanf("%d",&n);
	printf("Enter  integers: ");
	for (int i = 0; i < n; ++i) {
    	scanf("%d", &arr[i]);
	}
	printf("Largest in given array is %d", largest(arr, n));
	return 0;
}

