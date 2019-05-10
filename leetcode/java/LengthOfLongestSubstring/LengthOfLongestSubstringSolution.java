import java.util.HashMap;
import java.util.Map;

//solution of LeetCode: Sliding Window
public class LengthOfLongestSubstringSolution {

    public int lengthOfLongestSubstring(String s) {
    	int n = s.length();
        int maxlen = 0;
        Map<Character, Integer> map = new HashMap<>();
        for(int j=0,i=0; j<n; j++){
        	if(map.containsKey(s.charAt(j))){
        		i = Math.max(map.get(s.charAt(j)), i);
        	}
    		maxlen = Math.max(maxlen, j - i + 1);
            map.put(s.charAt(j), j + 1);
        }
        return maxlen;
	}
}