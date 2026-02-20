#include <bits/stdc++.h>
using namespace std;
char c[1000001];//开大点，以防万一
int s=0,total=0;//s表示人数，total表示总流量
int main()
{
	while(gets(c+1))//读数据
	{
		if(c[1]=='+') s++;//如果第一个字符是+号，人数+1
		if(c[1]=='-') s--;//同上，反之亦然
		if(c[1]-'+'&&c[1]-'-')//第一个字符不是+或-，说明这一行是描述一个人说话
		{
			int t=1;//字符串起始位置（我习惯从1开始）
			while(c[t]-':') t++;//向右扫描直到冒号
			total+=((strlen(c+1)-t)*s);//算出话的长度，乘上人数，加到总流量里。
		}
	}
	cout<<total;//输出
	return 0;
}