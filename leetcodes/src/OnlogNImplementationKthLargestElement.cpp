#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
    public:
        int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        sort(nums.begin() , nums.end());
        return nums[len - k];

    }
};
int main()
{
    int k,elem;
    char choice;
    vector <int> vec;
    Solution s;


    while(choice != 'n')
    {
        cout<<"\nProvide vector element "<<endl;
        cin>>elem;
        vec.push_back(elem);
        cout<<"\nDo you want to continute (y/n) ";
        cin>>choice;
    }
    cout<<"\n Vector elements are  " ;
    for(auto val:vec)
    {
        cout<<val<<"  ";
    }
    cout<<"\nPlease provide Kth element value ";
    cin>>k;

    cout<<"\nValue of Kth Largest element is "<<s.findKthLargest(vec,k);
    cout<<endl;
}
