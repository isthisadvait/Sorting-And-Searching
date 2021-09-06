/*Merge Sort Algorithm Author -Raman Mehta */
#include <bits/stdc++.h>
#define endl  "\n"
#define pb push_back
#define ll long long
#define FIO  ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

//merging sorted array
void merge(vector<int>&Arr, int start, int mid, int end) {
	// create a temp array
	int temp[end - start + 1];
	

	// crawlers for both intervals and for temp
	int i = start, j = mid+1, k = 0;

	// traverse both arrays and in each iteration add smaller of both elements in temp 
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			ans+=(mid-i+1);
			k += 1; j += 1;
		}
	}

	// add elements left in the first interval 
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}

	// add elements left in the second interval 
	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}

	// copy temp to original interval
	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}

// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr

void mergeSort(vector<int>&Arr, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}

int main() {
    FIO
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        ans=0;
        for(int i=0;i<n;i++) cin>>v[i];
        mergeSort(v,0,n-1);
       // for(int x:v) cout<<x<<" ";
        
        cout<<ans<<endl;
        
        
    }
	
	return 0;
}
