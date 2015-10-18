package subsets;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import static org.junit.Assert.*;

/**
 * Created by leicao on 2/10/15.
 */
public class subsetsTest {

    @Test
    public void testSubsets() throws Exception {

        ArrayList<Integer> inputs = new ArrayList<Integer>(){{
            add(1);
            add(2);
            add(3);
        }};
        ArrayList<ArrayList<Integer>> outputs = new ArrayList<ArrayList<Integer>>(){{
            add(new ArrayList<Integer>(){{
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
            }});
            add(new ArrayList<Integer>(){{
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(2);
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
            }});
        }};
        subsets s = new subsets();
        ArrayList<ArrayList<Integer>> r = new ArrayList<ArrayList<Integer>>();
        r = s.subsets(inputs);

        System.out.println(r);
        assertTrue(r.containsAll(outputs) && r.size() == outputs.size());
    }

    @Test
    public void testSubsets1() throws Exception {
        int[] inputs = {1,2,3};
        List<List<Integer>> outputs = new ArrayList<List<Integer>>(){{
            add(new ArrayList<Integer>(){{
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
            }});
            add(new ArrayList<Integer>(){{
                add(2);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(2);
                add(3);
            }});
            add(new ArrayList<Integer>(){{
                add(1);
                add(2);
            }});
            add(new ArrayList<Integer>(){{
            }});
        }};
        subsets s = new subsets();
        List<List<Integer>> r = new ArrayList<List<Integer>>();
        r = s.subsets(inputs);

        System.out.println(r);
        assertTrue(r.containsAll(outputs) && r.size() == outputs.size());
    }
}