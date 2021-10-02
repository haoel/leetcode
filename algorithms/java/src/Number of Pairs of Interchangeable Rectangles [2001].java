class Solution {
    public long interchangeableRectangles(int[][] a) {
        int n=a.length;
        double arr[]=new double[n];
        for(int i=0;i<n;i++)
            arr[i]=(double)a[i][0]/a[i][1];
        Arrays.sort(arr);
        long ans=0;
        int i=0;
        while(i<n)
        {
            int j=i;
            long count=0;
            while(j<n&&arr[i]==arr[j])
            {
                count++;
                j++;
            }
            ans+=(count*(count-1))/2;
            i=j;
        }
        return ans;
    }
}
