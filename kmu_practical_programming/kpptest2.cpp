#include <iostream>
#include <vector>
using namespace std;

long long mergeSort(vector<int>& arr, int left, int right, vector<int>& temp)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = (left + right) / 2;
    long long inv_count = 0;
    inv_count += mergeSort(arr, left, mid, temp);
    inv_count += mergeSort(arr, mid + 1, right, temp);

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int l = left; l <= right; l++)
    {
        arr[l] = temp[l];
    }

    return inv_count;
}

int main()
{
    int test_case;
    cin >> test_case;

    for (int t = 0; t < test_case; t++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> temp(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long result = mergeSort(arr, 0, n - 1, temp);
        cout << result << endl;
    }

    return 0;
}
