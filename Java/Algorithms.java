import java.util.ArrayList;
import java.util.TreeMap;

/**
 * @author: Lam Duong
 * */
public class Algorithms {

    /**
     * The Johnson-Trotter Algorithm. This impelementation using a HashMap object
     * with a boolean value. Left is true. Right is false. Note: this will
     * take up Θ(n!) run-time.
     *
     * @param n the length of the number sequence
     * @return a list of permutations of the number sequence
     */
    public static ArrayList<Integer> johnsonTrotter(int n) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        TreeMap<Integer, Boolean> numberSequence = new TreeMap<Integer, Boolean>();
        int k = n;
        for (int i = 1; i <= n; i++) {
            numberSequence.put(i, true);
        }

        // O(n!) - the meat of the runtime
        while (hasMobileNumber(numberSequence)) {

        }
        return result;
    }

    /* Helper method for finding the mobile number. */
    public static boolean hasMobileNumber(TreeMap<Integer, Boolean> numberSequence) {
        boolean result = false;
        for (int i = 0; i < numberSequence.size(); i++) { // O(n)

        }
        return result;
    }
}
