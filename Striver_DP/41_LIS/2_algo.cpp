#include <bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> lis(n, 1);

    for (int i = 1; i < n; i++)
    {
        cout<<i<<"--> ";
        for (int j = 0; j < i; j++)
        {
            cout<<(arr[j] & arr[i]) * 2 <<" " << (arr[j] | arr[i])<<" - ";
            if ((((arr[j] & arr[i]) * 2) < (arr[j] | arr[i])) && lis[i] <= lis[j] )
            {
                lis[i] = 1 + lis[j];
            }
        }
        cout<<endl;
    }

    int mx = 1;
    for (int i = 0; i < n; i++){
        mx = max(mx, lis[i]);
        cout<<lis[i]<<" " ;

    }

    cout<<endl;
    return mx;


}

int main()
{

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)cin>>arr[i];

    int ans = lengthOfLIS(arr);

    cout<<ans<<endl;

    return 0;
}


   
    
