#include<iostream>
using namespace std;

#define m 9973
int tmp[10][10];

int main()
{
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		int i,j,l;
		int a[10][10];
		int sum=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		int ans[10][10];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				ans[i][j]=0;
				if(i==j)ans[i][j]=1;
			}
		}
		while(k!=0){
			if(k%2==1){

				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						tmp[i][j]=0;
					}
				}

				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						for(l=0;l<n;l++){
							tmp[i][j]+=ans[i][l]*a[l][j];
						}
					}
				}

				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						ans[i][j]=tmp[i][j]%m;
					}
				}


			}

			k/=2;

			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					tmp[i][j]=0;
				}
			}
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					for(l=0;l<n;l++){
						tmp[i][j]+=a[i][l]*a[l][j];
					}
				}
			}

			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					a[i][j]=tmp[i][j]%m;
				}
			}

		}
		for(i=0;i<n;i++){
			sum=sum+ans[i][i]%m;
		}
		cout<<sum%m<<endl;
	}
	return 0;
}
