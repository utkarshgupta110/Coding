public class stringBuffer {
    public static void main(String[] args) {
        StringBuffer sb = new StringBuffer("Utkarsh");
        System.out.println("Original StringBuffer: " + sb);
        
        // Append
        sb.append(" Gupta");
        System.out.println("After append: " + sb);
        
        // Insert
        sb.insert(7, " Singh");
        System.out.println("After insert: " + sb);
        
        // Delete
        sb.delete(7, 13);
        System.out.println("After delete: " + sb);
        
        // Replace
        sb.replace(0, 7, "Utk");
        System.out.println("After replace: " + sb);
        
        // Reverse
        sb.reverse();
        System.out.println("After reverse: " + sb);
        
        // Length
        System.out.println("Length of StringBuffer: " + sb.length());
    }
}
// This code demonstrates the use of StringBuffer in Java.
//stringBuffer is mutable
