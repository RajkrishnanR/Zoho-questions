
#include <bits/stdc++.h>
using namespace std;

void sortByHeight(int a[], int n)
{

	
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (a[i] >=0)
			ans.push_back(a[i]);
	}

	
	sort(ans.begin(), ans.end());

	int j = 0;
	for (int i = 0; i < n; i++) {

		
		if (a[i] >= 0) {
			a[i] = ans[j];
			j++;
		}
	}

	
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}


int main()
{
    int length;
    cin>>length;
    int a[length];
    if((length>=5)&&(length<=15)){
	for(int i=0;i<length;i++){
	    cin>>a[i];
	}

	int n = sizeof(a) / sizeof(a[0]);

	sortByHeight(a, n);
    }

	return 0;
}

//length=5,a[]={6,-1,3,-1,5},output a[]={3,-1,5,-1,6}

