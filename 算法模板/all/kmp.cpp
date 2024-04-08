class Solution {
public:
    void getnext(string needle,vector<int>&next)
    {
        int j = -1;
        next[0] = -1;
        int m = needle.size();
        for(int i = 1;i<m;i++)
        {
            while(j!=-1&&needle[i]!=needle[j+1])
            {
                j = next[j];
            }
            if(needle[i]==needle[j+1])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        next = vector<int>(n,0);
        getnext(needle,next);
        int j = -1;
        for(int i = 0;i<m;i++)
        {
            while(j!=-1&&haystack[i]!=needle[j+1])
            {
                j = next[j];
            }
            if(haystack[i] == needle[j+1])
            {
                j++;
            }
            if(j==n-1)
            {
                return i-j;
            }
        }
        return -1;
    }

    private:
    vector<int>next;
};