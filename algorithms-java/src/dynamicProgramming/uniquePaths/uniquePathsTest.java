package dynamicProgramming.uniquePaths;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 11/10/15.
 */
public class uniquePathsTest {

    @Test
    public void testUniquePaths() throws Exception {
        int[][] inputs = {
                {2,2},
                {3,7},
        };
        int[] results = {2,28};
        for (int i = 0; i < inputs.length; i++) {
            uniquePaths u = new uniquePaths();
            int r = u.uniquePaths(inputs[i][0], inputs[i][1]);
            System.out.println(r);
            assertEquals(results[i], r);
        }

    }
}