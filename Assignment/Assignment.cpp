#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> Coordinate(vector<vector<int>>& towers, int radius) 
{
    int Maximum_Quality = -1, x = -1, y = -1;
    for (int i = 0; i <= 100; i++) // considering coordinates in [0, 100] 
	{ 
        for (int j = 0; j <= 100; j++) 
		{
            int quality = 0;
            for (auto& tower : towers) 
			{
                int z = sqrt(pow(tower[0] - i, 2) + pow(tower[1] - j, 2));
                if (z <= radius) 
				{
                    quality += floor(tower[2] / (1 + z));
                }
            }
            if (quality > Maximum_Quality) 
			{
                Maximum_Quality = quality;
                x = i;
                y = j;
            } else if (quality == Maximum_Quality && (x == -1 || i < x || (i == x && j < y))) 
			{
                x = i;
                y = j;
            }
        }
    }
    return {x, y};
}

int main() {
    vector<vector<int>> towers = {{1,2,5},{2,1,7},{3,1,9}};
    int radius = 2;
    vector<int> result = Coordinate(towers, radius);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

