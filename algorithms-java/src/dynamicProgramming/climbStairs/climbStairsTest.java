package dynamicProgramming.climbStairs;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 12/10/15.
 */
public class climbStairsTest {

    @Test
    public void testClimbStairs() throws Exception {
        int[] inputs = {1,2,3,4};

        int[] results = {1,2,3,5};

        for (int i = 0; i < results.length; i++) {
            climbStairs c = new climbStairs();
            int r = c.climbStairs(inputs[i]);
            System.out.println(r);
            assertEquals(results[i], r);
        }
    }
}