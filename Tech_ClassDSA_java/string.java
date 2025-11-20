import java.util.*;
// immutable : creating string using new keyword
/*class string{
    String s1="Utkarsh";

    public static void main(String[] args) {
        string s=new string();
        System.out.println(s.s1);
        System.out.println(s.s1.concat("Gupta"));
        System.out.println(s.s1);
       
    }
}*/
// immutable : creating string using string literal
/*class string{
    public static void main(String[] args) {
    String s1="Utkarsh";

    System.out.println(s1);
    System.out.println(s1.concat("Gupta"));
    System.out.println(s1);
    }
}*/
// mutable : creating string using stringBuffer
class string{

    public static void main(String[] args) {
        StringBuffer sb=new StringBuffer("Utkarsh");
        System.out.println(sb);
        System.out.println(sb.append("Gupta"));// stringBuffer is mutable, so it can be changed and it has no effect on original string also it is faster than string and it has append method i.e. sb.append("Gupta")  insted of concatenation i.e. sb.concat("Gupta")
        System.out.println(sb);
        System.out.println(sb.reverse());
       
    }
}