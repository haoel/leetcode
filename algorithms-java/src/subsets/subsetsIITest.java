package subsets;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertTrue;

/**
 * Created by leicao on 2/10/15.
 */
public class subsetsIITest {

    @Test
    public void testSubsetsIILintcode() throws Exception {

        ArrayList<Integer> inputs = new ArrayList<Integer>(){{
            add(1);
            add(2);
            add(2);
        }};
        ArrayList<ArrayList<Integer>> outputs = new ArrayList<ArrayList<Integer>>(){{
            add(new ArrayList<Integer>(){{
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(2);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
            }});
        }};
        subsetsII s = new subsetsII();
        ArrayList<ArrayList<Integer>> r = new ArrayList<ArrayList<Integer>>();
        r = s.subsetsWithDup(inputs);

        System.out.println(r);
        assertTrue(r.containsAll(outputs) && r.size() == outputs.size());
    }

    @Test
    public void testSubsetsIILeetcode() throws Exception {
        int[] inputs = {1,2,2};
        List<List<Integer>> outputs = new ArrayList<List<Integer>>(){{
            add(new ArrayList<Integer>(){{
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(2);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
            }});
        }};
        subsetsII s = new subsetsII();
        List<List<Integer>> r = new ArrayList<List<Integer>>();
        r = s.subsetsWithDup(inputs);

        System.out.println(r);
        assertTrue(r.containsAll(outputs) && r.size() == outputs.size());
    }
}