package searchInABigSortedArray;

import org.junit.Test;
import searchInsertPosition.searchInsertPosition;

import static org.junit.Assert.*;

/**
 * Created by leicao on 5/10/15.
 */
public class searchInABigSortedArrayTest {

    @Test
    public void testSearchBigSortedArray() throws Exception {
        int [][] inputs = {
                {1,2,3,4},
                {1,1,1,1,2,2,3,3,3,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,6,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,
                10,10,10,10,10,11,11,11,11,12,12,12,13,13,13,13,13,14,14,14,14,14,15,15,15,15,15,15,15,16,16,16,16,16,16,16,16,16,17,17,
                17,17,17,17,17,18,18,19,19,19,19,20,20,20,20,20,20,20,20,20},
        };
        int[] targets = {3, 4};
        int[] results = {2, 9};
        searchInABigSortedArray s = new searchInABigSortedArray();
        for (int i = 0; i < inputs.length; i++) {
            int r = s.searchBigSortedArray(inputs[i], targets[i]);
            System.out.println(r);
            assertEquals(results[i], r);
        }


    }
}