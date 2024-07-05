#include <iostream>
#include <cstdlib>
using namespace std;

bool esSimoniana(int matriz[][5]);

int main()
{

    int matrizSimoniana[5][5] = {
      { 1 , 2 , 3, 4, 5 },
      { 5, 4, 18, 10, 11},
      { 1, 1, 1, 1, 1},
      { 9, 8, 4, 2, -5},
      { 10, 10, 10, 10, 10},
    };

    cout << esSimoniana(matrizSimoniana) << " endl" << endl;

    return 0;
}

bool esSimoniana(int matriz[][5])
{
    int acumuladores[5] = {};

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            acumuladores[x] += matriz[x][y];
        }
    }

    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            for (int z = 0; z < 5; z++)
            {
                if (matriz[x][y] == acumuladores[z])
                {
                    return true;
                }
            }
        }
    }

    return false;
}