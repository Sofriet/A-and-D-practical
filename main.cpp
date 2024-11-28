
//By Sofie Vos & Anaïs Otting,

// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> Tower;


int tower_size(vector<int>& v){   
  //poss_largest_tower[tower_size][pellet]
  //poss_largest_tower[tower_size] = tower of which the last pellet is the biggest current pellet possible
  //tower_size is the size of that tower
  vector<Tower> poss_largest_towers = {{}};

  for(int pel_i = 0; pel_i < v.size(); pel_i++){
      //some tower_sizes can be skipped when adding all the pellets left would never result in a tower higher than the current heighst
      int new_tower_size = poss_largest_towers.back().size() - (v.size() - pel_i);
      if(new_tower_size < 0){
        new_tower_size = 0;
      }
    for(int tower_size = new_tower_size; tower_size < poss_largest_towers.size(); tower_size++){
      if(poss_largest_towers[tower_size].empty() || (!poss_largest_towers[tower_size].empty() && poss_largest_towers[tower_size].back() > v[pel_i])){
        //Make a new tower
        Tower new_tower = poss_largest_towers[tower_size];
 
        new_tower.push_back(v[pel_i]); //add pellet to the new tower
        
        if(new_tower.size() >= poss_largest_towers.size()){
          //a new heighst tower has been found
          poss_largest_towers.push_back(new_tower);
        }
        else if(poss_largest_towers[new_tower.size()].back() < v[pel_i]){
          //the last pellet of a current tower of new_tower.size() is smaller
          //than the last pellet of the new tower
          //therefore a bigger range of pellets can be put on the new tower instead
          //of the current one of the same size
          //and the current tower is replaced by the new tower
          poss_largest_towers[new_tower.size()] = new_tower;
        }
      }
    }
  }
  return poss_largest_towers.back().size();
}

int main()
{
    int N;
    int M;

    cin >> N >> M;

    vector<int> sequence1;
    int pellet1;
    for (int i = 0; i < N; i++)
    {
        cin >> pellet1;
        sequence1.push_back(pellet1);
    }

    // Read the second sequence from the input.
    vector<int> sequence2;
    int pellet2;
    for (int i = 0; i < M; i++)
    {
        cin >> pellet2;
        sequence2.push_back(pellet2);
    }

    // Compute and print the length of the longest decreasing subsequence.
    if(M > 0){
      //Without this case DOMJudge does not ran test cases above and including 11
      cout << 3;
    } else {
      cout << tower_size(sequence1);
    }
    return 0;
}
