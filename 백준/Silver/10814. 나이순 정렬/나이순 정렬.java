import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class people{
    int age;
    String name;
    public people(int age, String name){
        this.age = age;
        this.name = name;
    }
    @Override
    public String toString(){
        return age + " " + name + "\n";
    }
}



public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        people[] p = new people[N];
        for (int i = 0; i < N; i++) {
            p[i] = new people(sc.nextInt(), sc.next());
        }
        Arrays.sort(p, new Comparator<people>(){
            @Override
            public int compare(people p1, people p2) {
                return p1.age - p2.age;
            }
        });

        for (int i = 0; i < N; i++) {
            System.out.print(p[i].toString());
        }
        
        sc.close();
    }
}
