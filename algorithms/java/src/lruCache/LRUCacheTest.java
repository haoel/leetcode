import java.util.ArrayList;

import org.junit.Test;
import static org.junit.Assert.*;

public class LRUCacheTest {

    private LRUCache c;

    public LRUCacheTest() {
        this.c = new LRUCache(2);
    }

    @Test
    public void testCacheStartsEmpty() {
        assertEquals(c.get(1), -1);
    }

    @Test
    public void testSetBelowCapacity() {
        c.set(1, 1);
        assertEquals(c.get(1), 1);
        assertEquals(c.get(2), -1);
        c.set(2, 4);
        assertEquals(c.get(1), 1);
        assertEquals(c.get(2), 4);
    }

    @Test
    public void testCapacityReachedOldestRemoved() {
        c.set(1, 1);
        c.set(2, 4);
        c.set(3, 9);
        assertEquals(c.get(1), -1);
        assertEquals(c.get(2), 4);
        assertEquals(c.get(3), 9);
    }

    @Test
    public void testGetRenewsEntry() {
        c.set(1, 1);
        c.set(2, 4);
        assertEquals(c.get(1), 1);
        c.set(3, 9);
        assertEquals(c.get(1), 1);
        assertEquals(c.get(2), -1);
        assertEquals(c.get(3), 9);
    }
}
