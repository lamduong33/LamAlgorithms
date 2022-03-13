import java.util.ArrayList;

/**
 * @author: Lam Duong
 */
public class Algorithms {

    /**
     * The Johnson-Trotter Algorithm. This impelementation using a HashMap object
     * with a boolean value. Left is true. Right is false. Note: this will take up
     * Θ(n!) run-time.
     *
     * @param n the length of the number sequence
     * @return a list of permutations of the number sequence
     */
    public static ArrayList<int[]> johnsonTrotter(int n) {
        int k = n;
        int[] numberSequence = new int[n];
        Boolean[] arrowSequence = new Boolean[n];
        ArrayList<int[]> result = new ArrayList<int[]>();

        // initialize the first permutation
        for (int i = 1; i <= n; i++) {
            numberSequence[i - 1] = i;
            arrowSequence[i - 1] = true;
        }
        result.add(numberSequence.clone());

        while (k != -1) { // O(n!)
            for (int i = 0; i < n; i++) { // Swap process - O(n)
                if (numberSequence[i] == k) {
                    int pointedIndex;
                    if (arrowSequence[i]) {
                        pointedIndex = i - 1;
                    } else {
                        pointedIndex = i + 1;
                    }
                    int tempNum = numberSequence[pointedIndex];
                    Boolean tempArrow = arrowSequence[pointedIndex];
                    numberSequence[pointedIndex] = numberSequence[i];
                    arrowSequence[pointedIndex] = arrowSequence[i];
                    numberSequence[i] = tempNum;
                    arrowSequence[i] = tempArrow;
                    break;
                }
            }
            // Flip any thing that is greater than k, O(n)
            for (int i = 0; i < n; i++) {
                if (numberSequence[i] > k) {
                    arrowSequence[i] = !arrowSequence[i];
                }
            }
            result.add(numberSequence.clone());
            k = greatestMobileNumber(numberSequence, arrowSequence, n); // O(n)
        }

        return result;
    }

    /* Helper method for johnsonTrotter() */
    public static int greatestMobileNumber(int[] numberSequence, Boolean[] arrowSequence, int n) {
        int k = -1; // -1 is not found
        for (int i = 0; i < n; i++) {
            if (i == 0) { // first
                if (!arrowSequence[i] && (numberSequence[i] > numberSequence[i + 1])) {
                    if (numberSequence[i] > k)
                        k = numberSequence[i];
                }
            } else if (i != n - 1) { // middle
                if ((arrowSequence[i] && (numberSequence[i] > numberSequence[i - 1]))
                        || (!arrowSequence[i] && (numberSequence[i] > numberSequence[i + 1]))) {
                    if (numberSequence[i] > k)
                        k = numberSequence[i];
                }
            } else { // last
                if (arrowSequence[i] && (numberSequence[i] > numberSequence[i - 1])) {
                    if (numberSequence[i] > k)
                        k = numberSequence[i];
                }
            }
        }
        return k;
    }

    public static void main(String[] args) {
        ArrayList<int[]> a = johnsonTrotter(4);
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a.get(i).length; j++) {
                System.out.print(a.get(i)[j]);
            }
            System.out.println();
        }
    }
}
