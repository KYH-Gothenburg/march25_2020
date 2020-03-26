package main.java;

class Main {

    public static int getTriangularNumber(int number) {
        int triangular = 0;
        while (number > 0) {
            triangular += number;
            number--;
        }
        return triangular;
    }

    public static int getTriangularR(int number) {
        // System.out.println("Method " + number);
        if (number == 1) {
            // System.out.println("Returned: 1");
            return 1;
        }
        // int result = number + getTriangularR(number - 1);
        // System.out.print("Returned: " + result);
        // System.out.println(" : " + number + " getTriangularR(" + number + "-1)");
        // return result;
        return number + getTriangularR(number - 1);
    }

    public static int facTail(int number) {
        if (number == 1) {
            return 1;
        }
        return number * facTail(number - 1);
    }

    public static int facHead(int number) {
        if (number > 1) {
            return number * facHead(number - 1);
        }
        return 1;
    }

    public static void main(String[] args) {
        System.out.println(facHead(5));
        // System.out.println(getTriangularR(97));
    }
}

// 3! 3 * 2 * 1 = 6

// 3! 3 * 2 = 6
// 2! 2 * 1
// 1! 1

// 4! 4 * 3 * 2 * 1 = 24

// 4! 4 * 6
// 3! 3 * 2
// 2! 2 * 1
// 1! 1