public class RomanToInt {
  /*
  Scroll from left to right
  if value of a numeral is higher or equal to the one to its right
  add the value of the right and left

  if the value of a numeral is lower than the one to its right
  subtract the left from the right

  IV = V - I

  VI = V + I

  */
  public static final int M = 1000;
  public static final int D = 500;
  public static final int C = 100;
  public static final int L = 50;
  public static final int X = 10;
  public static final int V = 5;
  public static final int I = 1;

  public static void main(String[] args) {
    String str = args[0];
    int sum = 0;

    for (int i = 0; i < str.length(); i++) {

      char c = str.charAt(i);

      if (i < str.length() - 1) {
        if (numeralAt(c) < numeralAt(str.charAt(i+1)))
          sum -= numeralAt(c);
        else
          sum += numeralAt(c);
      }
      else
        sum += numeralAt(c);
    }
    
    System.out.println(str + " is equal to " + sum);
  }
  public static int numeralAt(char c) {
    int n = 0;
    switch (c) {
      case 'M':
        n = M;
        break;
      case 'D':
        n = D;
        break;
      case 'C':
        n = C;
        break;
      case 'L':
        n = L;
        break;
      case 'X':
        n = X;
        break;
      case 'V':
        n = V;
        break;
      case 'I':
        n = I;
        break;
    }
    return n;
  }
}
