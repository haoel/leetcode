package dynamicProgramming.uniquePaths;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 11/10/15.
 */
public class uniquePathsIITest {

    @Test
    public void testUniquePathsWithObstacles() throws Exception {
        int[][][] inputs = {
            {
                {0,0,0},
                {0,1,0},
                {0,0,0},
            }
        };
        int[] results = {2};
        for (int i = 0; i < inputs.length; i++) {
            uniquePathsII u = new uniquePathsII();
            int r = u.uniquePathsWithObstacles(inputs[i]);
            System.out.println(r);
            assertEquals(results[i], r);
        }
    }
}