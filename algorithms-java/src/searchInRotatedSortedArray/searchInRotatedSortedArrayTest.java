package searchInRotatedSortedArray;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 3/10/15.
 */
public class searchInRotatedSortedArrayTest {

    @Test
    public void testSearch() throws Exception {

        int[][] inputes = {
            {1},
            {1},
            {6,8,9,1,3,5},
            {1,2},
            {2,1},
            {4,5,6,7,0,1,2},
            {0,1,2,4,5,6,7},
        };
        int[] targets = {0,1,5,2,2,6,6};
        int[] results = {-1,0,5,1,0,2,5};

        searchInRotatedSortedArray s = new searchInRotatedSortedArray();
        for (int i = 0; i < inputes.length; i++) {
            int r = s.search(inputes[i], targets[i]);
            System.out.println(r);
            assertEquals(results[i], r);
        }
    }
}