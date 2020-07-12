import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    public List<Integer>[] getNewList(List<Integer> list[], int N, int level){
		int tmp = 0;
		for( int i = level; i > 0 ; i-- ) {
			tmp += N * Math.pow(10, (i-1));
		}
		
		list[level].add(tmp);
		
		for(int i = 1; i <= level/2; i++) {
			int j = (level - i);
			
			for(int left = 0; left < list[i].size(); left++) {
				for(int right = 0; right < list[j].size(); right++) {
					int l = list[i].get(left);
					int r = list[j].get(right);
					list[level].add(l + r);
					list[level].add(l * r);
					list[level].add(l - r);
					list[level].add(r - l);
					if ( r != 0 ) {
						list[level].add(l / r);	
					}
					if ( l != 0 ) {
						list[level].add(r / l);
					}
				}
			}
		}
		return list;
	}
    public int solution(int N, int number) {
        List<Integer> list[] = new ArrayList[9];
		for(int i = 0 ; i < 9; i++) {
			list[i] = new ArrayList<Integer>();
		}
		for(int level = 1; level < 9; level++) {
			list = getNewList(list, N, level);
			HashSet<Integer> tmp = new HashSet<Integer>(list[level]);
			list[level] = new ArrayList<Integer>(tmp);
			if( list[level].contains(number)) {
				return level;
			}
		}
		return -1;
    }
}