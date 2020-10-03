class Solution {
public:
   int lengthOfLongestSubstring(string s)
   {
      int n = s.length();

      if (n == 0 || n == 1)
         return n;

      int alpha[256];

      for (int i = 0; i < 256; i++)
         alpha[i] = 0;

      deque<char> Q;

      int max = INT_MIN;

      for (int i = 0; i < n; i++)
      {
         if (alpha[s[i]] == 1)
         {
            while (Q.front() != s[i])
            {
               alpha[Q.front()] = 0;
               Q.pop_front();
            }
            alpha[Q.front()] = 0;
            Q.pop_front();
         }

         alpha[s[i]] = 1;
         Q.push_back(s[i]);
         int size = Q.size();
         max = std::max(max, size);
      }

      return max;
   }
};