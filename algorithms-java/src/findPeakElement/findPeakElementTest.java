package findPeakElement;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by leicao on 5/10/15.
 */
public class findPeakElementTest {

    @Test
    public void testFindPeak() throws Exception {
        //* For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
        int [][] inputs = {
            {1,2,3,1}
        };
        int[] results = {2};

        findPeakElement f = new findPeakElement();
        for (int i = 0; i < results.length; i++) {
            int r = f.findPeakElement(inputs[i]);
            System.out.println(r);
            assertEquals(results[i], r);
        }
    }
}