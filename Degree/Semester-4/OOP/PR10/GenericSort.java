package PR10;

import java.util.Arrays;

public class GenericSort {
    public static <T extends Comparable<T>> void sort(T[] arr) {
        Arrays.sort(arr); // uses Comparable
    }

    public static void main(String[] args) {
        Integer[] a = {5, 2, 8, 1};
        sort(a);

        for (int i : a)
            System.out.print(i + " ");
    }
}   