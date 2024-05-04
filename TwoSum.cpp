#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> freqSet;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++){
        freqSet[i] = nums[i];
    }        

    //for(auto i:freqSet) cout<<i.first<<"_"<<i.second<<endl;

    for (int i = 0; i < nums.size(); i++)
    {
        int elementToCheck = target - nums[i];
        if (freqSet[elementToCheck])
        {
            ans.push_back(freqSet[nums[i]]);
            ans.push_back(freqSet[elementToCheck]);

            return ans;
        }
    }

}

int main(){
    vector<int> query = {3, 4, 6, 1, 4};
    vector<int> ans = twoSum(query, 8);

    for(int i : ans)
        cout<<i<<"_";

    return 0;
}
