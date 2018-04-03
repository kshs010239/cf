#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>



using namespace std;
#define ll long long
#define DB(x) cout << (#x) << " = " << x << endl
#define DBV(x) {cout << (#x) << endl; for(auto it: x) cout << it << " "; cout << endl;}
typedef pair<int, int> dot;
#define X first
#define Y second



int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(auto& it: v)
		cin >> it;
	vector<vector<dot> > LIS(n + 1, vector<dot>(n + 1, dot(0, 0)));
	vector<vector<dot> > rLIS = LIS;
	for(int k = 0; k < n; k++)
	{
		int ans = 0;
		int two = 0;
		int rans = 0;
		int one = 0;
		for(int i = k; i < n; i++)
		{
			if(v[i] == 2)
			{
				two += 1;
				ans += 1;
				if(one > 0)
					one -= 1;
				else
					rans += 1;
			}
			else
			{
				if(two > 0)
					two -= 1;
				else
					ans += 1;			
				one += 1;
				rans += 1;
			}
			LIS[k][i + 1] = dot(ans - two, two);
			rLIS[k][i + 1] = dot(rans - one, one);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			int tmp = LIS[0][i].X;
			tmp += max(LIS[0][i].Y, rLIS[i][j].X);
			tmp += max(rLIS[i][j].Y, LIS[j][n].X);
			tmp += LIS[j][n].Y;
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
}
