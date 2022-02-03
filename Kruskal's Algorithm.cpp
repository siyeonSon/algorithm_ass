#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

typedef struct edge
{
  int p;
  int q;
  int weight;
} set_of_edges;

typedef struct node
{
  int depth;
  int parent;
} universe;

bool cmp(const set_of_edges &p, const set_of_edges &q)
{
  if (p.weight < q.weight)
    return true;
  else
    return false;
}

universe *U;
void initial(int n)
{
  for (int i = 1; i <= n; i++)
  {
    U[i].parent = i;
    U[i].depth = 0;
  }
}

int find(int i)
{
  int j;
  j = i;
  while (U[j].parent != j)
  {
    j = U[j].parent;
  }
  return j;
}

void merge(int p, int q)
{
  if (U[p].depth == U[q].depth)
  {
    U[p].depth += 1;
    U[q].parent = p;
  }
  else if (U[p].depth < U[q].depth)
  {
    U[p].parent = q;
  }
  else
  {
    U[q].parent = p;
  }
}

bool equal(int p, int q)
{
  if (p == q)
    return true;
  else
    return false;
}

void kruskal(int n, int m, vector<set_of_edges> &E, vector<set_of_edges> &F)
{
  int i, j, l = 0;
  int p, q;
  set_of_edges e;

  sort(E.begin(), E.end(), cmp);
  F.clear();
  initial(n);

  while (F.size() < n - 1)
  {
    e = E[l++];
    i = e.p;
    j = e.q;
    p = find(i);
    q = find(j);
    if (!equal(p, q))
    {
      merge(p, q);
      F.push_back(e);
    }
  }
}

int main(void)
{
  vector<set_of_edges> E, F;
  int n;            // vertex의 개수
  int p, q, weight; // set_pointer & weight
  cin >> n;
  U = new universe[n + 1];
  U[0].parent = -1;
  U[0].depth = -1;

  while (true)
  {
    set_of_edges e;
    cin >> p >> q >> weight;
    if (p == -1)
      break;
    e.p = p;
    e.q = q;
    e.weight = weight;
    E.push_back(e);
  }

  kruskal(n, E.size(), E, F);

  cout << endl
       << ">> F" << endl;
  for (int f = 0; f < F.size(); f++)
  {
    cout << F[f].p << " " << F[f].q << " " << F[f].weight << endl;
  }
}
