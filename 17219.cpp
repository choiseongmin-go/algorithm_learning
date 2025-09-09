#include <iostream>
#include <map>

using namespace std;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	map<string, string> m;
	string site, pwd, target_site;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> site >> pwd;
		m[site] = pwd;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> target_site;
		cout << m[target_site] << '\n';
	}

	return 0;
}