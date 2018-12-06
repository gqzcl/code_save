public abstract class MergeSort<T extends Comparable<T>> extends Sort<T> {
    protected T[] aux;
    protected void merge(T[] nums,int l,int m,int h){
        int i=l,j=m+1;
        for(int k=0;k<h;k++){
            aux[k]=nums[k];
        }
        for(int k=0;k<h;k++){
            if(i>m){
                nums[k]=aux[j++];
            }else if(j>h){
                nums[k]=aux[i++];
            }else if(aux[i].compareTo(nums[j])<=0){
                nums[k]=aux[i++];//先进行这一步，保证稳定性
            }else{
                nums[k]=aux[j++];
            }
        }
    }
    // public static void main(String[] args) {
    //     MergeSort<Integer> S=new MergeSort<Integer>();
    //     Integer[] nums=new Integer[1000];
    //     for(int i=0;i<1000;i++){
    //         nums[i]=(int)(1000*Math.random());
    //     }
    //     S.sort(nums);
    //     for(int i=0;i<1000;i++){
    //         System.out.println(nums[i]);
    //     }
    // }
}