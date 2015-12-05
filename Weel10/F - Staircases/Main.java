import java.io.*;
import java.util.*;

public class Main
{
 

private static Scanner in;

public static void main(String[] args)
{
      in = new Scanner(System.in);
      PrintWriter out = new PrintWriter(System.out);

      int x = in.nextInt();
      long[] as = new long[550];
      as[0] = 1;
      for(int i = 1; i < x; ++ i) {
          for (int j = x - 1; j >= 0; -- j) {
              if (x >= i + j) {
                  as[i+j] += as[j];
              }
          }
      }

      out.println(as[x]);
      out.flush();
   }
}
