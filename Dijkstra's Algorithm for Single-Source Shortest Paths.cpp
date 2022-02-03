#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef struct edge
{
  int p;
  int q;
  int weight;
};

void dijkstra(int n, int **W, vector<edge> &F)
{
  int i, vnear, k = 0;
  edge e;
  F.clear();
  int *touch = new int[n + 1];
  int *length = new int[n + 1];
  for (i = 2; i <= n; i++)
  {
    touch[i] = 1;
    length[i] = W[1][i];
  }

  for (k = 0; k < n - 1; k++)
  {
    int min = 9999;
    for (int i = 2; i <= n; i++)
    {
      if (0 <= length[i] && length[i] <= min)
      {
        min = length[i];
        vnear = i;
      }
    }

    e.p = touch[vnear];
    e.q = vnear;
    e.weight = W[e.p][e.q];

    F.push_back(e);

    for (int i = 2; i <= n; i++)
    {
      if (length[vnear] + W[vnear][i] < length[i])
      {
        length[i] = length[vnear] + W[vnear][i];
        touch[i] = vnear;
      }
    }
    length[vnear] = -1;
  }
}

int main()
{
  int n;
  int **W;
  vector<edge> E, F;
  cin >> n;

  W = new int *[n + 1];
  for (int i = 0; i < n + 1; i++)
  {
    W[i] = new int[n + 1];
    for (int j = 0; j < n + 1; j++)
    {
      W[i][j] = 9999;
      W[i][i] = 0;
    }
  }
  while (true)
  {
    edge sub;
    cin >> sub.p >> sub.q >> sub.weight;
    if (sub.p == -1)
      break;
    W[sub.p][sub.q] = sub.weight;
    E.push_back(sub);
  }

  dijkstra(n, W, F);
  cout << endl
       << ">> F" << endl;
  for (int i = 0; i < F.size(); i++)
  {
    cout << F[i].p << " " << F[i].q << " " << F[i].weight << endl;
  }
  return 0;
}