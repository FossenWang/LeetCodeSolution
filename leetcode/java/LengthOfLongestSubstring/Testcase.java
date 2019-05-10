

public class Testcase {

	public static void main(String[] args) {
		String[] strings = new String[4];
		strings[0] = "";
		strings[1] = "aaaaa";
		strings[2] = "zx";
		strings[3] = "asdqgqqefhbifadfkhbiu";
		int[] expected = {0,1,2,8};

		LengthOfLongestSubstringSolution lolss = new LengthOfLongestSubstringSolution();
		for (int i = 0; i<4; i++){
			int len = lolss.lengthOfLongestSubstring(strings[i]);
			 System.out.println("output:"+len+"\nexpected:"+expected[i]);
		}
	}

}
