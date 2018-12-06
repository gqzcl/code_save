import java.util.List;
import java.util.Arrays;
import java.util.Collections;

public class QuickSort<T extends Comparable<T>> extends Sort<T>{
    @Override
    public void sort(T[] nums){
        shuffle(nums);
        sort(nums,0,nums.length-1);
    }
    private void sort(T[] nums,int l,int h){
        if(h<=1){
            return;
        }
        int j=partition(nums,l,h);
        sort(nums,l,j-1);
        sort(nums,j+1,h);
    }
    private void shuffle(T[] nums){
        List<Comparable> list=Arrays.asList(nums);
        Collections.shuffle(list);
        list.toArray(nums);
    }
    private int partition(T[] nums, int l, int h) {
        int i = l, j = h + 1;
        T v = nums[l];
        while (true) {
            while (less(nums[++i], v) && i != h) ;
            while (less(v, nums[--j]) && j != l) ;
            if (i >= j)
                break;
            swap(nums, i, j);
        }
        swap(nums, l, j);
        return j;
    }
    public static void main(String[] args) {
        QuickSort<Integer> S=new QuickSort<Integer>();
        Integer[] nums=new Integer[1000];
        for(int i=0;i<1000;i++){
            nums[i]=(int)(1000*Math.random());
        }
        S.sort(nums);
        for(int i=0;i<1000;i++){
            System.out.println(nums[i]);
        }
    }
}