#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class mycomparision
{
    bool min_queue;
public:
    mycomparision(const bool& mqueue = false):min_queue(mqueue){
    }
    bool operator()(const pair<int,int>& lhs , const pair<int,int> &rhs) const{
        if(min_queue)
            return (lhs.first + lhs.second > rhs.first + rhs.second);
        else
            return (lhs.first + lhs.second < rhs.first + rhs.second);
    }
};

class Solution
{
public:
    vector<pair<int,int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, mycomparision> pq;
        for(int i = 0 ; i < nums1.size() ; i++)
        {
            for(int j = 0 ; j < nums2.size() ; j++)
            {
                if(pq.size() < k)
                {
                    pq.push(make_pair(nums1[i],nums2[j]));
                }
                else
                {
                    auto top_pair = pq.top();
                    if(top_pair.first + top_pair.second > nums1[i] + nums2[j])
                    {
                        pq.pop();
                        pq.push(make_pair(nums1[i],nums2[j]));

                    }
                }
            }
        }
        if(pq.size() == 0)
            return vector<pair<int,int> >();

        vector<pair<int,int>> vec(pq.size());
        int i = pq.size() - 1;
        while(!pq.empty()){
            vec[i] = pq.top();
            pq.pop();
            --i;
        }
        return vec;
    }
};


int main()
{
    vector<int> vec1{1,1,2,2,3,5,6,7,7,8,8,9};
    vector<int> vec2{1,2,3,3,3,4,8,8,9,11,12};
    int k = 5;
    Solution s;
    vector<pair<int,int>> receiver;
    receiver = s.kSmallestPairs(vec1,vec2,k);

    for(auto val : receiver)
    {
        cout<<"( "<<val.first<<" , "<<val.second<<" ) "<<"      ";
    }
    cout<<endl;

}
