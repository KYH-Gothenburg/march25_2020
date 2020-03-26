package main.java;

class Main {

    public static void bubblesortR(int[] arr, int length) {
        // Här behövs ett stoppvillkor

        // Här kommer ni göra logiken
        bubblesortR(arr, length - 1);
    }

    public static void bubblesort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            boolean swapped = false;
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swapped = true;
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = { 27, 3, 19, 64, 2, 76, 1 };
        // int arr[] = { 1, 2, 3, 19, 27, 64, 76 };

        bubblesort(arr);

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        // Nu är arr sorterad
    }
}