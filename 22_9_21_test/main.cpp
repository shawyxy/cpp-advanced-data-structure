#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv( numRows);
        for(int i = 0; i < numRows; i++)
        {
            vv[i].resize(i + 1);
            vv[i][0] = 1;
            vv[i][i] = 1;
        }
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 1; j < i; j++)
            {
                vv[i][j] = vv[i-1][j-1] + vv[i-1][j];
            }
        }
        return vv;
    }
};
void test1()
{
    Solution s;
    vector<vector<int>> vv = s.generate(5);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}
class Solution1{
public:
    int removeDuplicates(vector<int>& nums) {
        int old_sz = nums.size();
        for(int i = 1; i < nums.size();)
        {
            if(nums[i] == nums[i-1])
            {
                nums.erase(nums.begin()+i);
                cout << nums.size() << " ";
            }
            else
            {
                i++;
            }
        }
        return nums.size();
    }
};
#include <array>
void test2()
{
    Solution1 s;
    vector<int> a = {0,0,1,1,1,2,2,3,3,4};
    cout << s.removeDuplicates(a);

}
int main() {
    test2();
    return 0;
}
