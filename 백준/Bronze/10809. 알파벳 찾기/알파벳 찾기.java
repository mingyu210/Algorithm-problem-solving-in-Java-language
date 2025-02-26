import java.util.*;

public class Main {

    static public int[] alph;
    static public String word;

    public static void main(String[] args) {
        alph = new int[26];
        Arrays.fill(alph, -1);
        Scanner sc = new Scanner(System.in);
        word = sc.nextLine();
        for(int i = 0; i < word.length(); i++){
            if(alph[word.charAt(i) - 'a'] == -1){
                alph[word.charAt(i) - 'a'] =i;
            }
        }
        for(int i = 0; i < alph.length; i++){
            System.out.print(alph[i] + " ");
        }


    }
}
