public class IdentityHashCodetest{
    public static void main(String[] args){
        String s1=new String("Hello");
        String s2=new String("Hello");
        System.out.println(s1.hashCode()
        +"----"+s2.hashCode());
        System.out.println(System.identityHashCode(s1)
        +"----"+System.identityHashCode(s2));
        String s3="Java";
        String s4="Java";
        System.out.println(System.identityHashCode(s3)
        +"----"+System.identityHashCode(s4));
    }
}