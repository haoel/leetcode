package dynamicProgramming.minimumPathSum;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 12/10/15.
 */
public class minimumPathSumTest {

    @Test
    public void testMinPathSum() throws Exception {
        int[][][] inputs = {
            {
                {1,2},
                {1,2},
            }
        };

        int [] results = {4};

        for (int i = 0; i < results.length; i++) {
            minimumPathSum m = new minimumPathSum();
            int r = m.minPathSum(inputs[i]);
            System.out.println(r);
            assertEquals(results[i], r);
        }
    }
}