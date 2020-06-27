#include <iostream>
#include <vector>
#include <minmax.h>
#include <algorithm>

//bad solution
/*
This solution assumes the array is ordered and therefore the lowest value is at the start and the biggest value is at the end. Using 2 loops could also slow ya down in the real world. 
*/
#if 0
void minMaxSum(std::vector<unsigned long int> arr)
{
    unsigned long int maxSum = 0, minSum = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        //add all elements together - last element
        minSum += arr[i];

        
    }
    for (int j = n - 1; j > 0; j--)
    {
        //add all elements together - first element
        maxSum += arr[j];
    }
    
    std::cout << minSum << " " << maxSum << std::endl;
}
#endif

//better solution
/*
Using only one loop, all values for min and max are calculated. This solution uses the standard c++ library, minmax.h, to calculate in each iteration of the loop the min and max values.
In the print out the total value is taken off of the min and max correcting the values?
*/
#if 0
void minMaxSum(std::vector<unsigned long int> arr)
{
    unsigned long int minSum = ULONG_MAX;
    unsigned long int maxSum = 0;
    unsigned long int allSum = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        allSum += arr[i];
        minSum = min(minSum, arr[i]);
        maxSum = max(maxSum, arr[i]);
    }

    std::cout << allSum - maxSum << " " << allSum - minSum << std::endl;
}
#endif

//my favourite solution
/*
Using the sort function from the algorithm library, the list is sorted from smallest int first to largest int last. 
This ensures when the calculations for min and max are done that the list is ordered, reducing the need for those calculations to be done during the loop.
*/
#if 1
void minMaxSum(std::vector<unsigned long int> arr)
{
    unsigned long int minSum = ULONG_MAX;
    unsigned long int maxSum = 0;
    unsigned long int allSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        allSum += arr[i];
    }
    std::sort(arr.begin(), arr.end());
    minSum = allSum - arr[arr.size() - 1];
    maxSum = allSum - arr[0];

    std::cout << minSum << " " << maxSum << std::endl;

}
#endif
int main() {
	std::vector<unsigned long int> arr = { 260, 10, 50, 341, 505 };

	minMaxSum(arr);


	return 0;
}