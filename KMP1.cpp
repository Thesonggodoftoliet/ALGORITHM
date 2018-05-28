//KMP算法求串匹配问题
/*******           -1    // j=0   *******/
/*******next[j]=   max{k|1<=k<j且T[0]...T[k-1]=T[j-k]...T[j-1]}  集合非空 *** */
/*******           0    //  其他情况    ****/

#include <iostream>
#include <string>
using namespace std;



void Getnext(string str,int next[])
{
	next[0]=-1;
	for(int j=1;j<str.size();j++)
		for(int i=j-1;i>=0;i--)
		{
			string str1,str2;
			str1.assign(str,0,i);
			str2.assign(str,j-i,i);
			if(str1==str2) {
				next[j]=i;
				break;
			}
			else if(str1!=str2&&i==0) next[j]=0;
		}

    
}

int KMP(string str1,string str2)
{
	int next[10]={-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};
	Getnext(str2,next);
	for(int i=0;i<10;i++)
		cout<<next[i];
	cout<<endl;
	int i=0,j=0;
	while(i!=str1.size()&&j!=str2.size())
	{
		if(str1[i]==str2[j]){
			i++;
			j++;
		}
		else {
			j=next[j];
			if(j==-1){i++;j++;}
		}
	}

	if(j==str2.size()) return (i-str2.size()+1);
	else return -1;

}

int main()
{
	string str1=("ababaababccb");
	string str2=("ababc");
	int index=KMP(str1,str2);
	if(index>=0) cout<<"匹配完成，在第"<<index<<"的位置"<<endl;
	else cout<<"匹配失败"<<endl;
	return 0;
}
