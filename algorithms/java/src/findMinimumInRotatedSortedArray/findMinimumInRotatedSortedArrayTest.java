package findMinimumInRotatedSortedArray;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 5/10/15.
 */
public class findMinimumInRotatedSortedArrayTest {

    @Test
    public void testFindMin() throws Exception {
        int[][] inputs = {
            {4,5,6,7,0,1,2},
            {1,2,3},
            {2,3,1},
            {1,2,3,4},
            {2,3,4,1}
        };

        int [] results = {0,1,1,1,1};

        findMinimumInRotatedSortedArray f = new findMinimumInRotatedSortedArray();
        for (int i = 0; i < results.length; i++) {
            int r = f.findMin(inputs[i]);
            System.out.println(results[i]);
            assertEquals(results[i], r);
        }
    }
}