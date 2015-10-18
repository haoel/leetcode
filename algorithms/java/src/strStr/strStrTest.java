package strStr;

import com.sun.org.apache.xpath.internal.operations.Equals;

import static org.junit.Assert.*;

/**
 * Created by leicao on 2/10/15.
 */
public class strStrTest {

    @org.junit.Test
    public void testStrStr() throws Exception {
        strStr strStr = new strStr();
        String[][]  inputs = {
            {"I am the haystack!","haystack!"},
            {"I am the haystack!","haytack"},
        };
        int[] outputs = {9, -1};
        for (int i = 0; i < inputs.length; i++) {
            assertEquals(outputs[i], strStr.strStr(inputs[i][0], inputs[i][1]));
        }
    }
}