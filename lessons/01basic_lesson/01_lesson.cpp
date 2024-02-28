// 912
//快排和归并
class Solution {
public:
    void quick_sort(vector<int>&q,int l,int r)
    {
        if(l>=r)return ;
        int x = q[r]; //这边为l就不能取到q[l]，所以不能quick_sort(q,l,i-1); quick_sort(q,i,r);
        int i = l - 1;
        int j  = r+1;
        while(i<j)
        {
            do i++;while(q[i]<x);
            do j--;while(q[j]>x);
            if(i<j)
            {
                swap(q[i],q[j]);
            }
        }
        quick_sort(q,l,i-1);
        quick_sort(q,i,r);
    }


    void MergeSort(vector<int>&q,int l,int r)
    {
        //双指针算法 确定分界点 递归排序   归并合二为一 O(nlog(n));
        if(l >= r)
        {
            return ;
        }
        int mid = (l+r)>>1;
        MergeSort(q,l,mid);
        MergeSort(q,mid+1,r);
        int k = 0,i = l,j = mid +1;
        while(i<=mid&&j<=r)
        {
            if(q[i]<=q[j])tmp[k++] = q[i++];
            else tmp[k++] = q[j++];
        }
        while(i<=mid)tmp[k++] = q[i++];
        while(j<=r)tmp[k++] = q[j++];
        for(i = l,j = 0;i<=r;i++,j++)q[i] = tmp[j];

    }
    vector<int> sortArray(vector<int>& nums) {
        tmp = nums;
        MergeSort(nums,0,nums.size()-1);
        return nums;
    }
    private:
        vector<int>tmp;
};

//二分法模板

int bsearch_l(int l,int r)
{
    while(l<r)
    {
        int mid = l + r >>1;
        if(check(mid)) r=mid;
        else l = mid + 1;
    }
    return l;
}

int bsearch_2(int l,int r )
{
    while(l<r)
    {
        int mid = l + r + 1 >>1;
        if(check(mid)) l=mid;
        else r= mid - 1;
    }
    return l;
}
