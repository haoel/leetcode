package search2DMatrix;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 3/10/15.
 */
public class search2DMatrixTest {

    @Test
    public void testSearchMatrix() throws Exception {
        int[][][] inputes = {
                {
                        {1,3,5,7},
                        {10,11,16,20},
                        {23,30,34,50},
                },
        };
        int[] targets =  {3};
        boolean[] outputs = {true};

        search2DMatrix s = new search2DMatrix();
        for (int i = 0; i < targets.length; i++) {
            boolean r = s.searchMatrix(inputes[i], targets[i]);
            System.out.println(r);
            assertEquals(outputs[i], r);
        }
    }
}