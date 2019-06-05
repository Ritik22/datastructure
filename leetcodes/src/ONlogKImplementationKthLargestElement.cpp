//Leet code problem number 215 implementation
//Using min heap priority queue
//O ( nlogk) - complexity

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> ,greater<int> > pq;
        int len = nums.size();
        for(int i = 0; i < len ; i++)
        {
            if(pq.size() < k)
            {
                pq.push(nums[i]);
            }
            else
            {
                int elem = pq.top();
                if(elem < nums[i])
                {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
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
