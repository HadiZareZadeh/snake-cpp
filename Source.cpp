#include <iostream>

using namespace std;

int main(){
    int i,j,b,a,c;
    cout<<"Enter length: ";
    cin >>a;
    c=a;
    for(i=0;i<a;i++){
        b=i+i+1;
		for(int k=c-1;k>0;k--)
			cout << " ";
		c--;
		cout <<"*";
        for(j=b-1;j>0;j--)
            cout << " ";
		cout<<"*";
        cout << endl;
    }

	c=1;
	for(i=a-2;i>=0;i--){
		b=i+i+1;
		for (int k=0;k<c;k++)
			cout <<" ";
		c++;
		cout<<"*";
		for(j=0;j<b-1;j++)
			cout <<" ";
		cout<<"*";
		cout <<endl;
	}

	cin >> a;
	return 0;
}
