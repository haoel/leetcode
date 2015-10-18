// Source : https://leetcode.com/problems/first-bad-version/
// Inspired by : http://www.jiuzhang.com/solutions/first-bad-version/
// Author : Lei Cao
// Date   : 2014-10-05

/**********************************************************************************
 *
 * The code base version is an integer start from 1 to n.
 * One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests.
 * Find the first bad version.
 *
 * You can call isBadVersion to help you determine which version is the first bad one.
 * The details interface can be found in the code's annotation part.
 *
 **********************************************************************************/

package firstBadVersion;

/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */
public class firstBadVersion extends VersionControl {
    public int firstBadVersion(int n) {
        if (n < 1) {
            return 0;
        }
        int start = 1;
        int end = n;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (super.isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (super.isBadVersion(start)) {
            return start;
        }
        if (super.isBadVersion(end)) {
            return end;
        }
        return 0;
    }
}
