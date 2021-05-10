// Source : https://leetcode.com/problems/finding-mk-average/
// Author : Hao Chen
// Date   : 2021-04-20

/***************************************************************************************************** 
 *
 * You are given two integers, m and k, and a stream of integers. You are tasked to implement a data 
 * structure that calculates the MKAverage for the stream.
 * 
 * The MKAverage can be calculated using these steps:
 * 
 * 	If the number of the elements in the stream is less than m you should consider the 
 * MKAverage to be -1. Otherwise, copy the last m elements of the stream to a separate container.
 * 	Remove the smallest k elements and the largest k elements from the container.
 * 	Calculate the average value for the rest of the elements rounded down to the nearest 
 * integer.
 * 
 * Implement the MKAverage class:
 * 
 * 	MKAverage(int m, int k) Initializes the MKAverage object with an empty stream and the two 
 * integers m and k.
 * 	void addElement(int num) Inserts a new element num into the stream.
 * 	int calculateMKAverage() Calculates and returns the MKAverage for the current stream 
 * rounded down to the nearest integer.
 * 
 * Example 1:
 * 
 * Input
 * ["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", 
 * "addElement", "addElement", "addElement", "calculateMKAverage"]
 * [[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
 * Output
 * [null, null, null, -1, null, 3, null, null, null, 5]
 * 
 * Explanation
 * MKAverage obj = new MKAverage(3, 1); 
 * obj.addElement(3);        // current elements are [3]
 * obj.addElement(1);        // current elements are [3,1]
 * obj.calculateMKAverage(); // return -1, because m = 3 and only 2 elements exist.
 * obj.addElement(10);       // current elements are [3,1,10]
 * obj.calculateMKAverage(); // The last 3 elements are [3,1,10].
 *                           // After removing smallest and largest 1 element the container will be 
 * [3].
 *                           // The average of [3] equals 3/1 = 3, return 3
 * obj.addElement(5);        // current elements are [3,1,10,5]
 * obj.addElement(5);        // current elements are [3,1,10,5,5]
 * obj.addElement(5);        // current elements are [3,1,10,5,5,5]
 * obj.calculateMKAverage(); // The last 3 elements are [5,5,5].
 *                           // After removing smallest and largest 1 element the container will be 
 * [5].
 *                           // The average of [5] equals 5/1 = 5, return 5
 * 
 * Constraints:
 * 
 * 	3 <= m <= 10^5
 * 	1 <= k*2 < m
 * 	1 <= num <= 10^5
 * 	At most 10^5 calls will be made to addElement and calculateMKAverage.
 ******************************************************************************************************/

class MKAverage {
private:
    vector<int> ringBuf;
    int pos;
    multiset<int> left, mid, right;
    long sum;
    long maxmin;
    int m;
    int k;
private:
    template <class T>
    void print(T& v) {
        for(auto it : v){
            cout << it << "+";
        }
        cout <<endl;
    }
    int takeMax(multiset<int>& s) {
        auto it = --s.end();
        int n = *it;
        s.erase(it);
        return n;
    }
    int takeMin(multiset<int>& s) {
        auto it = s.begin();
        int n = *it;
        s.erase(it);
        return n;
    }
public:
    MKAverage(int _m, int _k): ring(_m, 0), m(_m), k(_k), sum(0), pos(0), maxmin(0) {
        
    }
    
    void ins(int n) {
        left.insert(n);
        maxmin += n;
        if (left.size() > k ) {
            int n = takeMax(left);
            right.insert(n);
            if (right.size() > k) {
                int n = takeMin(right);
                maxmin -= n;
                mid.insert(n);
            }
        }
    }
    
    void del(int n) {
        if (n <= *(left.rbegin())) {
            left.erase(left.find(n));
            int n1 = takeMin(mid);
            left.insert(n1);
            maxmin += (n1 - n);
        }else if (n >= *(right.begin())) {
            right.erase(right.find(n));
            int n1 = takeMax(mid);
            right.insert(n1);
            maxmin += (n1 - n);
        }else {
            mid.erase(mid.find(n));
        }   
    }
    
    void addElement(int num) {
        pos++; 
        if (pos > m) {
            int n = ringBuf[pos % m];
            sum -= n;
            del(n);
            //cout << "DEL: n=" << n << ", sum=" << sum << ", maxmin=" << maxmin << endl;
            //print(left); print(mid);print(right);
        } 
        
        ringBuf[pos % m] = num ;
        sum += num;
        
        ins(num);
        //cout << "INS: n=" << num << ", sum=" << sum << ", maxmin=" << maxmin << endl;
        //print(left); print(mid);print(right);
    }

    
    int calculateMKAverage() {
        if (pos < m) return -1;
        //cout << "CAL: sum=" << sum << ", maxmin=" << maxmin  << ", delta=" << sum - maxmin<< endl;
        return (sum - maxmin) / (m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */









//TLE solution - using only one array and Binary Search.


class MKAverage1 {
private:
    vector<int> ring;
    int pos;
    vector<int> sort;
    long sum;
    long maxmin;
    int m;
    int k;
private:
    template <class T>
    void print(T& v) {
        for(auto it : v){
            cout << it << "+";
        }
        cout <<endl;
    }
public:
    MKAverage1(int _m, int _k):  ring(_m,0), m(_m), k(_k), sum(0), pos(0), maxmin(0) {
        
    }
    void ins(int n) {
        
        int low = 0, high = sort.size()-1;
        int mid;
        if (high < 0 || n >= sort[high]) {
            sort.push_back(n); 
            return;
        }
        
        while(low <= high){
            mid = low + (high-low)/2;
            if (sort[mid]  <= n ) low = mid + 1;
            else high = mid - 1;
        }
        auto it = sort.begin() + low;
        sort.insert(it, n);
    }
    
    void del(int n) {
        int len = sort.size();
        int low = 0, high = len -1;
        int mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if (sort[mid] == n) break;
            if (sort[mid]  < n ) low = mid + 1;
            else high = mid - 1;
        }
        
        if (low > high) return;
        
        auto it = sort.begin() + mid;
        sort.erase(it);
        
    }
    void addElement(int num) {
        pos++;
        
        if (pos > m) {
            int n = ring[pos % m];
            sum -= n;
            
            int len = sort.size();
            if (n <= sort[k-1] ) maxmin += (sort[k]-n);
            else if (n >= sort[len-k]) maxmin += (sort[len-k-1] - n);
            
            del(n);
            //cout << "DEL: n=" << n << ", sum=" << sum << ", maxmin=" << maxmin << endl;
            //print(sort);
        } 
        
        
        ring[pos % m] = num;
        sum += num;
        
        if (sort.size() < 2*k ) {
            maxmin += num;
        } else {
            int len = sort.size();
            if (num <= sort[k-1]) maxmin += (num - sort[k-1]);
            else if (num >= sort[len-k]) maxmin += (num -sort[len-k]);
        }
        
        ins(num);
        //cout << "INS: n=" << num << ", sum=" << sum << ", maxmin=" << maxmin << endl;
        //print(sort);
    }

    
    int calculateMKAverage() {
        if ( pos < m) return -1;
        //cout << "CAL: sum=" << sum << ", maxmin=" << maxmin  << ", delta=" << sum - maxmin<< endl;
        return (sum - maxmin) / (m-2*k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */




