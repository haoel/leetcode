package firstBadVersion;

/**
 * Created by leicao on 5/10/15.
 */
public class VersionControl {
    int firstBadVersion;
    boolean isBadVersion(int version) {
        if (version >= firstBadVersion) {
            return true;
        }
        return false;
    }
}
