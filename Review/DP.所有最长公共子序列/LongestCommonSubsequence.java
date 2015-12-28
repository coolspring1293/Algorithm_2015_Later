import java.util.*;

/**
 * The string "abcabcaa" and "acbacba" have longest common subsequences:
 * ababa
 * abaca
 * abcba
 * acaba
 * acaca
 * acbaa
 * acbca
 * @author York
 *
 */

public class LongestCommonSubsequence {
	String source;
	String target;
	int[][] c;
	int[][] last1;
	int[][] last2;
	int lcsLength;
	char[] tmp;
	String alphabet;
	HashSet<String> set = new HashSet<String>();
	
	public LongestCommonSubsequence() {
	}
	
	public LongestCommonSubsequence(String s, String t) {
		this.source = s;
		this.target = t;
	}
	
	public int LCSLength() {
		int m = source.length();
		int n = target.length();
		c = new int[m+1][n+1];
	
		c[0][0] = 0;
		for(int i = 1; i <= m; ++i) {
			c[i][0] = 0;
		}
		for(int j = 1; j <= n; ++j) {
			c[0][j] = 0;
		}
		
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(source.charAt(i-1) == target.charAt(j-1)) {
					c[i][j] = c[i-1][j-1] + 1;
				} else if(c[i-1][j] >= c[i][j-1]){
					c[i][j] = c[i-1][j];
				} else {
					c[i][j] = c[i][j-1];
				}
				
			}
		}
		return lcsLength = c[m][n];
	}
	
	private void lastIndexOf(String s, int[][] last) {
		for (int j = 0; j < alphabet.length(); ++j) {
			char c = alphabet.charAt(j);
			for (int i = 1; i <= s.length(); ++i) {
				int lastIndex;
				for (lastIndex = i; lastIndex >= 1; --lastIndex) {
					if(c == s.charAt(lastIndex-1)) {
						last[i][j] = lastIndex;
						break;
					}
				}
				if(lastIndex <= 0) {
					last[i][j] = 0;
				}
			}
		}
	}
	
	private void backTraceAll(int index1, int index2, int len) {
		if(len <= 0) {
			String str = new String(tmp);
			System.out.println("lcs: " + str);
			set.add(str);
			return;
		}
		if(index1 > 0 && index2 > 0) {
			for(int j = 0; j < alphabet.length(); ++j) {
				//字母表中第j个字符最后一次出现在子串source(0, index1)的下标
				int t1 = last1[index1][j];
				int t2 = last2[index2][j];
				//数学证明是？或者给出递归表达式吧
				if(c[t1][t2] == len) {
					tmp[len-1] = alphabet.charAt(j);
					backTraceAll(t1-1, t2-1, len-1);
				}
			}
		}
	}
	
	public void printAll() {
		int m = source.length();
		int n = target.length();
		
		//由两个字符串构成的字母表，包含它们中出现过的所有字符的集合
		//alphabet = {i| i in source or target};
		HashSet<Character> alpha = new HashSet<Character>();
		for(int i = 0; i < m; ++i) {
			alpha.add(source.charAt(i));
		}
		for(int j = 0; j < n; ++j) {
			alpha.add(target.charAt(j));
		}
		int length = alpha.size();
		Character[] characters = new Character[length];
		alpha.toArray(characters);
		char[] chars = new char[length];
		for(int i = 0; i < length; ++i) {
			chars[i] = characters[i];
		}
		alphabet = new String(chars);

		System.out.println("alphabet = " + alphabet);
		
		last1 = new int[m+1][alphabet.length()];
		last2 = new int[n+1][alphabet.length()];
		
		System.out.println("c[][]: ");
		for(int i = 0; i <= m; ++i) {
			for(int j = 0; j <= n; ++j) {
				System.out.print(c[i][j] + "\t");
			}
			System.out.println();
		}
		
		
		lastIndexOf(source, last1);
		lastIndexOf(target, last2);
		
		System.out.println("last1[][]: ");
		for(int i = 0; i <= m; ++i) {
			for(int j = 0; j < alphabet.length(); ++j) {
				System.out.print(last1[i][j] + " ");
			}
			System.out.println();
		}
		
		System.out.println("last2[][]: ");
		for(int i = 0; i <= n; ++i) {
			for(int j = 0; j < alphabet.length(); ++j) {
				System.out.print(last2[i][j] + " ");
			}
			System.out.println();
		}

		
		System.out.println("lcs length = " + lcsLength);
		
		tmp = new char[lcsLength];
		backTraceAll(m, n, lcsLength);
		System.out.println("All longest common sequences: ");
		for(String s: set) {
			System.out.println(s);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter two strings:");
		String str1 = sc.nextLine();
		String str2 = sc.nextLine();
		LongestCommonSubsequence lcs = new LongestCommonSubsequence(str1, str2);
		int max = lcs.LCSLength();
		System.out.println("longest length = " + max);
		lcs.printAll();
	}
}