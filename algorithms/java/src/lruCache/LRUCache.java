/*
Analogous to the C++ solution at:
https://github.com/haoel/leetcode/blob/625ad10464701fc4177b9ef33c8ad052d0a7d984/algorithms/cpp/LRUCache/LRUCache.cpp
which uses linked list + hash map. But the Java stdlib provides LinkedHashMap
which already implements that for us, making this solution shorter.

This could also be done by using, but that generates
some inheritance boilerplate, and ends up taking the same number of lines:
https://github.com/cirosantilli/haoel-leetcode/commit/ff04930b2dc31f270854e40b560723577c7b49fd
*/

import java.util.LinkedHashMap;
import java.util.Iterator;

public class LRUCache {

    private int capacity;
    private LinkedHashMap<Integer,Integer> map;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new LinkedHashMap<>();
    }

    public int get(int key) {
        Integer value = this.map.get(key);
        if (value == null) {
            value = -1;
        } else {
            this.set(key, value);
        }
        return value;
    }

    public void set(int key, int value) {
        if (this.map.containsKey(key)) {
            this.map.remove(key);
        } else if (this.map.size() == this.capacity) {
            Iterator<Integer> it = this.map.keySet().iterator();
            it.next();
            it.remove();
        }
        map.put(key, value);
    }
}
