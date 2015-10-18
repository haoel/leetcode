package searchForRange;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 3/10/15.
 */
public class searchForRangeTest {

    @Test
    public void testSearchRange() throws Exception {

        int[][] inputs = {
            {5, 7, 7, 8, 8, 10}
        };
        int[] targets = {8};
        int[][] results = {
            {3,4}
        };

        searchForRange s = new searchForRange();
        for (int i = 0; i < inputs.length; i++) {
            int[] r = s.searchRange(inputs[i], targets[i]);
            System.out.println(r);
            assertArrayEquals(results[i], r);
        }
    }
}