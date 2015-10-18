package dynamicProgramming.triangle;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 15/10/15.
 */
public class triangleTest {

    @Test
    public void testMinimumTotal() throws Exception {
        int[][][] inputes = {
            {
                {2},
                {3,4},
                {6,5,7},
                {4,1,8,3},
            }
        };

        int[] results = {11};

        for (int i = 0; i < results.length; i++) {
            triangle t = new triangle();
            int r = t.minimumTotal2(inputes[i]);
            assertEquals(results[i], r);
        }

    }
}