

#include <bits/stdc++.h>

using namespace std;


bool checksum(int A[], int size, int x) {
for (int i = 0; i < (size - 1); i++) {
	for (int j = (i + 1); j < size; j++) {
	if (A[i] + A[j] == x) {

		return 1;
	}
	}
}

return 0;
}

int main() {
int size;
cin>>size;
int A[size];
if((size>=1)&&(size<=100)){

for(int i=0;i<size;i++){
    cin>>A[i];
}

int x;
cout<<"Target value ?"<<endl;
cin>>x;

if (checksum(A, size, x)) {
	cout << "Possible" << endl;
} else {
	cout << "Not Possible " << endl;
}
}
return 0;
}

//size =5,A={1,2,3,4,5},target value=8,output=Possible.


