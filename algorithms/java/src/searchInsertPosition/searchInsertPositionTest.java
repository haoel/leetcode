package searchInsertPosition;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 3/10/15.
 */
public class searchInsertPositionTest {

    @Test
    public void testSearchInsert() throws Exception {
        int [][] inputs = {
                {1,3,5,6},
                {1,3,5,6},
                {1,3,5,6},
                {1,3,5,6},
        };
        int[] targets = {5,2,7,0};
        int[] results = {2,1,4,0};
        searchInsertPosition s = new searchInsertPosition();
        for (int i = 0; i < inputs.length; i++) {
            int r = s.searchInsert(inputs[i], targets[i]);
            System.out.println(r);
            assertEquals(results[i], r);
        }
    }
}